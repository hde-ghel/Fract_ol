/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:42:24 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/04/06 16:49:15 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		init_mlx(t_var *var)
{
	init_img(var);
	if ((var->mlx_ptr = mlx_init()) == NULL)
		return(error("malloc error"));
	if ((var->win_ptr = mlx_new_window(var->mlx_ptr, LENGTH, HEIGHT, "Fractol"))
			== NULL)
		return (error("malloc error"));
	if ((var->img_ptr = mlx_new_image(var->mlx_ptr, LENGTH, HEIGHT)) == NULL)
		return(error("malloc error"));
	var->img_str = (int *)mlx_get_data_addr(var->img_ptr, &var->bpp
	, &var->length, &var->endian);
	return(0);
}

int		expose_hook(t_var *var)
{
	draw_img(var);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr, 0, 0);
	return(0);
}
