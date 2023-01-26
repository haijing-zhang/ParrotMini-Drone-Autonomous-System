  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 19;
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
    ;% Auto data (dexojrsdjj)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.Sensors
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% dexojrsdjj.Constant_Value
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.RateTransition_InitialCondition
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.outlierBelowFloor_const
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.outlierJump_const
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.currentEstimateVeryOffFromPressure_const
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.currentStateVeryOffsonarflt_const
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.Checkerrorcondition_const
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.u0continuousOFerrors_const
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteDerivative_ICPrevScaledInput
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant1_const
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxp_const
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxq_const
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxw1_const
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxw2_const
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxdw1_const
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 7;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxdw2_const
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 8;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxp2_const
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 9;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxq2_const
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 10;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxw3_const
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 11;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxw4_const
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 12;
	
	  ;% dexojrsdjj.fxgka2mnesn.minHeightforOF_const
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 13;
	
	  ;% dexojrsdjj.fxgka2mnesn.DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 14;
	
	  ;% dexojrsdjj.fxgka2mnesn.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 15;
	
	  ;% dexojrsdjj.fxgka2mnesn.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 16;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant2_const
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 17;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant4_const
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 18;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant3_const
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 19;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant5_const
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 20;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const_j00hy5w41n
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 21;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant1_const_es2id1xqb3
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.WrapToZero_Threshold
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.WrapToZero_Threshold_ajpu2ajsvb
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.WrapToZero_Threshold_kl5sqi5005
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.WrapToZero_Threshold_eztyhrsd23
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const_ltbq4yopxw
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const_hl25wzzkec
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 5;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const_gyd5vwlf1g
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn._Value
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.Lykyhatkk1_Y0
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.deltax_Y0
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay2_InitialCondition
	  section.data(5).logicalSrcIdx = 43;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.X0_Value
	  section.data(6).logicalSrcIdx = 44;
	  section.data(6).dtTransOffset = 5;
	
	  ;% dexojrsdjj.fxgka2mnesn.SaturationSonar_LowerSat
	  section.data(7).logicalSrcIdx = 45;
	  section.data(7).dtTransOffset = 7;
	
	  ;% dexojrsdjj.fxgka2mnesn.sonarFilter_IIR_NumCoef
	  section.data(8).logicalSrcIdx = 46;
	  section.data(8).dtTransOffset = 8;
	
	  ;% dexojrsdjj.fxgka2mnesn.sonarFilter_IIR_DenCoef
	  section.data(9).logicalSrcIdx = 47;
	  section.data(9).dtTransOffset = 12;
	
	  ;% dexojrsdjj.fxgka2mnesn.sonarFilter_IIR_InitialStates
	  section.data(10).logicalSrcIdx = 48;
	  section.data(10).dtTransOffset = 16;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainM_Value
	  section.data(11).logicalSrcIdx = 49;
	  section.data(11).dtTransOffset = 17;
	
	  ;% dexojrsdjj.fxgka2mnesn.C_Value
	  section.data(12).logicalSrcIdx = 50;
	  section.data(12).dtTransOffset = 19;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainM_Value_lxsgu00dk3
	  section.data(13).logicalSrcIdx = 51;
	  section.data(13).dtTransOffset = 21;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainM_Value_aebz5up2fh
	  section.data(14).logicalSrcIdx = 52;
	  section.data(14).dtTransOffset = 23;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainM_Value_iznlefhuea
	  section.data(15).logicalSrcIdx = 53;
	  section.data(15).dtTransOffset = 25;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainL_Value
	  section.data(16).logicalSrcIdx = 54;
	  section.data(16).dtTransOffset = 33;
	
	  ;% dexojrsdjj.fxgka2mnesn.gravity_Value
	  section.data(17).logicalSrcIdx = 55;
	  section.data(17).dtTransOffset = 41;
	
	  ;% dexojrsdjj.fxgka2mnesn.gainaccinput1_Gain
	  section.data(18).logicalSrcIdx = 56;
	  section.data(18).dtTransOffset = 44;
	
	  ;% dexojrsdjj.fxgka2mnesn.xValue_Value
	  section.data(19).logicalSrcIdx = 57;
	  section.data(19).dtTransOffset = 45;
	
	  ;% dexojrsdjj.fxgka2mnesn.yValue_Value
	  section.data(20).logicalSrcIdx = 58;
	  section.data(20).dtTransOffset = 46;
	
	  ;% dexojrsdjj.fxgka2mnesn.zValue_Value
	  section.data(21).logicalSrcIdx = 59;
	  section.data(21).dtTransOffset = 47;
	
	  ;% dexojrsdjj.fxgka2mnesn.A_Value
	  section.data(22).logicalSrcIdx = 60;
	  section.data(22).dtTransOffset = 48;
	
	  ;% dexojrsdjj.fxgka2mnesn.gravity_Value_jqr0ovwu0c
	  section.data(23).logicalSrcIdx = 61;
	  section.data(23).dtTransOffset = 52;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainL_Value_pnfyizgwmu
	  section.data(24).logicalSrcIdx = 62;
	  section.data(24).dtTransOffset = 55;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainL_Value_lxbsmbqbfu
	  section.data(25).logicalSrcIdx = 63;
	  section.data(25).dtTransOffset = 57;
	
	  ;% dexojrsdjj.fxgka2mnesn.B_Value
	  section.data(26).logicalSrcIdx = 64;
	  section.data(26).dtTransOffset = 59;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_Value
	  section.data(27).logicalSrcIdx = 65;
	  section.data(27).dtTransOffset = 61;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainL_Value_bldhsg2ud4
	  section.data(28).logicalSrcIdx = 66;
	  section.data(28).dtTransOffset = 62;
	
	  ;% dexojrsdjj.fxgka2mnesn.Wait3Seconds_Value
	  section.data(29).logicalSrcIdx = 67;
	  section.data(29).dtTransOffset = 64;
	
	  ;% dexojrsdjj.fxgka2mnesn.DelayOneStep_InitialCondition
	  section.data(30).logicalSrcIdx = 68;
	  section.data(30).dtTransOffset = 65;
	
	  ;% dexojrsdjj.fxgka2mnesn.u5meters_Value
	  section.data(31).logicalSrcIdx = 69;
	  section.data(31).dtTransOffset = 66;
	
	  ;% dexojrsdjj.fxgka2mnesn.CovarianceZ_Value
	  section.data(32).logicalSrcIdx = 70;
	  section.data(32).dtTransOffset = 67;
	
	  ;% dexojrsdjj.fxgka2mnesn.CovarianceZ_Value_bvnqeaggu2
	  section.data(33).logicalSrcIdx = 71;
	  section.data(33).dtTransOffset = 83;
	
	  ;% dexojrsdjj.fxgka2mnesn.P0_Value
	  section.data(34).logicalSrcIdx = 72;
	  section.data(34).dtTransOffset = 87;
	
	  ;% dexojrsdjj.fxgka2mnesn.CovarianceZ_Value_bpspmajp05
	  section.data(35).logicalSrcIdx = 73;
	  section.data(35).dtTransOffset = 91;
	
	  ;% dexojrsdjj.fxgka2mnesn.CovarianceZ_Value_ms5vxcmax5
	  section.data(36).logicalSrcIdx = 74;
	  section.data(36).dtTransOffset = 95;
	
	  ;% dexojrsdjj.fxgka2mnesn.G_Value
	  section.data(37).logicalSrcIdx = 75;
	  section.data(37).dtTransOffset = 99;
	
	  ;% dexojrsdjj.fxgka2mnesn.H_Value
	  section.data(38).logicalSrcIdx = 76;
	  section.data(38).dtTransOffset = 101;
	
	  ;% dexojrsdjj.fxgka2mnesn.N_Value
	  section.data(39).logicalSrcIdx = 77;
	  section.data(39).dtTransOffset = 102;
	
	  ;% dexojrsdjj.fxgka2mnesn.Q_Value
	  section.data(40).logicalSrcIdx = 78;
	  section.data(40).dtTransOffset = 103;
	
	  ;% dexojrsdjj.fxgka2mnesn.R_Value
	  section.data(41).logicalSrcIdx = 79;
	  section.data(41).dtTransOffset = 104;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 106;
      section.data(106)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.D_xy_Gain
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain
	  section.data(2).logicalSrcIdx = 81;
	  section.data(2).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.Saturation_UpperSat
	  section.data(3).logicalSrcIdx = 82;
	  section.data(3).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.Saturation_LowerSat
	  section.data(4).logicalSrcIdx = 83;
	  section.data(4).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.P_xy_Gain
	  section.data(5).logicalSrcIdx = 84;
	  section.data(5).dtTransOffset = 5;
	
	  ;% dexojrsdjj.fxgka2mnesn.takeoff_gain1_Gain
	  section.data(6).logicalSrcIdx = 85;
	  section.data(6).dtTransOffset = 7;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_z1_Gain
	  section.data(7).logicalSrcIdx = 86;
	  section.data(7).dtTransOffset = 8;
	
	  ;% dexojrsdjj.fxgka2mnesn.P_z1_Gain
	  section.data(8).logicalSrcIdx = 87;
	  section.data(8).dtTransOffset = 9;
	
	  ;% dexojrsdjj.fxgka2mnesn._Value_iigvqrtbvy
	  section.data(9).logicalSrcIdx = 88;
	  section.data(9).dtTransOffset = 10;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain_kw5wpt2a10
	  section.data(10).logicalSrcIdx = 89;
	  section.data(10).dtTransOffset = 11;
	
	  ;% dexojrsdjj.fxgka2mnesn.Out1_Y0
	  section.data(11).logicalSrcIdx = 90;
	  section.data(11).dtTransOffset = 12;
	
	  ;% dexojrsdjj.fxgka2mnesn.Lykyhatkk1_Y0_cokidwstay
	  section.data(12).logicalSrcIdx = 91;
	  section.data(12).dtTransOffset = 13;
	
	  ;% dexojrsdjj.fxgka2mnesn.deltax_Y0_k5wvmx5y5h
	  section.data(13).logicalSrcIdx = 92;
	  section.data(13).dtTransOffset = 14;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain_p3e2qyvrfr
	  section.data(14).logicalSrcIdx = 93;
	  section.data(14).dtTransOffset = 15;
	
	  ;% dexojrsdjj.fxgka2mnesn.opticalFlowErrorCorrect_Gain
	  section.data(15).logicalSrcIdx = 94;
	  section.data(15).dtTransOffset = 16;
	
	  ;% dexojrsdjj.fxgka2mnesn.TorqueTotalThrustToThrustPerMotor_Value
	  section.data(16).logicalSrcIdx = 95;
	  section.data(16).dtTransOffset = 17;
	
	  ;% dexojrsdjj.fxgka2mnesn.A_Value_a4ccttduli
	  section.data(17).logicalSrcIdx = 96;
	  section.data(17).dtTransOffset = 33;
	
	  ;% dexojrsdjj.fxgka2mnesn.SimplyIntegrateVelocity_gainval
	  section.data(18).logicalSrcIdx = 97;
	  section.data(18).dtTransOffset = 49;
	
	  ;% dexojrsdjj.fxgka2mnesn.SimplyIntegrateVelocity_IC
	  section.data(19).logicalSrcIdx = 98;
	  section.data(19).dtTransOffset = 50;
	
	  ;% dexojrsdjj.fxgka2mnesn.invertzaxisGain_Gain
	  section.data(20).logicalSrcIdx = 99;
	  section.data(20).dtTransOffset = 51;
	
	  ;% dexojrsdjj.fxgka2mnesn.prsToAltGain_Gain
	  section.data(21).logicalSrcIdx = 100;
	  section.data(21).dtTransOffset = 52;
	
	  ;% dexojrsdjj.fxgka2mnesn.pressureFilter_IIR_NumCoef
	  section.data(22).logicalSrcIdx = 101;
	  section.data(22).dtTransOffset = 53;
	
	  ;% dexojrsdjj.fxgka2mnesn.pressureFilter_IIR_DenCoef
	  section.data(23).logicalSrcIdx = 102;
	  section.data(23).dtTransOffset = 57;
	
	  ;% dexojrsdjj.fxgka2mnesn.pressureFilter_IIR_InitialStates
	  section.data(24).logicalSrcIdx = 103;
	  section.data(24).dtTransOffset = 61;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_gainval
	  section.data(25).logicalSrcIdx = 104;
	  section.data(25).dtTransOffset = 62;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_IC
	  section.data(26).logicalSrcIdx = 105;
	  section.data(26).dtTransOffset = 63;
	
	  ;% dexojrsdjj.fxgka2mnesn.X0_Value_iebopo3rxe
	  section.data(27).logicalSrcIdx = 106;
	  section.data(27).dtTransOffset = 64;
	
	  ;% dexojrsdjj.fxgka2mnesn.Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
	  section.data(28).logicalSrcIdx = 107;
	  section.data(28).dtTransOffset = 66;
	
	  ;% dexojrsdjj.fxgka2mnesn.inverseIMU_gain_Gain
	  section.data(29).logicalSrcIdx = 108;
	  section.data(29).dtTransOffset = 72;
	
	  ;% dexojrsdjj.fxgka2mnesn.FIR_IMUaccel_InitialStates
	  section.data(30).logicalSrcIdx = 109;
	  section.data(30).dtTransOffset = 78;
	
	  ;% dexojrsdjj.fxgka2mnesn.FIR_IMUaccel_Coefficients
	  section.data(31).logicalSrcIdx = 110;
	  section.data(31).dtTransOffset = 79;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain2_Gain
	  section.data(32).logicalSrcIdx = 111;
	  section.data(32).dtTransOffset = 85;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_h3rrj2jx2k
	  section.data(33).logicalSrcIdx = 112;
	  section.data(33).dtTransOffset = 86;
	
	  ;% dexojrsdjj.fxgka2mnesn.C_Value_hgmeyjklds
	  section.data(34).logicalSrcIdx = 113;
	  section.data(34).dtTransOffset = 87;
	
	  ;% dexojrsdjj.fxgka2mnesn.X0_Value_iynsusju2g
	  section.data(35).logicalSrcIdx = 114;
	  section.data(35).dtTransOffset = 89;
	
	  ;% dexojrsdjj.fxgka2mnesn.C_Value_icp2nf4rsg
	  section.data(36).logicalSrcIdx = 115;
	  section.data(36).dtTransOffset = 91;
	
	  ;% dexojrsdjj.fxgka2mnesn.LPFFcutoff40Hz1_NumCoef
	  section.data(37).logicalSrcIdx = 116;
	  section.data(37).dtTransOffset = 93;
	
	  ;% dexojrsdjj.fxgka2mnesn.LPFFcutoff40Hz1_DenCoef
	  section.data(38).logicalSrcIdx = 117;
	  section.data(38).dtTransOffset = 95;
	
	  ;% dexojrsdjj.fxgka2mnesn.LPFFcutoff40Hz1_InitialStates
	  section.data(39).logicalSrcIdx = 118;
	  section.data(39).dtTransOffset = 97;
	
	  ;% dexojrsdjj.fxgka2mnesn.LPFFcutoff40Hz_NumCoef
	  section.data(40).logicalSrcIdx = 119;
	  section.data(40).dtTransOffset = 98;
	
	  ;% dexojrsdjj.fxgka2mnesn.LPFFcutoff40Hz_DenCoef
	  section.data(41).logicalSrcIdx = 120;
	  section.data(41).dtTransOffset = 100;
	
	  ;% dexojrsdjj.fxgka2mnesn.LPFFcutoff40Hz_InitialStates
	  section.data(42).logicalSrcIdx = 121;
	  section.data(42).dtTransOffset = 102;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIR_IMUgyro_r_NumCoef
	  section.data(43).logicalSrcIdx = 122;
	  section.data(43).dtTransOffset = 103;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIR_IMUgyro_r_DenCoef
	  section.data(44).logicalSrcIdx = 123;
	  section.data(44).dtTransOffset = 109;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIR_IMUgyro_r_InitialStates
	  section.data(45).logicalSrcIdx = 124;
	  section.data(45).dtTransOffset = 115;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_jwftkbz0rw
	  section.data(46).logicalSrcIdx = 125;
	  section.data(46).dtTransOffset = 116;
	
	  ;% dexojrsdjj.fxgka2mnesn.X0_Value_ckt0hlpura
	  section.data(47).logicalSrcIdx = 126;
	  section.data(47).dtTransOffset = 117;
	
	  ;% dexojrsdjj.fxgka2mnesn.C_Value_i2rj2gykf0
	  section.data(48).logicalSrcIdx = 127;
	  section.data(48).dtTransOffset = 121;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain1_Gain
	  section.data(49).logicalSrcIdx = 128;
	  section.data(49).dtTransOffset = 129;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIRgyroz_NumCoef
	  section.data(50).logicalSrcIdx = 129;
	  section.data(50).dtTransOffset = 130;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIRgyroz_DenCoef
	  section.data(51).logicalSrcIdx = 130;
	  section.data(51).dtTransOffset = 136;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIRgyroz_InitialStates
	  section.data(52).logicalSrcIdx = 131;
	  section.data(52).dtTransOffset = 142;
	
	  ;% dexojrsdjj.fxgka2mnesn.TSamp_WtEt
	  section.data(53).logicalSrcIdx = 132;
	  section.data(53).dtTransOffset = 143;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay_InitialCondition
	  section.data(54).logicalSrcIdx = 133;
	  section.data(54).dtTransOffset = 144;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay1_InitialCondition
	  section.data(55).logicalSrcIdx = 134;
	  section.data(55).dtTransOffset = 145;
	
	  ;% dexojrsdjj.fxgka2mnesn.B_Value_fiwsw45qg3
	  section.data(56).logicalSrcIdx = 135;
	  section.data(56).dtTransOffset = 146;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_Value_hewe32b5gz
	  section.data(57).logicalSrcIdx = 136;
	  section.data(57).dtTransOffset = 154;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_pr_Gain
	  section.data(58).logicalSrcIdx = 137;
	  section.data(58).dtTransOffset = 158;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_gainval_iwh011vtdj
	  section.data(59).logicalSrcIdx = 138;
	  section.data(59).dtTransOffset = 160;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_IC_gbobkcke1e
	  section.data(60).logicalSrcIdx = 139;
	  section.data(60).dtTransOffset = 161;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_UpperSat
	  section.data(61).logicalSrcIdx = 140;
	  section.data(61).dtTransOffset = 162;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_LowerSat
	  section.data(62).logicalSrcIdx = 141;
	  section.data(62).dtTransOffset = 163;
	
	  ;% dexojrsdjj.fxgka2mnesn.I_pr_Gain
	  section.data(63).logicalSrcIdx = 142;
	  section.data(63).dtTransOffset = 164;
	
	  ;% dexojrsdjj.fxgka2mnesn.P_pr_Gain
	  section.data(64).logicalSrcIdx = 143;
	  section.data(64).dtTransOffset = 165;
	
	  ;% dexojrsdjj.fxgka2mnesn.w1_Value
	  section.data(65).logicalSrcIdx = 144;
	  section.data(65).dtTransOffset = 167;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_gainval_ew03ezrphv
	  section.data(66).logicalSrcIdx = 145;
	  section.data(66).dtTransOffset = 168;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_IC_oqluhrp12r
	  section.data(67).logicalSrcIdx = 146;
	  section.data(67).dtTransOffset = 169;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_UpperSat_czctfai3ec
	  section.data(68).logicalSrcIdx = 147;
	  section.data(68).dtTransOffset = 170;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_LowerSat_lh0wc4iyar
	  section.data(69).logicalSrcIdx = 148;
	  section.data(69).dtTransOffset = 171;
	
	  ;% dexojrsdjj.fxgka2mnesn.SaturationThrust1_UpperSat
	  section.data(70).logicalSrcIdx = 149;
	  section.data(70).dtTransOffset = 172;
	
	  ;% dexojrsdjj.fxgka2mnesn.SaturationThrust1_LowerSat
	  section.data(71).logicalSrcIdx = 150;
	  section.data(71).dtTransOffset = 173;
	
	  ;% dexojrsdjj.fxgka2mnesn.P_yaw_Gain
	  section.data(72).logicalSrcIdx = 151;
	  section.data(72).dtTransOffset = 174;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_yaw_Gain
	  section.data(73).logicalSrcIdx = 152;
	  section.data(73).dtTransOffset = 175;
	
	  ;% dexojrsdjj.fxgka2mnesn.ThrustToMotorCommand_Gain
	  section.data(74).logicalSrcIdx = 153;
	  section.data(74).dtTransOffset = 176;
	
	  ;% dexojrsdjj.fxgka2mnesn.Saturation5_UpperSat
	  section.data(75).logicalSrcIdx = 154;
	  section.data(75).dtTransOffset = 177;
	
	  ;% dexojrsdjj.fxgka2mnesn.Saturation5_LowerSat
	  section.data(76).logicalSrcIdx = 155;
	  section.data(76).dtTransOffset = 178;
	
	  ;% dexojrsdjj.fxgka2mnesn.MotorDirections_Gain
	  section.data(77).logicalSrcIdx = 156;
	  section.data(77).dtTransOffset = 179;
	
	  ;% dexojrsdjj.fxgka2mnesn.A_Value_kpkzmmvck4
	  section.data(78).logicalSrcIdx = 157;
	  section.data(78).dtTransOffset = 183;
	
	  ;% dexojrsdjj.fxgka2mnesn.A_Value_ahq1egpklt
	  section.data(79).logicalSrcIdx = 158;
	  section.data(79).dtTransOffset = 187;
	
	  ;% dexojrsdjj.fxgka2mnesn.B_Value_gewxjxqwgp
	  section.data(80).logicalSrcIdx = 159;
	  section.data(80).dtTransOffset = 191;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_Value_kewzrolmza
	  section.data(81).logicalSrcIdx = 160;
	  section.data(81).dtTransOffset = 193;
	
	  ;% dexojrsdjj.fxgka2mnesn.B_Value_oupiwz53ke
	  section.data(82).logicalSrcIdx = 161;
	  section.data(82).dtTransOffset = 194;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_Value_kgolnx5zuj
	  section.data(83).logicalSrcIdx = 162;
	  section.data(83).dtTransOffset = 196;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay_InitialCondition_eicgbedez5
	  section.data(84).logicalSrcIdx = 163;
	  section.data(84).dtTransOffset = 197;
	
	  ;% dexojrsdjj.fxgka2mnesn.antiWU_Gain_Gain
	  section.data(85).logicalSrcIdx = 164;
	  section.data(85).dtTransOffset = 198;
	
	  ;% dexojrsdjj.fxgka2mnesn.I_pr_Gain_ougu4l0ttu
	  section.data(86).logicalSrcIdx = 165;
	  section.data(86).dtTransOffset = 199;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain_o4gwbrjhx2
	  section.data(87).logicalSrcIdx = 166;
	  section.data(87).dtTransOffset = 200;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain1_Gain_poq4ia0msg
	  section.data(88).logicalSrcIdx = 167;
	  section.data(88).dtTransOffset = 201;
	
	  ;% dexojrsdjj.fxgka2mnesn.P0_Value_epjew24mjm
	  section.data(89).logicalSrcIdx = 168;
	  section.data(89).dtTransOffset = 202;
	
	  ;% dexojrsdjj.fxgka2mnesn.G_Value_iasvoaqhdn
	  section.data(90).logicalSrcIdx = 169;
	  section.data(90).dtTransOffset = 218;
	
	  ;% dexojrsdjj.fxgka2mnesn.Q_Value_mma3dboje2
	  section.data(91).logicalSrcIdx = 170;
	  section.data(91).dtTransOffset = 234;
	
	  ;% dexojrsdjj.fxgka2mnesn.H_Value_izzbon0ymh
	  section.data(92).logicalSrcIdx = 171;
	  section.data(92).dtTransOffset = 250;
	
	  ;% dexojrsdjj.fxgka2mnesn.N_Value_ijhidsttxx
	  section.data(93).logicalSrcIdx = 172;
	  section.data(93).dtTransOffset = 258;
	
	  ;% dexojrsdjj.fxgka2mnesn.P0_Value_hcn5hq1hqg
	  section.data(94).logicalSrcIdx = 173;
	  section.data(94).dtTransOffset = 266;
	
	  ;% dexojrsdjj.fxgka2mnesn.G_Value_m5gseh4woj
	  section.data(95).logicalSrcIdx = 174;
	  section.data(95).dtTransOffset = 270;
	
	  ;% dexojrsdjj.fxgka2mnesn.Q_Value_ji5skitrue
	  section.data(96).logicalSrcIdx = 175;
	  section.data(96).dtTransOffset = 274;
	
	  ;% dexojrsdjj.fxgka2mnesn.P0_Value_lopxhjyv34
	  section.data(97).logicalSrcIdx = 176;
	  section.data(97).dtTransOffset = 278;
	
	  ;% dexojrsdjj.fxgka2mnesn.G_Value_grrdsw3m3n
	  section.data(98).logicalSrcIdx = 177;
	  section.data(98).dtTransOffset = 282;
	
	  ;% dexojrsdjj.fxgka2mnesn.Q_Value_pmhpoendsc
	  section.data(99).logicalSrcIdx = 178;
	  section.data(99).dtTransOffset = 286;
	
	  ;% dexojrsdjj.fxgka2mnesn.R_Value_hddz4qywlb
	  section.data(100).logicalSrcIdx = 179;
	  section.data(100).dtTransOffset = 290;
	
	  ;% dexojrsdjj.fxgka2mnesn.H_Value_aobfd2zxie
	  section.data(101).logicalSrcIdx = 180;
	  section.data(101).dtTransOffset = 294;
	
	  ;% dexojrsdjj.fxgka2mnesn.N_Value_fu0lr2d3gh
	  section.data(102).logicalSrcIdx = 181;
	  section.data(102).dtTransOffset = 296;
	
	  ;% dexojrsdjj.fxgka2mnesn.H_Value_ok0xozghuo
	  section.data(103).logicalSrcIdx = 182;
	  section.data(103).dtTransOffset = 298;
	
	  ;% dexojrsdjj.fxgka2mnesn.N_Value_bbzn23tslu
	  section.data(104).logicalSrcIdx = 183;
	  section.data(104).dtTransOffset = 300;
	
	  ;% dexojrsdjj.fxgka2mnesn.R_Value_a3jasmvgij
	  section.data(105).logicalSrcIdx = 184;
	  section.data(105).dtTransOffset = 302;
	
	  ;% dexojrsdjj.fxgka2mnesn.R_Value_l03r0qunad
	  section.data(106).logicalSrcIdx = 185;
	  section.data(106).dtTransOffset = 303;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.Output_InitialCondition
	  section.data(1).logicalSrcIdx = 186;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.Output_InitialCondition_f4j4r4eocj
	  section.data(2).logicalSrcIdx = 187;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.Output_InitialCondition_gr2qw4cxga
	  section.data(3).logicalSrcIdx = 188;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.FixPtConstant_Value
	  section.data(4).logicalSrcIdx = 189;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_hjx4evh03u
	  section.data(5).logicalSrcIdx = 190;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.Output_InitialCondition_hxy4e0ic3f
	  section.data(6).logicalSrcIdx = 191;
	  section.data(6).dtTransOffset = 5;
	
	  ;% dexojrsdjj.fxgka2mnesn.FixPtConstant_Value_l1quqfmtyl
	  section.data(7).logicalSrcIdx = 192;
	  section.data(7).dtTransOffset = 6;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_a30z1ihgak
	  section.data(8).logicalSrcIdx = 193;
	  section.data(8).dtTransOffset = 7;
	
	  ;% dexojrsdjj.fxgka2mnesn.FixPtConstant_Value_pdn5vk5ols
	  section.data(9).logicalSrcIdx = 194;
	  section.data(9).dtTransOffset = 8;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_egj0ugy2nx
	  section.data(10).logicalSrcIdx = 195;
	  section.data(10).dtTransOffset = 9;
	
	  ;% dexojrsdjj.fxgka2mnesn.FixPtConstant_Value_mmu3lup0zn
	  section.data(11).logicalSrcIdx = 196;
	  section.data(11).dtTransOffset = 10;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_jygluzzgcj
	  section.data(12).logicalSrcIdx = 197;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.controlModePosVsOrient_Value
	  section.data(1).logicalSrcIdx = 198;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.isSqrtUsed_Value
	  section.data(2).logicalSrcIdx = 199;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.isSqrtUsed_Value_ayya5glmgw
	  section.data(3).logicalSrcIdx = 200;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.isSqrtUsed_Value_fyzj4vw30p
	  section.data(4).logicalSrcIdx = 201;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.isSqrtUsed_Value_je3jzvvebq
	  section.data(5).logicalSrcIdx = 202;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.Disabletemperaturecompensation_CurrentSetting
	  section.data(1).logicalSrcIdx = 203;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.Merge_InitialOutput
	  section.data(2).logicalSrcIdx = 204;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.boxx2sxddf.deltax_Y0
	  section.data(1).logicalSrcIdx = 205;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.ieoyjrjufk.Lykyhatkk1_Y0
	  section.data(1).logicalSrcIdx = 206;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.auyrlkczqpj.deltax_Y0
	  section.data(1).logicalSrcIdx = 207;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.ftjpp1i1nwt.Lykyhatkk1_Y0
	  section.data(1).logicalSrcIdx = 208;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.edmf1x5ofn.Constant_Value
	  section.data(1).logicalSrcIdx = 209;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.bp5djohmz0.Constant_Value
	  section.data(1).logicalSrcIdx = 210;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.jtkhw0lgkw.Constant_Value
	  section.data(1).logicalSrcIdx = 211;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.mui4furwa3.Constant_Value
	  section.data(1).logicalSrcIdx = 212;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.mkh12fremc3.Constant_Value
	  section.data(1).logicalSrcIdx = 213;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ntrh2fpvwnc)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.dephasaxdc
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.mplsyaumfh
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.jcydcfokrq
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.des2f4zu3n
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.am53zdlbzw
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.dnazwsvmne
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.hjq3spfnkl
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.pybvy2uarv
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 7;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.bu5z5o4mak
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 8;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.fbukxwx20m
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 9;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.kb55jy5iky
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 12;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.di0vapflam
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 13;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.n0pnodhba1
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 14;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.cx3xemd1qz
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 17;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.n2tsgqseru
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 19;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.j3gikbjvns
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 23;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.lip1w3qso4
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 24;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.j4f4ocvklu
	  section.data(13).logicalSrcIdx = 17;
	  section.data(13).dtTransOffset = 36;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.cxjyl01bud
	  section.data(14).logicalSrcIdx = 18;
	  section.data(14).dtTransOffset = 38;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.ipfvwleu0r
	  section.data(15).logicalSrcIdx = 19;
	  section.data(15).dtTransOffset = 42;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.pqvwq2atjn
	  section.data(16).logicalSrcIdx = 20;
	  section.data(16).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.jx4gh3lhfo
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.llusgyamke
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.bdph3bzr40
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.olu11ofwkn
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.boxx2sxddf.jr33ft2rwp
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.ieoyjrjufk.fd4g40ws5p
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.auyrlkczqpj.jr33ft2rwp
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.ftjpp1i1nwt.fd4g40ws5p
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
	      
	    ;% motors_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 217;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(12) = section;
	    clear section
	  
	      
	    ;% flag_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 218;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(13) = section;
	    clear section
	  
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 25;
    sectIdxOffset = 13;
    
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
    ;% Auto data (cjyyyt0pe2y)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.adkargetc2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.iiwhcel3vp
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.hvkcnsgbbz
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.ojzwywsqra
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.hf525y4flm
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.glnxqugnfv
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.n4c02ccmvw
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 3;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.myqcaypgmg
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.eimslitsk2.LoggedData
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.ixqsivrvyc.LoggedData
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.nrgtwaze1u.LoggedData
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.ha4ctbbhvs.LoggedData
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.p1hpljzkyu.LoggedData
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.pr4j3tta4v.LoggedData
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.okwpvfoy42.LoggedData
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bzgfyf5aab.LoggedData
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.jkzxf325k4
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bdtll520oe
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.pwshjzhr55
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 5;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.nyjef1ycyg
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 6;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.g3y2exu1od
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 8;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.igdo3uvfy5
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 23;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bxz11ul2qv
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 25;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.ah0gcg1hha
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 26;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.brphiodnrc
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 27;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.coz3ppgkas
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 32;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.dd2ozag2ww
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 36;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bwea4hxqvk
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 46;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bs11adx5jj
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 48;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.joy12tk1bf
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 50;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.dkxa54wcha
	  section.data(15).logicalSrcIdx = 31;
	  section.data(15).dtTransOffset = 52;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.m4kvx310y2
	  section.data(16).logicalSrcIdx = 32;
	  section.data(16).dtTransOffset = 54;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.gvhkwoegbg
	  section.data(17).logicalSrcIdx = 33;
	  section.data(17).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.iyk1p23sk3
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.e34yfyxvng
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.dqzlvsxig5
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.h0cpqqovwr
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.aj2vlvhpfu
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.lopel0ovxm
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.nvlnzfl5aj
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bqdnrt4mpw
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.l4nshphdfj
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.mwwbqhz3bs
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 3;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.m0i15tnngn
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 4;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.ftvkipmcfj
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 5;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.oersqf0c3p
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.p21jfteabq
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.jjttlxirju
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bofwvja4x2
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.kz35mo0sw4
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 3;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.pg0c4rhf4s
	  section.data(5).logicalSrcIdx = 55;
	  section.data(5).dtTransOffset = 4;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.a1wkwaye0m
	  section.data(6).logicalSrcIdx = 56;
	  section.data(6).dtTransOffset = 5;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bmsybdcoxe
	  section.data(7).logicalSrcIdx = 57;
	  section.data(7).dtTransOffset = 6;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.pqnbafajkv
	  section.data(8).logicalSrcIdx = 58;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.boxx2sxddf.ey1udbrupy
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.boxx2sxddf.di3vx4yz3h
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.ieoyjrjufk.ot4wi4ovqd
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.ieoyjrjufk.gbfirdjdlf
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.auyrlkczqpj.ey1udbrupy
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.auyrlkczqpj.di3vx4yz3h
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.ftjpp1i1nwt.ot4wi4ovqd
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.ftjpp1i1nwt.gbfirdjdlf
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.edmf1x5ofn.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.bp5djohmz0.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.jtkhw0lgkw.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.mui4furwa3.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.mkh12fremc3.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
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


  targMap.checksum0 = 1312271428;
  targMap.checksum1 = 3337056683;
  targMap.checksum2 = 1144876379;
  targMap.checksum3 = 673069500;

