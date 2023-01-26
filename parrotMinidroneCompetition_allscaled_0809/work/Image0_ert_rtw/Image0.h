/*
 * Image0.h
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

#ifndef RTW_HEADER_Image0_h_
#define RTW_HEADER_Image0_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Image0_COMMON_INCLUDES_
#define Image0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rsedu_image.h"
#endif                                 /* Image0_COMMON_INCLUDES_ */

#include "MW_target_hardware_resources.h"

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define Image0_M                       (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap;

#endif                                 /* typedef_cell_wrap */

#ifndef struct_tag_ka0xmCFxNA495MDHzPTiFE
#define struct_tag_ka0xmCFxNA495MDHzPTiFE

struct tag_ka0xmCFxNA495MDHzPTiFE
{
  int32_T isInitialized;
  cell_wrap inputVarSize;
};

#endif                                 /* struct_tag_ka0xmCFxNA495MDHzPTiFE */

#ifndef typedef_parrot_ImageProcess
#define typedef_parrot_ImageProcess

typedef struct tag_ka0xmCFxNA495MDHzPTiFE parrot_ImageProcess;

#endif                                 /* typedef_parrot_ImageProcess */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  parrot_ImageProcess obj;             /* '<S1>/PARROT Image Conversion' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  real_T Delay1_DSTATE;                /* '<S1>/Delay1' */
  real_T x_accumulator;                /* '<S1>/Waypoints_straight' */
  real_T y_accumulator;                /* '<S1>/Waypoints_straight' */
  real_T pixel_count;                  /* '<S1>/Waypoints_straight' */
  real_T column_accumulator;           /* '<S1>/Red Marker Detection' */
  real_T count_pixel;                  /* '<S1>/Red Marker Detection' */
  real_T row_accumulator;              /* '<S1>/Red Marker Detection' */
  real_T orientation_track;
  real_T b_norm;
  int32_T Erosionforlandingmark_NUMNONZ_DW[6];/* '<S1>/Erosion for landing mark' */
  int32_T Erosionforlandingmark_STREL_DW[6];/* '<S1>/Erosion for landing mark' */
  int32_T Erosionforlandingmark_ERODE_OFF_DW[74];/* '<S1>/Erosion for landing mark' */
  int32_T Dilation_NUMNONZ_DW[6];      /* '<S1>/Dilation' */
  int32_T Dilation_STREL_DW[6];        /* '<S1>/Dilation' */
  int32_T Dilation_DILATE_OFF_DW[122]; /* '<S1>/Dilation' */
  int8_T frame[19200];                 /* '<S1>/MATLAB Function' */
  uint8_T b_varargout_3[19200];
  uint8_T b_varargout_2[19200];
  uint8_T b_varargout_1[19200];
  boolean_T binarized_frame[19200];    /* '<S1>/Image Binarization' */
  boolean_T Erosionforlandingmark[19200];/* '<S1>/Erosion for landing mark' */
  boolean_T Erosionforlandingmark_ONE_PAD_IMG_DW[26825];/* '<S1>/Erosion for landing mark' */
  boolean_T Erosionforlandingmark_TWO_PAD_IMG_DW[26825];/* '<S1>/Erosion for landing mark' */
  boolean_T Dilation[19200];           /* '<S1>/Dilation' */
  boolean_T Dilation_ONE_PAD_IMG_DW[28841];/* '<S1>/Dilation' */
  boolean_T Dilation_TWO_PAD_IMG_DW[28841];/* '<S1>/Dilation' */
  boolean_T Delay2_DSTATE;             /* '<S1>/Delay2' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: nhdims
   * Referenced by: '<S1>/Erosion for landing mark'
   */
  int32_T Erosionforlandingmark_NHDIMS_RTP[12];

  /* Expression: nhdims
   * Referenced by: '<S1>/Dilation'
   */
  int32_T Dilation_NHDIMS_RTP[12];

  /* Expression: nhood
   * Referenced by: '<S1>/Erosion for landing mark'
   */
  boolean_T Erosionforlandingmark_NHOOD_RTP[74];

  /* Expression: nhood
   * Referenced by: '<S1>/Dilation'
   */
  boolean_T Dilation_NHOOD_RTP[122];
} ConstP;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T VisionbasedData[6];           /* '<Root>/Vision-based Data' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Imported (extern) pointer block signals */
extern uint8_T *imRGB;                 /* '<Root>/Image Data' */

/* Block signals and states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void Image0_initialize(void);
extern void Image0_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Cast To Boolean1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('flightControlSystem/Image Processing System')    - opens subsystem flightControlSystem/Image Processing System
 * hilite_system('flightControlSystem/Image Processing System/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'flightControlSystem'
 * '<S1>'   : 'flightControlSystem/Image Processing System'
 * '<S2>'   : 'flightControlSystem/Image Processing System/Image Binarization'
 * '<S3>'   : 'flightControlSystem/Image Processing System/MATLAB Function'
 * '<S4>'   : 'flightControlSystem/Image Processing System/Red Marker Detection'
 * '<S5>'   : 'flightControlSystem/Image Processing System/Waypoints_straight'
 */
#endif                                 /* RTW_HEADER_Image0_h_ */
