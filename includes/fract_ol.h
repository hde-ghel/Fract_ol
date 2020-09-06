/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:48:57 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/04/07 17:00:59 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "keycode.h"
# include "../minilibx/mlx.h"

//a supprimer
#include <stdio.h>

# define ENDIAN 1
# define LENGTH 800
# define HEIGHT 600
# define BITS_PER_PIXEL 8

typedef struct	s_var
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_str;

	//img variable
	int			endian;
	int			bpp;
	int			height;
	int			length;

	//mandelbrot
	double		zoom_x;
	double		zoom_y;
	double		it_max;
	int			color;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;

}				t_var;

int			init_mlx(t_var *var);
void		init_img(t_var *var);
int			expose_hook(t_var *var);
int			error(char *str);
void		draw_img(t_var *var);
int			key_press(int key, t_var *var);
void		mandelbrot(t_var *var);
void		put_pixel(int color, int x, int y, int *img_str);

#endif
