  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 13;
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
      section.nData     = 90;
      section.data(90)  = dumData; %prealloc
      
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
	  section.data(4).dtTransOffset = 5191;
	
	  ;% rtP.Timerelativetothecurrenttimestep_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 36115;
	
	  ;% rtP.TransportDelay_Delay
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 36974;
	
	  ;% rtP.TransportDelay_InitOutput
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 36975;
	
	  ;% rtP.AddedMassForces_Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 36976;
	
	  ;% rtP.DispforRotation1_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 37012;
	
	  ;% rtP.Gravity_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 37018;
	
	  ;% rtP.GravityForce_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 37019;
	
	  ;% rtP.Density_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 37020;
	
	  ;% rtP.Gravity1_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 37021;
	
	  ;% rtP.GravityForce1_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 37022;
	
	  ;% rtP.CenterofGravity_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 37023;
	
	  ;% rtP.DispforRotation_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 37026;
	
	  ;% rtP.RestoringForces_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 37029;
	
	  ;% rtP.ViscousDamping_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 37065;
	
	  ;% rtP.LinearDamping_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 37101;
	
	  ;% rtP.CenterofGravity_Value_kv4jtzv4sz
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 37137;
	
	  ;% rtP.DispforRotation_Value_e2awq1sqk5
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 37140;
	
	  ;% rtP.MooringStiffness_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 37143;
	
	  ;% rtP.MooringDamping_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 37144;
	
	  ;% rtP.MooringPreTension_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 37145;
	
	  ;% rtP.RampFunctionTime_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 37146;
	
	  ;% rtP.WaveType_Value_lnsink2wos
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 37147;
	
	  ;% rtP.DampingForces_Gain_gmglkqwyrk
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 37148;
	
	  ;% rtP.WaveType_Value_brm2lvz52e
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 37184;
	
	  ;% rtP.InitialZeroVelocity_Value_mbg4rllwz5
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 37185;
	
	  ;% rtP.ImpulseResponseFunctionK_Value_fjjrzbclsj
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 42339;
	
	  ;% rtP.Timerelativetothecurrenttimestep_Value_jpehs0wqht
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 73263;
	
	  ;% rtP.TransportDelay_Delay_bp43gzj5e3
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 74122;
	
	  ;% rtP.TransportDelay_InitOutput_ii0y22uej3
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 74123;
	
	  ;% rtP.AddedMassForces_Gain_oroqvzk1e4
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 74124;
	
	  ;% rtP.DispforRotation1_Value_o3itv5xzx4
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 74160;
	
	  ;% rtP.Gravity_Value_gftrulwsfn
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 74166;
	
	  ;% rtP.GravityForce_Value_bwfmpxsvsr
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 74167;
	
	  ;% rtP.Density_Value_nszowylvmf
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 74168;
	
	  ;% rtP.Gravity1_Value_gkp4y35w4n
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 74169;
	
	  ;% rtP.GravityForce1_Value_ipgtikjaun
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 74170;
	
	  ;% rtP.CenterofGravity_Value_moatrz5qxk
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 74171;
	
	  ;% rtP.DispforRotation_Value_ocikgyapyh
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 74174;
	
	  ;% rtP.RestoringForces_Gain_cyy4gncipu
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 74177;
	
	  ;% rtP.ViscousDamping_Gain_k1dk0v0wf1
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 74213;
	
	  ;% rtP.LinearDamping_Gain_gt4kyc33is
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 74249;
	
	  ;% rtP.CenterofGravity_Value_idcvji535z
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 74285;
	
	  ;% rtP.DispforRotation_Value_ftba4kbp25
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 74288;
	
	  ;% rtP.MooringStiffness_Gain_l3g4tznmmz
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 74291;
	
	  ;% rtP.MooringDamping_Gain_loasej4jiy
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 74292;
	
	  ;% rtP.MooringPreTension_Value_n0e1y4yp2s
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 74293;
	
	  ;% rtP.RampFunctionTime_Value_mg4suvbwbg
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 74294;
	
	  ;% rtP.WaveType_Value_jdh1bnnh0l
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 74295;
	
	  ;% rtP.DampingForces_Gain_itl5dvfc3u
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74296;
	
	  ;% rtP.WaveType_Value_jkynzzqjsn
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 74332;
	
	  ;% rtP.InitialZeroVelocity_Value_gvmd2jy3st
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 74333;
	
	  ;% rtP.ImpulseResponseFunctionK_Value_i5uuouboea
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 79487;
	
	  ;% rtP.Timerelativetothecurrenttimestep_Value_kvgyp5pq4q
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 110411;
	
	  ;% rtP.TransportDelay_Delay_foibzxd41j
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 111270;
	
	  ;% rtP.TransportDelay_InitOutput_bf1kxbkfem
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 111271;
	
	  ;% rtP.AddedMassForces_Gain_icvgvsh5ju
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 111272;
	
	  ;% rtP.DispforRotation1_Value_dhyoflxvyp
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 111308;
	
	  ;% rtP.Gravity_Value_cx40ikecyz
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 111314;
	
	  ;% rtP.GravityForce_Value_nk3enkxm1g
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 111315;
	
	  ;% rtP.Density_Value_cwal0gh0jx
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 111316;
	
	  ;% rtP.Gravity1_Value_jzzrqnwdx1
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 111317;
	
	  ;% rtP.GravityForce1_Value_a3ipdgsubl
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 111318;
	
	  ;% rtP.CenterofGravity_Value_ffrrlkfvt3
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 111319;
	
	  ;% rtP.DispforRotation_Value_dwwryftswo
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 111322;
	
	  ;% rtP.RestoringForces_Gain_pooakzjpnq
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 111325;
	
	  ;% rtP.ViscousDamping_Gain_ibhby0wcea
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 111361;
	
	  ;% rtP.LinearDamping_Gain_f1vdp50wdd
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 111397;
	
	  ;% rtP.CenterofGravity_Value_izurzrsyhp
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 111433;
	
	  ;% rtP.DispforRotation_Value_md2plndz15
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 111436;
	
	  ;% rtP.MooringStiffness_Gain_ixw1h4sghu
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 111439;
	
	  ;% rtP.MooringDamping_Gain_nkhqr3tbky
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 111440;
	
	  ;% rtP.MooringPreTension_Value_p53dhtwkd4
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 111441;
	
	  ;% rtP.RampFunctionTime_Value_mnlhvccsmd
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 111442;
	
	  ;% rtP.WaveType_Value_cbd1s2tvax
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 111443;
	
	  ;% rtP.Gain3_Gain
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 111444;
	
	  ;% rtP.PCCStiffnessCoefficient_Value
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 111445;
	
	  ;% rtP.PCCDampingCoefficient_Value
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 111446;
	
	  ;% rtP.Gain2_Gain
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 111447;
	
	  ;% rtP.Gain1_Gain
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 111448;
	
	  ;% rtP.Gain_Gain
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 111449;
	
	  ;% rtP.Gain3_Gain_nxxgw4dkhx
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 111450;
	
	  ;% rtP.PCCStiffnessCoefficient_Value_bq4hxfosr4
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 111451;
	
	  ;% rtP.PCCDampingCoefficient_Value_p0lvrll2jb
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 111452;
	
	  ;% rtP.Gain2_Gain_kgiq1thyom
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 111453;
	
	  ;% rtP.Gain1_Gain_nupg4bxvwd
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 111454;
	
	  ;% rtP.Gain_Gain_crbn4vzgqb
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 111455;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.apfdt1mk1s.Constant1_Value
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.apfdt1mk1s.SineWave_Amp
	  section.data(2).logicalSrcIdx = 91;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.apfdt1mk1s.SineWave_Bias
	  section.data(3).logicalSrcIdx = 92;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.apfdt1mk1s.SineWave_Freq
	  section.data(4).logicalSrcIdx = 93;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.apfdt1mk1s.SineWave_Phase
	  section.data(5).logicalSrcIdx = 94;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.apfdt1mk1s.Constant_Value
	  section.data(6).logicalSrcIdx = 95;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.ogpjwh504b.ExcitationRePart2_Value
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.ogpjwh504b.ExcitationRePart3_Value
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtP.ogpjwh504b.wavespectrum_Value
	  section.data(3).logicalSrcIdx = 98;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtP.ogpjwh504b.wavefrequency_Value
	  section.data(4).logicalSrcIdx = 99;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtP.ogpjwh504b.dw1_Value
	  section.data(5).logicalSrcIdx = 100;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtP.ogpjwh504b.wavefrequency1_Value
	  section.data(6).logicalSrcIdx = 101;
	  section.data(6).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.ogpjwh504b.hq5rtzuhum.CosWaveFunction_Amp
	  section.data(1).logicalSrcIdx = 102;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.ogpjwh504b.hq5rtzuhum.CosWaveFunction_Bias
	  section.data(2).logicalSrcIdx = 103;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.ogpjwh504b.hq5rtzuhum.CosWaveFunction_Freq
	  section.data(3).logicalSrcIdx = 104;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.ogpjwh504b.hq5rtzuhum.CosWaveFunction_Phase
	  section.data(4).logicalSrcIdx = 105;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.ogpjwh504b.hq5rtzuhum.SinWaveFunction_Amp
	  section.data(5).logicalSrcIdx = 106;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.ogpjwh504b.hq5rtzuhum.SinWaveFunction_Bias
	  section.data(6).logicalSrcIdx = 107;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.ogpjwh504b.hq5rtzuhum.SinWaveFunction_Freq
	  section.data(7).logicalSrcIdx = 108;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.ogpjwh504b.hq5rtzuhum.SinWaveFunction_Phase
	  section.data(8).logicalSrcIdx = 109;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtP.fmempv5ety.CosWave_Amp
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.fmempv5ety.CosWave_Bias
	  section.data(2).logicalSrcIdx = 111;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.fmempv5ety.CosWave_Freq
	  section.data(3).logicalSrcIdx = 112;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.fmempv5ety.CosWave_Phase
	  section.data(4).logicalSrcIdx = 113;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.fmempv5ety.BEMExcitationRePart_Value
	  section.data(5).logicalSrcIdx = 114;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.fmempv5ety.SinWave_Amp
	  section.data(6).logicalSrcIdx = 115;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtP.fmempv5ety.SinWave_Bias
	  section.data(7).logicalSrcIdx = 116;
	  section.data(7).dtTransOffset = 11;
	
	  ;% rtP.fmempv5ety.SinWave_Freq
	  section.data(8).logicalSrcIdx = 117;
	  section.data(8).dtTransOffset = 12;
	
	  ;% rtP.fmempv5ety.SinWave_Phase
	  section.data(9).logicalSrcIdx = 118;
	  section.data(9).dtTransOffset = 13;
	
	  ;% rtP.fmempv5ety.BEMExcitationImPart1_Value
	  section.data(10).logicalSrcIdx = 119;
	  section.data(10).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.msblmfssu1.Constant1_Value
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.msblmfssu1.SineWave_Amp
	  section.data(2).logicalSrcIdx = 121;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.msblmfssu1.SineWave_Bias
	  section.data(3).logicalSrcIdx = 122;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.msblmfssu1.SineWave_Freq
	  section.data(4).logicalSrcIdx = 123;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.msblmfssu1.SineWave_Phase
	  section.data(5).logicalSrcIdx = 124;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.msblmfssu1.Constant_Value
	  section.data(6).logicalSrcIdx = 125;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.fkat0ywnxz.ExcitationRePart2_Value
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.fkat0ywnxz.ExcitationRePart3_Value
	  section.data(2).logicalSrcIdx = 127;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtP.fkat0ywnxz.wavespectrum_Value
	  section.data(3).logicalSrcIdx = 128;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtP.fkat0ywnxz.wavefrequency_Value
	  section.data(4).logicalSrcIdx = 129;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtP.fkat0ywnxz.dw1_Value
	  section.data(5).logicalSrcIdx = 130;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtP.fkat0ywnxz.wavefrequency1_Value
	  section.data(6).logicalSrcIdx = 131;
	  section.data(6).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.fkat0ywnxz.hq5rtzuhum.CosWaveFunction_Amp
	  section.data(1).logicalSrcIdx = 132;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.fkat0ywnxz.hq5rtzuhum.CosWaveFunction_Bias
	  section.data(2).logicalSrcIdx = 133;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.fkat0ywnxz.hq5rtzuhum.CosWaveFunction_Freq
	  section.data(3).logicalSrcIdx = 134;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.fkat0ywnxz.hq5rtzuhum.CosWaveFunction_Phase
	  section.data(4).logicalSrcIdx = 135;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.fkat0ywnxz.hq5rtzuhum.SinWaveFunction_Amp
	  section.data(5).logicalSrcIdx = 136;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.fkat0ywnxz.hq5rtzuhum.SinWaveFunction_Bias
	  section.data(6).logicalSrcIdx = 137;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.fkat0ywnxz.hq5rtzuhum.SinWaveFunction_Freq
	  section.data(7).logicalSrcIdx = 138;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.fkat0ywnxz.hq5rtzuhum.SinWaveFunction_Phase
	  section.data(8).logicalSrcIdx = 139;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtP.h5j4mvdijc.CosWave_Amp
	  section.data(1).logicalSrcIdx = 140;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.h5j4mvdijc.CosWave_Bias
	  section.data(2).logicalSrcIdx = 141;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.h5j4mvdijc.CosWave_Freq
	  section.data(3).logicalSrcIdx = 142;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.h5j4mvdijc.CosWave_Phase
	  section.data(4).logicalSrcIdx = 143;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.h5j4mvdijc.BEMExcitationRePart_Value
	  section.data(5).logicalSrcIdx = 144;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.h5j4mvdijc.SinWave_Amp
	  section.data(6).logicalSrcIdx = 145;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtP.h5j4mvdijc.SinWave_Bias
	  section.data(7).logicalSrcIdx = 146;
	  section.data(7).dtTransOffset = 11;
	
	  ;% rtP.h5j4mvdijc.SinWave_Freq
	  section.data(8).logicalSrcIdx = 147;
	  section.data(8).dtTransOffset = 12;
	
	  ;% rtP.h5j4mvdijc.SinWave_Phase
	  section.data(9).logicalSrcIdx = 148;
	  section.data(9).dtTransOffset = 13;
	
	  ;% rtP.h5j4mvdijc.BEMExcitationImPart1_Value
	  section.data(10).logicalSrcIdx = 149;
	  section.data(10).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.cnj3cuyx4ul.Constant1_Value
	  section.data(1).logicalSrcIdx = 150;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.cnj3cuyx4ul.SineWave_Amp
	  section.data(2).logicalSrcIdx = 151;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.cnj3cuyx4ul.SineWave_Bias
	  section.data(3).logicalSrcIdx = 152;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.cnj3cuyx4ul.SineWave_Freq
	  section.data(4).logicalSrcIdx = 153;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.cnj3cuyx4ul.SineWave_Phase
	  section.data(5).logicalSrcIdx = 154;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.cnj3cuyx4ul.Constant_Value
	  section.data(6).logicalSrcIdx = 155;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtP.h02m5m2hejt.ExcitationRePart2_Value
	  section.data(1).logicalSrcIdx = 156;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.h02m5m2hejt.ExcitationRePart3_Value
	  section.data(2).logicalSrcIdx = 157;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtP.h02m5m2hejt.wavespectrum_Value
	  section.data(3).logicalSrcIdx = 158;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtP.h02m5m2hejt.wavefrequency_Value
	  section.data(4).logicalSrcIdx = 159;
	  section.data(4).dtTransOffset = 13;
	
	  ;% rtP.h02m5m2hejt.dw1_Value
	  section.data(5).logicalSrcIdx = 160;
	  section.data(5).dtTransOffset = 14;
	
	  ;% rtP.h02m5m2hejt.wavefrequency1_Value
	  section.data(6).logicalSrcIdx = 161;
	  section.data(6).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtP.h02m5m2hejt.hq5rtzuhum.CosWaveFunction_Amp
	  section.data(1).logicalSrcIdx = 162;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.h02m5m2hejt.hq5rtzuhum.CosWaveFunction_Bias
	  section.data(2).logicalSrcIdx = 163;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.h02m5m2hejt.hq5rtzuhum.CosWaveFunction_Freq
	  section.data(3).logicalSrcIdx = 164;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.h02m5m2hejt.hq5rtzuhum.CosWaveFunction_Phase
	  section.data(4).logicalSrcIdx = 165;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.h02m5m2hejt.hq5rtzuhum.SinWaveFunction_Amp
	  section.data(5).logicalSrcIdx = 166;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.h02m5m2hejt.hq5rtzuhum.SinWaveFunction_Bias
	  section.data(6).logicalSrcIdx = 167;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.h02m5m2hejt.hq5rtzuhum.SinWaveFunction_Freq
	  section.data(7).logicalSrcIdx = 168;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.h02m5m2hejt.hq5rtzuhum.SinWaveFunction_Phase
	  section.data(8).logicalSrcIdx = 169;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtP.fzybd15s0q0.CosWave_Amp
	  section.data(1).logicalSrcIdx = 170;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.fzybd15s0q0.CosWave_Bias
	  section.data(2).logicalSrcIdx = 171;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.fzybd15s0q0.CosWave_Freq
	  section.data(3).logicalSrcIdx = 172;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.fzybd15s0q0.CosWave_Phase
	  section.data(4).logicalSrcIdx = 173;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.fzybd15s0q0.BEMExcitationRePart_Value
	  section.data(5).logicalSrcIdx = 174;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.fzybd15s0q0.SinWave_Amp
	  section.data(6).logicalSrcIdx = 175;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtP.fzybd15s0q0.SinWave_Bias
	  section.data(7).logicalSrcIdx = 176;
	  section.data(7).dtTransOffset = 11;
	
	  ;% rtP.fzybd15s0q0.SinWave_Freq
	  section.data(8).logicalSrcIdx = 177;
	  section.data(8).dtTransOffset = 12;
	
	  ;% rtP.fzybd15s0q0.SinWave_Phase
	  section.data(9).logicalSrcIdx = 178;
	  section.data(9).dtTransOffset = 13;
	
	  ;% rtP.fzybd15s0q0.BEMExcitationImPart1_Value
	  section.data(10).logicalSrcIdx = 179;
	  section.data(10).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
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
    nTotSects     = 7;
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
      section.nData     = 63;
      section.data(63)  = dumData; %prealloc
      
	  ;% rtB.gja4dzl325
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.blpo5iedij
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% rtB.hqtb5p5515
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 47;
	
	  ;% rtB.pnsa2f20mr
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 53;
	
	  ;% rtB.euxjdg3wyk
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 59;
	
	  ;% rtB.dlr5ya0rha
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 65;
	
	  ;% rtB.pr41rtecbf
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 71;
	
	  ;% rtB.merar43jbg
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 77;
	
	  ;% rtB.ihnthpc5j1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 83;
	
	  ;% rtB.fyev0m4vsa
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 89;
	
	  ;% rtB.dhfvei2wiq
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 90;
	
	  ;% rtB.b1n5unk4di
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 96;
	
	  ;% rtB.p1qklr3iem
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 102;
	
	  ;% rtB.dzcyvgjss1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 106;
	
	  ;% rtB.kyqswxndxu
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 110;
	
	  ;% rtB.os0vmujie2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 114;
	
	  ;% rtB.f5vdxtzttp
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 118;
	
	  ;% rtB.ny3ji5snoz
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 122;
	
	  ;% rtB.b3fkm4fcdn
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 126;
	
	  ;% rtB.jcuedl2jnj
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 132;
	
	  ;% rtB.o5jrwx140d
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 138;
	
	  ;% rtB.ggc0r0fx3g
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 144;
	
	  ;% rtB.njnofax133
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 150;
	
	  ;% rtB.amxl55ezpx
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 156;
	
	  ;% rtB.ihg0r14bhr
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 162;
	
	  ;% rtB.pj144ebf30
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 168;
	
	  ;% rtB.edopdfd1hm
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 174;
	
	  ;% rtB.kgii2iaa1l
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 180;
	
	  ;% rtB.jfce0w0ghr
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 184;
	
	  ;% rtB.pcf0pfmweo
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 188;
	
	  ;% rtB.if52phrmag
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 192;
	
	  ;% rtB.mocddkrpki
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 196;
	
	  ;% rtB.kzwkda2ehh
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 200;
	
	  ;% rtB.e0ns1clddv
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 204;
	
	  ;% rtB.hdrzhitnck
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 210;
	
	  ;% rtB.lkgzajb1kd
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 216;
	
	  ;% rtB.muoixesghk
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 222;
	
	  ;% rtB.jeu1moqvun
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 228;
	
	  ;% rtB.ialr351o51
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 234;
	
	  ;% rtB.j4t0l5sh1l
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 240;
	
	  ;% rtB.fnesyp43ae
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 246;
	
	  ;% rtB.okcf5s1hfi
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 252;
	
	  ;% rtB.hmeg1w5jim
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 258;
	
	  ;% rtB.nbocq1o42k
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 262;
	
	  ;% rtB.d5a52isphm
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 266;
	
	  ;% rtB.icy3aei5aw
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 270;
	
	  ;% rtB.add5kxxow3
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 274;
	
	  ;% rtB.oigl01ewmc
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 278;
	
	  ;% rtB.l5ibfslonp
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 282;
	
	  ;% rtB.ejgnutoxk4
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 318;
	
	  ;% rtB.cdoh40kylx
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 324;
	
	  ;% rtB.c4gqqn41jy
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 390;
	
	  ;% rtB.mhluogc5lp
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 456;
	
	  ;% rtB.miwvnyxkwg
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 522;
	
	  ;% rtB.gdetjhzpld
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 523;
	
	  ;% rtB.pr2wmuatwp
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 524;
	
	  ;% rtB.euklvqzjnb
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 527;
	
	  ;% rtB.hflxw2u4c0
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 530;
	
	  ;% rtB.l2wrpxekcz
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 538;
	
	  ;% rtB.jcjac2h4yl
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 539;
	
	  ;% rtB.g5gg5rwfxi
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 540;
	
	  ;% rtB.mb24q41lpq
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 543;
	
	  ;% rtB.kzugd0mwbk
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 546;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ipyob4ujct.jmbenplned
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.iluwjccpxx.c0mvqybgil
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.hbwafuhekh.jmbenplned
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.evtto0adau.c0mvqybgil
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.arymfxlfvv.jmbenplned
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.nd0v2sbydt.c0mvqybgil
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
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
    nTotSects     = 23;
    sectIdxOffset = 7;
    
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
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtDW.okejdpgu1c
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.k4kmsogsl5
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtDW.ihegmmijy4
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtDW.ojcm0w354h
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtDW.e2rajb5jef
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtDW.d1dr20wbil
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% rtDW.nbmftfajwj
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtDW.d4bgxhw4kx
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 14;
	
	  ;% rtDW.knlt4i5nhu
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% rtDW.phzhuqqbqj
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 18;
	
	  ;% rtDW.dblqjhlznj
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 20;
	
	  ;% rtDW.dwhzhgdlwe
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 22;
	
	  ;% rtDW.g4w5whunn0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 24;
	
	  ;% rtDW.ihejtbnivo
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 26;
	
	  ;% rtDW.kv0fr1ezds
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 28;
	
	  ;% rtDW.jvtm2q20yi
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 30;
	
	  ;% rtDW.csqplvugez
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 32;
	
	  ;% rtDW.b2ebqtdjfn
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 34;
	
	  ;% rtDW.cqf5illkg4.modelTStart
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 36;
	
	  ;% rtDW.l3gqrt0mpz.modelTStart
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 37;
	
	  ;% rtDW.m1arggegue.modelTStart
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% rtDW.pyei4aktas
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lav352kiwz
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.gknbsopy3r
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.k21g4xkqyw
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.gqikoc3gqq
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.d3bbzrpbvx
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.awgpzntukc
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.k13qfbrzod
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.l5glelo31i
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.iob1f2j3jw
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.ozvltbk2so.TUbufferPtrs
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.fv3pugwi2m.TUbufferPtrs
	  section.data(12).logicalSrcIdx = 32;
	  section.data(12).dtTransOffset = 22;
	
	  ;% rtDW.a1q2j3sqxq.TUbufferPtrs
	  section.data(13).logicalSrcIdx = 33;
	  section.data(13).dtTransOffset = 34;
	
	  ;% rtDW.kac3j5zyhm
	  section.data(14).logicalSrcIdx = 34;
	  section.data(14).dtTransOffset = 46;
	
	  ;% rtDW.mzt5dujgnf
	  section.data(15).logicalSrcIdx = 35;
	  section.data(15).dtTransOffset = 47;
	
	  ;% rtDW.hmwzsbnven
	  section.data(16).logicalSrcIdx = 36;
	  section.data(16).dtTransOffset = 48;
	
	  ;% rtDW.ejbhclilet
	  section.data(17).logicalSrcIdx = 37;
	  section.data(17).dtTransOffset = 49;
	
	  ;% rtDW.fvtzlyem05
	  section.data(18).logicalSrcIdx = 38;
	  section.data(18).dtTransOffset = 50;
	
	  ;% rtDW.facajaxtwh.LoggedData
	  section.data(19).logicalSrcIdx = 39;
	  section.data(19).dtTransOffset = 51;
	
	  ;% rtDW.ea2glvbgz2.LoggedData
	  section.data(20).logicalSrcIdx = 40;
	  section.data(20).dtTransOffset = 52;
	
	  ;% rtDW.fb5d5dwuih.LoggedData
	  section.data(21).logicalSrcIdx = 41;
	  section.data(21).dtTransOffset = 53;
	
	  ;% rtDW.cgg15aa41a
	  section.data(22).logicalSrcIdx = 42;
	  section.data(22).dtTransOffset = 54;
	
	  ;% rtDW.kya05gko0q
	  section.data(23).logicalSrcIdx = 43;
	  section.data(23).dtTransOffset = 55;
	
	  ;% rtDW.hi5y52mclc
	  section.data(24).logicalSrcIdx = 44;
	  section.data(24).dtTransOffset = 56;
	
	  ;% rtDW.msaqjkzdc4
	  section.data(25).logicalSrcIdx = 45;
	  section.data(25).dtTransOffset = 57;
	
	  ;% rtDW.itv4lh1itu
	  section.data(26).logicalSrcIdx = 46;
	  section.data(26).dtTransOffset = 58;
	
	  ;% rtDW.pztby5tdmg.LoggedData
	  section.data(27).logicalSrcIdx = 47;
	  section.data(27).dtTransOffset = 59;
	
	  ;% rtDW.o3l54yb1i3.LoggedData
	  section.data(28).logicalSrcIdx = 48;
	  section.data(28).dtTransOffset = 60;
	
	  ;% rtDW.lvjvwmkulx.LoggedData
	  section.data(29).logicalSrcIdx = 49;
	  section.data(29).dtTransOffset = 61;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.iie0k52gf2.Tail
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hxf5v0hxfq.Tail
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtDW.nrayhafgyw.Tail
	  section.data(3).logicalSrcIdx = 52;
	  section.data(3).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.gl2utjnv03
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.mrlpfzs3wn
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.dnkdbkqczp
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.kols4c4dg4
	  section.data(4).logicalSrcIdx = 56;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.gibqmcfn3a
	  section.data(5).logicalSrcIdx = 57;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ob5wky4wsa
	  section.data(6).logicalSrcIdx = 58;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.hmp4wnm12v
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.k3vqeab02b
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.a50xvoi5cw
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.bnvulmonk2
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.ipyob4ujct.cl4bth31oo
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ipyob4ujct.n3iy5isn5k
	  section.data(2).logicalSrcIdx = 64;
	  section.data(2).dtTransOffset = 5154;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.ipyob4ujct.fazqyerxsu
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.i00ohkzxv2.oqsczzj035
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.apfdt1mk1s.cvx5ycrffh
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.ogpjwh504b.ljbrchkhk1
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fmempv5ety.gnrlcinhso
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.hbwafuhekh.cl4bth31oo
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hbwafuhekh.n3iy5isn5k
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 5154;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.hbwafuhekh.fazqyerxsu
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.a1tdc130d3.oqsczzj035
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.msblmfssu1.cvx5ycrffh
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fkat0ywnxz.ljbrchkhk1
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.h5j4mvdijc.gnrlcinhso
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.arymfxlfvv.cl4bth31oo
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.arymfxlfvv.n3iy5isn5k
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 5154;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.arymfxlfvv.fazqyerxsu
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.coaxej2udzm.oqsczzj035
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cnj3cuyx4ul.cvx5ycrffh
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.h02m5m2hejt.ljbrchkhk1
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fzybd15s0q0.gnrlcinhso
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
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


  targMap.checksum0 = 4188621712;
  targMap.checksum1 = 2115538234;
  targMap.checksum2 = 615640652;
  targMap.checksum3 = 871521442;

