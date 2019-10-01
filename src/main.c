/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:34:08 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/04/07 18:09:05 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		error(char *str)
{
	ft_putstr(str);
	return(-1);
}

void		init_env(t_var *var)
{
	//var->color = 0x000C1210;
	var->color = 0x00110201;
	var->it_max = 50;
	//var->zoom = 400;
	var->x1 = -2.1;
	var->x2 = 0.6;
	var->y1 = -1.2;
	var->y2 = 2;
}


int		main()
{
	t_var	*var;

	if (!(var = (t_var *)malloc(sizeof(t_var))))
		return(error("malloc error"));
	init_env(var);
	init_mlx(var);
	mlx_hook(var->win_ptr, 2, 1, key_press, var);
	mlx_expose_hook(var->win_ptr, expose_hook, var);
	mlx_loop(var->mlx_ptr);
	return (0);
}
