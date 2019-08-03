/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/David Martinez/Desktop/Arquitectura de computadoras - ESCOMIPS/ESCOMIPS/Components/stack.vhd";
extern char *IEEE_P_3620187407;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );


static void work_a_4013391153_3456191687_p_0(char *t0)
{
    char t29[16];
    char t30[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    int t12;
    int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned char t18;
    unsigned char t19;
    unsigned char t20;
    unsigned char t21;
    unsigned char t22;
    unsigned char t23;
    unsigned char t24;
    unsigned char t25;
    unsigned char t26;
    unsigned char t27;
    char *t28;
    unsigned int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t39;

LAB0:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1632U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB12;

LAB13:    t3 = (unsigned char)0;

LAB14:    if (t3 != 0)
        goto LAB10;

LAB11:
LAB3:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    t6 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t29, t6, 3);
    t5 = (t0 + 4192);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 3U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(51, ng0);
    t1 = (t0 + 2808U);
    t2 = *((char **)t1);
    t1 = (t0 + 2688U);
    t5 = *((char **)t1);
    t6 = *((int *)t5);
    t7 = (t6 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t6);
    t15 = (16U * t14);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t8 = (t0 + 4256);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t17 = *((char **)t11);
    memcpy(t17, t1, 16U);
    xsi_driver_first_trans_fast_port(t8);
    t1 = (t0 + 4112);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(30, ng0);
    t1 = (t0 + 7944);
    *((int *)t1) = 0;
    t5 = (t0 + 7948);
    *((int *)t5) = 7;
    t6 = 0;
    t7 = 7;

LAB5:    if (t6 <= t7)
        goto LAB6;

LAB8:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    t1 = (t2 + 0);
    *((int *)t1) = 0;
    goto LAB3;

LAB6:    xsi_set_current_line(31, ng0);
    t8 = xsi_get_transient_memory(16U);
    memset(t8, 0, 16U);
    t9 = t8;
    memset(t9, (unsigned char)2, 16U);
    t10 = (t0 + 2808U);
    t11 = *((char **)t10);
    t10 = (t0 + 7944);
    t12 = *((int *)t10);
    t13 = (t12 - 0);
    t14 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, *((int *)t10));
    t15 = (16U * t14);
    t16 = (0 + t15);
    t17 = (t11 + t16);
    memcpy(t17, t8, 16U);

LAB7:    t1 = (t0 + 7944);
    t6 = *((int *)t1);
    t2 = (t0 + 7948);
    t7 = *((int *)t2);
    if (t6 == t7)
        goto LAB8;

LAB9:    t12 = (t6 + 1);
    t6 = t12;
    t5 = (t0 + 7944);
    *((int *)t5) = t6;
    goto LAB5;

LAB10:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 1832U);
    t8 = *((char **)t2);
    t22 = *((unsigned char *)t8);
    t23 = (t22 == (unsigned char)3);
    if (t23 == 1)
        goto LAB21;

LAB22:    t21 = (unsigned char)0;

LAB23:    if (t21 == 1)
        goto LAB18;

LAB19:    t20 = (unsigned char)0;

LAB20:    if (t20 != 0)
        goto LAB15;

LAB17:
LAB16:    xsi_set_current_line(38, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t18 = *((unsigned char *)t2);
    t19 = (t18 == (unsigned char)3);
    if (t19 == 1)
        goto LAB30;

LAB31:    t4 = (unsigned char)0;

LAB32:    if (t4 == 1)
        goto LAB27;

LAB28:    t3 = (unsigned char)0;

LAB29:    if (t3 != 0)
        goto LAB24;

LAB26:
LAB25:    xsi_set_current_line(42, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t18 = *((unsigned char *)t2);
    t19 = (t18 == (unsigned char)2);
    if (t19 == 1)
        goto LAB39;

LAB40:    t4 = (unsigned char)0;

LAB41:    if (t4 == 1)
        goto LAB36;

LAB37:    t3 = (unsigned char)0;

LAB38:    if (t3 != 0)
        goto LAB33;

LAB35:
LAB34:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t18 = *((unsigned char *)t2);
    t19 = (t18 == (unsigned char)2);
    if (t19 == 1)
        goto LAB48;

LAB49:    t4 = (unsigned char)0;

LAB50:    if (t4 == 1)
        goto LAB45;

LAB46:    t3 = (unsigned char)0;

LAB47:    if (t3 != 0)
        goto LAB42;

LAB44:
LAB43:    goto LAB3;

LAB12:    t2 = (t0 + 1672U);
    t5 = *((char **)t2);
    t18 = *((unsigned char *)t5);
    t19 = (t18 == (unsigned char)3);
    t3 = t19;
    goto LAB14;

LAB15:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1352U);
    t11 = *((char **)t2);
    t2 = (t0 + 2808U);
    t17 = *((char **)t2);
    t2 = (t0 + 2688U);
    t28 = *((char **)t2);
    t6 = *((int *)t28);
    t7 = (t6 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t6);
    t15 = (16U * t14);
    t16 = (0 + t15);
    t2 = (t17 + t16);
    memcpy(t2, t11, 16U);
    goto LAB16;

LAB18:    t2 = (t0 + 2152U);
    t10 = *((char **)t2);
    t26 = *((unsigned char *)t10);
    t27 = (t26 == (unsigned char)2);
    t20 = t27;
    goto LAB20;

LAB21:    t2 = (t0 + 1992U);
    t9 = *((char **)t2);
    t24 = *((unsigned char *)t9);
    t25 = (t24 == (unsigned char)2);
    t21 = t25;
    goto LAB23;

LAB24:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 2688U);
    t9 = *((char **)t1);
    t6 = *((int *)t9);
    t7 = (t6 + 1);
    t1 = (t0 + 2688U);
    t10 = *((char **)t1);
    t1 = (t10 + 0);
    *((int *)t1) = t7;
    xsi_set_current_line(40, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 2808U);
    t5 = *((char **)t1);
    t1 = (t0 + 2688U);
    t8 = *((char **)t1);
    t6 = *((int *)t8);
    t7 = (t6 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t6);
    t15 = (16U * t14);
    t16 = (0 + t15);
    t1 = (t5 + t16);
    memcpy(t1, t2, 16U);
    goto LAB25;

