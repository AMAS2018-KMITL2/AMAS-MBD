/*
 * trigger_test.c
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

#include "trigger_test.h"
#include "trigger_test_private.h"
#include "trigger_test_dt.h"
#define trigger_test_PinNumber         (22.0)

/* Block signals (auto storage) */
B_trigger_test_T trigger_test_B;

/* Block states (auto storage) */
DW_trigger_test_T trigger_test_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_trigger_test_T trigger_test_PrevZCX;

/* Real-time model */
RT_MODEL_trigger_test_T trigger_test_M_;
RT_MODEL_trigger_test_T *const trigger_test_M = &trigger_test_M_;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    if (u1 != 0.0) {
      y = (rtNaN);
    }
  } else if (u0 == 0.0) {
    y = u1 * 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      yEq = (y == 0.0);
      if ((!yEq) && (u1 > floor(u1))) {
        q = fabs(u0 / u1);
        yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
      }

      if (yEq) {
        y = u1 * 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Model step function */
void trigger_test_step(void)
{
  boolean_T p;
  boolean_T p_0;
  real_T sampleTime;

  /* Reset subsysRan breadcrumbs */
  srClearBC(trigger_test_DW.TriggeredSubsystem_SubsysRanBC);

  /* Start for MATLABSystem: '<S1>/Digital Read' incorporates:
   *  MATLABSystem: '<S1>/Digital Read'
   */
  p = false;
  p_0 = true;
  if (!(trigger_test_DW.obj.SampleTime == trigger_test_P.DigitalRead_SampleTime))
  {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(trigger_test_P.DigitalRead_SampleTime)) && (!rtIsNaN
          (trigger_test_P.DigitalRead_SampleTime))) || rtIsInf
        (trigger_test_P.DigitalRead_SampleTime)) {
      sampleTime = trigger_test_P.DigitalRead_SampleTime;
    }

    trigger_test_DW.obj.SampleTime = sampleTime;
  }

  /* MATLABSystem: '<S1>/Digital Read' incorporates:
   *  Start for MATLABSystem: '<S1>/Digital Read'
   */
  trigger_test_B.DigitalRead = MW_gpioRead((uint32_T)trigger_test_PinNumber);

  /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  if (trigger_test_B.DigitalRead &&
      (trigger_test_PrevZCX.TriggeredSubsystem_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreRead: '<S2>/Data Store Read' */
    sampleTime = trigger_test_DW.A;

    /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
     *  Constant: '<S2>/Constant'
     *  DataStoreRead: '<S2>/Data Store Read'
     *  Sum: '<S2>/Sum'
     */
    trigger_test_DW.A += trigger_test_P.Constant_Value;

    /* Math: '<S2>/Math Function' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    trigger_test_B.MathFunction = rt_modd_snf(sampleTime,
      trigger_test_P.Constant1_Value);
    trigger_test_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  trigger_test_PrevZCX.TriggeredSubsystem_Trig_ZCE = trigger_test_B.DigitalRead;

  /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, trigger_test_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(trigger_test_M)!=-1) &&
        !((rtmGetTFinal(trigger_test_M)-trigger_test_M->Timing.taskTime0) >
          trigger_test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(trigger_test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(trigger_test_M)) {
      rtmSetErrorStatus(trigger_test_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++trigger_test_M->Timing.clockTick0)) {
    ++trigger_test_M->Timing.clockTickH0;
  }

  trigger_test_M->Timing.taskTime0 = trigger_test_M->Timing.clockTick0 *
    trigger_test_M->Timing.stepSize0 + trigger_test_M->Timing.clockTickH0 *
    trigger_test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void trigger_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)trigger_test_M, 0,
                sizeof(RT_MODEL_trigger_test_T));
  rtmSetTFinal(trigger_test_M, -1);
  trigger_test_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  trigger_test_M->Sizes.checksums[0] = (3907093949U);
  trigger_test_M->Sizes.checksums[1] = (1811489758U);
  trigger_test_M->Sizes.checksums[2] = (1542038691U);
  trigger_test_M->Sizes.checksums[3] = (2591067875U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    trigger_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &trigger_test_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(trigger_test_M->extModeInfo,
      &trigger_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(trigger_test_M->extModeInfo,
                        trigger_test_M->Sizes.checksums);
    rteiSetTPtr(trigger_test_M->extModeInfo, rtmGetTPtr(trigger_test_M));
  }

  /* block I/O */
  (void) memset(((void *) &trigger_test_B), 0,
                sizeof(B_trigger_test_T));

  /* states (dwork) */
  (void) memset((void *)&trigger_test_DW, 0,
                sizeof(DW_trigger_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    trigger_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    real_T sampleTime;

    /* Start for MATLABSystem: '<S1>/Digital Read' */
    trigger_test_DW.obj.isInitialized = 0;
    trigger_test_DW.objisempty = true;
    if (((!rtIsInf(trigger_test_P.DigitalRead_SampleTime)) && (!rtIsNaN
          (trigger_test_P.DigitalRead_SampleTime))) || rtIsInf
        (trigger_test_P.DigitalRead_SampleTime)) {
      sampleTime = trigger_test_P.DigitalRead_SampleTime;
    }

    trigger_test_DW.obj.SampleTime = sampleTime;
    trigger_test_DW.obj.isInitialized = 1;
    MW_gpioInit((uint32_T)trigger_test_PinNumber, false);

    /* End of Start for MATLABSystem: '<S1>/Digital Read' */

    /* Start for Triggered SubSystem: '<Root>/Triggered Subsystem' */
    /* Start for DataStoreMemory: '<S2>/Data Store Memory' */
    trigger_test_DW.A = trigger_test_P.DataStoreMemory_InitialValue;

    /* End of Start for SubSystem: '<Root>/Triggered Subsystem' */
  }

  trigger_test_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Triggered Subsystem' */
  /* SystemInitialize for Outport: '<S2>/ON//OFF' */
  trigger_test_B.MathFunction = trigger_test_P.ONOFF_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Triggered Subsystem' */
}

/* Model terminate function */
void trigger_test_terminate(void)
{
  /* Start for MATLABSystem: '<S1>/Digital Read' incorporates:
   *  Terminate for MATLABSystem: '<S1>/Digital Read'
   */
  if (trigger_test_DW.obj.isInitialized == 1) {
    trigger_test_DW.obj.isInitialized = 2;
    MW_gpioTerminate((uint32_T)trigger_test_PinNumber);
  }

  /* End of Start for MATLABSystem: '<S1>/Digital Read' */
}
