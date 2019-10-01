/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:12:19 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/25 14:39:21 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void		mandelbrot_algo(t_co *z, t_co *c, t_co *square)
{
	double		tmp;

	tmp = z->r;
	z->r = square->r - square->i + c->r;
	z->i = 2 * z->i * tmp + c->i;
}

void		julia_algo(t_co *z, t_co *c, t_co *square)
{
	double		tmp;

	tmp = z->r;
	z->r = square->r - square->i - 0.8 + c->r;
	z->i = 2 * z->i * tmp + c->i;
}

void		burning_ship_algo(t_co *z, t_co *c, t_co *square)
{
	double		tmp;

	tmp = z->r;
	z->r = square->r - square->i + c->r;
	z->i = 2 * fabs(tmp * z->i) + c->i;
}
