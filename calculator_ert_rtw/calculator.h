/*
 * calculator.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "calculator".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Mar  7 18:12:23 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_calculator_h_
#define RTW_HEADER_calculator_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef calculator_COMMON_INCLUDES_
# define calculator_COMMON_INCLUDES_
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SCI.h"
#include "MW_gpio.h"
#include "MW_led_lct.h"
#endif                                 /* calculator_COMMON_INCLUDES_ */

#include "calculator_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T FromWs[6];                    /* '<S6>/FromWs' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  int8_T int8_1;                       /* '<S4>/int8_1' */
  int8_T int8_2;                       /* '<S4>/int8_2' */
  int8_T int8_3;                       /* '<S4>/int8_3' */
  boolean_T DataTypeConversion;        /* '<S5>/Data Type Conversion' */
} B_calculator_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_Digi_T obj; /* '<S1>/Digital Read' */
  codertarget_raspi_internal_SC_T obj_p;/* '<Root>/Serial Write' */
  real_T A;                            /* '<S5>/Data Store Memory' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S6>/FromWs' */

  void *DigitalWrite_PWORK;            /* '<S3>/Digital Write' */
  void *DigitalWrite_PWORK_a;          /* '<S2>/Digital Write' */
  void *DigitalRead_PWORK;             /* '<S1>/Digital Read' */
  void *SerialWrite_PWORK;             /* '<Root>/Serial Write' */
  codertarget_linux_blocks_Di_i_T obj_o;/* '<S3>/Digital Write' */
  codertarget_linux_blocks_Di_i_T obj_oh;/* '<S2>/Digital Write' */
  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S6>/FromWs' */

  int8_T Switch_SubsysRanBC;           /* '<Root>/Switch' */
  boolean_T objisempty;                /* '<S3>/Digital Write' */
  boolean_T objisempty_n;              /* '<S2>/Digital Write' */
  boolean_T objisempty_c;              /* '<S1>/Digital Read' */
  boolean_T objisempty_m;              /* '<Root>/Serial Write' */
} DW_calculator_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Switch_Trig_ZCE;          /* '<Root>/Switch' */
} PrevZCX_calculator_T;

/* Parameters (auto storage) */
struct P_calculator_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: sampleTime
                                        * Referenced by: '<S1>/Digital Read'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Switch_1_Threshold;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch_1'
                                        */
  real_T Switch_2_Threshold;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch_2'
                                        */
  real_T Switch_3_Threshold;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch_3'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T LED_p1[5];                   /* Expression: deviceFile
                                        * Referenced by: '<Root>/LED'
                                        */
  boolean_T ONOFF_Y0;                  /* Computed Parameter: ONOFF_Y0
                                        * Referenced by: '<S5>/ON//OFF'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_calculator_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_calculator_T calculator_P;

/* Block signals (auto storage) */
extern B_calculator_T calculator_B;

/* Block states (auto storage) */
extern DW_calculator_T calculator_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_calculator_T calculator_PrevZCX;

/* Model entry point functions */
extern void calculator_initialize(void);
extern void calculator_step(void);
extern void calculator_terminate(void);

/* Real-time Model object */
extern RT_MODEL_calculator_T *const calculator_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'calculator'
 * '<S1>'   : 'calculator/GPIO Read'
 * '<S2>'   : 'calculator/GPIO Write'
 * '<S3>'   : 'calculator/GPIO Write1'
 * '<S4>'   : 'calculator/Main'
 * '<S5>'   : 'calculator/Switch'
 * '<S6>'   : 'calculator/Main/Signal Builder'
 */
#endif                                 /* RTW_HEADER_calculator_h_ */
