/*
* Copyright (C) 2016 MediaTek Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See http://www.gnu.org/licenses/gpl-2.0.html for more details.
*/
#ifndef __MT6631_FM_LIB_H__
#define __MT6631_FM_LIB_H__

#include "fm_typedef.h"

enum {
	DSPPATCH = 0xFFF9,
	USDELAY = 0xFFFA,
	MSDELAY = 0xFFFB,
	HW_VER = 0xFFFD,
	POLL_N = 0xFFFE,	/* poling check if bit(n) is '0' */
	POLL_P = 0xFFFF,	/* polling check if bit(n) is '1' */
};

enum {
	FM_PUS_DSPPATCH = DSPPATCH,
	FM_PUS_USDELAY = USDELAY,
	FM_PUS_MSDELAY = MSDELAY,
	FM_PUS_HW_VER = HW_VER,
	FM_PUS_POLL_N = POLL_N,	/* poling check if bit(n) is '0' */
	FM_PUS_POLL_P = POLL_P,	/* polling check if bit(n) is '1' */
	FM_PUS_MAX
};

enum {
	mt6631_E1 = 0,
	mt6631_E2
};

struct mt6631_fm_cqi {
	unsigned short ch;
	unsigned short rssi;
	unsigned short reserve;
};

struct adapt_fm_cqi {
	signed int ch;
	signed int rssi;
	signed int reserve;
};

struct mt6631_full_cqi {
	unsigned short ch;
	unsigned short rssi;
	unsigned short pamd;
	unsigned short pr;
	unsigned short fpamd;
	unsigned short mr;
	unsigned short atdc;
	unsigned short prx;
	unsigned short atdev;
	unsigned short smg;		/* soft-mute gain */
	unsigned short drssi;		/* delta rssi */
};

signed int mt6631_fm_low_ops_register(struct fm_callback *cb, struct fm_basic_interface *bi);
signed int mt6631_fm_low_ops_unregister(struct fm_basic_interface *bi);
signed int mt6631_fm_rds_ops_register(struct fm_basic_interface *bi, struct fm_rds_interface *ri);
signed int mt6631_fm_rds_ops_unregister(struct fm_rds_interface *ri);

#endif
