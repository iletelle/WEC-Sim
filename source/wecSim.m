%%% WEC-Sim run file
%% Start WEC-Sim log
tic; bdclose('all'); clc; diary off; 
if exist('simulation.log','file'); delete('simulation.log'); end
diary('simulation.log')


%% Read input file
evalc([simu.inputFile]);


%% Setup simulation and load simMechanics file
fprintf('\nWEC-Sim Pre-processing ...   \n')
simu.numWecBodies = length(body(1,:));
if exist('constraint','var') == 1; simu.numConstraints = length(constraint(1,:)); end
if exist('pto','var') == 1; simu.numPtos = length(pto(1,:)); end
simu.loadSimMechModel(simu.simMechanicsFile);


%% Check that the hydro data for each body is given for the same frequencies
for ii = 1:simu.numWecBodies
    if length(body(1).hydroData.simulation_parameters.w) ~= length(body(ii).hydroData.simulation_parameters.w)
       error('BEM simulations for each body must have the same number of frequencies')
    else
       for jj = 1:length(body(1).hydroData.simulation_parameters.w)
           if body(1).hydroData.simulation_parameters.w(jj) ~= body(ii).hydroData.simulation_parameters.w(jj)
              error('BEM simulations must be run with the same frequencies.')
           end; clear jj;
       end
    end
end; clear ii;


%% HydroForces Pre-Processing: Wave Setup & HydroForcePre
waves.waveSetup(simu.numFreq, body(1).hydroData.simulation_parameters.w, body(1).hydroData.simulation_parameters.wDepth, simu.rampT, simu.dt, simu.maxIt); 
for kk = 1:simu.numWecBodies
    body(kk).hydroForcePre(waves.w,simu.CIkt,simu.numFreq,simu.dt,simu.rho,waves.type);
end

%% Output All the Simulation and Model Setting
listSimulationParameters;
waves.listInfo
fprintf('\nList of Body: ');
fprintf('Number of Bodies = %u \n',simu.numWecBodies)
for i = 1:simu.numWecBodies
    body(i).listInfo
end
listPtoConstraints;

%% Run Simulation
fprintf('\nSimulating the WEC device defined in the SimMechanics model %s...   \n',simu.simMechanicsFile)
for iBod = 1:simu.numWecBodies; body(iBod).adjustMassMatrix; end
sim(simu.simMechanicsFile);
for iBod = 1:simu.numWecBodies; body(iBod).restoreMassMatrix; end
fprintf('\n')

%% Post processing and Saving Results
postResponse
if exist('userDefinedFunctions.m','file') == 2
    userDefinedFunctions;                
end
clear ans; toc; diary off; movefile('simulation.log',simu.logFile)
save(simu.caseFile)

