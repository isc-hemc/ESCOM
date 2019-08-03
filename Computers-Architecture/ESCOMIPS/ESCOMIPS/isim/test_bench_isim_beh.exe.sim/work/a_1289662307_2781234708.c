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
static const char *ng0 = "C:/Users/David Martinez/Desktop/Arquitectura de computadoras - ESCOMIPS/ESCOMIPS/Components/register_file.vhd";
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_2540846514_1035706684(char *, char *, char *, char *, int );
char *ieee_p_1242562249_sub_2547962040_1035706684(char *, char *, char *, char *, int );


static void work_a_1289662307_2781234708_p_0(char *t0)
{
    char t30[16];
    char t31[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    int t5;
    char *t6;
    int t7;
    int t8;
    char *t9;
    char *t10;
    char *t11;
    int t12;
    int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    unsigned char t22;
    unsigned char t23;
    unsigned char t24;
    unsigned char t25;
    unsigned char t26;
    unsigned char t27;
    unsigned char t28;
    char *t29;
    unsigned int t32;
    char *t33;
    int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;

LAB0:    xsi_set_current_line(23, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 2272U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB12;

LAB13:    t3 = (unsigned char)0;

LAB14:    if (t3 != 0)
        goto LAB10;

LAB11:
LAB3:    t1 = (t0 + 5048);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(24, ng0);
    t5 = (16 - 1);
    t1 = (t0 + 9645);
    *((int *)t1) = 0;
    t6 = (t0 + 9649);
    *((int *)t6) = t5;
    t7 = 0;
    t8 = t5;

LAB5:    if (t7 <= t8)
        goto LAB6;

LAB8:    goto LAB3;

LAB6:    xsi_set_current_line(25, ng0);
    t9 = xsi_get_transient_memory(16U);
    memset(t9, 0, 16U);
    t10 = t9;
    memset(t10, (unsigned char)2, 16U);
    t11 = (t0 + 9645);
    t12 = *((int *)t11);
    t13 = (t12 - 0);
    t14 = (t13 * 1);
    t15 = (16U * t14);
    t16 = (0U + t15);
    t17 = (t0 + 5160);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t9, 16U);
    xsi_driver_first_trans_delta(t17, t16, 16U, 0LL);

LAB7:    t1 = (t0 + 9645);
    t7 = *((int *)t1);
    t2 = (t0 + 9649);
    t8 = *((int *)t2);
    if (t7 == t8)
        goto LAB8;

LAB9:    t5 = (t7 + 1);
    t7 = t5;
    t6 = (t0 + 9645);
    *((int *)t6) = t7;
    goto LAB5;

LAB10:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 2472U);
    t9 = *((char **)t2);
    t25 = *((unsigned char *)t9);
    t26 = (t25 == (unsigned char)3);
    if (t26 == 1)
        goto LAB18;

LAB19:    t24 = (unsigned char)0;

LAB20:    if (t24 != 0)
        goto LAB15;

LAB17:
LAB16:    xsi_set_current_line(31, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t22 = *((unsigned char *)t2);
    t23 = (t22 == (unsigned char)3);
    if (t23 == 1)
        goto LAB27;

LAB28:    t4 = (unsigned char)0;

LAB29:    if (t4 == 1)
        goto LAB24;

LAB25:    t3 = (unsigned char)0;

LAB26:    if (t3 != 0)
        goto LAB21;

LAB23:
LAB22:    xsi_set_current_line(34, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t22 = *((unsigned char *)t2);
    t23 = (t22 == (unsigned char)3);
    if (t23 == 1)
        goto LAB36;

LAB37:    t4 = (unsigned char)0;

LAB38:    if (t4 == 1)
        goto LAB33;

LAB34:    t3 = (unsigned char)0;

LAB35:    if (t3 != 0)
        goto LAB30;

LAB32:
LAB31:    goto LAB3;

LAB12:    t2 = (t0 + 2312U);
    t6 = *((char **)t2);
    t22 = *((unsigned char *)t6);
    t23 = (t22 == (unsigned char)3);
    t3 = t23;
    goto LAB14;

LAB15:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 1992U);
    t11 = *((char **)t2);
    t2 = (t0 + 1032U);
    t17 = *((char **)t2);
    t2 = (t0 + 9196U);
    t5 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t17, t2);
    t7 = (t5 - 0);
    t14 = (t7 * 1);
    t15 = (16U * t14);
    t16 = (0U + t15);
    t18 = (t0 + 5160);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t29 = *((char **)t21);
    memcpy(t29, t11, 16U);
    xsi_driver_first_trans_delta(t18, t16, 16U, 0LL);
    goto LAB16;

LAB18:    t2 = (t0 + 2632U);
    t10 = *((char **)t2);
    t27 = *((unsigned char *)t10);
    t28 = (t27 == (unsigned char)2);
    t24 = t28;
    goto LAB20;

LAB21:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 2952U);
    t10 = *((char **)t1);
    t1 = (t0 + 1192U);
    t11 = *((char **)t1);
    t1 = (t0 + 9212U);
    t5 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t11, t1);
    t7 = (t5 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 15, 1, t5);
    t15 = (16U * t14);
    t16 = (0 + t15);
    t17 = (t10 + t16);
    t18 = (t31 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 15;
    t19 = (t18 + 4U);
    *((int *)t19) = 0;
    t19 = (t18 + 8U);
    *((int *)t19) = -1;
    t8 = (0 - 15);
    t32 = (t8 * -1);
    t32 = (t32 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t32;
    t19 = (t0 + 1512U);
    t20 = *((char **)t19);
    t19 = (t0 + 9244U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t20, t19);
    t21 = ieee_p_1242562249_sub_2547962040_1035706684(IEEE_P_1242562249, t30, t17, t31, t12);
    t29 = (t0 + 1032U);
    t33 = *((char **)t29);
    t29 = (t0 + 9196U);
    t13 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t33, t29);
    t34 = (t13 - 0);
    t32 = (t34 * 1);
    t35 = (16U * t32);
    t36 = (0U + t35);
    t37 = (t0 + 5160);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    memcpy(t41, t21, 16U);
    xsi_driver_first_trans_delta(t37, t36, 16U, 0LL);
    goto LAB22;

LAB24:    t1 = (t0 + 2792U);
    t9 = *((char **)t1);
    t26 = *((unsigned char *)t9);
    t27 = (t26 == (unsigned char)2);
    t3 = t27;
    goto LAB26;

LAB27:    t1 = (t0 + 2632U);
    t6 = *((char **)t1);
    t24 = *((unsigned char *)t6);
    t25 = (t24 == (unsigned char)3);
    t4 = t25;
    goto LAB29;

LAB30:    xsi_set_current_line(35, ng0);
    t1 = (t0 + 2952U);
    t10 = *((char **)t1);
    t1 = (t0 + 1192U);
    t11 = *((char **)t1);
    t1 = (t0 + 9212U);
    t5 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t11, t1);
    t7 = (t5 - 0);
    t14 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 15, 1, t5);
    t15 = (16U * t14);
    t16 = (0 + t15);
    t17 = (t10 + t16);
    t18 = (t31 + 0U);
    t19 = (t18 + 0U);
    *((int *)t19) = 15;
    t19 = (t18 + 4U);
    *((int *)t19) = 0;
    t19 = (t18 + 8U);
    *((int *)t19) = -1;
    t8 = (0 - 15);
    t32 = (t8 * -1);
    t32 = (t32 + 1);
    t19 = (t18 + 12U);
    *((unsigned int *)t19) = t32;
    t19 = (t0 + 1512U);
    t20 = *((char **)t19);
    t19 = (t0 + 9244U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t20, t19);
    t21 = ieee_p_1242562249_sub_2540846514_1035706684(IEEE_P_1242562249, t30, t17, t31, t12);
    t29 = (t0 + 1032U);
    t33 = *((char **)t29);
    t29 = (t0 + 9196U);
    t13 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t33, t29);
    t34 = (t13 - 0);
    t32 = (t34 * 1);
    t35 = (16U * t32);
    t36 = (0U + t35);
    t37 = (t0 + 5160);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    memcpy(t41, t21, 16U);
    xsi_driver_first_trans_delta(t37, t36, 16U, 0LL);
    goto LAB31;

