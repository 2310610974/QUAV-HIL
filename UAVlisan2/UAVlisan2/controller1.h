/*
 * File: controller1.h
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

#ifndef RTW_HEADER_controller1_h_
#define RTW_HEADER_controller1_h_
#ifndef controller1_COMMON_INCLUDES_
#define controller1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* controller1_COMMON_INCLUDES_ */

#include "controller1_types.h"
#include <string.h>
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S5>/f1_1D_fuzzy' */
typedef struct {
  real_T mu_F1[11];
} B_f1_1D_fuzzy_controller1_T;

/* Block signals for system '<S5>/f4_3D_fuzzy' */
typedef struct {
  real_T PSI[1331];
  real_T mu_F1[11];
  real_T mu_F2[11];
  real_T mu_F3[11];
} B_f4_3D_fuzzy_controller1_T;

/* Block signals (default storage) */
typedef struct {
  real_T PSI[121];
  real_T mu_F1[11];
  real_T mu_F2[11];
  real_T c_a[9];
  real_T xd[6];                        /* '<Root>/controler ' */
  real_T Uk1[6];                       /* '<S3>/UD' */
  real_T Diff_p[6];
  real_T TSamp_o[6];                   /* '<S2>/TSamp' */
  real_T D_beta[4];                    /* '<Root>/controler ' */
  real_T zp1[3];
  real_T D_p[3];
  real_T zp2[3];
  real_T zp2_tmp[3];
  real_T zp2_tmp_m[3];
  real_T h_a[3];
  real_T d_a[3];
  real_T Diff_p_c[3];
  real_T a[3];
  real_T P;                            /* '<Root>/controler ' */
  real_T V;                            /* '<Root>/controler ' */
  real_T all;
  real_T d_norm;
  real_T z14;
  real_T M11;
  real_T M12;
  real_T absxk;
  real_T t;
  real_T Clock2;                       /* '<Root>/Clock2' */
  real_T rtb_fuzzy_l_k;
  real_T rtb_fuzzy_b_c;
  real_T rtb_fuzzy_od_b;
  real_T rtb_fuzzy_g_p;
  real_T rtb_fuzzy_o_c;
  B_f4_3D_fuzzy_controller1_T sf_f5_3D_fuzzy;/* '<S5>/f5_3D_fuzzy' */
  B_f4_3D_fuzzy_controller1_T sf_f4_3D_fuzzy;/* '<S5>/f4_3D_fuzzy' */
  B_f1_1D_fuzzy_controller1_T sf_f3_1D_fuzzy;/* '<S5>/f3_1D_fuzzy' */
  B_f1_1D_fuzzy_controller1_T sf_f2_1D_fuzzy;/* '<S5>/f2_1D_fuzzy' */
  B_f1_1D_fuzzy_controller1_T sf_f1_1D_fuzzy;/* '<S5>/f1_1D_fuzzy' */
} B_controller1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE[6];                 /* '<S3>/UD' */
  real_T DiscreteTransferFcn_states;   /* '<S1>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn2_states;  /* '<S1>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn1_states;  /* '<S1>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn3_states;  /* '<S1>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4_states;  /* '<S1>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5_states;  /* '<S1>/Discrete Transfer Fcn5' */
  real_T UD_DSTATE_k[6];               /* '<S2>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<Root>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<Root>/Discrete-Time Integrator2' */
} DW_controller1_T;

/* Real-time Model Data Structure */
struct tag_RTM_controller1_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  B_controller1_T *blockIO;
  DW_controller1_T *dwork;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Model entry point functions */
extern void controller1_initialize(RT_MODEL_controller1_T *const controller1_M,
  real_T controller1_U_In1[6], real_T controller1_U_x[6], real_T
  controller1_Y_u[6]);
extern void controller1_step(RT_MODEL_controller1_T *const controller1_M, real_T
  controller1_U_In1[6], real_T controller1_U_x[6], real_T controller1_Y_u[6]);
extern void controller1_terminate(RT_MODEL_controller1_T *const controller1_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller1'
 * '<S1>'   : 'controller1/2Î¬ÂË²¨3'
 * '<S2>'   : 'controller1/Discrete Derivative1'
 * '<S3>'   : 'controller1/Discrete Derivative2'
 * '<S4>'   : 'controller1/controler '
 * '<S5>'   : 'controller1/fuzzy'
 * '<S6>'   : 'controller1/fuzzy/f1_1D_fuzzy'
 * '<S7>'   : 'controller1/fuzzy/f2_1D_fuzzy'
 * '<S8>'   : 'controller1/fuzzy/f3_1D_fuzzy'
 * '<S9>'   : 'controller1/fuzzy/f4_3D_fuzzy'
 * '<S10>'  : 'controller1/fuzzy/f5_3D_fuzzy'
 * '<S11>'  : 'controller1/fuzzy/f6_2D_fuzzy'
 */
#endif                                 /* RTW_HEADER_controller1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
