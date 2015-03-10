  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 54;
      section.data(54)  = dumData; %prealloc
      
	  ;% rtP.DampingForces_Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.WaveType_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% rtP.InitialZeroVelocity_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 37;
	
	  ;% rtP.ImpulseResponseFunctionK_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3643;
	
	  ;% rtP.Timerelativetothecurrenttimestep_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25279;
	
	  ;% rtP.TransportDelay_Delay
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 25880;
	
	  ;% rtP.TransportDelay_InitOutput
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 25881;
	
	  ;% rtP.AddedMassForces_Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 25882;
	
	  ;% rtP.DispforRotation1_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 25918;
	
	  ;% rtP.Gravity_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 25924;
	
	  ;% rtP.GravityForce_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 25925;
	
	  ;% rtP.Density_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 25926;
	
	  ;% rtP.Gravity1_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 25927;
	
	  ;% rtP.GravityForce1_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 25928;
	
	  ;% rtP.CenterofGravity_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 25929;
	
	  ;% rtP.DispforRotation_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 25932;
	
	  ;% rtP.RestoringForces_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 25935;
	
	  ;% rtP.ViscousDamping_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25971;
	
	  ;% rtP.LinearDamping_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 26007;
	
	  ;% rtP.CenterofGravity_Value_ehagwuwxhi
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 26043;
	
	  ;% rtP.DispforRotation_Value_n4dcoglnve
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 26046;
	
	  ;% rtP.MooringStiffness_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 26049;
	
	  ;% rtP.MooringDamping_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26050;
	
	  ;% rtP.MooringPreTension_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26051;
	
	  ;% rtP.RampFunctionTime_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 26052;
	
	  ;% rtP.WaveType_Value_ghmpcbwqgc
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 26053;
	
	  ;% rtP.DampingForces_Gain_lg5w5letwj
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26054;
	
	  ;% rtP.WaveType_Value_kmlj0k40q4
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 26090;
	
	  ;% rtP.InitialZeroVelocity_Value_espd2duag2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 26091;
	
	  ;% rtP.ImpulseResponseFunctionK_Value_oxs4p44uy4
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29697;
	
	  ;% rtP.Timerelativetothecurrenttimestep_Value_pdxfuxlbzx
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 72969;
	
	  ;% rtP.TransportDelay_Delay_idbp52hm4z
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 73570;
	
	  ;% rtP.TransportDelay_InitOutput_ok1nab0an0
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 73571;
	
	  ;% rtP.AddedMassForces_Gain_nn4j25aboc
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 73572;
	
	  ;% rtP.DispforRotation1_Value_bb2prsf5d3
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 73608;
	
	  ;% rtP.Gravity_Value_l5d2lookat
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 73614;
	
	  ;% rtP.GravityForce_Value_cfqmx3j5kp
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 73615;
	
	  ;% rtP.Density_Value_aih4vdbghl
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 73616;
	
	  ;% rtP.Gravity1_Value_mtxwpjdnnl
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 73617;
	
	  ;% rtP.GravityForce1_Value_lk4e3aezgl
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 73618;
	
	  ;% rtP.CenterofGravity_Value_md1kocvst4
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 73619;
	
	  ;% rtP.DispforRotation_Value_e2df3x2zha
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 73622;
	
	  ;% rtP.RestoringForces_Gain_gtjxe5fum0
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 73625;
	
	  ;% rtP.ViscousDamping_Gain_muya5lc1kx
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 73661;
	
	  ;% rtP.LinearDamping_Gain_bf1ntj5xm0
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 73697;
	
	  ;% rtP.CenterofGravity_Value_b3htdqbdxy
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 73733;
	
	  ;% rtP.DispforRotation_Value_hu2rwtrpwt
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 73736;
	
	  ;% rtP.MooringStiffness_Gain_ftpngfcbjw
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 73739;
	
	  ;% rtP.MooringDamping_Gain_hnfjdm1021
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 73740;
	
	  ;% rtP.MooringPreTension_Value_klqp1nyvd4
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 73741;
	
	  ;% rtP.RampFunctionTime_Value_n3y3wgeehz
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 73742;
	
	  ;% rtP.WaveType_Value_cigtbjvhxd
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 73743;
	
	  ;% rtP.PCCStiffnessCoefficient_Value
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 73744;
	
	  ;% rtP.PCCDampingCoefficient_Value
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 73745;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.kw4gz4nylz.Constant1_Value
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.kw4gz4nylz.SineWave_Amp
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.kw4gz4nylz.SineWave_Bias
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.kw4gz4nylz.SineWave_Freq
	  section.data(4).logicalSrcIdx = 57;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.kw4gz4nylz.SineWave_Phase
	  section.data(5).logicalSrcIdx = 58;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.kw4gz4nylz.Constant_Value
	  section.data(6).logicalSrcIdx = 59;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.arvvtfsmo3.ExcitationRePart2_Value
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.arvvtfsmo3.ExcitationRePart3_Value
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtP.arvvtfsmo3.wavespectrum_Value
	  section.data(3).logicalSrcIdx = 62;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtP.arvvtfsmo3.wavefrequency_Value
	  section.data(4).logicalSrcIdx = 63;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtP.arvvtfsmo3.dw1_Value
	  section.data(5).logicalSrcIdx = 64;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtP.arvvtfsmo3.wavefrequency1_Value
	  section.data(6).logicalSrcIdx = 65;
	  section.data(6).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.arvvtfsmo3.izalnoy5rm.CosWaveFunction_Amp
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.arvvtfsmo3.izalnoy5rm.CosWaveFunction_Bias
	  section.data(2).logicalSrcIdx = 67;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.arvvtfsmo3.izalnoy5rm.CosWaveFunction_Freq
	  section.data(3).logicalSrcIdx = 68;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.arvvtfsmo3.izalnoy5rm.CosWaveFunction_Phase
	  section.data(4).logicalSrcIdx = 69;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.arvvtfsmo3.izalnoy5rm.SinWaveFunction_Amp
	  section.data(5).logicalSrcIdx = 70;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.arvvtfsmo3.izalnoy5rm.SinWaveFunction_Bias
	  section.data(6).logicalSrcIdx = 71;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.arvvtfsmo3.izalnoy5rm.SinWaveFunction_Freq
	  section.data(7).logicalSrcIdx = 72;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.arvvtfsmo3.izalnoy5rm.SinWaveFunction_Phase
	  section.data(8).logicalSrcIdx = 73;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtP.bt1qvoldbv.CosWave_Amp
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.bt1qvoldbv.CosWave_Bias
	  section.data(2).logicalSrcIdx = 75;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.bt1qvoldbv.CosWave_Freq
	  section.data(3).logicalSrcIdx = 76;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.bt1qvoldbv.CosWave_Phase
	  section.data(4).logicalSrcIdx = 77;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.bt1qvoldbv.BEMExcitationRePart_Value
	  section.data(5).logicalSrcIdx = 78;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.bt1qvoldbv.SinWave_Amp
	  section.data(6).logicalSrcIdx = 79;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtP.bt1qvoldbv.SinWave_Bias
	  section.data(7).logicalSrcIdx = 80;
	  section.data(7).dtTransOffset = 11;
	
	  ;% rtP.bt1qvoldbv.SinWave_Freq
	  section.data(8).logicalSrcIdx = 81;
	  section.data(8).dtTransOffset = 12;
	
	  ;% rtP.bt1qvoldbv.SinWave_Phase
	  section.data(9).logicalSrcIdx = 82;
	  section.data(9).dtTransOffset = 13;
	
	  ;% rtP.bt1qvoldbv.BEMExcitationImPart1_Value
	  section.data(10).logicalSrcIdx = 83;
	  section.data(10).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.l1kcj50fwey.Constant1_Value
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.l1kcj50fwey.SineWave_Amp
	  section.data(2).logicalSrcIdx = 85;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.l1kcj50fwey.SineWave_Bias
	  section.data(3).logicalSrcIdx = 86;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.l1kcj50fwey.SineWave_Freq
	  section.data(4).logicalSrcIdx = 87;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.l1kcj50fwey.SineWave_Phase
	  section.data(5).logicalSrcIdx = 88;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.l1kcj50fwey.Constant_Value
	  section.data(6).logicalSrcIdx = 89;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.aqx150ksytr.ExcitationRePart2_Value
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.aqx150ksytr.ExcitationRePart3_Value
	  section.data(2).logicalSrcIdx = 91;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtP.aqx150ksytr.wavespectrum_Value
	  section.data(3).logicalSrcIdx = 92;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtP.aqx150ksytr.wavefrequency_Value
	  section.data(4).logicalSrcIdx = 93;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtP.aqx150ksytr.dw1_Value
	  section.data(5).logicalSrcIdx = 94;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtP.aqx150ksytr.wavefrequency1_Value
	  section.data(6).logicalSrcIdx = 95;
	  section.data(6).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.aqx150ksytr.izalnoy5rm.CosWaveFunction_Amp
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.aqx150ksytr.izalnoy5rm.CosWaveFunction_Bias
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.aqx150ksytr.izalnoy5rm.CosWaveFunction_Freq
	  section.data(3).logicalSrcIdx = 98;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.aqx150ksytr.izalnoy5rm.CosWaveFunction_Phase
	  section.data(4).logicalSrcIdx = 99;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.aqx150ksytr.izalnoy5rm.SinWaveFunction_Amp
	  section.data(5).logicalSrcIdx = 100;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.aqx150ksytr.izalnoy5rm.SinWaveFunction_Bias
	  section.data(6).logicalSrcIdx = 101;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.aqx150ksytr.izalnoy5rm.SinWaveFunction_Freq
	  section.data(7).logicalSrcIdx = 102;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.aqx150ksytr.izalnoy5rm.SinWaveFunction_Phase
	  section.data(8).logicalSrcIdx = 103;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtP.i0grvgounuc.CosWave_Amp
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.i0grvgounuc.CosWave_Bias
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.i0grvgounuc.CosWave_Freq
	  section.data(3).logicalSrcIdx = 106;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.i0grvgounuc.CosWave_Phase
	  section.data(4).logicalSrcIdx = 107;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.i0grvgounuc.BEMExcitationRePart_Value
	  section.data(5).logicalSrcIdx = 108;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.i0grvgounuc.SinWave_Amp
	  section.data(6).logicalSrcIdx = 109;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtP.i0grvgounuc.SinWave_Bias
	  section.data(7).logicalSrcIdx = 110;
	  section.data(7).dtTransOffset = 11;
	
	  ;% rtP.i0grvgounuc.SinWave_Freq
	  section.data(8).logicalSrcIdx = 111;
	  section.data(8).dtTransOffset = 12;
	
	  ;% rtP.i0grvgounuc.SinWave_Phase
	  section.data(9).logicalSrcIdx = 112;
	  section.data(9).dtTransOffset = 13;
	
	  ;% rtP.i0grvgounuc.BEMExcitationImPart1_Value
	  section.data(10).logicalSrcIdx = 113;
	  section.data(10).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% rtB.e3kvmjjnay
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.pzk0tdps0y
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.eygknao1u4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtB.fengm4fmax
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 33;
	
	  ;% rtB.prqhmb3ipp
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 39;
	
	  ;% rtB.hbwwq3eobw
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 45;
	
	  ;% rtB.lodjazp425
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 51;
	
	  ;% rtB.m1oa4qzzhe
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 57;
	
	  ;% rtB.gvkcwsrbjc
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 63;
	
	  ;% rtB.e25y0jyyb1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 69;
	
	  ;% rtB.gh1qfaqu5w
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 75;
	
	  ;% rtB.oci4zspmmv
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 81;
	
	  ;% rtB.biiiks5bdq
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 87;
	
	  ;% rtB.bweohccgoh
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 91;
	
	  ;% rtB.eyb1czk053
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 95;
	
	  ;% rtB.hoyspdnpx3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 99;
	
	  ;% rtB.kia00mwvqk
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 103;
	
	  ;% rtB.jr2ghgakgm
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 107;
	
	  ;% rtB.emwpmefl5g
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 111;
	
	  ;% rtB.jqhg2efiao
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 117;
	
	  ;% rtB.bsey3hhgmx
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 123;
	
	  ;% rtB.dxffftz4xe
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 129;
	
	  ;% rtB.jcjoil1xwx
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 135;
	
	  ;% rtB.ahbtwvlwht
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 141;
	
	  ;% rtB.gxr43wuykr
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 147;
	
	  ;% rtB.fn50r1iv2s
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 153;
	
	  ;% rtB.edbqtdapxx
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 159;
	
	  ;% rtB.mionfsauuc
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 165;
	
	  ;% rtB.lkkej41yzf
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 169;
	
	  ;% rtB.k02keb4tly
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 173;
	
	  ;% rtB.hoc2fuxv0g
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 177;
	
	  ;% rtB.gbda5p2r2f
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 181;
	
	  ;% rtB.j1dwgbinuj
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 185;
	
	  ;% rtB.hahanrb1fp
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 189;
	
	  ;% rtB.etx2cwdnb4
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 213;
	
	  ;% rtB.o3ytx35x4v
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 219;
	
	  ;% rtB.b13mdyyvoc
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 285;
	
	  ;% rtB.lle3duusb5
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 351;
	
	  ;% rtB.mcslv3o4nz
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 352;
	
	  ;% rtB.ovrdoaeae5
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 353;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.gk1vvo5dud.pgkwjiqtkn
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.hxduip3sjb.pgkwjiqtkn
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 13;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% rtDW.jhsjwq4b1m
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hvjbqhm5oo
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtDW.df3rh4z0gd
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtDW.owzp013kx2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtDW.m3h1jcujy4
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtDW.hts5jxxzji
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtDW.md4q5iksqt
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtDW.mbkovhbhoz
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 14;
	
	  ;% rtDW.mfpmp4gwws
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% rtDW.nzqg25m1lg
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 18;
	
	  ;% rtDW.l1g0f5hnak
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 20;
	
	  ;% rtDW.oqwcwkuk03
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 22;
	
	  ;% rtDW.cvt2mfevlv
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 24;
	
	  ;% rtDW.nyoeq2soc1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 3630;
	
	  ;% rtDW.ajv5jtlwij
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 3631;
	
	  ;% rtDW.pe4ejkzi2m
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 7237;
	
	  ;% rtDW.nbfng2z4ir.modelTStart
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 7238;
	
	  ;% rtDW.db2mbofoip.modelTStart
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 7239;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% rtDW.lm3sijg1j1
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.dhyxq0jnh5
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.f4urr54u23
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.mvbmsho13j
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.lcyjf3fqb0
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.agkrcbkdh5
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.njkjfcqdc3
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.kieznzt55p
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.focflcnmnv
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.oyfyizkz25
	  section.data(10).logicalSrcIdx = 27;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.aqyccuzu4f.TUbufferPtrs
	  section.data(11).logicalSrcIdx = 28;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.pj0j1eoun4.TUbufferPtrs
	  section.data(12).logicalSrcIdx = 29;
	  section.data(12).dtTransOffset = 22;
	
	  ;% rtDW.dfba0ayog2
	  section.data(13).logicalSrcIdx = 30;
	  section.data(13).dtTransOffset = 34;
	
	  ;% rtDW.mb1a41sbow
	  section.data(14).logicalSrcIdx = 31;
	  section.data(14).dtTransOffset = 35;
	
	  ;% rtDW.mqwpk5opbx
	  section.data(15).logicalSrcIdx = 32;
	  section.data(15).dtTransOffset = 36;
	
	  ;% rtDW.ppcwemgz0a
	  section.data(16).logicalSrcIdx = 33;
	  section.data(16).dtTransOffset = 37;
	
	  ;% rtDW.dt3ok1ryhy
	  section.data(17).logicalSrcIdx = 34;
	  section.data(17).dtTransOffset = 38;
	
	  ;% rtDW.grkodaq2kd
	  section.data(18).logicalSrcIdx = 35;
	  section.data(18).dtTransOffset = 39;
	
	  ;% rtDW.hjs5z0ka4j
	  section.data(19).logicalSrcIdx = 36;
	  section.data(19).dtTransOffset = 40;
	
	  ;% rtDW.hafmpp5qwx
	  section.data(20).logicalSrcIdx = 37;
	  section.data(20).dtTransOffset = 41;
	
	  ;% rtDW.hinmghz5iq
	  section.data(21).logicalSrcIdx = 38;
	  section.data(21).dtTransOffset = 42;
	
	  ;% rtDW.ebufosmij4
	  section.data(22).logicalSrcIdx = 39;
	  section.data(22).dtTransOffset = 43;
	
	  ;% rtDW.kmx1camcmy.LoggedData
	  section.data(23).logicalSrcIdx = 40;
	  section.data(23).dtTransOffset = 44;
	
	  ;% rtDW.jzxtw4vtua.LoggedData
	  section.data(24).logicalSrcIdx = 41;
	  section.data(24).dtTransOffset = 45;
	
	  ;% rtDW.ce1jzkjckk.LoggedData
	  section.data(25).logicalSrcIdx = 42;
	  section.data(25).dtTransOffset = 46;
	
	  ;% rtDW.mmokpjpvho.LoggedData
	  section.data(26).logicalSrcIdx = 43;
	  section.data(26).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.anmk1ei3yl.Tail
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ke454bg2ir.Tail
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.bxqmm1o411
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.nofdnsita2
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.if5tadkli2
	  section.data(3).logicalSrcIdx = 48;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.gn2tshspwh
	  section.data(4).logicalSrcIdx = 49;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.fk22kz5jyq
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.g5k0jhqbfv
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.cq0zpszeap
	  section.data(3).logicalSrcIdx = 52;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.ks0u35sdaj
	  section.data(4).logicalSrcIdx = 53;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.ba32jnnpzi
	  section.data(5).logicalSrcIdx = 54;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.hfpj0irdgz
	  section.data(6).logicalSrcIdx = 55;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cy14v3kgd2.dbhao2hevj
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.kw4gz4nylz.ckdn4xd4hz
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.arvvtfsmo3.ofnp3tiibi
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.bt1qvoldbv.e2lhwvg4n3
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.p14hwlcq5ag.dbhao2hevj
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.l1kcj50fwey.ckdn4xd4hz
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.aqx150ksytr.ofnp3tiibi
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.i0grvgounuc.e2lhwvg4n3
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1252914586;
  targMap.checksum1 = 3362424525;
  targMap.checksum2 = 2296161348;
  targMap.checksum3 = 934207540;

