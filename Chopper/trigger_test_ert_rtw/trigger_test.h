/*
 * trigger_test.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "trigger_test".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Feb 19 23:43:51 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_trigger_test_h_
#define RTW_HEADER_trigger_test_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef trigger_test_COMMON_INCLUDES_
# define trigger_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_gpio.h"
#endif                                 /* trigger_test_COMMON_INCLUDES_ */

#include "trigger_test_types.h"

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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T MathFunction;                 /* '<S2>/Math Function' */
  boolean_T DigitalRead;               /* '<S1>/Digital Read' */
} B_trigger_test_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_Digi_T obj; /* '<S1>/Digital Read' */
  real_T A;                            /* '<S2>/Data Store Memory' */
  void *DigitalRead_PWORK;             /* '<S1>/Digital Read' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<Root>/Triggered Subsystem' */
  boolean_T objisempty;                /* '<S1>/Digital Read' */
} DW_trigger_test_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<Root>/Triggered Subsystem' */
} PrevZCX_trigger_test_T;

/* Parameters (auto storage) */
struct P_trigger_test_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: sampleTime
                                        * Referenced by: '<S1>/Digital Read'
                                        */
  real_T ONOFF_Y0;                     /* Computed Parameter: ONOFF_Y0
                                        * Referenced by: '<S2>/ON//OFF'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_trigger_test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_trigger_test_T trigger_test_P;

/* Block signals (auto storage) */
extern B_trigger_test_T trigger_test_B;

/* Block states (auto storage) */
extern DW_trigger_test_T trigger_test_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_trigger_test_T trigger_test_PrevZCX;

/* Model entry point functions */
extern void trigger_test_initialize(void);
extern void trigger_test_step(void);
extern void trigger_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_trigger_test_T *const trigger_test_M;

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
 * '<Root>' : 'trigger_test'
 * '<S1>'   : 'trigger_test/GPIO Read'
 * '<S2>'   : 'trigger_test/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_trigger_test_h_ */
