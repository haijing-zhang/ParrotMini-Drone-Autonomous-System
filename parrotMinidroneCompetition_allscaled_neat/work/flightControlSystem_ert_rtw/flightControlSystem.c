/*
 * flightControlSystem.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 2.83
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sun Aug  8 14:05:04 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "flightControlSystem.h"

/* Named constants for Chart: '<S239>/Chart1' */
#define IN_END_MARKER_DETECTED         ((uint8_T)1U)
#define IN_LANDING                     ((uint8_T)2U)
#define IN_LEAVE_MARKER                ((uint8_T)3U)
#define IN_LINE_FOLLOWING              ((uint8_T)4U)
#define IN_TAKE_OFF                    ((uint8_T)5U)

/* Named constants for Chart: '<S239>/x_linear_contribute' */
#define IN_IDLE                        ((uint8_T)2U)
#define IN_TRACK_DETECTED              ((uint8_T)3U)

/* Named constants for Chart: '<S241>/Chart' */
#define IN_Grabbing                    ((uint8_T)1U)
#define IN_TAKE_OFF_p                  ((uint8_T)3U)
#define IN_TRACKING                    ((uint8_T)4U)

/* Named constants for Chart: '<S5>/circle count' */
#define IN_IDLE_h                      ((uint8_T)1U)
#define IN_LEAVE_MARKER_p              ((uint8_T)2U)
#define IN_MARKER_DETECTED             ((uint8_T)3U)
#define IN_TRACE_LANE                  ((uint8_T)4U)
#define NumBitsPerChar                 8U

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd ' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<Root>/Control System' */
uint8_T flag_outport;                  /* '<Root>/Control System' */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_roundd_snf(real_T u);
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
static void Noopticalflow(uint8_T *rty_Out1);
static void MATLABFunction(real_T rtu_derivative_error, real_T
  rtu_CHANGE_DERIVATIVE_ERROR_THRESHOLD, DW_MATLABFunction *localDW);
static void derivativeerror(real_T rtu_dev_contribute_prev, real_T
  rtu_derivative_error, real_T rtu_flag_change_error, real_T rtu_count_prev,
  real_T rtu_flag_count_prev, DW_derivativeerror *localDW);
static void MeasurementUpdate_Disable(DW_MeasurementUpdate *localDW);
static void MeasurementUpdate(boolean_T rtu_Enable, const real32_T rtu_Lk[2],
  real32_T rtu_yk, const real32_T rtu_Ck[2], const real32_T rtu_xhatkk1[2],
  real32_T rtu_Dk, real32_T rtu_uk, DW_MeasurementUpdate *localDW);
static void EnabledSubsystem_Disable(DW_EnabledSubsystem *localDW);
static void EnabledSubsystem(boolean_T rtu_Enable, const real32_T rtu_Mk[2],
  const real32_T rtu_Ck[2], real32_T rtu_yk, const real32_T rtu_xhatkk1[2],
  DW_EnabledSubsystem *localDW);
static void ControlSystem_Init(DW_ControlSystem *localDW);
static void ControlSystem(const CommandBus *rtu_ReferenceValueServerCmds, const
  SensorsBus *rtu_Sensors, const real_T rtu_VisionbasedData[6], DW_ControlSystem
  *localDW, ZCE_ControlSystem *localZCE);

/* Forward declaration for local functions */
static void SystemCore_step(const uint8_T varargin_1[38400], uint8_T
  varargout_1[19200], uint8_T varargout_2[19200], uint8_T varargout_3[19200]);
static real_T mod(real_T x);
static void rate_monotonic_scheduler(void);
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(rtM, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.2s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S4>/No optical flow '
 *    '<S4>/Ultrasound improper'
 *    '<S4>/Normal condition'
 */
static void Noopticalflow(uint8_T *rty_Out1)
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
static void MATLABFunction(real_T rtu_derivative_error, real_T
  rtu_CHANGE_DERIVATIVE_ERROR_THRESHOLD, DW_MATLABFunction *localDW)
{
  localDW->flag_change_error = (fabs(rtu_derivative_error) >=
    rtu_CHANGE_DERIVATIVE_ERROR_THRESHOLD);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S244>/derivative error'
 *    '<S250>/derivative error'
 */
static void derivativeerror(real_T rtu_dev_contribute_prev, real_T
  rtu_derivative_error, real_T rtu_flag_change_error, real_T rtu_count_prev,
  real_T rtu_flag_count_prev, DW_derivativeerror *localDW)
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
      localDW->count = 0.0;
      flag_count = 0;
    } else {
      localDW->count = rtu_count_prev + 1.0;
      flag_count = 1;
    }

    dev_contribute = rtu_derivative_error * 0.002;
    if ((dev_contribute == 0.0) && (rtu_dev_contribute_prev != 0.0)) {
      dev_contribute = rtu_dev_contribute_prev;
    }
  } else {
    localDW->count = 0.0;
    dev_contribute = 0.0;
  }

  localDW->dev_contribute = dev_contribute;
  localDW->flag_count = flag_count;
}

/*
 * Disable for enable system:
 *    '<S347>/MeasurementUpdate'
 *    '<S401>/MeasurementUpdate'
 */
static void MeasurementUpdate_Disable(DW_MeasurementUpdate *localDW)
{
  /* Disable for Product: '<S378>/Product3' incorporates:
   *  Outport: '<S378>/L*(y[k]-yhat[k|k-1])'
   */
  localDW->Product3[0] = 0.0F;
  localDW->Product3[1] = 0.0F;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S347>/MeasurementUpdate'
 *    '<S401>/MeasurementUpdate'
 */
static void MeasurementUpdate(boolean_T rtu_Enable, const real32_T rtu_Lk[2],
  real32_T rtu_yk, const real32_T rtu_Ck[2], const real32_T rtu_xhatkk1[2],
  real32_T rtu_Dk, real32_T rtu_uk, DW_MeasurementUpdate *localDW)
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
    localDW->Product3[0] = rtu_Lk[0] * rtb_Sum_l;
    localDW->Product3[1] = rtu_Lk[1] * rtb_Sum_l;
  } else if (localDW->MeasurementUpdate_MODE) {
    MeasurementUpdate_Disable(localDW);
  }

  /* End of Outputs for SubSystem: '<S347>/MeasurementUpdate' */
}

/*
 * Disable for enable system:
 *    '<S354>/Enabled Subsystem'
 *    '<S408>/Enabled Subsystem'
 */
static void EnabledSubsystem_Disable(DW_EnabledSubsystem *localDW)
{
  /* Disable for Product: '<S380>/Product2' incorporates:
   *  Outport: '<S380>/deltax'
   */
  localDW->Product2[0] = 0.0F;
  localDW->Product2[1] = 0.0F;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S354>/Enabled Subsystem'
 *    '<S408>/Enabled Subsystem'
 */
static void EnabledSubsystem(boolean_T rtu_Enable, const real32_T rtu_Mk[2],
  const real32_T rtu_Ck[2], real32_T rtu_yk, const real32_T rtu_xhatkk1[2],
  DW_EnabledSubsystem *localDW)
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
    localDW->Product2[0] = rtu_Mk[0] * rtb_Add1;
    localDW->Product2[1] = rtu_Mk[1] * rtb_Add1;
  } else if (localDW->EnabledSubsystem_MODE) {
    EnabledSubsystem_Disable(localDW);
  }

  /* End of Outputs for SubSystem: '<S354>/Enabled Subsystem' */
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* System initialize for atomic system: '<Root>/Control System' */
static void ControlSystem_Init(DW_ControlSystem *localDW)
{
  /* InitializeConditions for Delay: '<S327>/MemoryX' */
  localDW->icLoad = true;

  /* InitializeConditions for Delay: '<S381>/MemoryX' */
  localDW->icLoad_k = true;

  /* InitializeConditions for Delay: '<S261>/MemoryX' */
  localDW->icLoad_c = true;

  /* InitializeConditions for Delay: '<S447>/MemoryX' */
  localDW->icLoad_o = true;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_PrevResetState = 2;
}

