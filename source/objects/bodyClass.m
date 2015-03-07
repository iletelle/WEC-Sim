% This class defines the properities of rigid bodies the comprise WECs
%
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

classdef bodyClass<handle
    properties %from hdf5 file; Hydrodynamic data from BEM or user defined
        hydroData  = struct('properties', struct('name', 'NONE', ...            %name of body
                                         'bodyNumber', 0, ...                   %body number in BEM simulation 0-indexed
                                         'cg'     , [0, 0, 0], ...              %location of center of gravity [x,y,z] in m
                                         'cb'     , [0, 0, 0], ...              %location of center of buoyancy [x,y,z] in m
                                         'dispVol', 0), ...                     %displaced volume in m^3
                            'hydro_coeffs', struct('ex', struct('mag' , 0, ...  %magnitude of excitation force, numFreq x 6 matrix
                                                   'phase'  , 0, ...            %phase of excitation force, numFreq x 6 matrix
                                                   're'     , 0, ...            %real component of excitation force, numFreq x 6 matrix
                                                   'im'     , 0), ...           %imaginary component of excitation force, numFreq x 6 matrix
                                          'am', struct('all', 0, ...            %frequency dependent added mass, 6 x 6 x numFreq
                                                   'inf'   , 0, ...             %added mass at infinite frequency, 6 x 6 matrix
                                                   'comps' , struct), ...       %component vectors for frequency dependent added mass, structure containing 36 vectors length numFreq
                                          'rd', struct('all', 0, ...            %frequency dependent radiation damping, 6 x 6 x numFreq
                                                   'comps' , struct), ...       %component vectors for frequency dependent radiation damping, structure containing 36 vectors length numFreq
                                          'k', 0), ...                          %linear hydrostatic restoring coefficient matrix, 6x6
                            'simulation_parameters', struct('T', 0, ...         %period vector in s
                                         'w'            , 0, ...                %frequency vector in rad/s 
                                         'g'            , 0, ...                %gravitational acceleration in m/s^2
                                         'rho'          , 0, ...                %water density in kg/m^3 
                                         'wDepth'       , 0, ...                %water depth in m 
                                         'wDir'         , 0))                   %wave direction in rad
    end
    
    properties %from input file
        mass                   = 0                                              %mass in kg
        momOfInertia           = [0 0 0]                                        %moment of inertia [Ixx Iyy Izz] in kg*m^2
        geometryFile           = 'NONE'                                         %location of geomtry stl file
        mooring                = struct('c',          0, ...                    %mooring damping, 6 x 6 matrix
                                        'k',          0, ...                    %mooring stiffness, 6 x 6 matrix
                                        'preTension', 0)                        %mooring preTension, Vector length 6
        viscDrag               = struct('cd',  [0 0 0 0 0 0], ...               %viscous (quadratic) drag cd, vector length 6
                                        'characteristicArea', [0 0 0 0 0 0])    %characteristic area for viscous drag, vector length 6
                                        %fixme: add linear damping
        initDisp               = struct('initLinDisp', [0 0 0], ...             %initial displacement of center fo gravity - used for decay tests (format: [displacment in m], default = [0 0 0])
                                        'initAngularDispAxis', [1 0 0], ...     %initial displacement of cog - axis of rotation - used for decay tests (format: [x y z], default = [1 0 0])
                                        'initAngularDispAngle', 0)              %initial displacement of cog - Angle of rotation - used for decay tests (format: [radians], default = 0)
        linearDamping          = [0 0 0 0 0 0]
    end
    
    properties %internal
        hydroForce             = struct()                                       %hydrodynamic forces and coefficients used during simulation
    end

    methods
        function obj = bodyClass(filename,iBod) 
        % Initilization function
        % Read in hdf5 file
            if exist(filename,'file') == 0
                error('The hdf5 file %s does not exist',file)                
            end
            info = h5info(filename);
            obj.hydroData.properties = h5load(filename, [info.Groups(iBod).Name '/properties']);
            obj.hydroData.hydro_coeffs = h5load(filename, [info.Groups(iBod).Name '/hydro_coeffs']);
            obj.hydroData.simulation_parameters = h5load(filename, '/simulation_parameters');
            obj.hydroData.properties.name = obj.hydroData.properties.name{1};
        end
      
        function hydroForcePre(obj,w,CIkt,numFreq,dt,rho,waveType)
        % HydroForce Pre-processing calculations        
            obj.hydroForce.linearHydroRestCoef =  obj.hydroData.hydro_coeffs.k;
            obj.hydroForce.visDampingCoef = diag(0.5*rho.*obj.viscDrag.cd.*obj.viscDrag.characteristicArea);
            obj.hydroForce.linearDamping = diag(obj.linearDamping);
            switch waveType   
                case {'noWave','regular'}
                    obj = regExcitation(obj,w);
                    obj = constAddedMassAndDamping(obj,w,CIkt);
                case {'noWaveCIC','regularCIC'}
                    obj = regExcitation(obj,w);
                    obj = irfInfAddedMassAndDamping(obj,numFreq,CIkt,dt);
                case {'irregular','irregularImport'}
                    obj = irrExcitation(obj,w,numFreq);
                    obj = irfInfAddedMassAndDamping(obj,numFreq,CIkt,dt);
                otherwise
                    error('Unexpected wave environment type setting')
            end
            
            %internal functions for hydroForcePre
            function bodyTemp = regExcitation(bodyTemp,w)
                bodyTemp.hydroForce.fExt.re=zeros(1,6);
                bodyTemp.hydroForce.fExt.im=zeros(1,6);
                for ii=1:6
                    bodyTemp.hydroForce.fExt.re(ii) = interp1(bodyTemp.hydroData.simulation_parameters.w,bodyTemp.hydroData.hydro_coeffs.ex.re(:,ii),w,'spline');
                    bodyTemp.hydroForce.fExt.im(ii) = interp1(bodyTemp.hydroData.simulation_parameters.w,bodyTemp.hydroData.hydro_coeffs.ex.im(:,ii),w,'spline');      
                end
            end
            
            function bodyTemp = irrExcitation(bodyTemp,wv, numFreq)
                bodyTemp.hydroForce.fExt.re=zeros(numFreq,6);
                bodyTemp.hydroForce.fExt.im=zeros(numFreq,6);
                for i = 1:numFreq
                    w1 = wv(i);
                    for ii=1:6
                        bodyTemp.hydroForce.fExt.re(i,ii) = interp1(bodyTemp.hydroData.simulation_parameters.w,bodyTemp.hydroData.hydro_coeffs.ex.re(:,ii),w1,'linear');    
                        bodyTemp.hydroForce.fExt.im(i,ii) = interp1(bodyTemp.hydroData.simulation_parameters.w,bodyTemp.hydroData.hydro_coeffs.ex.im(:,ii),w1,'linear');      
                    end
                end
            end
            
            function bodyTemp = constAddedMassAndDamping(bodyTemp,w,CIkt)
                iBod = bodyTemp.hydroData.properties.bodyNumber + 1;
                bodyTemp.hydroForce.fAddedMass=zeros(6,6);
                bodyTemp.hydroForce.fDamping  =zeros(6,6);
                for ii=1:6
                    for jj=1:6
                        kk = jj + (iBod-1) * 6;
                        tmp = reshape(bodyTemp.hydroData.hydro_coeffs.am.all(ii,kk,:),1,length(bodyTemp.hydroData.simulation_parameters.T));
                        bodyTemp.hydroForce.fAddedMass(ii,jj) = interp1(bodyTemp.hydroData.simulation_parameters.w,tmp,w,'spline');
                        tmp = reshape(bodyTemp.hydroData.hydro_coeffs.rd.all(ii,kk,:),1,length(bodyTemp.hydroData.simulation_parameters.T));
                        bodyTemp.hydroForce.fDamping  (ii,jj) = interp1(bodyTemp.hydroData.simulation_parameters.w,tmp,w,'spline');
                    end
                end
                bodyTemp.hydroForce.irka=zeros(CIkt+1,6,6);
                bodyTemp.hydroForce.irkb=zeros(CIkt+1,6,6);
                bodyTemp.hydroForce.ssRadf.A = zeros(6*kk,6*kk);
                bodyTemp.hydroForce.ssRadf.B = zeros(6*kk,6*kk);
                bodyTemp.hydroForce.ssRadf.C = zeros(6,6*kk);
                bodyTemp.hydroForce.ssRadf.D = zeros(6,6*kk);
            end
            
            function bodyTemp = irfInfAddedMassAndDamping(bodyTemp,numFreq,CIkt,dt)
                iBod = bodyTemp.hydroData.properties.bodyNumber + 1;                
                WFQSt=min(bodyTemp.hydroData.simulation_parameters.w);
                WFQEd=max(bodyTemp.hydroData.simulation_parameters.w);
                df  = (WFQEd-WFQSt)/(numFreq-1);
                w2 = WFQSt:df:WFQEd;
                fDamping  =zeros(numFreq,6,6);
                for j = 1:numFreq
                    for ii=1:6
                        for jj=1:6
                            kk = jj + (iBod-1) * 6;
                            tmp = reshape(bodyTemp.hydroData.hydro_coeffs.rd.all(ii,kk,:),1,length(bodyTemp.hydroData.simulation_parameters.T));
                            fDamping(j,ii,jj) = interp1(bodyTemp.hydroData.simulation_parameters.w,tmp,w2(j),'linear');
                        end
                        clear tmp
                    end
                end    
                bodyTemp.hydroForce.irkb=zeros(CIkt+1,6,6);
                for kt=1:CIkt+1;
                    t = dt*(kt-1);
                    for ii=1:6
                        for jj=1:6
                            tmp=fDamping(:,ii,jj).*cos(w2(:)*t);
                            bodyTemp.hydroForce.irkb(kt,ii,jj) = 2./pi*trapz(w2,tmp);
                        end
                    end
                end; clear tmp
                bodyTemp.hydroForce.fAddedMass=bodyTemp.hydroData.hydro_coeffs.am.inf(:,1+(iBod-1)*6:6+(iBod-1)*6);
                bodyTemp.hydroForce.fDamping=zeros(6,6);
                
            end
        end

        function adjustMassMatrix(obj)
        % Merge diagnal term of add mass matrix to the mass matrix     
        % 1. Storage the the original mass and added-mass properties
        % 2. Add diagnal added-mass inertia to moment of inertia
        % 3. Add the maximum diagnal traslational added-mass to body mass
            obj.hydroForce.storage.mass = obj.mass;
            obj.hydroForce.storage.momOfInertia = obj.momOfInertia;
            obj.hydroForce.storage.fAddedMass = obj.hydroForce.fAddedMass;

            tmp.fadm=diag(obj.hydroForce.fAddedMass);
            obj.mass = obj.mass+max(tmp.fadm(1:3));
            obj.momOfInertia = obj.momOfInertia+tmp.fadm(4:6)';
            obj.hydroForce.fAddedMass(1,1) = obj.hydroForce.fAddedMass(1,1) - max(tmp.fadm(1:3));
            obj.hydroForce.fAddedMass(2,2) = obj.hydroForce.fAddedMass(2,2) - max(tmp.fadm(1:3));
            obj.hydroForce.fAddedMass(3,3) = obj.hydroForce.fAddedMass(3,3) - max(tmp.fadm(1:3));
            obj.hydroForce.fAddedMass(4,4) = 0;
            obj.hydroForce.fAddedMass(5,5) = 0;
            obj.hydroForce.fAddedMass(6,6) = 0;
        end
        
        function restoreMassMatrix(obj)
        % Restore the mass and added-mass matrix back to the original value
           obj.mass = obj.hydroForce.storage.mass;
           obj.momOfInertia = obj.hydroForce.storage.momOfInertia;
           obj.hydroForce.fAddedMass = obj.hydroForce.storage.fAddedMass;
        end
        
        function listInfo(obj)
        % Listing Body Info
            fprintf('\n\t***** Body Number %G, Name: %s *****\n',obj.hydroData.properties.bodyNumber,obj.hydroData.properties.name)
            fprintf('\tBody CG                          (m) = [%G,%G,%G]\n',obj.hydroData.properties.cg)
            fprintf('\tBody Mass                       (kg) = %G \n',obj.mass);
            fprintf('\tBody Diagonal MOI              (kgm2)= [%G,%G,%G]\n',obj.momOfInertia)
        end
        
        function checkProperties(obj)
        end
    end
end
