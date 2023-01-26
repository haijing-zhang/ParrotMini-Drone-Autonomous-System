/*
 * Code generation for system model 'flightControlSystem'
 *
 * Model                      : flightControlSystem
 * Model version              : 2.83
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sun Aug  8 13:53:24 2021
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "flightControlSystem.h"
#include "flightControlSystem_private.h"
#include "mod_nOBiMHsG.h"
#include "rt_atan2d_snf.h"
#include "rt_powf_snf.h"
#include "rt_roundd_snf.h"

/* Named constants for Chart: '<S239>/Chart1' */
#define flightControlSystem_IN_END_MARKER_DETECTED ((uint8_T)1U)
#define flightControlSystem_IN_LANDING ((uint8_T)2U)
#define flightControlSystem_IN_LEAVE_MARKER ((uint8_T)3U)
#define flightControlSystem_IN_LINE_FOLLOWING ((uint8_T)4U)
#define flightControlSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flightControlSystem_IN_TAKE_OFF ((uint8_T)5U)

/* Named constants for Chart: '<S239>/x_linear_contribute' */
#define flightControlSystem_IN_IDLE    ((uint8_T)2U)
#define flightControlSystem_IN_TRACK_DETECTED ((uint8_T)3U)

/* Named constants for Chart: '<S241>/Chart' */
#define flightControlSystem_IN_Grabbing ((uint8_T)1U)
#define flightControlSystem_IN_TAKE_OFF_p ((uint8_T)3U)
#define flightControlSystem_IN_TRACKING ((uint8_T)4U)

/* Named constants for Chart: '<S5>/circle count' */
#define flightControlSystem_IN_IDLE_h  ((uint8_T)1U)
#define flightControlSystem_IN_LEAVE_MARKER_p ((uint8_T)2U)
#define flightControlSystem_IN_MARKER_DETECTED ((uint8_T)3U)
#define flightControlSystem_IN_TRACE_LANE ((uint8_T)4U)

MdlrefDW_flightControlSystem_T flightControlSystem_MdlrefDW;

/* Block signals (default storage) */
B_flightControlSystem_c_T flightControlSystem_B;

/* Block states (default storage) */
DW_flightControlSystem_f_T flightControlSystem_DW;

/* Previous zero-crossings (trigger) states */
ZCE_flightControlSystem_T flightControlSystem_PrevZCX;

/* Forward declaration for local functions */
static void flightControlSystem_SystemCore_step(const uint8_T varargin_1[38400],
  uint8_T varargout_1[19200], uint8_T varargout_2[19200], uint8_T varargout_3
  [19200]);

/*
 * Output and update for action system:
 *    '<S4>/No optical flow '
 *    '<S4>/Ultrasound improper'
 *    '<S4>/Normal condition'
 */
void flightControlSystem_Noopticalflow(uint8_T *rty_Out1)
{
  /* SignalConversion generated from: '<S229>/Out1' incorporates:
   *  Constant: '<S229>/Constant'
   */
  *rty_Out1 = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S244>/MATLAB Function'
 *    '<S250>/MATLAB Function'
 */
void flightControlSystem_MATLABFunction(real_T rtu_derivative_error, real_T
  rtu_CHANGE_DERIVATIVE_ERROR_THRESHOLD, B_MATLABFunction_flightControlSystem_T *
  localB)
{
  localB->flag_change_error = (fabs(rtu_derivative_error) >=
    rtu_CHANGE_DERIVATIVE_ERROR_THRESHOLD);
}

/*
 * System initialize for atomic system:
 *    '<S244>/derivative error'
 *    '<S250>/derivative error'
 */
void flightControlSystem_derivativeerror_Init
  (DW_derivativeerror_flightControlSystem_T *localDW)
{
  localDW->count_to_be_hold_not_empty = false;
}

/*
 * System reset for atomic system:
 *    '<S244>/derivative error'
 *    '<S250>/derivative error'
 */
void flightControlSystem_derivativeerror_Reset
  (DW_derivativeerror_flightControlSystem_T *localDW)
{
  localDW->count_to_be_hold_not_empty = false;
}

/*
 * Output and update for atomic system:
 *    '<S244>/derivative error'
 *    '<S250>/derivative error'
 */
void flightControlSystem_derivativeerror(real_T rtu_dev_contribute_prev, real_T
  rtu_derivative_error, real_T rtu_flag_change_error, real_T rtu_count_prev,
  real_T rtu_flag_count_prev, B_derivativeerror_flightControlSystem_T *localB,
  DW_derivativeerror_flightControlSystem_T *localDW)
{
  real_T dev_contribute;
  int32_T flag_count;
  if (!localDW->count_to_be_hold_not_empty) {
    localDW->count_to_be_hold = 40.0;
    localDW->count_to_be_hold = rt_roundd_snf(localDW->count_to_be_hold);
    localDW->count_to_be_hold_not_empty = true;
  }

  flag_count = 0;
  if ((rtu_flag_change_error != 0.0) && (rtu_count_prev == 0.0)) {
    flag_count = 1;
  }

  if ((rtu_flag_count_prev != 0.0) || (flag_count != 0)) {
    if (rtu_count_prev == localDW->count_to_be_hold) {
      localB->count = 0.0;
      flag_count = 0;
    } else {
      localB->count = rtu_count_prev + 1.0;
      flag_count = 1;
    }

    dev_contribute = rtu_derivative_error * 0.002;
    if ((dev_contribute == 0.0) && (rtu_dev_contribute_prev != 0.0)) {
      dev_contribute = rtu_dev_contribute_prev;
    }
  } else {
    localB->count = 0.0;
    dev_contribute = 0.0;
  }

  localB->dev_contribute = dev_contribute;
  localB->flag_count = flag_count;
}

/*
 * System initialize for enable system:
 *    '<S347>/MeasurementUpdate'
 *    '<S401>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate_Init
  (B_MeasurementUpdate_flightControlSystem_T *localB)
{
  /* SystemInitialize for Product: '<S378>/Product3' incorporates:
   *  Outport: '<S378>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = 0.0F;
  localB->Product3[1] = 0.0F;
}

/*
 * Disable for enable system:
 *    '<S347>/MeasurementUpdate'
 *    '<S401>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate_Disable
  (B_MeasurementUpdate_flightControlSystem_T *localB,
   DW_MeasurementUpdate_flightControlSystem_T *localDW)
{
  /* Disable for Product: '<S378>/Product3' incorporates:
   *  Outport: '<S378>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = 0.0F;
  localB->Product3[1] = 0.0F;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Start for enable system:
 *    '<S347>/MeasurementUpdate'
 *    '<S401>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate_Start
  (DW_MeasurementUpdate_flightControlSystem_T *localDW)
{
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S347>/MeasurementUpdate'
 *    '<S401>/MeasurementUpdate'
 */
void flightControlSystem_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[2], real32_T rtu_yk, const real32_T rtu_Ck[2], const real32_T
  rtu_xhatkk1[2], real32_T rtu_Dk, real32_T rtu_uk,
  B_MeasurementUpdate_flightControlSystem_T *localB,
  DW_MeasurementUpdate_flightControlSystem_T *localDW)
{
  real32_T rtb_Sum_l;

  /* Outputs for Enabled SubSystem: '<S347>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S378>/Enable'
   */
  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;

    /* Sum: '<S378>/Sum' incorporates:
     *  Product: '<S378>/C[k]*xhat[k|k-1]'
     *  Product: '<S378>/D[k]*u[k]'
     *  Sum: '<S378>/Add1'
     */
    rtb_Sum_l = rtu_yk - ((rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[1] * rtu_xhatkk1
      [1]) + rtu_Dk * rtu_uk);

    /* Product: '<S378>/Product3' */
    localB->Product3[0] = rtu_Lk[0] * rtb_Sum_l;
    localB->Product3[1] = rtu_Lk[1] * rtb_Sum_l;
  } else if (localDW->MeasurementUpdate_MODE) {
    flightControlSystem_MeasurementUpdate_Disable(localB, localDW);
  }

  /* End of Outputs for SubSystem: '<S347>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S354>/Enabled Subsystem'
 *    '<S408>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem_Init
  (B_EnabledSubsystem_flightControlSystem_T *localB)
{
  /* SystemInitialize for Product: '<S380>/Product2' incorporates:
   *  Outport: '<S380>/deltax'
   */
  localB->Product2[0] = 0.0F;
  localB->Product2[1] = 0.0F;
}

/*
 * Disable for enable system:
 *    '<S354>/Enabled Subsystem'
 *    '<S408>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem_Disable
  (B_EnabledSubsystem_flightControlSystem_T *localB,
   DW_EnabledSubsystem_flightControlSystem_T *localDW)
{
  /* Disable for Product: '<S380>/Product2' incorporates:
   *  Outport: '<S380>/deltax'
   */
  localB->Product2[0] = 0.0F;
  localB->Product2[1] = 0.0F;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S354>/Enabled Subsystem'
 *    '<S408>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem_Start
  (DW_EnabledSubsystem_flightControlSystem_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S354>/Enabled Subsystem'
 *    '<S408>/Enabled Subsystem'
 */
void flightControlSystem_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[2], const real32_T rtu_Ck[2], real32_T rtu_yk, const real32_T
  rtu_xhatkk1[2], B_EnabledSubsystem_flightControlSystem_T *localB,
  DW_EnabledSubsystem_flightControlSystem_T *localDW)
{
  real32_T rtb_Add1;

  /* Outputs for Enabled SubSystem: '<S354>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S380>/Enable'
   */
  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S380>/Add1' incorporates:
     *  Product: '<S380>/Product'
     */
    rtb_Add1 = rtu_yk - (rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[1] * rtu_xhatkk1[1]);

    /* Product: '<S380>/Product2' */
    localB->Product2[0] = rtu_Mk[0] * rtb_Add1;
    localB->Product2[1] = rtu_Mk[1] * rtb_Add1;
  } else if (localDW->EnabledSubsystem_MODE) {
    flightControlSystem_EnabledSubsystem_Disable(localB, localDW);
  }

  /* End of Outputs for SubSystem: '<S354>/Enabled Subsystem' */
}

