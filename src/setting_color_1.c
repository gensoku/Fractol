/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_color_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:06:21 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:06:23 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_color_10(t_env *e)
{
	e->color[209] = 0x8b475d;
	e->color[210] = 0xff34b3;
	e->color[211] = 0xee30a7;
	e->color[212] = 0xcd2990;
	e->color[213] = 0x8b1c62;
	e->color[214] = 0xff3e96;
	e->color[215] = 0xee3a8c;
	e->color[216] = 0xcd3278;
	e->color[217] = 0x8b2252;
	e->color[218] = 0xff00ff;
	e->color[219] = 0xee00ee;
	e->color[220] = 0xcd00cd;
	e->color[221] = 0x8b008b;
	e->color[222] = 0xff83fa;
	e->color[223] = 0xee7ae9;
	e->color[224] = 0xcd69c9;
	e->color[225] = 0x8b4789;
	e->color[226] = 0xffbbff;
	e->color[227] = 0xeeaeee;
	e->color[228] = 0xcd96cd;
	e->color[229] = 0x8b668b;
	e->color[230] = 0xe066ff;
	e->color[231] = 0xd15fee;
	e->color[232] = 0xb452cd;
	set_color_11(e);
}

static void	set_color_9(t_env *e)
{
	e->color[185] = 0x8b2500;
	e->color[186] = 0xff0000;
	e->color[187] = 0xee0000;
	e->color[188] = 0xcd0000;
	e->color[189] = 0x8b0000;
	e->color[190] = 0xff1493;
	e->color[191] = 0xee1289;
	e->color[192] = 0xcd1076;
	e->color[193] = 0x8b0a50;
	e->color[194] = 0xff6eb4;
	e->color[195] = 0xee6aa7;
	e->color[196] = 0xcd6090;
	e->color[197] = 0x8b3a62;
	e->color[198] = 0xffb5c5;
	e->color[199] = 0xeea9b8;
	e->color[200] = 0xcd919e;
	e->color[201] = 0x8b636c;
	e->color[202] = 0xffaeb9;
	e->color[203] = 0xeea2ad;
	e->color[204] = 0xcd8c95;
	e->color[205] = 0x8b5f65;
	e->color[206] = 0xff82ab;
	e->color[207] = 0xee799f;
	e->color[208] = 0xcd6889;
	set_color_10(e);
}

static void	set_color_8(t_env *e)
{
	e->color[162] = 0xffa07a;
	e->color[163] = 0xee9572;
	e->color[164] = 0xcd8162;
	e->color[165] = 0x8b5742;
	e->color[166] = 0xffa500;
	e->color[167] = 0xee9a00;
	e->color[168] = 0xcd8500;
	e->color[169] = 0x8b5a00;
	e->color[170] = 0xff7f00;
	e->color[171] = 0xee7600;
	e->color[172] = 0xcd6600;
	e->color[173] = 0x8b4500;
	e->color[174] = 0xff7256;
	e->color[175] = 0xee6a50;
	e->color[176] = 0xcd5b45;
	e->color[177] = 0x8b3e2f;
	e->color[178] = 0xff6347;
	e->color[179] = 0xee5c42;
	e->color[180] = 0xcd4f39;
	e->color[181] = 0x8b3626;
	e->color[182] = 0xff4500;
	e->color[183] = 0xee4000;
	e->color[184] = 0xcd3700;
	set_color_9(e);
}

static void	set_color_7(t_env *e)
{
	e->color[139] = 0xeed8ae;
	e->color[140] = 0xcdba96;
	e->color[141] = 0x8b7e66;
	e->color[142] = 0xffa54f;
	e->color[143] = 0xee9a49;
	e->color[144] = 0xcd853f;
	e->color[145] = 0x8b5a2b;
	e->color[146] = 0xff7f24;
	e->color[147] = 0xee7621;
	e->color[148] = 0xcd661d;
	e->color[149] = 0x8b4513;
	e->color[150] = 0xff3030;
	e->color[151] = 0xee2c2c;
	e->color[152] = 0xcd2626;
	e->color[153] = 0x8b1a1a;
	e->color[154] = 0xff4040;
	e->color[155] = 0xee3b3b;
	e->color[156] = 0xcd3333;
	e->color[157] = 0x8b2323;
	e->color[158] = 0xff8c69;
	e->color[159] = 0xee8262;
	e->color[160] = 0xcd7054;
	e->color[161] = 0x8b4c39;
	set_color_8(e);
}

void		set_color_6(t_env *e)
{
	e->color[116] = 0xcd9b1d;
	e->color[117] = 0x8b6914;
	e->color[118] = 0xffb90f;
	e->color[119] = 0xeead0e;
	e->color[120] = 0xcd950c;
	e->color[121] = 0x8b6508;
	e->color[122] = 0xffc1c1;
	e->color[123] = 0xeeb4b4;
	e->color[124] = 0xcd9b9b;
	e->color[125] = 0x8b6969;
	e->color[126] = 0xff6a6a;
	e->color[127] = 0xee6363;
	e->color[128] = 0xcd5555;
	e->color[129] = 0x8b3a3a;
	e->color[130] = 0xff8247;
	e->color[131] = 0xee7942;
	e->color[132] = 0xcd6839;
	e->color[133] = 0x8b4726;
	e->color[134] = 0xffd39b;
	e->color[135] = 0xeec591;
	e->color[136] = 0xcdaa7d;
	e->color[137] = 0x8b7355;
	e->color[138] = 0xffe7ba;
	set_color_7(e);
}
