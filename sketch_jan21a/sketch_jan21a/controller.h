/*
 * File: controller.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jan 21 15:47:48 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#ifndef controller_COMMON_INCLUDES_
#define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

#include "controller_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
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

/* Block signals (default storage) */
typedef struct {
  real_T D_alpha_heng_2[6];            /* '<Root>/controller1' */
  real_T D_delta_1[6];                 /* '<Root>/controller1' */
  real_T D_delta_2[6];                 /* '<Root>/controller1' */
  real_T D_Delta_1[6];                 /* '<Root>/controller1' */
  real_T D_Delta_2[6];                 /* '<Root>/controller1' */
  real_T D_V_guji[6];                  /* '<Root>/controller1' */
  real_T D_Theta_guji_1[6];            /* '<Root>/controller1' */
  real_T D_Theta_guji_2[6];            /* '<Root>/controller1' */
  real_T yd_zitai[3];                  /* '<Root>/controller1' */
  real_T TSamp[3];                     /* '<S1>/TSamp' */
  real_T o;
  real_T D_lambda;
  real_T x_gongji_111;
  real_T x_gongji_121;
  real_T x_gongji_131;
  real_T x_gongji_141;
  real_T x_gongji_151;
  real_T x_gongji_161;
  real_T x_gongji_112;
  real_T x_gongji_122;
  real_T x_gongji_132;
  real_T x_gongji_142;
  real_T x_gongji_152;
  real_T x_gongji_162;
  real_T yd_gongji_1;
  real_T yd_gongji_2;
  real_T yd_gongji_3;
  real_T z_11;
  real_T z_21;
  real_T z_31;
  real_T v;
  real_T D_v;
  real_T beta_1;
  real_T beta_2;
  real_T beta_3;
  real_T h_1;
  real_T h_2;
  real_T h_3;
  real_T mu_1;
  real_T mu_2;
  real_T mu_3;
  real_T v_2;
  real_T v_3;
  real_T alpha_11;
  real_T alpha_21;
  real_T alpha_31;
  real_T D_alpha_heng_32;
  real_T pi_1;
  real_T pi_2;
  real_T pi_3;
  real_T u1;
  real_T u2;
  real_T u3;
  real_T F;
  real_T psi_d;
  real_T yd_4;
  real_T yd_5;
  real_T yd_gongji_4;
  real_T yd_gongji_5;
  real_T yd_gongji_6;
  real_T z_41;
  real_T z_51;
  real_T z_61;
  real_T beta_4;
  real_T beta_5;
  real_T beta_6;
  real_T h_4;
  real_T h_5;
  real_T h_6;
  real_T mu_4;
  real_T mu_5;
  real_T mu_6;
  real_T alpha_41;
  real_T alpha_51;
  real_T alpha_61;
  real_T D_alpha_heng_62;
  real_T pi_4;
  real_T pi_5;
  real_T pi_6;
  real_T u4;
  real_T u5;
  real_T u6;
  real_T Clock;                        /* '<Root>/Clock' */
  real_T pi_1_tmp;
  real_T pi_2_tmp;
  real_T pi_3_tmp;
  real_T pi_4_tmp;
  real_T pi_5_tmp;
  real_T pi_6_tmp;
  real_T alpha_11_tmp_tmp;
  real_T alpha_21_tmp_tmp;
  real_T alpha_31_tmp_tmp;
  real_T pi_1_tmp_tmp;
  real_T pi_2_tmp_tmp;
  real_T pi_3_tmp_tmp;
  real_T Omega_tmp;
  real_T beta_4_tmp;
  real_T alpha_51_tmp_tmp;
  real_T alpha_61_tmp_tmp;
  real_T pi_4_tmp_tmp;
  real_T pi_5_tmp_tmp;
  real_T pi_6_tmp_tmp;
  real_T u6_tmp;
  real_T pi_1_tmp_m;
} B_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[6];/* '<Root>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states;   /* '<S3>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_states;  /* '<S3>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_states;  /* '<S3>/Discrete Transfer Fcn2' */
  real_T UD_DSTATE[3];                 /* '<S1>/UD' */
  real_T DiscreteTimeIntegrator8_DSTATE[6];/* '<Root>/Discrete-Time Integrator8' */
  real_T DiscreteTimeIntegrator7_DSTATE[6];/* '<Root>/Discrete-Time Integrator7' */
  real_T DiscreteTimeIntegrator6_DSTATE[6];/* '<Root>/Discrete-Time Integrator6' */
  real_T DiscreteTimeIntegrator5_DSTATE[6];/* '<Root>/Discrete-Time Integrator5' */
  real_T DiscreteTimeIntegrator4_DSTATE[6];/* '<Root>/Discrete-Time Integrator4' */
  real_T DiscreteTimeIntegrator3_DSTATE[6];/* '<Root>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator2_DSTATE[6];/* '<Root>/Discrete-Time Integrator2' */
} DW_controller_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [4;4;4;0;0;0]
   * Referenced by: '<Root>/Discrete-Time Integrator4'
   */
  real_T DiscreteTimeIntegrator4_IC[6];

  /* Expression: [2.2;2.2;2.2;0;0;0]
   * Referenced by: '<Root>/Discrete-Time Integrator3'
   */
  real_T DiscreteTimeIntegrator3_IC[6];

  /* Expression: [1.2;1.2;1.2;0.2;0.2;0.2]
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  real_T DiscreteTimeIntegrator2_IC[6];
} ConstP_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T yr_1[3];                      /* '<Root>/yr_1' */
  real_T fd[3];                        /* '<Root>/fd' */
  real_T D_x[6];                       /* '<Root>/D_x' */
  real_T x[6];                         /* '<Root>/x' */
} ExtU_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T x_gongji_11[3];               /* '<Root>/x_gongji_11' */
  real_T x_gongji_12[3];               /* '<Root>/x_gongji_12' */
  real_T y_d_gongji_1[3];              /* '<Root>/y_d_gongji_1' */
  real_T u[6];                         /* '<Root>/u' */
  real_T yd_zitai[3];                  /* '<Root>/yd_zitai' */
} ExtY_controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_controller_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

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

/* Block signals (default storage) */
extern B_controller_T controller_B;

/* Block states (default storage) */
extern DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_controller_T controller_Y;

/* Constant parameters (default storage) */
extern const ConstP_controller_T controller_ConstP;

/* Model entry point functions */
extern void controller_initialize(void);
extern void controller_step(void);
extern void controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_T *const controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'controller'
 * '<S1>'   : 'controller/Discrete Derivative'
 * '<S2>'   : 'controller/controller1'
 * '<S3>'   : 'controller/ÂË²¨1'
 */
#endif                                 /* RTW_HEADER_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