LAB27:    t1 = (t0 + 2152U);
    t8 = *((char **)t1);
    t22 = *((unsigned char *)t8);
    t23 = (t22 == (unsigned char)2);
    t3 = t23;
    goto LAB29;

LAB30:    t1 = (t0 + 1992U);
    t5 = *((char **)t1);
    t20 = *((unsigned char *)t5);
    t21 = (t20 == (unsigned char)3);
    t4 = t21;
    goto LAB32;

LAB33:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 2688U);
    t9 = *((char **)t1);
    t6 = *((int *)t9);
    t7 = (t6 - 1);
    t1 = (t0 + 2688U);
    t10 = *((char **)t1);
    t1 = (t10 + 0);
    *((int *)t1) = t7;
    xsi_set_current_line(44, ng0);
    t1 = (t0 + 2808U);
    t2 = *((char **)t1);
    t1 = (t0 + 2688U);
    t5 = *((char **)t1);
    t6 = *((int *)t5);
    t7 = (t6 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t6);
    t15 = (16U * t14);
    t16 = (0 + t15);
    t1 = (t2 + t16);
    t8 = (t30 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 15;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = -1;
    t12 = (0 - 15);
    t31 = (t12 * -1);
    t31 = (t31 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t31;
    t9 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t29, t1, t30, 1);
    t10 = (t0 + 2808U);
    t11 = *((char **)t10);
    t10 = (t0 + 2688U);
    t17 = *((char **)t10);
    t13 = *((int *)t17);
    t32 = (t13 - 0);
    t31 = (t32 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t13);
    t33 = (16U * t31);
    t34 = (0 + t33);
    t10 = (t11 + t34);
    t28 = (t29 + 12U);
    t35 = *((unsigned int *)t28);
    t36 = (1U * t35);
    memcpy(t10, t9, t36);
    goto LAB34;

LAB36:    t1 = (t0 + 2152U);
    t8 = *((char **)t1);
    t22 = *((unsigned char *)t8);
    t23 = (t22 == (unsigned char)3);
    t3 = t23;
    goto LAB38;

LAB39:    t1 = (t0 + 1992U);
    t5 = *((char **)t1);
    t20 = *((unsigned char *)t5);
    t21 = (t20 == (unsigned char)2);
    t4 = t21;
    goto LAB41;

LAB42:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 2808U);
    t9 = *((char **)t1);
    t1 = (t0 + 2688U);
    t10 = *((char **)t1);
    t6 = *((int *)t10);
    t7 = (t6 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t6);
    t15 = (16U * t14);
    t16 = (0 + t15);
    t1 = (t9 + t16);
    t11 = (t30 + 0U);
    t17 = (t11 + 0U);
    *((int *)t17) = 15;
    t17 = (t11 + 4U);
    *((int *)t17) = 0;
    t17 = (t11 + 8U);
    *((int *)t17) = -1;
    t12 = (0 - 15);
    t31 = (t12 * -1);
    t31 = (t31 + 1);
    t17 = (t11 + 12U);
    *((unsigned int *)t17) = t31;
    t17 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t29, t1, t30, 1);
    t28 = (t0 + 2808U);
    t37 = *((char **)t28);
    t28 = (t0 + 2688U);
    t38 = *((char **)t28);
    t13 = *((int *)t38);
    t32 = (t13 - 0);
    t31 = (t32 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t13);
    t33 = (16U * t31);
    t34 = (0 + t33);
    t28 = (t37 + t34);
    t39 = (t29 + 12U);
    t35 = *((unsigned int *)t39);
    t36 = (1U * t35);
    memcpy(t28, t17, t36);
    goto LAB43;

LAB45:    t1 = (t0 + 2152U);
    t8 = *((char **)t1);
    t22 = *((unsigned char *)t8);
    t23 = (t22 == (unsigned char)2);
    t3 = t23;
    goto LAB47;

LAB48:    t1 = (t0 + 1992U);
    t5 = *((char **)t1);
    t20 = *((unsigned char *)t5);
    t21 = (t20 == (unsigned char)2);
    t4 = t21;
    goto LAB50;

}


extern void work_a_4013391153_3456191687_init()
{
	static char *pe[] = {(void *)work_a_4013391153_3456191687_p_0};
	xsi_register_didat("work_a_4013391153_3456191687", "isim/test_bench_isim_beh.exe.sim/work/a_4013391153_3456191687.didat");
	xsi_register_executes(pe);
}
