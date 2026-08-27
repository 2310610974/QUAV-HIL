/*
 * File: controller1.c
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

#include "controller1.h"
#include "rtwtypes.h"
#include "controller1_private.h"
#include <math.h>
#include <string.h>

/*
 * Output and update for atomic system:
 *    '<S5>/f1_1D_fuzzy'
 *    '<S5>/f2_1D_fuzzy'
 *    '<S5>/f3_1D_fuzzy'
 */
void controller1_f1_1D_fuzzy(real_T rtu_u, real_T *rty_fuzzy,
  B_f1_1D_fuzzy_controller1_T *localB)
{
  real_T all;
  real_T c_a;
  int32_T a;
  all = 0.0;
  for (a = 0; a < 11; a++) {
    switch (a + 1) {
     case 1:
      if (rtu_u <= -5.0) {
        c_a = 1.0;
        localB->mu_F1[a] = 1.0;
      } else {
        c_a = exp(-((rtu_u - -5.0) * (rtu_u - -5.0)) / 0.22222222222222221);
        localB->mu_F1[a] = c_a;
      }
      break;

     case 11:
      if (rtu_u >= 5.0) {
        c_a = 1.0;
        localB->mu_F1[a] = 1.0;
      } else {
        c_a = exp(-((rtu_u - 5.0) * (rtu_u - 5.0)) / 0.22222222222222221);
        localB->mu_F1[a] = c_a;
      }
      break;

     default:
      c_a = rtu_u - ((real_T)a - 5.0);
      c_a = exp(-(c_a * c_a) / 0.22222222222222221);
      localB->mu_F1[a] = c_a;
      break;
    }

    all += c_a;
  }

  c_a = 0.0;
  for (a = 0; a < 11; a++) {
    real_T PSI;
    PSI = localB->mu_F1[a] / all;
    c_a += PSI * PSI;
  }

  *rty_fuzzy = c_a;
}

/*
 * Output and update for atomic system:
 *    '<S5>/f4_3D_fuzzy'
 *    '<S5>/f5_3D_fuzzy'
 */
void controller1_f4_3D_fuzzy(const real_T rtu_u[3], real_T *rty_fuzzy,
  B_f4_3D_fuzzy_controller1_T *localB)
{
  real_T all;
  real_T c_a;
  int32_T b;
  int32_T c;
  int32_T i;
  memset(&localB->mu_F1[0], 0, 11U * sizeof(real_T));
  memset(&localB->mu_F2[0], 0, 11U * sizeof(real_T));
  all = 0.0;
  memset(&localB->PSI[0], 0, 1331U * sizeof(real_T));
  for (i = 0; i < 11; i++) {
    switch (i + 1) {
     case 1:
      if (rtu_u[0] <= -5.0) {
        localB->mu_F1[i] = 1.0;
      } else {
        localB->mu_F1[i] = exp(-((rtu_u[0] - -5.0) * (rtu_u[0] - -5.0)) /
          0.22222222222222221);
      }
      break;

     case 11:
      if (rtu_u[0] >= 5.0) {
        localB->mu_F1[i] = 1.0;
      } else {
        localB->mu_F1[i] = exp(-((rtu_u[0] - 5.0) * (rtu_u[0] - 5.0)) /
          0.22222222222222221);
      }
      break;

     default:
      c_a = rtu_u[0] - ((real_T)i - 5.0);
      localB->mu_F1[i] = exp(-(c_a * c_a) / 0.22222222222222221);
      break;
    }

    for (b = 0; b < 11; b++) {
      switch (b + 1) {
       case 1:
        if (rtu_u[1] <= -5.0) {
          localB->mu_F2[b] = 1.0;
        } else {
          localB->mu_F2[b] = exp(-((rtu_u[0] - -5.0) * (rtu_u[0] - -5.0)) /
            0.22222222222222221);
        }
        break;

       case 11:
        if (rtu_u[1] >= 5.0) {
          localB->mu_F2[b] = 1.0;
        } else {
          localB->mu_F2[b] = exp(-((rtu_u[0] - 5.0) * (rtu_u[0] - 5.0)) /
            0.22222222222222221);
        }
        break;

       default:
        c_a = rtu_u[0] - ((real_T)b - 5.0);
        localB->mu_F2[b] = exp(-(c_a * c_a) / 0.22222222222222221);
        break;
      }

      for (c = 0; c < 11; c++) {
        switch (c + 1) {
         case 1:
          if (rtu_u[2] <= -5.0) {
            c_a = 1.0;
            localB->mu_F3[c] = 1.0;
          } else {
            c_a = exp(-((rtu_u[0] - -5.0) * (rtu_u[0] - -5.0)) /
                      0.22222222222222221);
            localB->mu_F3[c] = c_a;
          }
          break;

         case 11:
          if (rtu_u[2] >= 5.0) {
            c_a = 1.0;
            localB->mu_F3[c] = 1.0;
          } else {
            c_a = exp(-((rtu_u[0] - 5.0) * (rtu_u[0] - 5.0)) /
                      0.22222222222222221);
            localB->mu_F3[c] = c_a;
          }
          break;

         default:
          c_a = rtu_u[0] - ((real_T)c - 5.0);
          c_a = exp(-(c_a * c_a) / 0.22222222222222221);
          localB->mu_F3[c] = c_a;
          break;
        }

        all += localB->mu_F1[i] * localB->mu_F2[b] * c_a;
      }
    }
  }

  for (i = 0; i < 11; i++) {
    for (b = 0; b < 11; b++) {
      for (c = 0; c < 11; c++) {
        localB->PSI[(c * 11 + b) * 11 + i] = localB->mu_F3[c] * localB->mu_F2[b]
          * localB->mu_F1[i] / all;
      }
    }
  }

  all = 0.0;
  for (i = 0; i < 1331; i++) {
    c_a = localB->PSI[i];
    all += c_a * c_a;
  }

  *rty_fuzzy = all;
}

