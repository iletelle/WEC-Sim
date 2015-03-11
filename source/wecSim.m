%%% WEC-Sim run file
%% Start WEC-Sim log
bdclose('all'); clc; diary off; 
if exist('simulation.log','file'); delete('simulation.log'); end
diary('simulation.log')


%% Read input file
fprintf('\nWEC-Sim Read Input File ...   \n'); tic; 
evalc('wecSimInputFile');
toc;

%% Setup simulation
fprintf('\nWEC-Sim Pre-processing ...   \n'); tic;
simu.numWecBodies = length(body(1,:));
if exist('constraint','var') == 1; simu.numConstraints = length(constraint(1,:)); end
if exist('pto','var') == 1; simu.numPtos = length(pto(1,:)); end


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
end; clear ii; toc;


%% HydroForces Pre-Processing: Wave Setup & HydroForcePre
tic;
fprintf('\nWEC-Sim Wave Setup & Model Setup & Run WEC-Sim ...   \n')
waves.waveSetup(body(1).hydroData.simulation_parameters.w, body(1).hydroData.simulation_parameters.wDepth, simu.rampT, simu.dt, simu.maxIt, simu.g); 
for kk = 1:simu.numWecBodies
    body(kk).hydroForcePre(waves.w,simu.CIkt,waves.numFreq,simu.dt,simu.rho,waves.type,kk);
end; clear kk


%% Output All the Simulation and Model Setting
listSimulationParameters;

waves.listInfo

fprintf('\nList of Body: ');
fprintf('Number of Bodies = %u \n',simu.numWecBodies)
for i = 1:simu.numWecBodies
    body(i).listInfo
end;  clear i

fprintf('\nList of PTO(s): ');
if (exist('pto','var') == 0)
    fprintf('No PTO in the system\n')
else
    fprintf('Number of PTOs = %G \n',length(pto(1,:)))
    for i=1:simu.numPtos
        pto(i).listInfo
    end; clear i
end

fprintf('\nList of Constraint(s): ');
if (exist('constraint','var') == 0)
    fprintf('No Constraint in the system\n')
else
    fprintf('Number of Constraints = %G \n',length(constraint(1,:)))
    for i=1:simu.numConstraints
        constraint(i).listInfo
    end; clear i
end


%% Load simMechanics file & Run Simulation
fprintf('\nSimulating the WEC device defined in the SimMechanics model %s...   \n',simu.simMechanicsFile)
simu.loadSimMechModel(simu.simMechanicsFile);
for iBod = 1:simu.numWecBodies; body(iBod).adjustMassMatrix; end; clear iBod
tDelayWarning = 'Simulink:blocks:TDelayTimeTooSmall';
warning('off',tDelayWarning); clear tDelayWarning
if simu.rampT == 0; simu.rampT = 10e-8; end
if strcmp(simu.explorer,'on') &&  ~isfloat(waves.waterDepth)
    waves.waterDepth = 200;
    warning('Invalid water depth given. waves.waterDepth set to 200m for vizualisation.')
end
sim(simu.simMechanicsFile);
if simu.rampT == 10e-8; simu.rampT = 0; end
postResponse
for iBod = 1:simu.numWecBodies
    body(iBod).restoreMassMatrix
    body(iBod).storeForceAddedMass(output.bodies(iBod).forceAddedMass)
    output.bodies(iBod).forceAddedMass = body(iBod).forceAddedMass(output.bodies(iBod).acceleration);
end; clear iBod
fprintf('\n')

%% Post processing and Saving Results
if exist('userDefinedFunctions.m','file') == 2
    userDefinedFunctions;                
end
clear ans; toc; 

diary off; movefile('simulation.log',simu.logFile)
save(simu.caseFile)

