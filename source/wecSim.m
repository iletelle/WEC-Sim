%% WEC-Sim run file
tic; clc; bdclose('all');

%% Initiate the simulation class and specify input file name
simu = simulationClass;

%% Read input file
waves.randPreDefined = 0;
evalc([simu.inputFile]);

%% Start WEC-Sim log
diary off; 
if exist('simulation.log','file') 
    delete('simulation.log'); 
end
diary('simulation.log')

%% Load SimMecahnics file
simu.loadSimMechModel(simu.simMechanicsFile);

%% Count bodies, constraints, and PTOs
simu.numWecBodies = length(body(1,:));
if exist('constraint','var') == 1
    simu.numConstraints = length(constraint(1,:));
end
if exist('pto','var') == 1
    simu.numPtos = length(pto(1,:));
end

%% Check hydro data
checkBem(body)

%% Wave Setup
waveSetup

%% HydroForce Pre-Processing
for kk = 1:simu.numWecBodies
    body(kk).hydroForcePre(waves.w,simu.CIkt,simu.numFreq,simu.dt,simu.rho,waves.type);
end

%% Output All the Simulation and Model Setting
listSimulationParameters;
%bodies]
fprintf('\nList of Body: ');
fprintf('Number of Bodies = %u \n',simu.numWecBodies)
for i = 1:simu.numWecBodies
    body(i).listBodyInfo
end
%ptos and constraints
listPtoConstraints;

%% Run Simulation
fprintf(['\nSimulating the WEC device defined in the SimMechanics '...
   'model %s...   \n'],simu.simMechanicsFile)
for iBod = 1:simu.numWecBodies
    body(iBod).adjustMassMatrix;
end
sim(simu.simMechanicsFile);
for iBod = 1:simu.numWecBodies
    body(iBod).restoreMassMatrix;
end
fprintf('\n')

%% Post processing and Saving Results
postResponse

%% User Defined Post Processing Processing (e.g., calculate average power)
if exist('userDefinedFunctions.m','file') == 2
    userDefinedFunctions;                
end

clear ans
toc
diary off
save(simu.caseFile)
movefile('simulation.log',simu.logFile)

