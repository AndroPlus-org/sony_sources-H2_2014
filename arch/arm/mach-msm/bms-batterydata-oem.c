/* Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 * Copyright (C) 2014 Sony Mobile Communications Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/batterydata-lib.h>

static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 65},
	.y		= {1492, 1492, 1493, 1483, 1502},
	.cols	= 5
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 29,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.ocv		= {
				{4173, 4167, 4163, 4156, 4154},
				{4104, 4107, 4108, 4102, 4104},
				{4057, 4072, 4069, 4061, 4060},
				{3973, 4009, 4019, 4016, 4020},
				{3932, 3959, 3981, 3982, 3983},
				{3899, 3928, 3954, 3950, 3950},
				{3868, 3895, 3925, 3921, 3920},
				{3837, 3866, 3898, 3894, 3892},
				{3812, 3841, 3853, 3856, 3862},
				{3794, 3818, 3825, 3823, 3822},
				{3780, 3799, 3804, 3804, 3803},
				{3768, 3787, 3790, 3788, 3788},
				{3757, 3779, 3778, 3775, 3776},
				{3747, 3772, 3771, 3766, 3765},
				{3736, 3763, 3766, 3760, 3746},
				{3725, 3749, 3756, 3747, 3729},
				{3714, 3718, 3734, 3724, 3706},
				{3701, 3703, 3696, 3689, 3668},
				{3675, 3695, 3682, 3675, 3662},
				{3670, 3691, 3680, 3673, 3661},
				{3661, 3686, 3679, 3672, 3656},
				{3649, 3680, 3676, 3669, 3641},
				{3633, 3669, 3667, 3655, 3606},
				{3610, 3647, 3640, 3620, 3560},
				{3580, 3607, 3596, 3572, 3501},
				{3533, 3548, 3537, 3512, 3425},
				{3457, 3468, 3459, 3429, 3324},
				{3328, 3348, 3340, 3297, 3172},
				{3000, 3000, 3000, 3000, 3000}
	}
};

static struct sf_lut rbatt_sf = {
	.rows		= 29,
	.cols		= 5,
	/* row_entries are temperature */
	.row_entries	= {-20, 0, 20, 40, 65},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40,
					35, 30, 25, 20, 15, 10, 9, 8, 7, 6, 5,
					4, 3, 2, 1, 0},
	.sf		= {
				{357, 187, 100, 91, 91},
				{400, 208, 105, 94, 94},
				{390, 204, 106, 95, 96},
				{391, 201, 108, 98, 98},
				{391, 202, 110, 98, 100},
				{390, 200, 110, 99, 102},
				{389, 200, 110, 99, 102},
				{393, 202, 101, 93, 100},
				{407, 205, 99, 89, 94},
				{428, 208, 100, 91, 96},
				{455, 212, 102, 92, 98},
				{495, 220, 104, 93, 101},
				{561, 232, 107, 95, 102},
				{634, 245, 112, 98, 98},
				{714, 258, 114, 98, 98},
				{791, 266, 114, 97, 100},
				{871, 289, 108, 95, 97},
				{973, 340, 124, 108, 105},
				{489, 241, 109, 96, 99},
				{511, 246, 110, 96, 99},
				{534, 252, 111, 95, 98},
				{579, 263, 112, 96, 96},
				{636, 276, 111, 95, 97},
				{730, 294, 109, 96, 99},
				{868, 328, 112, 98, 104},
				{1089, 374, 119, 101, 115},
				{1559, 457, 128, 105, 213},
				{12886, 1026, 637, 422, 3269},
				{170899, 127211, 98968, 88907, 77102},
	}
};

struct bms_battery_data oem_batt_data = {
	.fcc			= 1500,
	.fcc_temp_lut		= &fcc_temp,
	.pc_temp_ocv_lut	= &pc_temp_ocv,
	.rbatt_sf_lut		= &rbatt_sf,
	.default_rbatt_mohm	= 236,
	.flat_ocv_threshold_uv	= 3800000,
};

struct bms_battery_data *bms_batt_data = &oem_batt_data;
int bms_batt_data_num = 1;
