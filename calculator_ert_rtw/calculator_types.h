/*
 * calculator_types.h
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

#ifndef RTW_HEADER_calculator_types_h_
#define RTW_HEADER_calculator_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_codertarget_raspi_internal_Ha_T
#define typedef_codertarget_raspi_internal_Ha_T

typedef struct {
  int32_T dummy;
} codertarget_raspi_internal_Ha_T;

#endif                                 /*typedef_codertarget_raspi_internal_Ha_T*/

#ifndef typedef_codertarget_raspi_internal_SC_T
#define typedef_codertarget_raspi_internal_SC_T

typedef struct {
  int32_T isInitialized;
  codertarget_raspi_internal_Ha_T Hw;
  uint32_T MW_SCIHANDLE;
} codertarget_raspi_internal_SC_T;

#endif                                 /*typedef_codertarget_raspi_internal_SC_T*/

#ifndef typedef_codertarget_linux_blocks_Digi_T
#define typedef_codertarget_linux_blocks_Digi_T

typedef struct {
  int32_T isInitialized;
  real_T SampleTime;
} codertarget_linux_blocks_Digi_T;

#endif                                 /*typedef_codertarget_linux_blocks_Digi_T*/

#ifndef typedef_codertarget_linux_blocks_Di_i_T
#define typedef_codertarget_linux_blocks_Di_i_T

typedef struct {
  int32_T isInitialized;
} codertarget_linux_blocks_Di_i_T;

#endif                                 /*typedef_codertarget_linux_blocks_Di_i_T*/

#ifndef typedef_struct_T_calculator_T
#define typedef_struct_T_calculator_T

typedef struct {
  real_T f1[2];
} struct_T_calculator_T;

#endif                                 /*typedef_struct_T_calculator_T*/

#ifndef typedef_struct_T_calculator_i_T
#define typedef_struct_T_calculator_i_T

typedef struct {
  char_T f1[7];
} struct_T_calculator_i_T;

#endif                                 /*typedef_struct_T_calculator_i_T*/

#ifndef typedef_struct_T_calculator_ia_T
#define typedef_struct_T_calculator_ia_T

typedef struct {
  char_T f1[11];
  char_T f2[6];
} struct_T_calculator_ia_T;

#endif                                 /*typedef_struct_T_calculator_ia_T*/

#ifndef typedef_struct_T_calculator_iaw_T
#define typedef_struct_T_calculator_iaw_T

typedef struct {
  char_T f1[11];
  char_T f2[6];
  char_T f3[7];
  char_T f4[2];
  uint8_T f5;
} struct_T_calculator_iaw_T;

#endif                                 /*typedef_struct_T_calculator_iaw_T*/

#ifndef typedef_struct_T_calculator_iawe_T
#define typedef_struct_T_calculator_iawe_T

typedef struct {
  char_T f1[11];
  char_T f2[6];
  char_T f3[2];
  real_T f4;
  char_T f5[2];
  real_T f6;
} struct_T_calculator_iawe_T;

#endif                                 /*typedef_struct_T_calculator_iawe_T*/

#ifndef typedef_struct_T_calculator_iawef_T
#define typedef_struct_T_calculator_iawef_T

typedef struct {
  char_T f1[11];
  char_T f2[6];
  char_T f3[7];
  char_T f4[2];
  uint8_T f5;
  char_T f6[2];
  uint8_T f7;
} struct_T_calculator_iawef_T;

#endif                                 /*typedef_struct_T_calculator_iawef_T*/

#ifndef typedef_struct_T_calculator_iawef4_T
#define typedef_struct_T_calculator_iawef4_T

typedef struct {
  char_T f1[4];
  char_T f2[5];
  char_T f3[5];
  char_T f4[6];
  char_T f5[5];
  char_T f6[6];
  char_T f7[6];
  char_T f8[6];
} struct_T_calculator_iawef4_T;

#endif                                 /*typedef_struct_T_calculator_iawef4_T*/

#ifndef typedef_struct_T_calculator_iawef4y_T
#define typedef_struct_T_calculator_iawef4y_T

typedef struct {
  char_T f1[4];
  char_T f2[11];
  char_T f3[7];
  char_T f4[6];
} struct_T_calculator_iawef4y_T;

#endif                                 /*typedef_struct_T_calculator_iawef4y_T*/

/* Parameters (auto storage) */
typedef struct P_calculator_T_ P_calculator_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_calculator_T RT_MODEL_calculator_T;

#endif                                 /* RTW_HEADER_calculator_types_h_ */
