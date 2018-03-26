/*
 * pi_transmitter_types.h
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

#ifndef RTW_HEADER_pi_transmitter_types_h_
#define RTW_HEADER_pi_transmitter_types_h_
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

#ifndef typedef_struct_T_pi_transmitter_T
#define typedef_struct_T_pi_transmitter_T

typedef struct {
  real_T f1[2];
} struct_T_pi_transmitter_T;

#endif                                 /*typedef_struct_T_pi_transmitter_T*/

#ifndef typedef_struct_T_pi_transmitter_c_T
#define typedef_struct_T_pi_transmitter_c_T

typedef struct {
  char_T f1[7];
} struct_T_pi_transmitter_c_T;

#endif                                 /*typedef_struct_T_pi_transmitter_c_T*/

#ifndef typedef_struct_T_pi_transmitter_cz_T
#define typedef_struct_T_pi_transmitter_cz_T

typedef struct {
  char_T f1[11];
  char_T f2[6];
} struct_T_pi_transmitter_cz_T;

#endif                                 /*typedef_struct_T_pi_transmitter_cz_T*/

#ifndef typedef_struct_T_pi_transmitter_cza_T
#define typedef_struct_T_pi_transmitter_cza_T

typedef struct {
  char_T f1[11];
  char_T f2[6];
  char_T f3[7];
  char_T f4[2];
  uint8_T f5;
} struct_T_pi_transmitter_cza_T;

#endif                                 /*typedef_struct_T_pi_transmitter_cza_T*/

#ifndef typedef_struct_T_pi_transmitter_czab_T
#define typedef_struct_T_pi_transmitter_czab_T

typedef struct {
  char_T f1[11];
  char_T f2[6];
  char_T f3[2];
  real_T f4;
  char_T f5[2];
  real_T f6;
} struct_T_pi_transmitter_czab_T;

#endif                                 /*typedef_struct_T_pi_transmitter_czab_T*/

#ifndef typedef_struct_T_pi_transmitter_czabs_T
#define typedef_struct_T_pi_transmitter_czabs_T

typedef struct {
  char_T f1[11];
  char_T f2[6];
  char_T f3[7];
  char_T f4[2];
  uint8_T f5;
  char_T f6[2];
  uint8_T f7;
} struct_T_pi_transmitter_czabs_T;

#endif                                 /*typedef_struct_T_pi_transmitter_czabs_T*/

#ifndef typedef_struct_T_pi_transmitte_czabst_T
#define typedef_struct_T_pi_transmitte_czabst_T

typedef struct {
  char_T f1[4];
  char_T f2[5];
  char_T f3[5];
  char_T f4[6];
  char_T f5[5];
  char_T f6[6];
  char_T f7[6];
  char_T f8[6];
} struct_T_pi_transmitte_czabst_T;

#endif                                 /*typedef_struct_T_pi_transmitte_czabst_T*/

/* Parameters (auto storage) */
typedef struct P_pi_transmitter_T_ P_pi_transmitter_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_pi_transmitter_T RT_MODEL_pi_transmitter_T;

#endif                                 /* RTW_HEADER_pi_transmitter_types_h_ */
