/*
 * trigger_test_types.h
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

#ifndef RTW_HEADER_trigger_test_types_h_
#define RTW_HEADER_trigger_test_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_codertarget_linux_blocks_Digi_T
#define typedef_codertarget_linux_blocks_Digi_T

typedef struct {
  int32_T isInitialized;
  real_T SampleTime;
} codertarget_linux_blocks_Digi_T;

#endif                                 /*typedef_codertarget_linux_blocks_Digi_T*/

#ifndef typedef_struct_T_trigger_test_T
#define typedef_struct_T_trigger_test_T

typedef struct {
  char_T f1[7];
} struct_T_trigger_test_T;

#endif                                 /*typedef_struct_T_trigger_test_T*/

#ifndef typedef_struct_T_trigger_test_b_T
#define typedef_struct_T_trigger_test_b_T

typedef struct {
  char_T f1[4];
  char_T f2[11];
  char_T f3[7];
  char_T f4[6];
} struct_T_trigger_test_b_T;

#endif                                 /*typedef_struct_T_trigger_test_b_T*/

/* Parameters (auto storage) */
typedef struct P_trigger_test_T_ P_trigger_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_trigger_test_T RT_MODEL_trigger_test_T;

#endif                                 /* RTW_HEADER_trigger_test_types_h_ */
