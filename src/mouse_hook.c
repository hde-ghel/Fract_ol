/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:39:28 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/24 21:36:53 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		mouse_move(int x, int y, t_var *var)
{
	if (var->l_clic == 1 && x >= LENGTH - I_LENGTH && x <= LENGTH && y >= 0 &&
			y <= I_HEIGHT)
	{
		if (var->julia_mode == 1 && (var->fractale == 1 || var->fractale == 2 ||
					var->fractale == 3))
		{
			var->julia_c_r = -2.1 + (double)x / I_LENGTH * (var->x2 - var->x1);
			var->julia_c_i = -1.5 + (double)y / I_HEIGHT * (var->y2 - var->y1);
		}
		else
		{
			var->offset_x = ((var->previous_x - (double)x) / I_LENGTH) *
				(var->x2 - var->x1) / var->rzoom;
			var->offset_y = ((var->previous_y - (double)y) / I_LENGTH) *
				(var->y2 - var->y1) / var->rzoom;
			var->previous_x = (double)x;
			var->previous_y = (double)y;
		}
		expose_hook(var);
	}
	return (0);
}

int		mouse_release(int key, int x, int y, t_var *var)
{
	var->l_clic = 0;
	if (key == 12 && x == 2000 && y == 1000)
		ft_putstr("parametres are used");
	return (0);
}

void	mouse_centre(int x, int y, t_var *var)
{
	if (x >= LENGTH - I_LENGTH && x <= LENGTH && y >= 0 && y <= I_HEIGHT)
	{
		x = x - (LENGTH - I_LENGTH);
		var->r_xmouse = (double)x / I_LENGTH;
		var->r_ymouse = (double)y / I_HEIGHT;
	}
	else
	{
		var->r_xmouse = 0.5;
		var->r_ymouse = 0.5;
	}
}

int		mouse_hook(int key, int x, int y, t_var *var)
{
	var->offset_x = 0;
	var->offset_y = 0;
	var->x_centre = 0;
	var->y_centre = 0;
	if (key == SCROLLUP_KEY && var->rzoom < 97887578100179)
	{
		mouse_centre(x, y, var);
		var->rzoom += (0.1 * var->rzoom);
		var->x_centre = (var->x2 - var->x1) * var->r_xmouse / var->rzoom * 0.1;
		var->y_centre = (var->y2 - var->y1) * var->r_ymouse / var->rzoom * 0.1;
	}
	else if (key == SCROLLDOWN_KEY && var->rzoom > 0.5)
	{
		mouse_centre(x, y, var);
		var->temp = var->rzoom;
		var->rzoom = var->rzoom / 1.1;
		var->x_centre = (var->x2 - var->x1) * var->r_xmouse / var->temp * -0.1;
		var->y_centre = (var->y2 - var->y1) * var->r_ymouse / var->temp * -0.1;
	}
	mouse_hook_2(key, x, y, var);
	expose_hook(var);
	return (0);
}
