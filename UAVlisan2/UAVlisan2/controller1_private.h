/*
 * File: controller1_private.h
 *
 * Code generated for Simulink model 'controller1'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jan 13 15:41:37 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller1_private_h_
#define RTW_HEADER_controller1_private_h_
#include "rtwtypes.h"
#include "controller1.h"
#include "controller1_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void controller1_f1_1D_fuzzy(real_T rtu_u, real_T *rty_fuzzy,
  B_f1_1D_fuzzy_controller1_T *localB);
extern void controller1_f4_3D_fuzzy(const real_T rtu_u[3], real_T *rty_fuzzy,
  B_f4_3D_fuzzy_controller1_T *localB);

#endif                                 /* RTW_HEADER_controller1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
