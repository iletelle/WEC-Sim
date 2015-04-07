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
% Set Wave Environment
switch waves.type
    case {'noWave'}       % No Wave
            if strcmp(waves.noWaveHydrodynamicCoeffT,'NOT DEFINED')
                error('The noWaveHydrodynamicCoeffT variable must be defined when using the "noWave" wave type');
            end
            waves = waveClass(waves.type,0,waves.noWaveHydrodynamicCoeffT,waves.heading,simu,body); %H is equal to 0.
            waves.bemFreq    = body(1).hydro.data.frequency;    % Frequencies from WAMIT
            waves.waterDepth = body(1).hydro.data.waterDepth;   % Water Depth from WAMIT
            [waves.waveAmpTime,waves.A,waves.w]=wavesReg(waves,simu);
     case {'noWaveCIC'}       % No WaveCIC
            waves = waveClass(waves.type,0,0,waves.heading,simu,body); %H is equal to 0.
            waves.bemFreq    = body(1).hydro.data.frequency;    % Frequencies from WAMIT
            waves.waterDepth = body(1).hydro.data.waterDepth;   % Water Depth from WAMIT
            [waves.waveAmpTime,waves.A,waves.w]=wavesReg(waves,simu);
            waves.w = 1;                            %w is equal to 0 to avoid infinity             
    case {'regular','regularCIC'}        % Regular Waves
            waves = waveClass(waves.type,waves.H,waves.T,waves.heading,simu,body);
            waves.bemFreq    = body(1).hydro.data.frequency;    % Frequencies from WAMIT
            waves.waterDepth = body(1).hydro.data.waterDepth;   % Water Depth from WAMIT
            [waves.waveAmpTime,waves.A,waves.w]=wavesReg(waves,simu);         
            waves.k = fzero(@(x) waves.w^(2)/simu.g - x*tanh(x*body(1).hydro.data.waterDepth),waves.w^2/simu.g);
    case {'irregular'}      % Irregular Waves
            waves = waveClass(waves.type,waves.H,waves.T,waves.heading,simu,body,waves.spectrumType,waves.randPreDefined,'none');
            waves.bemFreq    = body(1).hydro.data.frequency;    % Frequencies from WAMIT
            waves.waterDepth = body(1).hydro.data.waterDepth;   % Water Depth from WAMIT
            [waves.waveAmpTime,waves.A,waves.w]=wavesIrreg(waves,simu);
    case {'irregularImport'}      % Irregular Waves
            waves = waveClass(waves.type,0,0,waves.heading,simu,body,'Imported',waves.randPreDefined,waves.spectrumDataFile);
            waves.bemFreq    = body(1).hydro.data.frequency;    % Frequencies from WAMIT
            waves.waterDepth = body(1).hydro.data.waterDepth;   % Water Depth from WAMIT
            [waves.waveAmpTime,waves.A,waves.w]=wavesIrreg(waves,simu);
    case {'userdefined'}      % User Defined Wave Elevation Time Series
            waves = waveClass(waves.type,0,0,waves.heading,simu,body,'userdefined',0,waves.spectrumDataFile);
            waves.bemFreq    = body(1).hydro.data.frequency;    % Frequencies from WAMIT
            waves.waterDepth = body(1).hydro.data.waterDepth;   % Water Depth from WAMIT
            [waves.waveAmpTime,waves.A,waves.w]=wavesUserDefined(waves,simu);
    otherwise
            error('Unexpected wave environment type setting');
end

% Hack for when infinite water depth is used in WAMIT
if imag(waves.waterDepth) == Inf 
    warning(['waves.waterDepth was changed from ' num2str(waves.waterDepth) ...
        ' to 200 m for visualization purposes'])
    waves.waterDepth = 200;
end
