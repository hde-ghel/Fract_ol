/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:11:25 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/24 21:28:32 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void		offsets_init(t_var *var)
{
	var->x1 += var->x_centre + var->offset_x;
	var->x2 += var->x_centre + var->offset_x;
	var->y1 += var->y_centre + var->offset_y;
	var->y2 += var->y_centre + var->offset_y;
	var->zoom_x = I_LENGTH / (var->x2 - var->x1) * var->rzoom;
	var->zoom_y = I_HEIGHT / (var->y2 - var->y1) * var->rzoom;
}

void		choose_fractale3(t_var *var, t_co *z, t_co *c, t_co *square)
{
	double	tmp;

	if (var->fractale == 8)
	{
		tmp = z->r;
		z->r = (square->r - (square->i * 3.0)) * fabs(z->r) + c->r;
		z->i = ((tmp * tmp * 3) - square->i) * fabs(z->i) + c->i;
	}
	else if (var->fractale == 9)
	{
		tmp = z->r;
		z->r = fabs(square->r - square->i) + c->r;
		z->i = 2 * fabs(tmp * z->i) + c->i;
	}
}

void		choose_fractale2(t_var *var, t_co *z, t_co *c, t_co *square)
{
	double		tmp;

	if (var->fractale == 5)
	{
		tmp = z->r;
		z->r = square->r - square->i + c->r;
		z->i = -2 * tmp * z->i + c->i;
	}
	else if (var->fractale == 6)
	{
		tmp = z->r;
		z->r = -(square->r - (square->i * 3.0)) * z->r + c->r;
		z->i = ((tmp * tmp * 3.0) - square->i) * z->i + c->i;
	}
	else if (var->fractale == 7)
	{
		tmp = z->r;
		z->r = square->r * square->r + square->i * square->i - 6 *
				square->r * square->i + c->r;
		z->i = 4 * tmp * z->i * (tmp * tmp - square->i) + c->i;
	}
	choose_fractale3(var, z, c, square);
}

void		choose_fractale(t_var *var, t_co *z, t_co *c, t_co *square)
{
	double		tmp;

	if (var->fractale == 0)
		mandelbrot_algo(z, c, square);
	else if (var->fractale == 1)
		julia_algo(z, c, square);
	else if (var->fractale == 2)
	{
		tmp = z->r;
		z->r = square->r * z->r - 3 * z->r * square->i - 0.8 + c->r;
		z->i = 3 * square->r * z->i - z->i * square->i + c->i;
	}
	else if (var->fractale == 3)
	{
		tmp = z->r;
		z->r = square->r * square->r + square->i * square->i - 6 *
				square->r * square->i - 0.8 + c->r;
		z->i = 4 * tmp * z->i * (tmp * tmp - square->i) + c->i;
	}
	else if (var->fractale == 4)
		burning_ship_algo(z, c, square);
	choose_fractale2(var, z, c, square);
}
