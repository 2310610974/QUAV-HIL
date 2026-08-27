/*
 * File: Subsystem.c
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

#include "Subsystem.h"
#include "rtwtypes.h"
#include <math.h>
#include "Subsystem_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Subsystem_T Subsystem_B;

/* Block states (default storage) */
DW_Subsystem_T Subsystem_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Subsystem_T Subsystem_Y;

/* Real-time model */
static RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;
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
void Subsystem_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp[3];

  {
    real_T Diff[3];
    real_T D_alpha_heng_32;
    real_T D_alpha_heng_62;
    real_T D_lambda;
    real_T D_v;
    real_T F;
    real_T Omega_tmp;
    real_T alpha_11;
    real_T alpha_11_tmp_tmp;
    real_T alpha_21;
    real_T alpha_21_tmp_tmp;
    real_T alpha_31;
    real_T alpha_31_tmp_tmp;
    real_T alpha_41;
    real_T alpha_51;
    real_T alpha_51_tmp_tmp;
    real_T alpha_61;
    real_T alpha_61_tmp_tmp;
    real_T beta_1;
    real_T beta_2;
    real_T beta_3;
    real_T beta_4;
    real_T beta_4_tmp;
    real_T beta_5;
    real_T beta_6;
    real_T h_1;
    real_T h_2;
    real_T h_3;
    real_T h_4;
    real_T h_5;
    real_T h_6;
    real_T mu_1;
    real_T mu_2;
    real_T mu_3;
    real_T mu_4;
    real_T mu_5;
    real_T mu_6;
    real_T o;
    real_T pi_1;
    real_T pi_1_tmp;
    real_T pi_1_tmp_0;
    real_T pi_1_tmp_tmp;
    real_T pi_2;
    real_T pi_2_tmp;
    real_T pi_2_tmp_0;
    real_T pi_2_tmp_tmp;
    real_T pi_3;
    real_T pi_3_tmp;
    real_T pi_3_tmp_0;
    real_T pi_3_tmp_tmp;
    real_T pi_4;
    real_T pi_4_tmp;
    real_T pi_4_tmp_0;
    real_T pi_4_tmp_tmp;
    real_T pi_5;
    real_T pi_5_tmp;
    real_T pi_5_tmp_0;
    real_T pi_5_tmp_tmp;
    real_T pi_6;
    real_T pi_6_tmp;
    real_T pi_6_tmp_0;
    real_T pi_6_tmp_tmp;
    real_T psi_d;
    real_T rtb_Clock;
    real_T u1;
    real_T u2;
    real_T u3;
    real_T u4;
    real_T u5;
    real_T u6;
    real_T u6_tmp;
    real_T v;
    real_T v_2;
    real_T v_3;
    real_T x_gongji_111;
    real_T x_gongji_112;
    real_T x_gongji_121;
    real_T x_gongji_122;
    real_T x_gongji_131;
    real_T x_gongji_132;
    real_T x_gongji_141;
    real_T x_gongji_142;
    real_T x_gongji_151;
    real_T x_gongji_152;
    real_T x_gongji_161;
    real_T x_gongji_162;
    real_T yd_4;
    real_T yd_5;
    real_T yd_gongji_1;
    real_T yd_gongji_2;
    real_T yd_gongji_3;
    real_T yd_gongji_4;
    real_T yd_gongji_5;
    real_T yd_gongji_6;
    real_T z_11;
    real_T z_21;
    real_T z_31;
    real_T z_41;
    real_T z_51;
    real_T z_61;
    boolean_T tmp;
    boolean_T tmp_0;
    boolean_T tmp_1;

    /* Clock: '<S1>/Clock' */
    rtb_Clock = Subsystem_M->Timing.t[0];

    /* SampleTimeMath: '<S2>/TSamp' incorporates:
     *  DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn'
     *  DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1'
     *  DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn2'
     *
     * About '<S2>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp[0] = 0.0952 * Subsystem_DW.DiscreteTransferFcn_states * 1000.0;
    rtb_TSamp[1] = 0.0952 * Subsystem_DW.DiscreteTransferFcn1_states * 1000.0;
    rtb_TSamp[2] = 0.0952 * Subsystem_DW.DiscreteTransferFcn2_states * 1000.0;

    /* Sum: '<S2>/Diff' incorporates:
     *  UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    Diff[0] = rtb_TSamp[0] - Subsystem_DW.UD_DSTATE[0];
    Diff[1] = rtb_TSamp[1] - Subsystem_DW.UD_DSTATE[1];
    Diff[2] = rtb_TSamp[2] - Subsystem_DW.UD_DSTATE[2];

    /* MATLAB Function: '<S1>/Embedded MATLAB Function2' incorporates:
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator3'
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator4'
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator6'
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator7'
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator8'
     *  Inport: '<Root>/D_x'
     *  Inport: '<Root>/fd'
     *  Inport: '<Root>/x'
     *  Inport: '<Root>/yr_1'
     */
    if (rtb_Clock < 10.0) {
      o = 0.0;
      D_lambda = 0.0;
    } else {
      o = cos(0.25 * rtb_Clock) * -0.01;
      D_lambda = sin(0.25 * rtb_Clock) * 0.0025;
    }

    x_gongji_111 = (o + 1.0) * Subsystem_U.x[0];
    x_gongji_121 = (o + 1.0) * Subsystem_U.x[1];
    x_gongji_131 = (o + 1.0) * Subsystem_U.x[2];
    x_gongji_141 = (o + 1.0) * Subsystem_U.x[3];
    x_gongji_151 = (o + 1.0) * Subsystem_U.x[4];
    x_gongji_161 = (o + 1.0) * Subsystem_U.x[5];
    x_gongji_112 = (o + 1.0) * Subsystem_U.D_x[0];
    x_gongji_122 = (o + 1.0) * Subsystem_U.D_x[1];
    x_gongji_132 = (o + 1.0) * Subsystem_U.D_x[2];
    x_gongji_142 = (o + 1.0) * Subsystem_U.D_x[3];
    x_gongji_152 = (o + 1.0) * Subsystem_U.D_x[4];
    x_gongji_162 = (o + 1.0) * Subsystem_U.D_x[5];
    yd_gongji_1 = (o + 1.0) * Subsystem_U.yr_1[0];
    yd_gongji_2 = (o + 1.0) * Subsystem_U.yr_1[1];
    yd_gongji_3 = (o + 1.0) * Subsystem_U.yr_1[2];
    z_11 = (x_gongji_111 - (yd_gongji_1 - 1.0)) * 8.0;
    z_21 = (x_gongji_121 - (yd_gongji_2 - 1.0)) * 8.0;
    z_31 = (x_gongji_131 - yd_gongji_3) * 8.0;
    if ((rtb_Clock >= 0.0) && (rtb_Clock <= 3.0)) {
      mu_1 = 1.0 / ((rtb_Clock + 0.01) * (rtb_Clock + 0.01)) -
        0.1111111111111111;
      v = rt_powd_snf(mu_1, 4.0) + 1.0;
      D_v = rt_powd_snf(mu_1, 3.0) * -8.0 / rt_powd_snf(rtb_Clock + 0.01, 3.0);
    } else {
      v = 1.0;
      D_v = 0.0;
    }

    mu_4 = v * v;
    mu_1 = z_11 * z_11;
    beta_1 = (mu_4 - mu_1) * 70.0;
    mu_2 = z_21 * z_21;
    beta_2 = (mu_4 - mu_2) * 70.0;
    mu_3 = z_31 * z_31;
    beta_3 = (mu_4 - mu_3) * 70.0;
    tmp = ((beta_1 > 0.0) && (beta_1 <= 0.03));
    if (tmp) {
      h_1 = 1.0 - rt_powd_snf(beta_1 / 0.03 - 1.0, 4.0);
    } else {
      h_1 = 1.0;
    }

    tmp_0 = ((beta_2 > 0.0) && (beta_2 <= 0.03));
    if (tmp_0) {
      h_2 = 1.0 - rt_powd_snf(beta_2 / 0.03 - 1.0, 4.0);
    } else {
      h_2 = 1.0;
    }

    tmp_1 = ((beta_3 > 0.0) && (beta_3 <= 0.03));
    if (tmp_1) {
      h_3 = 1.0 - rt_powd_snf(beta_3 / 0.03 - 1.0, 4.0);
    } else {
      h_3 = 1.0;
    }

    if (tmp) {
      mu_1 = 1.0 / h_1 - 560.0 / (h_1 * h_1 * 0.03) * rt_powd_snf(beta_1 / 0.03
        - 1.0, 3.0) * mu_1;
    } else {
      mu_1 = 1.0;
    }

    if (tmp_0) {
      mu_2 = 1.0 / h_2 - 560.0 / (h_2 * h_2 * 0.03) * rt_powd_snf(beta_2 / 0.03
        - 1.0, 3.0) * mu_2;
    } else {
      mu_2 = 1.0;
    }

    if (tmp_1) {
      mu_3 = 1.0 / h_3 - 560.0 / (h_3 * h_3 * 0.03) * rt_powd_snf(beta_3 / 0.03
        - 1.0, 3.0) * mu_3;
    } else {
      mu_3 = 1.0;
    }

    if (tmp) {
      beta_1 = 560.0 / (h_1 * h_1 * 0.03) * rt_powd_snf(beta_1 / 0.03 - 1.0, 3.0)
        * v * D_v * z_11;
    } else {
      beta_1 = 0.0;
    }

    if (tmp_0) {
      v_2 = 560.0 / (h_2 * h_2 * 0.03) * rt_powd_snf(beta_2 / 0.03 - 1.0, 3.0) *
        v * D_v * z_21;
    } else {
      v_2 = 0.0;
    }

    if (tmp_1) {
      v_3 = 560.0 / (h_3 * h_3 * 0.03) * rt_powd_snf(beta_3 / 0.03 - 1.0, 3.0) *
        v * D_v * z_31;
    } else {
      v_3 = 0.0;
    }

    alpha_11_tmp_tmp = mu_1 * mu_1;
    beta_3 = Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[0] *
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[0] * alpha_11_tmp_tmp;
    beta_2 = sqrt(beta_3 + 1024.0);
    alpha_11 = alpha_11_tmp_tmp * Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[0];
    alpha_11_tmp_tmp = 1.5 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[0] /
      sqrt(Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[0] *
           Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[0] + 1024.0);
    alpha_11 = ((((z_11 / h_1 * -60.0 - alpha_11 * 11.0 / (4.0 * beta_2)) -
                  alpha_11 * Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[0] /
                  beta_2) - beta_1) - alpha_11_tmp_tmp) / (mu_1 * 8.0);
    alpha_21_tmp_tmp = mu_2 * mu_2;
    z_11 = Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[1] *
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[1] * alpha_21_tmp_tmp;
    h_1 = sqrt(z_11 + 2304.0);
    alpha_21 = alpha_21_tmp_tmp * Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[1];
    alpha_21_tmp_tmp = 1.5 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[1] /
      sqrt(Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[1] *
           Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[1] + 2304.0);
    alpha_21 = ((((z_21 / h_2 * -40.0 - alpha_21 * 11.0 / (4.0 * h_1)) -
                  alpha_21 * Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[1] /
                  h_1) - v_2) - alpha_21_tmp_tmp) / (mu_2 * 8.0);
    alpha_31_tmp_tmp = mu_3 * mu_3;
    z_21 = Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[2] *
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[2] * alpha_31_tmp_tmp;
    h_2 = sqrt(z_21 + 2025.0);
    D_alpha_heng_32 = alpha_31_tmp_tmp *
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[2];
    alpha_31_tmp_tmp = 1.5 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[2] /
      sqrt(Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[2] *
           Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[2] + 2025.0);
    alpha_31 = ((((z_31 / h_3 * -50.0 - D_alpha_heng_32 * 11.0 / (4.0 * h_2)) -
                  D_alpha_heng_32 * Subsystem_DW.DiscreteTimeIntegrator3_DSTATE
                  [2] / h_2) - v_3) - alpha_31_tmp_tmp) / (mu_3 * 8.0);
    z_31 = (alpha_11 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[0]) / 0.01;
    h_3 = (alpha_21 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[1]) / 0.01;
    D_alpha_heng_32 = (alpha_31 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[2])
      / 0.01;
    pi_1_tmp_tmp = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[0] *
      Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[0];
    pi_1_tmp = sqrt(pi_1_tmp_tmp + 12.96);
    pi_1_tmp_0 = Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[0] / sqrt
      (Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[0] *
       Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[0] + 12.96);
    pi_1 = (((((x_gongji_112 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[0]) *
               60.0 + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[0] * 11.0 /
               (4.0 * pi_1_tmp)) + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[0]
              * Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[0] / pi_1_tmp) -
             z_31) + pi_1_tmp_0) + Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[0];
    pi_2_tmp_tmp = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[1] *
      Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[1];
    pi_2_tmp = sqrt(pi_2_tmp_tmp + 12.25);
    pi_2_tmp_0 = Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[1] / sqrt
      (Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[1] *
       Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[1] + 12.25);
    pi_2 = (((((x_gongji_122 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[1]) *
               40.0 + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[1] * 11.0 /
               (4.0 * pi_2_tmp)) + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[1]
              * Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[1] / pi_2_tmp) - h_3)
            + pi_2_tmp_0) + Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[1];
    pi_3_tmp_tmp = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[2] *
      Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[2];
    pi_3_tmp = sqrt(pi_3_tmp_tmp + 10.240000000000002);
    pi_3_tmp_0 = Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[2] / sqrt
      (Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[2] *
       Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[2] + 10.240000000000002);
    pi_3 = (((((x_gongji_132 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[2]) *
               50.0 + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[2] * 11.0 /
               (4.0 * pi_3_tmp)) + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[2]
              * Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[2] / pi_3_tmp) -
             D_alpha_heng_32) + pi_3_tmp_0) +
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[2];
    u1 = Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[0] *
      Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[0];
    u2 = pi_1 * pi_1;
    u1 = -(u1 * Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[0] * u2) / sqrt
      (pi_1_tmp_tmp * u1 * u2 + 144.0);
    u2 = Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[1] *
      Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[1];
    u3 = pi_2 * pi_2;
    u2 = -(u2 * Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[1] * u3) / sqrt
      (pi_2_tmp_tmp * u2 * u3 + 121.0);
    u3 = Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[2] *
      Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[2];
    F = pi_3 * pi_3;
    u3 = -(u3 * Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[2] * F) / sqrt
      (pi_3_tmp_tmp * u3 * F + 121.0);
    yd_4 = (u1 * u1 + u2 * u2) + u3 * u3;
    F = sqrt(yd_4) * 1.8;
    Omega_tmp = 1.4142135623730951 * u1 / 24.0;
    psi_d = 1.4142135623730951 * u2 / 24.0;
    yd_gongji_4 = F / 120.0 - Omega_tmp;
    Omega_tmp += F / 120.0;
    F = ((-sqrt(fabs((Omega_tmp + psi_d) + u3 / 3.96) / 4.0) + sqrt(fabs
           ((yd_gongji_4 + psi_d) - u3 / 3.96) / 4.0)) - sqrt(fabs((yd_gongji_4
            - psi_d) + u3 / 3.96) / 4.0)) + sqrt(fabs((Omega_tmp - psi_d) - u3 /
      3.96) / 4.0);
    Omega_tmp = sin(rtb_Clock);
    psi_d = 0.1 * Omega_tmp + 1.0;
    yd_gongji_4 = cos(psi_d);
    yd_gongji_5 = sin(psi_d);
    yd_4 = asin((yd_gongji_5 * u1 - yd_gongji_4 * u2) / sqrt(yd_4 + 1.0E-6));
    yd_5 = atan((yd_gongji_4 * u1 + yd_gongji_5 * u2) / (u3 + 1.0E-6));
    yd_gongji_4 = (o + 1.0) * yd_4;
    yd_gongji_5 = (o + 1.0) * yd_5;
    yd_gongji_6 = (o + 1.0) * psi_d;
    z_41 = (x_gongji_141 - yd_gongji_4) * 10.0;
    z_51 = (x_gongji_151 - yd_gongji_5) * 10.0;
    z_61 = (x_gongji_161 - yd_gongji_6) * 10.0;
    beta_4_tmp = z_41 * z_41;
    beta_4 = (mu_4 - beta_4_tmp) * 70.0;
    mu_5 = z_51 * z_51;
    beta_5 = (mu_4 - mu_5) * 70.0;
    mu_6 = z_61 * z_61;
    beta_6 = (mu_4 - mu_6) * 70.0;
    tmp = ((beta_4 > 0.0) && (beta_4 <= 0.03));
    if (tmp) {
      h_4 = 1.0 - rt_powd_snf(beta_4 / 0.03 - 1.0, 4.0);
    } else {
      h_4 = 1.0;
    }

    tmp_0 = ((beta_5 > 0.0) && (beta_5 <= 0.03));
    if (tmp_0) {
      h_5 = 1.0 - rt_powd_snf(beta_5 / 0.03 - 1.0, 4.0);
    } else {
      h_5 = 1.0;
    }

    tmp_1 = ((beta_6 > 0.0) && (beta_6 <= 0.03));
    if (tmp_1) {
      h_6 = 1.0 - rt_powd_snf(beta_6 / 0.03 - 1.0, 4.0);
    } else {
      h_6 = 1.0;
    }

    if (tmp) {
      mu_4 = 1.0 / h_4 - 560.0 / (h_4 * h_4 * 0.03) * rt_powd_snf(beta_4 / 0.03
        - 1.0, 3.0) * beta_4_tmp;
    } else {
      mu_4 = 1.0;
    }

    if (tmp_0) {
      mu_5 = 1.0 / h_5 - 560.0 / (h_5 * h_5 * 0.03) * rt_powd_snf(beta_5 / 0.03
        - 1.0, 3.0) * mu_5;
    } else {
      mu_5 = 1.0;
    }

    if (tmp_1) {
      mu_6 = 1.0 / h_6 - 560.0 / (h_6 * h_6 * 0.03) * rt_powd_snf(beta_6 / 0.03
        - 1.0, 3.0) * mu_6;
    } else {
      mu_6 = 1.0;
    }

    if (tmp) {
      beta_4 = 560.0 / (h_4 * h_4 * 0.03) * rt_powd_snf(beta_4 / 0.03 - 1.0, 3.0)
        * v * D_v * z_41;
    } else {
      beta_4 = 0.0;
    }

    if (tmp_0) {
      beta_5 = 560.0 / (h_5 * h_5 * 0.03) * rt_powd_snf(beta_5 / 0.03 - 1.0, 3.0)
        * v * D_v * z_51;
    } else {
      beta_5 = 0.0;
    }

    if (tmp_1) {
      beta_6 = 560.0 / (h_6 * h_6 * 0.03) * rt_powd_snf(beta_6 / 0.03 - 1.0, 3.0)
        * v * D_v * z_61;
    } else {
      beta_6 = 0.0;
    }

    beta_4_tmp = mu_4 * mu_4;
    v = Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[3] *
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[3] * beta_4_tmp;
    D_v = sqrt(v + 1024.0);
    alpha_41 = beta_4_tmp * Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[3];
    beta_4_tmp = 1.5 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[3] / sqrt
      (Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[3] *
       Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[3] + 1024.0);
    alpha_41 = ((((z_41 / h_4 * -40.0 - alpha_41 * 11.0 / (4.0 * D_v)) -
                  alpha_41 * Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[3] /
                  D_v) - beta_4) - beta_4_tmp) / (mu_4 * 10.0);
    alpha_51_tmp_tmp = mu_5 * mu_5;
    z_41 = Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[4] *
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[4] * alpha_51_tmp_tmp;
    h_4 = sqrt(z_41 + 1369.0);
    alpha_51 = alpha_51_tmp_tmp * Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[4];
    alpha_51_tmp_tmp = 1.5 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[4] /
      sqrt(Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[4] *
           Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[4] + 1369.0);
    alpha_51 = ((((z_51 / h_5 * -40.0 - alpha_51 * 11.0 / (4.0 * h_4)) -
                  alpha_51 * Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[4] /
                  h_4) - beta_5) - alpha_51_tmp_tmp) / (mu_5 * 10.0);
    alpha_61_tmp_tmp = mu_6 * mu_6;
    z_51 = Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[5] *
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[5] * alpha_61_tmp_tmp;
    h_5 = sqrt(z_51 + 1296.0);
    D_alpha_heng_62 = alpha_61_tmp_tmp *
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[5];
    alpha_61_tmp_tmp = 1.5 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[5] /
      sqrt(Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[5] *
           Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[5] + 1296.0);
    alpha_61 = ((((z_61 / h_6 * -40.0 - D_alpha_heng_62 * 11.0 / (4.0 * h_5)) -
                  D_alpha_heng_62 * Subsystem_DW.DiscreteTimeIntegrator3_DSTATE
                  [5] / h_5) - beta_6) - alpha_61_tmp_tmp) / (mu_6 * 10.0);
    z_61 = (alpha_41 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[3]) / 0.03;
    h_6 = (alpha_51 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[4]) / 0.05;
    D_alpha_heng_62 = (alpha_61 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[5])
      / 0.08;
    pi_4_tmp_tmp = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[3] *
      Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[3];
    pi_4_tmp = sqrt(pi_4_tmp_tmp + 7.2900000000000009);
    pi_4_tmp_0 = Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[3] / sqrt
      (Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[3] *
       Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[3] + 7.2900000000000009);
    pi_4 = (((((x_gongji_142 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[3]) *
               40.0 + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[3] * 11.0 /
               (4.0 * pi_4_tmp)) + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[3]
              * Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[3] / pi_4_tmp) -
             z_61) + pi_4_tmp_0) + Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[3];
    pi_5_tmp_tmp = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[4] *
      Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[4];
    pi_5_tmp = sqrt(pi_5_tmp_tmp + 7.839999999999999);
    pi_5_tmp_0 = Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[4] / sqrt
      (Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[4] *
       Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[4] + 7.839999999999999);
    pi_5 = (((((x_gongji_152 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[4]) *
               40.0 + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[4] * 11.0 /
               (4.0 * pi_5_tmp)) + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[4]
              * Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[4] / pi_5_tmp) - h_6)
            + pi_5_tmp_0) + Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[4];
    pi_6_tmp_tmp = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[5] *
      Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[5];
    pi_6_tmp = sqrt(pi_6_tmp_tmp + 9.6100000000000012);
    pi_6_tmp_0 = Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[5] / sqrt
      (Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[5] *
       Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[5] + 9.6100000000000012);
    pi_6 = (((((x_gongji_162 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE[5]) *
               40.0 + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[5] * 11.0 /
               (4.0 * pi_6_tmp)) + Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[5]
              * Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[5] / pi_6_tmp) -
             D_alpha_heng_62) + pi_6_tmp_0) +
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[5];
    u4 = Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[3] *
      Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[3];
    u5 = pi_4 * pi_4;
    u4 = -(u4 * Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[3] * u5) / sqrt
      (pi_4_tmp_tmp * u4 * u5 + 4.0);
    u5 = Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[4] *
      Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[4];
    u6 = pi_5 * pi_5;
    u5 = -(u5 * Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[4] * u6) / sqrt
      (pi_5_tmp_tmp * u5 * u6 + 4.0);
    u6 = Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[5] *
      Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[5];
    u6_tmp = pi_6 * pi_6;
    u6 = -(u6 * Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[5] * u6_tmp) / sqrt
      (pi_6_tmp_tmp * u6 * u6_tmp + 4.0);
    Subsystem_B.yd_zitai[0] = yd_4;
    Subsystem_B.yd_zitai[1] = yd_5;
    Subsystem_B.yd_zitai[2] = psi_d;
    Subsystem_B.D_alpha_heng_2[0] = z_31;
    Subsystem_B.D_alpha_heng_2[1] = h_3;
    Subsystem_B.D_alpha_heng_2[2] = D_alpha_heng_32;
    Subsystem_B.D_alpha_heng_2[3] = z_61;
    Subsystem_B.D_alpha_heng_2[4] = h_6;
    Subsystem_B.D_alpha_heng_2[5] = D_alpha_heng_62;
    Subsystem_B.D_delta_1[0] = ((mu_1 * 8.0 *
      (Subsystem_DW.DiscreteTimeIntegrator_DSTATE[0] - alpha_11) + -60.0 *
      Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[0]) + mu_1 * 8.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[0]) - alpha_11_tmp_tmp;
    Subsystem_B.D_delta_1[1] = ((mu_2 * 8.0 *
      (Subsystem_DW.DiscreteTimeIntegrator_DSTATE[1] - alpha_21) + -40.0 *
      Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[1]) + mu_2 * 8.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[1]) - alpha_21_tmp_tmp;
    Subsystem_B.D_delta_1[2] = ((mu_3 * 8.0 *
      (Subsystem_DW.DiscreteTimeIntegrator_DSTATE[2] - alpha_31) + -50.0 *
      Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[2]) + mu_3 * 8.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[2]) - alpha_31_tmp_tmp;
    Subsystem_B.D_delta_1[3] = ((mu_4 * 10.0 *
      (Subsystem_DW.DiscreteTimeIntegrator_DSTATE[3] - alpha_41) + -40.0 *
      Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[3]) + mu_4 * 10.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[3]) - beta_4_tmp;
    Subsystem_B.D_delta_1[4] = ((mu_5 * 10.0 *
      (Subsystem_DW.DiscreteTimeIntegrator_DSTATE[4] - alpha_51) + -40.0 *
      Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[4]) + mu_5 * 10.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[4]) - alpha_51_tmp_tmp;
    Subsystem_B.D_delta_1[5] = ((mu_6 * 10.0 *
      (Subsystem_DW.DiscreteTimeIntegrator_DSTATE[5] - alpha_61) + -40.0 *
      Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[5]) + mu_6 * 10.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[5]) - alpha_61_tmp_tmp;
    Subsystem_B.D_delta_2[0] = -60.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[0] - pi_1_tmp_0;
    Subsystem_B.D_delta_2[1] = -40.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[1] - pi_2_tmp_0;
    Subsystem_B.D_delta_2[2] = -50.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[2] - pi_3_tmp_0;
    Subsystem_B.D_delta_2[3] = -40.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[3] - pi_4_tmp_0;
    Subsystem_B.D_delta_2[4] = -40.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[4] - pi_5_tmp_0;
    Subsystem_B.D_delta_2[5] = -40.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[5] - pi_6_tmp_0;
    psi_d = 8.0 / (o + 1.0) * D_lambda;
    yd_4 = (o + 1.0) * 8.0;
    Subsystem_B.D_Delta_1[0] = (((((psi_d * x_gongji_111 - psi_d * yd_gongji_1)
      - yd_4 * Subsystem_U.fd_A[0]) * mu_1 + mu_1 * 8.0 *
      (Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[0] + alpha_11)) + beta_1) +
      60.0 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[0]) + alpha_11_tmp_tmp;
    Subsystem_B.D_Delta_1[1] = (((((psi_d * x_gongji_121 - psi_d * yd_gongji_2)
      - yd_4 * Subsystem_U.fd_A[1]) * mu_2 + mu_2 * 8.0 *
      (Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[1] + alpha_21)) + v_2) + 40.0
      * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[1]) + alpha_21_tmp_tmp;
    Subsystem_B.D_Delta_1[2] = (((((psi_d * x_gongji_131 - psi_d * yd_gongji_3)
      - yd_4 * Subsystem_U.fd_A[2]) * mu_3 + mu_3 * 8.0 *
      (Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[2] + alpha_31)) + v_3) + 50.0
      * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[2]) + alpha_31_tmp_tmp;
    psi_d = 10.0 / (o + 1.0) * D_lambda;
    yd_4 = (o + 1.0) * 10.0;
    Subsystem_B.D_Delta_1[3] = (((((psi_d * x_gongji_141 - psi_d * yd_gongji_4)
      - yd_4 * Diff[0]) * mu_4 + mu_4 * 10.0 *
      (Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[3] + alpha_41)) + beta_4) +
      40.0 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[3]) + beta_4_tmp;
    Subsystem_B.D_Delta_1[4] = (((((psi_d * x_gongji_151 - psi_d * yd_gongji_5)
      - yd_4 * Diff[1]) * mu_5 + mu_5 * 10.0 *
      (Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[4] + alpha_51)) + beta_5) +
      40.0 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[4]) + alpha_51_tmp_tmp;
    Subsystem_B.D_Delta_1[5] = (((((psi_d * x_gongji_161 - psi_d * yd_gongji_6)
      - yd_4 * Diff[2]) * mu_6 + mu_6 * 10.0 *
      (Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[5] + alpha_61)) + beta_6) +
      40.0 * Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[5]) + alpha_61_tmp_tmp;
    x_gongji_141 = (o + 1.0) * 0.8;
    x_gongji_151 = cos(0.2 * rtb_Clock) * 0.02 * (o + 1.0);
    Subsystem_B.D_Delta_2[0] = ((((((x_gongji_112 / (o + 1.0) * D_lambda +
      x_gongji_141 * u1) - z_31) + x_gongji_151) + -0.001 * Subsystem_U.D_x[0] /
      1.8 * (o + 1.0)) + 0.2 * Omega_tmp / 1.8 * (o + 1.0)) + 60.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[0]) + pi_1_tmp_0;
    Subsystem_B.D_Delta_2[1] = ((((((x_gongji_122 / (o + 1.0) * D_lambda +
      x_gongji_141 * u2) - h_3) + x_gongji_151) + -0.001 * Subsystem_U.D_x[1] /
      1.8 * (o + 1.0)) + 0.0001 * cos(rtb_Clock) / 1.8 * (o + 1.0)) + 40.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[1]) + pi_2_tmp_0;
    x_gongji_141 = (o + 1.0) * 0.0;
    Subsystem_B.D_Delta_2[2] = ((((((x_gongji_132 / (o + 1.0) * D_lambda + (o +
      1.0) * u3) - D_alpha_heng_32) + x_gongji_141) + (-9.81 - 0.001 *
      Subsystem_U.D_x[2] / 1.8) * (o + 1.0)) + (o + 1.0) * 0.083333333333333329)
      + 50.0 * Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[2]) + pi_3_tmp_0;
    Subsystem_B.D_Delta_2[3] = ((((((x_gongji_142 / (o + 1.0) * D_lambda + (o +
      1.0) * u4) - z_61) + x_gongji_141) + ((Subsystem_U.D_x[4] *
      Subsystem_U.D_x[5] - 8.2133333333333342E-5 * Subsystem_U.D_x[4] * F) -
      0.19999999999999998 * Subsystem_U.D_x[3]) * (o + 1.0)) + 0.05 * Omega_tmp /
      0.75 * (o + 1.0)) + 40.0 * Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[3])
      + pi_4_tmp_0;
    Subsystem_B.D_Delta_2[4] = ((((((x_gongji_152 / (o + 1.0) * D_lambda + (o +
      1.0) * u5) - h_6) + x_gongji_141) + ((-Subsystem_U.D_x[3] *
      Subsystem_U.D_x[5] - 8.2133333333333342E-5 * Subsystem_U.D_x[3] * F) -
      0.19999999999999998 * Subsystem_U.D_x[4]) * (o + 1.0)) + (o + 1.0) *
      0.013333333333333334) + 40.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[4]) + pi_5_tmp_0;
    Subsystem_B.D_Delta_2[5] = ((((((x_gongji_162 / (o + 1.0) * D_lambda + (o +
      1.0) * u6) - D_alpha_heng_62) + x_gongji_141) + (0.0 * Subsystem_U.D_x[3] *
      Subsystem_U.D_x[4] - 0.099999999999999992 * Subsystem_U.D_x[5]) * (o + 1.0))
      + cos(5.0 * Subsystem_U.x[3]) * 0.02 / 1.5 * (o + 1.0)) + 40.0 *
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[5]) + pi_6_tmp_0;
    Subsystem_B.D_V_guji[0] = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[0] *
      pi_1 - 3.6 * Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[0];
    Subsystem_B.D_V_guji[1] = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[1] *
      pi_2 - 3.5 * Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[1];
    Subsystem_B.D_V_guji[2] = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[2] *
      pi_3 - 3.2 * Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[2];
    Subsystem_B.D_V_guji[3] = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[3] *
      pi_4 - 2.7 * Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[3];
    Subsystem_B.D_V_guji[4] = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[4] *
      pi_5 - 2.8 * Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[4];
    Subsystem_B.D_V_guji[5] = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[5] *
      pi_6 - 3.1 * Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[5];
    Subsystem_B.D_Theta_guji_1[0] = beta_3 / beta_2 - 32.0 *
      Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[0];
    Subsystem_B.D_Theta_guji_1[1] = z_11 / h_1 - 48.0 *
      Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[1];
    Subsystem_B.D_Theta_guji_1[2] = z_21 / h_2 - 45.0 *
      Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[2];
    Subsystem_B.D_Theta_guji_1[3] = v / D_v - 32.0 *
      Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[3];
    Subsystem_B.D_Theta_guji_1[4] = z_41 / h_4 - 37.0 *
      Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[4];
    Subsystem_B.D_Theta_guji_1[5] = z_51 / h_5 - 36.0 *
      Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[5];
    Subsystem_B.D_Theta_guji_2[0] = pi_1_tmp_tmp / pi_1_tmp - 3.6 *
      Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[0];
    Subsystem_B.D_Theta_guji_2[1] = pi_2_tmp_tmp / pi_2_tmp - 3.5 *
      Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[1];
    Subsystem_B.D_Theta_guji_2[2] = pi_3_tmp_tmp / pi_3_tmp - 3.2 *
      Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[2];
    Subsystem_B.D_Theta_guji_2[3] = pi_4_tmp_tmp / pi_4_tmp - 2.7 *
      Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[3];
    Subsystem_B.D_Theta_guji_2[4] = pi_5_tmp_tmp / pi_5_tmp - 2.8 *
      Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[4];
    Subsystem_B.D_Theta_guji_2[5] = pi_6_tmp_tmp / pi_6_tmp - 3.1 *
      Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[5];

    /* Outport: '<Root>/u' incorporates:
     *  MATLAB Function: '<S1>/Embedded MATLAB Function2'
     */
    Subsystem_Y.u[0] = u1;
    Subsystem_Y.u[1] = u2;
    Subsystem_Y.u[2] = u3;
    Subsystem_Y.u[3] = u4;
    Subsystem_Y.u[4] = u5;
    Subsystem_Y.u[5] = u6;

    /* Outport: '<Root>/x_gongji_11' incorporates:
     *  MATLAB Function: '<S1>/Embedded MATLAB Function2'
     */
    Subsystem_Y.x_gongji_11[0] = x_gongji_111;
    Subsystem_Y.x_gongji_11[1] = x_gongji_121;
    Subsystem_Y.x_gongji_11[2] = x_gongji_131;

    /* Outport: '<Root>/x_gongji_12' incorporates:
     *  MATLAB Function: '<S1>/Embedded MATLAB Function2'
     */
    Subsystem_Y.x_gongji_12[0] = x_gongji_112;
    Subsystem_Y.x_gongji_12[1] = x_gongji_122;
    Subsystem_Y.x_gongji_12[2] = x_gongji_132;

    /* Outport: '<Root>/y_d_gongji_1' incorporates:
     *  MATLAB Function: '<S1>/Embedded MATLAB Function2'
     */
    Subsystem_Y.y_d_gongji_1[0] = yd_gongji_1 - 1.0;
    Subsystem_Y.y_d_gongji_1[1] = yd_gongji_2 - 1.0;
    Subsystem_Y.y_d_gongji_1[2] = yd_gongji_3;

    /* Outport: '<Root>/yd_zitai' */
    Subsystem_Y.yd_zitai[0] = Subsystem_B.yd_zitai[0];
    Subsystem_Y.yd_zitai[1] = Subsystem_B.yd_zitai[1];
    Subsystem_Y.yd_zitai[2] = Subsystem_B.yd_zitai[2];
  }

  {
    int32_T i;

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    for (i = 0; i < 6; i++) {
      Subsystem_DW.DiscreteTimeIntegrator_DSTATE[i] += 0.001 *
        Subsystem_B.D_alpha_heng_2[i];
    }

    /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

    /* Update for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn' */
    Subsystem_DW.DiscreteTransferFcn_states = (Subsystem_B.yd_zitai[0] -
      (-0.9048) * Subsystem_DW.DiscreteTransferFcn_states) / 1.0;

    /* Update for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn1' */
    Subsystem_DW.DiscreteTransferFcn1_states = (Subsystem_B.yd_zitai[1] -
      (-0.9048) * Subsystem_DW.DiscreteTransferFcn1_states) / 1.0;

    /* Update for DiscreteTransferFcn: '<S4>/Discrete Transfer Fcn2' */
    Subsystem_DW.DiscreteTransferFcn2_states = (Subsystem_B.yd_zitai[2] -
      (-0.9048) * Subsystem_DW.DiscreteTransferFcn2_states) / 1.0;

    /* Update for UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    Subsystem_DW.UD_DSTATE[0] = rtb_TSamp[0];
    Subsystem_DW.UD_DSTATE[1] = rtb_TSamp[1];
    Subsystem_DW.UD_DSTATE[2] = rtb_TSamp[2];

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator8' */
    for (i = 0; i < 6; i++) {
      Subsystem_DW.DiscreteTimeIntegrator8_DSTATE[i] += 0.001 *
        Subsystem_B.D_delta_1[i];
    }

    /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator8' */

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator7' */
    for (i = 0; i < 6; i++) {
      Subsystem_DW.DiscreteTimeIntegrator7_DSTATE[i] += 0.001 *
        Subsystem_B.D_delta_2[i];
    }

    /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator7' */

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator6' */
    for (i = 0; i < 6; i++) {
      Subsystem_DW.DiscreteTimeIntegrator6_DSTATE[i] += 0.001 *
        Subsystem_B.D_Delta_1[i];
    }

    /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator6' */

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator5' */
    for (i = 0; i < 6; i++) {
      Subsystem_DW.DiscreteTimeIntegrator5_DSTATE[i] += 0.001 *
        Subsystem_B.D_Delta_2[i];
    }

    /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator5' */

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator4' */
    for (i = 0; i < 6; i++) {
      Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[i] += 0.001 *
        Subsystem_B.D_V_guji[i];
    }

    /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator4' */

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
    for (i = 0; i < 6; i++) {
      Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[i] += 0.001 *
        Subsystem_B.D_Theta_guji_1[i];
    }

    /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
    for (i = 0; i < 6; i++) {
      Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[i] += 0.001 *
        Subsystem_B.D_Theta_guji_2[i];
    }

    /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Subsystem_M->Timing.t[0] =
    ((time_T)(++Subsystem_M->Timing.clockTick0)) * Subsystem_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Subsystem_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Subsystem_M->solverInfo,
                          &Subsystem_M->Timing.simTimeStep);
    rtsiSetTPtr(&Subsystem_M->solverInfo, &rtmGetTPtr(Subsystem_M));
    rtsiSetStepSizePtr(&Subsystem_M->solverInfo, &Subsystem_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Subsystem_M->solverInfo, (&rtmGetErrorStatus
      (Subsystem_M)));
    rtsiSetRTModelPtr(&Subsystem_M->solverInfo, Subsystem_M);
  }

  rtsiSetSimTimeStep(&Subsystem_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Subsystem_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Subsystem_M, &Subsystem_M->Timing.tArray[0]);
  Subsystem_M->Timing.stepSize0 = 0.001;

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator4' */
      Subsystem_DW.DiscreteTimeIntegrator4_DSTATE[i] =
        Subsystem_ConstP.DiscreteTimeIntegrator4_IC[i];

      /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
      Subsystem_DW.DiscreteTimeIntegrator3_DSTATE[i] =
        Subsystem_ConstP.DiscreteTimeIntegrator3_IC[i];

      /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
      Subsystem_DW.DiscreteTimeIntegrator2_DSTATE[i] =
        Subsystem_ConstP.DiscreteTimeIntegrator2_IC[i];
    }
  }
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
