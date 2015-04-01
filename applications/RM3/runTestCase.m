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

%% Run the WEC-Sim RM3 Test Case for 1DOF w/PTO
% This script will run the RM3 in WEC-Sim for regular waves with Hs=2.5[m] 
% and Tp=8[s]. The RM3 WEC models has 2 bodies, restricted to heave motion
% only, and has PTO damping=1200[kN-s/m]. This script compares results from
% the latest WEC-Sim run, to a previous compile of WEC-Sim. 
% For more info reference Ruehl OMAE 2014.
% 


%% Load Data and Run Simulation
wecSim;
new.time = output.bodies(1).time;
new.body1_heave = output.bodies(1).position(:,3) - output.bodies(1).position(1,3);
new.body2_heave = output.bodies(2).position(:,3) - output.bodies(2).position(1,3);
new.rel_heave = output.ptos(1).pos;
clear output;
 
load('output_org.mat');
org.time = output.bodies(1).time;
org.body1_heave = output.bodies(1).position(:,3) - output.bodies(1).position(1,3);
org.body2_heave = output.bodies(2).position(:,3) - output.bodies(2).position(1,3);
org.rel_heave = output.ptos(1).pos;
clear output;





%% Quantify Maximum Difference Between Saved and Current WEC-Sim Runs
[B1_H_max,B1_H_I]=max(abs(org.body1_heave - new.body1_heave));
[B2_H_max,B2_H_I]=max(abs(org.body2_heave - new.body2_heave));
[Rel_H_max,Rel_H_I]=max(abs(org.rel_heave - new.rel_heave));

fprintf(['\nBody1_Heave Max Diff = ' num2str(B1_H_max) ...
    ' m at time = ' num2str(org.time(B1_H_I)) 's\n'])
fprintf(['Body2_Heave Max Diff = ' num2str(B2_H_max) ...
    ' m at time = ' num2str(org.time(B2_H_I)) 's\n'])
fprintf(['Relative_Heave Max Diff = ' num2str(Rel_H_max) ...
    ' m at time = ' num2str(org.time(Rel_H_I)) 's\n'])





%% Plot Heave Comparisons
figure()%figure('units','normalized','outerposition',[0 0 1 1]);
% First Row: t=0-400s
% Second Row: t=350-400s

%First Column: Body 1 Heave
subplot(2,3,1)
plot(org.time, org.body1_heave, 'r-',...
     new.time, new.body1_heave, 'k-')
xlabel('time(s)')
ylabel('Heave(m)')
title('Float')
str1=['Max Diff = ' num2str(B1_H_max) ' m'];
str2=['at time = ' num2str(org.time(B1_H_I)) 's'];
a=text(10,1.5,str1);set(a,'FontSize',12)
a=text(10,1.2,str2);set(a,'FontSize',12)
xlim([0 400])
ylim([-2 2])

subplot(2,3,4)
m=plot(org.time(find(org.time==350):end),...
    org.body1_heave(find(org.time==350):end),'r-',...
    new.time(find(new.time==350):end),...
    new.body1_heave(find(new.time==350):end),'k-');
a=get(m(1),'LineWidth')+1;
set(m(1),'LineWidth',a)
xlabel('time(s)')
ylabel('Heave(m)')
xlim([350 400])
ylim([-2 2])


%Second Column: Body 2 Heave
subplot(2,3,2)
plot(org.time, org.body2_heave, 'r-',...
     new.time, new.body2_heave, 'k-')
xlabel('time(s)')
ylabel('Heave(m)')
title('Spar/Plate 1DOF')
str1=['Max Diff = ' num2str(B2_H_max) ' m'];
str2=['at time = ' num2str(org.time(B2_H_I)) 's'];
a=text(10,1.5,str1);set(a,'FontSize',12)
a=text(10,1.2,str2);set(a,'FontSize',12)
xlim([0 400])
ylim([-0.4 0.4])

subplot(2,3,5)
m=plot(org.time(find(org.time==350):end),...
    org.body2_heave(find(org.time==350):end),'r-',...
    new.time(find(new.time==350):end),...
    new.body2_heave(find(new.time==350):end),'k-');
a=get(m(1),'LineWidth')+1;
set(m(1),'LineWidth',a)
xlabel('time(s)')
ylabel('Heave(m)')
xlim([350 400])
ylim([-0.4 0.4])


%Third Column: Relative Heave
subplot(2,3,3)
plot(org.time, org.rel_heave, 'r-',...
     new.time, new.rel_heave, 'k-')
xlabel('time(s)')
ylabel('Heave(m)')
title('Relative Motion')
str1=['Max Diff = ' num2str(Rel_H_max) ' m'];
str2=['at time = ' num2str(org.time(Rel_H_I)) 's'];
a=text(10,1.5,str1);set(a,'FontSize',12)
a=text(10,1.2,str2);set(a,'FontSize',12)
xlim([0 400])
ylim([-2 2])
legend('org','new')

subplot(2,3,6)
m=plot(org.time(find(org.time==350):end),...
    org.rel_heave(find(org.time==350):end),'r-',...
    new.time(find(new.time==350):end),...
    new.rel_heave(find(new.time==350):end),'k-');
a=get(m(1),'LineWidth')+1;
set(m(1),'LineWidth',a)
xlabel('time(s)')
ylabel('Heave(m)')
xlim([350 400])
ylim([-2 2])



%%
test.new = new;
test.org = org;
clear h m str1 str2 a B1_H_max B1_H_I B2_H_max B2_H_I Rel_H_max Rel_H_I new org





