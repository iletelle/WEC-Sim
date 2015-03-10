
%% Wave Information
% Wave Information: Regular Waves
waves = waveClass('regular');%'regularCIC';
waves.H = 3.0;
waves.T = 14.0;

%% Simulation Data
simu = simulationClass();
simu.startTime = 0;
simu.rampT = 25*waves.T;
simu.endTime = 100*waves.T;
simu.dt = waves.T/200;
simu.simMechanicsFile = 'foswec.slx';
simu.mode = 'rapid-accelerator';
simu.explorer = 'off';
% simu.CITime = 63;
% simu.numFreq = 1001;
 
%% Body Data

%Body 1: Flap 1 (r,-)
body(1) = bodyClass('hydroData/WAMIT/oswec.h5',1);
diff = 0.5*1136958.21;
body(1).mass = 1136958.21 - diff;
body(1).momOfInertia = [76.9955, 25.6662, 52.8373] * body(1).mass; 
body(1).geometryFile = '../geom/Flap.stl';
body(1).viscDrag.cd = [0,0,0,0,8,0];
body(1).viscDrag.characteristicArea = [0,0,0,0,0.25*25*16^4,0];

%Body 2: Flap 2 (l,+)
body(2) = bodyClass('hydroData/WAMIT/oswec.h5',2);
body(2).mass = 1136958.21 - diff;
body(2).momOfInertia = [76.9955, 25.6662, 52.8373] * body(2).mass; 
body(2).geometryFile = '../geom/Flap.stl';
body(2).viscDrag.cd = [0,0,0,0,8,0];
body(2).viscDrag.characteristicArea = [0,0,0,0,0.25*25*16^4,0];


%Body 3: Platform
body(3) = bodyClass('hydroData/WAMIT/oswec.h5',3);
body(3).mass = 541618.81 + 2*diff;
body(3).momOfInertia = [196.3548, 248.3423, 391.4806] * body(3).mass; 
body(3).geometryFile = '../geom/Platform.stl';
body(3).viscDrag.cd = [0,0,0,0,0,0];
body(3).viscDrag.characteristicArea = [0,0,0,0,0,0];

%% PTO and Constraint Parameters

% PTO1 - Flap 1 Pitch
pto(1) = ptoClass('flap1pitch');
pto(1).loc = [-20 0 -16];
pto(1).k = 0;
pto(1).c = 0;

% PTO2 - Flap 2 Pitch
pto(2) = ptoClass('flap2pitch');
pto(2).loc = [20 0 -16];
pto(2).k = 0;
pto(2).c = 0;

% Constraint 1 - Platform Constraint
constraint(1) = constraintClass('platformFixed');
constraint(1).loc = body(3).hydroData.properties.cg;