/* System initialize for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Init
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW)
{
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
  localDW->SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  localDW->SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S257>/Delay2' */
  localDW->Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S261>/MemoryX' */
  localDW->icLoad = true;

  /* InitializeConditions for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S262>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[0] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S262>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[1] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S262>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S325>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S327>/MemoryX' */
  localDW->icLoad_p = true;

  /* InitializeConditions for DiscreteFir: '<S259>/FIR_IMUaccel' */
  localDW->FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    localDW->FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S259>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S381>/MemoryX' */
  localDW->icLoad_k = true;

  /* InitializeConditions for DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S259>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    localDW->IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S259>/IIR_IMUgyro_r' */

  /* InitializeConditions for UnitDelay: '<S438>/Output' */
  localDW->Output_DSTATE = 0U;

  /* InitializeConditions for Delay: '<S447>/MemoryX' */
  localDW->icLoad_o = true;

  /* InitializeConditions for UnitDelay: '<S520>/Output' */
  localDW->Output_DSTATE_n = 0U;

  /* InitializeConditions for DiscreteFilter: '<S446>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    localDW->IIRgyroz_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S446>/IIRgyroz' */

  /* InitializeConditions for UnitDelay: '<S454>/UD' */
  localDW->UD_DSTATE_k[0] = 0.0F;

  /* InitializeConditions for Delay: '<S442>/Delay' */
  localDW->Delay_DSTATE_a[0] = 0.0F;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE_p[0] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S454>/UD' */
  localDW->UD_DSTATE_k[1] = 0.0F;

  /* InitializeConditions for Delay: '<S442>/Delay' */
  localDW->Delay_DSTATE_a[1] = 0.0F;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE_p[1] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S14>/Output' */
  localDW->Output_DSTATE_h = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_d = 0.0F;
  localDW->DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S244>/Delay6' */
  localDW->Delay6_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S246>/UD' */
  localDW->UD_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S244>/Delay' */
  localDW->Delay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S244>/Delay5' */
  localDW->Delay5_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S241>/Delay1' */
  localDW->Delay1_DSTATE[0] = 0.0;
  localDW->Delay1_DSTATE[1] = 0.0;
  localDW->Delay1_DSTATE[2] = 0.0;
  localDW->Delay1_DSTATE[3] = 0.0;

  /* InitializeConditions for Delay: '<S250>/Delay6' */
  localDW->Delay6_DSTATE_o = 0.0;

  /* InitializeConditions for UnitDelay: '<S252>/UD' */
  localDW->UD_DSTATE_i = 0.0;

  /* InitializeConditions for Delay: '<S250>/Delay' */
  localDW->Delay_DSTATE_d = 0.0;

  /* InitializeConditions for Delay: '<S250>/Delay5' */
  localDW->Delay5_DSTATE_h = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S202>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_n[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S202>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_n[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_p = 0.0F;

  /* InitializeConditions for UnitDelay: '<S227>/Output' */
  localDW->Output_DSTATE_g = 0U;

  /* InitializeConditions for Delay: '<S4>/Delay One Step' */
  localDW->DelayOneStep_DSTATE = 0.0;

  /* SystemInitialize for Merge: '<S4>/Merge' */
  localB->Merge = 0U;

  /* SystemInitialize for Chart: '<S239>/Chart1' */
  localDW->temporalCounter_i1_k = 0U;
  localDW->is_active_c5_flightControlSystem = 0U;
  localDW->is_c5_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localDW->x_planned_stored = 0.0;
  localDW->circle_count_m = 0.0;
  localB->x_planned = 0.0;

  /* SystemInitialize for MATLAB Function: '<S244>/derivative error' */
  flightControlSystem_derivativeerror_Init(&localDW->sf_derivativeerror);

  /* SystemInitialize for Chart: '<S239>/x_linear_contribute' */
  localDW->is_active_c20_flightControlSystem = 0U;
  localDW->is_c20_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localB->linear_part_c = 0.0;

  /* SystemInitialize for Chart: '<S240>/Chart1' */
  localDW->temporalCounter_i1_p = 0U;
  localDW->is_active_c21_flightControlSystem = 0U;
  localDW->is_c21_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localDW->y_planned_stored = 0.0;
  localDW->circle_count_k = 0.0;
  localB->y_planned = 0.0;

  /* SystemInitialize for MATLAB Function: '<S250>/derivative error' */
  flightControlSystem_derivativeerror_Init(&localDW->sf_derivativeerror_c);

  /* SystemInitialize for Chart: '<S240>/y_linear_contribute' */
  localDW->is_active_c24_flightControlSystem = 0U;
  localDW->is_c24_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localB->linear_part = 0.0;

  /* SystemInitialize for Chart: '<S241>/Chart' */
  localDW->temporalCounter_i1_n = 0U;
  localDW->is_active_c25_flightControlSystem = 0U;
  localDW->is_c25_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localDW->circle_count = 0.0;
  localB->z_planned = 0.0;
  localB->flag_end_marker_to_controller = 0.0;

  /* SystemInitialize for Chart: '<S5>/circle count' */
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_flightControlSystem = 0U;
  localDW->is_c10_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localB->circle_count = 0.0;
  localB->flag_tracelane = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S283>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S313>/Product3' incorporates:
   *  Outport: '<S313>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[0] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S283>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S289>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S315>/Product2' incorporates:
   *  Outport: '<S315>/deltax'
   */
  localB->Product2[0] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S289>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S283>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S313>/Product3' incorporates:
   *  Outport: '<S313>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S283>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S289>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S315>/Product2' incorporates:
   *  Outport: '<S315>/deltax'
   */
  localB->Product2[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S289>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S347>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Init(&localB->MeasurementUpdate_n);

  /* End of SystemInitialize for SubSystem: '<S347>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S354>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Init(&localB->EnabledSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S354>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S401>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Init(&localB->MeasurementUpdate_j);

  /* End of SystemInitialize for SubSystem: '<S401>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S408>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Init(&localB->EnabledSubsystem_n);

  /* End of SystemInitialize for SubSystem: '<S408>/Enabled Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S435>/Triggered Subsystem' */
  /* SystemInitialize for Outport: '<S439>/Out1' incorporates:
   *  Inport: '<S439>/In1'
   */
  localB->In1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S435>/Triggered Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S485>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S516>/Product3' incorporates:
   *  Outport: '<S516>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S485>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S492>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S518>/Product2' incorporates:
   *  Outport: '<S518>/deltax'
   */
  localB->Product2_k[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S492>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S485>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S516>/Product3' incorporates:
   *  Outport: '<S516>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S485>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S492>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S518>/Product2' incorporates:
   *  Outport: '<S518>/deltax'
   */
  localB->Product2_k[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S492>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S485>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S516>/Product3' incorporates:
   *  Outport: '<S516>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[2] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S485>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S492>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S518>/Product2' incorporates:
   *  Outport: '<S518>/deltax'
   */
  localB->Product2_k[2] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S492>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S485>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S516>/Product3' incorporates:
   *  Outport: '<S516>/L*(y[k]-yhat[k|k-1])'
   */
  localB->Product3_a[3] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S485>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S492>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S518>/Product2' incorporates:
   *  Outport: '<S518>/deltax'
   */
  localB->Product2_k[3] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S492>/Enabled Subsystem' */
}

/* System reset for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Reset
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW)
{
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
  localDW->SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  localDW->SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S257>/Delay2' */
  localDW->Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S261>/MemoryX' */
  localDW->icLoad = true;

  /* InitializeConditions for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S262>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[0] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S262>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[1] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S262>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S325>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S327>/MemoryX' */
  localDW->icLoad_p = true;

  /* InitializeConditions for DiscreteFir: '<S259>/FIR_IMUaccel' */
  localDW->FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    localDW->FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S259>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S381>/MemoryX' */
  localDW->icLoad_k = true;

  /* InitializeConditions for DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S259>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    localDW->IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S259>/IIR_IMUgyro_r' */

  /* InitializeConditions for UnitDelay: '<S438>/Output' */
  localDW->Output_DSTATE = 0U;

  /* InitializeConditions for Delay: '<S447>/MemoryX' */
  localDW->icLoad_o = true;

  /* InitializeConditions for UnitDelay: '<S520>/Output' */
  localDW->Output_DSTATE_n = 0U;

  /* InitializeConditions for DiscreteFilter: '<S446>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    localDW->IIRgyroz_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S446>/IIRgyroz' */

  /* InitializeConditions for UnitDelay: '<S454>/UD' */
  localDW->UD_DSTATE_k[0] = 0.0F;

  /* InitializeConditions for Delay: '<S442>/Delay' */
  localDW->Delay_DSTATE_a[0] = 0.0F;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE_p[0] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S454>/UD' */
  localDW->UD_DSTATE_k[1] = 0.0F;

  /* InitializeConditions for Delay: '<S442>/Delay' */
  localDW->Delay_DSTATE_a[1] = 0.0F;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE_p[1] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S14>/Output' */
  localDW->Output_DSTATE_h = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_d = 0.0F;
  localDW->DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S244>/Delay6' */
  localDW->Delay6_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S246>/UD' */
  localDW->UD_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S244>/Delay' */
  localDW->Delay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S244>/Delay5' */
  localDW->Delay5_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S241>/Delay1' */
  localDW->Delay1_DSTATE[0] = 0.0;
  localDW->Delay1_DSTATE[1] = 0.0;
  localDW->Delay1_DSTATE[2] = 0.0;
  localDW->Delay1_DSTATE[3] = 0.0;

  /* InitializeConditions for Delay: '<S250>/Delay6' */
  localDW->Delay6_DSTATE_o = 0.0;

  /* InitializeConditions for UnitDelay: '<S252>/UD' */
  localDW->UD_DSTATE_i = 0.0;

  /* InitializeConditions for Delay: '<S250>/Delay' */
  localDW->Delay_DSTATE_d = 0.0;

  /* InitializeConditions for Delay: '<S250>/Delay5' */
  localDW->Delay5_DSTATE_h = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S202>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_n[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S202>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_n[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_p = 0.0F;

  /* InitializeConditions for UnitDelay: '<S227>/Output' */
  localDW->Output_DSTATE_g = 0U;

  /* InitializeConditions for Delay: '<S4>/Delay One Step' */
  localDW->DelayOneStep_DSTATE = 0.0;

  /* SystemReset for Chart: '<S5>/circle count' */
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_flightControlSystem = 0U;
  localDW->is_c10_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localB->circle_count = 0.0;
  localB->flag_tracelane = 0.0;

  /* SystemReset for MATLAB Function: '<S244>/derivative error' */
  flightControlSystem_derivativeerror_Reset(&localDW->sf_derivativeerror);

  /* SystemReset for Chart: '<S239>/x_linear_contribute' */
  localDW->is_active_c20_flightControlSystem = 0U;
  localDW->is_c20_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localB->linear_part_c = 0.0;

  /* SystemReset for Chart: '<S241>/Chart' */
  localDW->temporalCounter_i1_n = 0U;
  localDW->is_active_c25_flightControlSystem = 0U;
  localDW->is_c25_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localDW->circle_count = 0.0;
  localB->z_planned = 0.0;
  localB->flag_end_marker_to_controller = 0.0;

  /* SystemReset for Chart: '<S239>/Chart1' */
  localDW->temporalCounter_i1_k = 0U;
  localDW->is_active_c5_flightControlSystem = 0U;
  localDW->is_c5_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localDW->x_planned_stored = 0.0;
  localDW->circle_count_m = 0.0;
  localB->x_planned = 0.0;

  /* SystemReset for MATLAB Function: '<S250>/derivative error' */
  flightControlSystem_derivativeerror_Reset(&localDW->sf_derivativeerror_c);

  /* SystemReset for Chart: '<S240>/y_linear_contribute' */
  localDW->is_active_c24_flightControlSystem = 0U;
  localDW->is_c24_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localB->linear_part = 0.0;

  /* SystemReset for Chart: '<S240>/Chart1' */
  localDW->temporalCounter_i1_p = 0U;
  localDW->is_active_c21_flightControlSystem = 0U;
  localDW->is_c21_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;
  localDW->y_planned_stored = 0.0;
  localDW->circle_count_k = 0.0;
  localB->y_planned = 0.0;
}

/* Disable for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Disable
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW)
{
  /* Disable for Enabled SubSystem: '<S289>/Enabled Subsystem' */
  if (localDW->EnabledSubsystem_MODE_i) {
    /* Disable for Product: '<S315>/Product2' incorporates:
     *  Outport: '<S315>/deltax'
     */
    localB->Product2[0] = 0.0;
    localB->Product2[1] = 0.0;
    localDW->EnabledSubsystem_MODE_i = false;
  }

  /* End of Disable for SubSystem: '<S289>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S354>/Enabled Subsystem' */
  if (localDW->EnabledSubsystem_d.EnabledSubsystem_MODE) {
    flightControlSystem_EnabledSubsystem_Disable(&localB->EnabledSubsystem_d,
      &localDW->EnabledSubsystem_d);
  }

  /* End of Disable for SubSystem: '<S354>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S408>/Enabled Subsystem' */
  if (localDW->EnabledSubsystem_n.EnabledSubsystem_MODE) {
    flightControlSystem_EnabledSubsystem_Disable(&localB->EnabledSubsystem_n,
      &localDW->EnabledSubsystem_n);
  }

  /* End of Disable for SubSystem: '<S408>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S492>/Enabled Subsystem' */
  if (localDW->EnabledSubsystem_MODE) {
    /* Disable for Product: '<S518>/Product2' incorporates:
     *  Outport: '<S518>/deltax'
     */
    localB->Product2_k[0] = 0.0F;
    localB->Product2_k[1] = 0.0F;
    localB->Product2_k[2] = 0.0F;
    localB->Product2_k[3] = 0.0F;
    localDW->EnabledSubsystem_MODE = false;
  }

  /* End of Disable for SubSystem: '<S492>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S485>/MeasurementUpdate' */
  if (localDW->MeasurementUpdate_MODE) {
    /* Disable for Product: '<S516>/Product3' incorporates:
     *  Outport: '<S516>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3_a[0] = 0.0F;
    localB->Product3_a[1] = 0.0F;
    localB->Product3_a[2] = 0.0F;
    localB->Product3_a[3] = 0.0F;
    localDW->MeasurementUpdate_MODE = false;
  }

  /* End of Disable for SubSystem: '<S485>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S283>/MeasurementUpdate' */
  if (localDW->MeasurementUpdate_MODE_h) {
    /* Disable for Product: '<S313>/Product3' incorporates:
     *  Outport: '<S313>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3[0] = 0.0;
    localB->Product3[1] = 0.0;
    localDW->MeasurementUpdate_MODE_h = false;
  }

  /* End of Disable for SubSystem: '<S283>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S401>/MeasurementUpdate' */
  if (localDW->MeasurementUpdate_j.MeasurementUpdate_MODE) {
    flightControlSystem_MeasurementUpdate_Disable(&localB->MeasurementUpdate_j,
      &localDW->MeasurementUpdate_j);
  }

  /* End of Disable for SubSystem: '<S401>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S347>/MeasurementUpdate' */
  if (localDW->MeasurementUpdate_n.MeasurementUpdate_MODE) {
    flightControlSystem_MeasurementUpdate_Disable(&localB->MeasurementUpdate_n,
      &localDW->MeasurementUpdate_n);
  }

  /* End of Disable for SubSystem: '<S347>/MeasurementUpdate' */
}

/* Start for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Start
  (DW_ControlSystem_flightControlSystem_T *localDW)
{
  /* Start for Enabled SubSystem: '<S289>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE_i = false;

  /* End of Start for SubSystem: '<S289>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S354>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Start(&localDW->EnabledSubsystem_d);

  /* End of Start for SubSystem: '<S354>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S408>/Enabled Subsystem' */
  flightControlSystem_EnabledSubsystem_Start(&localDW->EnabledSubsystem_n);

  /* End of Start for SubSystem: '<S408>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S492>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S492>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S485>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S485>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S283>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE_h = false;

  /* End of Start for SubSystem: '<S283>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S401>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Start(&localDW->MeasurementUpdate_j);

  /* End of Start for SubSystem: '<S401>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S347>/MeasurementUpdate' */
  flightControlSystem_MeasurementUpdate_Start(&localDW->MeasurementUpdate_n);

  /* End of Start for SubSystem: '<S347>/MeasurementUpdate' */
}

/* Output and update for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem(const CommandBus
  *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors, const real_T
  rtu_VisionbasedData[6], B_ControlSystem_flightControlSystem_T *localB,
  DW_ControlSystem_flightControlSystem_T *localDW,
  ZCE_ControlSystem_flightControlSystem_T *localZCE)
{
  real32_T rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;
  real32_T rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1;
  real32_T rtb_MathFunction_g_tmp;
  real32_T rtb_MathFunction_g_tmp_0;
  real32_T rtb_MathFunction_g_tmp_1;
  real32_T rtb_MathFunction_g_tmp_2;
  real32_T rtb_MathFunction_g_tmp_3;
  real32_T rtb_SaturationThrust1_tmp;
  real32_T u0;
  int16_T rtb_LogicalOperator;
  boolean_T rtb_Compare_fo;
  boolean_T rtb_Compare_hgg;
  boolean_T rtb_Compare_o;
  boolean_T rtb_Compare_p;

  /* DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' */
  if (localDW->SimplyIntegrateVelocity_PrevResetState <= 0) {
    localDW->SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
    localDW->SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  }

  localB->SimplyIntegrateVelocity[0] = localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->SimplyIntegrateVelocity[1] = localDW->SimplyIntegrateVelocity_DSTATE[1];

  /* End of DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' */

  /* Delay: '<S261>/MemoryX' incorporates:
   *  Constant: '<S264>/Constant'
   *  Delay: '<S257>/Delay2'
   *  RelationalOperator: '<S264>/Compare'
   */
  localDW->icLoad = ((localDW->Delay2_DSTATE > 0.0) || localDW->icLoad);
  if (localDW->icLoad) {
    localDW->MemoryX_DSTATE[0] = -0.046;
    localDW->MemoryX_DSTATE[1] = 0.0;
  }

  /* Gain: '<S257>/prsToAltGain' incorporates:
   *  Sum: '<S259>/Sum2'
   */
  localB->altfrompress = (rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
    rtu_Sensors->SensorCalibration[6]) * 0.0832137167F;

  /* DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_tmp = ((localB->altfrompress - -2.93717074F *
    localDW->pressureFilter_IIR_states[0]) - 2.87629962F *
    localDW->pressureFilter_IIR_states[1]) - -0.939098954F *
    localDW->pressureFilter_IIR_states[2];
  localB->pressureFilter_IIR = ((3.75683794E-6F *
    localDW->pressureFilter_IIR_tmp + 1.12705138E-5F *
    localDW->pressureFilter_IIR_states[0]) + 1.12705138E-5F *
    localDW->pressureFilter_IIR_states[1]) + 3.75683794E-6F *
    localDW->pressureFilter_IIR_states[2];

  /* DiscreteFilter: '<S262>/sonarFilter_IIR' incorporates:
   *  Gain: '<S257>/invertzaxisGain'
   */
  localB->x_error = -(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;
  localDW->sonarFilter_IIR_tmp = ((localB->x_error - -2.9371707284498907 *
    localDW->sonarFilter_IIR_states[0]) - 2.8762997234793319 *
    localDW->sonarFilter_IIR_states[1]) - -0.939098940325283 *
    localDW->sonarFilter_IIR_states[2];

  /* Saturate: '<S262>/SaturationSonar' incorporates:
   *  Gain: '<S257>/invertzaxisGain'
   */
  if (-(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude >= -0.44) {
    localB->rtb_Add_idx_0 = -0.44;
  } else {
    localB->rtb_Add_idx_0 = -(real_T)
      rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;
  }

  /* End of Saturate: '<S262>/SaturationSonar' */

  /* Logic: '<S262>/nicemeasurementor newupdateneeded' incorporates:
   *  Abs: '<S262>/Absestdiff'
   *  Abs: '<S262>/Absestdiff1'
   *  Abs: '<S262>/Absestdiff2'
   *  Constant: '<S316>/Constant'
   *  Constant: '<S317>/Constant'
   *  Constant: '<S318>/Constant'
   *  Constant: '<S319>/Constant'
   *  Delay: '<S257>/Delay2'
   *  DiscreteFilter: '<S262>/sonarFilter_IIR'
   *  Gain: '<S257>/invertzaxisGain'
   *  Logic: '<S262>/NOT'
   *  Logic: '<S262>/findingoutliers'
   *  Logic: '<S262>/newupdateneeded'
   *  RelationalOperator: '<S316>/Compare'
   *  RelationalOperator: '<S317>/Compare'
   *  RelationalOperator: '<S318>/Compare'
   *  RelationalOperator: '<S319>/Compare'
   *  Sum: '<S262>/Add'
   *  Sum: '<S262>/Add1'
   *  Sum: '<S262>/Add2'
   */
  rtb_Compare_p = ((fabs(localDW->Delay2_DSTATE - localB->rtb_Add_idx_0) <= 0.1)
                   && (-(real_T)
                       rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude <
                       -0.44) && ((!(fabs(localB->pressureFilter_IIR -
    localDW->Delay2_DSTATE) >= 0.8)) || (!(fabs((((3.7568380197512489E-6 *
    localDW->sonarFilter_IIR_tmp + 1.1270514059253748E-5 *
    localDW->sonarFilter_IIR_states[0]) + 1.1270514059253748E-5 *
    localDW->sonarFilter_IIR_states[1]) + 3.7568380197512489E-6 *
    localDW->sonarFilter_IIR_states[2]) - localDW->Delay2_DSTATE) >= 0.4))));

  /* Outputs for Enabled SubSystem: '<S289>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S315>/Enable'
   */
  if (rtb_Compare_p) {
    localDW->EnabledSubsystem_MODE_i = true;

    /* Sum: '<S315>/Add1' incorporates:
     *  Constant: '<S261>/C'
     *  Delay: '<S261>/MemoryX'
     *  Gain: '<S257>/invertzaxisGain'
     *  Product: '<S315>/Product'
     */
    localB->u_h = -(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude -
      (0.0 * localDW->MemoryX_DSTATE[1] + localDW->MemoryX_DSTATE[0]);

    /* Product: '<S315>/Product2' */
    localB->Product2[0] = 0.02624142064187163 * localB->u_h;
    localB->Product2[1] = 0.0697767360714917 * localB->u_h;
  } else if (localDW->EnabledSubsystem_MODE_i) {
    /* Disable for Product: '<S315>/Product2' incorporates:
     *  Outport: '<S315>/deltax'
     */
    localB->Product2[0] = 0.0;
    localB->Product2[1] = 0.0;
    localDW->EnabledSubsystem_MODE_i = false;
  }

  /* End of Outputs for SubSystem: '<S289>/Enabled Subsystem' */

  /* Sum: '<S289>/Add' incorporates:
   *  Delay: '<S261>/MemoryX'
   */
  localB->rtb_Add_idx_0 = localB->Product2[0] + localDW->MemoryX_DSTATE[0];
  localB->x_error = localB->Product2[1] + localDW->MemoryX_DSTATE[1];

  /* DataTypeConversion: '<S257>/Data Type Conversion' */
  localB->altfrompress = (real32_T)localB->rtb_Add_idx_0;

  /* Delay: '<S327>/MemoryX' */
  if (localDW->icLoad_p) {
    localDW->MemoryX_DSTATE_g[0] = 0.0F;
    localDW->MemoryX_DSTATE_g[1] = 0.0F;
  }

  localB->MemoryX_e[0] = localDW->MemoryX_DSTATE_g[0];
  localB->MemoryX_e[1] = localDW->MemoryX_DSTATE_g[1];

  /* Bias: '<S259>/Assuming that the  preflight calibration was done at level orientation' */
  for (localB->i_k = 0; localB->i_k < 6; localB->i_k++) {
    localB->Sum1_p[localB->i_k] = rtu_Sensors->SensorCalibration[localB->i_k] +
      rtCP_Assumingthatthepreflightcalibrationwasdoneatlevelorientati
      [localB->i_k];
  }

  /* End of Bias: '<S259>/Assuming that the  preflight calibration was done at level orientation' */

  /* Gain: '<S259>/inverseIMU_gain' incorporates:
   *  Sum: '<S259>/Sum1'
   */
  localB->inverseIMU_gain[0] = (rtu_Sensors->HALSensors.HAL_acc_SI.x -
    localB->Sum1_p[0]) * 0.994075298F;
  localB->inverseIMU_gain[1] = (rtu_Sensors->HALSensors.HAL_acc_SI.y -
    localB->Sum1_p[1]) * 0.996184587F;
  localB->inverseIMU_gain[2] = (rtu_Sensors->HALSensors.HAL_acc_SI.z -
    localB->Sum1_p[2]) * 1.00549F;
  localB->inverseIMU_gain[3] = (rtu_Sensors->HALSensors.HAL_gyro_SI.x -
    localB->Sum1_p[3]) * 1.00139189F;
  localB->inverseIMU_gain[4] = (rtu_Sensors->HALSensors.HAL_gyro_SI.y -
    localB->Sum1_p[4]) * 0.993601203F;
  localB->inverseIMU_gain[5] = (rtu_Sensors->HALSensors.HAL_gyro_SI.z -
    localB->Sum1_p[5]) * 1.00003F;

  /* DiscreteFir: '<S259>/FIR_IMUaccel' */
  localB->r = localB->inverseIMU_gain[0] * 0.0264077242F;
  localB->cff = 1;
  localB->i_k = localDW->FIR_IMUaccel_circBuf;
  while (localB->i_k < 5) {
    localB->r += localDW->FIR_IMUaccel_states[localB->i_k] *
      rtCP_FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->i_k++;
  }

  localB->i_k = 0;
  while (localB->i_k < localDW->FIR_IMUaccel_circBuf) {
    localB->r += localDW->FIR_IMUaccel_states[localB->i_k] *
      rtCP_FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->i_k++;
  }

  localB->FIR_IMUaccel[0] = localB->r;

  /* Math: '<S326>/Math Function' incorporates:
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   */
  localB->rtb_MathFunction_idx_0 = rt_powf_snf(localB->r, 2.0F);

  /* DiscreteFir: '<S259>/FIR_IMUaccel' */
  localB->r = localB->inverseIMU_gain[1] * 0.0264077242F;
  localB->cff = 1;
  localB->i_k = localDW->FIR_IMUaccel_circBuf;
  while (localB->i_k < 5) {
    localB->r += localDW->FIR_IMUaccel_states[localB->i_k + 5] *
      rtCP_FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->i_k++;
  }

  localB->i_k = 0;
  while (localB->i_k < localDW->FIR_IMUaccel_circBuf) {
    localB->r += localDW->FIR_IMUaccel_states[localB->i_k + 5] *
      rtCP_FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->i_k++;
  }

  localB->FIR_IMUaccel[1] = localB->r;

  /* Math: '<S326>/Math Function' incorporates:
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   */
  u0 = localB->r;

  /* DiscreteFir: '<S259>/FIR_IMUaccel' */
  localB->r = localB->inverseIMU_gain[2] * 0.0264077242F;
  localB->cff = 1;
  localB->i_k = localDW->FIR_IMUaccel_circBuf;
  while (localB->i_k < 5) {
    localB->r += localDW->FIR_IMUaccel_states[localB->i_k + 10] *
      rtCP_FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->i_k++;
  }

  localB->i_k = 0;
  while (localB->i_k < localDW->FIR_IMUaccel_circBuf) {
    localB->r += localDW->FIR_IMUaccel_states[localB->i_k + 10] *
      rtCP_FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->i_k++;
  }

  localB->FIR_IMUaccel[2] = localB->r;

  /* Gain: '<S323>/Gain2' */
  localB->Saturation_j = 0.101936802F * localB->FIR_IMUaccel[0];

  /* Trigonometry: '<S323>/Trigonometric Function1' */
  if (localB->Saturation_j > 1.0F) {
    localB->Saturation_j = 1.0F;
  } else if (localB->Saturation_j < -1.0F) {
    localB->Saturation_j = -1.0F;
  }

  localB->TrigonometricFunction1 = (real32_T)asin(localB->Saturation_j);

  /* End of Trigonometry: '<S323>/Trigonometric Function1' */

  /* Sqrt: '<S326>/Sqrt' incorporates:
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   *  Math: '<S326>/Math Function'
   *  Sum: '<S326>/Sum of Elements'
   */
  localB->Saturation_j = (real32_T)sqrt((localB->rtb_MathFunction_idx_0 +
    rt_powf_snf(u0, 2.0F)) + rt_powf_snf(localB->r, 2.0F));

  /* Logic: '<S258>/Logical Operator' incorporates:
   *  Constant: '<S321>/Constant'
   *  Constant: '<S322>/Constant'
   *  RelationalOperator: '<S321>/Compare'
   *  RelationalOperator: '<S322>/Compare'
   */
  rtb_LogicalOperator = (int16_T)((localB->Saturation_j > 6.867F) &&
    (localB->Saturation_j < 12.753F));

  /* DataTypeConversion: '<S371>/Conversion' */
  localB->Conversion[0] = 0.00118693F;
  localB->Conversion[1] = -3.28681635E-5F;

  /* Outputs for Enabled SubSystem: '<S354>/Enabled Subsystem' */
  /* DataTypeConversion: '<S327>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S327>/C'
   */
  flightControlSystem_EnabledSubsystem(rtb_LogicalOperator != 0,
    localB->Conversion, rtCP_C_Value_h, localB->TrigonometricFunction1,
    localB->MemoryX_e, &localB->EnabledSubsystem_d, &localDW->EnabledSubsystem_d);

  /* End of Outputs for SubSystem: '<S354>/Enabled Subsystem' */

  /* Sum: '<S354>/Add' incorporates:
   *  Delay: '<S327>/MemoryX'
   */
  localB->rtb_Filter_idx_0 = localB->EnabledSubsystem_d.Product2[0] +
    localDW->MemoryX_DSTATE_g[0];

  /* Delay: '<S381>/MemoryX' */
  if (localDW->icLoad_k) {
    localDW->MemoryX_DSTATE_m[0] = 0.0F;
    localDW->MemoryX_DSTATE_m[1] = 0.0F;
  }

  /* Trigonometry: '<S324>/Trigonometric Function' incorporates:
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   *  Product: '<S324>/Divide'
   */
  localB->TrigonometricFunction = (real32_T)atan(localB->FIR_IMUaccel[1] /
    localB->r);

  /* Delay: '<S381>/MemoryX' */
  localB->MemoryX_g[0] = localDW->MemoryX_DSTATE_m[0];

  /* DataTypeConversion: '<S425>/Conversion' */
  localB->Conversion[0] = 0.00118693F;

  /* Delay: '<S381>/MemoryX' */
  localB->MemoryX_g[1] = localDW->MemoryX_DSTATE_m[1];

  /* DataTypeConversion: '<S425>/Conversion' */
  localB->Conversion[1] = -3.28681635E-5F;

  /* Outputs for Enabled SubSystem: '<S408>/Enabled Subsystem' */
  /* DataTypeConversion: '<S381>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S381>/C'
   */
  flightControlSystem_EnabledSubsystem(rtb_LogicalOperator != 0,
    localB->Conversion, rtCP_C_Value_i, localB->TrigonometricFunction,
    localB->MemoryX_g, &localB->EnabledSubsystem_n, &localDW->EnabledSubsystem_n);

  /* End of Outputs for SubSystem: '<S408>/Enabled Subsystem' */

  /* Sum: '<S408>/Add' incorporates:
   *  Delay: '<S381>/MemoryX'
   */
  localB->rtb_Integrator_idx_0 = localB->EnabledSubsystem_n.Product2[0] +
    localDW->MemoryX_DSTATE_m[0];

  /* DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_tmp = (localB->inverseIMU_gain[3] - -0.591549456F *
    localDW->LPFFcutoff40Hz1_states) / 2.5915494F;
  localB->p = localDW->LPFFcutoff40Hz1_tmp + localDW->LPFFcutoff40Hz1_states;

  /* DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_tmp = (localB->inverseIMU_gain[4] - -0.591549456F *
    localDW->LPFFcutoff40Hz_states) / 2.5915494F;
  localB->q = localDW->LPFFcutoff40Hz_tmp + localDW->LPFFcutoff40Hz_states;

  /* DiscreteFilter: '<S259>/IIR_IMUgyro_r' */
  localB->Gain_m = localB->inverseIMU_gain[5];
  localB->denIdx = 1;
  for (localB->i_k = 0; localB->i_k < 5; localB->i_k++) {
    localB->Gain_m -= rtCP_IIR_IMUgyro_r_DenCoef[localB->denIdx] *
      localDW->IIR_IMUgyro_r_states[localB->i_k];
    localB->denIdx++;
  }

  localDW->IIR_IMUgyro_r_tmp = localB->Gain_m;
  localB->Saturation_j = 0.282124132F * localDW->IIR_IMUgyro_r_tmp;
  localB->denIdx = 1;
  for (localB->i_k = 0; localB->i_k < 5; localB->i_k++) {
    localB->Saturation_j += rtCP_IIR_IMUgyro_r_NumCoef[localB->denIdx] *
      localDW->IIR_IMUgyro_r_states[localB->i_k];
    localB->denIdx++;
  }

  /* End of DiscreteFilter: '<S259>/IIR_IMUgyro_r' */

  /* RelationalOperator: '<S437>/Compare' incorporates:
   *  Constant: '<S437>/Constant'
   *  UnitDelay: '<S438>/Output'
   */
  rtb_Compare_o = (localDW->Output_DSTATE == 1U);

  /* Outputs for Triggered SubSystem: '<S435>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S439>/Trigger'
   */
  if (((localZCE->TriggeredSubsystem_Trig_ZCE == 1) != (int32_T)rtb_Compare_o) &&
      (localZCE->TriggeredSubsystem_Trig_ZCE != 3)) {
    /* Inport: '<S439>/In1' */
    localB->In1 = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature;
  }

  localZCE->TriggeredSubsystem_Trig_ZCE = rtb_Compare_o;

  /* End of Outputs for SubSystem: '<S435>/Triggered Subsystem' */

  /* Sum: '<S435>/Subtract1' incorporates:
   *  Gain: '<S435>/Gain'
   *  ManualSwitch: '<S435>/Disable temperature compensation'
   *  Sum: '<S435>/Subtract'
   */
  localB->r = localB->Saturation_j -
    (rtu_Sensors->HALSensors.HAL_gyro_SI.temperature - localB->In1) * 0.00228F;

  /* Sum: '<S258>/Subtract' incorporates:
   *  Delay: '<S327>/MemoryX'
   *  Delay: '<S381>/MemoryX'
   *  Sum: '<S354>/Add'
   *  Sum: '<S408>/Add'
   */
  localB->rtb_MathFunction_idx_0 = localB->p -
    (localB->EnabledSubsystem_n.Product2[1] + localDW->MemoryX_DSTATE_m[1]);
  localB->rtb_MathFunction_idx_1 = localB->q -
    (localB->EnabledSubsystem_d.Product2[1] + localDW->MemoryX_DSTATE_g[1]);

  /* Delay: '<S447>/MemoryX' */
  if (localDW->icLoad_o) {
    localDW->MemoryX_DSTATE_l[0] = 0.0F;
    localDW->MemoryX_DSTATE_l[1] = 0.0F;
    localDW->MemoryX_DSTATE_l[2] = 0.0F;
    localDW->MemoryX_DSTATE_l[3] = 0.0F;
  }

  /* Switch: '<S448>/Switch' incorporates:
   *  Constant: '<S519>/Constant'
   *  Gain: '<S448>/Gain'
   *  Gain: '<S448>/opticalFlowErrorCorrect'
   *  Product: '<S448>/ '
   *  RelationalOperator: '<S519>/Compare'
   *  UnitDelay: '<S520>/Output'
   */
  if (localDW->Output_DSTATE_n < 800U) {
    localB->rtb_Switch_m_idx_0 = rtu_Sensors->VisionSensors.opticalFlow_data[0];
    localB->rtb_Switch_m_idx_1 = rtu_Sensors->VisionSensors.opticalFlow_data[1];
  } else {
    localB->rtb_Switch_m_idx_0 = rtu_Sensors->VisionSensors.opticalFlow_data[0] *
      -localB->altfrompress * 1.15F;
    localB->rtb_Switch_m_idx_1 = rtu_Sensors->VisionSensors.opticalFlow_data[1] *
      -localB->altfrompress * 1.15F;
  }

  /* End of Switch: '<S448>/Switch' */

  /* Abs: '<S445>/Abs' */
  localB->Gain_m = (real32_T)fabs(localB->altfrompress);

  /* Sum: '<S442>/angular velocity compensation' incorporates:
   *  Gain: '<S445>/Gain1'
   *  Product: '<S445>/prod'
   */
  localB->angularvelocitycompensation[0] = localB->rtb_Switch_m_idx_0 +
    -(localB->Gain_m * localB->rtb_MathFunction_idx_1);
  localB->angularvelocitycompensation[1] = localB->Gain_m *
    localB->rtb_MathFunction_idx_0 + localB->rtb_Switch_m_idx_1;

  /* SignalConversion generated from: '<S446>/IIRgyroz' */
  localB->TmpSignalConversionAtIIRgyrozInport1[0] = localB->p;
  localB->TmpSignalConversionAtIIRgyrozInport1[1] = localB->q;
  for (localB->cff = 0; localB->cff < 2; localB->cff++) {
    /* DiscreteFilter: '<S446>/IIRgyroz' */
    localB->i = localB->cff * 5;
    localB->Gain_m = localB->TmpSignalConversionAtIIRgyrozInport1[localB->cff];
    localB->denIdx = 1;
    for (localB->i_k = 0; localB->i_k < 5; localB->i_k++) {
      localB->Gain_m -= localDW->IIRgyroz_states[localB->i + localB->i_k] *
        rtCP_IIRgyroz_DenCoef[localB->denIdx];
      localB->denIdx++;
    }

    localDW->IIRgyroz_tmp[localB->cff] = localB->Gain_m;
    localB->Saturation_j = 0.282124132F * localDW->IIRgyroz_tmp[localB->cff];
    localB->denIdx = 1;
    for (localB->i_k = 0; localB->i_k < 5; localB->i_k++) {
      localB->Saturation_j += localDW->IIRgyroz_states[localB->i + localB->i_k] *
        rtCP_IIRgyroz_NumCoef[localB->denIdx];
      localB->denIdx++;
    }

    /* SampleTimeMath: '<S454>/TSamp' incorporates:
     *  DiscreteFilter: '<S446>/IIRgyroz'
     *
     * About '<S454>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->Gain_m = localB->Saturation_j * 200.0F;

    /* DiscreteFilter: '<S446>/IIRgyroz' incorporates:
     *  Sum: '<S454>/Diff'
     *  UnitDelay: '<S454>/UD'
     */
    localB->Conversion[localB->cff] = localB->Gain_m - localDW->
      UD_DSTATE_k[localB->cff];

    /* SampleTimeMath: '<S454>/TSamp'
     *
     * About '<S454>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TmpSignalConversionAtIIRgyrozInport1[localB->cff] = localB->Gain_m;
  }

  /* Abs: '<S446>/Abs' incorporates:
   *  Abs: '<S446>/Abs4'
   */
  localB->Gain_m = (real32_T)fabs(localB->p);

  /* Abs: '<S446>/Abs1' incorporates:
   *  Abs: '<S446>/Abs5'
   */
  localB->pitchrollerror = (real32_T)fabs(localB->q);

  /* Logic: '<S446>/Logical Operator3' incorporates:
   *  Abs: '<S446>/Abs'
   *  Abs: '<S446>/Abs1'
   *  Abs: '<S446>/Abs2'
   *  Abs: '<S446>/Abs3'
   *  Abs: '<S446>/Abs6'
   *  Abs: '<S446>/Abs7'
   *  Abs: '<S446>/Abs8'
   *  Abs: '<S446>/Abs9'
   *  Constant: '<S455>/Constant'
   *  Constant: '<S456>/Constant'
   *  Constant: '<S457>/Constant'
   *  Constant: '<S458>/Constant'
   *  Constant: '<S459>/Constant'
   *  Constant: '<S460>/Constant'
   *  Constant: '<S461>/Constant'
   *  Constant: '<S462>/Constant'
   *  Constant: '<S463>/Constant'
   *  Constant: '<S464>/Constant'
   *  Constant: '<S465>/Constant'
   *  Delay: '<S442>/Delay'
   *  Logic: '<S446>/Logical Operator'
   *  Logic: '<S446>/Logical Operator1'
   *  Logic: '<S446>/Logical Operator2'
   *  RelationalOperator: '<S455>/Compare'
   *  RelationalOperator: '<S456>/Compare'
   *  RelationalOperator: '<S457>/Compare'
   *  RelationalOperator: '<S458>/Compare'
   *  RelationalOperator: '<S459>/Compare'
   *  RelationalOperator: '<S460>/Compare'
   *  RelationalOperator: '<S461>/Compare'
   *  RelationalOperator: '<S462>/Compare'
   *  RelationalOperator: '<S463>/Compare'
   *  RelationalOperator: '<S464>/Compare'
   *  RelationalOperator: '<S465>/Compare'
   *  Sum: '<S446>/Add'
   */
  rtb_Compare_o = (((((real32_T)fabs(localB->rtb_Filter_idx_0) <= 0.6F) &&
                     ((real32_T)fabs(localB->rtb_Integrator_idx_0) <= 0.6F) &&
                     (localB->Gain_m <= 7.0F) && (localB->pitchrollerror <= 7.0F)
                     && ((real32_T)fabs(localB->Conversion[0]) <= 80.0F) &&
                     ((real32_T)fabs(localB->Conversion[1]) <= 80.0F)) ||
                    ((localB->Gain_m <= 0.5F) && (localB->pitchrollerror <= 0.5F)))
                   && ((real32_T)fabs(localB->rtb_Switch_m_idx_0 -
    localDW->Delay_DSTATE_a[0]) <= 5.0F) && ((real32_T)fabs
    (localB->rtb_Switch_m_idx_1 - localDW->Delay_DSTATE_a[1]) <= 5.0F) &&
                   (localB->altfrompress <= -0.4F));

  /* Outputs for Enabled SubSystem: '<S492>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S518>/Enable'
   */
  if (rtb_Compare_o) {
    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S518>/Add1' incorporates:
     *  Constant: '<S447>/C'
     *  Delay: '<S447>/MemoryX'
     *  Product: '<S518>/Product'
     */
    for (localB->i_k = 0; localB->i_k < 2; localB->i_k++) {
      localB->rtb_angularvelocitycompensation_c[localB->i_k] =
        localB->angularvelocitycompensation[localB->i_k] -
        (((rtCP_C_Value_i2[localB->i_k + 2] * localDW->MemoryX_DSTATE_l[1] +
           rtCP_C_Value_i2[localB->i_k] * localDW->MemoryX_DSTATE_l[0]) +
          rtCP_C_Value_i2[localB->i_k + 4] * localDW->MemoryX_DSTATE_l[2]) +
         rtCP_C_Value_i2[localB->i_k + 6] * localDW->MemoryX_DSTATE_l[3]);
    }

    /* End of Sum: '<S518>/Add1' */
    for (localB->i_k = 0; localB->i_k < 4; localB->i_k++) {
      /* Product: '<S518>/Product2' incorporates:
       *  Constant: '<S466>/KalmanGainM'
       *  DataTypeConversion: '<S509>/Conversion'
       */
      localB->Product2_k[localB->i_k] = 0.0F;
      localB->Product2_k[localB->i_k] += (real32_T)
        rtCP_KalmanGainM_Value_i[localB->i_k] *
        localB->rtb_angularvelocitycompensation_c[0];
      localB->Product2_k[localB->i_k] += (real32_T)
        rtCP_KalmanGainM_Value_i[localB->i_k + 4] *
        localB->rtb_angularvelocitycompensation_c[1];
    }
  } else if (localDW->EnabledSubsystem_MODE) {
    /* Disable for Product: '<S518>/Product2' incorporates:
     *  Outport: '<S518>/deltax'
     */
    localB->Product2_k[0] = 0.0F;
    localB->Product2_k[1] = 0.0F;
    localB->Product2_k[2] = 0.0F;
    localB->Product2_k[3] = 0.0F;
    localDW->EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S492>/Enabled Subsystem' */

  /* Sum: '<S492>/Add' incorporates:
   *  Delay: '<S447>/MemoryX'
   */
  localB->Add_o[0] = localB->Product2_k[0] + localDW->MemoryX_DSTATE_l[0];
  localB->Add_o[1] = localB->Product2_k[1] + localDW->MemoryX_DSTATE_l[1];
  localB->Add_o[2] = localB->Product2_k[2] + localDW->MemoryX_DSTATE_l[2];
  localB->Add_o[3] = localB->Product2_k[3] + localDW->MemoryX_DSTATE_l[3];

  /* Trigonometry: '<S263>/sincos' incorporates:
   *  DiscreteIntegrator: '<S325>/Discrete-Time Integrator'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   *  SignalConversion generated from: '<S263>/sincos'
   *  Trigonometry: '<S450>/sincos'
   *  Trigonometry: '<S523>/sincos'
   */
  localB->Saturation_j = (real32_T)sin(localDW->DiscreteTimeIntegrator_DSTATE);
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 = (real32_T)
    cos(localDW->DiscreteTimeIntegrator_DSTATE);
  localB->pitchrollerror = (real32_T)sin(localB->rtb_Filter_idx_0);
  localB->rtb_Product_idx_0 = (real32_T)cos(localB->rtb_Filter_idx_0);
  localB->rtb_Product_idx_1 = (real32_T)sin(localB->rtb_Integrator_idx_0);
  u0 = (real32_T)cos(localB->rtb_Integrator_idx_0);

  /* Fcn: '<S263>/Fcn11' incorporates:
   *  Fcn: '<S450>/Fcn11'
   *  Fcn: '<S523>/Fcn11'
   *  Trigonometry: '<S263>/sincos'
   */
  localB->SaturationThrust1 =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 *
    localB->rtb_Product_idx_0;
  localB->MathFunction_g[0] = localB->SaturationThrust1;

  /* Fcn: '<S263>/Fcn21' incorporates:
   *  Fcn: '<S450>/Fcn21'
   *  Fcn: '<S523>/Fcn21'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 =
    localB->pitchrollerror * localB->rtb_Product_idx_1;
  rtb_MathFunction_g_tmp = localB->Saturation_j * u0;
  localB->MathFunction_g[1] =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 -
    rtb_MathFunction_g_tmp;

  /* Fcn: '<S263>/Fcn31' incorporates:
   *  Fcn: '<S450>/Fcn31'
   *  Fcn: '<S523>/Fcn31'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_SaturationThrust1_tmp = localB->pitchrollerror * u0;
  rtb_MathFunction_g_tmp_0 = localB->Saturation_j * localB->rtb_Product_idx_1;
  localB->MathFunction_g[2] = rtb_SaturationThrust1_tmp *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 +
    rtb_MathFunction_g_tmp_0;

  /* Fcn: '<S263>/Fcn12' incorporates:
   *  Fcn: '<S450>/Fcn12'
   *  Fcn: '<S523>/Fcn12'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_MathFunction_g_tmp_1 = localB->Saturation_j * localB->rtb_Product_idx_0;
  localB->MathFunction_g[3] = rtb_MathFunction_g_tmp_1;

  /* Fcn: '<S263>/Fcn22' incorporates:
   *  Fcn: '<S263>/Fcn21'
   *  Fcn: '<S450>/Fcn22'
   *  Fcn: '<S523>/Fcn22'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_MathFunction_g_tmp_2 =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 * u0;
  localB->MathFunction_g[4] =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *
    localB->Saturation_j + rtb_MathFunction_g_tmp_2;

  /* Fcn: '<S263>/Fcn32' incorporates:
   *  Fcn: '<S263>/Fcn31'
   *  Fcn: '<S450>/Fcn32'
   *  Fcn: '<S523>/Fcn32'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_MathFunction_g_tmp_3 =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 *
    localB->rtb_Product_idx_1;
  localB->MathFunction_g[5] = rtb_SaturationThrust1_tmp * localB->Saturation_j -
    rtb_MathFunction_g_tmp_3;

  /* Fcn: '<S263>/Fcn13' incorporates:
   *  Trigonometry: '<S263>/sincos'
   */
  localB->MathFunction_g[6] = -localB->pitchrollerror;

  /* Fcn: '<S263>/Fcn23' incorporates:
   *  Fcn: '<S450>/Fcn23'
   *  Fcn: '<S523>/Fcn23'
   *  Trigonometry: '<S263>/sincos'
   */
  localB->rtb_Product_idx_1 *= localB->rtb_Product_idx_0;
  localB->MathFunction_g[7] = localB->rtb_Product_idx_1;

  /* Fcn: '<S263>/Fcn33' incorporates:
   *  Fcn: '<S450>/Fcn33'
   *  Fcn: '<S523>/Fcn33'
   *  Trigonometry: '<S263>/sincos'
   */
  u0 *= localB->rtb_Product_idx_0;
  localB->MathFunction_g[8] = u0;

  /* DataTypeConversion: '<S257>/Data Type Conversion1' incorporates:
   *  Delay: '<S6>/Delay1'
   */
  localB->y_error = localDW->Delay1_DSTATE_p[0];
  localB->Diff = localDW->Delay1_DSTATE_p[1];

  /* Product: '<S257>/Product1' incorporates:
   *  DataTypeConversion: '<S257>/Data Type Conversion1'
   *  Math: '<S257>/Math Function'
   *  SignalConversion generated from: '<S257>/Product1'
   */
  for (localB->i_k = 0; localB->i_k < 3; localB->i_k++) {
    localB->flag_hover = localB->MathFunction_g[localB->i_k + 6] *
      localB->x_error;
    localB->u_h = localB->flag_hover + (localB->MathFunction_g[localB->i_k + 3] *
      localB->Diff + localB->MathFunction_g[localB->i_k] * localB->y_error);
    localB->Product1[localB->i_k] = localB->u_h;
    localB->rtb_MathFunction_g_m[localB->i_k] = localB->u_h;
  }

  /* End of Product: '<S257>/Product1' */

  /* DataTypeConversion: '<S257>/Data Type Conversion2' */
  localB->Gain_m = (real32_T)localB->rtb_MathFunction_g_m[2];

  /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
   *  DataTypeConversion: '<S257>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S325>/Discrete-Time Integrator'
   *  Sum: '<S258>/Subtract'
   */
  localB->TmpSignalConversionAtToWorkspaceInport1[2] = localB->altfrompress;
  localB->TmpSignalConversionAtToWorkspaceInport1[3] =
    localDW->DiscreteTimeIntegrator_DSTATE;
  localB->TmpSignalConversionAtToWorkspaceInport1[4] = localB->rtb_Filter_idx_0;
  localB->TmpSignalConversionAtToWorkspaceInport1[5] =
    localB->rtb_Integrator_idx_0;
  localB->TmpSignalConversionAtToWorkspaceInport1[0] =
    localB->SimplyIntegrateVelocity[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[6] = localB->Add_o[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[1] =
    localB->SimplyIntegrateVelocity[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[7] = localB->Add_o[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[8] = (real32_T)
    localB->Product1[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[9] =
    localB->rtb_MathFunction_idx_0;
  localB->TmpSignalConversionAtToWorkspaceInport1[10] =
    localB->rtb_MathFunction_idx_1;
  localB->TmpSignalConversionAtToWorkspaceInport1[11] = localB->r;

  /* Math: '<S257>/Math Function' */
  for (localB->i_k = 0; localB->i_k < 3; localB->i_k++) {
    localB->VectorConcatenate[3 * localB->i_k] = localB->MathFunction_g
      [localB->i_k];
    localB->VectorConcatenate[3 * localB->i_k + 1] = localB->
      MathFunction_g[localB->i_k + 3];
    localB->VectorConcatenate[3 * localB->i_k + 2] = localB->
      MathFunction_g[localB->i_k + 6];
  }

  for (localB->i_k = 0; localB->i_k < 9; localB->i_k++) {
    localB->MathFunction_g[localB->i_k] = localB->VectorConcatenate[localB->i_k];
  }

  /* End of Math: '<S257>/Math Function' */

  /* Fcn: '<S523>/Fcn11' */
  localB->MathFunction_a[0] = localB->SaturationThrust1;

  /* Fcn: '<S523>/Fcn21' */
  localB->MathFunction_a[1] =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 -
    rtb_MathFunction_g_tmp;

  /* Fcn: '<S523>/Fcn31' */
  localB->MathFunction_a[2] = rtb_SaturationThrust1_tmp *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 +
    rtb_MathFunction_g_tmp_0;

  /* Fcn: '<S523>/Fcn12' */
  localB->MathFunction_a[3] = rtb_MathFunction_g_tmp_1;

  /* Fcn: '<S523>/Fcn22' */
  localB->MathFunction_a[4] =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *
    localB->Saturation_j + rtb_MathFunction_g_tmp_2;

  /* Fcn: '<S523>/Fcn32' */
  localB->MathFunction_a[5] = rtb_SaturationThrust1_tmp * localB->Saturation_j -
    rtb_MathFunction_g_tmp_3;

  /* Fcn: '<S523>/Fcn13' */
  localB->MathFunction_a[6] = -localB->pitchrollerror;

  /* Fcn: '<S523>/Fcn23' */
  localB->MathFunction_a[7] = localB->rtb_Product_idx_1;

  /* Fcn: '<S523>/Fcn33' */
  localB->MathFunction_a[8] = u0;

  /* Math: '<S443>/Math Function' */
  for (localB->i_k = 0; localB->i_k < 3; localB->i_k++) {
    localB->VectorConcatenate[3 * localB->i_k] = localB->MathFunction_a
      [localB->i_k];
    localB->VectorConcatenate[3 * localB->i_k + 1] = localB->
      MathFunction_a[localB->i_k + 3];
    localB->VectorConcatenate[3 * localB->i_k + 2] = localB->
      MathFunction_a[localB->i_k + 6];
  }

  for (localB->i_k = 0; localB->i_k < 9; localB->i_k++) {
    localB->MathFunction_a[localB->i_k] = localB->VectorConcatenate[localB->i_k];
  }

  /* End of Math: '<S443>/Math Function' */

  /* RelationalOperator: '<S449>/Compare' incorporates:
   *  Constant: '<S449>/Constant'
   */
  rtb_Compare_hgg = (localB->altfrompress <= -0.4F);

  /* Logic: '<S444>/Logical Operator' incorporates:
   *  Constant: '<S451>/Constant'
   *  Constant: '<S452>/Constant'
   *  RelationalOperator: '<S451>/Compare'
   *  RelationalOperator: '<S452>/Compare'
   */
  rtb_Compare_fo = ((localB->rtb_Switch_m_idx_0 != 0.0F) ||
                    (localB->rtb_Switch_m_idx_1 != 0.0F));

  /* Fcn: '<S450>/Fcn11' */
  localB->VectorConcatenate[0] = localB->SaturationThrust1;

  /* Fcn: '<S450>/Fcn21' */
  localB->VectorConcatenate[1] =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 -
    rtb_MathFunction_g_tmp;

  /* Fcn: '<S450>/Fcn31' */
  localB->VectorConcatenate[2] = rtb_SaturationThrust1_tmp *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 +
    rtb_MathFunction_g_tmp_0;

  /* Fcn: '<S450>/Fcn12' */
  localB->VectorConcatenate[3] = rtb_MathFunction_g_tmp_1;

  /* Fcn: '<S450>/Fcn22' */
  localB->VectorConcatenate[4] =
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 *
    localB->Saturation_j + rtb_MathFunction_g_tmp_2;

  /* Fcn: '<S450>/Fcn32' */
  localB->VectorConcatenate[5] = rtb_SaturationThrust1_tmp *
    localB->Saturation_j - rtb_MathFunction_g_tmp_3;

  /* Fcn: '<S450>/Fcn13' */
  localB->VectorConcatenate[6] = -localB->pitchrollerror;

  /* Fcn: '<S450>/Fcn23' */
  localB->VectorConcatenate[7] = localB->rtb_Product_idx_1;

  /* Fcn: '<S450>/Fcn33' */
  localB->VectorConcatenate[8] = u0;

  /* Sum: '<S444>/Add' incorporates:
   *  Concatenate: '<S453>/Vector Concatenate'
   *  Product: '<S444>/Product1'
   */
  for (localB->i_k = 0; localB->i_k < 3; localB->i_k++) {
    localB->Product1[localB->i_k] = localB->FIR_IMUaccel[localB->i_k] -
      ((localB->VectorConcatenate[localB->i_k + 3] * 0.0 +
        localB->VectorConcatenate[localB->i_k] * 0.0) +
       localB->VectorConcatenate[localB->i_k + 6] * -9.81);
  }

  /* End of Sum: '<S444>/Add' */

  /* Product: '<S444>/Product' incorporates:
   *  Gain: '<S444>/gainaccinput1'
   */
  localB->rtb_Product_idx_0 = (real32_T)rtb_Compare_fo * (real32_T)
    localB->Product1[0] * (real32_T)rtb_Compare_hgg;
  localB->rtb_Product_idx_1 = (real32_T)rtb_Compare_fo * (real32_T)
    localB->Product1[1] * (real32_T)rtb_Compare_hgg;

  /* Outputs for Enabled SubSystem: '<S485>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S516>/Enable'
   */
  if (rtb_Compare_o) {
    localDW->MeasurementUpdate_MODE = true;
    for (localB->i_k = 0; localB->i_k < 2; localB->i_k++) {
      /* Sum: '<S516>/Sum' incorporates:
       *  Constant: '<S447>/C'
       *  Delay: '<S447>/MemoryX'
       *  Product: '<S516>/C[k]*xhat[k|k-1]'
       *  Product: '<S516>/D[k]*u[k]'
       *  Sum: '<S516>/Add1'
       */
      localB->rtb_angularvelocitycompensation_c[localB->i_k] =
        localB->angularvelocitycompensation[localB->i_k] -
        ((rtCP_C_Value_i2[localB->i_k + 6] * localDW->MemoryX_DSTATE_l[3] +
          (rtCP_C_Value_i2[localB->i_k + 4] * localDW->MemoryX_DSTATE_l[2] +
           (rtCP_C_Value_i2[localB->i_k + 2] * localDW->MemoryX_DSTATE_l[1] +
            rtCP_C_Value_i2[localB->i_k] * localDW->MemoryX_DSTATE_l[0]))) +
         (0.0F * localB->rtb_Product_idx_1 + 0.0F * localB->rtb_Product_idx_0));
    }

    for (localB->i_k = 0; localB->i_k < 4; localB->i_k++) {
      /* Product: '<S516>/Product3' incorporates:
       *  Constant: '<S466>/KalmanGainL'
       *  DataTypeConversion: '<S508>/Conversion'
       */
      localB->Product3_a[localB->i_k] = 0.0F;
      localB->Product3_a[localB->i_k] += (real32_T)rtCP_KalmanGainL_Value
        [localB->i_k] * localB->rtb_angularvelocitycompensation_c[0];
      localB->Product3_a[localB->i_k] += (real32_T)rtCP_KalmanGainL_Value
        [localB->i_k + 4] * localB->rtb_angularvelocitycompensation_c[1];
    }
  } else if (localDW->MeasurementUpdate_MODE) {
    /* Disable for Product: '<S516>/Product3' incorporates:
     *  Outport: '<S516>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3_a[0] = 0.0F;
    localB->Product3_a[1] = 0.0F;
    localB->Product3_a[2] = 0.0F;
    localB->Product3_a[3] = 0.0F;
    localDW->MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S485>/MeasurementUpdate' */

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  UnitDelay: '<S14>/Output'
   */
  rtb_Compare_o = (localDW->Output_DSTATE_h < 100);

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  if ((!rtb_Compare_o) && (localDW->DiscreteTimeIntegrator_PrevResetState == 1))
  {
    localDW->DiscreteTimeIntegrator_DSTATE_d = 0.0F;
  }

  if (localDW->DiscreteTimeIntegrator_DSTATE_d >= 2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_d = 2.0F;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE_d <= -2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_d = -2.0F;
  }

  /* MATLAB Function: '<S5>/Take off checker' */
  localB->flag_hover = ((localB->altfrompress < -0.65) && (localB->altfrompress >
    -0.75F));

  /* Chart: '<S5>/circle count' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c10_flightControlSystem == 0U) {
    localDW->is_active_c10_flightControlSystem = 1U;
    localB->circle_count = 0.0;
    localB->flag_tracelane = 0.0;
    localDW->is_c10_flightControlSystem = flightControlSystem_IN_IDLE_h;
    localDW->temporalCounter_i1 = 0U;
  } else {
    switch (localDW->is_c10_flightControlSystem) {
     case flightControlSystem_IN_IDLE_h:
      if ((localDW->temporalCounter_i1 >= 600U) && (localB->flag_hover == 1.0))
      {
        localDW->is_c10_flightControlSystem =
          flightControlSystem_IN_LEAVE_MARKER_p;
        localB->flag_tracelane = 1.0;
      }
      break;

     case flightControlSystem_IN_LEAVE_MARKER_p:
      if ((localB->flag_hover == 1.0) && (rtu_VisionbasedData[2] == 0.0)) {
        localDW->is_c10_flightControlSystem = flightControlSystem_IN_TRACE_LANE;
        localB->flag_tracelane = 1.0;
      }
      break;

     case flightControlSystem_IN_MARKER_DETECTED:
      if (localB->flag_hover == 0.0) {
        localDW->is_c10_flightControlSystem =
          flightControlSystem_IN_LEAVE_MARKER_p;
        localB->flag_tracelane = 1.0;
      }
      break;

     default:
      /* case IN_TRACE_LANE: */
      if (rtu_VisionbasedData[2] == 1.0) {
        localDW->is_c10_flightControlSystem =
          flightControlSystem_IN_MARKER_DETECTED;
        localB->circle_count++;
        localB->flag_tracelane = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/circle count' */

  /* MATLAB Function: '<S5>/MATLAB Function' */
  if (localB->flag_hover == 1.0) {
    if (localB->flag_tracelane == 0.0) {
      localB->x_error = rtu_VisionbasedData[0];
      localB->y_error = rtu_VisionbasedData[1];
    } else {
      localB->x_error = rtu_VisionbasedData[3];
      localB->y_error = rtu_VisionbasedData[4];
    }
  } else {
    localB->x_error = 0.0;
    localB->y_error = 0.0;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* Sum: '<S246>/Diff' incorporates:
   *  SampleTimeMath: '<S246>/TSamp'
   *  UnitDelay: '<S246>/UD'
   *
   * About '<S246>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  localB->Diff = localB->x_error - localDW->UD_DSTATE;

  /* MATLAB Function: '<S236>/parameter_setting' */
  if (localB->circle_count < 1.0) {
    localB->u_h = 10.0;
  } else {
    localB->u_h = 100.0;
  }

  /* End of MATLAB Function: '<S236>/parameter_setting' */

  /* MATLAB Function: '<S244>/MATLAB Function' */
  flightControlSystem_MATLABFunction(localB->Diff, localB->u_h,
    &localB->sf_MATLABFunction_e);

  /* MATLAB Function: '<S244>/derivative error' incorporates:
   *  Delay: '<S244>/Delay'
   *  Delay: '<S244>/Delay5'
   *  Delay: '<S244>/Delay6'
   */
  flightControlSystem_derivativeerror(localDW->Delay6_DSTATE, localB->Diff,
    localB->sf_MATLABFunction_e.flag_change_error, localDW->Delay_DSTATE,
    localDW->Delay5_DSTATE, &localB->sf_derivativeerror,
    &localDW->sf_derivativeerror);

  /* Chart: '<S239>/x_linear_contribute' */
  if (localDW->is_active_c20_flightControlSystem == 0U) {
    localDW->is_active_c20_flightControlSystem = 1U;
    localDW->is_c20_flightControlSystem = flightControlSystem_IN_IDLE;
  } else {
    switch (localDW->is_c20_flightControlSystem) {
     case flightControlSystem_IN_END_MARKER_DETECTED:
      localB->linear_part_c = localB->x_error * 0.0022;
      break;

     case flightControlSystem_IN_IDLE:
      localDW->is_c20_flightControlSystem =
        flightControlSystem_IN_TRACK_DETECTED;
      break;

     default:
      /* case IN_TRACK_DETECTED: */
      if ((rtu_VisionbasedData[2] == 1.0) && (rtu_VisionbasedData[5] == 0.0)) {
        localDW->is_c20_flightControlSystem =
          flightControlSystem_IN_END_MARKER_DETECTED;
      } else {
        localB->linear_part_c = localB->x_error * 0.0038;
      }
      break;
    }
  }

  /* End of Chart: '<S239>/x_linear_contribute' */

  /* MATLAB Function: '<S241>/MATLAB Function' incorporates:
   *  Delay: '<S241>/Delay1'
   */
  if (rtu_VisionbasedData[2] != 0.0) {
    localB->Diff = sqrt(localB->x_error * localB->x_error + localB->y_error *
                        localB->y_error);
    localB->norm_error_tot = localB->Diff + localDW->Delay1_DSTATE[0];
  } else {
    localB->norm_error_tot = 100.0;
    localB->Diff = 100.0;
  }

  /* Chart: '<S241>/Chart' */
  if (localDW->temporalCounter_i1_n < 1023U) {
    localDW->temporalCounter_i1_n++;
  }

  if (localDW->is_active_c25_flightControlSystem == 0U) {
    localDW->is_active_c25_flightControlSystem = 1U;
    localDW->circle_count = 0.0;
    localDW->is_c25_flightControlSystem = flightControlSystem_IN_TAKE_OFF_p;
    localDW->temporalCounter_i1_n = 0U;
    localB->z_planned = -0.7;
    localB->flag_end_marker_to_controller = 0.0;
  } else {
    switch (localDW->is_c25_flightControlSystem) {
     case flightControlSystem_IN_Grabbing:
      localB->flag_end_marker_to_controller = 1.0;
      if ((localDW->temporalCounter_i1_n >= 600U) && (localDW->circle_count <=
           1.0)) {
        localDW->is_c25_flightControlSystem = flightControlSystem_IN_TAKE_OFF_p;
        localDW->temporalCounter_i1_n = 0U;
        localB->z_planned = -0.7;
        localB->flag_end_marker_to_controller = 0.0;
      } else if (localDW->circle_count > 1.0) {
        localDW->is_c25_flightControlSystem = flightControlSystem_IN_LANDING;
        localB->z_planned += 0.0005;
      }
      break;

     case flightControlSystem_IN_LANDING:
      if (localB->z_planned <= 0.0) {
        localDW->is_c25_flightControlSystem = flightControlSystem_IN_LANDING;
        localB->z_planned += 0.0005;
      }
      break;

     case flightControlSystem_IN_TAKE_OFF_p:
      localB->flag_end_marker_to_controller = 0.0;
      if ((localDW->temporalCounter_i1_n >= 600U) && (localB->flag_hover == 1.0)
          && (rtu_VisionbasedData[2] == 0.0)) {
        localDW->is_c25_flightControlSystem = flightControlSystem_IN_TRACKING;
        localB->z_planned = -0.7;
        localB->flag_end_marker_to_controller = 0.0;
      }
      break;

     default:
      /* case IN_TRACKING: */
      localB->flag_end_marker_to_controller = 0.0;
      if ((rtu_VisionbasedData[2] == 1.0) && (localB->norm_error_tot <= 20.0)) {
        localDW->is_c25_flightControlSystem = flightControlSystem_IN_Grabbing;
        localDW->temporalCounter_i1_n = 0U;
        localB->z_planned = -0.5;
        localB->flag_end_marker_to_controller = 1.0;
        localDW->circle_count++;
      }
      break;
    }
  }

  /* End of Chart: '<S241>/Chart' */

  /* Chart: '<S239>/Chart1' incorporates:
   *  DataTypeConversion: '<S239>/Cast To Double1'
   */
  if (localDW->temporalCounter_i1_k < 1023U) {
    localDW->temporalCounter_i1_k++;
  }

  if (localDW->is_active_c5_flightControlSystem == 0U) {
    localDW->is_active_c5_flightControlSystem = 1U;
    localDW->circle_count_m = 0.0;
    localDW->is_c5_flightControlSystem = flightControlSystem_IN_TAKE_OFF;
    localDW->temporalCounter_i1_k = 0U;
    localB->x_planned = 0.0;
  } else {
    switch (localDW->is_c5_flightControlSystem) {
     case flightControlSystem_IN_END_MARKER_DETECTED:
      if (localB->flag_end_marker_to_controller == 1.0) {
        localDW->is_c5_flightControlSystem = flightControlSystem_IN_LANDING;
        localDW->temporalCounter_i1_k = 0U;
        localB->x_planned = localDW->x_planned_stored;
      } else {
        localB->x_planned = localB->SimplyIntegrateVelocity[0] +
          localB->linear_part_c;
        localDW->x_planned_stored = localB->x_planned;
      }
      break;

     case flightControlSystem_IN_LANDING:
      if ((localDW->temporalCounter_i1_k >= 1000U) && (localB->flag_hover == 1.0)
          && (localDW->circle_count_m <= 1.0)) {
        localDW->is_c5_flightControlSystem = flightControlSystem_IN_LEAVE_MARKER;
      }
      break;

     case flightControlSystem_IN_LEAVE_MARKER:
      if (rtu_VisionbasedData[2] == 0.0) {
        localDW->is_c5_flightControlSystem =
          flightControlSystem_IN_LINE_FOLLOWING;
      } else {
        localB->x_planned = (localB->SimplyIntegrateVelocity[0] +
                             localB->linear_part_c) +
          localB->sf_derivativeerror.dev_contribute;
        localDW->x_planned_stored = localB->x_planned;
      }
      break;

     case flightControlSystem_IN_LINE_FOLLOWING:
      if (rtu_VisionbasedData[2] == 1.0) {
        localDW->is_c5_flightControlSystem =
          flightControlSystem_IN_END_MARKER_DETECTED;
        localDW->circle_count_m++;
      } else {
        localB->x_planned = (localB->SimplyIntegrateVelocity[0] +
                             localB->linear_part_c) +
          localB->sf_derivativeerror.dev_contribute;
        localDW->x_planned_stored = localB->x_planned;
      }
      break;

     default:
      /* case IN_TAKE_OFF: */
      if ((localDW->temporalCounter_i1_k >= 600U) && (localB->flag_hover == 1.0))
      {
        localDW->is_c5_flightControlSystem = flightControlSystem_IN_LEAVE_MARKER;
      } else {
        localB->x_planned = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S239>/Chart1' */

  /* Sum: '<S252>/Diff' incorporates:
   *  SampleTimeMath: '<S252>/TSamp'
   *  UnitDelay: '<S252>/UD'
   *
   * About '<S252>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  localB->norm_error_tot = localB->y_error - localDW->UD_DSTATE_i;

  /* MATLAB Function: '<S250>/MATLAB Function' */
  flightControlSystem_MATLABFunction(localB->norm_error_tot, localB->u_h,
    &localB->sf_MATLABFunction_o);

  /* MATLAB Function: '<S250>/derivative error' incorporates:
   *  Delay: '<S250>/Delay'
   *  Delay: '<S250>/Delay5'
   *  Delay: '<S250>/Delay6'
   */
  flightControlSystem_derivativeerror(localDW->Delay6_DSTATE_o,
    localB->norm_error_tot, localB->sf_MATLABFunction_o.flag_change_error,
    localDW->Delay_DSTATE_d, localDW->Delay5_DSTATE_h,
    &localB->sf_derivativeerror_c, &localDW->sf_derivativeerror_c);

  /* Chart: '<S240>/y_linear_contribute' */
  if (localDW->is_active_c24_flightControlSystem == 0U) {
    localDW->is_active_c24_flightControlSystem = 1U;
    localDW->is_c24_flightControlSystem = flightControlSystem_IN_IDLE;
  } else {
    switch (localDW->is_c24_flightControlSystem) {
     case flightControlSystem_IN_END_MARKER_DETECTED:
      localB->linear_part = localB->y_error * 0.0022;
      break;

     case flightControlSystem_IN_IDLE:
      if ((rtu_VisionbasedData[2] == 1.0) && (rtu_VisionbasedData[5] == 0.0)) {
        localDW->is_c24_flightControlSystem =
          flightControlSystem_IN_TRACK_DETECTED;
      }
      break;

     default:
      /* case IN_TRACK_DETECTED: */
      if ((rtu_VisionbasedData[2] == 1.0) && (rtu_VisionbasedData[5] == 0.0)) {
        localDW->is_c24_flightControlSystem =
          flightControlSystem_IN_END_MARKER_DETECTED;
      } else {
        localB->linear_part = localB->y_error * 0.0038;
      }
      break;
    }
  }

  /* End of Chart: '<S240>/y_linear_contribute' */

  /* Chart: '<S240>/Chart1' incorporates:
   *  DataTypeConversion: '<S240>/Cast To Double1'
   */
  if (localDW->temporalCounter_i1_p < 1023U) {
    localDW->temporalCounter_i1_p++;
  }

  if (localDW->is_active_c21_flightControlSystem == 0U) {
    localDW->is_active_c21_flightControlSystem = 1U;
    localDW->circle_count_k = 0.0;
    localDW->y_planned_stored = 0.0;
    localDW->is_c21_flightControlSystem = flightControlSystem_IN_TAKE_OFF;
    localDW->temporalCounter_i1_p = 0U;
    localB->y_planned = 0.0;
  } else {
    switch (localDW->is_c21_flightControlSystem) {
     case flightControlSystem_IN_END_MARKER_DETECTED:
      if (localB->flag_end_marker_to_controller == 1.0) {
        localDW->is_c21_flightControlSystem = flightControlSystem_IN_LANDING;
        localDW->temporalCounter_i1_p = 0U;
        localB->y_planned = localDW->y_planned_stored;
      } else {
        localB->y_planned = localB->SimplyIntegrateVelocity[1] +
          localB->linear_part;
        localDW->y_planned_stored = localB->y_planned;
      }
      break;

     case flightControlSystem_IN_LANDING:
      if ((localDW->temporalCounter_i1_p >= 1000U) && (localB->flag_hover == 1.0)
          && (localDW->circle_count_k <= 1.0)) {
        localDW->is_c21_flightControlSystem =
          flightControlSystem_IN_LEAVE_MARKER;
      }
      break;

     case flightControlSystem_IN_LEAVE_MARKER:
      if (rtu_VisionbasedData[2] == 0.0) {
        localDW->is_c21_flightControlSystem =
          flightControlSystem_IN_LINE_FOLLOWING;
      } else {
        localB->y_planned = (localB->SimplyIntegrateVelocity[1] +
                             localB->linear_part) +
          localB->sf_derivativeerror_c.dev_contribute;
        localDW->y_planned_stored = localB->y_planned;
      }
      break;

     case flightControlSystem_IN_LINE_FOLLOWING:
      if (rtu_VisionbasedData[2] == 1.0) {
        localDW->is_c21_flightControlSystem =
          flightControlSystem_IN_END_MARKER_DETECTED;
        localDW->circle_count_k++;
      } else {
        localB->y_planned = (localB->SimplyIntegrateVelocity[1] +
                             localB->linear_part) +
          localB->sf_derivativeerror_c.dev_contribute;
        localDW->y_planned_stored = localB->y_planned;
      }
      break;

     default:
      /* case IN_TAKE_OFF: */
      if ((localDW->temporalCounter_i1_p >= 600U) && (localB->flag_hover == 1.0))
      {
        localDW->is_c21_flightControlSystem =
          flightControlSystem_IN_LEAVE_MARKER;
      } else {
        localB->y_planned = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S240>/Chart1' */

  /* Sum: '<S7>/Sum2' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion3'
   */
  localB->pitchrollerror = (real32_T)localB->z_planned - localB->altfrompress;

  /* Switch: '<S7>/TakeoffOrControl_Switch1' incorporates:
   *  Constant: '<S7>/w1'
   *  DataTypeConversion: '<S257>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S7>/D_z1'
   *  Gain: '<S7>/P_z1'
   *  Gain: '<S7>/takeoff_gain1'
   *  Sum: '<S7>/Sum1'
   */
  if (rtb_Compare_o) {
    localB->SaturationThrust1 = -0.278113484F;
  } else {
    localB->SaturationThrust1 = (0.8F * localB->pitchrollerror +
      localDW->DiscreteTimeIntegrator_DSTATE_d) - 0.5F * (real32_T)
      localB->rtb_MathFunction_g_m[2];
  }

  /* End of Switch: '<S7>/TakeoffOrControl_Switch1' */

  /* Sum: '<S10>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  DataTypeConversion: '<S5>/Data Type Conversion2'
   */
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 = (real32_T)
    localB->x_planned - localB->SimplyIntegrateVelocity[0];
  rtb_MathFunction_g_tmp = (real32_T)localB->y_planned -
    localB->SimplyIntegrateVelocity[1];

  /* Saturate: '<S159>/Saturation' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  u0 = (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 *
        rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 +
        localB->Saturation_j * rtb_MathFunction_g_tmp) * 0.7F;
  if (u0 > 0.5F) {
    u0 = 0.5F;
  } else if (u0 < -0.5F) {
    u0 = -0.5F;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   */
  localB->rtb_Switch_m_idx_0 = u0 - localB->Add_o[0];

  /* Sum: '<S211>/Sum' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  Gain: '<S207>/Proportional Gain'
   */
  localB->rtb_Switch_m_idx_1 = 0.2F * localB->rtb_Switch_m_idx_0 +
    localDW->Integrator_DSTATE[0];

  /* Saturate: '<S209>/Saturation' */
  if (localB->rtb_Switch_m_idx_1 > 0.34906584F) {
    u0 = 0.34906584F;
  } else if (localB->rtb_Switch_m_idx_1 < -0.34906584F) {
    u0 = -0.34906584F;
  } else {
    u0 = localB->rtb_Switch_m_idx_1;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_g[0] =
    (u0 - -6.95774698F *
     localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0])
    / 8.95774746F;

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   */
  localB->angularvelocitycompensation[0] = localB->rtb_Switch_m_idx_0;

  /* Sum: '<S211>/Sum' */
  localB->Conversion[0] = localB->rtb_Switch_m_idx_1;

  /* Saturate: '<S159>/Saturation' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  u0 = (-localB->Saturation_j *
        rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 +
        rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 *
        rtb_MathFunction_g_tmp) * 0.7F;
  if (u0 > 0.5F) {
    u0 = 0.5F;
  } else if (u0 < -0.5F) {
    u0 = -0.5F;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   */
  localB->rtb_Switch_m_idx_0 = u0 - localB->Add_o[1];

  /* Sum: '<S211>/Sum' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  Gain: '<S207>/Proportional Gain'
   */
  localB->rtb_Switch_m_idx_1 = 0.2F * localB->rtb_Switch_m_idx_0 +
    localDW->Integrator_DSTATE[1];

  /* Saturate: '<S209>/Saturation' */
  if (localB->rtb_Switch_m_idx_1 > 0.34906584F) {
    u0 = 0.34906584F;
  } else if (localB->rtb_Switch_m_idx_1 < -0.34906584F) {
    u0 = -0.34906584F;
  } else {
    u0 = localB->rtb_Switch_m_idx_1;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_g[1] =
    (u0 - -6.95774698F *
     localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1])
    / 8.95774746F;

  /* Sum: '<S8>/Sum1' incorporates:
   *  DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   *  Gain: '<S10>/Gain'
   *  Gain: '<S55>/Proportional Gain'
   *  Sum: '<S8>/Sum19'
   *  Switch: '<S3>/Switch_refAtt'
   */
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 =
    (-(localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_g
       [0] +
       localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
       [0]) - localB->rtb_Filter_idx_0) * 4.0F - localB->rtb_MathFunction_idx_1;
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 =
    ((localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_g[1]
      + localDW->
      LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1]) -
     localB->rtb_Integrator_idx_0) * 4.0F - localB->rtb_MathFunction_idx_0;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  localB->rtb_MathFunction_idx_0 = (0.00012F *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 -
    localDW->Filter_DSTATE[0]) * 70.0F;

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Gain: '<S94>/Derivative Gain'
   */
  localB->rtb_MathFunction_idx_1 = (0.003F *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 +
    localDW->Integrator_DSTATE_n[0]) + localB->rtb_MathFunction_idx_0;

  /* Saturate: '<S107>/Saturation' */
  if (localB->rtb_MathFunction_idx_1 > 0.02F) {
    rtb_SaturationThrust1_tmp = 0.02F;
  } else if (localB->rtb_MathFunction_idx_1 < -0.02F) {
    rtb_SaturationThrust1_tmp = -0.02F;
  } else {
    rtb_SaturationThrust1_tmp = localB->rtb_MathFunction_idx_1;
  }

  /* Gain: '<S103>/Filter Coefficient' */
  localB->rtb_Filter_idx_0 = localB->rtb_MathFunction_idx_0;

  /* Sum: '<S109>/Sum' */
  localB->rtb_Integrator_idx_0 = localB->rtb_MathFunction_idx_1;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  localB->rtb_MathFunction_idx_0 = (9.72E-5F *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 -
    localDW->Filter_DSTATE[1]) * 70.0F;

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Gain: '<S94>/Derivative Gain'
   */
  localB->rtb_MathFunction_idx_1 = (0.00243F *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0 +
    localDW->Integrator_DSTATE_n[1]) + localB->rtb_MathFunction_idx_0;

  /* Saturate: '<S107>/Saturation' */
  if (localB->rtb_MathFunction_idx_1 > 0.02F) {
    rtb_MathFunction_g_tmp_0 = 0.02F;
  } else if (localB->rtb_MathFunction_idx_1 < -0.02F) {
    rtb_MathFunction_g_tmp_0 = -0.02F;
  } else {
    rtb_MathFunction_g_tmp_0 = localB->rtb_MathFunction_idx_1;
  }

  /* Sum: '<S11>/Sum1' incorporates:
   *  BusAssignment: '<S1>/Control Mode Update'
   *  DiscreteIntegrator: '<S325>/Discrete-Time Integrator'
   */
  localB->Saturation_j = rtu_ReferenceValueServerCmds->orient_ref[0] -
    localDW->DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<S11>/Saturation' */
  if (localB->Saturation_j > 0.52359879F) {
    localB->Saturation_j = 0.52359879F;
  } else if (localB->Saturation_j < -0.52359879F) {
    localB->Saturation_j = -0.52359879F;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Saturate: '<S7>/SaturationThrust1' incorporates:
   *  Constant: '<S7>/w1'
   *  Sum: '<S7>/Sum5'
   */
  if (localB->SaturationThrust1 + -0.61803F > 1.20204329F) {
    rtb_MathFunction_g_tmp = 1.20204329F;
  } else if (localB->SaturationThrust1 + -0.61803F < -1.20204329F) {
    rtb_MathFunction_g_tmp = -1.20204329F;
  } else {
    rtb_MathFunction_g_tmp = localB->SaturationThrust1 + -0.61803F;
  }

  /* SignalConversion generated from: '<S9>/Product' incorporates:
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Gain: '<S11>/D_yaw'
   *  Gain: '<S11>/P_yaw'
   *  Sum: '<S11>/Sum2'
   *  Sum: '<S258>/Subtract'
   */
  rtb_MathFunction_g_tmp_1 = (0.004F * localB->Saturation_j +
    localDW->DiscreteTimeIntegrator_DSTATE_p) - 0.0012F * localB->r;
  for (localB->i_k = 0; localB->i_k < 4; localB->i_k++) {
    /* Saturate: '<S12>/Saturation5' incorporates:
     *  Constant: '<S9>/Pitch correction'
     *  Constant: '<S9>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S12>/ThrustToMotorCommand'
     *  Product: '<S9>/Product'
     *  Saturate: '<S107>/Saturation'
     *  Saturate: '<S7>/SaturationThrust1'
     *  Sum: '<S9>/Add'
     */
    u0 = -1530.72681F * (rtCP_TorqueTotalThrustToThrustPerMotor_Value
                         [localB->i_k + 12] * rtb_MathFunction_g_tmp_0 +
                         (rtCP_TorqueTotalThrustToThrustPerMotor_Value
                          [localB->i_k + 8] * (rtb_SaturationThrust1_tmp +
      0.002F) + (rtCP_TorqueTotalThrustToThrustPerMotor_Value[localB->i_k + 4] *
                 rtb_MathFunction_g_tmp_1 +
                 rtCP_TorqueTotalThrustToThrustPerMotor_Value[localB->i_k] *
                 rtb_MathFunction_g_tmp)));
    if (u0 > 500.0F) {
      u0 = 500.0F;
    } else if (u0 < 10.0F) {
      u0 = 10.0F;
    }

    /* End of Saturate: '<S12>/Saturation5' */

    /* Gain: '<S12>/MotorDirections' */
    localB->MotorDirections[localB->i_k] = rtCP_MotorDirections_Gain[localB->i_k]
      * u0;
  }

  /* Sum: '<S257>/Sum' incorporates:
   *  Constant: '<S257>/gravity'
   *  Math: '<S257>/Math Function'
   *  Product: '<S257>/Product'
   */
  for (localB->i_k = 0; localB->i_k < 3; localB->i_k++) {
    localB->Product1[localB->i_k] = ((localB->MathFunction_g[localB->i_k + 3] *
      localB->FIR_IMUaccel[1] + localB->MathFunction_g[localB->i_k] *
      localB->FIR_IMUaccel[0]) + localB->MathFunction_g[localB->i_k + 6] *
      localB->FIR_IMUaccel[2]) + rtCP_gravity_Value_j[localB->i_k];
  }

  /* End of Sum: '<S257>/Sum' */

  /* Outputs for Enabled SubSystem: '<S283>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S313>/Enable'
   */
  if (rtb_Compare_p) {
    localDW->MeasurementUpdate_MODE_h = true;

    /* Sum: '<S313>/Sum' incorporates:
     *  Constant: '<S261>/C'
     *  Constant: '<S261>/D'
     *  Delay: '<S261>/MemoryX'
     *  Gain: '<S257>/invertzaxisGain'
     *  Product: '<S313>/C[k]*xhat[k|k-1]'
     *  Product: '<S313>/D[k]*u[k]'
     *  Sum: '<S313>/Add1'
     */
    localB->u_h = -(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude -
      ((0.0 * localDW->MemoryX_DSTATE[1] + localDW->MemoryX_DSTATE[0]) + 0.0 *
       localB->Product1[2]);

    /* Product: '<S313>/Product3' */
    localB->Product3[0] = 0.026590304322229058 * localB->u_h;
    localB->Product3[1] = 0.06977673607149236 * localB->u_h;
  } else if (localDW->MeasurementUpdate_MODE_h) {
    /* Disable for Product: '<S313>/Product3' incorporates:
     *  Outport: '<S313>/L*(y[k]-yhat[k|k-1])'
     */
    localB->Product3[0] = 0.0;
    localB->Product3[1] = 0.0;
    localDW->MeasurementUpdate_MODE_h = false;
  }

  /* End of Outputs for SubSystem: '<S283>/MeasurementUpdate' */

  /* DataTypeConversion: '<S424>/Conversion' */
  localB->Saturation[0] = 0.00118709437F;
  localB->Saturation[1] = -3.28681635E-5F;

  /* Outputs for Enabled SubSystem: '<S401>/MeasurementUpdate' */
  /* DataTypeConversion: '<S381>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S381>/C'
   *  Constant: '<S381>/D'
   */
  flightControlSystem_MeasurementUpdate(rtb_LogicalOperator != 0,
    localB->Saturation, localB->TrigonometricFunction, rtCP_C_Value_i,
    localB->MemoryX_g, 0.0F, localB->p, &localB->MeasurementUpdate_j,
    &localDW->MeasurementUpdate_j);

  /* End of Outputs for SubSystem: '<S401>/MeasurementUpdate' */

  /* DataTypeConversion: '<S370>/Conversion' */
  localB->MemoryX_g[0] = 0.00118709437F;
  localB->MemoryX_g[1] = -3.28681635E-5F;

  /* Outputs for Enabled SubSystem: '<S347>/MeasurementUpdate' */
  /* DataTypeConversion: '<S327>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S327>/C'
   *  Constant: '<S327>/D'
   */
  flightControlSystem_MeasurementUpdate(rtb_LogicalOperator != 0,
    localB->MemoryX_g, localB->TrigonometricFunction1, rtCP_C_Value_h,
    localB->MemoryX_e, 0.0F, localB->q, &localB->MeasurementUpdate_n,
    &localDW->MeasurementUpdate_n);

  /* End of Outputs for SubSystem: '<S347>/MeasurementUpdate' */

  /* DeadZone: '<S93>/DeadZone' incorporates:
   *  Gain: '<S91>/ZeroGain'
   */
  if (localB->rtb_Integrator_idx_0 > 0.02F) {
    localB->TrigonometricFunction1 = localB->rtb_Integrator_idx_0 - 0.02F;
  } else if (localB->rtb_Integrator_idx_0 >= -0.02F) {
    localB->TrigonometricFunction1 = 0.0F;
  } else {
    localB->TrigonometricFunction1 = localB->rtb_Integrator_idx_0 - -0.02F;
  }

  /* Gain: '<S97>/Integral Gain' */
  rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 *= 0.006F;

  /* Gain: '<S193>/ZeroGain' */
  localB->MemoryX_g[0] = 0.0F * localB->Conversion[0];

  /* DeadZone: '<S195>/DeadZone' incorporates:
   *  Gain: '<S193>/ZeroGain'
   */
  if (localB->Conversion[0] > 0.34906584F) {
    u0 = localB->Conversion[0] - 0.34906584F;
    localB->Conversion[0] -= 0.34906584F;
  } else {
    if (localB->Conversion[0] >= -0.34906584F) {
      u0 = 0.0F;
    } else {
      u0 = localB->Conversion[0] - -0.34906584F;
    }

    if (localB->Conversion[0] >= -0.34906584F) {
      localB->Conversion[0] = 0.0F;
    } else {
      localB->Conversion[0] -= -0.34906584F;
    }
  }

  /* Gain: '<S199>/Integral Gain' */
  rtb_SaturationThrust1_tmp = 0.1F * localB->angularvelocitycompensation[0];
  localB->angularvelocitycompensation[0] *= 0.1F;

  /* DeadZone: '<S93>/DeadZone' */
  if (localB->rtb_MathFunction_idx_1 > 0.02F) {
    localB->TrigonometricFunction = localB->rtb_MathFunction_idx_1 - 0.02F;
  } else if (localB->rtb_MathFunction_idx_1 >= -0.02F) {
    localB->TrigonometricFunction = 0.0F;
  } else {
    localB->TrigonometricFunction = localB->rtb_MathFunction_idx_1 - -0.02F;
  }

  /* Gain: '<S97>/Integral Gain' */
  localB->SaturationThrust1 = 0.00486F *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_0;

  /* DeadZone: '<S195>/DeadZone' */
  if (localB->rtb_Switch_m_idx_1 > 0.34906584F) {
    localB->Conversion[1] = localB->rtb_Switch_m_idx_1 - 0.34906584F;
  } else if (localB->rtb_Switch_m_idx_1 >= -0.34906584F) {
    localB->Conversion[1] = 0.0F;
  } else {
    localB->Conversion[1] = localB->rtb_Switch_m_idx_1 - -0.34906584F;
  }

  /* Gain: '<S199>/Integral Gain' */
  localB->angularvelocitycompensation[1] = 0.1F * localB->rtb_Switch_m_idx_0;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/ '
   *  Constant: '<S4>/    '
   *  RelationalOperator: '<S4>/GreaterThan'
   *  Sum: '<S4>/Difference between  sonar and pressure'
   *  Switch: '<S4>/         '
   *  UnitDelay: '<S227>/Output'
   */
  if (localDW->Output_DSTATE_g > 600U) {
    localB->u_h = rtu_Sensors->VisionSensors.opticalFlow_data[2];
    localB->flag_hover = rtu_Sensors->VisionSensors.opticalFlow_data[2];
    localB->pressureFilter_IIR = localB->altfrompress -
      localB->pressureFilter_IIR;
  } else {
    localB->u_h = 0.0;
    localB->flag_hover = 0.0;
    localB->pressureFilter_IIR = 0.0F;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S220>/Constant'
   *  DataTypeConversion: '<S4>/   '
   *  Delay: '<S4>/Delay One Step'
   *  Product: '<S4>/  '
   *  RelationalOperator: '<S220>/Compare'
   */
  localB->u_h = (real_T)(localB->flag_hover == -1.0) *
    localDW->DelayOneStep_DSTATE + (real_T)(localB->u_h == -1.0);

  /* If: '<S4>/If' incorporates:
   *  Abs: '<S4>/Abs'
   *  Abs: '<S4>/Abs  '
   *  Abs: '<S4>/Abs1'
   *  Abs: '<S4>/Abs2'
   *  Abs: '<S4>/Abs3'
   *  Abs: '<S4>/Abs4'
   *  Abs: '<S4>/Abs5'
   *  Constant: '<S219>/Constant'
   *  Constant: '<S221>/Constant'
   *  Constant: '<S222>/Constant'
   *  Constant: '<S223>/Constant'
   *  Constant: '<S224>/Constant'
   *  Constant: '<S225>/Constant'
   *  Constant: '<S226>/Constant'
   *  Constant: '<S4>/0.5 meters'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S4>/Logical Operator3'
   *  RelationalOperator: '<S219>/Compare'
   *  RelationalOperator: '<S221>/Compare'
   *  RelationalOperator: '<S222>/Compare'
   *  RelationalOperator: '<S223>/Compare'
   *  RelationalOperator: '<S224>/Compare'
   *  RelationalOperator: '<S225>/Compare'
   *  RelationalOperator: '<S226>/Compare'
   *  RelationalOperator: '<S4>/GreaterThan  '
   *  Sum: '<S4>/Subtract'
   *  Sum: '<S4>/Subtract1'
   */
  if (((real32_T)fabs(localB->SimplyIntegrateVelocity[0]) > 10.0F) || ((real32_T)
       fabs(localB->SimplyIntegrateVelocity[1]) > 10.0F)) {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S228>/Action Port'
     */
    /* Merge: '<S4>/Merge' incorporates:
     *  Constant: '<S228>/Constant'
     *  SignalConversion generated from: '<S228>/Out1'
     */
    localB->Merge = 1U;

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */
  } else if ((((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]) >
               0.01F) && ((real32_T)fabs
                          (rtu_Sensors->VisionSensors.opticalFlow_data[0] -
                localB->Add_o[0]) > 6.0F)) || (((real32_T)fabs
               (rtu_Sensors->VisionSensors.opticalFlow_data[1] - localB->Add_o[1])
    > 6.0F) && ((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[1]) >
                0.01F))) {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S232>/Action Port'
     */
    /* Merge: '<S4>/Merge' incorporates:
     *  Constant: '<S232>/Constant'
     *  SignalConversion generated from: '<S232>/Out1'
     */
    localB->Merge = 99U;

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else if (localB->u_h > 50.0) {
    /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
     *  ActionPort: '<S229>/Action Port'
     */
    flightControlSystem_Noopticalflow(&localB->Merge);

    /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
  } else if ((real32_T)fabs(localB->pressureFilter_IIR) > 0.5F) {
    /* Outputs for IfAction SubSystem: '<S4>/Ultrasound improper' incorporates:
     *  ActionPort: '<S231>/Action Port'
     */
    flightControlSystem_Noopticalflow(&localB->Merge);

    /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/Normal condition' incorporates:
     *  ActionPort: '<S230>/Action Port'
     */
    flightControlSystem_Noopticalflow(&localB->Merge);

    /* End of Outputs for SubSystem: '<S4>/Normal condition' */
  }

  /* End of If: '<S4>/If' */
  /* SignalConversion generated from: '<S443>/Product' */
  localB->altfrompress = localB->Add_o[0];
  localB->pressureFilter_IIR = localB->Add_o[1];

  /* Product: '<S443>/Product' incorporates:
   *  Math: '<S443>/Math Function'
   *  SignalConversion generated from: '<S443>/Product'
   */
  for (localB->i_k = 0; localB->i_k < 3; localB->i_k++) {
    localB->FIR_IMUaccel[localB->i_k] = localB->MathFunction_a[localB->i_k + 6] *
      localB->Gain_m + (localB->MathFunction_a[localB->i_k + 3] *
                        localB->pressureFilter_IIR + localB->
                        MathFunction_a[localB->i_k] * localB->altfrompress);
  }

  /* End of Product: '<S443>/Product' */

  /* Update for DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  localDW->SimplyIntegrateVelocity_PrevResetState = 1;

  /* Update for Delay: '<S257>/Delay2' */
  localDW->Delay2_DSTATE = localB->rtb_Add_idx_0;

  /* Update for Delay: '<S261>/MemoryX' */
  localDW->icLoad = false;

  /* Update for DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] += 0.005F * localB->FIR_IMUaccel[0];

  /* Product: '<S283>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S261>/A'
   *  Delay: '<S261>/MemoryX'
   */
  localB->rtb_Add_idx_0 = 0.005 * localDW->MemoryX_DSTATE[1] +
    localDW->MemoryX_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[1] += 0.005F * localB->FIR_IMUaccel[1];

  /* Product: '<S283>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S261>/A'
   *  Delay: '<S261>/MemoryX'
   */
  localB->flag_hover = 0.0 * localDW->MemoryX_DSTATE[0] +
    localDW->MemoryX_DSTATE[1];

  /* Update for Delay: '<S261>/MemoryX' incorporates:
   *  Constant: '<S261>/B'
   *  Product: '<S283>/B[k]*u[k]'
   *  Product: '<S313>/Product3'
   *  Sum: '<S283>/Add'
   */
  localDW->MemoryX_DSTATE[0] = (0.0 * localB->Product1[2] +
    localB->rtb_Add_idx_0) + localB->Product3[0];

  /* Update for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = localDW->pressureFilter_IIR_states[1];

  /* Update for Delay: '<S261>/MemoryX' incorporates:
   *  Constant: '<S261>/B'
   *  Product: '<S283>/B[k]*u[k]'
   *  Product: '<S313>/Product3'
   *  Sum: '<S283>/Add'
   */
  localDW->MemoryX_DSTATE[1] = (0.005 * localB->Product1[2] + localB->flag_hover)
    + localB->Product3[1];

  /* Update for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = localDW->pressureFilter_IIR_states[0];
  localDW->pressureFilter_IIR_states[0] = localDW->pressureFilter_IIR_tmp;

  /* Update for DiscreteFilter: '<S262>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = localDW->sonarFilter_IIR_states[1];
  localDW->sonarFilter_IIR_states[1] = localDW->sonarFilter_IIR_states[0];
  localDW->sonarFilter_IIR_states[0] = localDW->sonarFilter_IIR_tmp;

  /* Update for DiscreteIntegrator: '<S325>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE += 0.005F * localB->r;

  /* Update for Delay: '<S327>/MemoryX' */
  localDW->icLoad_p = false;

  /* Product: '<S347>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S327>/A'
   *  Delay: '<S327>/MemoryX'
   */
  rtb_MathFunction_g_tmp = -0.005F * localDW->MemoryX_DSTATE_g[1] +
    localDW->MemoryX_DSTATE_g[0];
  rtb_MathFunction_g_tmp_1 = 0.0F * localDW->MemoryX_DSTATE_g[0] +
    localDW->MemoryX_DSTATE_g[1];

  /* Update for Delay: '<S327>/MemoryX' incorporates:
   *  Constant: '<S327>/B'
   *  Product: '<S347>/B[k]*u[k]'
   *  Product: '<S378>/Product3'
   *  Sum: '<S347>/Add'
   */
  localDW->MemoryX_DSTATE_g[0] = (0.005F * localB->q + rtb_MathFunction_g_tmp) +
    localB->MeasurementUpdate_n.Product3[0];
  localDW->MemoryX_DSTATE_g[1] = (0.0F * localB->q + rtb_MathFunction_g_tmp_1) +
    localB->MeasurementUpdate_n.Product3[1];

  /* Update for DiscreteFir: '<S259>/FIR_IMUaccel' */
  /* Update circular buffer index */
  localDW->FIR_IMUaccel_circBuf--;
  if (localDW->FIR_IMUaccel_circBuf < 0) {
    localDW->FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf] =
    localB->inverseIMU_gain[0];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 5] =
    localB->inverseIMU_gain[1];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 10] =
    localB->inverseIMU_gain[2];

  /* End of Update for DiscreteFir: '<S259>/FIR_IMUaccel' */

  /* Update for Delay: '<S381>/MemoryX' */
  localDW->icLoad_k = false;

  /* Product: '<S401>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S381>/A'
   *  Delay: '<S381>/MemoryX'
   */
  rtb_MathFunction_g_tmp = -0.005F * localDW->MemoryX_DSTATE_m[1] +
    localDW->MemoryX_DSTATE_m[0];
  rtb_MathFunction_g_tmp_1 = 0.0F * localDW->MemoryX_DSTATE_m[0] +
    localDW->MemoryX_DSTATE_m[1];

  /* Update for Delay: '<S381>/MemoryX' incorporates:
   *  Constant: '<S381>/B'
   *  Product: '<S401>/B[k]*u[k]'
   *  Product: '<S432>/Product3'
   *  Sum: '<S401>/Add'
   */
  localDW->MemoryX_DSTATE_m[0] = (0.005F * localB->p + rtb_MathFunction_g_tmp) +
    localB->MeasurementUpdate_j.Product3[0];
  localDW->MemoryX_DSTATE_m[1] = (0.0F * localB->p + rtb_MathFunction_g_tmp_1) +
    localB->MeasurementUpdate_j.Product3[1];

  /* Update for DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localDW->LPFFcutoff40Hz1_tmp;

  /* Update for DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz' */
  localDW->LPFFcutoff40Hz_states = localDW->LPFFcutoff40Hz_tmp;

  /* Update for DiscreteFilter: '<S259>/IIR_IMUgyro_r' */
  localDW->IIR_IMUgyro_r_states[4] = localDW->IIR_IMUgyro_r_states[3];
  localDW->IIR_IMUgyro_r_states[3] = localDW->IIR_IMUgyro_r_states[2];
  localDW->IIR_IMUgyro_r_states[2] = localDW->IIR_IMUgyro_r_states[1];
  localDW->IIR_IMUgyro_r_states[1] = localDW->IIR_IMUgyro_r_states[0];
  localDW->IIR_IMUgyro_r_states[0] = localDW->IIR_IMUgyro_r_tmp;

  /* Update for UnitDelay: '<S438>/Output' incorporates:
   *  Constant: '<S440>/FixPt Constant'
   *  Sum: '<S440>/FixPt Sum1'
   */
  localDW->Output_DSTATE++;

  /* Update for Delay: '<S447>/MemoryX' */
  localDW->icLoad_o = false;
  for (localB->i_k = 0; localB->i_k < 4; localB->i_k++) {
    /* Product: '<S485>/B[k]*u[k]' incorporates:
     *  Constant: '<S447>/B'
     */
    localB->fv[localB->i_k] = rtCP_B_Value_f[localB->i_k + 4] *
      localB->rtb_Product_idx_1 + rtCP_B_Value_f[localB->i_k] *
      localB->rtb_Product_idx_0;

    /* Product: '<S485>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S447>/A'
     *  Delay: '<S447>/MemoryX'
     */
    localB->fv1[localB->i_k] = rtCP_A_Value_a[localB->i_k + 12] *
      localDW->MemoryX_DSTATE_l[3] + (rtCP_A_Value_a[localB->i_k + 8] *
      localDW->MemoryX_DSTATE_l[2] + (rtCP_A_Value_a[localB->i_k + 4] *
      localDW->MemoryX_DSTATE_l[1] + rtCP_A_Value_a[localB->i_k] *
      localDW->MemoryX_DSTATE_l[0]));
  }

  /* Update for Delay: '<S447>/MemoryX' incorporates:
   *  Sum: '<S485>/Add'
   */
  localDW->MemoryX_DSTATE_l[0] = (localB->fv[0] + localB->fv1[0]) +
    localB->Product3_a[0];
  localDW->MemoryX_DSTATE_l[1] = (localB->fv[1] + localB->fv1[1]) +
    localB->Product3_a[1];
  localDW->MemoryX_DSTATE_l[2] = (localB->fv[2] + localB->fv1[2]) +
    localB->Product3_a[2];
  localDW->MemoryX_DSTATE_l[3] = (localB->fv[3] + localB->fv1[3]) +
    localB->Product3_a[3];

  /* Update for UnitDelay: '<S520>/Output' incorporates:
   *  Constant: '<S521>/FixPt Constant'
   *  Sum: '<S521>/FixPt Sum1'
   */
  localDW->Output_DSTATE_n++;
  for (localB->cff = 0; localB->cff < 2; localB->cff++) {
    /* Update for Delay: '<S442>/Delay' */
    localB->r = localB->Add_o[localB->cff];

    /* Update for DiscreteFilter: '<S446>/IIRgyroz' */
    localB->i = localB->cff * 5;
    localDW->IIRgyroz_states[localB->i + 4] = localDW->IIRgyroz_states[localB->i
      + 3];
    localDW->IIRgyroz_states[localB->i + 3] = localDW->IIRgyroz_states[localB->i
      + 2];
    localDW->IIRgyroz_states[localB->i + 2] = localDW->IIRgyroz_states[localB->i
      + 1];
    localDW->IIRgyroz_states[localB->i + 1] = localDW->IIRgyroz_states[localB->i];
    localDW->IIRgyroz_states[localB->i] = localDW->IIRgyroz_tmp[localB->cff];

    /* Update for UnitDelay: '<S454>/UD' */
    localDW->UD_DSTATE_k[localB->cff] =
      localB->TmpSignalConversionAtIIRgyrozInport1[localB->cff];

    /* Update for Delay: '<S442>/Delay' */
    localDW->Delay_DSTATE_a[localB->cff] = localB->r;

    /* Update for Delay: '<S6>/Delay1' */
    localDW->Delay1_DSTATE_p[localB->cff] = localB->r;
  }

  /* Update for UnitDelay: '<S14>/Output' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  Sum: '<S15>/FixPt Sum1'
   */
  localDW->Output_DSTATE_h++;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S7>/I_pr'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_d += 0.24F * localB->pitchrollerror *
    0.005F;
  if (localDW->DiscreteTimeIntegrator_DSTATE_d >= 2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_d = 2.0F;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE_d <= -2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_d = -2.0F;
  }

  localDW->DiscreteTimeIntegrator_PrevResetState = (int8_T)rtb_Compare_o;

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

  /* Update for Delay: '<S244>/Delay6' */
  localDW->Delay6_DSTATE = localB->sf_derivativeerror.dev_contribute;

  /* Update for UnitDelay: '<S246>/UD' incorporates:
   *  SampleTimeMath: '<S246>/TSamp'
   *
   * About '<S246>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  localDW->UD_DSTATE = localB->x_error;

  /* Update for Delay: '<S244>/Delay' */
  localDW->Delay_DSTATE = localB->sf_derivativeerror.count;

  /* Update for Delay: '<S244>/Delay5' */
  localDW->Delay5_DSTATE = localB->sf_derivativeerror.flag_count;

  /* Update for Delay: '<S241>/Delay1' incorporates:
   *  MATLAB Function: '<S241>/MATLAB Function'
   */
  localDW->Delay1_DSTATE[0] = localDW->Delay1_DSTATE[1];
  localDW->Delay1_DSTATE[1] = localDW->Delay1_DSTATE[2];
  localDW->Delay1_DSTATE[2] = localDW->Delay1_DSTATE[3];
  localDW->Delay1_DSTATE[3] = localB->Diff;

  /* Update for Delay: '<S250>/Delay6' */
  localDW->Delay6_DSTATE_o = localB->sf_derivativeerror_c.dev_contribute;

  /* Update for UnitDelay: '<S252>/UD' incorporates:
   *  SampleTimeMath: '<S252>/TSamp'
   *
   * About '<S252>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   */
  localDW->UD_DSTATE_i = localB->y_error;

  /* Update for Delay: '<S250>/Delay' */
  localDW->Delay_DSTATE_d = localB->sf_derivativeerror_c.count;

  /* Update for Delay: '<S250>/Delay5' */
  localDW->Delay5_DSTATE_h = localB->sf_derivativeerror_c.flag_count;

  /* Signum: '<S193>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  RelationalOperator: '<S193>/NotEqual'
   */
  if (localB->Conversion[0] < 0.0F) {
    localB->r = -1.0F;
  } else if (localB->Conversion[0] > 0.0F) {
    localB->r = 1.0F;
  } else if (localB->Conversion[0] == 0.0F) {
    localB->r = 0.0F;
  } else {
    localB->r = (rtNaNF);
  }

  /* Signum: '<S193>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   */
  if (localB->angularvelocitycompensation[0] < 0.0F) {
    localB->p = -1.0F;
  } else if (localB->angularvelocitycompensation[0] > 0.0F) {
    localB->p = 1.0F;
  } else if (localB->angularvelocitycompensation[0] == 0.0F) {
    localB->p = 0.0F;
  } else {
    localB->p = (rtNaNF);
  }

  /* Switch: '<S193>/Switch' incorporates:
   *  Constant: '<S193>/Constant1'
   *  DataTypeConversion: '<S193>/DataTypeConv1'
   *  DataTypeConversion: '<S193>/DataTypeConv2'
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  Logic: '<S193>/AND3'
   *  RelationalOperator: '<S193>/Equal1'
   *  RelationalOperator: '<S193>/NotEqual'
   */
  if ((localB->MemoryX_g[0] != u0) && ((int8_T)localB->r == (int8_T)localB->p))
  {
    rtb_SaturationThrust1_tmp = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S202>/Integrator' */
  localDW->Integrator_DSTATE[0] += 0.005F * rtb_SaturationThrust1_tmp;

  /* Update for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_g[0];

  /* Signum: '<S91>/SignPreSat' */
  if (localB->TrigonometricFunction1 < 0.0F) {
    localB->r = -1.0F;
  } else if (localB->TrigonometricFunction1 > 0.0F) {
    localB->r = 1.0F;
  } else if (localB->TrigonometricFunction1 == 0.0F) {
    localB->r = 0.0F;
  } else {
    localB->r = (rtNaNF);
  }

  /* Signum: '<S91>/SignPreIntegrator' */
  if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 < 0.0F) {
    localB->p = -1.0F;
  } else if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 >
             0.0F) {
    localB->p = 1.0F;
  } else if (rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 ==
             0.0F) {
    localB->p = 0.0F;
  } else {
    localB->p = (rtNaNF);
  }

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Constant1'
   *  DataTypeConversion: '<S91>/DataTypeConv1'
   *  DataTypeConversion: '<S91>/DataTypeConv2'
   *  Gain: '<S91>/ZeroGain'
   *  Logic: '<S91>/AND3'
   *  RelationalOperator: '<S91>/Equal1'
   *  RelationalOperator: '<S91>/NotEqual'
   */
  if ((0.0F * localB->rtb_Integrator_idx_0 != localB->TrigonometricFunction1) &&
      ((int8_T)localB->r == (int8_T)localB->p)) {
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1 = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_n[0] += 0.005F *
    rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_1;

  /* Update for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[0] += 0.005F * localB->rtb_Filter_idx_0;

  /* DeadZone: '<S195>/DeadZone' */
  if (localB->rtb_Switch_m_idx_1 > 0.34906584F) {
    u0 = localB->rtb_Switch_m_idx_1 - 0.34906584F;
  } else if (localB->rtb_Switch_m_idx_1 >= -0.34906584F) {
    u0 = 0.0F;
  } else {
    u0 = localB->rtb_Switch_m_idx_1 - -0.34906584F;
  }

  /* Signum: '<S193>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  RelationalOperator: '<S193>/NotEqual'
   */
  if (localB->Conversion[1] < 0.0F) {
    localB->r = -1.0F;
  } else if (localB->Conversion[1] > 0.0F) {
    localB->r = 1.0F;
  } else if (localB->Conversion[1] == 0.0F) {
    localB->r = 0.0F;
  } else {
    localB->r = (rtNaNF);
  }

  /* Signum: '<S193>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   */
  if (localB->angularvelocitycompensation[1] < 0.0F) {
    rtb_SaturationThrust1_tmp = -1.0F;
  } else if (localB->angularvelocitycompensation[1] > 0.0F) {
    rtb_SaturationThrust1_tmp = 1.0F;
  } else if (localB->angularvelocitycompensation[1] == 0.0F) {
    rtb_SaturationThrust1_tmp = 0.0F;
  } else {
    rtb_SaturationThrust1_tmp = (rtNaNF);
  }

  /* Switch: '<S193>/Switch' incorporates:
   *  Constant: '<S193>/Constant1'
   *  DataTypeConversion: '<S193>/DataTypeConv1'
   *  DataTypeConversion: '<S193>/DataTypeConv2'
   *  Gain: '<S193>/ZeroGain'
   *  Gain: '<S199>/Integral Gain'
   *  Logic: '<S193>/AND3'
   *  RelationalOperator: '<S193>/Equal1'
   *  RelationalOperator: '<S193>/NotEqual'
   */
  if ((0.0F * localB->rtb_Switch_m_idx_1 != u0) && ((int8_T)localB->r == (int8_T)
       rtb_SaturationThrust1_tmp)) {
    localB->rtb_Filter_idx_0 = 0.0F;
  } else {
    localB->rtb_Filter_idx_0 = 0.1F * localB->rtb_Switch_m_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S202>/Integrator' */
  localDW->Integrator_DSTATE[1] += 0.005F * localB->rtb_Filter_idx_0;

  /* Update for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_g[1];

  /* Signum: '<S91>/SignPreSat' */
  if (localB->TrigonometricFunction < 0.0F) {
    localB->TrigonometricFunction1 = -1.0F;
  } else if (localB->TrigonometricFunction > 0.0F) {
    localB->TrigonometricFunction1 = 1.0F;
  } else if (localB->TrigonometricFunction == 0.0F) {
    localB->TrigonometricFunction1 = 0.0F;
  } else {
    localB->TrigonometricFunction1 = (rtNaNF);
  }

  /* Signum: '<S91>/SignPreIntegrator' */
  if (localB->SaturationThrust1 < 0.0F) {
    localB->p = -1.0F;
  } else if (localB->SaturationThrust1 > 0.0F) {
    localB->p = 1.0F;
  } else if (localB->SaturationThrust1 == 0.0F) {
    localB->p = 0.0F;
  } else {
    localB->p = (rtNaNF);
  }

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Constant1'
   *  DataTypeConversion: '<S91>/DataTypeConv1'
   *  DataTypeConversion: '<S91>/DataTypeConv2'
   *  Gain: '<S91>/ZeroGain'
   *  Logic: '<S91>/AND3'
   *  RelationalOperator: '<S91>/Equal1'
   *  RelationalOperator: '<S91>/NotEqual'
   */
  if ((0.0F * localB->rtb_MathFunction_idx_1 != localB->TrigonometricFunction) &&
      ((int8_T)localB->TrigonometricFunction1 == (int8_T)localB->p)) {
    localB->SaturationThrust1 = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_n[1] += 0.005F * localB->SaturationThrust1;

  /* Update for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[1] += 0.005F * localB->rtb_MathFunction_idx_0;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S11>/I_yaw'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_p += 0.002F * localB->Saturation_j *
    0.005F;

  /* Update for UnitDelay: '<S227>/Output' incorporates:
   *  Constant: '<S233>/FixPt Constant'
   *  Sum: '<S233>/FixPt Sum1'
   */
  localDW->Output_DSTATE_g++;

  /* Update for Delay: '<S4>/Delay One Step' */
  localDW->DelayOneStep_DSTATE = localB->u_h;
}

static void flightControlSystem_SystemCore_step(const uint8_T varargin_1[38400],
  uint8_T varargout_1[19200], uint8_T varargout_2[19200], uint8_T varargout_3
  [19200])
{
  MW_Build_RGB(&varargin_1[0], &varargout_1[0], &varargout_2[0], &varargout_3[0]);
}

/* System initialize for referenced model: 'flightControlSystem' */
void flightControlSystem_Init(void)
{
  int32_T i;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  for (i = 0; i < 6; i++) {
    flightControlSystem_DW.RateTransition_Buffer[i] = 0.0;
  }

  flightControlSystem_DW.RateTransition_ActiveBufIdx = 0;

  /* End of InitializeConditions for RateTransition: '<Root>/Rate Transition' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Init(&flightControlSystem_B.ControlSystem,
    &flightControlSystem_DW.ControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Control System' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Image Processing System' */
  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightControlSystem_DW.Delay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  flightControlSystem_DW.Delay1_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S2>/Delay2' */
  flightControlSystem_DW.Delay2_DSTATE = false;

  /* SystemInitialize for MATLAB Function: '<S2>/Red Marker Detection' */
  flightControlSystem_DW.column_accumulator = 0.0;
  flightControlSystem_DW.count_pixel = 0.0;
  flightControlSystem_DW.row_accumulator = 0.0;

  /* SystemInitialize for MATLAB Function: '<S2>/Waypoints' */
  flightControlSystem_DW.x_accumulator = 0.0;
  flightControlSystem_DW.y_accumulator = 0.0;
  flightControlSystem_DW.pixel_count = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Image Processing System' */

  /* SystemInitialize for SignalConversion generated from: '<Root>/Control System' */
  flag_outport = flightControlSystem_B.ControlSystem.Merge;
}

/* System reset for referenced model: 'flightControlSystem' */
void flightControlSystem_Reset(void)
{
  int32_T i;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  for (i = 0; i < 6; i++) {
    flightControlSystem_DW.RateTransition_Buffer[i] = 0.0;
  }

  flightControlSystem_DW.RateTransition_ActiveBufIdx = 0;

  /* End of InitializeConditions for RateTransition: '<Root>/Rate Transition' */

  /* SystemReset for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Reset(&flightControlSystem_B.ControlSystem,
    &flightControlSystem_DW.ControlSystem);

  /* End of SystemReset for SubSystem: '<Root>/Control System' */

  /* SystemReset for Atomic SubSystem: '<Root>/Image Processing System' */
  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightControlSystem_DW.Delay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  flightControlSystem_DW.Delay1_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S2>/Delay2' */
  flightControlSystem_DW.Delay2_DSTATE = false;

  /* SystemReset for MATLAB Function: '<S2>/Waypoints' */
  flightControlSystem_DW.x_accumulator = 0.0;
  flightControlSystem_DW.y_accumulator = 0.0;
  flightControlSystem_DW.pixel_count = 0.0;

  /* SystemReset for MATLAB Function: '<S2>/Red Marker Detection' */
  flightControlSystem_DW.column_accumulator = 0.0;
  flightControlSystem_DW.count_pixel = 0.0;
  flightControlSystem_DW.row_accumulator = 0.0;

  /* End of SystemReset for SubSystem: '<Root>/Image Processing System' */
}

/* Disable for referenced model: 'flightControlSystem' */
void flightControlSystem_Disable(void)
{
  /* Disable for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Disable(&flightControlSystem_B.ControlSystem,
    &flightControlSystem_DW.ControlSystem);

  /* End of Disable for SubSystem: '<Root>/Control System' */
}

/* Start for referenced model: 'flightControlSystem' */
void flightControlSystem_Start(void)
{
  int32_T curNumNonZ;
  int32_T idxNHood;
  int32_T idxOffsets;
  int32_T m;
  int32_T n;
  int32_T nhIdx;

  /* Start for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Start(&flightControlSystem_DW.ControlSystem);

  /* End of Start for SubSystem: '<Root>/Control System' */

  /* Start for Atomic SubSystem: '<Root>/Image Processing System' */
  /* Start for MATLABSystem: '<S2>/PARROT Image Conversion' */
  flightControlSystem_DW.objisempty = true;
  flightControlSystem_DW.obj.isInitialized = 1;

  /* Start for S-Function (svipmorphop): '<S2>/Erosion for landing mark' */
  idxNHood = 0;
  idxOffsets = 0;
  for (nhIdx = 0; nhIdx < 6; nhIdx++) {
    curNumNonZ = 0;
    for (n = 0; n < rtCP_Erosionforlandingmark_NHDIMS_RTP[nhIdx + 6]; n++) {
      for (m = 0; m < rtCP_Erosionforlandingmark_NHDIMS_RTP[nhIdx]; m++) {
        if (rtCP_Erosionforlandingmark_NHOOD_RTP[idxNHood]) {
          flightControlSystem_DW.Erosionforlandingmark_ERODE_OFF_DW[idxOffsets] =
            n * 145 + m;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[nhIdx] = curNumNonZ;
  }

  /* End of Start for S-Function (svipmorphop): '<S2>/Erosion for landing mark' */

  /* Start for S-Function (svipmorphop): '<S2>/Dilation' */
  idxNHood = 0;
  idxOffsets = 0;
  for (nhIdx = 0; nhIdx < 6; nhIdx++) {
    curNumNonZ = 0;
    for (n = 0; n < rtCP_Dilation_NHDIMS_RTP[nhIdx + 6]; n++) {
      for (m = 0; m < rtCP_Dilation_NHDIMS_RTP[nhIdx]; m++) {
        if (rtCP_Dilation_NHOOD_RTP[idxNHood]) {
          flightControlSystem_DW.Dilation_DILATE_OFF_DW[idxOffsets] = n * 151 +
            m;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    flightControlSystem_DW.Dilation_NUMNONZ_DW[nhIdx] = curNumNonZ;
  }

  /* End of Start for S-Function (svipmorphop): '<S2>/Dilation' */
  /* End of Start for SubSystem: '<Root>/Image Processing System' */
}

/* Output and update for referenced model: 'flightControlSystem' */
void flightControlSystemTID0(void)
{
  /* RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_B.i = flightControlSystem_DW.RateTransition_ActiveBufIdx *
    6;
  for (flightControlSystem_B.i1 = 0; flightControlSystem_B.i1 < 6;
       flightControlSystem_B.i1++) {
    /* RateTransition: '<Root>/Rate Transition' */
    flightControlSystem_B.RateTransition[flightControlSystem_B.i1] =
      flightControlSystem_DW.RateTransition_Buffer[flightControlSystem_B.i1 +
      flightControlSystem_B.i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Control System' */
  /* Inport: '<Root>/AC cmd ' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_ControlSystem(&cmd_inport, &sensor_inport,
    flightControlSystem_B.RateTransition, &flightControlSystem_B.ControlSystem,
    &flightControlSystem_DW.ControlSystem,
    &flightControlSystem_PrevZCX.ControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Control System' */

  /* SignalConversion generated from: '<Root>/Control System' */
  motors_outport[0] = flightControlSystem_B.ControlSystem.MotorDirections[0];
  motors_outport[1] = flightControlSystem_B.ControlSystem.MotorDirections[1];
  motors_outport[2] = flightControlSystem_B.ControlSystem.MotorDirections[2];
  motors_outport[3] = flightControlSystem_B.ControlSystem.MotorDirections[3];

  /* SignalConversion generated from: '<Root>/Control System' */
  flag_outport = flightControlSystem_B.ControlSystem.Merge;
}

/* Output and update for referenced model: 'flightControlSystem' */
void flightControlSystemTID1(void)
{
  real_T center_x;
  real_T center_y;
  int32_T bufIdx;
  int32_T i;
  int32_T ku;
  int32_T ky;
  int32_T m;
  int32_T outIdx;
  uint32_T qY;
  uint32_T qY_0;
  uint8_T b_varargout_2;
  boolean_T flag_error_x;
  boolean_T flag_error_y;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  flightControlSystem_SystemCore_step(imRGB, flightControlSystem_B.b_varargout_1,
    flightControlSystem_B.b_varargout_2, flightControlSystem_B.b_varargout_3);

  /* MATLAB Function: '<S2>/Image Binarization' incorporates:
   *  MATLABSystem: '<S2>/PARROT Image Conversion'
   */
  for (i = 0; i < 19200; i++) {
    b_varargout_2 = (uint8_T)(int32_T)rt_roundd_snf((real_T)
      flightControlSystem_B.b_varargout_3[i] / 2.0);
    ky = flightControlSystem_B.b_varargout_1[i];
    qY_0 = (uint32_T)ky - (uint8_T)(int32_T)rt_roundd_snf((real_T)
      flightControlSystem_B.b_varargout_2[i] / 2.0);
    if (qY_0 > (uint32_T)ky) {
      qY_0 = 0U;
    }

    qY = qY_0 - b_varargout_2;
    if (qY > qY_0) {
      qY = 0U;
    }

    flightControlSystem_B.binarized_frame[i] = ((int32_T)qY >= 80);
    flightControlSystem_B.b_varargout_2[i] = b_varargout_2;
  }

  /* End of MATLAB Function: '<S2>/Image Binarization' */

  /* S-Function (svipmorphop): '<S2>/Erosion for landing mark' */
  ky = 0;
  ku = 0;
  for (i = 0; i < 9; i++) {
    for (m = 0; m < 145; m++) {
      flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky] = true;
      ky++;
    }
  }

  for (i = 0; i < 160; i++) {
    for (m = 0; m < 9; m++) {
      flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky] = true;
      ky++;
    }

    memcpy(&flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky],
           &flightControlSystem_B.binarized_frame[ku], 120U * sizeof(boolean_T));
    ky += 120;
    ku += 120;
    for (m = 0; m < 16; m++) {
      flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky] = true;
      ky++;
    }
  }

  for (i = 0; i < 16; i++) {
    for (m = 0; m < 145; m++) {
      flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky] = true;
      ky++;
    }
  }

  for (i = 0; i < 26825; i++) {
    flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[i] = true;
  }

  bufIdx = 0;
  for (ky = 0; ky < 185; ky++) {
    for (m = 0; m < 139; m++) {
      flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[3 + bufIdx] =
        true;
      i = 0;
      while (i < flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[0]) {
        if (!flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[bufIdx
            + flightControlSystem_DW.Erosionforlandingmark_ERODE_OFF_DW[i]]) {
          flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[3 + bufIdx]
            = false;
          i = flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[0];
        }

        i++;
      }

      bufIdx++;
    }

    bufIdx += 6;
  }

  bufIdx = 0;
  for (ky = 0; ky < 181; ky++) {
    for (m = 0; m < 141; m++) {
      flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[292 + bufIdx] =
        true;
      i = 0;
      while (i < flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[1]) {
        if (!flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[flightControlSystem_DW.Erosionforlandingmark_ERODE_OFF_DW
            [i + flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[0]] +
            bufIdx]) {
          flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[292 +
            bufIdx] = false;
          i = flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[1];
        }

        i++;
      }

      bufIdx++;
    }

    bufIdx += 4;
  }

  ku = flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[0] +
    flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[1];
  bufIdx = 0;
  for (ky = 0; ky < 179; ky++) {
    for (m = 0; m < 145; m++) {
      flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[435 + bufIdx] =
        true;
      i = 0;
      while (i < flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[2]) {
        if (!flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[flightControlSystem_DW.Erosionforlandingmark_ERODE_OFF_DW
            [i + ku] + bufIdx]) {
          flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[435 +
            bufIdx] = false;
          i = flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[2];
        }

        i++;
      }

      bufIdx++;
    }
  }

  ku += flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[2];
  bufIdx = 0;
  for (ky = 0; ky < 181; ky++) {
    for (m = 0; m < 141; m++) {
      flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[292 + bufIdx] =
        true;
      i = 0;
      while (i < flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[3]) {
        if (!flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[flightControlSystem_DW.Erosionforlandingmark_ERODE_OFF_DW
            [i + ku] + bufIdx]) {
          flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[292 +
            bufIdx] = false;
          i = flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[3];
        }

        i++;
      }

      bufIdx++;
    }

    bufIdx += 4;
  }

  ku += flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[3];
  bufIdx = 0;
  for (ky = 0; ky < 181; ky++) {
    for (m = 0; m < 145; m++) {
      flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[290 + bufIdx] =
        true;
      i = 0;
      while (i < flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[4]) {
        if (!flightControlSystem_DW.Erosionforlandingmark_ONE_PAD_IMG_DW[flightControlSystem_DW.Erosionforlandingmark_ERODE_OFF_DW
            [i + ku] + bufIdx]) {
          flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[290 +
            bufIdx] = false;
          i = flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[4];
        }

        i++;
      }

      bufIdx++;
    }
  }

  ku += flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[4];
  bufIdx = 1312;
  outIdx = 0;
  for (ky = 9; ky < 169; ky++) {
    for (m = 7; m < 127; m++) {
      flightControlSystem_B.Erosionforlandingmark[outIdx] = true;
      i = 0;
      while (i < flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[5]) {
        if (!flightControlSystem_DW.Erosionforlandingmark_TWO_PAD_IMG_DW[flightControlSystem_DW.Erosionforlandingmark_ERODE_OFF_DW
            [i + ku] + bufIdx]) {
          flightControlSystem_B.Erosionforlandingmark[outIdx] = false;
          i = flightControlSystem_DW.Erosionforlandingmark_NUMNONZ_DW[5];
        }

        i++;
      }

      bufIdx++;
      outIdx++;
    }

    bufIdx += 25;
  }

  /* End of S-Function (svipmorphop): '<S2>/Erosion for landing mark' */

  /* S-Function (svipmorphop): '<S2>/Dilation' incorporates:
   *  S-Function (svipmorphop): '<S2>/Erosion for landing mark'
   */
  memset(&flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[0], 0, 28841U * sizeof
         (boolean_T));
  for (bufIdx = 0; bufIdx < 19200; bufIdx++) {
    if (flightControlSystem_B.Erosionforlandingmark[bufIdx]) {
      i = bufIdx / 120;
      outIdx = (bufIdx - i * 120) + i * 151;
      for (i = 0; i < flightControlSystem_DW.Dilation_NUMNONZ_DW[0]; i++) {
        flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[outIdx +
          flightControlSystem_DW.Dilation_DILATE_OFF_DW[i]] = true;
      }
    }
  }

  memset(&flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[0], 0, 28841U * sizeof
         (boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < flightControlSystem_DW.Dilation_NUMNONZ_DW[1]; i++) {
        flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[bufIdx +
          flightControlSystem_DW.Dilation_DILATE_OFF_DW[flightControlSystem_DW.Dilation_NUMNONZ_DW
          [0] + i]] = true;
      }
    }
  }

  ky = flightControlSystem_DW.Dilation_NUMNONZ_DW[0] +
    flightControlSystem_DW.Dilation_NUMNONZ_DW[1];
  memset(&flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[0], 0, 28841U * sizeof
         (boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < flightControlSystem_DW.Dilation_NUMNONZ_DW[2]; i++) {
        flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[bufIdx +
          flightControlSystem_DW.Dilation_DILATE_OFF_DW[ky + i]] = true;
      }
    }
  }

  ky += flightControlSystem_DW.Dilation_NUMNONZ_DW[2];
  memset(&flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[0], 0, 28841U * sizeof
         (boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < flightControlSystem_DW.Dilation_NUMNONZ_DW[3]; i++) {
        flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[bufIdx +
          flightControlSystem_DW.Dilation_DILATE_OFF_DW[ky + i]] = true;
      }
    }
  }

  ky += flightControlSystem_DW.Dilation_NUMNONZ_DW[3];
  memset(&flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[0], 0, 28841U * sizeof
         (boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < flightControlSystem_DW.Dilation_NUMNONZ_DW[4]; i++) {
        flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[bufIdx +
          flightControlSystem_DW.Dilation_DILATE_OFF_DW[ky + i]] = true;
      }
    }
  }

  ky += flightControlSystem_DW.Dilation_NUMNONZ_DW[4];
  memset(&flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[0], 0, 28841U * sizeof
         (boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (flightControlSystem_DW.Dilation_ONE_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < flightControlSystem_DW.Dilation_NUMNONZ_DW[5]; i++) {
        flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[bufIdx +
          flightControlSystem_DW.Dilation_DILATE_OFF_DW[ky + i]] = true;
      }
    }
  }

  ky = 0;
  ku = 0;
  for (i = 0; i < 6; i++) {
    ky += (rtCP_Dilation_NHDIMS_RTP[i] - 1) >> 1;
    ku += (rtCP_Dilation_NHDIMS_RTP[i + 6] - 1) >> 1;
  }

  bufIdx = ku * 151 + ky;
  outIdx = 0;
  for (ky = 0; ky < 160; ky++) {
    for (m = 0; m < 120; m++) {
      flightControlSystem_B.Dilation[outIdx] =
        flightControlSystem_DW.Dilation_TWO_PAD_IMG_DW[bufIdx];
      outIdx++;
      bufIdx++;
    }

    bufIdx += 31;
  }

  /* End of S-Function (svipmorphop): '<S2>/Dilation' */

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  S-Function (svipmorphop): '<S2>/Dilation'
   */
  for (i = 0; i < 19200; i++) {
    flightControlSystem_B.frame[i] = (int8_T)
      (flightControlSystem_B.binarized_frame[i] -
       flightControlSystem_B.Dilation[i]);
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* MATLAB Function: '<S2>/Waypoints' incorporates:
   *  Delay: '<S2>/Delay'
   *  Delay: '<S2>/Delay1'
   *  Delay: '<S2>/Delay2'
   */
  center_y = mod_nOBiMHsG(rt_atan2d_snf(-flightControlSystem_DW.Delay_DSTATE,
    flightControlSystem_DW.Delay1_DSTATE));
  if (flightControlSystem_DW.Delay2_DSTATE) {
    for (ky = 0; ky < 81; ky++) {
      for (m = 0; m < 81; m++) {
        flightControlSystem_B.b_norm = sqrt((((real_T)ky + 20.0) - 59.5) *
          (((real_T)ky + 20.0) - 59.5) + (((real_T)m + 40.0) - 79.5) * (((real_T)
          m + 40.0) - 79.5));
        if ((flightControlSystem_B.b_norm >= 30.0) &&
            (flightControlSystem_B.b_norm <= 40.0)) {
          flightControlSystem_B.b_norm = mod_nOBiMHsG(rt_atan2d_snf(((real_T)ky
            + 20.0) - 59.5, ((real_T)m + 40.0) - 79.5));
          flightControlSystem_B.y_ref_temp = mod_nOBiMHsG(center_y +
            1.0833078115826873);
          center_x = mod_nOBiMHsG(center_y - 1.0833078115826873);
          if (flightControlSystem_B.y_ref_temp < center_x) {
            flag_error_x = (((flightControlSystem_B.b_norm <= 6.2831853071795862)
                             && (flightControlSystem_B.b_norm >= center_x)) ||
                            ((flightControlSystem_B.b_norm <=
                              flightControlSystem_B.y_ref_temp) &&
                             (flightControlSystem_B.b_norm >= 0.0)));
          } else {
            flag_error_x = ((flightControlSystem_B.b_norm <=
                             flightControlSystem_B.y_ref_temp) &&
                            (flightControlSystem_B.b_norm >= center_x));
          }

          if (flag_error_x && (flightControlSystem_B.frame[(int32_T)(((real32_T)
                 ((real_T)m + 40.0) - 1.0F) * 120.0F + (real32_T)((real_T)ky +
                 20.0)) - 1] == 1)) {
            flightControlSystem_DW.pixel_count++;
            flightControlSystem_DW.x_accumulator += (real_T)ky + 20.0;
            flightControlSystem_DW.y_accumulator += (real_T)m + 40.0;
          }
        }
      }
    }
  } else {
    for (ku = 0; ku < 81; ku++) {
      for (m = 0; m < 81; m++) {
        flightControlSystem_B.b_norm = sqrt((((real_T)ku + 20.0) - 59.5) *
          (((real_T)ku + 20.0) - 59.5) + (((real_T)m + 40.0) - 79.5) * (((real_T)
          m + 40.0) - 79.5));
        if ((flightControlSystem_B.b_norm >= 30.0) &&
            (flightControlSystem_B.b_norm <= 40.0) &&
            (flightControlSystem_B.frame[(int32_T)(((real32_T)((real_T)m + 40.0)
               - 1.0F) * 120.0F + (real32_T)((real_T)ku + 20.0)) - 1] == 1)) {
          flightControlSystem_DW.pixel_count++;
          flightControlSystem_DW.x_accumulator += (real_T)ku + 20.0;
          flightControlSystem_DW.y_accumulator += (real_T)m + 40.0;
        }
      }
    }
  }

  flightControlSystem_B.b_norm = -(rt_roundd_snf
    (flightControlSystem_DW.x_accumulator / flightControlSystem_DW.pixel_count)
    - 60.0);
  flightControlSystem_B.y_ref_temp = rt_roundd_snf
    (flightControlSystem_DW.y_accumulator / flightControlSystem_DW.pixel_count)
    - 80.0;
  if (rtIsNaN(flightControlSystem_B.b_norm)) {
    flightControlSystem_B.b_norm = 0.0;
    flag_error_x = false;
  } else {
    flag_error_x = true;
  }

  if (rtIsNaN(flightControlSystem_B.y_ref_temp)) {
    flightControlSystem_B.y_ref_temp = 0.0;
    flag_error_y = false;
  } else {
    flag_error_y = true;
  }

  flightControlSystem_DW.pixel_count = 0.0;
  flightControlSystem_DW.x_accumulator = 0.0;
  flightControlSystem_DW.y_accumulator = 0.0;
  flag_error_x = (flag_error_x || flag_error_y);

  /* MATLAB Function: '<S2>/Red Marker Detection' incorporates:
   *  S-Function (svipmorphop): '<S2>/Erosion for landing mark'
   */
  for (i = 0; i < 120; i++) {
    for (m = 0; m < 160; m++) {
      if (flightControlSystem_B.Erosionforlandingmark[120 * m + i]) {
        flightControlSystem_DW.count_pixel++;
        flightControlSystem_DW.column_accumulator += (real_T)m + 1.0;
        flightControlSystem_DW.row_accumulator += (real_T)i + 1.0;
      }
    }
  }

  if (flightControlSystem_DW.count_pixel != 0.0) {
    i = 1;
    center_x = rt_roundd_snf(flightControlSystem_DW.row_accumulator /
      flightControlSystem_DW.count_pixel) - 5.0;
    center_y = rt_roundd_snf(flightControlSystem_DW.column_accumulator /
      flightControlSystem_DW.count_pixel);
  } else {
    i = 0;
    center_x = 60.0;
    center_y = 80.0;
  }

  flightControlSystem_DW.column_accumulator = 0.0;
  flightControlSystem_DW.row_accumulator = 0.0;
  flightControlSystem_DW.count_pixel = 0.0;

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  MATLAB Function: '<S2>/Waypoints'
   */
  flightControlSystem_DW.Delay_DSTATE = flightControlSystem_B.b_norm;

  /* Update for Delay: '<S2>/Delay1' incorporates:
   *  MATLAB Function: '<S2>/Waypoints'
   */
  flightControlSystem_DW.Delay1_DSTATE = flightControlSystem_B.y_ref_temp;

  /* Update for Delay: '<S2>/Delay2' */
  flightControlSystem_DW.Delay2_DSTATE = flag_error_x;

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  MATLAB Function: '<S2>/Red Marker Detection'
   *  MATLAB Function: '<S2>/Waypoints'
   */
  flightControlSystem_DW.RateTransition_Buffer
    [(flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] = -(center_x
    - 60.0);
  flightControlSystem_DW.RateTransition_Buffer[1 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] = center_y -
    80.0;
  flightControlSystem_DW.RateTransition_Buffer[2 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] = i;
  flightControlSystem_DW.RateTransition_Buffer[3 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] =
    flightControlSystem_B.b_norm;
  flightControlSystem_DW.RateTransition_Buffer[4 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] =
    flightControlSystem_B.y_ref_temp;
  flightControlSystem_DW.RateTransition_Buffer[5 +
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0) * 6] =
    flag_error_x;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  flightControlSystem_DW.RateTransition_ActiveBufIdx = (int8_T)
    (flightControlSystem_DW.RateTransition_ActiveBufIdx == 0);
}

/* Model initialize function */
void flightControlSystem_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_flightControlSystem_T *const flightControlSystem_M =
    &(flightControlSystem_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(flightControlSystem_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) &flightControlSystem_B), 0,
                sizeof(B_flightControlSystem_c_T));

  /* states (dwork) */
  (void) memset((void *)&flightControlSystem_DW, 0,
                sizeof(DW_flightControlSystem_f_T));
  flightControlSystem_PrevZCX.ControlSystem.TriggeredSubsystem_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
}
