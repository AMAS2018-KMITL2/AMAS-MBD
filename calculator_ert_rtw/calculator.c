/*
 * calculator.c
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

#include "calculator.h"
#include "calculator_private.h"
#include "calculator_dt.h"
#define calculator_PinNumber           (22.0)
#define calculator_PinNumber_i         (21.0)
#define calculator_PinNumber_ia        (20.0)

/* Block signals (auto storage) */
B_calculator_T calculator_B;

/* Block states (auto storage) */
DW_calculator_T calculator_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_calculator_T calculator_PrevZCX;

/* Real-time model */
RT_MODEL_calculator_T calculator_M_;
RT_MODEL_calculator_T *const calculator_M = &calculator_M_;
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

/* Model step function */
void calculator_step(void)
{
  boolean_T p;
  boolean_T p_0;
  real_T sampleTime;
  uint8_T TxDataLocChar[3];
  int8_T rtb_TmpSignalConversionAtSerial[3];
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(calculator_DW.Switch_SubsysRanBC);

  /* Start for MATLABSystem: '<S1>/Digital Read' incorporates:
   *  MATLABSystem: '<S1>/Digital Read'
   */
  p = false;
  p_0 = true;
  if (!(calculator_DW.obj.SampleTime == calculator_P.DigitalRead_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(calculator_P.DigitalRead_SampleTime)) && (!rtIsNaN
          (calculator_P.DigitalRead_SampleTime))) || rtIsInf
        (calculator_P.DigitalRead_SampleTime)) {
      sampleTime = calculator_P.DigitalRead_SampleTime;
    }

    calculator_DW.obj.SampleTime = sampleTime;
  }

  /* MATLABSystem: '<S1>/Digital Read' incorporates:
   *  Start for MATLABSystem: '<S1>/Digital Read'
   */
  p = MW_gpioRead((uint32_T)calculator_PinNumber);

  /* Outputs for Triggered SubSystem: '<Root>/Switch' incorporates:
   *  TriggerPort: '<S5>/Trigger'
   */
  if (p && (calculator_PrevZCX.Switch_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreRead: '<S5>/Data Store Read' */
    sampleTime = calculator_DW.A;

    /* DataStoreWrite: '<S5>/Data Store Write' incorporates:
     *  Constant: '<S5>/Constant'
     *  DataStoreRead: '<S5>/Data Store Read'
     *  Sum: '<S5>/Sum'
     */
    calculator_DW.A += calculator_P.Constant_Value_h;

    /* Math: '<S5>/Math Function' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    sampleTime = rt_modd_snf(sampleTime, calculator_P.Constant1_Value);

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    calculator_B.DataTypeConversion = (sampleTime != 0.0);
    calculator_DW.Switch_SubsysRanBC = 4;
  }

  calculator_PrevZCX.Switch_Trig_ZCE = p;

  /* End of Outputs for SubSystem: '<Root>/Switch' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (calculator_P.ManualSwitch_CurrentSetting == 1) {
    calculator_B.ManualSwitch = calculator_B.DataTypeConversion;
  } else {
    calculator_B.ManualSwitch = calculator_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Outputs for Atomic SubSystem: '<Root>/Main' */
  /* FromWorkspace: '<S6>/FromWs' */
  {
    real_T *pDataValues = (real_T *) calculator_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) calculator_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = calculator_DW.FromWs_IWORK.PrevIndex;
    real_T t = calculator_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[27]) {
      currTimeIndex = 26;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    calculator_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 6; ++elIdx) {
              (&calculator_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex];
              pDataValues += 28;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 6; ++elIdx) {
              (&calculator_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex + 1];
              pDataValues += 28;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 6; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&calculator_B.FromWs[0])[elIdx] = (real_T) rtInterpolate(d1, d2, f1,
              f2);
            pDataValues += 28;
          }
        }
      }
    }
  }

  /* Switch: '<S4>/Switch_1' */
  if (calculator_B.ManualSwitch > calculator_P.Switch_1_Threshold) {
    /* DataTypeConversion: '<S4>/int8_1' */
    sampleTime = floor(calculator_B.FromWs[0]);
    if (rtIsNaN(sampleTime) || rtIsInf(sampleTime)) {
      sampleTime = 0.0;
    } else {
      sampleTime = fmod(sampleTime, 256.0);
    }

    calculator_B.int8_1 = (int8_T)(sampleTime < 0.0 ? (int32_T)(int8_T)-(int8_T)
      (uint8_T)-sampleTime : (int32_T)(int8_T)(uint8_T)sampleTime);
  } else {
    /* DataTypeConversion: '<S4>/int8_1' incorporates:
     *  Constant: '<S4>/Constant'
     */
    sampleTime = floor(calculator_P.Constant_Value_o);
    if (rtIsNaN(sampleTime) || rtIsInf(sampleTime)) {
      sampleTime = 0.0;
    } else {
      sampleTime = fmod(sampleTime, 256.0);
    }

    calculator_B.int8_1 = (int8_T)(sampleTime < 0.0 ? (int32_T)(int8_T)-(int8_T)
      (uint8_T)-sampleTime : (int32_T)(int8_T)(uint8_T)sampleTime);
  }

  /* End of Switch: '<S4>/Switch_1' */

  /* Switch: '<S4>/Switch_2' */
  if (calculator_B.ManualSwitch > calculator_P.Switch_2_Threshold) {
    /* DataTypeConversion: '<S4>/int8_2' */
    sampleTime = floor(calculator_B.FromWs[1]);
    if (rtIsNaN(sampleTime) || rtIsInf(sampleTime)) {
      sampleTime = 0.0;
    } else {
      sampleTime = fmod(sampleTime, 256.0);
    }

    calculator_B.int8_2 = (int8_T)(sampleTime < 0.0 ? (int32_T)(int8_T)-(int8_T)
      (uint8_T)-sampleTime : (int32_T)(int8_T)(uint8_T)sampleTime);
  } else {
    /* DataTypeConversion: '<S4>/int8_2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    sampleTime = floor(calculator_P.Constant_Value_o);
    if (rtIsNaN(sampleTime) || rtIsInf(sampleTime)) {
      sampleTime = 0.0;
    } else {
      sampleTime = fmod(sampleTime, 256.0);
    }

    calculator_B.int8_2 = (int8_T)(sampleTime < 0.0 ? (int32_T)(int8_T)-(int8_T)
      (uint8_T)-sampleTime : (int32_T)(int8_T)(uint8_T)sampleTime);
  }

  /* End of Switch: '<S4>/Switch_2' */

  /* Switch: '<S4>/Switch_3' */
  if (calculator_B.ManualSwitch > calculator_P.Switch_3_Threshold) {
    /* DataTypeConversion: '<S4>/int8_3' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    sampleTime = floor(calculator_P.Constant2_Value);
    if (rtIsNaN(sampleTime) || rtIsInf(sampleTime)) {
      sampleTime = 0.0;
    } else {
      sampleTime = fmod(sampleTime, 256.0);
    }

    calculator_B.int8_3 = (int8_T)(sampleTime < 0.0 ? (int32_T)(int8_T)-(int8_T)
      (uint8_T)-sampleTime : (int32_T)(int8_T)(uint8_T)sampleTime);
  } else {
    /* DataTypeConversion: '<S4>/int8_3' incorporates:
     *  Constant: '<S4>/Constant'
     */
    sampleTime = floor(calculator_P.Constant_Value_o);
    if (rtIsNaN(sampleTime) || rtIsInf(sampleTime)) {
      sampleTime = 0.0;
    } else {
      sampleTime = fmod(sampleTime, 256.0);
    }

    calculator_B.int8_3 = (int8_T)(sampleTime < 0.0 ? (int32_T)(int8_T)-(int8_T)
      (uint8_T)-sampleTime : (int32_T)(int8_T)(uint8_T)sampleTime);
  }

  /* End of Switch: '<S4>/Switch_3' */
  /* End of Outputs for SubSystem: '<Root>/Main' */

  /* Start for MATLABSystem: '<S2>/Digital Write' incorporates:
   *  MATLABSystem: '<S2>/Digital Write'
   */
  sampleTime = rt_roundd_snf(calculator_B.FromWs[3]);
  if (sampleTime < 256.0) {
    if (sampleTime >= 0.0) {
      tmp = (uint8_T)sampleTime;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  MW_gpioWrite((uint32_T)calculator_PinNumber_i, tmp);

  /* End of Start for MATLABSystem: '<S2>/Digital Write' */

  /* Start for MATLABSystem: '<S3>/Digital Write' incorporates:
   *  MATLABSystem: '<S3>/Digital Write'
   */
  sampleTime = rt_roundd_snf(calculator_B.FromWs[4]);
  if (sampleTime < 256.0) {
    if (sampleTime >= 0.0) {
      tmp = (uint8_T)sampleTime;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  MW_gpioWrite((uint32_T)calculator_PinNumber_ia, tmp);

  /* End of Start for MATLABSystem: '<S3>/Digital Write' */

  /* S-Function (linuxLedWrite_sfcn): '<Root>/LED' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  MW_ledWrite(calculator_P.LED_p1, calculator_B.ManualSwitch != 0.0);

  /* SignalConversion: '<Root>/TmpSignal ConversionAtSerial WriteInport1' */
  rtb_TmpSignalConversionAtSerial[0] = calculator_B.int8_1;
  rtb_TmpSignalConversionAtSerial[1] = calculator_B.int8_2;
  rtb_TmpSignalConversionAtSerial[2] = calculator_B.int8_3;

  /* Start for MATLABSystem: '<Root>/Serial Write' incorporates:
   *  MATLABSystem: '<Root>/Serial Write'
   */
  memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
         (size_t)3 * sizeof(uint8_T));
  MW_SCI_Transmit(calculator_DW.obj_p.MW_SCIHANDLE, TxDataLocChar, 3U);

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, calculator_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(1, (((calculator_M->Timing.clockTick1+
                          calculator_M->Timing.clockTickH1* 4294967296.0)) * 0.1));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(calculator_M)!=-1) &&
        !((rtmGetTFinal(calculator_M)-calculator_M->Timing.t[0]) >
          calculator_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(calculator_M, "Simulation finished");
    }

    if (rtmGetStopRequested(calculator_M)) {
      rtmSetErrorStatus(calculator_M, "Simulation finished");
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
  if (!(++calculator_M->Timing.clockTick0)) {
    ++calculator_M->Timing.clockTickH0;
  }

  calculator_M->Timing.t[0] = calculator_M->Timing.clockTick0 *
    calculator_M->Timing.stepSize0 + calculator_M->Timing.clockTickH0 *
    calculator_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    calculator_M->Timing.clockTick1++;
    if (!calculator_M->Timing.clockTick1) {
      calculator_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void calculator_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)calculator_M, 0,
                sizeof(RT_MODEL_calculator_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&calculator_M->solverInfo,
                          &calculator_M->Timing.simTimeStep);
    rtsiSetTPtr(&calculator_M->solverInfo, &rtmGetTPtr(calculator_M));
    rtsiSetStepSizePtr(&calculator_M->solverInfo,
                       &calculator_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&calculator_M->solverInfo, (&rtmGetErrorStatus
      (calculator_M)));
    rtsiSetRTModelPtr(&calculator_M->solverInfo, calculator_M);
  }

  rtsiSetSimTimeStep(&calculator_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&calculator_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(calculator_M, &calculator_M->Timing.tArray[0]);
  rtmSetTFinal(calculator_M, 10.0);
  calculator_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  calculator_M->Sizes.checksums[0] = (1594597444U);
  calculator_M->Sizes.checksums[1] = (1336844780U);
  calculator_M->Sizes.checksums[2] = (18666395U);
  calculator_M->Sizes.checksums[3] = (2541377075U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    calculator_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)&calculator_DW.Switch_SubsysRanBC;
    rteiSetModelMappingInfoPtr(calculator_M->extModeInfo,
      &calculator_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(calculator_M->extModeInfo, calculator_M->Sizes.checksums);
    rteiSetTPtr(calculator_M->extModeInfo, rtmGetTPtr(calculator_M));
  }

  /* block I/O */
  (void) memset(((void *) &calculator_B), 0,
                sizeof(B_calculator_T));

  /* states (dwork) */
  (void) memset((void *)&calculator_DW, 0,
                sizeof(DW_calculator_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    calculator_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    real_T sampleTime;
    codertarget_raspi_internal_SC_T *obj;
    uint32_T RxPinLoc;
    uint32_T TxPinLoc;
    char_T SCIModuleLoc[11];
    MW_SCI_StopBits_Type StopBitsValue;
    MW_SCI_Parity_Type ParityValue;
    static const char_T tmp[10] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'S',
      '0' };

    int32_T i;

    /* Start for MATLABSystem: '<S1>/Digital Read' */
    calculator_DW.obj.isInitialized = 0;
    calculator_DW.objisempty_c = true;
    if (((!rtIsInf(calculator_P.DigitalRead_SampleTime)) && (!rtIsNaN
          (calculator_P.DigitalRead_SampleTime))) || rtIsInf
        (calculator_P.DigitalRead_SampleTime)) {
      sampleTime = calculator_P.DigitalRead_SampleTime;
    }

    calculator_DW.obj.SampleTime = sampleTime;
    calculator_DW.obj.isInitialized = 1;
    MW_gpioInit((uint32_T)calculator_PinNumber, false);

    /* End of Start for MATLABSystem: '<S1>/Digital Read' */

    /* Start for Triggered SubSystem: '<Root>/Switch' */
    /* Start for DataStoreMemory: '<S5>/Data Store Memory' */
    calculator_DW.A = calculator_P.DataStoreMemory_InitialValue;

    /* End of Start for SubSystem: '<Root>/Switch' */

    /* Start for Atomic SubSystem: '<Root>/Main' */

    /* Start for FromWorkspace: '<S6>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 3.0, 3.0, 3.35, 3.35, 3.6, 3.6, 3.95,
        3.95, 4.0, 4.0, 4.3, 4.3, 4.65, 4.65, 5.0, 5.0, 5.3500000000000005,
        5.3500000000000005, 5.65, 5.65, 6.0, 6.0, 7.0, 7.0, 8.0, 8.0, 10.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, -1.0,
        -1.0, 0.0, 0.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0,
        -1.0, -1.0, -1.0, -1.0, 45.0, 45.0, 0.0, 0.0, 0.0, 0.0, 100.0, 100.0,
        100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
        100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 50.0, 50.0, 50.0,
        50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0 } ;

      calculator_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
      calculator_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
      calculator_DW.FromWs_IWORK.PrevIndex = 0;
    }

    /* End of Start for SubSystem: '<Root>/Main' */

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    calculator_DW.obj_oh.isInitialized = 0;
    calculator_DW.objisempty_n = true;
    calculator_DW.obj_oh.isInitialized = 1;
    MW_gpioInit((uint32_T)calculator_PinNumber_i, true);

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    calculator_DW.obj_o.isInitialized = 0;
    calculator_DW.objisempty = true;
    calculator_DW.obj_o.isInitialized = 1;
    MW_gpioInit((uint32_T)calculator_PinNumber_ia, true);

    /* Start for S-Function (linuxLedWrite_sfcn): '<Root>/LED' */
    MW_ledInit(calculator_P.LED_p1);

    /* Start for MATLABSystem: '<Root>/Serial Write' */
    calculator_DW.obj_p.isInitialized = 0;
    calculator_DW.objisempty_m = true;
    obj = &calculator_DW.obj_p;
    calculator_DW.obj_p.isInitialized = 1;
    RxPinLoc = MW_UNDEFINED_VALUE;
    TxPinLoc = MW_UNDEFINED_VALUE;
    calculator_DW.obj_p.MW_SCIHANDLE = 0U;
    for (i = 0; i < 10; i++) {
      SCIModuleLoc[i] = tmp[i];
    }

    SCIModuleLoc[10] = '\x00';
    obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleLoc, true, RxPinLoc, TxPinLoc);
    MW_SCI_SetBaudrate(calculator_DW.obj_p.MW_SCIHANDLE, 9600U);
    StopBitsValue = MW_SCI_STOPBITS_1;
    ParityValue = MW_SCI_PARITY_NONE;
    MW_SCI_SetFrameFormat(calculator_DW.obj_p.MW_SCIHANDLE, 8U, ParityValue,
                          StopBitsValue);

    /* End of Start for MATLABSystem: '<Root>/Serial Write' */
  }

  calculator_PrevZCX.Switch_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Switch' */
  /* SystemInitialize for Outport: '<S5>/ON//OFF' */
  calculator_B.DataTypeConversion = calculator_P.ONOFF_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Switch' */
}

/* Model terminate function */
void calculator_terminate(void)
{
  /* Start for MATLABSystem: '<S1>/Digital Read' incorporates:
   *  Terminate for MATLABSystem: '<S1>/Digital Read'
   */
  if (calculator_DW.obj.isInitialized == 1) {
    calculator_DW.obj.isInitialized = 2;
    MW_gpioTerminate((uint32_T)calculator_PinNumber);
  }

  /* End of Start for MATLABSystem: '<S1>/Digital Read' */

  /* Start for MATLABSystem: '<S2>/Digital Write' incorporates:
   *  Terminate for MATLABSystem: '<S2>/Digital Write'
   */
  if (calculator_DW.obj_oh.isInitialized == 1) {
    calculator_DW.obj_oh.isInitialized = 2;
    MW_gpioTerminate((uint32_T)calculator_PinNumber_i);
  }

  /* End of Start for MATLABSystem: '<S2>/Digital Write' */

  /* Start for MATLABSystem: '<S3>/Digital Write' incorporates:
   *  Terminate for MATLABSystem: '<S3>/Digital Write'
   */
  if (calculator_DW.obj_o.isInitialized == 1) {
    calculator_DW.obj_o.isInitialized = 2;
    MW_gpioTerminate((uint32_T)calculator_PinNumber_ia);
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Write' */

  /* Terminate for S-Function (linuxLedWrite_sfcn): '<Root>/LED' */
  MW_ledTerminate(calculator_P.LED_p1);

  /* Start for MATLABSystem: '<Root>/Serial Write' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Serial Write'
   */
  if (calculator_DW.obj_p.isInitialized == 1) {
    calculator_DW.obj_p.isInitialized = 2;
    MW_SCI_Close(calculator_DW.obj_p.MW_SCIHANDLE);
  }

  /* End of Start for MATLABSystem: '<Root>/Serial Write' */
}
