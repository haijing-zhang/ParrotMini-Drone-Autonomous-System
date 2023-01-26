/*
 * flightControlSystem_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 2.83
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sun Aug  8 13:53:24 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightControlSystem_private_h_
#define RTW_HEADER_flightControlSystem_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real_T rtCP_pooled_ckUrqqE5cQjo[8];
extern const real_T rtCP_pooled_ZIlPlxFuKBgw[8];
extern const real_T rtCP_pooled_OlAt8KbpQEG0[3];
extern const int32_T rtCP_pooled_G5JIlGPxChCk[12];
extern const int32_T rtCP_pooled_xHda5yoX4x5Y[12];
extern const real32_T rtCP_pooled_AiPFoGkd3zrs[16];
extern const real32_T rtCP_pooled_HiTm18TP3yla[16];
extern const real32_T rtCP_pooled_aLwfmFKBoRwh[6];
extern const real32_T rtCP_pooled_KvfM2cKww6Wz[6];
extern const real32_T rtCP_pooled_Y1cPDYRzaj44[2];
extern const real32_T rtCP_pooled_adLCBuYxtU1Q[6];
extern const real32_T rtCP_pooled_VH0dmwbCQMUq[6];
extern const real32_T rtCP_pooled_Y9czxQiuYSgv[8];
extern const real32_T rtCP_pooled_dgegQRGH7J9u[8];
extern const real32_T rtCP_pooled_oEBofkCxx3u4[4];
extern const boolean_T rtCP_pooled_xXb3eMWWHk32[74];
extern const boolean_T rtCP_pooled_V505X1rvl341[122];

#define rtCP_KalmanGainM_Value_i       rtCP_pooled_ckUrqqE5cQjo  /* Expression: pInitialization.M
                                                                  * Referenced by: '<S466>/KalmanGainM'
                                                                  */
#define rtCP_KalmanGainL_Value         rtCP_pooled_ZIlPlxFuKBgw  /* Expression: pInitialization.L
                                                                  * Referenced by: '<S466>/KalmanGainL'
                                                                  */
#define rtCP_gravity_Value_j           rtCP_pooled_OlAt8KbpQEG0  /* Expression: [0 0 g]
                                                                  * Referenced by: '<S257>/gravity'
                                                                  */
#define rtCP_Erosionforlandingmark_NHDIMS_RTP rtCP_pooled_G5JIlGPxChCk/* Expression: nhdims
                                                                      * Referenced by: '<S2>/Erosion for landing mark'
                                                                      */
#define rtCP_Dilation_NHDIMS_RTP       rtCP_pooled_xHda5yoX4x5Y  /* Expression: nhdims
                                                                  * Referenced by: '<S2>/Dilation'
                                                                  */
#define rtCP_TorqueTotalThrustToThrustPerMotor_Value rtCP_pooled_AiPFoGkd3zrs/* Computed Parameter: rtCP_TorqueTotalThrustToThrustPerMotor_Value
                                                                      * Referenced by: '<S9>/TorqueTotalThrustToThrustPerMotor'
                                                                      */
#define rtCP_A_Value_a                 rtCP_pooled_HiTm18TP3yla  /* Computed Parameter: rtCP_A_Value_a
                                                                  * Referenced by: '<S447>/A'
                                                                  */
#define rtCP_Assumingthatthepreflightcalibrationwasdoneatlevelorientati rtCP_pooled_aLwfmFKBoRwh/* Computed Parameter: rtCP_Assumingthatthepreflightcalibrationwasdoneatlevelorientati
                                                                      * Referenced by: '<S259>/Assuming that the  preflight calibration was done at level orientation'
                                                                      */
#define rtCP_FIR_IMUaccel_Coefficients rtCP_pooled_KvfM2cKww6Wz  /* Computed Parameter: rtCP_FIR_IMUaccel_Coefficients
                                                                  * Referenced by: '<S259>/FIR_IMUaccel'
                                                                  */
#define rtCP_C_Value_h                 rtCP_pooled_Y1cPDYRzaj44  /* Computed Parameter: rtCP_C_Value_h
                                                                  * Referenced by: '<S327>/C'
                                                                  */
#define rtCP_C_Value_i                 rtCP_pooled_Y1cPDYRzaj44  /* Computed Parameter: rtCP_C_Value_i
                                                                  * Referenced by: '<S381>/C'
                                                                  */
#define rtCP_IIR_IMUgyro_r_NumCoef     rtCP_pooled_adLCBuYxtU1Q  /* Computed Parameter: rtCP_IIR_IMUgyro_r_NumCoef
                                                                  * Referenced by: '<S259>/IIR_IMUgyro_r'
                                                                  */
#define rtCP_IIR_IMUgyro_r_DenCoef     rtCP_pooled_VH0dmwbCQMUq  /* Computed Parameter: rtCP_IIR_IMUgyro_r_DenCoef
                                                                  * Referenced by: '<S259>/IIR_IMUgyro_r'
                                                                  */
#define rtCP_C_Value_i2                rtCP_pooled_Y9czxQiuYSgv  /* Computed Parameter: rtCP_C_Value_i2
                                                                  * Referenced by: '<S447>/C'
                                                                  */
#define rtCP_IIRgyroz_NumCoef          rtCP_pooled_adLCBuYxtU1Q  /* Computed Parameter: rtCP_IIRgyroz_NumCoef
                                                                  * Referenced by: '<S446>/IIRgyroz'
                                                                  */
#define rtCP_IIRgyroz_DenCoef          rtCP_pooled_VH0dmwbCQMUq  /* Computed Parameter: rtCP_IIRgyroz_DenCoef
                                                                  * Referenced by: '<S446>/IIRgyroz'
                                                                  */
#define rtCP_B_Value_f                 rtCP_pooled_dgegQRGH7J9u  /* Computed Parameter: rtCP_B_Value_f
                                                                  * Referenced by: '<S447>/B'
                                                                  */
#define rtCP_MotorDirections_Gain      rtCP_pooled_oEBofkCxx3u4  /* Computed Parameter: rtCP_MotorDirections_Gain
                                                                  * Referenced by: '<S12>/MotorDirections'
                                                                  */
#define rtCP_Erosionforlandingmark_NHOOD_RTP rtCP_pooled_xXb3eMWWHk32/* Expression: nhood
                                                                      * Referenced by: '<S2>/Erosion for landing mark'
                                                                      */
#define rtCP_Dilation_NHOOD_RTP        rtCP_pooled_V505X1rvl341  /* Expression: nhood
                                                                  * Referenced by: '<S2>/Dilation'
                                                                  */

/* Imported (extern) pointer block signals */
extern uint8_T *imRGB;                 /* '<Root>/Image Data' */

#endif                           /* RTW_HEADER_flightControlSystem_private_h_ */
