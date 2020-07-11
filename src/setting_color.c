/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:06:11 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:06:12 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_color_5(t_env *e)
{
	e->color[93] = 0x6e8b3d;
	e->color[94] = 0xfff68f;
	e->color[95] = 0xeee685;
	e->color[96] = 0xcdc673;
	e->color[97] = 0x8b864e;
	e->color[98] = 0xffec8b;
	e->color[99] = 0xeedc82;
	e->color[100] = 0xcdbe70;
	e->color[101] = 0x8b814c;
	e->color[102] = 0xffffe0;
	e->color[103] = 0xeeeed1;
	e->color[104] = 0xcdcdb4;
	e->color[105] = 0x8b8b7a;
	e->color[106] = 0xffff00;
	e->color[107] = 0xeeee00;
	e->color[108] = 0xcdcd00;
	e->color[109] = 0x8b8b00;
	e->color[110] = 0xffd700;
	e->color[111] = 0xeec900;
	e->color[112] = 0xcdad00;
	e->color[113] = 0x8b7500;
	e->color[114] = 0xffc125;
	e->color[115] = 0xeeb422;
	set_color_6(e);
}

static void		set_color_4(t_env *e)
{
	e->color[70] = 0x9aff9a;
	e->color[71] = 0x90ee90;
	e->color[72] = 0x7ccd7c;
	e->color[73] = 0x548b54;
	e->color[74] = 0xff7f;
	e->color[75] = 0xee76;
	e->color[76] = 0xcd66;
	e->color[77] = 0x8b45;
	e->color[78] = 0xff00;
	e->color[79] = 0xee00;
	e->color[80] = 0xcd00;
	e->color[81] = 0x8b00;
	e->color[82] = 0x7fff00;
	e->color[83] = 0x76ee00;
	e->color[84] = 0x66cd00;
	e->color[85] = 0x458b00;
	e->color[86] = 0xc0ff3e;
	e->color[87] = 0xb3ee3a;
	e->color[88] = 0x9acd32;
	e->color[89] = 0x698b22;
	e->color[90] = 0xcaff70;
	e->color[91] = 0xbcee68;
	e->color[92] = 0xa2cd5a;
	set_color_5(e);
}

static void		set_color_3(t_env *e)
{
	e->color[47] = 0xb0c4de;
	e->color[48] = 0xadd8e6;
	e->color[49] = 0xb0e0e6;
	e->color[50] = 0xafeeee;
	e->color[51] = 0xced100;
	e->color[52] = 0x48d1cc;
	e->color[53] = 0x40e0d0;
	e->color[54] = 0xffff00;
	e->color[55] = 0xe0ffff;
	e->color[56] = 0x5f9ea0;
	e->color[57] = 0x66cdaa;
	e->color[58] = 0x7fffd4;
	e->color[59] = 0x76eec6;
	e->color[60] = 0x66cdaa;
	e->color[61] = 0x458b74;
	e->color[62] = 0xc1ffc1;
	e->color[63] = 0xb4eeb4;
	e->color[64] = 0x9bcd9b;
	e->color[65] = 0x698b69;
	e->color[66] = 0x54ff9f;
	e->color[67] = 0x4eee94;
	e->color[68] = 0x43cd80;
	e->color[69] = 0x2e8b57;
	set_color_4(e);
}

static void		set_color_2(t_env *e)
{
	e->color[24] = 0xfff0f5;
	e->color[25] = 0xffe4e1;
	e->color[26] = 0x2f4f4f;
	e->color[27] = 0x696969;
	e->color[28] = 0x708090;
	e->color[29] = 0x778899;
	e->color[30] = 0xbebebe;
	e->color[31] = 0xd3d3d3;
	e->color[32] = 0x191970;
	e->color[33] = 0x800000;
	e->color[34] = 0x6495ed;
	e->color[35] = 0x483d8b;
	e->color[36] = 0x6a5acd;
	e->color[37] = 0x7b68ee;
	e->color[38] = 0x8470ff;
	e->color[39] = 0xcd0000;
	e->color[40] = 0x4169e1;
	e->color[41] = 0xff0000;
	e->color[42] = 0x1e90ff;
	e->color[43] = 0xbfff00;
	e->color[44] = 0x87ceeb;
	e->color[45] = 0x87cefa;
	e->color[46] = 0x4682b4;
	set_color_3(e);
}

void			set_color(t_env *e)
{
	e->color[0] = 0xffffff;
	e->color[1] = 0xf8f8ff;
	e->color[2] = 0xf5f5f5;
	e->color[3] = 0xdcdcdc;
	e->color[4] = 0xfffaf0;
	e->color[5] = 0xfdf5e6;
	e->color[6] = 0xfaf0e6;
	e->color[7] = 0xfaebd7;
	e->color[8] = 0xffefd5;
	e->color[9] = 0xffebcd;
	e->color[10] = 0xffe4c4;
	e->color[11] = 0xffdab9;
	e->color[12] = 0xffdead;
	e->color[13] = 0xffe4b5;
	e->color[14] = 0xfff8dc;
	e->color[15] = 0xfffff0;
	e->color[17] = 0xfffacd;
	e->color[18] = 0xfff5ee;
	e->color[19] = 0xf0fff0;
	e->color[20] = 0xf5fffa;
	e->color[21] = 0xf0ffff;
	e->color[22] = 0xf0f8ff;
	e->color[23] = 0xe6e6fa;
	set_color_2(e);
}
