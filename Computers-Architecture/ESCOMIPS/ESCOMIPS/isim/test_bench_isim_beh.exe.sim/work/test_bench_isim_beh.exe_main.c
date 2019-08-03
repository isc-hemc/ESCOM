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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *STD_STANDARD;
char *WORK_P_0102800657;
char *IEEE_P_3499444699;
char *IEEE_P_1242562249;
char *WORK_P_3633938752;
char *IEEE_P_3620187407;
char *IEEE_P_2592010699;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    work_p_3633938752_init();
    work_p_0102800657_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    ieee_p_1242562249_init();
    work_a_2901242090_1033135635_init();
    work_a_4201587701_1394663956_init();
    work_a_2350894660_0057919484_init();
    work_a_2564808399_1866643722_init();
    work_a_0179176252_0356776894_init();
    work_a_2263464102_0136054119_init();
    work_a_4028475423_2072577406_init();
    work_a_2180653485_3744881843_init();
    work_a_4013391153_3456191687_init();
    work_a_1289662307_2781234708_init();
    work_a_2351365864_1499595665_init();
    work_a_1802162170_0488466564_init();
    work_a_1365290634_2208187658_init();
    work_a_0352817100_4185824078_init();
    work_a_0095573003_2729759962_init();
    work_a_4001821752_1440508606_init();
    work_a_2578365841_2372691052_init();


    xsi_register_tops("work_a_2578365841_2372691052");

    STD_STANDARD = xsi_get_engine_memory("std_standard");
    WORK_P_0102800657 = xsi_get_engine_memory("work_p_0102800657");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    WORK_P_3633938752 = xsi_get_engine_memory("work_p_3633938752");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);

    return xsi_run_simulation(argc, argv);

}
