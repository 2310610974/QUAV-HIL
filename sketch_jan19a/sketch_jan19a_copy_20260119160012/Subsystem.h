/*
 * File: Subsystem.h
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 12.271
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Jan 19 15:58:16 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#ifndef Subsystem_COMMON_INCLUDES_
#define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

#include "Subsystem_types.h"
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
  real_T D_alpha_heng_2[6];            /* '<S1>/Embedded MATLAB Function2' */
  real_T D_delta_1[6];                 /* '<S1>/Embedded MATLAB Function2' */
  real_T D_delta_2[6];                 /* '<S1>/Embedded MATLAB Function2' */
  real_T D_Delta_1[6];                 /* '<S1>/Embedded MATLAB Function2' */
  real_T D_Delta_2[6];                 /* '<S1>/Embedded MATLAB Function2' */
  real_T D_V_guji[6];                  /* '<S1>/Embedded MATLAB Function2' */
  real_T D_Theta_guji_1[6];            /* '<S1>/Embedded MATLAB Function2' */
  real_T D_Theta_guji_2[6];            /* '<S1>/Embedded MATLAB Function2' */
  real_T yd_zitai[3];                  /* '<S1>/Embedded MATLAB Function2' */
} B_Subsystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[6];/* '<S1>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states;   /* '<S4>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_states;  /* '<S4>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_states;  /* '<S4>/Discrete Transfer Fcn2' */
  real_T UD_DSTATE[3];                 /* '<S2>/UD' */
  real_T DiscreteTimeIntegrator8_DSTATE[6];/* '<S1>/Discrete-Time Integrator8' */
  real_T DiscreteTimeIntegrator7_DSTATE[6];/* '<S1>/Discrete-Time Integrator7' */
  real_T DiscreteTimeIntegrator6_DSTATE[6];/* '<S1>/Discrete-Time Integrator6' */
  real_T DiscreteTimeIntegrator5_DSTATE[6];/* '<S1>/Discrete-Time Integrator5' */
  real_T DiscreteTimeIntegrator4_DSTATE[6];/* '<S1>/Discrete-Time Integrator4' */
  real_T DiscreteTimeIntegrator3_DSTATE[6];/* '<S1>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator2_DSTATE[6];/* '<S1>/Discrete-Time Integrator2' */
} DW_Subsystem_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [4;4;4;0;0;0]
   * Referenced by: '<S1>/Discrete-Time Integrator4'
   */
  real_T DiscreteTimeIntegrator4_IC[6];

  /* Expression: [2.2;2.2;2.2;0;0;0]
   * Referenced by: '<S1>/Discrete-Time Integrator3'
   */
  real_T DiscreteTimeIntegrator3_IC[6];

  /* Expression: [1.2;1.2;1.2;0.2;0.2;0.2]
   * Referenced by: '<S1>/Discrete-Time Integrator2'
   */
  real_T DiscreteTimeIntegrator2_IC[6];
} ConstP_Subsystem_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T yr_1[3];                      /* '<Root>/yr_1' */
  real_T fd_A[3];                      /* '<Root>/fd' */
  real_T D_x[6];                       /* '<Root>/D_x' */
  real_T x[6];                         /* '<Root>/x' */
} ExtU_Subsystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T x_gongji_11[3];               /* '<Root>/x_gongji_11' */
  real_T x_gongji_12[3];               /* '<Root>/x_gongji_12' */
  real_T y_d_gongji_1[3];              /* '<Root>/y_d_gongji_1' */
  real_T u[6];                         /* '<Root>/u' */
  real_T yd_zitai[3];                  /* '<Root>/yd_zitai' */
} ExtY_Subsystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_Subsystem_T {
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
extern B_Subsystem_T Subsystem_B;

/* Block states (default storage) */
extern DW_Subsystem_T Subsystem_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Subsystem_T Subsystem_Y;

/* Constant parameters (default storage) */
extern const ConstP_Subsystem_T Subsystem_ConstP;

/* Model entry point functions */
extern void Subsystem_initialize(void);
extern void Subsystem_step(void);
extern void Subsystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Subsystem_T *const Subsystem_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('x1UAVx20260119/UAV/AA1/Subsystem')    - opens subsystem x1UAVx20260119/UAV/AA1/Subsystem
 * hilite_system('x1UAVx20260119/UAV/AA1/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'x1UAVx20260119/UAV/AA1'
 * '<S1>'   : 'x1UAVx20260119/UAV/AA1/Subsystem'
 * '<S2>'   : 'x1UAVx20260119/UAV/AA1/Subsystem/Discrete Derivative'
 * '<S3>'   : 'x1UAVx20260119/UAV/AA1/Subsystem/Embedded MATLAB Function2'
 * '<S4>'   : 'x1UAVx20260119/UAV/AA1/Subsystem/ÂË²¨1'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
