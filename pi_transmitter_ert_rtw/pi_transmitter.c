/*
 * pi_transmitter.c
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

#include "pi_transmitter.h"
#include "pi_transmitter_private.h"
#include "pi_transmitter_dt.h"

/* Block signals (auto storage) */
B_pi_transmitter_T pi_transmitter_B;

/* Block states (auto storage) */
DW_pi_transmitter_T pi_transmitter_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_pi_transmitter_T pi_transmitter_PrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU_pi_transmitter_T pi_transmitter_U;

/* Real-time model */
RT_MODEL_pi_transmitter_T pi_transmitter_M_;
RT_MODEL_pi_transmitter_T *const pi_transmitter_M = &pi_transmitter_M_;
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
void pi_transmitter_step(void)
{
  uint8_T TxDataLocChar[3];
  real_T rtb_MathFunction;
  ZCEventType zcEvent;

  /* Reset subsysRan breadcrumbs */
  srClearBC(pi_transmitter_DW.Switch_SubsysRanBC);

  /* Outputs for Triggered SubSystem: '<Root>/Switch' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  /* Inport: '<Root>/ON//OFF' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &pi_transmitter_PrevZCX.Switch_Trig_ZCE,
                     (pi_transmitter_U.ONOFF));
  if (zcEvent != NO_ZCEVENT) {
    /* DataStoreRead: '<S2>/Data Store Read' */
    rtb_MathFunction = pi_transmitter_DW.A;

    /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
     *  Constant: '<S2>/Constant'
     *  DataStoreRead: '<S2>/Data Store Read'
     *  Sum: '<S2>/Sum'
     */
    pi_transmitter_DW.A += pi_transmitter_P.Constant_Value_j;

    /* Math: '<S2>/Math Function' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    rtb_MathFunction = rt_modd_snf(rtb_MathFunction,
      pi_transmitter_P.Constant1_Value_h);

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    pi_transmitter_B.DataTypeConversion = (rtb_MathFunction != 0.0);
    pi_transmitter_DW.Switch_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<Root>/Switch' */

  /* ManualSwitch: '<Root>/Manual Switch3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (pi_transmitter_P.ManualSwitch3_CurrentSetting == 1) {
    pi_transmitter_B.ManualSwitch3 = pi_transmitter_B.DataTypeConversion;
  } else {
    pi_transmitter_B.ManualSwitch3 = pi_transmitter_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch3' */

  /* Outputs for Atomic SubSystem: '<Root>/Main' */
  /* Switch: '<S1>/Switch_1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (pi_transmitter_B.ManualSwitch3 > pi_transmitter_P.Switch_1_Threshold) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Inport: '<Root>/Motor'
     */
    if (pi_transmitter_P.ManualSwitch_CurrentSetting == 1) {
      rtb_MathFunction = pi_transmitter_U.Motor;
    } else {
      rtb_MathFunction = pi_transmitter_P.Constant2_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */
  } else {
    rtb_MathFunction = pi_transmitter_P.Constant_Value_l;
  }

  /* End of Switch: '<S1>/Switch_1' */

  /* DataTypeConversion: '<S1>/int8_1' */
  rtb_MathFunction = floor(rtb_MathFunction);
  if (rtIsNaN(rtb_MathFunction) || rtIsInf(rtb_MathFunction)) {
    rtb_MathFunction = 0.0;
  } else {
    rtb_MathFunction = fmod(rtb_MathFunction, 256.0);
  }

  pi_transmitter_B.int8_1 = (int8_T)(rtb_MathFunction < 0.0 ? (int32_T)(int8_T)
    -(int8_T)(uint8_T)-rtb_MathFunction : (int32_T)(int8_T)(uint8_T)
    rtb_MathFunction);

  /* End of DataTypeConversion: '<S1>/int8_1' */

  /* Switch: '<S1>/Switch_2' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (pi_transmitter_B.ManualSwitch3 > pi_transmitter_P.Switch_2_Threshold) {
    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Inport: '<Root>/Steer'
     */
    if (pi_transmitter_P.ManualSwitch1_CurrentSetting == 1) {
      rtb_MathFunction = pi_transmitter_U.Steer;
    } else {
      rtb_MathFunction = pi_transmitter_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */
  } else {
    rtb_MathFunction = pi_transmitter_P.Constant_Value_l;
  }

  /* End of Switch: '<S1>/Switch_2' */

  /* DataTypeConversion: '<S1>/int8_2' */
  rtb_MathFunction = floor(rtb_MathFunction);
  if (rtIsNaN(rtb_MathFunction) || rtIsInf(rtb_MathFunction)) {
    rtb_MathFunction = 0.0;
  } else {
    rtb_MathFunction = fmod(rtb_MathFunction, 256.0);
  }

  pi_transmitter_B.int8_2 = (int8_T)(rtb_MathFunction < 0.0 ? (int32_T)(int8_T)
    -(int8_T)(uint8_T)-rtb_MathFunction : (int32_T)(int8_T)(uint8_T)
    rtb_MathFunction);

  /* End of DataTypeConversion: '<S1>/int8_2' */

  /* Switch: '<S1>/Switch_3' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (pi_transmitter_B.ManualSwitch3 > pi_transmitter_P.Switch_3_Threshold) {
    /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Inport: '<Root>/LidarServo'
     */
    if (pi_transmitter_P.ManualSwitch2_CurrentSetting == 1) {
      rtb_MathFunction = pi_transmitter_U.LidarServo;
    } else {
      rtb_MathFunction = pi_transmitter_P.Constant3_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */
  } else {
    rtb_MathFunction = pi_transmitter_P.Constant_Value_l;
  }

  /* End of Switch: '<S1>/Switch_3' */

  /* DataTypeConversion: '<S1>/int8_3' */
  rtb_MathFunction = floor(rtb_MathFunction);
  if (rtIsNaN(rtb_MathFunction) || rtIsInf(rtb_MathFunction)) {
    rtb_MathFunction = 0.0;
  } else {
    rtb_MathFunction = fmod(rtb_MathFunction, 256.0);
  }

  pi_transmitter_B.int8_3 = (int8_T)(rtb_MathFunction < 0.0 ? (int32_T)(int8_T)
    -(int8_T)(uint8_T)-rtb_MathFunction : (int32_T)(int8_T)(uint8_T)
    rtb_MathFunction);

  /* End of DataTypeConversion: '<S1>/int8_3' */
  /* End of Outputs for SubSystem: '<Root>/Main' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAtSerial WriteInport1' */
  pi_transmitter_B.TmpSignalConversionAtSerialWrit[0] = pi_transmitter_B.int8_3;
  pi_transmitter_B.TmpSignalConversionAtSerialWrit[1] = pi_transmitter_B.int8_2;
  pi_transmitter_B.TmpSignalConversionAtSerialWrit[2] = pi_transmitter_B.int8_1;

  /* S-Function (linuxLedWrite_sfcn): '<Root>/LED' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  MW_ledWrite(pi_transmitter_P.LED_p1, pi_transmitter_B.ManualSwitch3 != 0.0);

  /* Start for MATLABSystem: '<Root>/Serial Write' incorporates:
   *  MATLABSystem: '<Root>/Serial Write'
   */
  memcpy((void *)&TxDataLocChar[0], (void *)
         &pi_transmitter_B.TmpSignalConversionAtSerialWrit[0], (size_t)3 *
         sizeof(uint8_T));
  MW_SCI_Transmit(pi_transmitter_DW.obj.MW_SCIHANDLE, TxDataLocChar, 3U);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.025s, 0.0s] */
    rtExtModeUpload(0, pi_transmitter_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.025s, 0.0s] */
    if ((rtmGetTFinal(pi_transmitter_M)!=-1) &&
        !((rtmGetTFinal(pi_transmitter_M)-pi_transmitter_M->Timing.taskTime0) >
          pi_transmitter_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(pi_transmitter_M, "Simulation finished");
    }

    if (rtmGetStopRequested(pi_transmitter_M)) {
      rtmSetErrorStatus(pi_transmitter_M, "Simulation finished");
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
  if (!(++pi_transmitter_M->Timing.clockTick0)) {
    ++pi_transmitter_M->Timing.clockTickH0;
  }

  pi_transmitter_M->Timing.taskTime0 = pi_transmitter_M->Timing.clockTick0 *
    pi_transmitter_M->Timing.stepSize0 + pi_transmitter_M->Timing.clockTickH0 *
    pi_transmitter_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void pi_transmitter_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pi_transmitter_M, 0,
                sizeof(RT_MODEL_pi_transmitter_T));
  rtmSetTFinal(pi_transmitter_M, 5.0);
  pi_transmitter_M->Timing.stepSize0 = 0.025;

  /* External mode info */
  pi_transmitter_M->Sizes.checksums[0] = (1244592533U);
  pi_transmitter_M->Sizes.checksums[1] = (1100557078U);
  pi_transmitter_M->Sizes.checksums[2] = (4155620994U);
  pi_transmitter_M->Sizes.checksums[3] = (2205770055U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    pi_transmitter_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)&pi_transmitter_DW.Switch_SubsysRanBC;
    rteiSetModelMappingInfoPtr(pi_transmitter_M->extModeInfo,
      &pi_transmitter_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pi_transmitter_M->extModeInfo,
                        pi_transmitter_M->Sizes.checksums);
    rteiSetTPtr(pi_transmitter_M->extModeInfo, rtmGetTPtr(pi_transmitter_M));
  }

  /* block I/O */
  (void) memset(((void *) &pi_transmitter_B), 0,
                sizeof(B_pi_transmitter_T));

  /* states (dwork) */
  (void) memset((void *)&pi_transmitter_DW, 0,
                sizeof(DW_pi_transmitter_T));

  /* external inputs */
  (void)memset((void *)&pi_transmitter_U, 0, sizeof(ExtU_pi_transmitter_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pi_transmitter_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_raspi_internal_SC_T *obj;
    uint32_T RxPinLoc;
    uint32_T TxPinLoc;
    char_T SCIModuleLoc[11];
    MW_SCI_StopBits_Type StopBitsValue;
    MW_SCI_Parity_Type ParityValue;
    static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
      '0' };

    int32_T i;

    /* Start for Triggered SubSystem: '<Root>/Switch' */
    /* Start for DataStoreMemory: '<S2>/Data Store Memory' */
    pi_transmitter_DW.A = pi_transmitter_P.DataStoreMemory_InitialValue;

    /* End of Start for SubSystem: '<Root>/Switch' */

    /* Start for S-Function (linuxLedWrite_sfcn): '<Root>/LED' */
    MW_ledInit(pi_transmitter_P.LED_p1);

    /* Start for MATLABSystem: '<Root>/Serial Write' */
    pi_transmitter_DW.obj.isInitialized = 0;
    pi_transmitter_DW.objisempty = true;
    obj = &pi_transmitter_DW.obj;
    pi_transmitter_DW.obj.isInitialized = 1;
    RxPinLoc = MW_UNDEFINED_VALUE;
    TxPinLoc = MW_UNDEFINED_VALUE;
    pi_transmitter_DW.obj.MW_SCIHANDLE = 0U;
    for (i = 0; i < 10; i++) {
      SCIModuleLoc[i] = tmp[i];
    }

    SCIModuleLoc[10] = '\x00';
    obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleLoc, true, RxPinLoc, TxPinLoc);
    MW_SCI_SetBaudrate(pi_transmitter_DW.obj.MW_SCIHANDLE, 9600U);
    StopBitsValue = MW_SCI_STOPBITS_1;
    ParityValue = MW_SCI_PARITY_NONE;
    MW_SCI_SetFrameFormat(pi_transmitter_DW.obj.MW_SCIHANDLE, 8U, ParityValue,
                          StopBitsValue);

    /* End of Start for MATLABSystem: '<Root>/Serial Write' */
  }

  pi_transmitter_PrevZCX.Switch_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Switch' */
  /* SystemInitialize for Outport: '<S2>/ON//OFF' */
  pi_transmitter_B.DataTypeConversion = pi_transmitter_P.ONOFF_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Switch' */
}

/* Model terminate function */
void pi_transmitter_terminate(void)
{
  /* Terminate for S-Function (linuxLedWrite_sfcn): '<Root>/LED' */
  MW_ledTerminate(pi_transmitter_P.LED_p1);

  /* Start for MATLABSystem: '<Root>/Serial Write' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Serial Write'
   */
  if (pi_transmitter_DW.obj.isInitialized == 1) {
    pi_transmitter_DW.obj.isInitialized = 2;
    MW_SCI_Close(pi_transmitter_DW.obj.MW_SCIHANDLE);
  }

  /* End of Start for MATLABSystem: '<Root>/Serial Write' */
}
