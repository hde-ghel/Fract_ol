/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:49:36 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/04/07 17:03:52 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	key_press(int key, t_var *var)
{
	printf("%d\n", key);
	if (key == ESC_KEY)
		exit(0);
	else if (key == NKPL_KEY)
	{
		var->zoom_x += 20;
		var->zoom_y += 20;
	}
	else if (key == NKMN_KEY)
	{
		var->zoom_x -= 20;
		var->zoom_x -= 20;
	}
	else if (key == PUP_KEY)
		var->it_max += 2;
	else if (key == PDOWN_KEY)
		var->it_max -= 2;
	else if (key == E_KEY)
		var->color += 10;
	else if (key == R_KEY)
		var->color -= 10;
	expose_hook(var);
	//printf("zoom = %f\n it_max = %f\n color =  %d\n", var->zoom, var->it_max, var->color);
	return(0);
}
