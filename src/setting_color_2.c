/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_color_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:06:33 by tsedigi           #+#    #+#             */
/*   Updated: 2016/05/11 10:06:35 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_color15(t_env *e)
{
	e->color[331] = 0xc9c9c9;
	e->color[332] = 0xcccccc;
	e->color[333] = 0xcfcfcf;
	e->color[334] = 0xd1d1d1;
	e->color[335] = 0xd4d4d4;
	e->color[336] = 0xd6d6d6;
	e->color[337] = 0xd9d9d9;
	e->color[338] = 0xdbdbdb;
	e->color[339] = 0xdedede;
	e->color[340] = 0xe0e0e0;
	e->color[341] = 0xe3e3e3;
	e->color[342] = 0xe5e5e5;
	e->color[343] = 0xe8e8e8;
	e->color[344] = 0xebebeb;
	e->color[345] = 0xededed;
	e->color[346] = 0xf0f0f0;
	e->color[347] = 0xf2f2f2;
	e->color[348] = 0xf5f5f5;
	e->color[349] = 0xf7f7f7;
	e->color[350] = 0xfafafa;
	e->color[351] = 0xfcfcfc;
	e->color[352] = 0xffffff;
	e->color[353] = 0xa9a9a9;
	e->color[354] = 0xa9a9a9;
	set_color16(e);
}

static void	set_color14(t_env *e)
{
	e->color[308] = 0x8f8f8f;
	e->color[309] = 0x919191;
	e->color[310] = 0x949494;
	e->color[311] = 0x969696;
	e->color[312] = 0x999999;
	e->color[313] = 0x9c9c9c;
	e->color[314] = 0x9e9e9e;
	e->color[315] = 0xa1a1a1;
	e->color[316] = 0xa3a3a3;
	e->color[317] = 0xa6a6a6;
	e->color[318] = 0xa8a8a8;
	e->color[319] = 0xababab;
	e->color[320] = 0xadadad;
	e->color[321] = 0xb0b0b0;
	e->color[322] = 0xb3b3b3;
	e->color[323] = 0xb5b5b5;
	e->color[324] = 0xb8b8b8;
	e->color[325] = 0xbababa;
	e->color[326] = 0xbdbdbd;
	e->color[327] = 0xbfbfbf;
	e->color[328] = 0xc2c2c2;
	e->color[329] = 0xc4c4c4;
	e->color[330] = 0xc7c7c7;
	set_color15(e);
}

static void	set_color13(t_env *e)
{
	e->color[284] = 0x525252;
	e->color[285] = 0x545454;
	e->color[286] = 0x575757;
	e->color[287] = 0x595959;
	e->color[288] = 0x5c5c5c;
	e->color[289] = 0x5e5e5e;
	e->color[290] = 0x616161;
	e->color[291] = 0x636363;
	e->color[292] = 0x666666;
	e->color[293] = 0x696969;
	e->color[294] = 0x6b6b6b;
	e->color[295] = 0x6e6e6e;
	e->color[296] = 0x707070;
	e->color[297] = 0x737373;
	e->color[298] = 0x757575;
	e->color[299] = 0x787878;
	e->color[300] = 0x7a7a7a;
	e->color[301] = 0x7d7d7d;
	e->color[302] = 0x7f7f7f;
	e->color[303] = 0x828282;
	e->color[304] = 0x858585;
	e->color[305] = 0x878787;
	e->color[306] = 0x8a8a8a;
	e->color[307] = 0x8c8c8c;
	set_color14(e);
}

static void	set_color12(t_env *e)
{
	e->color[257] = 0x141414;
	e->color[258] = 0x171717;
	e->color[260] = 0x1a1a1a;
	e->color[261] = 0x1c1c1c;
	e->color[262] = 0x1f1f1f;
	e->color[263] = 0x212121;
	e->color[264] = 0x242424;
	e->color[265] = 0x262626;
	e->color[266] = 0x292929;
	e->color[267] = 0x2b2b2b;
	e->color[268] = 0x2e2e2e;
	e->color[269] = 0x303030;
	e->color[270] = 0x333333;
	e->color[271] = 0x363636;
	e->color[272] = 0x383838;
	e->color[273] = 0x3b3b3b;
	e->color[274] = 0x3d3d3d;
	e->color[275] = 0x404040;
	e->color[278] = 0x424242;
	e->color[279] = 0x454545;
	e->color[280] = 0x474747;
	e->color[281] = 0x4a4a4a;
	e->color[282] = 0x4d4d4d;
	e->color[283] = 0x4f4f4f;
	set_color13(e);
}

void		set_color_11(t_env *e)
{
	e->color[233] = 0x7a378b;
	e->color[234] = 0xbf3eff;
	e->color[235] = 0xb23aee;
	e->color[236] = 0x9a32cd;
	e->color[237] = 0x68228b;
	e->color[238] = 0x9b30ff;
	e->color[239] = 0x912cee;
	e->color[240] = 0x7d26cd;
	e->color[241] = 0x551a8b;
	e->color[242] = 0xab82ff;
	e->color[243] = 0x9f79ee;
	e->color[244] = 0x8968cd;
	e->color[245] = 0x5d478b;
	e->color[246] = 0xffe1ff;
	e->color[247] = 0xeed2ee;
	e->color[248] = 0xcdb5cd;
	e->color[249] = 0x8b7b8b;
	e->color[250] = 0x30303;
	e->color[251] = 0x50505;
	e->color[252] = 0x80808;
	e->color[253] = 0xa0a0a;
	e->color[254] = 0xd0d0d;
	e->color[255] = 0xf0f0f;
	e->color[256] = 0x121212;
	set_color12(e);
}
