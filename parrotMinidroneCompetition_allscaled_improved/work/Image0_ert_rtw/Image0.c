/*
 * Image0.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Image0".
 *
 * Model version              : 2.77
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sun Jul  4 11:50:09 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Image0.h"
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);

/* Forward declaration for local functions */
static void SystemCore_step(const uint8_T varargin_1[38400], uint8_T
  varargout_1[19200], uint8_T varargout_2[19200], uint8_T varargout_3[19200]);
static real_T mod(real_T x);
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
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

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

static void SystemCore_step(const uint8_T varargin_1[38400], uint8_T
  varargout_1[19200], uint8_T varargout_2[19200], uint8_T varargout_3[19200])
{
  MW_Build_RGB(&varargin_1[0], &varargout_1[0], &varargout_2[0], &varargout_3[0]);
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

/* Function for MATLAB Function: '<S1>/Waypoints_straight' */
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

/* Model step function */
void Image0_step(void)
{
  real_T threshold_2;
  real_T y_ref_temp;
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
  /* MATLABSystem: '<S1>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  SystemCore_step(imRGB, rtDW.b_varargout_1, rtDW.b_varargout_2,
                  rtDW.b_varargout_3);

  /* MATLAB Function: '<S1>/Image Binarization' incorporates:
   *  MATLABSystem: '<S1>/PARROT Image Conversion'
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

  /* End of MATLAB Function: '<S1>/Image Binarization' */

  /* S-Function (svipmorphop): '<S1>/Erosion for landing mark' */
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

  /* End of S-Function (svipmorphop): '<S1>/Erosion for landing mark' */

  /* S-Function (svipmorphop): '<S1>/Dilation' incorporates:
   *  S-Function (svipmorphop): '<S1>/Erosion for landing mark'
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

  /* End of S-Function (svipmorphop): '<S1>/Dilation' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  S-Function (svipmorphop): '<S1>/Dilation'
   */
  for (i = 0; i < 19200; i++) {
    rtDW.frame[i] = (int8_T)(rtDW.binarized_frame[i] - rtDW.Dilation[i]);
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* MATLAB Function: '<S1>/Waypoints_straight' incorporates:
   *  Delay: '<S1>/Delay'
   *  Delay: '<S1>/Delay1'
   *  Delay: '<S1>/Delay2'
   */
  rtDW.orientation_track = mod(rt_atan2d_snf(-rtDW.Delay_DSTATE,
    rtDW.Delay1_DSTATE));
  if (rtDW.Delay2_DSTATE) {
    for (ky = 0; ky < 81; ky++) {
      for (m = 0; m < 81; m++) {
        rtDW.b_norm = sqrt((((real_T)ky + 20.0) - 59.5) * (((real_T)ky + 20.0) -
          59.5) + (((real_T)m + 40.0) - 79.5) * (((real_T)m + 40.0) - 79.5));
        if ((rtDW.b_norm >= 30.0) && (rtDW.b_norm <= 40.0)) {
          rtDW.b_norm = mod(rt_atan2d_snf(((real_T)ky + 20.0) - 59.5, ((real_T)m
            + 40.0) - 79.5));
          y_ref_temp = mod(rtDW.orientation_track + 1.0833078115826873);
          threshold_2 = mod(rtDW.orientation_track - 1.0833078115826873);
          if (y_ref_temp < threshold_2) {
            flag_error_x = (((rtDW.b_norm <= 6.2831853071795862) && (rtDW.b_norm
              >= threshold_2)) || ((rtDW.b_norm <= y_ref_temp) && (rtDW.b_norm >=
              0.0)));
          } else {
            flag_error_x = ((rtDW.b_norm <= y_ref_temp) && (rtDW.b_norm >=
              threshold_2));
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
  y_ref_temp = rt_roundd_snf(rtDW.y_accumulator / rtDW.pixel_count) - 80.0;
  if (rtIsNaN(rtDW.b_norm)) {
    rtDW.b_norm = 0.0;
    flag_error_x = false;
  } else {
    flag_error_x = true;
  }

  if (rtIsNaN(y_ref_temp)) {
    y_ref_temp = 0.0;
    flag_error_y = false;
  } else {
    flag_error_y = true;
  }

  rtDW.pixel_count = 0.0;
  rtDW.x_accumulator = 0.0;
  rtDW.y_accumulator = 0.0;
  flag_error_x = (flag_error_x || flag_error_y);

  /* MATLAB Function: '<S1>/Red Marker Detection' incorporates:
   *  S-Function (svipmorphop): '<S1>/Erosion for landing mark'
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
    rtDW.orientation_track = rt_roundd_snf(rtDW.row_accumulator /
      rtDW.count_pixel);
    threshold_2 = rt_roundd_snf(rtDW.column_accumulator / rtDW.count_pixel);
  } else {
    i = 0;
    rtDW.orientation_track = 60.0;
    threshold_2 = 80.0;
  }

  rtDW.column_accumulator = 0.0;
  rtDW.row_accumulator = 0.0;
  rtDW.count_pixel = 0.0;

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  MATLAB Function: '<S1>/Waypoints_straight'
   */
  rtDW.Delay_DSTATE = rtDW.b_norm;

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  MATLAB Function: '<S1>/Waypoints_straight'
   */
  rtDW.Delay1_DSTATE = y_ref_temp;

  /* Update for Delay: '<S1>/Delay2' */
  rtDW.Delay2_DSTATE = flag_error_x;

  /* Outport: '<Root>/Vision-based Data' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  MATLAB Function: '<S1>/Red Marker Detection'
   *  MATLAB Function: '<S1>/Waypoints_straight'
   */
  rtY.VisionbasedData[0] = -(rtDW.orientation_track - 60.0);
  rtY.VisionbasedData[1] = threshold_2 - 80.0;
  rtY.VisionbasedData[2] = i;
  rtY.VisionbasedData[3] = rtDW.b_norm;
  rtY.VisionbasedData[4] = y_ref_temp;
  rtY.VisionbasedData[5] = flag_error_x;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
}

/* Model initialize function */
void Image0_initialize(void)
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

    /* SystemInitialize for Atomic SubSystem: '<Root>/Image Processing System' */
    /* Start for S-Function (svipmorphop): '<S1>/Erosion for landing mark' */
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

    /* End of Start for S-Function (svipmorphop): '<S1>/Erosion for landing mark' */

    /* Start for S-Function (svipmorphop): '<S1>/Dilation' */
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

    /* End of Start for S-Function (svipmorphop): '<S1>/Dilation' */

    /* Start for MATLABSystem: '<S1>/PARROT Image Conversion' */
    rtDW.obj.isInitialized = 1;

    /* End of SystemInitialize for SubSystem: '<Root>/Image Processing System' */
  }
}
