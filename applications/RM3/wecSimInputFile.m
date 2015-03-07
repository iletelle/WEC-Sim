% Simulation Data

simu = simulationClass();
simu.startTime=0;                           % Simulation Start Time [s]
simu.endTime=400;                           % Simulation End Time [s]
simu.dt = 0.1;                              % Simulation Delta_Time [s]
simu.simMechanicsFile = 'RM3.slx';          % Specify Simulink Model File          
simu.mode='normal';                         % Specify Simulation Mode 
                                                % (normal/accelerator
                                                % /rapid-accelerator)
simu.explorer = 'on';                         % Turn SimMechanics Explorer 
                                                % (on/off)
simu.convCalc = 0;

% Wave Information
waves = waveClass('regularCIC');
waves.H = 2.5;                              % Wave Height [m]
waves.T = 8;                                % Wave Period [s]

% % Wave Information: Irregular Waves using PM Spectrum
% waves.H = 2.5;                              % Wave Height [m]
% waves.T = 8;                                % Wave Period [s]
% waves.type = 'irregular';                   % Specify Type of Waves 
% waves.spectrumType = 'PM';                   % Specify Wave Spectrum Type

% % Wave Information: Irregular Waves using User-Defined Spectrum
% waves.type = 'irregularImport';                   % Specify Type of Waves 
% waves.spectrumDataFile = 'ndbcBuoyData.txt';    % Specify fileName.text

% Body Data
body(1) = bodyClass('wamit/rm3.h5',1);               % Initialize bodyClass for Float
body(1).mass = body(1).hydroData.properties.dispVol * body(1).hydroData.simulation_parameters.rho;         % Mass from WAMIT [kg]
body(1).momOfInertia = ...                  % Moment of Inertia [kg-m^2]
    [20907301 21306090.66 37085481.11];      
body(1).geometryFile = 'geometry/float.stl';    % Geometry File

body(2) = bodyClass('wamit/rm3.h5',2);          % Initialize bodyClass for 
                                               % Spar/Plate
body(2).mass = body(2).hydroData.properties.dispVol * body(2).hydroData.simulation_parameters.rho;         % Mass from WAMIT [kg]
body(2).momOfInertia = ...
    [94419614.57 94407091.24 28542224.82];  % Moment of Inertia [kg-m^2]
body(2).geometryFile = 'geometry/plate.stl';    % Geometry File

% PTO and Constraint Parameters
constraint(1) = ...                         % Initialize Constraint Class 
    constraintClass('Constraint1');             % for Constraint1

constraint(1).loc = [0 0 0];

pto(1) = ptoClass('PTO1');                  % Initialize ptoClass for PTO1
pto(1).k=0;                                 % PTO Stiffness Coeff [N/m]
pto(1).c=1200000;                           % PTO Damping Coeff [Ns/m]
pto(1).loc = [0 0 0];