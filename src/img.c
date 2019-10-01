/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:00:47 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/08/12 22:11:34 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void		init_rc(t_var *var, t_co *z, t_co *c, t_xy *coord)
{
	c->r = ((double)coord->x / var->zoom_x) + var->x1;
	c->i = ((double)coord->y / var->zoom_y) + var->y1;
	z->r = 0;
	z->i = 0;
	if (var->fractale == 1 || var->fractale == 2 || var->fractale == 3)
	{
		z->r = c->r;
		z->i = c->i;
		c->r = 0.285 + var->julia_c_r;
		c->i = 0.01 + var->julia_c_i;
	}
}

void		draw_fract(t_var *var, t_xy *coord)
{
	int			i;
	t_co		z;
	t_co		c;
	t_co		square;

	i = 0;
	init_rc(var, &z, &c, coord);
	square.r = z.r * z.r;
	square.i = z.i * z.i;
	while (square.r + square.i < 4 && i < var->it_max)
	{
		choose_fractale(var, &z, &c, &square);
		square.r = z.r * z.r;
		square.i = z.i * z.i;
		i++;
	}
	set_color(var, i, coord);
}

void		*img_filler(void *var)
{
	t_xy		coord;
	t_thread	*state;

	state = (t_thread*)var;
	while (++state->x < state->x_max)
	{
		state->y = -1;
		while (++state->y < I_HEIGHT)
		{
			coord.x = state->x;
			coord.y = state->y;
			draw_fract(state->var, &coord);
		}
	}
	free(state);
	pthread_exit(NULL);
}

void		threads_draw(t_var *var)
{
	int			i;
	t_thread	*state;
	pthread_t	threads[NB_THREAD];

	i = -1;
	while (++i < NB_THREAD)
	{
		state = create_thread_struc(var);
		state->x = i * I_LENGTH / NB_THREAD - 1;
		state->x_max = (i + 1) * I_LENGTH / NB_THREAD;
		state->var = var;
		if ((pthread_create(&threads[i], NULL, img_filler, state)))
			clean_exit("threads creation error", var);
	}
	i = 0;
	while (i < NB_THREAD)
	{
		if (pthread_join(threads[i], NULL))
			clean_exit("threads join error", var);
		i++;
	}
}

void		draw_img(t_var *var)
{
	offsets_init(var);
	threads_draw(var);
	draw_menu(var);
}
