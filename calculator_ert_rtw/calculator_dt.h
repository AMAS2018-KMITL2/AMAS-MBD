/*
 * calculator_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_linux_blocks_Digi_T),
  sizeof(codertarget_linux_blocks_Di_i_T),
  sizeof(codertarget_raspi_internal_SC_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_linux_blocks_Digi_T",
  "codertarget_linux_blocks_Di_i_T",
  "codertarget_raspi_internal_SC_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&calculator_B.ManualSwitch), 0, 0, 1 },

  { (char_T *)(&calculator_B.int8_1), 2, 0, 3 },

  { (char_T *)(&calculator_B.DataTypeConversion), 8, 0, 1 }
  ,

  { (char_T *)(&calculator_DW.obj), 14, 0, 1 },

  { (char_T *)(&calculator_DW.obj_p), 16, 0, 1 },

  { (char_T *)(&calculator_DW.A), 0, 0, 1 },

  { (char_T *)(&calculator_DW.Scope_PWORK.LoggedData), 11, 0, 6 },

  { (char_T *)(&calculator_DW.obj_o), 15, 0, 2 },

  { (char_T *)(&calculator_DW.FromWs_IWORK.PrevIndex), 10, 0, 1 },

  { (char_T *)(&calculator_DW.Switch_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&calculator_DW.objisempty), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&calculator_P.Constant_Value), 0, 0, 10 },

  { (char_T *)(&calculator_P.ManualSwitch_CurrentSetting), 3, 0, 6 },

  { (char_T *)(&calculator_P.ONOFF_Y0), 8, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] calculator_dt.h */
