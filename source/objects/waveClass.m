%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Copyright 2014 the National Renewable Energy Laboratory and Sandia Corporation
% 
% Licensed under the Apache License, Version 2.0 (the "License");
% you may not use this file except in compliance with the License.
% You may obtain a copy of the License at
% 
%     http://www.apache.org/licenses/LICENSE-2.0
% 
% Unless required by applicable law or agreed to in writing, software
% distributed under the License is distributed on an "AS IS" BASIS,
% WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
% See the License for the specific language governing permissions and
% limitations under the License.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

classdef waveClass<handle  
    properties %from input file
        type                        = 'NOT DEFINED'                        % Wave type. Options for this varaibale are 'noWave' (no waves), 'regular' (regular waves), 'regularCIC' (regular waves using convolution integral to calculate radiation effects), 'irregular' (irregular waves), 'irregularPRE' (irregular waves with pre defined phase). The default is 'regular'.
        T                           = 'NOT DEFINED'                        % [s] Wave period (regular waves) or peak period (irregular waves) (default = 8)
        H                           = 'NOT DEFINED'                        % [m] Wave height (regular waves) or significant wave height (irregular waves) (default = 1)
        noWaveHydrodynamicCoeffT    = 'NOT DEFINED'                        % Period of BEM simulation used to determine hydrodynamic coefficients for simulations with no wave. This option is only used with the 'noWave' wave type.
        spectrumType                = 'NOT DEFINED'                        % Type of wave spectrum. Only PM, BS, JS, and Imported spectrum are supported.
        randPreDefined              = 0;                                   % Only used for irregular waves. Default is equal to 0; if it equals to 1, the waves pahse is pre-defined
        spectrumDataFile            = 'NOT DEFINED'                        % Data file that contains the spectrum data file        
    end
    
    properties %internal
        typeNum                     = []                                   % Number to represent different type of waves
        numFreq                     = []                                   % Number of interpolated wave frequencies (default = 'NOT DEFINED') 
        bemFreq                     = []                                   % Number of wave frequencies from WAMIT
        waterDepth                  = []                                   % [m] Water depth (from WAMIT)
        waveAmpTime                 = 999                                  % [m] Wave elevation time history
        A                           = []                                   % [m] Wave amplitude for regular waves or sqrt(wave spectrum vector) for irregular waves
        w                           = []                                   % [rad/s] Wave frequency (regular waves) or wave frequency vector (irregular waves)
        phaseRand                   = 999                                  % [rad] Random wave phase (only used for irregular waves)
    end
    
    methods
        function obj = waveClass(type)
            obj.type = type;
            switch obj.type
                case {'noWave','regular'}          % Regular Waves
                    obj.typeNum = 10;
                case {'noWaveCIC','regularCIC'}           % No Wave CIC
                    obj.typeNum = 11;
                case 'irregular'        % Irregular Waves
                    obj.typeNum = 20; 
                case 'irregularImport'      %  Irregular Waves w/Predefined Phase
                    obj.typeNum = 21;
                otherwise
                    error(['Unexpected wave environment type setting. ' ...
                        'Only noWave, noWaveCIC, regular, regularCIC, irregular, and irregularImport waves are supported at this time'])
            end
        end
        
        function waveSetup(obj,numFreq,bemFreq,waterDepth,rampT,dt,maxIt)
            obj.numFreq    = numFreq; %simu
            obj.bemFreq    = bemFreq; %body(1)
            obj.waterDepth = waterDepth; %body(1)
            switch obj.type
                case {'noWave'}
                    if strcmp(obj.noWaveHydrodynamicCoeffT,'NOT DEFINED')
                        error('The noWaveHydrodynamicCoeffT variable must be defined when using the "noWave" wave type');
                    end
                    obj.H = 0;
                    obj.T = obj.noWaveHydrodynamicCoeffT;
                case {'noWaveCIC'} 
                    obj.H = 0;
                    obj.T = 0;
                case {'irregularImport'}
                    obj.H = 0;
                    obj.T = 0;
                    obj.spectrumType = 'Imported';
                    if strcmp(obj.spectrumDataFile,'NOT DEFINED')
                        error('The spectrumDataFile variable must be defined when using the "irregularImport" wave type');
                    end
            end
            %calculate wave            
            switch obj.type
                case {'noWave','noWaveCIC','regular','regularCIC'}
                    [obj.waveAmpTime,obj.A,obj.w]=wavesReg(obj, rampT, dt, maxIt);
                case {'irregular','irregularImport'}        % Irregular Waves
                    obj.setWavePhase;    
                    [obj.waveAmpTime,obj.A,obj.w]=wavesIrreg(obj, rampT, dt, maxIt);
            end
            
            %internal functions for waveSetup
            function [waveAmpTime,waveAmp,w] = wavesReg(obj, rampT, dt, maxIt)
                maxRampIT=round(rampT/dt);
                w=2*pi/obj.T;
                waveAmp=obj.H/2;
                waveAmpTime=zeros(maxIt+1,1);%caculate wave history
                if rampT==0 % No wave ramping defined
                   for i=1:maxIt+1
                       t = (i-1)*dt;
                       waveAmpTime(i) = waveAmp*cos(w*t);
                   end
                else % If wave ramping defined
                   for i=1:maxRampIT
                       t = (i-1)*dt;
                       waveAmpTime(i) = waveAmp*cos(w*t)*(1+cos(pi+pi*(i-1)/maxRampIT))/2;
                   end
                   for i=maxRampIT+1:maxIt+1;
                       t = (i-1)*dt;
                       waveAmpTime(i) = waveAmp*cos(w*t);
                   end       
                end
            end
            
            function [waveAmpTime,Sf,frequency] = wavesIrreg(obj,rampT, dt, maxIt)
                % Define Function Inputs
                maxRampIT=round(rampT/dt);        % Max Wave Ramp Iteration
                numFqs=obj.numFreq;               % Number of Wave Frequencies
                WFQSt=min(obj.bemFreq);           % Min BEM Frequnecy [rad/s]
                WFQEd=max(obj.bemFreq);           % Max BEM Frequnecy [rad/s]
                df  = (WFQEd-WFQSt)/(numFqs-1);     % Delta Frequency [rad/s]
                % Define Hs and Tp for Spectrum Definition
                frequency = (WFQSt:df:WFQEd)';      % [rad/s]
                freq = frequency/(2*pi);            % [Hz]
                Tp = obj.T;                       % Peak Period[s]
                Hs = obj.H;                       % Sig Wave Height[m]
                g = 9.81;                           % Gravity [m/s/s]
                switch obj.spectrumType
                    case 'BS'       
                        % Bretschneider Sprectrum from Tucker and Pitt (2001)
                        B = (1.057/Tp)^4;
                        A_irreg = B*(Hs/2)^2;
                        S_f = (A_irreg*freq.^(-5).*exp(-B*freq.^(-4)));    
                        Sf = S_f./(2*pi);                            
                    case 'JS'      
                        % JONSWAP Spectrum from Hasselmann et. al (1973)
                        [S] = wecSimJonswap(freq,Hs,Tp); 
                        Sf = S./(2*pi);
                    case 'PM' 
                        % Pierson-Moskowitz Spectrum from Tucker and Pitt (2001)
                        B = (5/4)*(1/Tp)^(4);
                        A_irreg = g^2*(2*pi)^(-4);
                        S_f = (A_irreg*freq.^(-5).*exp(-B*freq.^(-4)));    
                        %alpha = 0.0081;
                        % Alpha Coefficient
                        alpha = Hs^(2)/16/trapz(freq,S_f);%Calculates the required \alpha_{j} coefficient to achieve the desired Hs %freq must be in ascending order, i.e., 1,2,3,4 or integration will result in negative summation
                        Sf = alpha*S_f./(2*pi);          
                    case 'Imported' 
                        %Imported Spectrum
                        data = dlmread(obj.spectrumDataFile);
                        freq_data = data(1,:);       % Buoy Freuqnecies [Hz]
                        Sf_data = data(2,:);        % Buoy Sprectal Data [m^2-s]
                        S_f = interp1(freq_data,Sf_data,freq,'pchip',0);   % Interpolated Spectral Data [m^2-s]
                        Sf = S_f./(2*pi); 
                end
                %  Calulate wave history
                waveAmpTime = zeros(maxIt+1,1);
                % No wave ramping defined
                if rampT==0    
                   for i=1:maxIt+1;
                       t = (i-1)*dt;
                       for j=1:numFqs
                           tmp=sqrt(2*Sf(j)*df);
                           waveAmpTime(i) = waveAmpTime(i) + tmp*real(exp(sqrt(-1)*(frequency(j)*t + obj.phaseRand(j))));
                       end
                   end
                % If wave ramping defined
                else    
                   for i=1:maxRampIT
                       t = (i-1)*dt;

                       for j=1:numFqs
                           tmp=sqrt(2*Sf(j)*df);
                           waveAmpTime(i) = waveAmpTime(i) + tmp*real(exp(sqrt(-1)*(frequency(j)*t + obj.phaseRand(j))));
                       end
                       waveAmpTime(i) = waveAmpTime(i)*(1+cos(pi+pi*(i-1)/maxRampIT))/2;
                   end
                   for i=maxRampIT+1:maxIt+1
                       t = (i-1)*dt;

                       for j=1:numFqs
                           tmp=sqrt(2*Sf(j)*df);
                           waveAmpTime(i) = waveAmpTime(i) + tmp*real(exp(sqrt(-1)*(frequency(j)*t + obj.phaseRand(j))));
                       end
                   end   
                end
            end
            
            function [S,freq] = wecSimJonswap(freq,Hs,Tp)
                % Function Definition
                % WECSimJONSWAP
                %     Creates a JONSWAP spectrum based on user-defined Hs and Tp, see
                %     Theory Manual for more information on JONSWAP formulation.
                % INPUTS: 
                %     freq = Wave Frequencies [Hz], defined frequencies from BEM solution
                %     Hs = Significant Wave Height [m], defined by user in wecSimInputFile
                %     Tp = Peak Period [s], defined by user in wecSimInputFile
                % OUTPUTS: 
                %     freq = Fave Frequencies [Hz], sorted in ascending order
                %     S = Final Spectrum [m^2-s] using the alpha(j) fit method, as defined  
                %           in the Theory Manual
                %
                % Sort Frequencies
                [r,~] = size(freq);
                if r == 1   % check to see if freq is a row vector
                    freq = sort(freq)';     % transpose to a column vector and sort in ascending order
                else
                    freq = sort(freq);      % sort in ascending order if freq is already in column format
                end
                % Constants
                fp = 1/Tp;
                gamma = 3.3;g = 9.81;
                siga = 0.07;sigb = 0.09;
                % Sort frequencies above and below fp
                [lind,~] = find(freq<=fp);%Sort frequencies below f_{p} %freq should have the units of Hertz [1/s]
                [hind,~] = find(freq>fp);%Sort frequencies above f_{p} %freq should have the units of Hertz [1/s]
                % Gamma Function
                Gf = zeros(size(freq));%this was the item causing an issue
                Gf(lind) = gamma.^exp(-(freq(lind)-fp).^2/(2*siga^2*fp^2));%freq should have the units of Hertz [1/s]
                Gf(hind) = gamma.^exp(-(freq(hind)-fp).^2/(2*sigb^2*fp^2));%freq should have the units of Hertz [1/s]
                % Spectrum Definition
                Sf = g^2*(2*pi)^(-4)*freq.^(-5).*exp(-(5/4).*(freq/fp).^(-4));%freq should have the units of Hertz [1/s]
                % Alpha Coefficient
                A = Hs^(2)/16/trapz(freq,Sf.*Gf);%Calculates the required \alpha_{j} coefficient to achieve the desired Hs%freq must be in ascending order, i.e., 1,2,3,4 or integration will result in negative summation
                % Final Sprectrum
                S = A*Sf.*Gf;   %Final Spectrum using the alpha(j) fit method [m^2-s]
            end
        end

        function setWavePhase(obj)
        % function for setup wave random phase
            if obj.randPreDefined ~= 0
               rng(seed);    
            end
            obj.phaseRand = 2*pi*rand(1,obj.numFreq);
        end

        function  listInfo(obj)
            fprintf('\nWave Environment: \n')
            switch obj.type
                case 'noWave'
                    fprintf('\tWave Type                            = No Wave\n')                    
                case 'regular'
                    fprintf('\tWave Type                            = Regular Waves (Sinusoidal Steady-State)\n')                    
                    fprintf('\tWave Height H                    (m) = %G\n',obj.H)                    
                    fprintf('\tWave Period T                  (sec) = %G\n',obj.T)                    
                case 'noWaveCIC'
                    fprintf('\tWave Type                            = No Wave (Convolution Integral Calculation)\n')                    
                case 'regularCIC'
                    fprintf('\tWave Type                            = Regular Waves (Convolution Integral Calculation)\n')                    
                    fprintf('\tWave Height H                    (m) = %G\n',obj.H)                    
                    fprintf('\tWave Period T                  (sec) = %G\n',obj.T)                    
                case 'irregular'
                    if obj.randPreDefined == 0
                       fprintf('\tWave Type                            = Irregular Waves (Arbitrary Random Phase)\n')                    
                    else
                       fprintf('\tWave Type                            = Irregular Waves (Predefined Random Phase)\n')                    
                    end
                    printWaveSpectrumType;   
                    fprintf('\tSignificant Wave Height Hs       (m) = %G\n',obj.H)                    
                    fprintf('\tPeak Wave Period Tp            (sec) = %G\n',obj.T)                         
                case 'irregularImport'
                    if obj.randPreDefined == 0
                       fprintf('\tWave Type                            = Irregular Waves (Arbitrary Random Phase)\n')                    
                    else
                       fprintf('\tWave Type                            = Irregular Waves (Predefined Random Phase)\n')                    
                    end
                    printWaveSpectrumType;
            end
            
            %internal functions for listInfo
            function obj = printWaveSpectrumType(obj)
                   if strcmp(obj.spectrumType,'BS')
                        fprintf('\tSpectrum Type                        = Bretschneider \n')                    
                   elseif strcmp(obj.spectrumType,'JS')
                        fprintf('\tSpectrum Type                        = JONSWAP \n')                    
                   elseif strcmp(obj.spectrumType,'PM')
                        fprintf('\tSpectrum Type                        = Pierson-Moskowitz  \n')                    
                   elseif strcmp(obj.spectrumType,'Imported')
                        fprintf('\tSpectrum Type                        = User-Defined \n')                                        
                   end            
            end
        end
        
        function checkProperties(obj)
        end
    end
end