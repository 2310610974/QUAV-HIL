/*
 * File: controller.c
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

#include "controller.h"
#include "rtwtypes.h"
#include <math.h>
#include "controller_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_controller_T controller_B;

/* Block states (default storage) */
DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_controller_T controller_Y;

/* Real-time model */
static RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void controller_step(void)
{
  {
    real_T pi_2_tmp;
    real_T pi_3_tmp;
    real_T pi_4_tmp;
    real_T pi_5_tmp;
    real_T pi_6_tmp;
    boolean_T tmp;
    boolean_T tmp_0;
    boolean_T tmp_1;

    /* Clock: '<Root>/Clock' */
    controller_B.Clock = controller_M->Timing.t[0];

    /* SampleTimeMath: '<S1>/TSamp' incorporates:
     *  DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
     *  DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1'
     *  DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2'
     *
     * About '<S1>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    controller_B.TSamp[0] = 0.0952 * controller_DW.DiscreteTransferFcn_states *
      1000.0;
    controller_B.TSamp[1] = 0.0952 * controller_DW.DiscreteTransferFcn1_states *
      1000.0;
    controller_B.TSamp[2] = 0.0952 * controller_DW.DiscreteTransferFcn2_states *
      1000.0;

    /* MATLAB Function: '<Root>/controller1' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator3'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator4'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator6'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator7'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator8'
     *  Inport: '<Root>/D_x'
     *  Inport: '<Root>/fd'
     *  Inport: '<Root>/x'
     *  Inport: '<Root>/yr_1'
     *  Sum: '<S1>/Diff'
     *  UnitDelay: '<S1>/UD'
     *
     * Block description for '<S1>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S1>/UD':
     *
     *  Store in Global RAM
     */
    if (controller_B.Clock < 10.0) {
      controller_B.o = 0.0;
      controller_B.D_lambda = 0.0;
    } else {
      controller_B.o = cos(0.25 * controller_B.Clock) * -0.01;
      controller_B.D_lambda = sin(0.25 * controller_B.Clock) * 0.0025;
    }

    controller_B.x_gongji_111 = (controller_B.o + 1.0) * controller_U.x[0];
    controller_B.x_gongji_121 = (controller_B.o + 1.0) * controller_U.x[1];
    controller_B.x_gongji_131 = (controller_B.o + 1.0) * controller_U.x[2];
    controller_B.x_gongji_141 = (controller_B.o + 1.0) * controller_U.x[3];
    controller_B.x_gongji_151 = (controller_B.o + 1.0) * controller_U.x[4];
    controller_B.x_gongji_161 = (controller_B.o + 1.0) * controller_U.x[5];
    controller_B.x_gongji_112 = (controller_B.o + 1.0) * controller_U.D_x[0];
    controller_B.x_gongji_122 = (controller_B.o + 1.0) * controller_U.D_x[1];
    controller_B.x_gongji_132 = (controller_B.o + 1.0) * controller_U.D_x[2];
    controller_B.x_gongji_142 = (controller_B.o + 1.0) * controller_U.D_x[3];
    controller_B.x_gongji_152 = (controller_B.o + 1.0) * controller_U.D_x[4];
    controller_B.x_gongji_162 = (controller_B.o + 1.0) * controller_U.D_x[5];
    controller_B.yd_gongji_1 = (controller_B.o + 1.0) * controller_U.yr_1[0];
    controller_B.yd_gongji_2 = (controller_B.o + 1.0) * controller_U.yr_1[1];
    controller_B.yd_gongji_3 = (controller_B.o + 1.0) * controller_U.yr_1[2];
    controller_B.z_11 = (controller_B.x_gongji_111 - (controller_B.yd_gongji_1 -
      1.0)) * 8.0;
    controller_B.z_21 = (controller_B.x_gongji_121 - (controller_B.yd_gongji_2 -
      1.0)) * 8.0;
    controller_B.z_31 = (controller_B.x_gongji_131 - controller_B.yd_gongji_3) *
      8.0;
    if ((controller_B.Clock >= 0.0) && (controller_B.Clock <= 3.0)) {
      controller_B.mu_1 = 1.0 / ((controller_B.Clock + 0.01) *
        (controller_B.Clock + 0.01)) - 0.1111111111111111;
      controller_B.v = rt_powd_snf(controller_B.mu_1, 4.0) + 1.0;
      controller_B.D_v = rt_powd_snf(controller_B.mu_1, 3.0) * -8.0 /
        rt_powd_snf(controller_B.Clock + 0.01, 3.0);
    } else {
      controller_B.v = 1.0;
      controller_B.D_v = 0.0;
    }

    controller_B.mu_4 = controller_B.v * controller_B.v;
    controller_B.mu_1 = controller_B.z_11 * controller_B.z_11;
    controller_B.beta_1 = (controller_B.mu_4 - controller_B.mu_1) * 70.0;
    controller_B.mu_2 = controller_B.z_21 * controller_B.z_21;
    controller_B.beta_2 = (controller_B.mu_4 - controller_B.mu_2) * 70.0;
    controller_B.mu_3 = controller_B.z_31 * controller_B.z_31;
    controller_B.beta_3 = (controller_B.mu_4 - controller_B.mu_3) * 70.0;
    tmp = ((controller_B.beta_1 > 0.0) && (controller_B.beta_1 <= 0.03));
    if (tmp) {
      controller_B.h_1 = 1.0 - rt_powd_snf(controller_B.beta_1 / 0.03 - 1.0, 4.0);
    } else {
      controller_B.h_1 = 1.0;
    }

    tmp_0 = ((controller_B.beta_2 > 0.0) && (controller_B.beta_2 <= 0.03));
    if (tmp_0) {
      controller_B.h_2 = 1.0 - rt_powd_snf(controller_B.beta_2 / 0.03 - 1.0, 4.0);
    } else {
      controller_B.h_2 = 1.0;
    }

    tmp_1 = ((controller_B.beta_3 > 0.0) && (controller_B.beta_3 <= 0.03));
    if (tmp_1) {
      controller_B.h_3 = 1.0 - rt_powd_snf(controller_B.beta_3 / 0.03 - 1.0, 4.0);
    } else {
      controller_B.h_3 = 1.0;
    }

    if (tmp) {
      controller_B.mu_1 = 1.0 / controller_B.h_1 - 560.0 / (controller_B.h_1 *
        controller_B.h_1 * 0.03) * rt_powd_snf(controller_B.beta_1 / 0.03 - 1.0,
        3.0) * controller_B.mu_1;
    } else {
      controller_B.mu_1 = 1.0;
    }

    if (tmp_0) {
      controller_B.mu_2 = 1.0 / controller_B.h_2 - 560.0 / (controller_B.h_2 *
        controller_B.h_2 * 0.03) * rt_powd_snf(controller_B.beta_2 / 0.03 - 1.0,
        3.0) * controller_B.mu_2;
    } else {
      controller_B.mu_2 = 1.0;
    }

    if (tmp_1) {
      controller_B.mu_3 = 1.0 / controller_B.h_3 - 560.0 / (controller_B.h_3 *
        controller_B.h_3 * 0.03) * rt_powd_snf(controller_B.beta_3 / 0.03 - 1.0,
        3.0) * controller_B.mu_3;
    } else {
      controller_B.mu_3 = 1.0;
    }

    if (tmp) {
      controller_B.beta_1 = 560.0 / (controller_B.h_1 * controller_B.h_1 * 0.03)
        * rt_powd_snf(controller_B.beta_1 / 0.03 - 1.0, 3.0) * controller_B.v *
        controller_B.D_v * controller_B.z_11;
    } else {
      controller_B.beta_1 = 0.0;
    }

    if (tmp_0) {
      controller_B.v_2 = 560.0 / (controller_B.h_2 * controller_B.h_2 * 0.03) *
        rt_powd_snf(controller_B.beta_2 / 0.03 - 1.0, 3.0) * controller_B.v *
        controller_B.D_v * controller_B.z_21;
    } else {
      controller_B.v_2 = 0.0;
    }

    if (tmp_1) {
      controller_B.v_3 = 560.0 / (controller_B.h_3 * controller_B.h_3 * 0.03) *
        rt_powd_snf(controller_B.beta_3 / 0.03 - 1.0, 3.0) * controller_B.v *
        controller_B.D_v * controller_B.z_31;
    } else {
      controller_B.v_3 = 0.0;
    }

    controller_B.alpha_11_tmp_tmp = controller_B.mu_1 * controller_B.mu_1;
    controller_B.beta_3 = controller_DW.DiscreteTimeIntegrator6_DSTATE[0] *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[0] *
      controller_B.alpha_11_tmp_tmp;
    controller_B.beta_2 = sqrt(controller_B.beta_3 + 1024.0);
    controller_B.alpha_11 = controller_B.alpha_11_tmp_tmp *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[0];
    controller_B.alpha_11_tmp_tmp = 1.5 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[0] / sqrt
      (controller_DW.DiscreteTimeIntegrator8_DSTATE[0] *
       controller_DW.DiscreteTimeIntegrator8_DSTATE[0] + 1024.0);
    controller_B.alpha_11 = ((((controller_B.z_11 / controller_B.h_1 * -60.0 -
      controller_B.alpha_11 * 11.0 / (4.0 * controller_B.beta_2)) -
      controller_B.alpha_11 * controller_DW.DiscreteTimeIntegrator3_DSTATE[0] /
      controller_B.beta_2) - controller_B.beta_1) -
      controller_B.alpha_11_tmp_tmp) / (controller_B.mu_1 * 8.0);
    controller_B.alpha_21_tmp_tmp = controller_B.mu_2 * controller_B.mu_2;
    controller_B.z_11 = controller_DW.DiscreteTimeIntegrator6_DSTATE[1] *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[1] *
      controller_B.alpha_21_tmp_tmp;
    controller_B.h_1 = sqrt(controller_B.z_11 + 2304.0);
    controller_B.alpha_21 = controller_B.alpha_21_tmp_tmp *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[1];
    controller_B.alpha_21_tmp_tmp = 1.5 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[1] / sqrt
      (controller_DW.DiscreteTimeIntegrator8_DSTATE[1] *
       controller_DW.DiscreteTimeIntegrator8_DSTATE[1] + 2304.0);
    controller_B.alpha_21 = ((((controller_B.z_21 / controller_B.h_2 * -40.0 -
      controller_B.alpha_21 * 11.0 / (4.0 * controller_B.h_1)) -
      controller_B.alpha_21 * controller_DW.DiscreteTimeIntegrator3_DSTATE[1] /
      controller_B.h_1) - controller_B.v_2) - controller_B.alpha_21_tmp_tmp) /
      (controller_B.mu_2 * 8.0);
    controller_B.alpha_31_tmp_tmp = controller_B.mu_3 * controller_B.mu_3;
    controller_B.z_21 = controller_DW.DiscreteTimeIntegrator6_DSTATE[2] *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[2] *
      controller_B.alpha_31_tmp_tmp;
    controller_B.h_2 = sqrt(controller_B.z_21 + 2025.0);
    controller_B.D_alpha_heng_32 = controller_B.alpha_31_tmp_tmp *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[2];
    controller_B.alpha_31_tmp_tmp = 1.5 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[2] / sqrt
      (controller_DW.DiscreteTimeIntegrator8_DSTATE[2] *
       controller_DW.DiscreteTimeIntegrator8_DSTATE[2] + 2025.0);
    controller_B.alpha_31 = ((((controller_B.z_31 / controller_B.h_3 * -50.0 -
      controller_B.D_alpha_heng_32 * 11.0 / (4.0 * controller_B.h_2)) -
      controller_B.D_alpha_heng_32 *
      controller_DW.DiscreteTimeIntegrator3_DSTATE[2] / controller_B.h_2) -
      controller_B.v_3) - controller_B.alpha_31_tmp_tmp) / (controller_B.mu_3 *
      8.0);
    controller_B.z_31 = (controller_B.alpha_11 -
                         controller_DW.DiscreteTimeIntegrator_DSTATE[0]) / 0.01;
    controller_B.h_3 = (controller_B.alpha_21 -
                        controller_DW.DiscreteTimeIntegrator_DSTATE[1]) / 0.01;
    controller_B.D_alpha_heng_32 = (controller_B.alpha_31 -
      controller_DW.DiscreteTimeIntegrator_DSTATE[2]) / 0.01;
    controller_B.pi_1_tmp_tmp = controller_DW.DiscreteTimeIntegrator5_DSTATE[0] *
      controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    controller_B.pi_1_tmp = sqrt(controller_B.pi_1_tmp_tmp + 12.96);
    controller_B.pi_1_tmp_m = controller_DW.DiscreteTimeIntegrator7_DSTATE[0] /
      sqrt(controller_DW.DiscreteTimeIntegrator7_DSTATE[0] *
           controller_DW.DiscreteTimeIntegrator7_DSTATE[0] + 12.96);
    controller_B.pi_1 = (((((controller_B.x_gongji_112 -
      controller_DW.DiscreteTimeIntegrator_DSTATE[0]) * 60.0 +
      controller_DW.DiscreteTimeIntegrator5_DSTATE[0] * 11.0 / (4.0 *
      controller_B.pi_1_tmp)) + controller_DW.DiscreteTimeIntegrator5_DSTATE[0] *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[0] / controller_B.pi_1_tmp) -
                          controller_B.z_31) + controller_B.pi_1_tmp_m) +
      controller_DW.DiscreteTimeIntegrator6_DSTATE[0];
    controller_B.pi_2_tmp_tmp = controller_DW.DiscreteTimeIntegrator5_DSTATE[1] *
      controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    controller_B.pi_2_tmp = sqrt(controller_B.pi_2_tmp_tmp + 12.25);
    pi_2_tmp = controller_DW.DiscreteTimeIntegrator7_DSTATE[1] / sqrt
      (controller_DW.DiscreteTimeIntegrator7_DSTATE[1] *
       controller_DW.DiscreteTimeIntegrator7_DSTATE[1] + 12.25);
    controller_B.pi_2 = (((((controller_B.x_gongji_122 -
      controller_DW.DiscreteTimeIntegrator_DSTATE[1]) * 40.0 +
      controller_DW.DiscreteTimeIntegrator5_DSTATE[1] * 11.0 / (4.0 *
      controller_B.pi_2_tmp)) + controller_DW.DiscreteTimeIntegrator5_DSTATE[1] *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[1] / controller_B.pi_2_tmp) -
                          controller_B.h_3) + pi_2_tmp) +
      controller_DW.DiscreteTimeIntegrator6_DSTATE[1];
    controller_B.pi_3_tmp_tmp = controller_DW.DiscreteTimeIntegrator5_DSTATE[2] *
      controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
    controller_B.pi_3_tmp = sqrt(controller_B.pi_3_tmp_tmp + 10.240000000000002);
    pi_3_tmp = controller_DW.DiscreteTimeIntegrator7_DSTATE[2] / sqrt
      (controller_DW.DiscreteTimeIntegrator7_DSTATE[2] *
       controller_DW.DiscreteTimeIntegrator7_DSTATE[2] + 10.240000000000002);
    controller_B.pi_3 = (((((controller_B.x_gongji_132 -
      controller_DW.DiscreteTimeIntegrator_DSTATE[2]) * 50.0 +
      controller_DW.DiscreteTimeIntegrator5_DSTATE[2] * 11.0 / (4.0 *
      controller_B.pi_3_tmp)) + controller_DW.DiscreteTimeIntegrator5_DSTATE[2] *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[2] / controller_B.pi_3_tmp) -
                          controller_B.D_alpha_heng_32) + pi_3_tmp) +
      controller_DW.DiscreteTimeIntegrator6_DSTATE[2];
    controller_B.u1 = controller_DW.DiscreteTimeIntegrator4_DSTATE[0] *
      controller_DW.DiscreteTimeIntegrator4_DSTATE[0];
    controller_B.u2 = controller_B.pi_1 * controller_B.pi_1;
    controller_B.u1 = -(controller_B.u1 *
                        controller_DW.DiscreteTimeIntegrator5_DSTATE[0] *
                        controller_B.u2) / sqrt(controller_B.pi_1_tmp_tmp *
      controller_B.u1 * controller_B.u2 + 144.0);
    controller_B.u2 = controller_DW.DiscreteTimeIntegrator4_DSTATE[1] *
      controller_DW.DiscreteTimeIntegrator4_DSTATE[1];
    controller_B.u3 = controller_B.pi_2 * controller_B.pi_2;
    controller_B.u2 = -(controller_B.u2 *
                        controller_DW.DiscreteTimeIntegrator5_DSTATE[1] *
                        controller_B.u3) / sqrt(controller_B.pi_2_tmp_tmp *
      controller_B.u2 * controller_B.u3 + 121.0);
    controller_B.u3 = controller_DW.DiscreteTimeIntegrator4_DSTATE[2] *
      controller_DW.DiscreteTimeIntegrator4_DSTATE[2];
    controller_B.F = controller_B.pi_3 * controller_B.pi_3;
    controller_B.u3 = -(controller_B.u3 *
                        controller_DW.DiscreteTimeIntegrator5_DSTATE[2] *
                        controller_B.F) / sqrt(controller_B.pi_3_tmp_tmp *
      controller_B.u3 * controller_B.F + 121.0);
    controller_B.yd_4 = (controller_B.u1 * controller_B.u1 + controller_B.u2 *
                         controller_B.u2) + controller_B.u3 * controller_B.u3;
    controller_B.F = sqrt(controller_B.yd_4) * 1.8;
    controller_B.Omega_tmp = 1.4142135623730951 * controller_B.u1 / 24.0;
    controller_B.psi_d = 1.4142135623730951 * controller_B.u2 / 24.0;
    controller_B.yd_gongji_4 = controller_B.F / 120.0 - controller_B.Omega_tmp;
    controller_B.Omega_tmp += controller_B.F / 120.0;
    controller_B.F = ((-sqrt(fabs((controller_B.Omega_tmp + controller_B.psi_d)
      + controller_B.u3 / 3.96) / 4.0) + sqrt(fabs((controller_B.yd_gongji_4 +
      controller_B.psi_d) - controller_B.u3 / 3.96) / 4.0)) - sqrt(fabs
      ((controller_B.yd_gongji_4 - controller_B.psi_d) + controller_B.u3 / 3.96)
      / 4.0)) + sqrt(fabs((controller_B.Omega_tmp - controller_B.psi_d) -
                          controller_B.u3 / 3.96) / 4.0);
    controller_B.Omega_tmp = sin(controller_B.Clock);
    controller_B.psi_d = 0.1 * controller_B.Omega_tmp + 1.0;
    controller_B.yd_gongji_4 = cos(controller_B.psi_d);
    controller_B.yd_gongji_5 = sin(controller_B.psi_d);
    controller_B.yd_4 = asin((controller_B.yd_gongji_5 * controller_B.u1 -
      controller_B.yd_gongji_4 * controller_B.u2) / sqrt(controller_B.yd_4 +
      1.0E-6));
    controller_B.yd_5 = atan((controller_B.yd_gongji_4 * controller_B.u1 +
      controller_B.yd_gongji_5 * controller_B.u2) / (controller_B.u3 + 1.0E-6));
    controller_B.yd_gongji_4 = (controller_B.o + 1.0) * controller_B.yd_4;
    controller_B.yd_gongji_5 = (controller_B.o + 1.0) * controller_B.yd_5;
    controller_B.yd_gongji_6 = (controller_B.o + 1.0) * controller_B.psi_d;
    controller_B.z_41 = (controller_B.x_gongji_141 - controller_B.yd_gongji_4) *
      10.0;
    controller_B.z_51 = (controller_B.x_gongji_151 - controller_B.yd_gongji_5) *
      10.0;
    controller_B.z_61 = (controller_B.x_gongji_161 - controller_B.yd_gongji_6) *
      10.0;
    controller_B.beta_4_tmp = controller_B.z_41 * controller_B.z_41;
    controller_B.beta_4 = (controller_B.mu_4 - controller_B.beta_4_tmp) * 70.0;
    controller_B.mu_5 = controller_B.z_51 * controller_B.z_51;
    controller_B.beta_5 = (controller_B.mu_4 - controller_B.mu_5) * 70.0;
    controller_B.mu_6 = controller_B.z_61 * controller_B.z_61;
    controller_B.beta_6 = (controller_B.mu_4 - controller_B.mu_6) * 70.0;
    tmp = ((controller_B.beta_4 > 0.0) && (controller_B.beta_4 <= 0.03));
    if (tmp) {
      controller_B.h_4 = 1.0 - rt_powd_snf(controller_B.beta_4 / 0.03 - 1.0, 4.0);
    } else {
      controller_B.h_4 = 1.0;
    }

    tmp_0 = ((controller_B.beta_5 > 0.0) && (controller_B.beta_5 <= 0.03));
    if (tmp_0) {
      controller_B.h_5 = 1.0 - rt_powd_snf(controller_B.beta_5 / 0.03 - 1.0, 4.0);
    } else {
      controller_B.h_5 = 1.0;
    }

    tmp_1 = ((controller_B.beta_6 > 0.0) && (controller_B.beta_6 <= 0.03));
    if (tmp_1) {
      controller_B.h_6 = 1.0 - rt_powd_snf(controller_B.beta_6 / 0.03 - 1.0, 4.0);
    } else {
      controller_B.h_6 = 1.0;
    }

    if (tmp) {
      controller_B.mu_4 = 1.0 / controller_B.h_4 - 560.0 / (controller_B.h_4 *
        controller_B.h_4 * 0.03) * rt_powd_snf(controller_B.beta_4 / 0.03 - 1.0,
        3.0) * controller_B.beta_4_tmp;
    } else {
      controller_B.mu_4 = 1.0;
    }

    if (tmp_0) {
      controller_B.mu_5 = 1.0 / controller_B.h_5 - 560.0 / (controller_B.h_5 *
        controller_B.h_5 * 0.03) * rt_powd_snf(controller_B.beta_5 / 0.03 - 1.0,
        3.0) * controller_B.mu_5;
    } else {
      controller_B.mu_5 = 1.0;
    }

    if (tmp_1) {
      controller_B.mu_6 = 1.0 / controller_B.h_6 - 560.0 / (controller_B.h_6 *
        controller_B.h_6 * 0.03) * rt_powd_snf(controller_B.beta_6 / 0.03 - 1.0,
        3.0) * controller_B.mu_6;
    } else {
      controller_B.mu_6 = 1.0;
    }

    if (tmp) {
      controller_B.beta_4 = 560.0 / (controller_B.h_4 * controller_B.h_4 * 0.03)
        * rt_powd_snf(controller_B.beta_4 / 0.03 - 1.0, 3.0) * controller_B.v *
        controller_B.D_v * controller_B.z_41;
    } else {
      controller_B.beta_4 = 0.0;
    }

    if (tmp_0) {
      controller_B.beta_5 = 560.0 / (controller_B.h_5 * controller_B.h_5 * 0.03)
        * rt_powd_snf(controller_B.beta_5 / 0.03 - 1.0, 3.0) * controller_B.v *
        controller_B.D_v * controller_B.z_51;
    } else {
      controller_B.beta_5 = 0.0;
    }

    if (tmp_1) {
      controller_B.beta_6 = 560.0 / (controller_B.h_6 * controller_B.h_6 * 0.03)
        * rt_powd_snf(controller_B.beta_6 / 0.03 - 1.0, 3.0) * controller_B.v *
        controller_B.D_v * controller_B.z_61;
    } else {
      controller_B.beta_6 = 0.0;
    }

    controller_B.beta_4_tmp = controller_B.mu_4 * controller_B.mu_4;
    controller_B.v = controller_DW.DiscreteTimeIntegrator6_DSTATE[3] *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[3] * controller_B.beta_4_tmp;
    controller_B.D_v = sqrt(controller_B.v + 1024.0);
    controller_B.alpha_41 = controller_B.beta_4_tmp *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[3];
    controller_B.beta_4_tmp = 1.5 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[3] / sqrt
      (controller_DW.DiscreteTimeIntegrator8_DSTATE[3] *
       controller_DW.DiscreteTimeIntegrator8_DSTATE[3] + 1024.0);
    controller_B.alpha_41 = ((((controller_B.z_41 / controller_B.h_4 * -40.0 -
      controller_B.alpha_41 * 11.0 / (4.0 * controller_B.D_v)) -
      controller_B.alpha_41 * controller_DW.DiscreteTimeIntegrator3_DSTATE[3] /
      controller_B.D_v) - controller_B.beta_4) - controller_B.beta_4_tmp) /
      (controller_B.mu_4 * 10.0);
    controller_B.alpha_51_tmp_tmp = controller_B.mu_5 * controller_B.mu_5;
    controller_B.z_41 = controller_DW.DiscreteTimeIntegrator6_DSTATE[4] *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[4] *
      controller_B.alpha_51_tmp_tmp;
    controller_B.h_4 = sqrt(controller_B.z_41 + 1369.0);
    controller_B.alpha_51 = controller_B.alpha_51_tmp_tmp *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[4];
    controller_B.alpha_51_tmp_tmp = 1.5 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[4] / sqrt
      (controller_DW.DiscreteTimeIntegrator8_DSTATE[4] *
       controller_DW.DiscreteTimeIntegrator8_DSTATE[4] + 1369.0);
    controller_B.alpha_51 = ((((controller_B.z_51 / controller_B.h_5 * -40.0 -
      controller_B.alpha_51 * 11.0 / (4.0 * controller_B.h_4)) -
      controller_B.alpha_51 * controller_DW.DiscreteTimeIntegrator3_DSTATE[4] /
      controller_B.h_4) - controller_B.beta_5) - controller_B.alpha_51_tmp_tmp) /
      (controller_B.mu_5 * 10.0);
    controller_B.alpha_61_tmp_tmp = controller_B.mu_6 * controller_B.mu_6;
    controller_B.z_51 = controller_DW.DiscreteTimeIntegrator6_DSTATE[5] *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[5] *
      controller_B.alpha_61_tmp_tmp;
    controller_B.h_5 = sqrt(controller_B.z_51 + 1296.0);
    controller_B.D_alpha_heng_62 = controller_B.alpha_61_tmp_tmp *
      controller_DW.DiscreteTimeIntegrator6_DSTATE[5];
    controller_B.alpha_61_tmp_tmp = 1.5 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[5] / sqrt
      (controller_DW.DiscreteTimeIntegrator8_DSTATE[5] *
       controller_DW.DiscreteTimeIntegrator8_DSTATE[5] + 1296.0);
    controller_B.alpha_61 = ((((controller_B.z_61 / controller_B.h_6 * -40.0 -
      controller_B.D_alpha_heng_62 * 11.0 / (4.0 * controller_B.h_5)) -
      controller_B.D_alpha_heng_62 *
      controller_DW.DiscreteTimeIntegrator3_DSTATE[5] / controller_B.h_5) -
      controller_B.beta_6) - controller_B.alpha_61_tmp_tmp) / (controller_B.mu_6
      * 10.0);
    controller_B.z_61 = (controller_B.alpha_41 -
                         controller_DW.DiscreteTimeIntegrator_DSTATE[3]) / 0.03;
    controller_B.h_6 = (controller_B.alpha_51 -
                        controller_DW.DiscreteTimeIntegrator_DSTATE[4]) / 0.05;
    controller_B.D_alpha_heng_62 = (controller_B.alpha_61 -
      controller_DW.DiscreteTimeIntegrator_DSTATE[5]) / 0.08;
    controller_B.pi_4_tmp_tmp = controller_DW.DiscreteTimeIntegrator5_DSTATE[3] *
      controller_DW.DiscreteTimeIntegrator5_DSTATE[3];
    controller_B.pi_4_tmp = sqrt(controller_B.pi_4_tmp_tmp + 7.2900000000000009);
    pi_4_tmp = controller_DW.DiscreteTimeIntegrator7_DSTATE[3] / sqrt
      (controller_DW.DiscreteTimeIntegrator7_DSTATE[3] *
       controller_DW.DiscreteTimeIntegrator7_DSTATE[3] + 7.2900000000000009);
    controller_B.pi_4 = (((((controller_B.x_gongji_142 -
      controller_DW.DiscreteTimeIntegrator_DSTATE[3]) * 40.0 +
      controller_DW.DiscreteTimeIntegrator5_DSTATE[3] * 11.0 / (4.0 *
      controller_B.pi_4_tmp)) + controller_DW.DiscreteTimeIntegrator5_DSTATE[3] *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[3] / controller_B.pi_4_tmp) -
                          controller_B.z_61) + pi_4_tmp) +
      controller_DW.DiscreteTimeIntegrator6_DSTATE[3];
    controller_B.pi_5_tmp_tmp = controller_DW.DiscreteTimeIntegrator5_DSTATE[4] *
      controller_DW.DiscreteTimeIntegrator5_DSTATE[4];
    controller_B.pi_5_tmp = sqrt(controller_B.pi_5_tmp_tmp + 7.839999999999999);
    pi_5_tmp = controller_DW.DiscreteTimeIntegrator7_DSTATE[4] / sqrt
      (controller_DW.DiscreteTimeIntegrator7_DSTATE[4] *
       controller_DW.DiscreteTimeIntegrator7_DSTATE[4] + 7.839999999999999);
    controller_B.pi_5 = (((((controller_B.x_gongji_152 -
      controller_DW.DiscreteTimeIntegrator_DSTATE[4]) * 40.0 +
      controller_DW.DiscreteTimeIntegrator5_DSTATE[4] * 11.0 / (4.0 *
      controller_B.pi_5_tmp)) + controller_DW.DiscreteTimeIntegrator5_DSTATE[4] *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[4] / controller_B.pi_5_tmp) -
                          controller_B.h_6) + pi_5_tmp) +
      controller_DW.DiscreteTimeIntegrator6_DSTATE[4];
    controller_B.pi_6_tmp_tmp = controller_DW.DiscreteTimeIntegrator5_DSTATE[5] *
      controller_DW.DiscreteTimeIntegrator5_DSTATE[5];
    controller_B.pi_6_tmp = sqrt(controller_B.pi_6_tmp_tmp + 9.6100000000000012);
    pi_6_tmp = controller_DW.DiscreteTimeIntegrator7_DSTATE[5] / sqrt
      (controller_DW.DiscreteTimeIntegrator7_DSTATE[5] *
       controller_DW.DiscreteTimeIntegrator7_DSTATE[5] + 9.6100000000000012);
    controller_B.pi_6 = (((((controller_B.x_gongji_162 -
      controller_DW.DiscreteTimeIntegrator_DSTATE[5]) * 40.0 +
      controller_DW.DiscreteTimeIntegrator5_DSTATE[5] * 11.0 / (4.0 *
      controller_B.pi_6_tmp)) + controller_DW.DiscreteTimeIntegrator5_DSTATE[5] *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[5] / controller_B.pi_6_tmp) -
                          controller_B.D_alpha_heng_62) + pi_6_tmp) +
      controller_DW.DiscreteTimeIntegrator6_DSTATE[5];
    controller_B.u4 = controller_DW.DiscreteTimeIntegrator4_DSTATE[3] *
      controller_DW.DiscreteTimeIntegrator4_DSTATE[3];
    controller_B.u5 = controller_B.pi_4 * controller_B.pi_4;
    controller_B.u4 = -(controller_B.u4 *
                        controller_DW.DiscreteTimeIntegrator5_DSTATE[3] *
                        controller_B.u5) / sqrt(controller_B.pi_4_tmp_tmp *
      controller_B.u4 * controller_B.u5 + 4.0);
    controller_B.u5 = controller_DW.DiscreteTimeIntegrator4_DSTATE[4] *
      controller_DW.DiscreteTimeIntegrator4_DSTATE[4];
    controller_B.u6 = controller_B.pi_5 * controller_B.pi_5;
    controller_B.u5 = -(controller_B.u5 *
                        controller_DW.DiscreteTimeIntegrator5_DSTATE[4] *
                        controller_B.u6) / sqrt(controller_B.pi_5_tmp_tmp *
      controller_B.u5 * controller_B.u6 + 4.0);
    controller_B.u6 = controller_DW.DiscreteTimeIntegrator4_DSTATE[5] *
      controller_DW.DiscreteTimeIntegrator4_DSTATE[5];
    controller_B.u6_tmp = controller_B.pi_6 * controller_B.pi_6;
    controller_B.u6 = -(controller_B.u6 *
                        controller_DW.DiscreteTimeIntegrator5_DSTATE[5] *
                        controller_B.u6_tmp) / sqrt(controller_B.pi_6_tmp_tmp *
      controller_B.u6 * controller_B.u6_tmp + 4.0);
    controller_B.yd_zitai[0] = controller_B.yd_4;
    controller_B.yd_zitai[1] = controller_B.yd_5;
    controller_B.yd_zitai[2] = controller_B.psi_d;
    controller_B.D_alpha_heng_2[0] = controller_B.z_31;
    controller_B.D_alpha_heng_2[1] = controller_B.h_3;
    controller_B.D_alpha_heng_2[2] = controller_B.D_alpha_heng_32;
    controller_B.D_alpha_heng_2[3] = controller_B.z_61;
    controller_B.D_alpha_heng_2[4] = controller_B.h_6;
    controller_B.D_alpha_heng_2[5] = controller_B.D_alpha_heng_62;
    controller_B.D_delta_1[0] = ((controller_B.mu_1 * 8.0 *
      (controller_DW.DiscreteTimeIntegrator_DSTATE[0] - controller_B.alpha_11) +
      -60.0 * controller_DW.DiscreteTimeIntegrator8_DSTATE[0]) +
      controller_B.mu_1 * 8.0 * controller_DW.DiscreteTimeIntegrator7_DSTATE[0])
      - controller_B.alpha_11_tmp_tmp;
    controller_B.D_delta_1[1] = ((controller_B.mu_2 * 8.0 *
      (controller_DW.DiscreteTimeIntegrator_DSTATE[1] - controller_B.alpha_21) +
      -40.0 * controller_DW.DiscreteTimeIntegrator8_DSTATE[1]) +
      controller_B.mu_2 * 8.0 * controller_DW.DiscreteTimeIntegrator7_DSTATE[1])
      - controller_B.alpha_21_tmp_tmp;
    controller_B.D_delta_1[2] = ((controller_B.mu_3 * 8.0 *
      (controller_DW.DiscreteTimeIntegrator_DSTATE[2] - controller_B.alpha_31) +
      -50.0 * controller_DW.DiscreteTimeIntegrator8_DSTATE[2]) +
      controller_B.mu_3 * 8.0 * controller_DW.DiscreteTimeIntegrator7_DSTATE[2])
      - controller_B.alpha_31_tmp_tmp;
    controller_B.D_delta_1[3] = ((controller_B.mu_4 * 10.0 *
      (controller_DW.DiscreteTimeIntegrator_DSTATE[3] - controller_B.alpha_41) +
      -40.0 * controller_DW.DiscreteTimeIntegrator8_DSTATE[3]) +
      controller_B.mu_4 * 10.0 * controller_DW.DiscreteTimeIntegrator7_DSTATE[3])
      - controller_B.beta_4_tmp;
    controller_B.D_delta_1[4] = ((controller_B.mu_5 * 10.0 *
      (controller_DW.DiscreteTimeIntegrator_DSTATE[4] - controller_B.alpha_51) +
      -40.0 * controller_DW.DiscreteTimeIntegrator8_DSTATE[4]) +
      controller_B.mu_5 * 10.0 * controller_DW.DiscreteTimeIntegrator7_DSTATE[4])
      - controller_B.alpha_51_tmp_tmp;
    controller_B.D_delta_1[5] = ((controller_B.mu_6 * 10.0 *
      (controller_DW.DiscreteTimeIntegrator_DSTATE[5] - controller_B.alpha_61) +
      -40.0 * controller_DW.DiscreteTimeIntegrator8_DSTATE[5]) +
      controller_B.mu_6 * 10.0 * controller_DW.DiscreteTimeIntegrator7_DSTATE[5])
      - controller_B.alpha_61_tmp_tmp;
    controller_B.D_delta_2[0] = -60.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[0] - controller_B.pi_1_tmp_m;
    controller_B.D_delta_2[1] = -40.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[1] - pi_2_tmp;
    controller_B.D_delta_2[2] = -50.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[2] - pi_3_tmp;
    controller_B.D_delta_2[3] = -40.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[3] - pi_4_tmp;
    controller_B.D_delta_2[4] = -40.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[4] - pi_5_tmp;
    controller_B.D_delta_2[5] = -40.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[5] - pi_6_tmp;
    controller_B.psi_d = 8.0 / (controller_B.o + 1.0) * controller_B.D_lambda;
    controller_B.yd_4 = (controller_B.o + 1.0) * 8.0;
    controller_B.D_Delta_1[0] = (((((controller_B.psi_d *
      controller_B.x_gongji_111 - controller_B.psi_d * controller_B.yd_gongji_1)
      - controller_B.yd_4 * controller_U.fd[0]) * controller_B.mu_1 +
      controller_B.mu_1 * 8.0 * (controller_DW.DiscreteTimeIntegrator5_DSTATE[0]
      + controller_B.alpha_11)) + controller_B.beta_1) + 60.0 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[0]) +
      controller_B.alpha_11_tmp_tmp;
    controller_B.D_Delta_1[1] = (((((controller_B.psi_d *
      controller_B.x_gongji_121 - controller_B.psi_d * controller_B.yd_gongji_2)
      - controller_B.yd_4 * controller_U.fd[1]) * controller_B.mu_2 +
      controller_B.mu_2 * 8.0 * (controller_DW.DiscreteTimeIntegrator5_DSTATE[1]
      + controller_B.alpha_21)) + controller_B.v_2) + 40.0 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[1]) +
      controller_B.alpha_21_tmp_tmp;
    controller_B.D_Delta_1[2] = (((((controller_B.psi_d *
      controller_B.x_gongji_131 - controller_B.psi_d * controller_B.yd_gongji_3)
      - controller_B.yd_4 * controller_U.fd[2]) * controller_B.mu_3 +
      controller_B.mu_3 * 8.0 * (controller_DW.DiscreteTimeIntegrator5_DSTATE[2]
      + controller_B.alpha_31)) + controller_B.v_3) + 50.0 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[2]) +
      controller_B.alpha_31_tmp_tmp;
    controller_B.psi_d = 10.0 / (controller_B.o + 1.0) * controller_B.D_lambda;
    controller_B.yd_4 = (controller_B.o + 1.0) * 10.0;
    controller_B.D_Delta_1[3] = (((((controller_B.psi_d *
      controller_B.x_gongji_141 - controller_B.psi_d * controller_B.yd_gongji_4)
      - (controller_B.TSamp[0] - controller_DW.UD_DSTATE[0]) * controller_B.yd_4)
      * controller_B.mu_4 + controller_B.mu_4 * 10.0 *
      (controller_DW.DiscreteTimeIntegrator5_DSTATE[3] + controller_B.alpha_41))
      + controller_B.beta_4) + 40.0 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[3]) + controller_B.beta_4_tmp;
    controller_B.D_Delta_1[4] = (((((controller_B.psi_d *
      controller_B.x_gongji_151 - controller_B.psi_d * controller_B.yd_gongji_5)
      - (controller_B.TSamp[1] - controller_DW.UD_DSTATE[1]) * controller_B.yd_4)
      * controller_B.mu_5 + controller_B.mu_5 * 10.0 *
      (controller_DW.DiscreteTimeIntegrator5_DSTATE[4] + controller_B.alpha_51))
      + controller_B.beta_5) + 40.0 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[4]) +
      controller_B.alpha_51_tmp_tmp;
    controller_B.D_Delta_1[5] = (((((controller_B.psi_d *
      controller_B.x_gongji_161 - controller_B.psi_d * controller_B.yd_gongji_6)
      - (controller_B.TSamp[2] - controller_DW.UD_DSTATE[2]) * controller_B.yd_4)
      * controller_B.mu_6 + controller_B.mu_6 * 10.0 *
      (controller_DW.DiscreteTimeIntegrator5_DSTATE[5] + controller_B.alpha_61))
      + controller_B.beta_6) + 40.0 *
      controller_DW.DiscreteTimeIntegrator8_DSTATE[5]) +
      controller_B.alpha_61_tmp_tmp;
    controller_B.x_gongji_141 = (controller_B.o + 1.0) * 0.8;
    controller_B.x_gongji_151 = cos(0.2 * controller_B.Clock) * 0.02 *
      (controller_B.o + 1.0);
    controller_B.D_Delta_2[0] = ((((((controller_B.x_gongji_112 /
      (controller_B.o + 1.0) * controller_B.D_lambda + controller_B.x_gongji_141
      * controller_B.u1) - controller_B.z_31) + controller_B.x_gongji_151) +
      -0.001 * controller_U.D_x[0] / 1.8 * (controller_B.o + 1.0)) + 0.2 *
      controller_B.Omega_tmp / 1.8 * (controller_B.o + 1.0)) + 60.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[0]) + controller_B.pi_1_tmp_m;
    controller_B.D_Delta_2[1] = ((((((controller_B.x_gongji_122 /
      (controller_B.o + 1.0) * controller_B.D_lambda + controller_B.x_gongji_141
      * controller_B.u2) - controller_B.h_3) + controller_B.x_gongji_151) +
      -0.001 * controller_U.D_x[1] / 1.8 * (controller_B.o + 1.0)) + 0.0001 *
      cos(controller_B.Clock) / 1.8 * (controller_B.o + 1.0)) + 40.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[1]) + pi_2_tmp;
    controller_B.x_gongji_141 = (controller_B.o + 1.0) * 0.0;
    controller_B.D_Delta_2[2] = ((((((controller_B.x_gongji_132 /
      (controller_B.o + 1.0) * controller_B.D_lambda + (controller_B.o + 1.0) *
      controller_B.u3) - controller_B.D_alpha_heng_32) +
      controller_B.x_gongji_141) + (-9.81 - 0.001 * controller_U.D_x[2] / 1.8) *
      (controller_B.o + 1.0)) + (controller_B.o + 1.0) * 0.083333333333333329) +
      50.0 * controller_DW.DiscreteTimeIntegrator7_DSTATE[2]) + pi_3_tmp;
    controller_B.D_Delta_2[3] = ((((((controller_B.x_gongji_142 /
      (controller_B.o + 1.0) * controller_B.D_lambda + (controller_B.o + 1.0) *
      controller_B.u4) - controller_B.z_61) + controller_B.x_gongji_141) +
      ((controller_U.D_x[4] * controller_U.D_x[5] - 8.2133333333333342E-5 *
        controller_U.D_x[4] * controller_B.F) - 0.19999999999999998 *
       controller_U.D_x[3]) * (controller_B.o + 1.0)) + 0.05 *
      controller_B.Omega_tmp / 0.75 * (controller_B.o + 1.0)) + 40.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[3]) + pi_4_tmp;
    controller_B.D_Delta_2[4] = ((((((controller_B.x_gongji_152 /
      (controller_B.o + 1.0) * controller_B.D_lambda + (controller_B.o + 1.0) *
      controller_B.u5) - controller_B.h_6) + controller_B.x_gongji_141) +
      ((-controller_U.D_x[3] * controller_U.D_x[5] - 8.2133333333333342E-5 *
        controller_U.D_x[3] * controller_B.F) - 0.19999999999999998 *
       controller_U.D_x[4]) * (controller_B.o + 1.0)) + (controller_B.o + 1.0) *
      0.013333333333333334) + 40.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[4]) + pi_5_tmp;
    controller_B.D_Delta_2[5] = ((((((controller_B.x_gongji_162 /
      (controller_B.o + 1.0) * controller_B.D_lambda + (controller_B.o + 1.0) *
      controller_B.u6) - controller_B.D_alpha_heng_62) +
      controller_B.x_gongji_141) + (0.0 * controller_U.D_x[3] *
      controller_U.D_x[4] - 0.099999999999999992 * controller_U.D_x[5]) *
      (controller_B.o + 1.0)) + cos(5.0 * controller_U.x[3]) * 0.02 / 1.5 *
      (controller_B.o + 1.0)) + 40.0 *
      controller_DW.DiscreteTimeIntegrator7_DSTATE[5]) + pi_6_tmp;
    controller_B.D_V_guji[0] = controller_DW.DiscreteTimeIntegrator5_DSTATE[0] *
      controller_B.pi_1 - 3.6 * controller_DW.DiscreteTimeIntegrator4_DSTATE[0];
    controller_B.D_V_guji[1] = controller_DW.DiscreteTimeIntegrator5_DSTATE[1] *
      controller_B.pi_2 - 3.5 * controller_DW.DiscreteTimeIntegrator4_DSTATE[1];
    controller_B.D_V_guji[2] = controller_DW.DiscreteTimeIntegrator5_DSTATE[2] *
      controller_B.pi_3 - 3.2 * controller_DW.DiscreteTimeIntegrator4_DSTATE[2];
    controller_B.D_V_guji[3] = controller_DW.DiscreteTimeIntegrator5_DSTATE[3] *
      controller_B.pi_4 - 2.7 * controller_DW.DiscreteTimeIntegrator4_DSTATE[3];
    controller_B.D_V_guji[4] = controller_DW.DiscreteTimeIntegrator5_DSTATE[4] *
      controller_B.pi_5 - 2.8 * controller_DW.DiscreteTimeIntegrator4_DSTATE[4];
    controller_B.D_V_guji[5] = controller_DW.DiscreteTimeIntegrator5_DSTATE[5] *
      controller_B.pi_6 - 3.1 * controller_DW.DiscreteTimeIntegrator4_DSTATE[5];
    controller_B.D_Theta_guji_1[0] = controller_B.beta_3 / controller_B.beta_2 -
      32.0 * controller_DW.DiscreteTimeIntegrator3_DSTATE[0];
    controller_B.D_Theta_guji_1[1] = controller_B.z_11 / controller_B.h_1 - 48.0
      * controller_DW.DiscreteTimeIntegrator3_DSTATE[1];
    controller_B.D_Theta_guji_1[2] = controller_B.z_21 / controller_B.h_2 - 45.0
      * controller_DW.DiscreteTimeIntegrator3_DSTATE[2];
    controller_B.D_Theta_guji_1[3] = controller_B.v / controller_B.D_v - 32.0 *
      controller_DW.DiscreteTimeIntegrator3_DSTATE[3];
    controller_B.D_Theta_guji_1[4] = controller_B.z_41 / controller_B.h_4 - 37.0
      * controller_DW.DiscreteTimeIntegrator3_DSTATE[4];
    controller_B.D_Theta_guji_1[5] = controller_B.z_51 / controller_B.h_5 - 36.0
      * controller_DW.DiscreteTimeIntegrator3_DSTATE[5];
    controller_B.D_Theta_guji_2[0] = controller_B.pi_1_tmp_tmp /
      controller_B.pi_1_tmp - 3.6 *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[0];
    controller_B.D_Theta_guji_2[1] = controller_B.pi_2_tmp_tmp /
      controller_B.pi_2_tmp - 3.5 *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[1];
    controller_B.D_Theta_guji_2[2] = controller_B.pi_3_tmp_tmp /
      controller_B.pi_3_tmp - 3.2 *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[2];
    controller_B.D_Theta_guji_2[3] = controller_B.pi_4_tmp_tmp /
      controller_B.pi_4_tmp - 2.7 *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[3];
    controller_B.D_Theta_guji_2[4] = controller_B.pi_5_tmp_tmp /
      controller_B.pi_5_tmp - 2.8 *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[4];
    controller_B.D_Theta_guji_2[5] = controller_B.pi_6_tmp_tmp /
      controller_B.pi_6_tmp - 3.1 *
      controller_DW.DiscreteTimeIntegrator2_DSTATE[5];

    /* Outport: '<Root>/u' incorporates:
     *  MATLAB Function: '<Root>/controller1'
     */
    controller_Y.u[0] = controller_B.u1;
    controller_Y.u[1] = controller_B.u2;
    controller_Y.u[2] = controller_B.u3;
    controller_Y.u[3] = controller_B.u4;
    controller_Y.u[4] = controller_B.u5;
    controller_Y.u[5] = controller_B.u6;

    /* Outport: '<Root>/x_gongji_11' incorporates:
     *  MATLAB Function: '<Root>/controller1'
     */
    controller_Y.x_gongji_11[0] = controller_B.x_gongji_111;
    controller_Y.x_gongji_11[1] = controller_B.x_gongji_121;
    controller_Y.x_gongji_11[2] = controller_B.x_gongji_131;

    /* Outport: '<Root>/x_gongji_12' incorporates:
     *  MATLAB Function: '<Root>/controller1'
     */
    controller_Y.x_gongji_12[0] = controller_B.x_gongji_112;
    controller_Y.x_gongji_12[1] = controller_B.x_gongji_122;
    controller_Y.x_gongji_12[2] = controller_B.x_gongji_132;

    /* Outport: '<Root>/y_d_gongji_1' incorporates:
     *  MATLAB Function: '<Root>/controller1'
     */
    controller_Y.y_d_gongji_1[0] = controller_B.yd_gongji_1 - 1.0;
    controller_Y.y_d_gongji_1[1] = controller_B.yd_gongji_2 - 1.0;
    controller_Y.y_d_gongji_1[2] = controller_B.yd_gongji_3;

    /* Outport: '<Root>/yd_zitai' */
    controller_Y.yd_zitai[0] = controller_B.yd_zitai[0];
    controller_Y.yd_zitai[1] = controller_B.yd_zitai[1];
    controller_Y.yd_zitai[2] = controller_B.yd_zitai[2];
  }

  {
    int32_T i;

    /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' */
    controller_DW.DiscreteTransferFcn_states = controller_B.yd_zitai[0] -
      -0.9048 * controller_DW.DiscreteTransferFcn_states;

    /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1' */
    controller_DW.DiscreteTransferFcn1_states = controller_B.yd_zitai[1] -
      -0.9048 * controller_DW.DiscreteTransferFcn1_states;

    /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2' */
    controller_DW.DiscreteTransferFcn2_states = controller_B.yd_zitai[2] -
      -0.9048 * controller_DW.DiscreteTransferFcn2_states;

    /* Update for UnitDelay: '<S1>/UD'
     *
     * Block description for '<S1>/UD':
     *
     *  Store in Global RAM
     */
    controller_DW.UD_DSTATE[0] = controller_B.TSamp[0];
    controller_DW.UD_DSTATE[1] = controller_B.TSamp[1];
    controller_DW.UD_DSTATE[2] = controller_B.TSamp[2];
    for (i = 0; i < 6; i++) {
      /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
      controller_DW.DiscreteTimeIntegrator_DSTATE[i] += 0.001 *
        controller_B.D_alpha_heng_2[i];

      /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator8' */
      controller_DW.DiscreteTimeIntegrator8_DSTATE[i] += 0.001 *
        controller_B.D_delta_1[i];

      /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator7' */
      controller_DW.DiscreteTimeIntegrator7_DSTATE[i] += 0.001 *
        controller_B.D_delta_2[i];

      /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator6' */
      controller_DW.DiscreteTimeIntegrator6_DSTATE[i] += 0.001 *
        controller_B.D_Delta_1[i];

      /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator5' */
      controller_DW.DiscreteTimeIntegrator5_DSTATE[i] += 0.001 *
        controller_B.D_Delta_2[i];

      /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' */
      controller_DW.DiscreteTimeIntegrator4_DSTATE[i] += 0.001 *
        controller_B.D_V_guji[i];

      /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' */
      controller_DW.DiscreteTimeIntegrator3_DSTATE[i] += 0.001 *
        controller_B.D_Theta_guji_1[i];

      /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
      controller_DW.DiscreteTimeIntegrator2_DSTATE[i] += 0.001 *
        controller_B.D_Theta_guji_2[i];
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  controller_M->Timing.t[0] =
    ((time_T)(++controller_M->Timing.clockTick0)) *
    controller_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    controller_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&controller_M->solverInfo,
                          &controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&controller_M->solverInfo, &rtmGetTPtr(controller_M));
    rtsiSetStepSizePtr(&controller_M->solverInfo,
                       &controller_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&controller_M->solverInfo, (&rtmGetErrorStatus
      (controller_M)));
    rtsiSetRTModelPtr(&controller_M->solverInfo, controller_M);
  }

  rtsiSetSimTimeStep(&controller_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&controller_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(controller_M, &controller_M->Timing.tArray[0]);
  controller_M->Timing.stepSize0 = 0.001;

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator4' */
      controller_DW.DiscreteTimeIntegrator4_DSTATE[i] =
        controller_ConstP.DiscreteTimeIntegrator4_IC[i];

      /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator3' */
      controller_DW.DiscreteTimeIntegrator3_DSTATE[i] =
        controller_ConstP.DiscreteTimeIntegrator3_IC[i];

      /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
      controller_DW.DiscreteTimeIntegrator2_DSTATE[i] =
        controller_ConstP.DiscreteTimeIntegrator2_IC[i];
    }
  }
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