/* Model step function */
void controller1_step(RT_MODEL_controller1_T *const controller1_M, real_T
                      controller1_U_In1[6], real_T controller1_U_x[6], real_T
                      controller1_Y_u[6])
{
  B_controller1_T *controller1_B = controller1_M->blockIO;
  DW_controller1_T *controller1_DW = controller1_M->dwork;

  {
    real_T c_b;
    real_T rtb_TmpSignalConversionAtSFun_0;
    real_T rtb_TmpSignalConversionAtSFun_1;
    int32_T b;
    int32_T i;
    int32_T tmp;
    static const int8_T y[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const real_T c_b_0[9] = { 1.8, 0.0, 0.0, 0.0, 1.8, 0.0, 0.0, 0.0, 1.8
    };

    static const real_T d[3] = { 0.010991149581709674, 0.054955747908548375,
      0.076938047071967719 };

    static const real_T e[3] = { 0.0, 0.0, 17.658 };

    static const real_T d_b[9] = { 1.0E-5, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0,
      1.0E-6 };

    static const real_T h_a[9] = { -2.2, -0.0, -0.0, -0.0, -2.0, -0.0, -0.0,
      -0.0, -2.2 };

    static const real_T e_b[9] = { 1.0E-5, 0.0, 0.0, 0.0, 1.0E-6, 0.0, 0.0, 0.0,
      1.0E-5 };

    /* UnitDelay: '<S3>/UD'
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    for (i = 0; i < 6; i++) {
      controller1_B->Uk1[i] = controller1_DW->UD_DSTATE[i];
    }

    /* SampleTimeMath: '<S3>/TSamp' incorporates:
     *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
     *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn1'
     *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn2'
     *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn3'
     *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn4'
     *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn5'
     *  UnitDelay: '<S3>/UD'
     *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    controller1_DW->UD_DSTATE[0] = 0.00995017 *
      controller1_DW->DiscreteTransferFcn_states * 1000.0;
    controller1_DW->UD_DSTATE[1] = 0.00995017 *
      controller1_DW->DiscreteTransferFcn2_states * 1000.0;
    controller1_DW->UD_DSTATE[2] = 0.00995017 *
      controller1_DW->DiscreteTransferFcn1_states * 1000.0;
    controller1_DW->UD_DSTATE[3] = 0.00995017 *
      controller1_DW->DiscreteTransferFcn3_states * 1000.0;
    controller1_DW->UD_DSTATE[4] = 0.00995017 *
      controller1_DW->DiscreteTransferFcn4_states * 1000.0;
    controller1_DW->UD_DSTATE[5] = 0.00995017 *
      controller1_DW->DiscreteTransferFcn5_states * 1000.0;
    for (i = 0; i < 6; i++) {
      /* Sum: '<S3>/Diff' incorporates:
       *  UnitDelay: '<S3>/UD'
       *
       * Block description for '<S3>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S3>/UD':
       *
       *  Store in Global RAM
       */
      controller1_B->Clock2 = controller1_DW->UD_DSTATE[i] - controller1_B->
        Uk1[i];
      controller1_B->Uk1[i] = controller1_B->Clock2;

      /* SampleTimeMath: '<S2>/TSamp'
       *
       * About '<S2>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       */
      controller1_B->Clock2 *= 1000.0;
      controller1_B->TSamp_o[i] = controller1_B->Clock2;

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
      controller1_B->Diff_p[i] = controller1_B->Clock2 -
        controller1_DW->UD_DSTATE_k[i];
    }

    /* Clock: '<Root>/Clock2' */
    controller1_B->Clock2 = controller1_M->Timing.t[0];

    /* MATLAB Function: '<S5>/f1_1D_fuzzy' incorporates:
     *  Inport: '<Root>/In1'
     */
    controller1_f1_1D_fuzzy(controller1_U_In1[0], &controller1_B->rtb_fuzzy_l_k,
      &controller1_B->sf_f1_1D_fuzzy);

    /* MATLAB Function: '<S5>/f2_1D_fuzzy' incorporates:
     *  Inport: '<Root>/In1'
     */
    controller1_f1_1D_fuzzy(controller1_U_In1[1], &controller1_B->rtb_fuzzy_b_c,
      &controller1_B->sf_f2_1D_fuzzy);

    /* MATLAB Function: '<S5>/f3_1D_fuzzy' incorporates:
     *  Inport: '<Root>/In1'
     */
    controller1_f1_1D_fuzzy(controller1_U_In1[2], &controller1_B->rtb_fuzzy_od_b,
      &controller1_B->sf_f3_1D_fuzzy);

    /* MATLAB Function: '<S5>/f4_3D_fuzzy' incorporates:
     *  Inport: '<Root>/In1'
     */
    controller1_f4_3D_fuzzy(&controller1_U_In1[3], &controller1_B->rtb_fuzzy_g_p,
      &controller1_B->sf_f4_3D_fuzzy);

    /* MATLAB Function: '<S5>/f5_3D_fuzzy' incorporates:
     *  Inport: '<Root>/In1'
     */
    controller1_f4_3D_fuzzy(&controller1_U_In1[3], &controller1_B->rtb_fuzzy_o_c,
      &controller1_B->sf_f5_3D_fuzzy);

    /* SignalConversion generated from: '<S11>/ SFunction ' incorporates:
     *  Inport: '<Root>/In1'
     *  MATLAB Function: '<S5>/f6_2D_fuzzy'
     */
    rtb_TmpSignalConversionAtSFun_0 = controller1_U_In1[3];
    rtb_TmpSignalConversionAtSFun_1 = controller1_U_In1[5];

    /* MATLAB Function: '<S5>/f6_2D_fuzzy' */
    controller1_B->all = 0.0;
    for (i = 0; i < 11; i++) {
      controller1_B->mu_F1[i] = 0.0;
      switch (i + 1) {
       case 1:
        if (rtb_TmpSignalConversionAtSFun_0 <= -5.0) {
          controller1_B->mu_F1[i] = 1.0;
        } else {
          controller1_B->mu_F1[i] = exp(-((rtb_TmpSignalConversionAtSFun_0 -
            -5.0) * (rtb_TmpSignalConversionAtSFun_0 - -5.0)) /
            0.22222222222222221);
        }
        break;

       case 11:
        if (rtb_TmpSignalConversionAtSFun_0 >= 5.0) {
          controller1_B->mu_F1[i] = 1.0;
        } else {
          controller1_B->mu_F1[i] = exp(-((rtb_TmpSignalConversionAtSFun_0 - 5.0)
            * (rtb_TmpSignalConversionAtSFun_0 - 5.0)) / 0.22222222222222221);
        }
        break;

       default:
        controller1_B->t = rtb_TmpSignalConversionAtSFun_0 - ((real_T)i - 5.0);
        controller1_B->mu_F1[i] = exp(-(controller1_B->t * controller1_B->t) /
          0.22222222222222221);
        break;
      }

      for (b = 0; b < 11; b++) {
        switch (b + 1) {
         case 1:
          if (rtb_TmpSignalConversionAtSFun_1 <= -5.0) {
            controller1_B->M11 = 1.0;
            controller1_B->mu_F2[b] = 1.0;
          } else {
            controller1_B->M11 = exp(-((rtb_TmpSignalConversionAtSFun_0 - -5.0) *
              (rtb_TmpSignalConversionAtSFun_0 - -5.0)) / 0.22222222222222221);
            controller1_B->mu_F2[b] = controller1_B->M11;
          }
          break;

         case 11:
          if (rtb_TmpSignalConversionAtSFun_1 >= 5.0) {
            controller1_B->M11 = 1.0;
            controller1_B->mu_F2[b] = 1.0;
          } else {
            controller1_B->M11 = exp(-((rtb_TmpSignalConversionAtSFun_0 - 5.0) *
              (rtb_TmpSignalConversionAtSFun_0 - 5.0)) / 0.22222222222222221);
            controller1_B->mu_F2[b] = controller1_B->M11;
          }
          break;

         default:
          controller1_B->M11 = rtb_TmpSignalConversionAtSFun_0 - ((real_T)b -
            5.0);
          controller1_B->M11 = exp(-(controller1_B->M11 * controller1_B->M11) /
            0.22222222222222221);
          controller1_B->mu_F2[b] = controller1_B->M11;
          break;
        }

        controller1_B->all += controller1_B->mu_F1[i] * controller1_B->M11;
      }
    }

    for (i = 0; i < 11; i++) {
      for (b = 0; b < 11; b++) {
        controller1_B->PSI[b * 11 + i] = controller1_B->mu_F2[b] *
          controller1_B->mu_F1[i] / controller1_B->all;
      }
    }

    controller1_B->M11 = 0.0;
    for (i = 0; i < 121; i++) {
      rtb_TmpSignalConversionAtSFun_0 = controller1_B->PSI[i];
      controller1_B->M11 += rtb_TmpSignalConversionAtSFun_0 *
        rtb_TmpSignalConversionAtSFun_0;
    }

    /* MATLAB Function: '<Root>/controler ' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
     *  Inport: '<Root>/In1'
     *  Inport: '<Root>/x'
     *  MATLAB Function: '<S5>/f6_2D_fuzzy'
     *  SignalConversion generated from: '<S4>/ SFunction '
     */
    rtb_TmpSignalConversionAtSFun_0 = sin(0.8 * controller1_B->Clock2) * 0.11;
    if (controller1_B->Clock2 <= 11.5) {
      controller1_B->absxk = 10.5;
    } else {
      controller1_B->absxk = 0.0;
    }

    controller1_B->D_p[0] = controller1_U_x[0] - controller1_B->absxk;
    if (controller1_B->Clock2 <= 11.5) {
      controller1_B->absxk = 10.5;
      i = 10;
    } else {
      controller1_B->absxk = 0.0;
      i = 0;
    }

    controller1_B->D_p[1] = controller1_U_x[1] - controller1_B->absxk;
    controller1_B->D_p[2] = controller1_U_x[2] - (real_T)i;
    controller1_B->all = 0.0;
    controller1_B->d_norm = 0.0;
    rtb_TmpSignalConversionAtSFun_1 = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      controller1_B->absxk = controller1_B->D_p[i];
      controller1_B->all += (((real_T)y[3 * i + 1] * controller1_B->D_p[1] +
        (real_T)y[3 * i] * controller1_B->D_p[0]) + (real_T)y[3 * i + 2] *
        controller1_B->D_p[2]) * controller1_B->absxk;
      controller1_B->absxk = fabs(controller1_B->absxk);
      if (controller1_B->absxk > rtb_TmpSignalConversionAtSFun_1) {
        controller1_B->t = rtb_TmpSignalConversionAtSFun_1 /
          controller1_B->absxk;
        controller1_B->d_norm = controller1_B->d_norm * controller1_B->t *
          controller1_B->t + 1.0;
        rtb_TmpSignalConversionAtSFun_1 = controller1_B->absxk;
      } else {
        controller1_B->t = controller1_B->absxk /
          rtb_TmpSignalConversionAtSFun_1;
        controller1_B->d_norm += controller1_B->t * controller1_B->t;
      }
    }

    controller1_B->all = sqrt(controller1_B->all);
    controller1_B->d_norm = rtb_TmpSignalConversionAtSFun_1 * sqrt
      (controller1_B->d_norm);
    if (controller1_B->d_norm >= 4.5) {
      controller1_B->P = 0.0;
      controller1_B->t = 0.0;
    } else if (controller1_B->all <= 1.5) {
      controller1_B->P = 100000.0;
      controller1_B->t = 100000.0;
    } else {
      rtb_TmpSignalConversionAtSFun_1 = controller1_B->d_norm *
        controller1_B->d_norm * 3.1415926535897931 / 20.25;
      controller1_B->absxk = cos(rtb_TmpSignalConversionAtSFun_1);
      controller1_B->P = (controller1_B->absxk + 1.0) * (controller1_B->absxk +
        1.0) / 2.0 * ((controller1_B->all - 2.25) * (controller1_B->all - 2.25))
        * 20.0;
      controller1_B->t = (controller1_B->absxk + 1.0) * -0.620561511820206 * sin
        (rtb_TmpSignalConversionAtSFun_1) * controller1_B->d_norm;
    }

    controller1_B->zp1[0] = controller1_U_x[0] - controller1_B->Clock2;
    controller1_B->zp1[1] = controller1_U_x[1] - controller1_B->Clock2;
    controller1_B->zp1[2] = controller1_U_x[2] - controller1_B->Clock2;
    controller1_B->absxk = (-10.8 -
      (controller1_DW->DiscreteTimeIntegrator1_DSTATE + 1.0)) - controller1_B->P
      / 2.0 * (controller1_DW->DiscreteTimeIntegrator1_DSTATE + 1.0);
    rtb_TmpSignalConversionAtSFun_1 = controller1_B->P * controller1_B->P;
    controller1_B->all = (controller1_DW->DiscreteTimeIntegrator1_DSTATE + 1.0) *
      (controller1_DW->DiscreteTimeIntegrator1_DSTATE + 1.0);
    controller1_B->zp2_tmp[0] = (controller1_DW->DiscreteTimeIntegrator1_DSTATE
      + 1.0) * controller1_B->zp1[0];
    controller1_B->zp2_tmp_m[0] = controller1_B->P * controller1_B->zp1[0];
    controller1_B->zp2_tmp[1] = (controller1_DW->DiscreteTimeIntegrator1_DSTATE
      + 1.0) * controller1_B->zp1[1];
    controller1_B->zp2_tmp_m[1] = controller1_B->P * controller1_B->zp1[1];
    controller1_B->zp2_tmp[2] = (controller1_DW->DiscreteTimeIntegrator1_DSTATE
      + 1.0) * controller1_B->zp1[2];
    controller1_B->zp2_tmp_m[2] = controller1_B->P * controller1_B->zp1[2];
    controller1_B->zp2[0] = (controller1_U_In1[0] - (((-10.8 *
      controller1_B->zp1[0] + controller1_B->Uk1[0]) - controller1_B->zp2_tmp[0])
      - controller1_B->zp2_tmp_m[0] / 2.0 *
      (controller1_DW->DiscreteTimeIntegrator1_DSTATE + 1.0))) -
      0.036637165272365588;
    controller1_B->zp2[1] = (controller1_U_In1[1] - (((-10.8 *
      controller1_B->zp1[1] + controller1_B->Uk1[1]) - controller1_B->zp2_tmp[1])
      - controller1_B->zp2_tmp_m[1] / 2.0 *
      (controller1_DW->DiscreteTimeIntegrator1_DSTATE + 1.0))) -
      0.18318582636182792;
    controller1_B->zp2[2] = (controller1_U_In1[2] - (((-10.8 *
      controller1_B->zp1[2] + controller1_B->Uk1[2]) - controller1_B->zp2_tmp[2])
      - controller1_B->zp2_tmp_m[2] / 2.0 *
      (controller1_DW->DiscreteTimeIntegrator1_DSTATE + 1.0))) -
      0.25646015690655904;
    if (controller1_B->d_norm >= 4.5) {
      controller1_B->V = 0.0;
    } else {
      controller1_B->d_norm = sin(controller1_B->d_norm * controller1_B->d_norm *
        -3.1415926535897931 / 2.0 * 20.25);
      controller1_B->V = (((controller1_U_In1[0] - 30.0) * (30.0 -
        controller1_U_In1[0]) + (controller1_U_In1[1] - 30.0) * (30.0 -
        controller1_U_In1[1])) + (controller1_U_In1[2] - 30.0) * (30.0 -
        controller1_U_In1[2])) * ((controller1_B->d_norm + 1.0) *
        (controller1_B->d_norm + 1.0) / 2.0);
    }

    controller1_B->rtb_fuzzy_l_k = ((controller1_B->rtb_fuzzy_l_k +
      controller1_B->rtb_fuzzy_b_c) + controller1_B->rtb_fuzzy_od_b) + 1.0;
    controller1_B->rtb_fuzzy_od_b = 1.0E-6 *
      controller1_DW->DiscreteTimeIntegrator_DSTATE[0] *
      controller1_B->rtb_fuzzy_l_k *
      (controller1_DW->DiscreteTimeIntegrator2_DSTATE + 1.0);
    controller1_B->D_p[0] = (controller1_U_In1[0] - controller1_B->Uk1[0]) *
      controller1_B->absxk;
    controller1_B->D_p[1] = (controller1_U_In1[1] - controller1_B->Uk1[1]) *
      controller1_B->absxk;
    controller1_B->D_p[2] = (controller1_U_In1[2] - controller1_B->Uk1[2]) *
      controller1_B->absxk;
    controller1_B->Diff_p_c[0] = controller1_B->Diff_p[0];
    controller1_B->Diff_p_c[1] = controller1_B->Diff_p[1];
    controller1_B->Diff_p_c[2] = controller1_B->Diff_p[2];
    controller1_B->c_a[0] = controller1_B->t * controller1_U_In1[0];
    controller1_B->c_a[3] = controller1_B->t * 0.0;
    controller1_B->c_a[6] = controller1_B->t * 0.0;
    controller1_B->c_a[1] = controller1_B->t * 0.0;
    controller1_B->c_a[4] = controller1_B->t * controller1_U_In1[1];
    controller1_B->c_a[7] = controller1_B->t * 0.0;
    controller1_B->c_a[2] = controller1_B->t * 0.0;
    controller1_B->c_a[5] = controller1_B->t * 0.0;
    controller1_B->c_a[8] = controller1_B->t * controller1_U_In1[2];
    for (i = 0; i < 3; i++) {
      controller1_B->absxk = 0.0;
      controller1_B->d_norm = 0.0;
      controller1_B->t = c_b_0[i + 3];
      c_b = c_b_0[i];
      controller1_B->z14 = c_b_0[i + 6];
      controller1_B->M12 = 0.0;
      for (b = 0; b < 3; b++) {
        controller1_B->rtb_fuzzy_b_c = controller1_B->zp2[b];
        controller1_B->absxk += ((d_b[3 * b + 1] * (controller1_B->t *
          controller1_B->V) + controller1_B->V * c_b * d_b[3 * b]) + d_b[3 * b +
          2] * (controller1_B->z14 * controller1_B->V)) *
          controller1_B->rtb_fuzzy_b_c;
        tmp = 3 * b + i;
        controller1_B->d_norm += h_a[tmp] * controller1_B->rtb_fuzzy_b_c;
        controller1_B->M12 += e_b[tmp] * controller1_B->rtb_fuzzy_od_b *
          controller1_B->rtb_fuzzy_b_c;
      }

      controller1_B->d_a[i] = controller1_B->M12;
      controller1_B->h_a[i] = ((controller1_B->d_norm - controller1_B->absxk /
        2.0 * (controller1_DW->DiscreteTimeIntegrator2_DSTATE + 1.0)) - d[i]) -
        e[i];
      controller1_B->a[i] = ((rtb_TmpSignalConversionAtSFun_1 *
        controller1_B->zp1[i] / 2.0 * controller1_B->all + (controller1_B->D_p[i]
        + controller1_B->Diff_p_c[i])) - ((controller1_B->c_a[i + 3] *
        controller1_B->zp1[1] + controller1_B->c_a[i] * controller1_B->zp1[0]) +
        controller1_B->c_a[i + 6] * controller1_B->zp1[2]) / 2.0 *
        (controller1_DW->DiscreteTimeIntegrator1_DSTATE + 1.0)) -
        controller1_B->zp2_tmp_m[i];
    }

    controller1_B->t = cos(rtb_TmpSignalConversionAtSFun_0);
    c_b = sin(rtb_TmpSignalConversionAtSFun_0);
    controller1_B->rtb_fuzzy_b_c = controller1_U_x[5] -
      rtb_TmpSignalConversionAtSFun_0;
    controller1_B->d_norm = sin(2.0 * controller1_B->Clock2) + 50.0;
    rtb_TmpSignalConversionAtSFun_1 = controller1_B->d_norm -
      rtb_TmpSignalConversionAtSFun_0;
    controller1_B->rtb_fuzzy_od_b = controller1_B->rtb_fuzzy_b_c *
      controller1_B->rtb_fuzzy_b_c;
    rtb_TmpSignalConversionAtSFun_1 = 1.0 / (rtb_TmpSignalConversionAtSFun_1 *
      rtb_TmpSignalConversionAtSFun_1 - controller1_B->rtb_fuzzy_od_b);
    controller1_B->all = (controller1_U_In1[5] - (-6.8 *
      controller1_B->rtb_fuzzy_b_c - 0.1 * rtb_TmpSignalConversionAtSFun_1 *
      controller1_B->rtb_fuzzy_b_c * (controller1_B->Uk1[5] * controller1_B->
      Uk1[5]))) - 0.024318019154289876;
    controller1_B->rtb_fuzzy_g_p = ((controller1_B->rtb_fuzzy_g_p +
      controller1_B->rtb_fuzzy_o_c) + controller1_B->M11) + 1.0;
    controller1_B->rtb_fuzzy_b_c = 0.0;
    controller1_B->absxk = controller1_B->a[1];
    controller1_B->rtb_fuzzy_o_c = controller1_B->a[0];
    controller1_B->M11 = controller1_B->a[2];
    for (i = 0; i < 3; i++) {
      controller1_B->D_p[i] = ((c_b_0[i + 3] * controller1_B->absxk + c_b_0[i] *
        controller1_B->rtb_fuzzy_o_c) + c_b_0[i + 6] * controller1_B->M11) +
        ((controller1_B->h_a[i] - controller1_B->d_a[i]) -
         controller1_B->zp2_tmp[i] /
         (controller1_DW->DiscreteTimeIntegrator2_DSTATE + 1.0));
      controller1_B->z14 = controller1_B->zp2[i];
      controller1_B->rtb_fuzzy_b_c += controller1_B->z14 * controller1_B->z14;
    }

    controller1_B->rtb_fuzzy_o_c = asin((controller1_B->D_p[0] * c_b -
      controller1_B->D_p[1] * controller1_B->t) / sqrt((controller1_B->D_p[0] *
      controller1_B->D_p[0] + controller1_B->D_p[1] * controller1_B->D_p[1]) +
      controller1_B->D_p[2] * controller1_B->D_p[2]));
    controller1_B->absxk = atan((controller1_B->D_p[0] * controller1_B->t +
      controller1_B->D_p[1] * c_b) / controller1_B->D_p[2]);
    controller1_B->z14 = controller1_U_x[3] - controller1_B->rtb_fuzzy_o_c;
    controller1_B->t = controller1_U_x[4] - controller1_B->absxk;
    controller1_B->M11 = controller1_B->d_norm - controller1_B->rtb_fuzzy_o_c;
    controller1_B->M12 = controller1_B->d_norm - controller1_B->absxk;
    controller1_B->d_norm = controller1_B->z14 * controller1_B->z14;
    controller1_B->M11 = 1.0 / (controller1_B->M11 * controller1_B->M11 -
      controller1_B->d_norm);
    c_b = controller1_B->t * controller1_B->t;
    controller1_B->M12 = 1.0 / (controller1_B->M12 * controller1_B->M12 - c_b);
    controller1_B->z14 = (controller1_U_In1[3] - (-6.8 * controller1_B->z14 -
      0.1 * controller1_B->M11 * controller1_B->z14 * (controller1_B->Uk1[3] *
      controller1_B->Uk1[3]))) - 0.073214298684507018;
    controller1_B->t = (controller1_U_In1[4] - (-6.9 * controller1_B->t - 0.1 *
      controller1_B->M12 * controller1_B->t * (controller1_B->Uk1[4] *
      controller1_B->Uk1[4]))) - 0.048882371673784439;
    controller1_B->D_beta[0] = ((controller1_DW->DiscreteTimeIntegrator2_DSTATE
      + 1.0) * (controller1_DW->DiscreteTimeIntegrator2_DSTATE + 1.0) * (0.00525
      * controller1_B->rtb_fuzzy_l_k) * controller1_B->rtb_fuzzy_b_c - 0.001575 *
      controller1_DW->DiscreteTimeIntegrator_DSTATE[0]) / 1000.0;
    controller1_B->rtb_fuzzy_l_k = 2.0105 * controller1_B->rtb_fuzzy_g_p *
      controller1_B->rtb_fuzzy_g_p;
    controller1_B->D_beta[1] = controller1_B->z14 * controller1_B->z14 *
      controller1_B->rtb_fuzzy_l_k + -1.4 *
      controller1_DW->DiscreteTimeIntegrator_DSTATE[1];
    controller1_B->D_beta[2] = controller1_B->t * controller1_B->t *
      controller1_B->rtb_fuzzy_l_k + -1.4 *
      controller1_DW->DiscreteTimeIntegrator_DSTATE[2];
    controller1_B->D_beta[3] = controller1_B->all * controller1_B->all *
      controller1_B->rtb_fuzzy_l_k + -1.4 *
      controller1_DW->DiscreteTimeIntegrator_DSTATE[3];
    controller1_B->xd[0] = controller1_B->Clock2;
    controller1_B->xd[1] = controller1_B->Clock2;
    controller1_B->xd[2] = controller1_B->Clock2;
    controller1_B->xd[3] = controller1_B->rtb_fuzzy_o_c;
    controller1_B->xd[4] = controller1_B->absxk;
    controller1_B->xd[5] = rtb_TmpSignalConversionAtSFun_0;

    /* Outport: '<Root>/u' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
     *  MATLAB Function: '<Root>/controler '
     */
    controller1_Y_u[0] = controller1_B->D_p[0];
    controller1_Y_u[1] = controller1_B->D_p[1];
    controller1_Y_u[2] = controller1_B->D_p[2];
    controller1_Y_u[3] = ((-11.9 * controller1_B->z14 - controller1_B->M11 *
      controller1_B->M11 * 0.1 * controller1_B->d_norm * controller1_B->z14) -
                          0.0073214298684507011) - 0.8 *
      controller1_DW->DiscreteTimeIntegrator_DSTATE[1] *
      controller1_B->rtb_fuzzy_g_p * controller1_B->z14;
    controller1_Y_u[4] = ((-11.9 * controller1_B->t - controller1_B->M12 *
      controller1_B->M12 * 0.1 * c_b * controller1_B->t) - 0.0048882371673784446)
      - 0.8 * controller1_DW->DiscreteTimeIntegrator_DSTATE[2] *
      controller1_B->rtb_fuzzy_g_p * controller1_B->t;
    controller1_Y_u[5] = ((-11.9 * controller1_B->all -
      rtb_TmpSignalConversionAtSFun_1 * rtb_TmpSignalConversionAtSFun_1 * 0.1 *
      controller1_B->rtb_fuzzy_od_b * controller1_B->all) -
                          0.0024318019154289877) - 0.8 *
      controller1_DW->DiscreteTimeIntegrator_DSTATE[3] *
      controller1_B->rtb_fuzzy_g_p * controller1_B->all;
  }

  {
    int32_T i;

    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
    controller1_DW->DiscreteTransferFcn_states = controller1_B->xd[0] -
      -0.99004983 * controller1_DW->DiscreteTransferFcn_states;

    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn2' */
    controller1_DW->DiscreteTransferFcn2_states = controller1_B->xd[1] -
      -0.99004983 * controller1_DW->DiscreteTransferFcn2_states;

    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn1' */
    controller1_DW->DiscreteTransferFcn1_states = controller1_B->xd[2] -
      -0.99004983 * controller1_DW->DiscreteTransferFcn1_states;

    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn3' */
    controller1_DW->DiscreteTransferFcn3_states = controller1_B->xd[3] -
      -0.99004983 * controller1_DW->DiscreteTransferFcn3_states;

    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn4' */
    controller1_DW->DiscreteTransferFcn4_states = controller1_B->xd[4] -
      -0.99004983 * controller1_DW->DiscreteTransferFcn4_states;

    /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn5' */
    controller1_DW->DiscreteTransferFcn5_states = controller1_B->xd[5] -
      -0.99004983 * controller1_DW->DiscreteTransferFcn5_states;

    /* Update for UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    for (i = 0; i < 6; i++) {
      controller1_DW->UD_DSTATE_k[i] = controller1_B->TSamp_o[i];
    }

    /* End of Update for UnitDelay: '<S2>/UD' */

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    controller1_DW->DiscreteTimeIntegrator_DSTATE[0] += 0.001 *
      controller1_B->D_beta[0];
    controller1_DW->DiscreteTimeIntegrator_DSTATE[1] += 0.001 *
      controller1_B->D_beta[1];
    controller1_DW->DiscreteTimeIntegrator_DSTATE[2] += 0.001 *
      controller1_B->D_beta[2];
    controller1_DW->DiscreteTimeIntegrator_DSTATE[3] += 0.001 *
      controller1_B->D_beta[3];

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    controller1_DW->DiscreteTimeIntegrator1_DSTATE += 0.001 * controller1_B->P;

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
    controller1_DW->DiscreteTimeIntegrator2_DSTATE += 0.001 * controller1_B->V;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  controller1_M->Timing.t[0] =
    ((time_T)(++controller1_M->Timing.clockTick0)) *
    controller1_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    controller1_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void controller1_initialize(RT_MODEL_controller1_T *const controller1_M, real_T
  controller1_U_In1[6], real_T controller1_U_x[6], real_T controller1_Y_u[6])
{
  B_controller1_T *controller1_B = controller1_M->blockIO;
  DW_controller1_T *controller1_DW = controller1_M->dwork;

  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&controller1_M->solverInfo,
                          &controller1_M->Timing.simTimeStep);
    rtsiSetTPtr(&controller1_M->solverInfo, &rtmGetTPtr(controller1_M));
    rtsiSetStepSizePtr(&controller1_M->solverInfo,
                       &controller1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&controller1_M->solverInfo, (&rtmGetErrorStatus
      (controller1_M)));
    rtsiSetRTModelPtr(&controller1_M->solverInfo, controller1_M);
  }

  rtsiSetSimTimeStep(&controller1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&controller1_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(controller1_M, &controller1_M->Timing.tArray[0]);
  controller1_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) controller1_B), 0,
                sizeof(B_controller1_T));

  /* states (dwork) */
  (void) memset((void *)controller1_DW, 0,
                sizeof(DW_controller1_T));

  /* external inputs */
  (void)memset(&controller1_U_In1[0], 0, 6U * sizeof(real_T));
  (void)memset(&controller1_U_x[0], 0, 6U * sizeof(real_T));

  /* external outputs */
  (void)memset(&controller1_Y_u[0], 0, 6U * sizeof(real_T));
}

/* Model terminate function */
void controller1_terminate(RT_MODEL_controller1_T *const controller1_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(controller1_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