/* Output and update for atomic system: '<Root>/Control System' */
static void ControlSystem(const CommandBus *rtu_ReferenceValueServerCmds, const
  SensorsBus *rtu_Sensors, const real_T rtu_VisionbasedData[6], DW_ControlSystem
  *localDW, ZCE_ControlSystem *localZCE)
{
  real32_T rtb_Subtract_p_idx_1_tmp;
  real32_T rtb_Subtract_p_idx_2_tmp;
  real32_T rtb_VectorConcatenate_tmp;
  real32_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_VectorConcatenate_tmp_1;
  real32_T rtb_VectorConcatenate_tmp_2;
  real32_T rtb_VectorConcatenate_tmp_tmp;
  real32_T rtb_sincos_o2_idx_0_tmp;
  real32_T rtb_sincos_o2_idx_1_tmp;
  int16_T rtb_LogicalOperator;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Compare_fh;
  boolean_T rtb_Compare_fl;

  /* Delay: '<S327>/MemoryX' */
  if (localDW->icLoad) {
    localDW->MemoryX_DSTATE_g[0] = 0.0F;
    localDW->MemoryX_DSTATE_g[1] = 0.0F;
  }

  localDW->MemoryX_e[0] = localDW->MemoryX_DSTATE_g[0];
  localDW->MemoryX_e[1] = localDW->MemoryX_DSTATE_g[1];

  /* Bias: '<S259>/Assuming that the  preflight calibration was done at level orientation' */
  for (localDW->i_b = 0; localDW->i_b < 6; localDW->i_b++) {
    localDW->Sum1_p[localDW->i_b] = rtu_Sensors->SensorCalibration[localDW->i_b]
      + rtConstP.Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi[
      localDW->i_b];
  }

  /* End of Bias: '<S259>/Assuming that the  preflight calibration was done at level orientation' */

  /* Gain: '<S259>/inverseIMU_gain' incorporates:
   *  Sum: '<S259>/Sum1'
   */
  localDW->inverseIMU_gain_idx_0 = (rtu_Sensors->HALSensors.HAL_acc_SI.x -
    localDW->Sum1_p[0]) * 0.994075298F;
  localDW->inverseIMU_gain_idx_1 = (rtu_Sensors->HALSensors.HAL_acc_SI.y -
    localDW->Sum1_p[1]) * 0.996184587F;
  localDW->inverseIMU_gain_idx_2 = (rtu_Sensors->HALSensors.HAL_acc_SI.z -
    localDW->Sum1_p[2]) * 1.00549F;

  /* DiscreteFir: '<S259>/FIR_IMUaccel' */
  localDW->pressureFilter_IIR_tmp = localDW->inverseIMU_gain_idx_0 *
    0.0264077242F;
  localDW->cff = 1;
  localDW->i_b = localDW->FIR_IMUaccel_circBuf;
  while (localDW->i_b < 5) {
    localDW->pressureFilter_IIR_tmp += localDW->FIR_IMUaccel_states[localDW->i_b]
      * rtConstP.FIR_IMUaccel_Coefficients[localDW->cff];
    localDW->cff++;
    localDW->i_b++;
  }

  localDW->i_b = 0;
  while (localDW->i_b < localDW->FIR_IMUaccel_circBuf) {
    localDW->pressureFilter_IIR_tmp += localDW->FIR_IMUaccel_states[localDW->i_b]
      * rtConstP.FIR_IMUaccel_Coefficients[localDW->cff];
    localDW->cff++;
    localDW->i_b++;
  }

  localDW->FIR_IMUaccel[0] = localDW->pressureFilter_IIR_tmp;

  /* Math: '<S326>/Math Function' incorporates:
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   */
  localDW->rtb_MathFunction_idx_0 = rt_powf_snf(localDW->pressureFilter_IIR_tmp,
    2.0F);

  /* DiscreteFir: '<S259>/FIR_IMUaccel' */
  localDW->pressureFilter_IIR_tmp = localDW->inverseIMU_gain_idx_1 *
    0.0264077242F;
  localDW->cff = 1;
  localDW->i_b = localDW->FIR_IMUaccel_circBuf;
  while (localDW->i_b < 5) {
    localDW->pressureFilter_IIR_tmp += localDW->FIR_IMUaccel_states[localDW->i_b
      + 5] * rtConstP.FIR_IMUaccel_Coefficients[localDW->cff];
    localDW->cff++;
    localDW->i_b++;
  }

  localDW->i_b = 0;
  while (localDW->i_b < localDW->FIR_IMUaccel_circBuf) {
    localDW->pressureFilter_IIR_tmp += localDW->FIR_IMUaccel_states[localDW->i_b
      + 5] * rtConstP.FIR_IMUaccel_Coefficients[localDW->cff];
    localDW->cff++;
    localDW->i_b++;
  }

  localDW->FIR_IMUaccel[1] = localDW->pressureFilter_IIR_tmp;

  /* Math: '<S326>/Math Function' incorporates:
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   */
  localDW->rtb_sincos_o2_a_idx_1 = localDW->pressureFilter_IIR_tmp;

  /* DiscreteFir: '<S259>/FIR_IMUaccel' */
  localDW->pressureFilter_IIR_tmp = localDW->inverseIMU_gain_idx_2 *
    0.0264077242F;
  localDW->cff = 1;
  localDW->i_b = localDW->FIR_IMUaccel_circBuf;
  while (localDW->i_b < 5) {
    localDW->pressureFilter_IIR_tmp += localDW->FIR_IMUaccel_states[localDW->i_b
      + 10] * rtConstP.FIR_IMUaccel_Coefficients[localDW->cff];
    localDW->cff++;
    localDW->i_b++;
  }

  localDW->i_b = 0;
  while (localDW->i_b < localDW->FIR_IMUaccel_circBuf) {
    localDW->pressureFilter_IIR_tmp += localDW->FIR_IMUaccel_states[localDW->i_b
      + 10] * rtConstP.FIR_IMUaccel_Coefficients[localDW->cff];
    localDW->cff++;
    localDW->i_b++;
  }

  localDW->FIR_IMUaccel[2] = localDW->pressureFilter_IIR_tmp;

  /* Gain: '<S323>/Gain2' */
  localDW->Saturation_j = 0.101936802F * localDW->FIR_IMUaccel[0];

  /* Trigonometry: '<S323>/Trigonometric Function1' */
  if (localDW->Saturation_j > 1.0F) {
    localDW->Saturation_j = 1.0F;
  } else if (localDW->Saturation_j < -1.0F) {
    localDW->Saturation_j = -1.0F;
  }

  localDW->TrigonometricFunction1 = (real32_T)asin(localDW->Saturation_j);

  /* End of Trigonometry: '<S323>/Trigonometric Function1' */

  /* Sqrt: '<S326>/Sqrt' incorporates:
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   *  Math: '<S326>/Math Function'
   *  Sum: '<S326>/Sum of Elements'
   */
  localDW->Saturation_j = (real32_T)sqrt((localDW->rtb_MathFunction_idx_0 +
    rt_powf_snf(localDW->rtb_sincos_o2_a_idx_1, 2.0F)) + rt_powf_snf
    (localDW->pressureFilter_IIR_tmp, 2.0F));

  /* Logic: '<S258>/Logical Operator' incorporates:
   *  Constant: '<S321>/Constant'
   *  Constant: '<S322>/Constant'
   *  RelationalOperator: '<S321>/Compare'
   *  RelationalOperator: '<S322>/Compare'
   */
  rtb_LogicalOperator = (int16_T)((localDW->Saturation_j > 6.867F) &&
    (localDW->Saturation_j < 12.753F));

  /* DataTypeConversion: '<S371>/Conversion' incorporates:
   *  DataTypeConversion: '<S425>/Conversion'
   */
  localDW->TmpSignalConversionAtIIRgyrozInport1[0] = 0.00118693F;
  localDW->TmpSignalConversionAtIIRgyrozInport1[1] = -3.28681635E-5F;

  /* Outputs for Enabled SubSystem: '<S354>/Enabled Subsystem' */
  /* DataTypeConversion: '<S327>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S327>/C'
   *  DataTypeConversion: '<S371>/Conversion'
   */
  EnabledSubsystem(rtb_LogicalOperator != 0,
                   localDW->TmpSignalConversionAtIIRgyrozInport1,
                   rtConstP.pooled19, localDW->TrigonometricFunction1,
                   localDW->MemoryX_e, &localDW->EnabledSubsystem_d);

  /* End of Outputs for SubSystem: '<S354>/Enabled Subsystem' */

  /* Sum: '<S354>/Add' incorporates:
   *  Delay: '<S327>/MemoryX'
   */
  localDW->rtb_MathFunction_idx_0 = localDW->EnabledSubsystem_d.Product2[0] +
    localDW->MemoryX_DSTATE_g[0];

  /* Delay: '<S381>/MemoryX' */
  if (localDW->icLoad_k) {
    localDW->MemoryX_DSTATE_m[0] = 0.0F;
    localDW->MemoryX_DSTATE_m[1] = 0.0F;
  }

  localDW->MemoryX_g[0] = localDW->MemoryX_DSTATE_m[0];
  localDW->MemoryX_g[1] = localDW->MemoryX_DSTATE_m[1];

  /* Trigonometry: '<S324>/Trigonometric Function' incorporates:
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   *  Product: '<S324>/Divide'
   */
  localDW->TrigonometricFunction = (real32_T)atan(localDW->FIR_IMUaccel[1] /
    localDW->pressureFilter_IIR_tmp);

  /* Outputs for Enabled SubSystem: '<S408>/Enabled Subsystem' */
  /* DataTypeConversion: '<S381>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S381>/C'
   */
  EnabledSubsystem(rtb_LogicalOperator != 0,
                   localDW->TmpSignalConversionAtIIRgyrozInport1,
                   rtConstP.pooled19, localDW->TrigonometricFunction,
                   localDW->MemoryX_g, &localDW->EnabledSubsystem_n);

  /* End of Outputs for SubSystem: '<S408>/Enabled Subsystem' */

  /* Sum: '<S408>/Add' incorporates:
   *  Delay: '<S381>/MemoryX'
   */
  localDW->rtb_Integrator_idx_0 = localDW->EnabledSubsystem_n.Product2[0] +
    localDW->MemoryX_DSTATE_m[0];

  /* Trigonometry: '<S263>/sincos' incorporates:
   *  DiscreteIntegrator: '<S325>/Discrete-Time Integrator'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   *  SignalConversion generated from: '<S263>/sincos'
   *  Trigonometry: '<S450>/sincos'
   *  Trigonometry: '<S523>/sincos'
   */
  localDW->rtb_Subtract_p_idx_0_tmp = (real32_T)sin
    (localDW->DiscreteTimeIntegrator_DSTATE);
  rtb_sincos_o2_idx_0_tmp = (real32_T)cos(localDW->DiscreteTimeIntegrator_DSTATE);
  rtb_Subtract_p_idx_1_tmp = (real32_T)sin(localDW->rtb_MathFunction_idx_0);
  rtb_sincos_o2_idx_1_tmp = (real32_T)cos(localDW->rtb_MathFunction_idx_0);
  rtb_Subtract_p_idx_2_tmp = (real32_T)sin(localDW->rtb_Integrator_idx_0);
  localDW->rtb_Product_idx_0 = (real32_T)cos(localDW->rtb_Integrator_idx_0);

  /* Fcn: '<S263>/Fcn11' incorporates:
   *  Fcn: '<S450>/Fcn11'
   *  Fcn: '<S523>/Fcn11'
   *  Trigonometry: '<S263>/sincos'
   */
  localDW->rtb_Product_idx_1 = rtb_sincos_o2_idx_0_tmp * rtb_sincos_o2_idx_1_tmp;
  localDW->VectorConcatenate[0] = localDW->rtb_Product_idx_1;

  /* Fcn: '<S263>/Fcn21' incorporates:
   *  Fcn: '<S450>/Fcn21'
   *  Fcn: '<S523>/Fcn21'
   *  Trigonometry: '<S263>/sincos'
   */
  localDW->SaturationThrust1 = rtb_Subtract_p_idx_1_tmp *
    rtb_Subtract_p_idx_2_tmp;
  localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
    localDW->rtb_Subtract_p_idx_0_tmp * localDW->rtb_Product_idx_0;
  localDW->VectorConcatenate[1] = localDW->SaturationThrust1 *
    rtb_sincos_o2_idx_0_tmp -
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c;

  /* Fcn: '<S263>/Fcn31' incorporates:
   *  Fcn: '<S450>/Fcn31'
   *  Fcn: '<S523>/Fcn31'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_VectorConcatenate_tmp_tmp = rtb_Subtract_p_idx_1_tmp *
    localDW->rtb_Product_idx_0;
  rtb_VectorConcatenate_tmp = localDW->rtb_Subtract_p_idx_0_tmp *
    rtb_Subtract_p_idx_2_tmp;
  localDW->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_tmp *
    rtb_sincos_o2_idx_0_tmp + rtb_VectorConcatenate_tmp;

  /* Fcn: '<S263>/Fcn12' incorporates:
   *  Fcn: '<S450>/Fcn12'
   *  Fcn: '<S523>/Fcn12'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_VectorConcatenate_tmp_0 = localDW->rtb_Subtract_p_idx_0_tmp *
    rtb_sincos_o2_idx_1_tmp;
  localDW->VectorConcatenate[3] = rtb_VectorConcatenate_tmp_0;

  /* Fcn: '<S263>/Fcn22' incorporates:
   *  Fcn: '<S263>/Fcn21'
   *  Fcn: '<S450>/Fcn22'
   *  Fcn: '<S523>/Fcn22'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_VectorConcatenate_tmp_1 = rtb_sincos_o2_idx_0_tmp *
    localDW->rtb_Product_idx_0;
  localDW->VectorConcatenate[4] = localDW->SaturationThrust1 *
    localDW->rtb_Subtract_p_idx_0_tmp + rtb_VectorConcatenate_tmp_1;

  /* Fcn: '<S263>/Fcn32' incorporates:
   *  Fcn: '<S263>/Fcn31'
   *  Fcn: '<S450>/Fcn32'
   *  Fcn: '<S523>/Fcn32'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_VectorConcatenate_tmp_2 = rtb_sincos_o2_idx_0_tmp *
    rtb_Subtract_p_idx_2_tmp;
  localDW->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_tmp *
    localDW->rtb_Subtract_p_idx_0_tmp - rtb_VectorConcatenate_tmp_2;

  /* Fcn: '<S263>/Fcn13' incorporates:
   *  Trigonometry: '<S263>/sincos'
   */
  localDW->VectorConcatenate[6] = -rtb_Subtract_p_idx_1_tmp;

  /* Fcn: '<S263>/Fcn23' incorporates:
   *  Fcn: '<S450>/Fcn23'
   *  Fcn: '<S523>/Fcn23'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_Subtract_p_idx_2_tmp *= rtb_sincos_o2_idx_1_tmp;
  localDW->VectorConcatenate[7] = rtb_Subtract_p_idx_2_tmp;

  /* Fcn: '<S263>/Fcn33' incorporates:
   *  Fcn: '<S450>/Fcn33'
   *  Fcn: '<S523>/Fcn33'
   *  Trigonometry: '<S263>/sincos'
   */
  rtb_sincos_o2_idx_1_tmp *= localDW->rtb_Product_idx_0;
  localDW->VectorConcatenate[8] = rtb_sincos_o2_idx_1_tmp;

  /* Fcn: '<S523>/Fcn11' */
  localDW->MathFunction_a[0] = localDW->rtb_Product_idx_1;

  /* Fcn: '<S523>/Fcn21' */
  localDW->MathFunction_a[1] = localDW->SaturationThrust1 *
    rtb_sincos_o2_idx_0_tmp -
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c;

  /* Fcn: '<S523>/Fcn31' */
  localDW->MathFunction_a[2] = rtb_VectorConcatenate_tmp_tmp *
    rtb_sincos_o2_idx_0_tmp + rtb_VectorConcatenate_tmp;

  /* Fcn: '<S523>/Fcn12' */
  localDW->MathFunction_a[3] = rtb_VectorConcatenate_tmp_0;

  /* Fcn: '<S523>/Fcn22' */
  localDW->MathFunction_a[4] = localDW->SaturationThrust1 *
    localDW->rtb_Subtract_p_idx_0_tmp + rtb_VectorConcatenate_tmp_1;

  /* Fcn: '<S523>/Fcn32' */
  localDW->MathFunction_a[5] = rtb_VectorConcatenate_tmp_tmp *
    localDW->rtb_Subtract_p_idx_0_tmp - rtb_VectorConcatenate_tmp_2;

  /* Fcn: '<S523>/Fcn13' */
  localDW->MathFunction_a[6] = -rtb_Subtract_p_idx_1_tmp;

  /* Fcn: '<S523>/Fcn23' */
  localDW->MathFunction_a[7] = rtb_Subtract_p_idx_2_tmp;

  /* Fcn: '<S523>/Fcn33' */
  localDW->MathFunction_a[8] = rtb_sincos_o2_idx_1_tmp;

  /* Math: '<S443>/Math Function' */
  for (localDW->i_b = 0; localDW->i_b < 3; localDW->i_b++) {
    localDW->VectorConcatenate_o[3 * localDW->i_b] = localDW->
      MathFunction_a[localDW->i_b];
    localDW->VectorConcatenate_o[3 * localDW->i_b + 1] = localDW->
      MathFunction_a[localDW->i_b + 3];
    localDW->VectorConcatenate_o[3 * localDW->i_b + 2] = localDW->
      MathFunction_a[localDW->i_b + 6];
  }

  for (localDW->i_b = 0; localDW->i_b < 9; localDW->i_b++) {
    localDW->MathFunction_a[localDW->i_b] = localDW->VectorConcatenate_o
      [localDW->i_b];
  }

  /* End of Math: '<S443>/Math Function' */

  /* Delay: '<S261>/MemoryX' incorporates:
   *  Constant: '<S264>/Constant'
   *  Delay: '<S257>/Delay2'
   *  RelationalOperator: '<S264>/Compare'
   */
  localDW->icLoad_c = ((localDW->Delay2_DSTATE > 0.0) || localDW->icLoad_c);
  if (localDW->icLoad_c) {
    localDW->MemoryX_DSTATE[0] = -0.046;
    localDW->MemoryX_DSTATE[1] = 0.0;
  }

  /* DiscreteFilter: '<S262>/pressureFilter_IIR' incorporates:
   *  Gain: '<S257>/prsToAltGain'
   *  Sum: '<S259>/Sum2'
   */
  localDW->rtb_VectorConcatenate_tmp =
    (((rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
       rtu_Sensors->SensorCalibration[6]) * 0.0832137167F - -2.93717074F *
      localDW->pressureFilter_IIR_states[0]) - 2.87629962F *
     localDW->pressureFilter_IIR_states[1]) - -0.939098954F *
    localDW->pressureFilter_IIR_states[2];
  localDW->pressureFilter_IIR = ((3.75683794E-6F *
    localDW->rtb_VectorConcatenate_tmp + 1.12705138E-5F *
    localDW->pressureFilter_IIR_states[0]) + 1.12705138E-5F *
    localDW->pressureFilter_IIR_states[1]) + 3.75683794E-6F *
    localDW->pressureFilter_IIR_states[2];

  /* DiscreteFilter: '<S262>/sonarFilter_IIR' incorporates:
   *  Gain: '<S257>/invertzaxisGain'
   */
  localDW->sonarFilter_IIR_tmp = ((-(real_T)
    rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude - -2.9371707284498907 *
    localDW->sonarFilter_IIR_states[0]) - 2.8762997234793319 *
    localDW->sonarFilter_IIR_states[1]) - -0.939098940325283 *
    localDW->sonarFilter_IIR_states[2];

  /* Saturate: '<S262>/SaturationSonar' incorporates:
   *  Gain: '<S257>/invertzaxisGain'
   */
  if (-(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude >= -0.44) {
    localDW->x_error = -0.44;
  } else {
    localDW->x_error = -(real_T)
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
  rtb_Compare_fl = ((fabs(localDW->Delay2_DSTATE - localDW->x_error) <= 0.1) &&
                    (-(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude
                     < -0.44) && ((!(fabs(localDW->pressureFilter_IIR -
    localDW->Delay2_DSTATE) >= 0.8)) || (!(fabs((((3.7568380197512489E-6 *
    localDW->sonarFilter_IIR_tmp + 1.1270514059253748E-5 *
    localDW->sonarFilter_IIR_states[0]) + 1.1270514059253748E-5 *
    localDW->sonarFilter_IIR_states[1]) + 3.7568380197512489E-6 *
    localDW->sonarFilter_IIR_states[2]) - localDW->Delay2_DSTATE) >= 0.4))));

  /* Outputs for Enabled SubSystem: '<S289>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S315>/Enable'
   */
  if (rtb_Compare_fl) {
    localDW->EnabledSubsystem_MODE_i = true;

    /* Sum: '<S315>/Add1' incorporates:
     *  Constant: '<S261>/C'
     *  Delay: '<S261>/MemoryX'
     *  Gain: '<S257>/invertzaxisGain'
     *  Product: '<S315>/Product'
     */
    localDW->u_h = -(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude -
      (0.0 * localDW->MemoryX_DSTATE[1] + localDW->MemoryX_DSTATE[0]);

    /* Product: '<S315>/Product2' */
    localDW->Product2[0] = 0.02624142064187163 * localDW->u_h;
    localDW->Product2[1] = 0.0697767360714917 * localDW->u_h;
  } else if (localDW->EnabledSubsystem_MODE_i) {
    /* Disable for Product: '<S315>/Product2' incorporates:
     *  Outport: '<S315>/deltax'
     */
    localDW->Product2[0] = 0.0;
    localDW->Product2[1] = 0.0;
    localDW->EnabledSubsystem_MODE_i = false;
  }

  /* End of Outputs for SubSystem: '<S289>/Enabled Subsystem' */

  /* Sum: '<S289>/Add' incorporates:
   *  Delay: '<S261>/MemoryX'
   */
  localDW->rtb_Add_idx_0 = localDW->Product2[0] + localDW->MemoryX_DSTATE[0];
  localDW->rtb_Add_idx_1 = localDW->Product2[1] + localDW->MemoryX_DSTATE[1];

  /* Switch: '<S448>/Switch' incorporates:
   *  Constant: '<S519>/Constant'
   *  DataTypeConversion: '<S257>/Data Type Conversion'
   *  Gain: '<S448>/Gain'
   *  Gain: '<S448>/opticalFlowErrorCorrect'
   *  Product: '<S448>/ '
   *  RelationalOperator: '<S519>/Compare'
   *  UnitDelay: '<S520>/Output'
   */
  if (localDW->Output_DSTATE < 800U) {
    localDW->rtb_sincos_o2_a_idx_0 = rtu_Sensors->
      VisionSensors.opticalFlow_data[0];
    localDW->rtb_sincos_o2_a_idx_1 = rtu_Sensors->
      VisionSensors.opticalFlow_data[1];
  } else {
    localDW->rtb_sincos_o2_a_idx_0 = rtu_Sensors->
      VisionSensors.opticalFlow_data[0] * -(real32_T)localDW->rtb_Add_idx_0 *
      1.15F;
    localDW->rtb_sincos_o2_a_idx_1 = rtu_Sensors->
      VisionSensors.opticalFlow_data[1] * -(real32_T)localDW->rtb_Add_idx_0 *
      1.15F;
  }

  /* End of Switch: '<S448>/Switch' */

  /* Abs: '<S445>/Abs' incorporates:
   *  DataTypeConversion: '<S257>/Data Type Conversion'
   */
  localDW->Saturation_j = (real32_T)fabs((real32_T)localDW->rtb_Add_idx_0);

  /* DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz1' incorporates:
   *  Gain: '<S259>/inverseIMU_gain'
   *  Sum: '<S259>/Sum1'
   */
  localDW->altfrompress = ((rtu_Sensors->HALSensors.HAL_gyro_SI.x -
    localDW->Sum1_p[3]) * 1.00139189F - -0.591549456F *
    localDW->LPFFcutoff40Hz1_states) / 2.5915494F;
  localDW->p = localDW->altfrompress + localDW->LPFFcutoff40Hz1_states;

  /* DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz' incorporates:
   *  Gain: '<S259>/inverseIMU_gain'
   *  Sum: '<S259>/Sum1'
   */
  localDW->LPFFcutoff40Hz_tmp = ((rtu_Sensors->HALSensors.HAL_gyro_SI.y -
    localDW->Sum1_p[4]) * 0.993601203F - -0.591549456F *
    localDW->LPFFcutoff40Hz_states) / 2.5915494F;
  localDW->q = localDW->LPFFcutoff40Hz_tmp + localDW->LPFFcutoff40Hz_states;

  /* DiscreteFilter: '<S259>/IIR_IMUgyro_r' incorporates:
   *  Gain: '<S259>/inverseIMU_gain'
   *  Sum: '<S259>/Sum1'
   */
  localDW->DataTypeConversion2 = (rtu_Sensors->HALSensors.HAL_gyro_SI.z -
    localDW->Sum1_p[5]) * 1.00003F;
  localDW->denIdx = 1;
  for (localDW->i_b = 0; localDW->i_b < 5; localDW->i_b++) {
    localDW->DataTypeConversion2 -= rtConstP.pooled23[localDW->denIdx] *
      localDW->IIR_IMUgyro_r_states[localDW->i_b];
    localDW->denIdx++;
  }

  localDW->IIR_IMUgyro_r_tmp = localDW->DataTypeConversion2;
  localDW->r = 0.282124132F * localDW->DataTypeConversion2;
  localDW->denIdx = 1;
  for (localDW->i_b = 0; localDW->i_b < 5; localDW->i_b++) {
    localDW->r += rtConstP.pooled22[localDW->denIdx] *
      localDW->IIR_IMUgyro_r_states[localDW->i_b];
    localDW->denIdx++;
  }

  /* End of DiscreteFilter: '<S259>/IIR_IMUgyro_r' */

  /* RelationalOperator: '<S437>/Compare' incorporates:
   *  Constant: '<S437>/Constant'
   *  UnitDelay: '<S438>/Output'
   */
  rtb_Compare_f = (localDW->Output_DSTATE_i == 1U);

  /* Outputs for Triggered SubSystem: '<S435>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S439>/Trigger'
   */
  if (((localZCE->TriggeredSubsystem_Trig_ZCE == 1) != (int32_T)rtb_Compare_f) &&
      (localZCE->TriggeredSubsystem_Trig_ZCE != 3)) {
    /* Inport: '<S439>/In1' */
    localDW->In1 = rtu_Sensors->HALSensors.HAL_gyro_SI.temperature;
  }

  localZCE->TriggeredSubsystem_Trig_ZCE = rtb_Compare_f;

  /* End of Outputs for SubSystem: '<S435>/Triggered Subsystem' */

  /* Sum: '<S435>/Subtract1' incorporates:
   *  Gain: '<S435>/Gain'
   *  ManualSwitch: '<S435>/Disable temperature compensation'
   *  Sum: '<S435>/Subtract'
   */
  localDW->r -= (rtu_Sensors->HALSensors.HAL_gyro_SI.temperature - localDW->In1)
    * 0.00228F;

  /* Sum: '<S258>/Subtract' incorporates:
   *  Delay: '<S327>/MemoryX'
   *  Delay: '<S381>/MemoryX'
   *  Sum: '<S354>/Add'
   *  Sum: '<S408>/Add'
   */
  localDW->rtb_Subtract_p_idx_0 = localDW->p -
    (localDW->EnabledSubsystem_n.Product2[1] + localDW->MemoryX_DSTATE_m[1]);
  localDW->rtb_Subtract_p_idx_1 = localDW->q -
    (localDW->EnabledSubsystem_d.Product2[1] + localDW->MemoryX_DSTATE_g[1]);

  /* Sum: '<S442>/angular velocity compensation' incorporates:
   *  Gain: '<S445>/Gain1'
   *  Product: '<S445>/prod'
   */
  localDW->angularvelocitycompensation[0] = localDW->rtb_sincos_o2_a_idx_0 +
    -(localDW->Saturation_j * localDW->rtb_Subtract_p_idx_1);
  localDW->angularvelocitycompensation[1] = localDW->Saturation_j *
    localDW->rtb_Subtract_p_idx_0 + localDW->rtb_sincos_o2_a_idx_1;

  /* SignalConversion generated from: '<S446>/IIRgyroz' */
  localDW->TmpSignalConversionAtIIRgyrozInport1[0] = localDW->p;
  localDW->TmpSignalConversionAtIIRgyrozInport1[1] = localDW->q;
  for (localDW->cff = 0; localDW->cff < 2; localDW->cff++) {
    /* DiscreteFilter: '<S446>/IIRgyroz' */
    localDW->i = localDW->cff * 5;
    localDW->DataTypeConversion2 = localDW->
      TmpSignalConversionAtIIRgyrozInport1[localDW->cff];
    localDW->denIdx = 1;
    for (localDW->i_b = 0; localDW->i_b < 5; localDW->i_b++) {
      localDW->DataTypeConversion2 -= localDW->IIRgyroz_states[localDW->i +
        localDW->i_b] * rtConstP.pooled23[localDW->denIdx];
      localDW->denIdx++;
    }

    localDW->Saturation_j = 0.282124132F * localDW->DataTypeConversion2;
    localDW->denIdx = 1;
    for (localDW->i_b = 0; localDW->i_b < 5; localDW->i_b++) {
      localDW->Saturation_j += localDW->IIRgyroz_states[localDW->i +
        localDW->i_b] * rtConstP.pooled22[localDW->denIdx];
      localDW->denIdx++;
    }

    /* SampleTimeMath: '<S454>/TSamp' incorporates:
     *  DiscreteFilter: '<S446>/IIRgyroz'
     *
     * About '<S454>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localDW->Saturation_j *= 200.0F;

    /* DiscreteFilter: '<S446>/IIRgyroz' incorporates:
     *  Sum: '<S454>/Diff'
     *  UnitDelay: '<S454>/UD'
     *
     * Block description for '<S454>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S454>/UD':
     *
     *  Store in Global RAM
     */
    localDW->IIRgyroz_tmp[localDW->cff] = localDW->DataTypeConversion2;
    localDW->Integrator_a[localDW->cff] = localDW->Saturation_j -
      localDW->UD_DSTATE_k[localDW->cff];

    /* SampleTimeMath: '<S454>/TSamp'
     *
     * About '<S454>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localDW->TmpSignalConversionAtIIRgyrozInport1[localDW->cff] =
      localDW->Saturation_j;
  }

  /* Abs: '<S446>/Abs' incorporates:
   *  Abs: '<S446>/Abs4'
   */
  localDW->DataTypeConversion2 = (real32_T)fabs(localDW->p);

  /* Abs: '<S446>/Abs1' incorporates:
   *  Abs: '<S446>/Abs5'
   */
  localDW->pitchrollerror = (real32_T)fabs(localDW->q);

  /* RelationalOperator: '<S449>/Compare' incorporates:
   *  Constant: '<S449>/Constant'
   *  DataTypeConversion: '<S257>/Data Type Conversion'
   */
  rtb_Compare_f = ((real32_T)localDW->rtb_Add_idx_0 <= -0.4F);

  /* Logic: '<S444>/Logical Operator' incorporates:
   *  Constant: '<S451>/Constant'
   *  Constant: '<S452>/Constant'
   *  RelationalOperator: '<S451>/Compare'
   *  RelationalOperator: '<S452>/Compare'
   */
  rtb_Compare_fh = ((localDW->rtb_sincos_o2_a_idx_0 != 0.0F) ||
                    (localDW->rtb_sincos_o2_a_idx_1 != 0.0F));

  /* Fcn: '<S450>/Fcn11' */
  localDW->VectorConcatenate_o[0] = localDW->rtb_Product_idx_1;

  /* Fcn: '<S450>/Fcn21' */
  localDW->VectorConcatenate_o[1] = localDW->SaturationThrust1 *
    rtb_sincos_o2_idx_0_tmp -
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c;

  /* Fcn: '<S450>/Fcn31' */
  localDW->VectorConcatenate_o[2] = rtb_VectorConcatenate_tmp_tmp *
    rtb_sincos_o2_idx_0_tmp + rtb_VectorConcatenate_tmp;

  /* Fcn: '<S450>/Fcn12' */
  localDW->VectorConcatenate_o[3] = rtb_VectorConcatenate_tmp_0;

  /* Fcn: '<S450>/Fcn22' */
  localDW->VectorConcatenate_o[4] = localDW->SaturationThrust1 *
    localDW->rtb_Subtract_p_idx_0_tmp + rtb_VectorConcatenate_tmp_1;

  /* Fcn: '<S450>/Fcn32' */
  localDW->VectorConcatenate_o[5] = rtb_VectorConcatenate_tmp_tmp *
    localDW->rtb_Subtract_p_idx_0_tmp - rtb_VectorConcatenate_tmp_2;

  /* Fcn: '<S450>/Fcn13' */
  localDW->VectorConcatenate_o[6] = -rtb_Subtract_p_idx_1_tmp;

  /* Fcn: '<S450>/Fcn23' */
  localDW->VectorConcatenate_o[7] = rtb_Subtract_p_idx_2_tmp;

  /* Fcn: '<S450>/Fcn33' */
  localDW->VectorConcatenate_o[8] = rtb_sincos_o2_idx_1_tmp;

  /* Sum: '<S444>/Add' incorporates:
   *  Concatenate: '<S453>/Vector Concatenate'
   *  Product: '<S444>/Product1'
   */
  for (localDW->i_b = 0; localDW->i_b < 3; localDW->i_b++) {
    localDW->Sum[localDW->i_b] = localDW->FIR_IMUaccel[localDW->i_b] -
      ((localDW->VectorConcatenate_o[localDW->i_b + 3] * 0.0 +
        localDW->VectorConcatenate_o[localDW->i_b] * 0.0) +
       localDW->VectorConcatenate_o[localDW->i_b + 6] * -9.81);
  }

  /* End of Sum: '<S444>/Add' */

  /* Product: '<S444>/Product' incorporates:
   *  Gain: '<S444>/gainaccinput1'
   */
  localDW->rtb_Product_idx_0 = (real32_T)rtb_Compare_fh * (real32_T)localDW->
    Sum[0] * (real32_T)rtb_Compare_f;
  localDW->rtb_Product_idx_1 = (real32_T)rtb_Compare_fh * (real32_T)localDW->
    Sum[1] * (real32_T)rtb_Compare_f;

  /* Delay: '<S447>/MemoryX' */
  if (localDW->icLoad_o) {
    localDW->MemoryX_DSTATE_l[0] = 0.0F;
    localDW->MemoryX_DSTATE_l[1] = 0.0F;
    localDW->MemoryX_DSTATE_l[2] = 0.0F;
    localDW->MemoryX_DSTATE_l[3] = 0.0F;
  }

  /* Outputs for Enabled SubSystem: '<S492>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S518>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S485>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S516>/Enable'
   */
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
   *  DataTypeConversion: '<S257>/Data Type Conversion'
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
  if (((((real32_T)fabs(localDW->rtb_MathFunction_idx_0) <= 0.6F) && ((real32_T)
         fabs(localDW->rtb_Integrator_idx_0) <= 0.6F) &&
        (localDW->DataTypeConversion2 <= 7.0F) && (localDW->pitchrollerror <=
         7.0F) && ((real32_T)fabs(localDW->Integrator_a[0]) <= 80.0F) &&
        ((real32_T)fabs(localDW->Integrator_a[1]) <= 80.0F)) ||
       ((localDW->DataTypeConversion2 <= 0.5F) && (localDW->pitchrollerror <=
         0.5F))) && ((real32_T)fabs(localDW->rtb_sincos_o2_a_idx_0 -
        localDW->Delay_DSTATE_a[0]) <= 5.0F) && ((real32_T)fabs
       (localDW->rtb_sincos_o2_a_idx_1 - localDW->Delay_DSTATE_a[1]) <= 5.0F) &&
      ((real32_T)localDW->rtb_Add_idx_0 <= -0.4F)) {
    localDW->MeasurementUpdate_MODE = true;
    for (localDW->i_b = 0; localDW->i_b < 2; localDW->i_b++) {
      rtb_sincos_o2_idx_1_tmp = rtConstP.C_Value_i[localDW->i_b + 6] *
        localDW->MemoryX_DSTATE_l[3] + (rtConstP.C_Value_i[localDW->i_b + 4] *
        localDW->MemoryX_DSTATE_l[2] + (rtConstP.C_Value_i[localDW->i_b + 2] *
        localDW->MemoryX_DSTATE_l[1] + rtConstP.C_Value_i[localDW->i_b] *
        localDW->MemoryX_DSTATE_l[0]));

      /* Sum: '<S516>/Sum' incorporates:
       *  Constant: '<S447>/C'
       *  Constant: '<S447>/D'
       *  Delay: '<S447>/MemoryX'
       *  Product: '<S516>/C[k]*xhat[k|k-1]'
       *  Product: '<S516>/D[k]*u[k]'
       *  Sum: '<S516>/Add1'
       */
      localDW->rtb_angularvelocitycompensation_k[localDW->i_b] =
        localDW->angularvelocitycompensation[localDW->i_b] - ((0.0F *
        localDW->rtb_Product_idx_0 + 0.0F * localDW->rtb_Product_idx_1) +
        rtb_sincos_o2_idx_1_tmp);
      localDW->Integrator_a[localDW->i_b] = rtb_sincos_o2_idx_1_tmp;
    }

    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S518>/Add1' incorporates:
     *  Constant: '<S447>/C'
     *  Delay: '<S447>/MemoryX'
     *  Product: '<S516>/C[k]*xhat[k|k-1]'
     *  Product: '<S518>/Product'
     */
    localDW->Saturation_j = localDW->angularvelocitycompensation[0] -
      localDW->Integrator_a[0];
    localDW->DataTypeConversion2 = localDW->angularvelocitycompensation[1] -
      localDW->Integrator_a[1];
    for (localDW->i_b = 0; localDW->i_b < 4; localDW->i_b++) {
      /* Product: '<S516>/Product3' incorporates:
       *  Constant: '<S466>/KalmanGainL'
       *  DataTypeConversion: '<S508>/Conversion'
       */
      localDW->Product3_a[localDW->i_b] = 0.0F;
      localDW->Product3_a[localDW->i_b] += (real32_T)
        rtConstP.KalmanGainL_Value[localDW->i_b] *
        localDW->rtb_angularvelocitycompensation_k[0];
      localDW->Product3_a[localDW->i_b] += (real32_T)
        rtConstP.KalmanGainL_Value[localDW->i_b + 4] *
        localDW->rtb_angularvelocitycompensation_k[1];

      /* Product: '<S518>/Product2' incorporates:
       *  Constant: '<S466>/KalmanGainM'
       *  DataTypeConversion: '<S509>/Conversion'
       */
      localDW->Product2_k[localDW->i_b] = 0.0F;
      localDW->Product2_k[localDW->i_b] += (real32_T)
        rtConstP.KalmanGainM_Value[localDW->i_b] * localDW->Saturation_j;
      localDW->Product2_k[localDW->i_b] += (real32_T)
        rtConstP.KalmanGainM_Value[localDW->i_b + 4] *
        localDW->DataTypeConversion2;
    }
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      /* Disable for Product: '<S516>/Product3' incorporates:
       *  Outport: '<S516>/L*(y[k]-yhat[k|k-1])'
       */
      localDW->Product3_a[0] = 0.0F;
      localDW->Product3_a[1] = 0.0F;
      localDW->Product3_a[2] = 0.0F;
      localDW->Product3_a[3] = 0.0F;
      localDW->MeasurementUpdate_MODE = false;
    }

    if (localDW->EnabledSubsystem_MODE) {
      /* Disable for Product: '<S518>/Product2' incorporates:
       *  Outport: '<S518>/deltax'
       */
      localDW->Product2_k[0] = 0.0F;
      localDW->Product2_k[1] = 0.0F;
      localDW->Product2_k[2] = 0.0F;
      localDW->Product2_k[3] = 0.0F;
      localDW->EnabledSubsystem_MODE = false;
    }
  }

  /* End of Logic: '<S446>/Logical Operator3' */
  /* End of Outputs for SubSystem: '<S485>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S492>/Enabled Subsystem' */

  /* Sum: '<S492>/Add' incorporates:
   *  Delay: '<S447>/MemoryX'
   */
  localDW->Add_o[0] = localDW->Product2_k[0] + localDW->MemoryX_DSTATE_l[0];
  localDW->Add_o[1] = localDW->Product2_k[1] + localDW->MemoryX_DSTATE_l[1];
  localDW->Add_o[2] = localDW->Product2_k[2] + localDW->MemoryX_DSTATE_l[2];
  localDW->Add_o[3] = localDW->Product2_k[3] + localDW->MemoryX_DSTATE_l[3];

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  UnitDelay: '<S14>/Output'
   */
  rtb_Compare_f = (localDW->Output_DSTATE_h < 100);

  /* DataTypeConversion: '<S257>/Data Type Conversion1' incorporates:
   *  Delay: '<S6>/Delay1'
   */
  localDW->unnamed_idx_0_tmp = localDW->Delay1_DSTATE_p[0];
  localDW->unnamed_idx_1_tmp = localDW->Delay1_DSTATE_p[1];

  /* Product: '<S257>/Product1' incorporates:
   *  Concatenate: '<S320>/Vector Concatenate'
   *  DataTypeConversion: '<S257>/Data Type Conversion1'
   *  SignalConversion generated from: '<S257>/Product1'
   */
  for (localDW->i_b = 0; localDW->i_b < 3; localDW->i_b++) {
    localDW->Sum[localDW->i_b] = localDW->VectorConcatenate[localDW->i_b + 6] *
      localDW->rtb_Add_idx_1 + (localDW->VectorConcatenate[localDW->i_b + 3] *
      localDW->unnamed_idx_1_tmp + localDW->VectorConcatenate[localDW->i_b] *
      localDW->unnamed_idx_0_tmp);
  }

  /* DataTypeConversion: '<S257>/Data Type Conversion2' */
  localDW->DataTypeConversion2 = (real32_T)localDW->Sum[2];

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  if ((!rtb_Compare_f) && (localDW->DiscreteTimeIntegrator_PrevResetState == 1))
  {
    localDW->DiscreteTimeIntegrator_DSTATE_d = 0.0F;
  }

  if (localDW->DiscreteTimeIntegrator_DSTATE_d >= 2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_d = 2.0F;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE_d <= -2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_d = -2.0F;
  }

  /* MATLAB Function: '<S5>/Take off checker' incorporates:
   *  DataTypeConversion: '<S257>/Data Type Conversion'
   */
  localDW->u_h = (((real32_T)localDW->rtb_Add_idx_0 < -0.65) && ((real32_T)
    localDW->rtb_Add_idx_0 > -0.75F));

  /* Chart: '<S5>/circle count' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c10_flightControlSystem == 0U) {
    localDW->is_active_c10_flightControlSystem = 1U;
    localDW->circle_count = 0.0;
    localDW->flag_tracelane = 0.0;
    localDW->is_c10_flightControlSystem = IN_IDLE_h;
    localDW->temporalCounter_i1 = 0U;
  } else {
    switch (localDW->is_c10_flightControlSystem) {
     case IN_IDLE_h:
      if ((localDW->temporalCounter_i1 >= 600U) && (localDW->u_h == 1.0)) {
        localDW->is_c10_flightControlSystem = IN_LEAVE_MARKER_p;
        localDW->flag_tracelane = 1.0;
      }
      break;

     case IN_LEAVE_MARKER_p:
      if ((localDW->u_h == 1.0) && (rtu_VisionbasedData[2] == 0.0)) {
        localDW->is_c10_flightControlSystem = IN_TRACE_LANE;
        localDW->flag_tracelane = 1.0;
      }
      break;

     case IN_MARKER_DETECTED:
      if (localDW->u_h == 0.0) {
        localDW->is_c10_flightControlSystem = IN_LEAVE_MARKER_p;
        localDW->flag_tracelane = 1.0;
      }
      break;

     default:
      /* case IN_TRACE_LANE: */
      if (rtu_VisionbasedData[2] == 1.0) {
        localDW->is_c10_flightControlSystem = IN_MARKER_DETECTED;
        localDW->circle_count++;
        localDW->flag_tracelane = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/circle count' */

  /* MATLAB Function: '<S5>/MATLAB Function' */
  if (localDW->u_h == 1.0) {
    if (localDW->flag_tracelane == 0.0) {
      localDW->x_error = rtu_VisionbasedData[0];
      localDW->y_error = rtu_VisionbasedData[1];
    } else {
      localDW->x_error = rtu_VisionbasedData[3];
      localDW->y_error = rtu_VisionbasedData[4];
    }
  } else {
    localDW->x_error = 0.0;
    localDW->y_error = 0.0;
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
   *
   * Block description for '<S246>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S246>/UD':
   *
   *  Store in Global RAM
   */
  localDW->Diff = localDW->x_error - localDW->UD_DSTATE;

  /* MATLAB Function: '<S236>/parameter_setting' */
  if (localDW->circle_count < 1.0) {
    localDW->i_b = 10;
  } else {
    localDW->i_b = 100;
  }

  /* End of MATLAB Function: '<S236>/parameter_setting' */

  /* MATLAB Function: '<S244>/MATLAB Function' */
  MATLABFunction(localDW->Diff, (real_T)localDW->i_b,
                 &localDW->sf_MATLABFunction_e);

  /* MATLAB Function: '<S244>/derivative error' incorporates:
   *  Delay: '<S244>/Delay'
   *  Delay: '<S244>/Delay5'
   *  Delay: '<S244>/Delay6'
   */
  derivativeerror(localDW->Delay6_DSTATE, localDW->Diff,
                  localDW->sf_MATLABFunction_e.flag_change_error,
                  localDW->Delay_DSTATE, localDW->Delay5_DSTATE,
                  &localDW->sf_derivativeerror);

  /* Chart: '<S239>/x_linear_contribute' */
  if (localDW->is_active_c20_flightControlSystem == 0U) {
    localDW->is_active_c20_flightControlSystem = 1U;
    localDW->is_c20_flightControlSystem = IN_IDLE;
  } else {
    switch (localDW->is_c20_flightControlSystem) {
     case IN_END_MARKER_DETECTED:
      localDW->linear_part_c = localDW->x_error * 0.0022;
      break;

     case IN_IDLE:
      localDW->is_c20_flightControlSystem = IN_TRACK_DETECTED;
      break;

     default:
      /* case IN_TRACK_DETECTED: */
      if ((rtu_VisionbasedData[2] == 1.0) && (rtu_VisionbasedData[5] == 0.0)) {
        localDW->is_c20_flightControlSystem = IN_END_MARKER_DETECTED;
      } else {
        localDW->linear_part_c = localDW->x_error * 0.0038;
      }
      break;
    }
  }

  /* End of Chart: '<S239>/x_linear_contribute' */

  /* MATLAB Function: '<S241>/MATLAB Function' incorporates:
   *  Delay: '<S241>/Delay1'
   */
  if (rtu_VisionbasedData[2] != 0.0) {
    localDW->Diff = sqrt(localDW->x_error * localDW->x_error + localDW->y_error *
                         localDW->y_error);
    localDW->norm_error_tot = localDW->Diff + localDW->Delay1_DSTATE[0];
  } else {
    localDW->norm_error_tot = 100.0;
    localDW->Diff = 100.0;
  }

  /* Chart: '<S241>/Chart' */
  if (localDW->temporalCounter_i1_n < 1023U) {
    localDW->temporalCounter_i1_n++;
  }

  if (localDW->is_active_c25_flightControlSystem == 0U) {
    localDW->is_active_c25_flightControlSystem = 1U;
    localDW->circle_count_m = 0.0;
    localDW->is_c25_flightControlSystem = IN_TAKE_OFF_p;
    localDW->temporalCounter_i1_n = 0U;
    localDW->z_planned = -0.7;
    localDW->flag_end_marker_to_controller = 0.0;
  } else {
    switch (localDW->is_c25_flightControlSystem) {
     case IN_Grabbing:
      localDW->flag_end_marker_to_controller = 1.0;
      if ((localDW->temporalCounter_i1_n >= 600U) && (localDW->circle_count_m <=
           1.0)) {
        localDW->is_c25_flightControlSystem = IN_TAKE_OFF_p;
        localDW->temporalCounter_i1_n = 0U;
        localDW->z_planned = -0.7;
        localDW->flag_end_marker_to_controller = 0.0;
      } else if (localDW->circle_count_m > 1.0) {
        localDW->is_c25_flightControlSystem = IN_LANDING;
        localDW->z_planned += 0.0005;
      }
      break;

     case IN_LANDING:
      if (localDW->z_planned <= 0.0) {
        localDW->is_c25_flightControlSystem = IN_LANDING;
        localDW->z_planned += 0.0005;
      }
      break;

     case IN_TAKE_OFF_p:
      localDW->flag_end_marker_to_controller = 0.0;
      if ((localDW->temporalCounter_i1_n >= 600U) && (localDW->u_h == 1.0) &&
          (rtu_VisionbasedData[2] == 0.0)) {
        localDW->is_c25_flightControlSystem = IN_TRACKING;
        localDW->z_planned = -0.7;
        localDW->flag_end_marker_to_controller = 0.0;
      }
      break;

     default:
      /* case IN_TRACKING: */
      localDW->flag_end_marker_to_controller = 0.0;
      if ((rtu_VisionbasedData[2] == 1.0) && (localDW->norm_error_tot <= 20.0))
      {
        localDW->is_c25_flightControlSystem = IN_Grabbing;
        localDW->temporalCounter_i1_n = 0U;
        localDW->z_planned = -0.5;
        localDW->flag_end_marker_to_controller = 1.0;
        localDW->circle_count_m++;
      }
      break;
    }
  }

  /* End of Chart: '<S241>/Chart' */

  /* DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' */
  if (localDW->SimplyIntegrateVelocity_PrevResetState <= 0) {
    localDW->SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
    localDW->SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  }

  /* Chart: '<S239>/Chart1' incorporates:
   *  DataTypeConversion: '<S239>/Cast To Double1'
   *  DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity'
   */
  if (localDW->temporalCounter_i1_k < 1023U) {
    localDW->temporalCounter_i1_k++;
  }

  if (localDW->is_active_c5_flightControlSystem == 0U) {
    localDW->is_active_c5_flightControlSystem = 1U;
    localDW->circle_count_m_c = 0.0;
    localDW->is_c5_flightControlSystem = IN_TAKE_OFF;
    localDW->temporalCounter_i1_k = 0U;
    localDW->x_planned = 0.0;
  } else {
    switch (localDW->is_c5_flightControlSystem) {
     case IN_END_MARKER_DETECTED:
      if (localDW->flag_end_marker_to_controller == 1.0) {
        localDW->is_c5_flightControlSystem = IN_LANDING;
        localDW->temporalCounter_i1_k = 0U;
        localDW->x_planned = localDW->x_planned_stored;
      } else {
        localDW->x_planned = localDW->SimplyIntegrateVelocity_DSTATE[0] +
          localDW->linear_part_c;
        localDW->x_planned_stored = localDW->x_planned;
      }
      break;

     case IN_LANDING:
      if ((localDW->temporalCounter_i1_k >= 1000U) && (localDW->u_h == 1.0) &&
          (localDW->circle_count_m_c <= 1.0)) {
        localDW->is_c5_flightControlSystem = IN_LEAVE_MARKER;
      }
      break;

     case IN_LEAVE_MARKER:
      if (rtu_VisionbasedData[2] == 0.0) {
        localDW->is_c5_flightControlSystem = IN_LINE_FOLLOWING;
      } else {
        localDW->x_planned = (localDW->SimplyIntegrateVelocity_DSTATE[0] +
                              localDW->linear_part_c) +
          localDW->sf_derivativeerror.dev_contribute;
        localDW->x_planned_stored = localDW->x_planned;
      }
      break;

     case IN_LINE_FOLLOWING:
      if (rtu_VisionbasedData[2] == 1.0) {
        localDW->is_c5_flightControlSystem = IN_END_MARKER_DETECTED;
        localDW->circle_count_m_c++;
      } else {
        localDW->x_planned = (localDW->SimplyIntegrateVelocity_DSTATE[0] +
                              localDW->linear_part_c) +
          localDW->sf_derivativeerror.dev_contribute;
        localDW->x_planned_stored = localDW->x_planned;
      }
      break;

     default:
      /* case IN_TAKE_OFF: */
      if ((localDW->temporalCounter_i1_k >= 600U) && (localDW->u_h == 1.0)) {
        localDW->is_c5_flightControlSystem = IN_LEAVE_MARKER;
      } else {
        localDW->x_planned = 0.0;
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
   *
   * Block description for '<S252>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S252>/UD':
   *
   *  Store in Global RAM
   */
  localDW->norm_error_tot = localDW->y_error - localDW->UD_DSTATE_i;

  /* MATLAB Function: '<S250>/MATLAB Function' */
  MATLABFunction(localDW->norm_error_tot, (real_T)localDW->i_b,
                 &localDW->sf_MATLABFunction_o);

  /* MATLAB Function: '<S250>/derivative error' incorporates:
   *  Delay: '<S250>/Delay'
   *  Delay: '<S250>/Delay5'
   *  Delay: '<S250>/Delay6'
   */
  derivativeerror(localDW->Delay6_DSTATE_o, localDW->norm_error_tot,
                  localDW->sf_MATLABFunction_o.flag_change_error,
                  localDW->Delay_DSTATE_d, localDW->Delay5_DSTATE_h,
                  &localDW->sf_derivativeerror_c);

  /* Chart: '<S240>/y_linear_contribute' */
  if (localDW->is_active_c24_flightControlSystem == 0U) {
    localDW->is_active_c24_flightControlSystem = 1U;
    localDW->is_c24_flightControlSystem = IN_IDLE;
  } else {
    switch (localDW->is_c24_flightControlSystem) {
     case IN_END_MARKER_DETECTED:
      localDW->linear_part = localDW->y_error * 0.0022;
      break;

     case IN_IDLE:
      if ((rtu_VisionbasedData[2] == 1.0) && (rtu_VisionbasedData[5] == 0.0)) {
        localDW->is_c24_flightControlSystem = IN_TRACK_DETECTED;
      }
      break;

     default:
      /* case IN_TRACK_DETECTED: */
      if ((rtu_VisionbasedData[2] == 1.0) && (rtu_VisionbasedData[5] == 0.0)) {
        localDW->is_c24_flightControlSystem = IN_END_MARKER_DETECTED;
      } else {
        localDW->linear_part = localDW->y_error * 0.0038;
      }
      break;
    }
  }

  /* End of Chart: '<S240>/y_linear_contribute' */

  /* Chart: '<S240>/Chart1' incorporates:
   *  DataTypeConversion: '<S240>/Cast To Double1'
   *  DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity'
   */
  if (localDW->temporalCounter_i1_p < 1023U) {
    localDW->temporalCounter_i1_p++;
  }

  if (localDW->is_active_c21_flightControlSystem == 0U) {
    localDW->is_active_c21_flightControlSystem = 1U;
    localDW->circle_count_k = 0.0;
    localDW->y_planned_stored = 0.0;
    localDW->is_c21_flightControlSystem = IN_TAKE_OFF;
    localDW->temporalCounter_i1_p = 0U;
    localDW->y_planned = 0.0;
  } else {
    switch (localDW->is_c21_flightControlSystem) {
     case IN_END_MARKER_DETECTED:
      if (localDW->flag_end_marker_to_controller == 1.0) {
        localDW->is_c21_flightControlSystem = IN_LANDING;
        localDW->temporalCounter_i1_p = 0U;
        localDW->y_planned = localDW->y_planned_stored;
      } else {
        localDW->y_planned = localDW->SimplyIntegrateVelocity_DSTATE[1] +
          localDW->linear_part;
        localDW->y_planned_stored = localDW->y_planned;
      }
      break;

     case IN_LANDING:
      if ((localDW->temporalCounter_i1_p >= 1000U) && (localDW->u_h == 1.0) &&
          (localDW->circle_count_k <= 1.0)) {
        localDW->is_c21_flightControlSystem = IN_LEAVE_MARKER;
      }
      break;

     case IN_LEAVE_MARKER:
      if (rtu_VisionbasedData[2] == 0.0) {
        localDW->is_c21_flightControlSystem = IN_LINE_FOLLOWING;
      } else {
        localDW->y_planned = (localDW->SimplyIntegrateVelocity_DSTATE[1] +
                              localDW->linear_part) +
          localDW->sf_derivativeerror_c.dev_contribute;
        localDW->y_planned_stored = localDW->y_planned;
      }
      break;

     case IN_LINE_FOLLOWING:
      if (rtu_VisionbasedData[2] == 1.0) {
        localDW->is_c21_flightControlSystem = IN_END_MARKER_DETECTED;
        localDW->circle_count_k++;
      } else {
        localDW->y_planned = (localDW->SimplyIntegrateVelocity_DSTATE[1] +
                              localDW->linear_part) +
          localDW->sf_derivativeerror_c.dev_contribute;
        localDW->y_planned_stored = localDW->y_planned;
      }
      break;

     default:
      /* case IN_TAKE_OFF: */
      if ((localDW->temporalCounter_i1_p >= 600U) && (localDW->u_h == 1.0)) {
        localDW->is_c21_flightControlSystem = IN_LEAVE_MARKER;
      } else {
        localDW->y_planned = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S240>/Chart1' */

  /* Sum: '<S7>/Sum2' incorporates:
   *  DataTypeConversion: '<S257>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion3'
   */
  localDW->pitchrollerror = (real32_T)localDW->z_planned - (real32_T)
    localDW->rtb_Add_idx_0;

  /* Switch: '<S7>/TakeoffOrControl_Switch1' incorporates:
   *  Constant: '<S7>/w1'
   *  DataTypeConversion: '<S257>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S7>/D_z1'
   *  Gain: '<S7>/P_z1'
   *  Gain: '<S7>/takeoff_gain1'
   *  Sum: '<S7>/Sum1'
   */
  if (rtb_Compare_f) {
    localDW->SaturationThrust1 = -0.278113484F;
  } else {
    /* Product: '<S257>/Product1' incorporates:
     *  Concatenate: '<S320>/Vector Concatenate'
     *  SignalConversion generated from: '<S257>/Product1'
     */
    for (localDW->i_b = 0; localDW->i_b < 3; localDW->i_b++) {
      localDW->Sum[localDW->i_b] = localDW->VectorConcatenate[localDW->i_b + 6] *
        localDW->rtb_Add_idx_1 + (localDW->VectorConcatenate[localDW->i_b + 3] *
        localDW->unnamed_idx_1_tmp + localDW->VectorConcatenate[localDW->i_b] *
        localDW->unnamed_idx_0_tmp);
    }

    localDW->SaturationThrust1 = (0.8F * localDW->pitchrollerror +
      localDW->DiscreteTimeIntegrator_DSTATE_d) - 0.5F * (real32_T)localDW->Sum
      [2];
  }

  /* End of Switch: '<S7>/TakeoffOrControl_Switch1' */

  /* Sum: '<S10>/Sum1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  DataTypeConversion: '<S5>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity'
   */
  localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
    (real32_T)localDW->x_planned - localDW->SimplyIntegrateVelocity_DSTATE[0];
  rtb_VectorConcatenate_tmp_tmp = (real32_T)localDW->y_planned -
    localDW->SimplyIntegrateVelocity_DSTATE[1];

  /* Saturate: '<S159>/Saturation' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  localDW->rtb_sincos_o2_a_idx_1 = (rtb_sincos_o2_idx_0_tmp *
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c +
    localDW->rtb_Subtract_p_idx_0_tmp * rtb_VectorConcatenate_tmp_tmp) * 0.7F;
  if (localDW->rtb_sincos_o2_a_idx_1 > 0.5F) {
    localDW->rtb_sincos_o2_a_idx_1 = 0.5F;
  } else if (localDW->rtb_sincos_o2_a_idx_1 < -0.5F) {
    localDW->rtb_sincos_o2_a_idx_1 = -0.5F;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   */
  rtb_Subtract_p_idx_2_tmp = localDW->rtb_sincos_o2_a_idx_1 - localDW->Add_o[0];

  /* Sum: '<S211>/Sum' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  Gain: '<S207>/Proportional Gain'
   */
  rtb_sincos_o2_idx_1_tmp = 0.2F * rtb_Subtract_p_idx_2_tmp +
    localDW->Integrator_DSTATE[0];

  /* Saturate: '<S209>/Saturation' */
  if (rtb_sincos_o2_idx_1_tmp > 0.34906584F) {
    localDW->rtb_sincos_o2_a_idx_1 = 0.34906584F;
  } else if (rtb_sincos_o2_idx_1_tmp < -0.34906584F) {
    localDW->rtb_sincos_o2_a_idx_1 = -0.34906584F;
  } else {
    localDW->rtb_sincos_o2_a_idx_1 = rtb_sincos_o2_idx_1_tmp;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  rtb_Subtract_p_idx_1_tmp = (localDW->rtb_sincos_o2_a_idx_1 - -6.95774698F *
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0])
    / 8.95774746F;
  localDW->Saturation_j = rtb_Subtract_p_idx_1_tmp +
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0];

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   */
  localDW->angularvelocitycompensation[0] = rtb_Subtract_p_idx_2_tmp;

  /* Sum: '<S211>/Sum' */
  localDW->Integrator_a[0] = rtb_sincos_o2_idx_1_tmp;

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->rtb_sincos_o2_a_idx_0 = rtb_Subtract_p_idx_1_tmp;

  /* Saturate: '<S159>/Saturation' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   *  MATLAB Function: '<S10>/Position error transformation (Earth to Body frame)'
   */
  localDW->rtb_sincos_o2_a_idx_1 = (-localDW->rtb_Subtract_p_idx_0_tmp *
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c +
    rtb_sincos_o2_idx_0_tmp * rtb_VectorConcatenate_tmp_tmp) * 0.7F;
  if (localDW->rtb_sincos_o2_a_idx_1 > 0.5F) {
    localDW->rtb_sincos_o2_a_idx_1 = 0.5F;
  } else if (localDW->rtb_sincos_o2_a_idx_1 < -0.5F) {
    localDW->rtb_sincos_o2_a_idx_1 = -0.5F;
  }

  /* Sum: '<S10>/Sum19' incorporates:
   *  Gain: '<S157>/Proportional Gain'
   */
  rtb_Subtract_p_idx_2_tmp = localDW->rtb_sincos_o2_a_idx_1 - localDW->Add_o[1];

  /* Sum: '<S211>/Sum' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  Gain: '<S207>/Proportional Gain'
   */
  rtb_sincos_o2_idx_1_tmp = 0.2F * rtb_Subtract_p_idx_2_tmp +
    localDW->Integrator_DSTATE[1];

  /* Saturate: '<S209>/Saturation' */
  if (rtb_sincos_o2_idx_1_tmp > 0.34906584F) {
    localDW->rtb_sincos_o2_a_idx_1 = 0.34906584F;
  } else if (rtb_sincos_o2_idx_1_tmp < -0.34906584F) {
    localDW->rtb_sincos_o2_a_idx_1 = -0.34906584F;
  } else {
    localDW->rtb_sincos_o2_a_idx_1 = rtb_sincos_o2_idx_1_tmp;
  }

  /* DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  rtb_Subtract_p_idx_1_tmp = (localDW->rtb_sincos_o2_a_idx_1 - -6.95774698F *
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1])
    / 8.95774746F;

  /* Sum: '<S8>/Sum1' incorporates:
   *  DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller'
   *  Gain: '<S10>/Gain'
   *  Gain: '<S55>/Proportional Gain'
   *  Sum: '<S8>/Sum19'
   *  Switch: '<S3>/Switch_refAtt'
   */
  localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
    (-localDW->Saturation_j - localDW->rtb_MathFunction_idx_0) * 4.0F -
    localDW->rtb_Subtract_p_idx_1;
  localDW->rtb_Subtract_p_idx_0 = ((rtb_Subtract_p_idx_1_tmp +
    localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1])
    - localDW->rtb_Integrator_idx_0) * 4.0F - localDW->rtb_Subtract_p_idx_0;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  localDW->rtb_Subtract_p_idx_0_tmp = (0.00012F *
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c -
    localDW->Filter_DSTATE[0]) * 70.0F;

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Gain: '<S94>/Derivative Gain'
   */
  rtb_sincos_o2_idx_0_tmp = (0.003F *
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c +
    localDW->Integrator_DSTATE_n[0]) + localDW->rtb_Subtract_p_idx_0_tmp;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_sincos_o2_idx_0_tmp > 0.02F) {
    rtb_VectorConcatenate_tmp_tmp = 0.02F;
  } else if (rtb_sincos_o2_idx_0_tmp < -0.02F) {
    rtb_VectorConcatenate_tmp_tmp = -0.02F;
  } else {
    rtb_VectorConcatenate_tmp_tmp = rtb_sincos_o2_idx_0_tmp;
  }

  /* Gain: '<S103>/Filter Coefficient' */
  localDW->rtb_MathFunction_idx_0 = localDW->rtb_Subtract_p_idx_0_tmp;

  /* Sum: '<S109>/Sum' */
  localDW->rtb_Integrator_idx_0 = rtb_sincos_o2_idx_0_tmp;

  /* Gain: '<S103>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S95>/Filter'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S95>/SumD'
   */
  localDW->rtb_Subtract_p_idx_0_tmp = (9.72E-5F * localDW->rtb_Subtract_p_idx_0
    - localDW->Filter_DSTATE[1]) * 70.0F;

  /* Sum: '<S109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Gain: '<S94>/Derivative Gain'
   */
  rtb_sincos_o2_idx_0_tmp = (0.00243F * localDW->rtb_Subtract_p_idx_0 +
    localDW->Integrator_DSTATE_n[1]) + localDW->rtb_Subtract_p_idx_0_tmp;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_sincos_o2_idx_0_tmp > 0.02F) {
    rtb_VectorConcatenate_tmp = 0.02F;
  } else if (rtb_sincos_o2_idx_0_tmp < -0.02F) {
    rtb_VectorConcatenate_tmp = -0.02F;
  } else {
    rtb_VectorConcatenate_tmp = rtb_sincos_o2_idx_0_tmp;
  }

  /* Sum: '<S11>/Sum1' incorporates:
   *  BusAssignment: '<S1>/Control Mode Update'
   *  DiscreteIntegrator: '<S325>/Discrete-Time Integrator'
   */
  localDW->Saturation_j = rtu_ReferenceValueServerCmds->orient_ref[0] -
    localDW->DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<S11>/Saturation' */
  if (localDW->Saturation_j > 0.52359879F) {
    localDW->Saturation_j = 0.52359879F;
  } else if (localDW->Saturation_j < -0.52359879F) {
    localDW->Saturation_j = -0.52359879F;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Saturate: '<S7>/SaturationThrust1' incorporates:
   *  Constant: '<S7>/w1'
   *  Sum: '<S7>/Sum5'
   */
  if (localDW->SaturationThrust1 + -0.61803F > 1.20204329F) {
    localDW->rtb_Subtract_p_idx_1 = 1.20204329F;
  } else if (localDW->SaturationThrust1 + -0.61803F < -1.20204329F) {
    localDW->rtb_Subtract_p_idx_1 = -1.20204329F;
  } else {
    localDW->rtb_Subtract_p_idx_1 = localDW->SaturationThrust1 + -0.61803F;
  }

  /* SignalConversion generated from: '<S9>/Product' incorporates:
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Gain: '<S11>/D_yaw'
   *  Gain: '<S11>/P_yaw'
   *  Sum: '<S11>/Sum2'
   *  Sum: '<S258>/Subtract'
   */
  localDW->SaturationThrust1 = (0.004F * localDW->Saturation_j +
    localDW->DiscreteTimeIntegrator_DSTATE_p) - 0.0012F * localDW->r;
  for (localDW->i_b = 0; localDW->i_b < 4; localDW->i_b++) {
    /* Saturate: '<S12>/Saturation5' incorporates:
     *  Constant: '<S9>/Pitch correction'
     *  Constant: '<S9>/TorqueTotalThrustToThrustPerMotor'
     *  Gain: '<S12>/ThrustToMotorCommand'
     *  Product: '<S9>/Product'
     *  Saturate: '<S107>/Saturation'
     *  Saturate: '<S7>/SaturationThrust1'
     *  Sum: '<S9>/Add'
     */
    localDW->rtb_sincos_o2_a_idx_1 = -1530.72681F *
      (rtConstP.TorqueTotalThrustToThrustPerMotor_Value[localDW->i_b + 12] *
       rtb_VectorConcatenate_tmp +
       (rtConstP.TorqueTotalThrustToThrustPerMotor_Value[localDW->i_b + 8] *
        (rtb_VectorConcatenate_tmp_tmp + 0.002F) +
        (rtConstP.TorqueTotalThrustToThrustPerMotor_Value[localDW->i_b + 4] *
         localDW->SaturationThrust1 +
         rtConstP.TorqueTotalThrustToThrustPerMotor_Value[localDW->i_b] *
         localDW->rtb_Subtract_p_idx_1)));
    if (localDW->rtb_sincos_o2_a_idx_1 > 500.0F) {
      localDW->rtb_sincos_o2_a_idx_1 = 500.0F;
    } else if (localDW->rtb_sincos_o2_a_idx_1 < 10.0F) {
      localDW->rtb_sincos_o2_a_idx_1 = 10.0F;
    }

    /* End of Saturate: '<S12>/Saturation5' */

    /* Gain: '<S12>/MotorDirections' */
    localDW->MotorDirections[localDW->i_b] =
      rtConstP.MotorDirections_Gain[localDW->i_b] *
      localDW->rtb_sincos_o2_a_idx_1;
  }

  /* Sum: '<S257>/Sum' incorporates:
   *  Concatenate: '<S320>/Vector Concatenate'
   *  Constant: '<S257>/gravity'
   *  DiscreteFir: '<S259>/FIR_IMUaccel'
   *  Math: '<S257>/Math Function'
   *  Product: '<S257>/Product'
   */
  for (localDW->i_b = 0; localDW->i_b < 3; localDW->i_b++) {
    localDW->Sum[localDW->i_b] = ((localDW->VectorConcatenate[3 * localDW->i_b +
      1] * localDW->FIR_IMUaccel[1] + localDW->VectorConcatenate[3 *
      localDW->i_b] * localDW->FIR_IMUaccel[0]) + localDW->VectorConcatenate[3 *
      localDW->i_b + 2] * localDW->pressureFilter_IIR_tmp) +
      rtConstP.gravity_Value_j[localDW->i_b];
  }

  /* End of Sum: '<S257>/Sum' */

  /* Outputs for Enabled SubSystem: '<S283>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S313>/Enable'
   */
  if (rtb_Compare_fl) {
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
    localDW->u_h = -(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude -
      ((0.0 * localDW->MemoryX_DSTATE[1] + localDW->MemoryX_DSTATE[0]) + 0.0 *
       localDW->Sum[2]);

    /* Product: '<S313>/Product3' */
    localDW->Product3[0] = 0.026590304322229058 * localDW->u_h;
    localDW->Product3[1] = 0.06977673607149236 * localDW->u_h;
  } else if (localDW->MeasurementUpdate_MODE_h) {
    /* Disable for Product: '<S313>/Product3' incorporates:
     *  Outport: '<S313>/L*(y[k]-yhat[k|k-1])'
     */
    localDW->Product3[0] = 0.0;
    localDW->Product3[1] = 0.0;
    localDW->MeasurementUpdate_MODE_h = false;
  }

  /* End of Outputs for SubSystem: '<S283>/MeasurementUpdate' */

  /* DataTypeConversion: '<S424>/Conversion' incorporates:
   *  DataTypeConversion: '<S370>/Conversion'
   */
  localDW->Saturation[0] = 0.00118709437F;
  localDW->Saturation[1] = -3.28681635E-5F;

  /* Outputs for Enabled SubSystem: '<S401>/MeasurementUpdate' */
  /* DataTypeConversion: '<S381>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S381>/C'
   *  Constant: '<S381>/D'
   *  DataTypeConversion: '<S424>/Conversion'
   */
  MeasurementUpdate(rtb_LogicalOperator != 0, localDW->Saturation,
                    localDW->TrigonometricFunction, rtConstP.pooled19,
                    localDW->MemoryX_g, 0.0F, localDW->p,
                    &localDW->MeasurementUpdate_j);

  /* End of Outputs for SubSystem: '<S401>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S347>/MeasurementUpdate' */
  /* DataTypeConversion: '<S327>/DataTypeConversionEnable' incorporates:
   *  Constant: '<S327>/C'
   *  Constant: '<S327>/D'
   */
  MeasurementUpdate(rtb_LogicalOperator != 0, localDW->Saturation,
                    localDW->TrigonometricFunction1, rtConstP.pooled19,
                    localDW->MemoryX_e, 0.0F, localDW->q,
                    &localDW->MeasurementUpdate_n);

  /* End of Outputs for SubSystem: '<S347>/MeasurementUpdate' */

  /* DeadZone: '<S93>/DeadZone' incorporates:
   *  Gain: '<S91>/ZeroGain'
   */
  if (localDW->rtb_Integrator_idx_0 > 0.02F) {
    localDW->pressureFilter_IIR_tmp = localDW->rtb_Integrator_idx_0 - 0.02F;
  } else if (localDW->rtb_Integrator_idx_0 >= -0.02F) {
    localDW->pressureFilter_IIR_tmp = 0.0F;
  } else {
    localDW->pressureFilter_IIR_tmp = localDW->rtb_Integrator_idx_0 - -0.02F;
  }

  /* Gain: '<S97>/Integral Gain' */
  localDW->TrigonometricFunction = 0.006F *
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c;

  /* Gain: '<S193>/ZeroGain' */
  localDW->MemoryX_g[0] = 0.0F * localDW->Integrator_a[0];

  /* DeadZone: '<S195>/DeadZone' incorporates:
   *  Gain: '<S193>/ZeroGain'
   */
  if (localDW->Integrator_a[0] > 0.34906584F) {
    localDW->rtb_sincos_o2_a_idx_1 = localDW->Integrator_a[0] - 0.34906584F;
    localDW->Integrator_a[0] -= 0.34906584F;
  } else {
    if (localDW->Integrator_a[0] >= -0.34906584F) {
      localDW->rtb_sincos_o2_a_idx_1 = 0.0F;
    } else {
      localDW->rtb_sincos_o2_a_idx_1 = localDW->Integrator_a[0] - -0.34906584F;
    }

    if (localDW->Integrator_a[0] >= -0.34906584F) {
      localDW->Integrator_a[0] = 0.0F;
    } else {
      localDW->Integrator_a[0] -= -0.34906584F;
    }
  }

  /* Gain: '<S199>/Integral Gain' */
  localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
    0.1F * localDW->angularvelocitycompensation[0];
  localDW->angularvelocitycompensation[0] *= 0.1F;

  /* DeadZone: '<S93>/DeadZone' */
  if (rtb_sincos_o2_idx_0_tmp > 0.02F) {
    localDW->TrigonometricFunction1 = rtb_sincos_o2_idx_0_tmp - 0.02F;
  } else if (rtb_sincos_o2_idx_0_tmp >= -0.02F) {
    localDW->TrigonometricFunction1 = 0.0F;
  } else {
    localDW->TrigonometricFunction1 = rtb_sincos_o2_idx_0_tmp - -0.02F;
  }

  /* Gain: '<S97>/Integral Gain' */
  localDW->rtb_Subtract_p_idx_0 *= 0.00486F;

  /* DeadZone: '<S195>/DeadZone' */
  if (rtb_sincos_o2_idx_1_tmp > 0.34906584F) {
    localDW->Integrator_a[1] = rtb_sincos_o2_idx_1_tmp - 0.34906584F;
  } else if (rtb_sincos_o2_idx_1_tmp >= -0.34906584F) {
    localDW->Integrator_a[1] = 0.0F;
  } else {
    localDW->Integrator_a[1] = rtb_sincos_o2_idx_1_tmp - -0.34906584F;
  }

  /* Gain: '<S199>/Integral Gain' */
  localDW->angularvelocitycompensation[1] = 0.1F * rtb_Subtract_p_idx_2_tmp;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/ '
   *  Constant: '<S4>/    '
   *  DataTypeConversion: '<S257>/Data Type Conversion'
   *  RelationalOperator: '<S4>/GreaterThan'
   *  Sum: '<S4>/Difference between  sonar and pressure'
   *  Switch: '<S4>/         '
   *  UnitDelay: '<S227>/Output'
   */
  if (localDW->Output_DSTATE_g > 600U) {
    localDW->u_h = rtu_Sensors->VisionSensors.opticalFlow_data[2];
    localDW->rtb_Add_idx_1 = rtu_Sensors->VisionSensors.opticalFlow_data[2];
    localDW->pressureFilter_IIR = (real32_T)localDW->rtb_Add_idx_0 -
      localDW->pressureFilter_IIR;
  } else {
    localDW->u_h = 0.0;
    localDW->rtb_Add_idx_1 = 0.0;
    localDW->pressureFilter_IIR = 0.0F;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S220>/Constant'
   *  DataTypeConversion: '<S4>/   '
   *  Delay: '<S4>/Delay One Step'
   *  Product: '<S4>/  '
   *  RelationalOperator: '<S220>/Compare'
   */
  localDW->u_h = (real_T)(localDW->rtb_Add_idx_1 == -1.0) *
    localDW->DelayOneStep_DSTATE + (real_T)(localDW->u_h == -1.0);

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
   *  DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity'
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
  if (((real32_T)fabs(localDW->SimplyIntegrateVelocity_DSTATE[0]) > 10.0F) ||
      ((real32_T)fabs(localDW->SimplyIntegrateVelocity_DSTATE[1]) > 10.0F)) {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S228>/Action Port'
     */
    /* Merge: '<S4>/Merge' incorporates:
     *  Constant: '<S228>/Constant'
     *  SignalConversion generated from: '<S228>/Out1'
     */
    localDW->Merge = 1U;

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */
  } else if ((((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]) >
               0.01F) && ((real32_T)fabs
                          (rtu_Sensors->VisionSensors.opticalFlow_data[0] -
                localDW->Add_o[0]) > 6.0F)) || (((real32_T)fabs
               (rtu_Sensors->VisionSensors.opticalFlow_data[1] - localDW->Add_o
                [1]) > 6.0F) && ((real32_T)fabs
               (rtu_Sensors->VisionSensors.opticalFlow_data[1]) > 0.01F))) {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S232>/Action Port'
     */
    /* Merge: '<S4>/Merge' incorporates:
     *  Constant: '<S232>/Constant'
     *  SignalConversion generated from: '<S232>/Out1'
     */
    localDW->Merge = 99U;

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else if (localDW->u_h > 50.0) {
    /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
     *  ActionPort: '<S229>/Action Port'
     */
    Noopticalflow(&localDW->Merge);

    /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
  } else if ((real32_T)fabs(localDW->pressureFilter_IIR) > 0.5F) {
    /* Outputs for IfAction SubSystem: '<S4>/Ultrasound improper' incorporates:
     *  ActionPort: '<S231>/Action Port'
     */
    Noopticalflow(&localDW->Merge);

    /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/Normal condition' incorporates:
     *  ActionPort: '<S230>/Action Port'
     */
    Noopticalflow(&localDW->Merge);

    /* End of Outputs for SubSystem: '<S4>/Normal condition' */
  }

  /* End of If: '<S4>/If' */

  /* Update for DiscreteIntegrator: '<S325>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE += 0.005F * localDW->r;

  /* Update for Delay: '<S327>/MemoryX' */
  localDW->icLoad = false;

  /* Product: '<S347>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S327>/A'
   *  Delay: '<S327>/MemoryX'
   */
  localDW->rtb_Subtract_p_idx_1 = -0.005F * localDW->MemoryX_DSTATE_g[1] +
    localDW->MemoryX_DSTATE_g[0];
  localDW->SaturationThrust1 = 0.0F * localDW->MemoryX_DSTATE_g[0] +
    localDW->MemoryX_DSTATE_g[1];

  /* Update for Delay: '<S327>/MemoryX' incorporates:
   *  Constant: '<S327>/B'
   *  Product: '<S347>/B[k]*u[k]'
   *  Product: '<S378>/Product3'
   *  Sum: '<S347>/Add'
   */
  localDW->MemoryX_DSTATE_g[0] = (0.005F * localDW->q +
    localDW->rtb_Subtract_p_idx_1) + localDW->MeasurementUpdate_n.Product3[0];
  localDW->MemoryX_DSTATE_g[1] = (0.0F * localDW->q + localDW->SaturationThrust1)
    + localDW->MeasurementUpdate_n.Product3[1];

  /* Update for DiscreteFir: '<S259>/FIR_IMUaccel' */
  /* Update circular buffer index */
  localDW->FIR_IMUaccel_circBuf--;
  if (localDW->FIR_IMUaccel_circBuf < 0) {
    localDW->FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf] =
    localDW->inverseIMU_gain_idx_0;
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 5] =
    localDW->inverseIMU_gain_idx_1;
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 10] =
    localDW->inverseIMU_gain_idx_2;

  /* End of Update for DiscreteFir: '<S259>/FIR_IMUaccel' */

  /* Update for Delay: '<S381>/MemoryX' */
  localDW->icLoad_k = false;

  /* Product: '<S401>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S381>/A'
   *  Delay: '<S381>/MemoryX'
   */
  localDW->rtb_Subtract_p_idx_1 = -0.005F * localDW->MemoryX_DSTATE_m[1] +
    localDW->MemoryX_DSTATE_m[0];
  localDW->SaturationThrust1 = 0.0F * localDW->MemoryX_DSTATE_m[0] +
    localDW->MemoryX_DSTATE_m[1];

  /* Update for Delay: '<S381>/MemoryX' incorporates:
   *  Constant: '<S381>/B'
   *  Product: '<S401>/B[k]*u[k]'
   *  Product: '<S432>/Product3'
   *  Sum: '<S401>/Add'
   */
  localDW->MemoryX_DSTATE_m[0] = (0.005F * localDW->p +
    localDW->rtb_Subtract_p_idx_1) + localDW->MeasurementUpdate_j.Product3[0];
  localDW->MemoryX_DSTATE_m[1] = (0.0F * localDW->p + localDW->SaturationThrust1)
    + localDW->MeasurementUpdate_j.Product3[1];

  /* Update for UnitDelay: '<S520>/Output' incorporates:
   *  Constant: '<S521>/FixPt Constant'
   *  Sum: '<S521>/FixPt Sum1'
   */
  localDW->Output_DSTATE++;

  /* Update for Delay: '<S257>/Delay2' */
  localDW->Delay2_DSTATE = localDW->rtb_Add_idx_0;

  /* Update for Delay: '<S261>/MemoryX' */
  localDW->icLoad_c = false;

  /* Product: '<S283>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S261>/A'
   *  Delay: '<S261>/MemoryX'
   */
  localDW->rtb_Add_idx_0 = 0.005 * localDW->MemoryX_DSTATE[1] +
    localDW->MemoryX_DSTATE[0];
  localDW->rtb_Add_idx_1 = 0.0 * localDW->MemoryX_DSTATE[0] +
    localDW->MemoryX_DSTATE[1];

  /* Update for Delay: '<S261>/MemoryX' incorporates:
   *  Constant: '<S261>/B'
   *  Product: '<S283>/B[k]*u[k]'
   *  Product: '<S313>/Product3'
   *  Sum: '<S283>/Add'
   */
  localDW->MemoryX_DSTATE[0] = (0.0 * localDW->Sum[2] + localDW->rtb_Add_idx_0)
    + localDW->Product3[0];

  /* Update for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = localDW->pressureFilter_IIR_states[1];

  /* Update for Delay: '<S261>/MemoryX' incorporates:
   *  Constant: '<S261>/B'
   *  Product: '<S283>/B[k]*u[k]'
   *  Product: '<S313>/Product3'
   *  Sum: '<S283>/Add'
   */
  localDW->MemoryX_DSTATE[1] = (0.005 * localDW->Sum[2] + localDW->rtb_Add_idx_1)
    + localDW->Product3[1];

  /* Update for DiscreteFilter: '<S262>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = localDW->pressureFilter_IIR_states[0];
  localDW->pressureFilter_IIR_states[0] = localDW->rtb_VectorConcatenate_tmp;

  /* Update for DiscreteFilter: '<S262>/sonarFilter_IIR' */
  localDW->sonarFilter_IIR_states[2] = localDW->sonarFilter_IIR_states[1];
  localDW->sonarFilter_IIR_states[1] = localDW->sonarFilter_IIR_states[0];
  localDW->sonarFilter_IIR_states[0] = localDW->sonarFilter_IIR_tmp;

  /* Update for DiscreteTransferFcn: '<S259>/LPF Fcutoff = 40Hz1' */
  localDW->LPFFcutoff40Hz1_states = localDW->altfrompress;

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
  localDW->Output_DSTATE_i++;
  for (localDW->cff = 0; localDW->cff < 2; localDW->cff++) {
    /* Update for DiscreteFilter: '<S446>/IIRgyroz' */
    localDW->i = localDW->cff * 5;
    localDW->IIRgyroz_states[localDW->i + 4] = localDW->IIRgyroz_states
      [localDW->i + 3];
    localDW->IIRgyroz_states[localDW->i + 3] = localDW->IIRgyroz_states
      [localDW->i + 2];
    localDW->IIRgyroz_states[localDW->i + 2] = localDW->IIRgyroz_states
      [localDW->i + 1];
    localDW->IIRgyroz_states[localDW->i + 1] = localDW->IIRgyroz_states
      [localDW->i];
    localDW->IIRgyroz_states[localDW->i] = localDW->IIRgyroz_tmp[localDW->cff];

    /* Update for UnitDelay: '<S454>/UD'
     *
     * Block description for '<S454>/UD':
     *
     *  Store in Global RAM
     */
    localDW->UD_DSTATE_k[localDW->cff] =
      localDW->TmpSignalConversionAtIIRgyrozInport1[localDW->cff];

    /* Update for Delay: '<S442>/Delay' */
    localDW->Delay_DSTATE_a[localDW->cff] = localDW->Add_o[localDW->cff];
  }

  /* Update for Delay: '<S447>/MemoryX' */
  localDW->icLoad_o = false;
  for (localDW->i_b = 0; localDW->i_b < 4; localDW->i_b++) {
    /* Product: '<S485>/B[k]*u[k]' incorporates:
     *  Constant: '<S447>/B'
     */
    localDW->fv[localDW->i_b] = rtConstP.B_Value_f[localDW->i_b + 4] *
      localDW->rtb_Product_idx_1 + rtConstP.B_Value_f[localDW->i_b] *
      localDW->rtb_Product_idx_0;

    /* Product: '<S485>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S447>/A'
     *  Delay: '<S447>/MemoryX'
     */
    localDW->fv1[localDW->i_b] = rtConstP.A_Value_a[localDW->i_b + 12] *
      localDW->MemoryX_DSTATE_l[3] + (rtConstP.A_Value_a[localDW->i_b + 8] *
      localDW->MemoryX_DSTATE_l[2] + (rtConstP.A_Value_a[localDW->i_b + 4] *
      localDW->MemoryX_DSTATE_l[1] + rtConstP.A_Value_a[localDW->i_b] *
      localDW->MemoryX_DSTATE_l[0]));
  }

  /* Update for Delay: '<S447>/MemoryX' incorporates:
   *  Sum: '<S485>/Add'
   */
  localDW->MemoryX_DSTATE_l[0] = (localDW->fv[0] + localDW->fv1[0]) +
    localDW->Product3_a[0];
  localDW->MemoryX_DSTATE_l[1] = (localDW->fv[1] + localDW->fv1[1]) +
    localDW->Product3_a[1];
  localDW->MemoryX_DSTATE_l[2] = (localDW->fv[2] + localDW->fv1[2]) +
    localDW->Product3_a[2];
  localDW->MemoryX_DSTATE_l[3] = (localDW->fv[3] + localDW->fv1[3]) +
    localDW->Product3_a[3];

  /* Update for UnitDelay: '<S14>/Output' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  Sum: '<S15>/FixPt Sum1'
   */
  localDW->Output_DSTATE_h++;

  /* Update for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE_p[0] = localDW->Add_o[0];
  localDW->Delay1_DSTATE_p[1] = localDW->Add_o[1];

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S7>/I_pr'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_d += 0.24F * localDW->pitchrollerror *
    0.005F;
  if (localDW->DiscreteTimeIntegrator_DSTATE_d >= 2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_d = 2.0F;
  } else if (localDW->DiscreteTimeIntegrator_DSTATE_d <= -2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_d = -2.0F;
  }

  localDW->DiscreteTimeIntegrator_PrevResetState = (int8_T)rtb_Compare_f;

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */

  /* Update for Delay: '<S244>/Delay6' */
  localDW->Delay6_DSTATE = localDW->sf_derivativeerror.dev_contribute;

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
   *
   * Block description for '<S246>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE = localDW->x_error;

  /* Update for Delay: '<S244>/Delay' */
  localDW->Delay_DSTATE = localDW->sf_derivativeerror.count;

  /* Update for Delay: '<S244>/Delay5' */
  localDW->Delay5_DSTATE = localDW->sf_derivativeerror.flag_count;

  /* Update for Delay: '<S241>/Delay1' incorporates:
   *  MATLAB Function: '<S241>/MATLAB Function'
   */
  localDW->Delay1_DSTATE[0] = localDW->Delay1_DSTATE[1];
  localDW->Delay1_DSTATE[1] = localDW->Delay1_DSTATE[2];
  localDW->Delay1_DSTATE[2] = localDW->Delay1_DSTATE[3];
  localDW->Delay1_DSTATE[3] = localDW->Diff;

  /* SignalConversion generated from: '<S443>/Product' */
  localDW->inverseIMU_gain_idx_0 = localDW->Add_o[0];
  localDW->inverseIMU_gain_idx_1 = localDW->Add_o[1];

  /* Product: '<S443>/Product' incorporates:
   *  Math: '<S443>/Math Function'
   *  SignalConversion generated from: '<S443>/Product'
   */
  for (localDW->i_b = 0; localDW->i_b < 3; localDW->i_b++) {
    localDW->FIR_IMUaccel[localDW->i_b] = localDW->MathFunction_a[localDW->i_b +
      6] * localDW->DataTypeConversion2 + (localDW->MathFunction_a[localDW->i_b
      + 3] * localDW->inverseIMU_gain_idx_1 + localDW->MathFunction_a
      [localDW->i_b] * localDW->inverseIMU_gain_idx_0);
  }

  /* End of Product: '<S443>/Product' */

  /* Update for DiscreteIntegrator: '<S443>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  localDW->SimplyIntegrateVelocity_DSTATE[0] += 0.005F * localDW->FIR_IMUaccel[0];
  localDW->SimplyIntegrateVelocity_DSTATE[1] += 0.005F * localDW->FIR_IMUaccel[1];
  localDW->SimplyIntegrateVelocity_PrevResetState = 1;

  /* Update for Delay: '<S250>/Delay6' */
  localDW->Delay6_DSTATE_o = localDW->sf_derivativeerror_c.dev_contribute;

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
   *
   * Block description for '<S252>/UD':
   *
   *  Store in Global RAM
   */
  localDW->UD_DSTATE_i = localDW->y_error;

  /* Update for Delay: '<S250>/Delay' */
  localDW->Delay_DSTATE_d = localDW->sf_derivativeerror_c.count;

  /* Update for Delay: '<S250>/Delay5' */
  localDW->Delay5_DSTATE_h = localDW->sf_derivativeerror_c.flag_count;

  /* Signum: '<S193>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  RelationalOperator: '<S193>/NotEqual'
   */
  if (localDW->Integrator_a[0] < 0.0F) {
    localDW->inverseIMU_gain_idx_0 = -1.0F;
  } else if (localDW->Integrator_a[0] > 0.0F) {
    localDW->inverseIMU_gain_idx_0 = 1.0F;
  } else if (localDW->Integrator_a[0] == 0.0F) {
    localDW->inverseIMU_gain_idx_0 = 0.0F;
  } else {
    localDW->inverseIMU_gain_idx_0 = (rtNaNF);
  }

  /* Signum: '<S193>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   */
  if (localDW->angularvelocitycompensation[0] < 0.0F) {
    localDW->inverseIMU_gain_idx_1 = -1.0F;
  } else if (localDW->angularvelocitycompensation[0] > 0.0F) {
    localDW->inverseIMU_gain_idx_1 = 1.0F;
  } else if (localDW->angularvelocitycompensation[0] == 0.0F) {
    localDW->inverseIMU_gain_idx_1 = 0.0F;
  } else {
    localDW->inverseIMU_gain_idx_1 = (rtNaNF);
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
  if ((localDW->MemoryX_g[0] != localDW->rtb_sincos_o2_a_idx_1) && ((int8_T)
       localDW->inverseIMU_gain_idx_0 == (int8_T)localDW->inverseIMU_gain_idx_1))
  {
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
      0.0F;
  }

  /* Update for DiscreteIntegrator: '<S202>/Integrator' */
  localDW->Integrator_DSTATE[0] += 0.005F *
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c;

  /* Update for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[0] =
    localDW->rtb_sincos_o2_a_idx_0;

  /* Signum: '<S91>/SignPreSat' */
  if (localDW->pressureFilter_IIR_tmp < 0.0F) {
    localDW->inverseIMU_gain_idx_0 = -1.0F;
  } else if (localDW->pressureFilter_IIR_tmp > 0.0F) {
    localDW->inverseIMU_gain_idx_0 = 1.0F;
  } else if (localDW->pressureFilter_IIR_tmp == 0.0F) {
    localDW->inverseIMU_gain_idx_0 = 0.0F;
  } else {
    localDW->inverseIMU_gain_idx_0 = (rtNaNF);
  }

  /* Signum: '<S91>/SignPreIntegrator' */
  if (localDW->TrigonometricFunction < 0.0F) {
    localDW->inverseIMU_gain_idx_1 = -1.0F;
  } else if (localDW->TrigonometricFunction > 0.0F) {
    localDW->inverseIMU_gain_idx_1 = 1.0F;
  } else if (localDW->TrigonometricFunction == 0.0F) {
    localDW->inverseIMU_gain_idx_1 = 0.0F;
  } else {
    localDW->inverseIMU_gain_idx_1 = (rtNaNF);
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
  if ((0.0F * localDW->rtb_Integrator_idx_0 != localDW->pressureFilter_IIR_tmp) &&
      ((int8_T)localDW->inverseIMU_gain_idx_0 == (int8_T)
       localDW->inverseIMU_gain_idx_1)) {
    localDW->TrigonometricFunction = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_n[0] += 0.005F * localDW->TrigonometricFunction;

  /* Update for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[0] += 0.005F * localDW->rtb_MathFunction_idx_0;

  /* DeadZone: '<S195>/DeadZone' */
  if (rtb_sincos_o2_idx_1_tmp > 0.34906584F) {
    localDW->rtb_sincos_o2_a_idx_1 = rtb_sincos_o2_idx_1_tmp - 0.34906584F;
  } else if (rtb_sincos_o2_idx_1_tmp >= -0.34906584F) {
    localDW->rtb_sincos_o2_a_idx_1 = 0.0F;
  } else {
    localDW->rtb_sincos_o2_a_idx_1 = rtb_sincos_o2_idx_1_tmp - -0.34906584F;
  }

  /* Signum: '<S193>/SignPreSat' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  RelationalOperator: '<S193>/NotEqual'
   */
  if (localDW->Integrator_a[1] < 0.0F) {
    localDW->inverseIMU_gain_idx_0 = -1.0F;
  } else if (localDW->Integrator_a[1] > 0.0F) {
    localDW->inverseIMU_gain_idx_0 = 1.0F;
  } else if (localDW->Integrator_a[1] == 0.0F) {
    localDW->inverseIMU_gain_idx_0 = 0.0F;
  } else {
    localDW->inverseIMU_gain_idx_0 = (rtNaNF);
  }

  /* Signum: '<S193>/SignPreIntegrator' incorporates:
   *  DiscreteIntegrator: '<S202>/Integrator'
   */
  if (localDW->angularvelocitycompensation[1] < 0.0F) {
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
      -1.0F;
  } else if (localDW->angularvelocitycompensation[1] > 0.0F) {
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
      1.0F;
  } else if (localDW->angularvelocitycompensation[1] == 0.0F) {
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
      0.0F;
  } else {
    localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c =
      (rtNaNF);
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
  if ((0.0F * rtb_sincos_o2_idx_1_tmp != localDW->rtb_sincos_o2_a_idx_1) &&
      ((int8_T)localDW->inverseIMU_gain_idx_0 == (int8_T)
       localDW->rtb_LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncon_c))
  {
    localDW->rtb_MathFunction_idx_0 = 0.0F;
  } else {
    localDW->rtb_MathFunction_idx_0 = 0.1F * rtb_Subtract_p_idx_2_tmp;
  }

  /* Update for DiscreteIntegrator: '<S202>/Integrator' */
  localDW->Integrator_DSTATE[1] += 0.005F * localDW->rtb_MathFunction_idx_0;

  /* Update for DiscreteTransferFcn: '<S10>/LPF 8Hz Cutoff Filter to avoid oscillations  induced by position controller' */
  localDW->LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle[1] =
    rtb_Subtract_p_idx_1_tmp;

  /* Signum: '<S91>/SignPreSat' */
  if (localDW->TrigonometricFunction1 < 0.0F) {
    localDW->pressureFilter_IIR_tmp = -1.0F;
  } else if (localDW->TrigonometricFunction1 > 0.0F) {
    localDW->pressureFilter_IIR_tmp = 1.0F;
  } else if (localDW->TrigonometricFunction1 == 0.0F) {
    localDW->pressureFilter_IIR_tmp = 0.0F;
  } else {
    localDW->pressureFilter_IIR_tmp = (rtNaNF);
  }

  /* Signum: '<S91>/SignPreIntegrator' */
  if (localDW->rtb_Subtract_p_idx_0 < 0.0F) {
    localDW->inverseIMU_gain_idx_1 = -1.0F;
  } else if (localDW->rtb_Subtract_p_idx_0 > 0.0F) {
    localDW->inverseIMU_gain_idx_1 = 1.0F;
  } else if (localDW->rtb_Subtract_p_idx_0 == 0.0F) {
    localDW->inverseIMU_gain_idx_1 = 0.0F;
  } else {
    localDW->inverseIMU_gain_idx_1 = (rtNaNF);
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
  if ((0.0F * rtb_sincos_o2_idx_0_tmp != localDW->TrigonometricFunction1) &&
      ((int8_T)localDW->pressureFilter_IIR_tmp == (int8_T)
       localDW->inverseIMU_gain_idx_1)) {
    localDW->rtb_Subtract_p_idx_0 = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S100>/Integrator' */
  localDW->Integrator_DSTATE_n[1] += 0.005F * localDW->rtb_Subtract_p_idx_0;

  /* Update for DiscreteIntegrator: '<S95>/Filter' */
  localDW->Filter_DSTATE[1] += 0.005F * localDW->rtb_Subtract_p_idx_0_tmp;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S11>/I_yaw'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_p += 0.002F * localDW->Saturation_j *
    0.005F;

  /* Update for UnitDelay: '<S227>/Output' incorporates:
   *  Constant: '<S233>/FixPt Constant'
   *  Sum: '<S233>/FixPt Sum1'
   */
  localDW->Output_DSTATE_g++;

  /* Update for Delay: '<S4>/Delay One Step' */
  localDW->DelayOneStep_DSTATE = localDW->u_h;
}

static void SystemCore_step(const uint8_T varargin_1[38400], uint8_T
  varargout_1[19200], uint8_T varargout_2[19200], uint8_T varargout_3[19200])
{
  MW_Build_RGB(&varargin_1[0], &varargout_1[0], &varargout_2[0], &varargout_3[0]);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Waypoints' */
static real_T mod(real_T x)
{
  real_T q;
  real_T r;
  boolean_T rEQ0;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 6.2831853071795862);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      q = fabs(x / 6.2831853071795862);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 6.2831853071795862;
    }
  }

  return r;
}

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition' */
  rtDW.i = rtDW.RateTransition_ActiveBufIdx * 6;
  for (rtDW.i1 = 0; rtDW.i1 < 6; rtDW.i1++) {
    rtDW.RateTransition[rtDW.i1] = rtDW.RateTransition_Buffer[rtDW.i1 + rtDW.i];
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Outputs for Atomic SubSystem: '<Root>/Control System' */
  /* Inport: '<Root>/AC cmd ' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  ControlSystem(&cmd_inport, &sensor_inport, rtDW.RateTransition,
                &rtDW.ControlSystem_o, &rtPrevZCX.ControlSystem_o);

  /* End of Outputs for SubSystem: '<Root>/Control System' */

  /* SignalConversion generated from: '<Root>/Control System' */
  motors_outport[0] = rtDW.ControlSystem_o.MotorDirections[0];
  motors_outport[1] = rtDW.ControlSystem_o.MotorDirections[1];
  motors_outport[2] = rtDW.ControlSystem_o.MotorDirections[2];
  motors_outport[3] = rtDW.ControlSystem_o.MotorDirections[3];

  /* SignalConversion generated from: '<Root>/Control System' */
  flag_outport = rtDW.ControlSystem_o.Merge;
}

/* Model step function for TID1 */
void flightControlSystem_step1(void)   /* Sample time: [0.2s, 0.0s] */
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
  SystemCore_step(imRGB, rtDW.b_varargout_1, rtDW.b_varargout_2,
                  rtDW.b_varargout_3);

  /* MATLAB Function: '<S2>/Image Binarization' incorporates:
   *  MATLABSystem: '<S2>/PARROT Image Conversion'
   */
  for (i = 0; i < 19200; i++) {
    b_varargout_2 = (uint8_T)(int32_T)rt_roundd_snf((real_T)rtDW.b_varargout_3[i]
      / 2.0);
    ky = rtDW.b_varargout_1[i];
    qY_0 = (uint32_T)ky - /*MW:OvSatOk*/ (uint8_T)(int32_T)rt_roundd_snf((real_T)
      rtDW.b_varargout_2[i] / 2.0);
    if (qY_0 > (uint32_T)ky) {
      qY_0 = 0U;
    }

    qY = qY_0 - /*MW:OvSatOk*/ b_varargout_2;
    if (qY > qY_0) {
      qY = 0U;
    }

    rtDW.binarized_frame[i] = ((int32_T)qY >= 80);
    rtDW.b_varargout_2[i] = b_varargout_2;
  }

  /* End of MATLAB Function: '<S2>/Image Binarization' */

  /* S-Function (svipmorphop): '<S2>/Erosion for landing mark' */
  ky = 0;
  ku = 0;
  for (i = 0; i < 9; i++) {
    for (m = 0; m < 145; m++) {
      rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky] = true;
      ky++;
    }
  }

  for (i = 0; i < 160; i++) {
    for (m = 0; m < 9; m++) {
      rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky] = true;
      ky++;
    }

    memcpy(&rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky],
           &rtDW.binarized_frame[ku], 120U * sizeof(boolean_T));
    ky += 120;
    ku += 120;
    for (m = 0; m < 16; m++) {
      rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky] = true;
      ky++;
    }
  }

  for (i = 0; i < 16; i++) {
    for (m = 0; m < 145; m++) {
      rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[ky] = true;
      ky++;
    }
  }

  for (i = 0; i < 26825; i++) {
    rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[i] = true;
  }

  bufIdx = 0;
  for (ky = 0; ky < 185; ky++) {
    for (m = 0; m < 139; m++) {
      rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[3 + bufIdx] = true;
      i = 0;
      while (i < rtDW.Erosionforlandingmark_NUMNONZ_DW[0]) {
        if (!rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[bufIdx +
            rtDW.Erosionforlandingmark_ERODE_OFF_DW[i]]) {
          rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[3 + bufIdx] = false;
          i = rtDW.Erosionforlandingmark_NUMNONZ_DW[0];
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
      rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[292 + bufIdx] = true;
      i = 0;
      while (i < rtDW.Erosionforlandingmark_NUMNONZ_DW[1]) {
        if (!rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[rtDW.Erosionforlandingmark_ERODE_OFF_DW
            [i + rtDW.Erosionforlandingmark_NUMNONZ_DW[0]] + bufIdx]) {
          rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[292 + bufIdx] = false;
          i = rtDW.Erosionforlandingmark_NUMNONZ_DW[1];
        }

        i++;
      }

      bufIdx++;
    }

    bufIdx += 4;
  }

  ku = rtDW.Erosionforlandingmark_NUMNONZ_DW[0] +
    rtDW.Erosionforlandingmark_NUMNONZ_DW[1];
  bufIdx = 0;
  for (ky = 0; ky < 179; ky++) {
    for (m = 0; m < 145; m++) {
      rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[435 + bufIdx] = true;
      i = 0;
      while (i < rtDW.Erosionforlandingmark_NUMNONZ_DW[2]) {
        if (!rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[rtDW.Erosionforlandingmark_ERODE_OFF_DW
            [i + ku] + bufIdx]) {
          rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[435 + bufIdx] = false;
          i = rtDW.Erosionforlandingmark_NUMNONZ_DW[2];
        }

        i++;
      }

      bufIdx++;
    }
  }

  ku += rtDW.Erosionforlandingmark_NUMNONZ_DW[2];
  bufIdx = 0;
  for (ky = 0; ky < 181; ky++) {
    for (m = 0; m < 141; m++) {
      rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[292 + bufIdx] = true;
      i = 0;
      while (i < rtDW.Erosionforlandingmark_NUMNONZ_DW[3]) {
        if (!rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[rtDW.Erosionforlandingmark_ERODE_OFF_DW
            [i + ku] + bufIdx]) {
          rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[292 + bufIdx] = false;
          i = rtDW.Erosionforlandingmark_NUMNONZ_DW[3];
        }

        i++;
      }

      bufIdx++;
    }

    bufIdx += 4;
  }

  ku += rtDW.Erosionforlandingmark_NUMNONZ_DW[3];
  bufIdx = 0;
  for (ky = 0; ky < 181; ky++) {
    for (m = 0; m < 145; m++) {
      rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[290 + bufIdx] = true;
      i = 0;
      while (i < rtDW.Erosionforlandingmark_NUMNONZ_DW[4]) {
        if (!rtDW.Erosionforlandingmark_ONE_PAD_IMG_DW[rtDW.Erosionforlandingmark_ERODE_OFF_DW
            [i + ku] + bufIdx]) {
          rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[290 + bufIdx] = false;
          i = rtDW.Erosionforlandingmark_NUMNONZ_DW[4];
        }

        i++;
      }

      bufIdx++;
    }
  }

  ku += rtDW.Erosionforlandingmark_NUMNONZ_DW[4];
  bufIdx = 1312;
  outIdx = 0;
  for (ky = 9; ky < 169; ky++) {
    for (m = 7; m < 127; m++) {
      rtDW.Erosionforlandingmark[outIdx] = true;
      i = 0;
      while (i < rtDW.Erosionforlandingmark_NUMNONZ_DW[5]) {
        if (!rtDW.Erosionforlandingmark_TWO_PAD_IMG_DW[rtDW.Erosionforlandingmark_ERODE_OFF_DW
            [i + ku] + bufIdx]) {
          rtDW.Erosionforlandingmark[outIdx] = false;
          i = rtDW.Erosionforlandingmark_NUMNONZ_DW[5];
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
  memset(&rtDW.Dilation_ONE_PAD_IMG_DW[0], 0, 28841U * sizeof(boolean_T));
  for (bufIdx = 0; bufIdx < 19200; bufIdx++) {
    if (rtDW.Erosionforlandingmark[bufIdx]) {
      i = bufIdx / 120;
      outIdx = (bufIdx - i * 120) + i * 151;
      for (i = 0; i < rtDW.Dilation_NUMNONZ_DW[0]; i++) {
        rtDW.Dilation_ONE_PAD_IMG_DW[outIdx + rtDW.Dilation_DILATE_OFF_DW[i]] =
          true;
      }
    }
  }

  memset(&rtDW.Dilation_TWO_PAD_IMG_DW[0], 0, 28841U * sizeof(boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (rtDW.Dilation_ONE_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < rtDW.Dilation_NUMNONZ_DW[1]; i++) {
        rtDW.Dilation_TWO_PAD_IMG_DW[bufIdx +
          rtDW.Dilation_DILATE_OFF_DW[rtDW.Dilation_NUMNONZ_DW[0] + i]] = true;
      }
    }
  }

  ky = rtDW.Dilation_NUMNONZ_DW[0] + rtDW.Dilation_NUMNONZ_DW[1];
  memset(&rtDW.Dilation_ONE_PAD_IMG_DW[0], 0, 28841U * sizeof(boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (rtDW.Dilation_TWO_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < rtDW.Dilation_NUMNONZ_DW[2]; i++) {
        rtDW.Dilation_ONE_PAD_IMG_DW[bufIdx + rtDW.Dilation_DILATE_OFF_DW[ky + i]]
          = true;
      }
    }
  }

  ky += rtDW.Dilation_NUMNONZ_DW[2];
  memset(&rtDW.Dilation_TWO_PAD_IMG_DW[0], 0, 28841U * sizeof(boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (rtDW.Dilation_ONE_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < rtDW.Dilation_NUMNONZ_DW[3]; i++) {
        rtDW.Dilation_TWO_PAD_IMG_DW[bufIdx + rtDW.Dilation_DILATE_OFF_DW[ky + i]]
          = true;
      }
    }
  }

  ky += rtDW.Dilation_NUMNONZ_DW[3];
  memset(&rtDW.Dilation_ONE_PAD_IMG_DW[0], 0, 28841U * sizeof(boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (rtDW.Dilation_TWO_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < rtDW.Dilation_NUMNONZ_DW[4]; i++) {
        rtDW.Dilation_ONE_PAD_IMG_DW[bufIdx + rtDW.Dilation_DILATE_OFF_DW[ky + i]]
          = true;
      }
    }
  }

  ky += rtDW.Dilation_NUMNONZ_DW[4];
  memset(&rtDW.Dilation_TWO_PAD_IMG_DW[0], 0, 28841U * sizeof(boolean_T));
  for (bufIdx = 0; bufIdx < 28841; bufIdx++) {
    if (rtDW.Dilation_ONE_PAD_IMG_DW[bufIdx]) {
      for (i = 0; i < rtDW.Dilation_NUMNONZ_DW[5]; i++) {
        rtDW.Dilation_TWO_PAD_IMG_DW[bufIdx + rtDW.Dilation_DILATE_OFF_DW[ky + i]]
          = true;
      }
    }
  }

  ky = 0;
  ku = 0;
  for (i = 0; i < 6; i++) {
    ky += (rtConstP.Dilation_NHDIMS_RTP[i] - 1) >> 1;
    ku += (rtConstP.Dilation_NHDIMS_RTP[i + 6] - 1) >> 1;
  }

  bufIdx = ku * 151 + ky;
  outIdx = 0;
  for (ky = 0; ky < 160; ky++) {
    for (m = 0; m < 120; m++) {
      rtDW.Dilation[outIdx] = rtDW.Dilation_TWO_PAD_IMG_DW[bufIdx];
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
    rtDW.frame[i] = (int8_T)(rtDW.binarized_frame[i] - rtDW.Dilation[i]);
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* MATLAB Function: '<S2>/Waypoints' incorporates:
   *  Delay: '<S2>/Delay'
   *  Delay: '<S2>/Delay1'
   *  Delay: '<S2>/Delay2'
   */
  center_y = mod(rt_atan2d_snf(-rtDW.Delay_DSTATE, rtDW.Delay1_DSTATE));
  if (rtDW.Delay2_DSTATE) {
    for (ky = 0; ky < 81; ky++) {
      for (m = 0; m < 81; m++) {
        rtDW.b_norm = sqrt((((real_T)ky + 20.0) - 59.5) * (((real_T)ky + 20.0) -
          59.5) + (((real_T)m + 40.0) - 79.5) * (((real_T)m + 40.0) - 79.5));
        if ((rtDW.b_norm >= 30.0) && (rtDW.b_norm <= 40.0)) {
          rtDW.b_norm = mod(rt_atan2d_snf(((real_T)ky + 20.0) - 59.5, ((real_T)m
            + 40.0) - 79.5));
          rtDW.y_ref_temp = mod(center_y + 1.0833078115826873);
          center_x = mod(center_y - 1.0833078115826873);
          if (rtDW.y_ref_temp < center_x) {
            flag_error_x = (((rtDW.b_norm <= 6.2831853071795862) && (rtDW.b_norm
              >= center_x)) || ((rtDW.b_norm <= rtDW.y_ref_temp) && (rtDW.b_norm
              >= 0.0)));
          } else {
            flag_error_x = ((rtDW.b_norm <= rtDW.y_ref_temp) && (rtDW.b_norm >=
              center_x));
          }

          if (flag_error_x && (rtDW.frame[(int32_T)(((real32_T)((real_T)m + 40.0)
                 - 1.0F) * 120.0F + (real32_T)((real_T)ky + 20.0)) - 1] == 1)) {
            rtDW.pixel_count++;
            rtDW.x_accumulator += (real_T)ky + 20.0;
            rtDW.y_accumulator += (real_T)m + 40.0;
          }
        }
      }
    }
  } else {
    for (ku = 0; ku < 81; ku++) {
      for (m = 0; m < 81; m++) {
        rtDW.b_norm = sqrt((((real_T)ku + 20.0) - 59.5) * (((real_T)ku + 20.0) -
          59.5) + (((real_T)m + 40.0) - 79.5) * (((real_T)m + 40.0) - 79.5));
        if ((rtDW.b_norm >= 30.0) && (rtDW.b_norm <= 40.0) && (rtDW.frame
             [(int32_T)(((real32_T)((real_T)m + 40.0) - 1.0F) * 120.0F +
                        (real32_T)((real_T)ku + 20.0)) - 1] == 1)) {
          rtDW.pixel_count++;
          rtDW.x_accumulator += (real_T)ku + 20.0;
          rtDW.y_accumulator += (real_T)m + 40.0;
        }
      }
    }
  }

  rtDW.b_norm = -(rt_roundd_snf(rtDW.x_accumulator / rtDW.pixel_count) - 60.0);
  rtDW.y_ref_temp = rt_roundd_snf(rtDW.y_accumulator / rtDW.pixel_count) - 80.0;
  if (rtIsNaN(rtDW.b_norm)) {
    rtDW.b_norm = 0.0;
    flag_error_x = false;
  } else {
    flag_error_x = true;
  }

  if (rtIsNaN(rtDW.y_ref_temp)) {
    rtDW.y_ref_temp = 0.0;
    flag_error_y = false;
  } else {
    flag_error_y = true;
  }

  rtDW.pixel_count = 0.0;
  rtDW.x_accumulator = 0.0;
  rtDW.y_accumulator = 0.0;
  flag_error_x = (flag_error_x || flag_error_y);

  /* MATLAB Function: '<S2>/Red Marker Detection' incorporates:
   *  S-Function (svipmorphop): '<S2>/Erosion for landing mark'
   */
  for (i = 0; i < 120; i++) {
    for (m = 0; m < 160; m++) {
      if (rtDW.Erosionforlandingmark[120 * m + i]) {
        rtDW.count_pixel++;
        rtDW.column_accumulator += (real_T)m + 1.0;
        rtDW.row_accumulator += (real_T)i + 1.0;
      }
    }
  }

  if (rtDW.count_pixel != 0.0) {
    i = 1;
    center_x = rt_roundd_snf(rtDW.row_accumulator / rtDW.count_pixel) - 5.0;
    center_y = rt_roundd_snf(rtDW.column_accumulator / rtDW.count_pixel);
  } else {
    i = 0;
    center_x = 60.0;
    center_y = 80.0;
  }

  rtDW.column_accumulator = 0.0;
  rtDW.row_accumulator = 0.0;
  rtDW.count_pixel = 0.0;

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  MATLAB Function: '<S2>/Waypoints'
   */
  rtDW.Delay_DSTATE = rtDW.b_norm;

  /* Update for Delay: '<S2>/Delay1' incorporates:
   *  MATLAB Function: '<S2>/Waypoints'
   */
  rtDW.Delay1_DSTATE = rtDW.y_ref_temp;

  /* Update for Delay: '<S2>/Delay2' */
  rtDW.Delay2_DSTATE = flag_error_x;

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  MATLAB Function: '<S2>/Red Marker Detection'
   *  MATLAB Function: '<S2>/Waypoints'
   */
  rtDW.RateTransition_Buffer[(rtDW.RateTransition_ActiveBufIdx == 0) * 6] =
    -(center_x - 60.0);
  rtDW.RateTransition_Buffer[1 + (rtDW.RateTransition_ActiveBufIdx == 0) * 6] =
    center_y - 80.0;
  rtDW.RateTransition_Buffer[2 + (rtDW.RateTransition_ActiveBufIdx == 0) * 6] =
    i;
  rtDW.RateTransition_Buffer[3 + (rtDW.RateTransition_ActiveBufIdx == 0) * 6] =
    rtDW.b_norm;
  rtDW.RateTransition_Buffer[4 + (rtDW.RateTransition_ActiveBufIdx == 0) * 6] =
    rtDW.y_ref_temp;
  rtDW.RateTransition_Buffer[5 + (rtDW.RateTransition_ActiveBufIdx == 0) * 6] =
    flag_error_x;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  rtDW.RateTransition_ActiveBufIdx = (int8_T)(rtDW.RateTransition_ActiveBufIdx ==
    0);
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T curNumNonZ;
    int32_T idxNHood;
    int32_T idxOffsets;
    int32_T m;
    int32_T n;
    int32_T nhIdx;
    rtPrevZCX.ControlSystem_o.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Control System' */
    ControlSystem_Init(&rtDW.ControlSystem_o);

    /* End of SystemInitialize for SubSystem: '<Root>/Control System' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Image Processing System' */
    /* Start for S-Function (svipmorphop): '<S2>/Erosion for landing mark' */
    idxNHood = 0;
    idxOffsets = 0;
    for (nhIdx = 0; nhIdx < 6; nhIdx++) {
      curNumNonZ = 0;
      for (n = 0; n < rtConstP.Erosionforlandingmark_NHDIMS_RTP[nhIdx + 6]; n++)
      {
        for (m = 0; m < rtConstP.Erosionforlandingmark_NHDIMS_RTP[nhIdx]; m++) {
          if (rtConstP.Erosionforlandingmark_NHOOD_RTP[idxNHood]) {
            rtDW.Erosionforlandingmark_ERODE_OFF_DW[idxOffsets] = n * 145 + m;
            curNumNonZ++;
            idxOffsets++;
          }

          idxNHood++;
        }
      }

      rtDW.Erosionforlandingmark_NUMNONZ_DW[nhIdx] = curNumNonZ;
    }

    /* End of Start for S-Function (svipmorphop): '<S2>/Erosion for landing mark' */

    /* Start for S-Function (svipmorphop): '<S2>/Dilation' */
    idxNHood = 0;
    idxOffsets = 0;
    for (nhIdx = 0; nhIdx < 6; nhIdx++) {
      curNumNonZ = 0;
      for (n = 0; n < rtConstP.Dilation_NHDIMS_RTP[nhIdx + 6]; n++) {
        for (m = 0; m < rtConstP.Dilation_NHDIMS_RTP[nhIdx]; m++) {
          if (rtConstP.Dilation_NHOOD_RTP[idxNHood]) {
            rtDW.Dilation_DILATE_OFF_DW[idxOffsets] = n * 151 + m;
            curNumNonZ++;
            idxOffsets++;
          }

          idxNHood++;
        }
      }

      rtDW.Dilation_NUMNONZ_DW[nhIdx] = curNumNonZ;
    }

    /* End of Start for S-Function (svipmorphop): '<S2>/Dilation' */

    /* Start for MATLABSystem: '<S2>/PARROT Image Conversion' */
    rtDW.obj.isInitialized = 1;

    /* End of SystemInitialize for SubSystem: '<Root>/Image Processing System' */
  }
}
