/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:11:25 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/04/07 17:16:51 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void		mandelbrot_algo(t_var *var, int x, int y)
{
	int			i;
	int			img_x;
	int			img_y;

	img_x = LENGTH;
	img_y = HEIGHT;
	var->zoom_x = img_x / (var->x2 - var->x1);
	var->zoom_y = img_x / (var->y2 - var->y1);
	while (x < img_x)
	{
		y = 0;
		while(y < img_y)
		{
			var->c_r = ((double)x / var->zoom_x) + var->x1;
			var->c_i = ((double)y / var->zoom_y) + var->y1;
			var->z_r = 0;
			var->z_i = 0;
			i = 0;
			while (var->z_r * var->z_r + var->z_i * var->z_i < 4 && i < var->it_max)
			{
				var->tmp = var->z_r;
				var->z_r = var->z_r * var->z_r - var->z_i * var->z_i + var->c_r;
				var->z_i = 2 * var->z_i * var->tmp + var->c_i;
				i++;
			}
			if (i == var->it_max)
				put_pixel(0x00000000, x, y, var->img_str);
			else
				put_pixel(var->color * i, x, y, var->img_str);
			y++;
		}
		x++;
	}
}

void		mandelbrot(t_var *var)
{
	double		x;
	double			y;

	x = 0;
	y = 0;

	mandelbrot_algo(var, x, y);
	/*
	while (x < HEIGHT)
	{
		while (y < LENGTH / HEIGHT)
		{
			mandelbrot_algo(var, x, y);
			y++;
		}
		x++;
	}
	*/
}
