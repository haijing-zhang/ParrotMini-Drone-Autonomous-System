/*
 * mod_nOBiMHsG.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 2.78
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jul  5 20:05:08 2021
 * Created for block: flightControlSystem
 */

#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "mod_nOBiMHsG.h"

/* Function for MATLAB Function: '<S2>/Waypoints_straight' */
real_T mod_nOBiMHsG(real_T x)
{
  real_T q;
  real_T r;
  boolean_T rEQ0;
  if (rtIsNaN(x) || rtIsInf(x)) {
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
