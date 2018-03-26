/*
 * pi_transmitter_data.c
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

/* Block parameters (auto storage) */
P_pi_transmitter_T pi_transmitter_P = {
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch_3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S2>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch2'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch3'
                                        */

  /*  Expression: deviceFile
   * Referenced by: '<Root>/LED'
   */
  { 108U, 101U, 100U, 48U, 0U },
  0                                    /* Computed Parameter: ONOFF_Y0
                                        * Referenced by: '<S2>/ON//OFF'
                                        */
};
