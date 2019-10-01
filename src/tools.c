/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:08:08 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/24 22:24:36 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void		put_pixel(int color, int x, int y, int *img_str)
{
	int		j;

	if (x >= 0 && x < I_LENGTH && y >= 0 && y < I_HEIGHT)
	{
		j = (y * I_LENGTH) + x;
		if (j >= 0 && j < (I_LENGTH * I_HEIGHT))
			img_str[j] = color;
	}
}

void		init_img(t_var *var)
{
	var->endian = ENDIAN;
	var->height = I_HEIGHT;
	var->length = I_LENGTH;
	var->bpp = BITS_PER_PIXEL;
}

t_thread	*create_thread_struc(t_var *var)
{
	t_thread	*new;

	if (!(new = (t_thread *)malloc(sizeof(t_thread))))
		clean_exit("threads struct malloc", var);
	return (new);
}

void		clean_exit(char *str, t_var *var)
{
	error(str, var);
	exit(-1);
}

void		init_coord(t_var *var)
{
	if (var->fractale == 0 || var->fractale == 4 || var->fractale == 9)
	{
		var->x1 = -2.1;
		var->x2 = 0.6;
		var->y1 = -1.2;
		var->y2 = 1.2;
		var->it_max = 50;
	}
	else
	{
		var->x1 = -1.65;
		var->x2 = 1.55;
		var->y1 = -1.5;
		var->y2 = 1.5;
		var->it_max = 50;
	}
}
