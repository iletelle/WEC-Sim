%% Simulation Data

simu = simulationClass();
simu.endTime=400;
simu.dt = 0.1;
simu.simMechanicsFile = 'RM3.slx';        
simu.mode='normal';
simu.explorer = 'on';
simu.convCalc = 0;
simu.rampT = 0;

%% Wave Information
%Regular Waves 
waves = waveClass('regularCIC');
waves.H = 2.5;
waves.T = 8;

%Irregular Waves using PM Spectrum
% waves.H = 2.5;
% waves.T = 8;
% waves.type = 'irregular';
% waves.spectrumType = 'PM';

%Irregular Waves using User-Defined Spectrum
% waves.type = 'irregularImport';
% waves.spectrumDataFile = 'ndbcBuoyData.txt';

%% Body Data
body(1) = bodyClass('wamit/rm3.h5',1);              
body(1).mass = body(1).hydroData.properties.dispVol * body(1).hydroData.simulation_parameters.rho;
body(1).momOfInertia = [20907301 21306090.66 37085481.11];      
body(1).geometryFile = 'geometry/float.stl';    

body(2) = bodyClass('wamit/rm3.h5',2);
body(2).mass = body(2).hydroData.properties.dispVol * body(2).hydroData.simulation_parameters.rho;
body(2).momOfInertia = [94419614.57 94407091.24 28542224.82];
body(2).geometryFile = 'geometry/plate.stl';

%% PTO and Constraint Parameters
constraint(1) = constraintClass('Constraint1');
constraint(1).loc = [0 0 0];

pto(1) = ptoClass('PTO1');
pto(1).k=0; 
pto(1).c=1200000; 
pto(1).loc = [0 0 0];
