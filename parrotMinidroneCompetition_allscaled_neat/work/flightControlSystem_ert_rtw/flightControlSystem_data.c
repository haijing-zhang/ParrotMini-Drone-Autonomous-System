/*
 * flightControlSystem_data.c
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

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Expression: pInitialization.M
   * Referenced by: '<S466>/KalmanGainM'
   */
  { 0.066408162001371535, 0.0, -0.021605460397771489, 0.0, 0.0,
    0.066408162001371535, 0.0, -0.021605460397771493 },

  /* Expression: pInitialization.L
   * Referenced by: '<S466>/KalmanGainL'
   */
  { 0.066516189303360354, 5.23402355848703E-19, -0.021605460397771867,
    -4.8628553107267881E-19, 4.3622439914025292E-18, 0.066516189303360354,
    -4.5659075919712689E-17, -0.021605460397771864 },

  /* Expression: [0 0 g]
   * Referenced by: '<S257>/gravity'
   */
  { 0.0, 0.0, 9.81 },

  /* Expression: nhdims
   * Referenced by: '<S2>/Erosion for landing mark'
   */
  { 7, 5, 1, 5, 1, 5, 1, 5, 7, 5, 5, 1 },

  /* Expression: nhdims
   * Referenced by: '<S2>/Dilation'
   */
  { 9, 7, 1, 7, 1, 3, 1, 7, 9, 7, 3, 1 },

  /* Computed Parameter: TorqueTotalThrustToThrustPerMotor_Value
   * Referenced by: '<S9>/TorqueTotalThrustToThrustPerMotor'
   */
  { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
    -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F, 5.66592F,
    5.66592F, -5.66592F },

  /* Computed Parameter: A_Value_a
   * Referenced by: '<S447>/A'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -0.005F, 0.0F, 1.0F, 0.0F,
    0.0F, -0.005F, 0.0F, 1.0F },

  /* Computed Parameter: Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
   * Referenced by: '<S259>/Assuming that the  preflight calibration was done at level orientation'
   */
  { 0.0F, 0.0F, 9.81F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: FIR_IMUaccel_Coefficients
   * Referenced by: '<S259>/FIR_IMUaccel'
   */
  { 0.0264077242F, 0.140531361F, 0.33306092F, 0.33306092F, 0.140531361F,
    0.0264077242F },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S327>/C'
   *   '<S381>/C'
   */
  { 1.0F, 0.0F },

  /* Computed Parameter: C_Value_i
   * Referenced by: '<S447>/C'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: B_Value_f
   * Referenced by: '<S447>/B'
   */
  { 0.005F, 0.0F, 0.0F, 0.0F, 0.0F, 0.005F, 0.0F, 0.0F },

  /* Pooled Parameter (Expression: Estimator.IMU.filterGyroNum)
   * Referenced by:
   *   '<S259>/IIR_IMUgyro_r'
   *   '<S446>/IIRgyroz'
   */
  { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
    0.282124132F },

  /* Pooled Parameter (Expression: Estimator.IMU.filterGyroDen)
   * Referenced by:
   *   '<S259>/IIR_IMUgyro_r'
   *   '<S446>/IIRgyroz'
   */
  { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

  /* Computed Parameter: MotorDirections_Gain
   * Referenced by: '<S12>/MotorDirections'
   */
  { 1.0F, -1.0F, 1.0F, -1.0F },

  /* Expression: nhood
   * Referenced by: '<S2>/Erosion for landing mark'
   */
  { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
    0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },

  /* Expression: nhood
   * Referenced by: '<S2>/Dilation'
   */
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 }
};
