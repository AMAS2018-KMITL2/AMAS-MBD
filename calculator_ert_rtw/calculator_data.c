/*
 * calculator_data.c
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

/* Block parameters (auto storage) */
P_calculator_T calculator_P = {
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.1,                                 /* Expression: sampleTime
                                        * Referenced by: '<S1>/Digital Read'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Switch_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Switch_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Switch_3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S5>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Data Store Memory'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */

  /*  Expression: deviceFile
   * Referenced by: '<Root>/LED'
   */
  { 108U, 101U, 100U, 48U, 0U },
  0                                    /* Computed Parameter: ONOFF_Y0
                                        * Referenced by: '<S5>/ON//OFF'
                                        */
};
