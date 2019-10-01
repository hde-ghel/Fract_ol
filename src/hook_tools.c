/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:33:41 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/24 21:52:58 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void		mouse_hook_2(int key, int x, int y, t_var *var)
{
	if (key == BUT1_KEY && x >= LENGTH - I_LENGTH && x <= LENGTH && y >= 0
			&& y <= I_HEIGHT)
	{
		var->previous_x = x;
		var->previous_y = y;
		var->l_clic = 1;
	}
}

void		color_hook_2(int key, t_var *var)
{
	if (key == M_KEY && var->c_frequency > -0.2)
		var->c_frequency -= 0.05;
	else if (key == N_KEY && var->c_frequency < 2)
		var->c_frequency += 0.05;
	else if (key == K_KEY && var->amplitude > -127)
		var->amplitude -= 5;
	else if (key == L_KEY && var->amplitude < 0)
		var->amplitude += 5;
	if ((var->color_mode == 1 || var->color_mode == 2) && (key == E_KEY ||
			key == R_KEY || key == F_KEY || key == G_KEY || key == V_KEY ||
			key == B_KEY || key == C_KEY || key == K_KEY || key == L_KEY ||
			key == N_KEY || key == M_KEY))
		create_colortab(var);
}

void		key_press_3(int key, t_var *var)
{
	if (key == NKMN_KEY && var->rzoom > 0.5)
	{
		var->temp = var->rzoom;
		var->rzoom = var->rzoom / 1.1;
		var->x_centre = (var->x2 - var->x1) / 2 / var->temp * -0.1;
		var->y_centre = (var->y2 - var->y1) / 2 / var->temp * -0.1;
	}
	else if (key == PUP_KEY && var->it_max < 500)
		var->it_max += 2;
	else if (key == PDOWN_KEY)
		var->it_max -= (var->it_max > 2) ? 2 : 0;
	else if (key == W_KEY)
		var->offset_y += 0.05 / var->rzoom;
	else if (key == S_KEY)
		var->offset_y -= 0.05 / var->rzoom;
	else if (key == A_KEY)
		var->offset_x += 0.05 / var->rzoom;
	else if (key == D_KEY)
		var->offset_x -= 0.05 / var->rzoom;
	else if (key == J_KEY)
		var->julia_mode = (var->julia_mode == 0) ? 1 : 0;
}
