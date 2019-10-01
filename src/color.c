/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:30:26 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/26 15:09:45 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

unsigned int	rgbtohex(int r, int g, int b)
{
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF));
}

int				color_mix(t_var *var, int i)
{
	float	frequency;
	int		amplitude;
	int		red;
	int		green;
	int		blue;

	frequency = 0.3 + var->c_frequency;
	amplitude = 127 + var->amplitude;
	if (var->color_mode == 1)
	{
		red = sin(frequency * (float)i + 0) * amplitude + var->red;
		green = sin(frequency * (float)i + 2) * amplitude + var->green;
		blue = sin(frequency * (float)i + 4) * amplitude + var->blue;
	}
	else
	{
		red = sin(frequency * (float)i) * amplitude + var->red;
		green = sin(frequency * (float)i) * amplitude + var->green;
		blue = sin(frequency * (float)i) * amplitude + var->blue;
	}
	return (rgbtohex(red, green, blue));
}

void			create_colortab(t_var *var)
{
	int		i;

	i = 0;
	while (i <= 500)
	{
		var->color_tab[i] = color_mix(var, i);
		i++;
	}
}

void			set_color(t_var *var, int i, t_xy *coord)
{
	double		r;

	r = (double)i / var->it_max;
	r = (r <= 0) ? 0 : r;
	r = (r > 1) ? -1 : r;
	if (var->color_mode == 0)
	{
		if (r > 0.5 || r == 0)
			put_pixel(0x00000000, coord->x, coord->y, var->img_str);
		else
			put_pixel(var->color * (float)i / var->it_max, coord->x,
					coord->y, var->img_str);
	}
	else if (var->color_mode == 1 || var->color_mode == 2)
	{
		if (r > 0.5 || r == 0)
			put_pixel(0x00000000, coord->x, coord->y, var->img_str);
		else
			put_pixel(var->color_tab[i], coord->x, coord->y, var->img_str);
	}
}
