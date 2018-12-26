//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: friction.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 20-Nov-2018 22:55:49
//

// Include Files
#include "rt_nonfinite.h"
#include "friction.h"

// Function Definitions

//
// function D = friction(Bvb,Bvk,Bvm,beta,dq1,dq2,dq3,dq4,dx,dy,q1,q2,q3,q4,rk,rw)
// FRICTION
//     D = FRICTION(BVB,BVK,BVM,BETA,DQ1,DQ2,DQ3,DQ4,DX,DY,Q1,Q2,Q3,Q4,RK,RW)
// Arguments    : float Bvb
//                float Bvk
//                float Bvm
//                double beta
//                float dq1
//                float dq2
//                float dq3
//                float dq4
//                float dx
//                float dy
//                float q1
//                float q2
//                float q3
//                float q4
//                float rk
//                float rw
//                float D[6]
// Return Type  : void
//
void friction(float Bvb, float Bvk, float Bvm, double beta, float dq1, float dq2,
              float dq3, float dq4, float dx, float dy, float q1, float q2,
              float q3, float q4, float rk, float rw, float D[6])
{
  float t2;
  float t3;
  float t4;
  float t5;
  float t6;
  float t7;
  float t8;
  float t9;
  float t10;
  float t11;
  float t12;
  float t26;
  float t40;
  float t57;

  //     This function was generated by the Symbolic Math Toolbox version 8.1.
  //     12-Nov-2018 22:44:49
  // 'friction:8' t2 = q1.^2;
  t2 = q1 * q1;

  // 'friction:9' t3 = q2.^2;
  t3 = q2 * q2;

  // 'friction:10' t4 = q3.^2;
  t4 = q3 * q3;

  // 'friction:11' t5 = q4.^2;
  t5 = q4 * q4;

  // 'friction:12' t6 = 1.0./rw.^2;
  t6 = 1.0F / (rw * rw);

  // 'friction:13' t7 = t2.^2;
  t7 = t2 * t2;

  // 'friction:14' t8 = t3.^2;
  t8 = t3 * t3;

  // 'friction:15' t9 = t4.^2;
  t9 = t4 * t4;

  // 'friction:16' t10 = t5.^2;
  t10 = t5 * t5;

  // 'friction:17' t11 = rw.^2;
  t11 = rw * rw;

  // 'friction:18' t12 = rk.^2;
  t12 = rk * rk;

  // 'friction:19' t13 = Bvm.*dy.*q2.*rk.*t3.*3.0;
  // 'friction:20' t14 = Bvm.*dq2.*q1.*q2.*t12.*6.0;
  // 'friction:21' t15 = Bvm.*dq3.*q1.*q3.*t12.*6.0;
  // 'friction:22' t16 = Bvm.*dq2.*q3.*q4.*t12.*6.0;
  // 'friction:23' t17 = Bvm.*dq4.*q1.*q4.*t12.*1.2e1;
  // 'friction:24' t18 = Bvm.*dy.*q2.*rk.*t2.*3.0;
  // 'friction:25' t19 = Bvm.*dy.*q2.*rk.*t4.*3.0;
  // 'friction:26' t20 = Bvm.*dy.*q2.*rk.*t5.*9.0;
  // 'friction:27' t21 = Bvb.*dq2.*q1.*q2.*t11.*8.0;
  // 'friction:28' t22 = Bvb.*dq3.*q1.*q3.*t11.*8.0;
  // 'friction:29' t23 = Bvb.*dq4.*q1.*q4.*t11.*8.0;
  // 'friction:30' t24 = Bvm.*dx.*q1.*q2.*q4.*rk.*6.0;
  // 'friction:31' t25 = Bvm.*dy.*q1.*q3.*q4.*rk.*6.0;
  // 'friction:32' t75 = Bvm.*dx.*q3.*rk.*t4.*3.0;
  // 'friction:33' t76 = Bvm.*dq1.*t3.*t12.*6.0;
  // 'friction:34' t77 = Bvm.*dq1.*t4.*t12.*6.0;
  // 'friction:35' t78 = Bvm.*dq1.*t5.*t12.*1.2e1;
  // 'friction:36' t79 = Bvb.*dq1.*t3.*t11.*8.0;
  // 'friction:37' t80 = Bvb.*dq1.*t4.*t11.*8.0;
  // 'friction:38' t81 = Bvb.*dq1.*t5.*t11.*8.0;
  // 'friction:39' t82 = Bvm.*dq3.*q2.*q4.*t12.*6.0;
  // 'friction:40' t83 = Bvm.*dx.*q3.*rk.*t2.*3.0;
  // 'friction:41' t84 = Bvm.*dx.*q3.*rk.*t3.*3.0;
  // 'friction:42' t85 = Bvm.*dx.*q3.*rk.*t5.*9.0;
  // 'friction:43' t26 = t13+t14+t15+t16+t17+t18+t19+t20+t21+t22+t23+t24+t25-t75-t76-t77-t78-t79-t80-t81-t82-t83-t84-t85; 
  t26 = ((((((((((((((((((((((Bvm * dy * q2 * rk * t3 * 3.0F + Bvm * dq2 * q1 *
    q2 * t12 * 6.0F) + Bvm * dq3 * q1 * q3 * t12 * 6.0F) + Bvm * dq2 * q3 * q4 *
    t12 * 6.0F) + Bvm * dq4 * q1 * q4 * t12 * 12.0F) + Bvm * dy * q2 * rk * t2 *
    3.0F) + Bvm * dy * q2 * rk * t4 * 3.0F) + Bvm * dy * q2 * rk * t5 * 9.0F) +
                       Bvb * dq2 * q1 * q2 * t11 * 8.0F) + Bvb * dq3 * q1 * q3 *
                      t11 * 8.0F) + Bvb * dq4 * q1 * q4 * t11 * 8.0F) + Bvm * dx
                    * q1 * q2 * q4 * rk * 6.0F) + Bvm * dy * q1 * q3 * q4 * rk *
                   6.0F) - Bvm * dx * q3 * rk * t4 * 3.0F) - Bvm * dq1 * t3 *
                 t12 * 6.0F) - Bvm * dq1 * t4 * t12 * 6.0F) - Bvm * dq1 * t5 *
               t12 * 12.0F) - Bvb * dq1 * t3 * t11 * 8.0F) - Bvb * dq1 * t4 *
             t11 * 8.0F) - Bvb * dq1 * t5 * t11 * 8.0F) - Bvm * dq3 * q2 * q4 *
           t12 * 6.0F) - Bvm * dx * q3 * rk * t2 * 3.0F) - Bvm * dx * q3 * rk *
         t3 * 3.0F) - Bvm * dx * q3 * rk * t5 * 9.0F;

  // 'friction:44' t27 = Bvm.*dy.*q1.*rk.*t2.*3.0;
  // 'friction:45' t28 = Bvm.*dq2.*t2.*t12.*6.0;
  // 'friction:46' t29 = Bvm.*dq2.*t4.*t12.*1.2e1;
  // 'friction:47' t30 = Bvm.*dq2.*t5.*t12.*6.0;
  // 'friction:48' t31 = Bvb.*dq2.*t2.*t11.*8.0;
  // 'friction:49' t32 = Bvb.*dq2.*t4.*t11.*8.0;
  // 'friction:50' t33 = Bvb.*dq2.*t5.*t11.*8.0;
  // 'friction:51' t34 = Bvm.*dq4.*q1.*q3.*t12.*6.0;
  // 'friction:52' t35 = Bvm.*dy.*q1.*rk.*t3.*3.0;
  // 'friction:53' t36 = Bvm.*dy.*q1.*rk.*t4.*9.0;
  // 'friction:54' t37 = Bvm.*dy.*q1.*rk.*t5.*3.0;
  // 'friction:55' t38 = Bvm.*dx.*q1.*q2.*q3.*rk.*6.0;
  // 'friction:56' t39 = Bvm.*dy.*q2.*q3.*q4.*rk.*6.0;
  // 'friction:57' t86 = Bvm.*dx.*q4.*rk.*t5.*3.0;
  // 'friction:58' t87 = Bvm.*dq1.*q1.*q2.*t12.*6.0;
  // 'friction:59' t88 = Bvm.*dq1.*q3.*q4.*t12.*6.0;
  // 'friction:60' t89 = Bvm.*dq3.*q2.*q3.*t12.*1.2e1;
  // 'friction:61' t90 = Bvm.*dq4.*q2.*q4.*t12.*6.0;
  // 'friction:62' t91 = Bvm.*dx.*q4.*rk.*t2.*3.0;
  // 'friction:63' t92 = Bvm.*dx.*q4.*rk.*t3.*3.0;
  // 'friction:64' t93 = Bvm.*dx.*q4.*rk.*t4.*9.0;
  // 'friction:65' t94 = Bvb.*dq1.*q1.*q2.*t11.*8.0;
  // 'friction:66' t95 = Bvb.*dq3.*q2.*q3.*t11.*8.0;
  // 'friction:67' t96 = Bvb.*dq4.*q2.*q4.*t11.*8.0;
  // 'friction:68' t40 = t27+t28+t29+t30+t31+t32+t33+t34+t35+t36+t37+t38+t39-t86-t87-t88-t89-t90-t91-t92-t93-t94-t95-t96; 
  t40 = ((((((((((((((((((((((Bvm * dy * q1 * rk * t2 * 3.0F + Bvm * dq2 * t2 *
    t12 * 6.0F) + Bvm * dq2 * t4 * t12 * 12.0F) + Bvm * dq2 * t5 * t12 * 6.0F) +
    Bvb * dq2 * t2 * t11 * 8.0F) + Bvb * dq2 * t4 * t11 * 8.0F) + Bvb * dq2 * t5
    * t11 * 8.0F) + Bvm * dq4 * q1 * q3 * t12 * 6.0F) + Bvm * dy * q1 * rk * t3 *
                       3.0F) + Bvm * dy * q1 * rk * t4 * 9.0F) + Bvm * dy * q1 *
                     rk * t5 * 3.0F) + Bvm * dx * q1 * q2 * q3 * rk * 6.0F) +
                   Bvm * dy * q2 * q3 * q4 * rk * 6.0F) - Bvm * dx * q4 * rk *
                  t5 * 3.0F) - Bvm * dq1 * q1 * q2 * t12 * 6.0F) - Bvm * dq1 *
                q3 * q4 * t12 * 6.0F) - Bvm * dq3 * q2 * q3 * t12 * 12.0F) - Bvm
              * dq4 * q2 * q4 * t12 * 6.0F) - Bvm * dx * q4 * rk * t2 * 3.0F) -
            Bvm * dx * q4 * rk * t3 * 3.0F) - Bvm * dx * q4 * rk * t4 * 9.0F) -
          Bvb * dq1 * q1 * q2 * t11 * 8.0F) - Bvb * dq3 * q2 * q3 * t11 * 8.0F)
    - Bvb * dq4 * q2 * q4 * t11 * 8.0F;

  // 'friction:69' t41 = Bvm.*dx.*q1.*rk.*t2.*3.0;
  // 'friction:70' t42 = Bvm.*dy.*q4.*rk.*t5.*3.0;
  // 'friction:71' t43 = Bvm.*dq1.*q1.*q3.*t12.*6.0;
  // 'friction:72' t44 = Bvm.*dq2.*q2.*q3.*t12.*1.2e1;
  // 'friction:73' t45 = Bvm.*dq4.*q1.*q2.*t12.*6.0;
  // 'friction:74' t46 = Bvm.*dq4.*q3.*q4.*t12.*6.0;
  // 'friction:75' t47 = Bvm.*dx.*q1.*rk.*t3.*9.0;
  // 'friction:76' t48 = Bvm.*dx.*q1.*rk.*t4.*3.0;
  // 'friction:77' t49 = Bvm.*dx.*q1.*rk.*t5.*3.0;
  // 'friction:78' t50 = Bvm.*dy.*q4.*rk.*t2.*3.0;
  // 'friction:79' t51 = Bvm.*dy.*q4.*rk.*t3.*9.0;
  // 'friction:80' t52 = Bvm.*dy.*q4.*rk.*t4.*3.0;
  // 'friction:81' t53 = Bvb.*dq1.*q1.*q3.*t11.*8.0;
  // 'friction:82' t54 = Bvb.*dq2.*q2.*q3.*t11.*8.0;
  // 'friction:83' t55 = Bvb.*dq4.*q3.*q4.*t11.*8.0;
  // 'friction:84' t56 = Bvm.*dy.*q1.*q2.*q3.*rk.*6.0;
  // 'friction:85' t97 = Bvm.*dq3.*t2.*t12.*6.0;
  // 'friction:86' t98 = Bvm.*dq3.*t3.*t12.*1.2e1;
  // 'friction:87' t99 = Bvm.*dq3.*t5.*t12.*6.0;
  // 'friction:88' t100 = Bvb.*dq3.*t2.*t11.*8.0;
  // 'friction:89' t101 = Bvb.*dq3.*t3.*t11.*8.0;
  // 'friction:90' t102 = Bvb.*dq3.*t5.*t11.*8.0;
  // 'friction:91' t103 = Bvm.*dq1.*q2.*q4.*t12.*6.0;
  // 'friction:92' t104 = Bvm.*dx.*q2.*q3.*q4.*rk.*6.0;
  // 'friction:93' t57 = t41+t42+t43+t44+t45+t46+t47+t48+t49+t50+t51+t52+t53+t54+t55+t56-t97-t98-t99-t100-t101-t102-t103-t104; 
  t57 = ((((((((((((((((((((((Bvm * dx * q1 * rk * t2 * 3.0F + Bvm * dy * q4 *
    rk * t5 * 3.0F) + Bvm * dq1 * q1 * q3 * t12 * 6.0F) + Bvm * dq2 * q2 * q3 *
    t12 * 12.0F) + Bvm * dq4 * q1 * q2 * t12 * 6.0F) + Bvm * dq4 * q3 * q4 * t12
    * 6.0F) + Bvm * dx * q1 * rk * t3 * 9.0F) + Bvm * dx * q1 * rk * t4 * 3.0F)
                       + Bvm * dx * q1 * rk * t5 * 3.0F) + Bvm * dy * q4 * rk *
                      t2 * 3.0F) + Bvm * dy * q4 * rk * t3 * 9.0F) + Bvm * dy *
                    q4 * rk * t4 * 3.0F) + Bvb * dq1 * q1 * q3 * t11 * 8.0F) +
                  Bvb * dq2 * q2 * q3 * t11 * 8.0F) + Bvb * dq4 * q3 * q4 * t11 *
                 8.0F) + Bvm * dy * q1 * q2 * q3 * rk * 6.0F) - Bvm * dq3 * t2 *
               t12 * 6.0F) - Bvm * dq3 * t3 * t12 * 12.0F) - Bvm * dq3 * t5 *
             t12 * 6.0F) - Bvb * dq3 * t2 * t11 * 8.0F) - Bvb * dq3 * t3 * t11 *
           8.0F) - Bvb * dq3 * t5 * t11 * 8.0F) - Bvm * dq1 * q2 * q4 * t12 *
         6.0F) - Bvm * dx * q2 * q3 * q4 * rk * 6.0F;

  // 'friction:94' t58 = Bvm.*dx.*q2.*rk.*t3.*3.0;
  // 'friction:95' t59 = Bvm.*dy.*q3.*rk.*t4.*3.0;
  // 'friction:96' t60 = Bvm.*dq4.*t2.*t12.*1.2e1;
  // 'friction:97' t61 = Bvm.*dq4.*t3.*t12.*6.0;
  // 'friction:98' t62 = Bvm.*dq4.*t4.*t12.*6.0;
  // 'friction:99' t63 = Bvb.*dq4.*t2.*t11.*8.0;
  // 'friction:100' t64 = Bvb.*dq4.*t3.*t11.*8.0;
  // 'friction:101' t65 = Bvb.*dq4.*t4.*t11.*8.0;
  // 'friction:102' t66 = Bvm.*dq2.*q1.*q3.*t12.*6.0;
  // 'friction:103' t67 = Bvm.*dx.*q2.*rk.*t2.*9.0;
  // 'friction:104' t68 = Bvm.*dx.*q2.*rk.*t4.*3.0;
  // 'friction:105' t69 = Bvm.*dx.*q2.*rk.*t5.*3.0;
  // 'friction:106' t70 = Bvm.*dy.*q3.*rk.*t2.*9.0;
  // 'friction:107' t71 = Bvm.*dy.*q3.*rk.*t3.*3.0;
  // 'friction:108' t72 = Bvm.*dy.*q3.*rk.*t5.*3.0;
  // 'friction:109' t73 = Bvm.*dy.*q1.*q2.*q4.*rk.*6.0;
  // 'friction:110' t105 = Bvm.*dq1.*q1.*q4.*t12.*1.2e1;
  // 'friction:111' t106 = Bvm.*dq3.*q1.*q2.*t12.*6.0;
  // 'friction:112' t107 = Bvm.*dq2.*q2.*q4.*t12.*6.0;
  // 'friction:113' t108 = Bvm.*dq3.*q3.*q4.*t12.*6.0;
  // 'friction:114' t109 = Bvb.*dq1.*q1.*q4.*t11.*8.0;
  // 'friction:115' t110 = Bvb.*dq2.*q2.*q4.*t11.*8.0;
  // 'friction:116' t111 = Bvb.*dq3.*q3.*q4.*t11.*8.0;
  // 'friction:117' t112 = Bvm.*dx.*q1.*q3.*q4.*rk.*6.0;
  // 'friction:118' t74 = t58+t59+t60+t61+t62+t63+t64+t65+t66+t67+t68+t69+t70+t71+t72+t73-t105-t106-t107-t108-t109-t110-t111-t112; 
  t12 = ((((((((((((((((((((((Bvm * dx * q2 * rk * t3 * 3.0F + Bvm * dy * q3 *
    rk * t4 * 3.0F) + Bvm * dq4 * t2 * t12 * 12.0F) + Bvm * dq4 * t3 * t12 *
    6.0F) + Bvm * dq4 * t4 * t12 * 6.0F) + Bvb * dq4 * t2 * t11 * 8.0F) + Bvb *
    dq4 * t3 * t11 * 8.0F) + Bvb * dq4 * t4 * t11 * 8.0F) + Bvm * dq2 * q1 * q3 *
                       t12 * 6.0F) + Bvm * dx * q2 * rk * t2 * 9.0F) + Bvm * dx *
                     q2 * rk * t4 * 3.0F) + Bvm * dx * q2 * rk * t5 * 3.0F) +
                   Bvm * dy * q3 * rk * t2 * 9.0F) + Bvm * dy * q3 * rk * t3 *
                  3.0F) + Bvm * dy * q3 * rk * t5 * 3.0F) + Bvm * dy * q1 * q2 *
                q4 * rk * 6.0F) - Bvm * dq1 * q1 * q4 * t12 * 12.0F) - Bvm * dq3
              * q1 * q2 * t12 * 6.0F) - Bvm * dq2 * q2 * q4 * t12 * 6.0F) - Bvm *
            dq3 * q3 * q4 * t12 * 6.0F) - Bvb * dq1 * q1 * q4 * t11 * 8.0F) -
          Bvb * dq2 * q2 * q4 * t11 * 8.0F) - Bvb * dq3 * q3 * q4 * t11 * 8.0F)
    - Bvm * dx * q1 * q3 * q4 * rk * 6.0F;

  // 'friction:119' D = [t6.*(Bvk.*dx.*t11.*4.0+Bvm.*dx.*t7.*3.0+Bvm.*dx.*t8.*3.0+Bvm.*dx.*t9.*3.0+Bvm.*dx.*t10.*3.0+Bvm.*dx.*t2.*t3.*1.8e1+Bvm.*dx.*t2.*t4.*6.0+Bvm.*dx.*t2.*t5.*6.0+Bvm.*dx.*t3.*t4.*6.0+Bvm.*dx.*t3.*t5.*6.0+Bvm.*dx.*t4.*t5.*1.8e1+Bvm.*dy.*q2.*q3.*t2.*1.2e1+Bvm.*dy.*q1.*q4.*t3.*1.2e1-Bvm.*dy.*q1.*q4.*t4.*1.2e1-Bvm.*dy.*q2.*q3.*t5.*1.2e1+Bvm.*dq1.*q3.*rk.*t2.*6.0-Bvm.*dq3.*q1.*rk.*t2.*6.0+Bvm.*dq1.*q3.*rk.*t3.*6.0-Bvm.*dq3.*q1.*rk.*t3.*1.8e1+Bvm.*dq1.*q3.*rk.*t4.*6.0-Bvm.*dq2.*q4.*rk.*t2.*6.0-Bvm.*dq3.*q1.*rk.*t4.*6.0+Bvm.*dq4.*q2.*rk.*t2.*1.8e1+Bvm.*dq1.*q3.*rk.*t5.*1.8e1-Bvm.*dq2.*q4.*rk.*t3.*6.0-Bvm.*dq3.*q1.*rk.*t5.*6.0+Bvm.*dq4.*q2.*rk.*t3.*6.0-Bvm.*dq2.*q4.*rk.*t4.*1.8e1+Bvm.*dq4.*q2.*rk.*t4.*6.0-Bvm.*dq2.*q4.*rk.*t5.*6.0+Bvm.*dq4.*q2.*rk.*t5.*6.0-Bvm.*dx.*q1.*q2.*q3.*q4.*2.4e1-Bvm.*dq1.*q1.*q2.*q4.*rk.*1.2e1+Bvm.*dq2.*q1.*q2.*q3.*rk.*1.2e1+Bvm.*dq3.*q2.*q3.*q4.*rk.*1.2e1-Bvm.*dq4.*q1.*q3.*q4.*rk.*1.2e1).*(1.0./4.0);t6.*(Bvk.*dy.*t11.*4.0+Bvm.*dy.*t7.*3.0+Bvm.*dy.*t8.*3.0+Bvm.*dy.*t9.*3.0+Bvm.*dy.*t10.*3.0+Bvm.*dy.*t2.*t3.*6.0+Bvm.*dy.*t2.*t4.*1.8e1+Bvm.*dy.*t2.*t5.*6.0+Bvm.*dy.*t3.*t4.*6.0+Bvm.*dy.*t3.*t5.*1.8e1+Bvm.*dy.*t4.*t5.*6.0+Bvm.*dx.*q2.*q3.*t2.*1.2e1+Bvm.*dx.*q1.*q4.*t3.*1.2e1-Bvm.*dx.*q1.*q4.*t4.*1.2e1-Bvm.*dx.*q2.*q3.*t5.*1.2e1-Bvm.*dq1.*q2.*rk.*t2.*6.0+Bvm.*dq2.*q1.*rk.*t2.*6.0-Bvm.*dq1.*q2.*rk.*t3.*6.0+Bvm.*dq2.*q1.*rk.*t3.*6.0-Bvm.*dq1.*q2.*rk.*t4.*6.0+Bvm.*dq2.*q1.*rk.*t4.*1.8e1-Bvm.*dq1.*q2.*rk.*t5.*1.8e1+Bvm.*dq2.*q1.*rk.*t5.*6.0-Bvm.*dq3.*q4.*rk.*t2.*6.0+Bvm.*dq4.*q3.*rk.*t2.*1.8e1-Bvm.*dq3.*q4.*rk.*t3.*1.8e1+Bvm.*dq4.*q3.*rk.*t3.*6.0-Bvm.*dq3.*q4.*rk.*t4.*6.0+Bvm.*dq4.*q3.*rk.*t4.*6.0-Bvm.*dq3.*q4.*rk.*t5.*6.0+Bvm.*dq4.*q3.*rk.*t5.*6.0+Bvm.*dy.*q1.*q2.*q3.*q4.*2.4e1-Bvm.*dq1.*q1.*q3.*q4.*rk.*1.2e1-Bvm.*dq3.*q1.*q2.*q3.*rk.*1.2e1+Bvm.*dq2.*q2.*q3.*q4.*rk.*1.2e1+Bvm.*dq4.*q1.*q2.*q4.*rk.*1.2e1).*(1.0./4.0);q2.*t6.*t26.*(1.0./2.0)+q1.*t6.*t40.*(1.0./2.0)-q4.*t6.*t57.*(1.0./2.0)-q3.*t6.*t74.*(1.0./2.0);q3.*t6.*t26.*(1.0./2.0)-q4.*t6.*t40.*(1.0./2.0)-q1.*t6.*t57.*(1.0./2.0)+q2.*t6.*t74.*(1.0./2.0);q4.*t6.*t26.*(1.0./2.0)+q3.*t6.*t40.*(1.0./2.0)+q2.*t6.*t57.*(1.0./2.0)+q1.*t6.*t74.*(1.0./2.0);beta.*(-1.0./2.0)]; 
  D[0] = t6 * (((((((((((((((((((((((((((((((((((Bvk * dx * t11 * 4.0F + Bvm *
    dx * t7 * 3.0F) + Bvm * dx * t8 * 3.0F) + Bvm * dx * t9 * 3.0F) + Bvm * dx *
    t10 * 3.0F) + Bvm * dx * t2 * t3 * 18.0F) + Bvm * dx * t2 * t4 * 6.0F) + Bvm
    * dx * t2 * t5 * 6.0F) + Bvm * dx * t3 * t4 * 6.0F) + Bvm * dx * t3 * t5 *
    6.0F) + Bvm * dx * t4 * t5 * 18.0F) + Bvm * dy * q2 * q3 * t2 * 12.0F) + Bvm
    * dy * q1 * q4 * t3 * 12.0F) - Bvm * dy * q1 * q4 * t4 * 12.0F) - Bvm * dy *
    q2 * q3 * t5 * 12.0F) + Bvm * dq1 * q3 * rk * t2 * 6.0F) - Bvm * dq3 * q1 *
    rk * t2 * 6.0F) + Bvm * dq1 * q3 * rk * t3 * 6.0F) - Bvm * dq3 * q1 * rk *
    t3 * 18.0F) + Bvm * dq1 * q3 * rk * t4 * 6.0F) - Bvm * dq2 * q4 * rk * t2 *
    6.0F) - Bvm * dq3 * q1 * rk * t4 * 6.0F) + Bvm * dq4 * q2 * rk * t2 * 18.0F)
    + Bvm * dq1 * q3 * rk * t5 * 18.0F) - Bvm * dq2 * q4 * rk * t3 * 6.0F) - Bvm
    * dq3 * q1 * rk * t5 * 6.0F) + Bvm * dq4 * q2 * rk * t3 * 6.0F) - Bvm * dq2 *
                       q4 * rk * t4 * 18.0F) + Bvm * dq4 * q2 * rk * t4 * 6.0F)
                     - Bvm * dq2 * q4 * rk * t5 * 6.0F) + Bvm * dq4 * q2 * rk *
                    t5 * 6.0F) - Bvm * dx * q1 * q2 * q3 * q4 * 24.0F) - Bvm *
                  dq1 * q1 * q2 * q4 * rk * 12.0F) + Bvm * dq2 * q1 * q2 * q3 *
                 rk * 12.0F) + Bvm * dq3 * q2 * q3 * q4 * rk * 12.0F) - Bvm *
               dq4 * q1 * q3 * q4 * rk * 12.0F) * 0.25F;
  D[1] = t6 * (((((((((((((((((((((((((((((((((((Bvk * dy * t11 * 4.0F + Bvm *
    dy * t7 * 3.0F) + Bvm * dy * t8 * 3.0F) + Bvm * dy * t9 * 3.0F) + Bvm * dy *
    t10 * 3.0F) + Bvm * dy * t2 * t3 * 6.0F) + Bvm * dy * t2 * t4 * 18.0F) + Bvm
    * dy * t2 * t5 * 6.0F) + Bvm * dy * t3 * t4 * 6.0F) + Bvm * dy * t3 * t5 *
    18.0F) + Bvm * dy * t4 * t5 * 6.0F) + Bvm * dx * q2 * q3 * t2 * 12.0F) + Bvm
    * dx * q1 * q4 * t3 * 12.0F) - Bvm * dx * q1 * q4 * t4 * 12.0F) - Bvm * dx *
    q2 * q3 * t5 * 12.0F) - Bvm * dq1 * q2 * rk * t2 * 6.0F) + Bvm * dq2 * q1 *
    rk * t2 * 6.0F) - Bvm * dq1 * q2 * rk * t3 * 6.0F) + Bvm * dq2 * q1 * rk *
    t3 * 6.0F) - Bvm * dq1 * q2 * rk * t4 * 6.0F) + Bvm * dq2 * q1 * rk * t4 *
    18.0F) - Bvm * dq1 * q2 * rk * t5 * 18.0F) + Bvm * dq2 * q1 * rk * t5 * 6.0F)
    - Bvm * dq3 * q4 * rk * t2 * 6.0F) + Bvm * dq4 * q3 * rk * t2 * 18.0F) - Bvm
    * dq3 * q4 * rk * t3 * 18.0F) + Bvm * dq4 * q3 * rk * t3 * 6.0F) - Bvm * dq3
                       * q4 * rk * t4 * 6.0F) + Bvm * dq4 * q3 * rk * t4 * 6.0F)
                     - Bvm * dq3 * q4 * rk * t5 * 6.0F) + Bvm * dq4 * q3 * rk *
                    t5 * 6.0F) + Bvm * dy * q1 * q2 * q3 * q4 * 24.0F) - Bvm *
                  dq1 * q1 * q3 * q4 * rk * 12.0F) - Bvm * dq3 * q1 * q2 * q3 *
                 rk * 12.0F) + Bvm * dq2 * q2 * q3 * q4 * rk * 12.0F) + Bvm *
               dq4 * q1 * q2 * q4 * rk * 12.0F) * 0.25F;
  D[2] = ((q2 * t6 * t26 * 0.5F + q1 * t6 * t40 * 0.5F) - q4 * t6 * t57 * 0.5F)
    - q3 * t6 * t12 * 0.5F;
  D[3] = ((q3 * t6 * t26 * 0.5F - q4 * t6 * t40 * 0.5F) - q1 * t6 * t57 * 0.5F)
    + q2 * t6 * t12 * 0.5F;
  D[4] = ((q4 * t6 * t26 * 0.5F + q3 * t6 * t40 * 0.5F) + q2 * t6 * t57 * 0.5F)
    + q1 * t6 * t12 * 0.5F;
  D[5] = (float)(beta * -0.5);
}

//
// File trailer for friction.cpp
//
// [EOF]
//