/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _SMI_CONFIGURATION_H_
#define _SMI_CONFIGURATION_H_

#include "smi_reg.h"
#include "mt_smi.h"

/* SMI common configuration */
#if defined(SMI_D1) || defined(SMI_D3) || defined(SMI_J)
	#define SMI_PARAM_BW_OPTIMIZATION (1)
	#define SMI_PARAM_BUS_OPTIMIZATION (0xFF)
	#define SMI_PARAM_ENABLE_IOCTL (1)
	#define SMI_PARAM_DISABLE_FREQ_HOPPING (0)
	#define SMI_PARAM_DISABLE_FREQ_MUX (1)
	#define SMI_PARAM_DISABLE_MMDVFS (0)
#elif defined(SMI_EV)
	#define SMI_PARAM_BW_OPTIMIZATION (1)
	#define SMI_PARAM_BUS_OPTIMIZATION (0x7F)
	#define SMI_PARAM_ENABLE_IOCTL (1)
	#define SMI_PARAM_DISABLE_FREQ_HOPPING (0)
	#define SMI_PARAM_DISABLE_FREQ_MUX (1)
	#define SMI_PARAM_DISABLE_MMDVFS (0)
#endif
/* ***********debug parameters************/


#define SMI_COMMON_DEFAULT_DEBUG_OFFSET_NUM 17
#define SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM 70


#if defined(SMI_D1) || defined(SMI_D3) || defined(SMI_J)
#define SMI_LARB0_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB1_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB2_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB3_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_COMMON_DEBUG_OFFSET_NUM SMI_COMMON_DEFAULT_DEBUG_OFFSET_NUM

#elif defined(SMI_D2)
#define SMI_LARB0_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB1_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB2_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_COMMON_DEBUG_OFFSET_NUM SMI_COMMON_DEFAULT_DEBUG_OFFSET_NUM

#elif defined(SMI_R)
#define SMI_LARB0_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB1_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_COMMON_DEBUG_OFFSET_NUM SMI_COMMON_DEFAULT_DEBUG_OFFSET_NUM

#elif defined(SMI_EV)
#define SMI_LARB0_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB1_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB2_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB3_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB4_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB5_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_LARB6_DEBUG_OFFSET_NUM SMI_LARB_DEFAULT_DEBUG_OFFSET_NUM
#define SMI_COMMON_DEBUG_OFFSET_NUM 23

#endif


struct SMI_SETTING_VALUE {
	unsigned int offset;
	int value;
};

struct SMI_SETTING {
	unsigned int smi_common_reg_num;
	struct SMI_SETTING_VALUE *smi_common_setting_vals;
	unsigned int smi_larb_reg_num[SMI_LARB_NR];
	struct SMI_SETTING_VALUE *smi_larb_setting_vals[SMI_LARB_NR];
};

struct SMI_PROFILE_CONFIG {
	int smi_profile;
	struct SMI_SETTING *setting;
};

struct SMI_CLK_INFO {
	char *name;
	unsigned long base_addr;
	unsigned short int offset;
};

enum SMI_CLK_ID {
	SMI_MTCMOS,
	SMI_CLK_LARB0,
	SMI_CLK_LARB1,
	SMI_CLK_LARB2,
	SMI_CLK_LARB3,
	SMI_CLK_LARB4,
	SMI_CLK_LARB5,
	SMI_CLK_LARB6,
	SMI_CLK_CNT
};

#define SMI_PROFILE_CONFIG_NUM SMI_BWC_SCEN_CNT
#define SMI_VC_SETTING_NUM SMI_LARB_NR

extern unsigned long smi_common_debug_offset[SMI_COMMON_DEBUG_OFFSET_NUM];
extern int smi_larb_debug_offset_num[SMI_LARB_NR];
extern unsigned long *smi_larb_debug_offset[SMI_LARB_NR];
extern struct SMI_SETTING_VALUE smi_vc_setting[SMI_VC_SETTING_NUM];
extern struct SMI_CLK_INFO smi_clk_info[SMI_CLK_CNT];
extern struct SMI_SETTING_VALUE *smi_larb_restore[SMI_LARB_NR];
extern unsigned int smi_restore_num[SMI_LARB_NR];
#endif
