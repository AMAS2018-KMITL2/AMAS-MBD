/*
 * pi_transmitter.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "pi_transmitter".
 *
 * Model version              : 1.5
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Mar 26 22:55:35 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pi_transmitter_h_
#define RTW_HEADER_pi_transmitter_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef pi_transmitter_COMMON_INCLUDES_
# define pi_transmitter_COMMON_INCLUDES_
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SCI.h"
#include "MW_led_lct.h"
#endif                                 /* pi_transmitter_COMMON_INCLUDES_ */

#include "pi_transmitter_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
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
  real_T ManualSwitch3;                /* '<Root>/Manual Switch3' */
  int8_T TmpSignalConversionAtSerialWrit[3];
  int8_T int8_1;                       /* '<S1>/int8_1' */
  int8_T int8_2;                       /* '<S1>/int8_2' */
  int8_T int8_3;                       /* '<S1>/int8_3' */
  boolean_T DataTypeConversion;        /* '<S2>/Data Type Conversion' */
} B_pi_transmitter_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_SC_T obj; /* '<Root>/Serial Write' */
  real_T A;                            /* '<S2>/Data Store Memory' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void *SerialWrite_PWORK;             /* '<Root>/Serial Write' */
  int8_T Switch_SubsysRanBC;           /* '<Root>/Switch' */
  boolean_T objisempty;                /* '<Root>/Serial Write' */
} DW_pi_transmitter_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Switch_Trig_ZCE;          /* '<Root>/Switch' */
} PrevZCX_pi_transmitter_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Motor;                        /* '<Root>/Motor' */
  real_T Steer;                        /* '<Root>/Steer' */
  real_T LidarServo;                   /* '<Root>/LidarServo' */
  real_T ONOFF;                        /* '<Root>/ON//OFF' */
} ExtU_pi_transmitter_T;

/* Parameters (auto storage) */
struct P_pi_transmitter_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 20
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Switch_1_Threshold;           /* Expression: 0
                                        * Referenced by: '<S1>/Switch_1'
                                        */
  real_T Switch_2_Threshold;           /* Expression: 0
                                        * Referenced by: '<S1>/Switch_2'
                                        */
  real_T Switch_3_Threshold;           /* Expression: 0
                                        * Referenced by: '<S1>/Switch_3'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: 2
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;/* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch2'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch3_CurrentSetting;/* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch3'
                                        */
  uint8_T LED_p1[5];                   /* Expression: deviceFile
                                        * Referenced by: '<Root>/LED'
                                        */
  boolean_T ONOFF_Y0;                  /* Computed Parameter: ONOFF_Y0
                                        * Referenced by: '<S2>/ON//OFF'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pi_transmitter_T {
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
extern P_pi_transmitter_T pi_transmitter_P;

/* Block signals (auto storage) */
extern B_pi_transmitter_T pi_transmitter_B;

/* Block states (auto storage) */
extern DW_pi_transmitter_T pi_transmitter_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_pi_transmitter_T pi_transmitter_U;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_pi_transmitter_T pi_transmitter_PrevZCX;

/* Model entry point functions */
extern void pi_transmitter_initialize(void);
extern void pi_transmitter_step(void);
extern void pi_transmitter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pi_transmitter_T *const pi_transmitter_M;

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
 * '<Root>' : 'pi_transmitter'
 * '<S1>'   : 'pi_transmitter/Main'
 * '<S2>'   : 'pi_transmitter/Switch'
 */
#endif                                 /* RTW_HEADER_pi_transmitter_h_ */
