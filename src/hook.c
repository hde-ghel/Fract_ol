/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:49:36 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/24 21:48:47 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		clean(t_var *var)
{
	if (var->mlx_ptr != NULL)
		ft_delete_mlx(var);
	if (var->color_tab != NULL)
		ft_memdel((void **)&var->color_tab);
	if (var != NULL)
		ft_memdel((void **)&var);
	return (1);
}

void	color_hook(int key, t_var *var)
{
	if (key == C_KEY)
		var->color_mode = (var->color_mode == 2) ? 0 : var->color_mode + 1;
	else if (key == R_KEY && var->color_mode == 0)
		var->color *= (var->color < 0xF4FFFFF) ? 1.1 : 1;
	else if (key == E_KEY && var->color_mode == 0)
		var->color *= (var->color > 100) ? 0.9 : 1;
	else if (key == E_KEY && (var->color_mode == 1 || var->color_mode == 2))
		var->red -= (var->red > -127) ? 8 : 0;
	else if (key == R_KEY && (var->color_mode == 1 || var->color_mode == 2))
		var->red += (var->red < 127) ? 8 : 0;
	else if (key == F_KEY && (var->color_mode == 1 || var->color_mode == 2))
		var->green -= (var->green > -127) ? 8 : 0;
	else if (key == G_KEY && (var->color_mode == 1 || var->color_mode == 2))
		var->green += (var->green < 127) ? 8 : 0;
	else if (key == V_KEY && (var->color_mode == 1 || var->color_mode == 2))
		var->blue -= (var->blue > -127) ? 8 : 0;
	else if (key == B_KEY && (var->color_mode == 1 || var->color_mode == 2))
		var->blue += (var->blue < 127) ? 8 : 0;
	color_hook_2(key, var);
}

void	key_press2(int key, t_var *var)
{
	int		tmp;

	tmp = var->fractale;
	if (key == NK0_KEY || key == NK1_KEY || key == NK2_KEY || key == NK3_KEY
			|| key == NK4_KEY || key == NK5_KEY || key == NK6_KEY
			|| key == NK7_KEY || key == NK8_KEY || key == NK9_KEY)
		var->fractale = (key < 90) ? (key - 82) : (key - 83);
	if (var->fractale != tmp)
	{
		init_coord(var);
		init_env(var);
	}
}

int		key_press(int key, t_var *var)
{
	var->offset_x = 0;
	var->offset_y = 0;
	var->x_centre = 0;
	var->y_centre = 0;
	key_press2(key, var);
	if (key == ESC_KEY)
		clean_exit("Goodbye\n", var);
	else if (key == F5_KEY)
	{
		init_env(var);
		init_coord(var);
	}
	else if (key == NKPL_KEY && var->rzoom < 97887578100179)
	{
		var->rzoom += (0.1 * var->rzoom);
		var->x_centre = (var->x2 - var->x1) / 2 / var->rzoom * 0.1;
		var->y_centre = (var->y2 - var->y1) / 2 / var->rzoom * 0.1;
	}
	key_press_3(key, var);
	color_hook(key, var);
	expose_hook(var);
	return (0);
}