LAB33:    t1 = (t0 + 2792U);
    t9 = *((char **)t1);
    t26 = *((unsigned char *)t9);
    t27 = (t26 == (unsigned char)3);
    t3 = t27;
    goto LAB35;

LAB36:    t1 = (t0 + 2632U);
    t6 = *((char **)t1);
    t24 = *((unsigned char *)t6);
    t25 = (t24 == (unsigned char)3);
    t4 = t25;
    goto LAB38;

}

static void work_a_1289662307_2781234708_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    xsi_set_current_line(40, ng0);

LAB3:    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t1 = (t0 + 1192U);
    t3 = *((char **)t1);
    t1 = (t0 + 9212U);
    t4 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t3, t1);
    t5 = (t4 - 0);
    t6 = (t5 * 1);
    xsi_vhdl_check_range_of_index(0, 15, 1, t4);
    t7 = (16U * t6);
    t8 = (0 + t7);
    t9 = (t2 + t8);
    t10 = (t0 + 5224);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t9, 16U);
    xsi_driver_first_trans_fast_port(t10);

LAB2:    t15 = (t0 + 5064);
    *((int *)t15) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1289662307_2781234708_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    xsi_set_current_line(41, ng0);

LAB3:    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t1 = (t0 + 9228U);
    t4 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t3, t1);
    t5 = (t4 - 0);
    t6 = (t5 * 1);
    xsi_vhdl_check_range_of_index(0, 15, 1, t4);
    t7 = (16U * t6);
    t8 = (0 + t7);
    t9 = (t2 + t8);
    t10 = (t0 + 5288);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t9, 16U);
    xsi_driver_first_trans_fast_port(t10);

LAB2:    t15 = (t0 + 5080);
    *((int *)t15) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_1289662307_2781234708_init()
{
	static char *pe[] = {(void *)work_a_1289662307_2781234708_p_0,(void *)work_a_1289662307_2781234708_p_1,(void *)work_a_1289662307_2781234708_p_2};
	xsi_register_didat("work_a_1289662307_2781234708", "isim/test_bench_isim_beh.exe.sim/work/a_1289662307_2781234708.didat");
	xsi_register_executes(pe);
}
