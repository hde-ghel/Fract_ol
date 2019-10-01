/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:00:47 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/04/06 16:49:31 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"


void		init_img(t_var *var)
{
	var->endian = ENDIAN;
	var->height = HEIGHT;
	var->length = LENGTH;
	var->bpp = BITS_PER_PIXEL;
}

void	put_pixel(int color, int x, int y, int *img_str)
{
	int		j;

	if (x > 0 && x < LENGTH && y > 0 && y < HEIGHT)
	{
		j = (y * LENGTH) + x;
		if (j >= 0 && j < (LENGTH * HEIGHT))
			img_str[j] = color;
	}
}

void		draw_img(t_var *var)
{
mandelbrot(var);
/*
	while(i != 200)
	{
		put_pixel(0x0032CD32, x, y, var->img_str);
		i++;
		x++;
		y++;
	}
*/
}
