/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:48:57 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/25 14:50:30 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "../libft/includes/libft.h"
# include "keycode.h"
# include "../minilibx_macos/mlx.h"

# define ENDIAN 1
# define LENGTH 1200
# define HEIGHT 900
# define I_LENGTH 900
# define I_HEIGHT 800
# define BITS_PER_PIXEL 32
# define NB_THREAD 16
# define GREY 0x00E0E0E0
# define GREEN 0x009Fb19F
# define DARK_GREY 0x00333333
# define BLUE 0x000000FF
# define LIGHT_BLUE 0x00ADD8E6
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define COLOR 0x000F0F0F

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;
typedef struct		s_co
{
	double			r;
	double			i;
}					t_co;
typedef struct		s_thread
{
	struct s_var	*var;
	int				x;
	int				x_max;
	int				y;
}					t_thread;
typedef struct		s_var
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_str;
	int				endian;
	int				bpp;
	int				height;
	int				length;
	int				fractale;
	int				previous_fractale;
	int				julia_mode;
	double			julia_c_r;
	double			julia_c_i;
	double			temp;
	double			zoom_x;
	double			zoom_y;
	double			rzoom;
	double			x_centre;
	double			y_centre;
	double			z_iter;
	int				*color_tab;
	int				it_max;
	int				color;
	int				color1;
	int				color2;
	int				red;
	int				green;
	int				blue;
	int				color_mode;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	double			offset_x;
	double			offset_y;
	float			c_frequency;
	int				amplitude;
	int				key;
	double			r_xmouse;
	double			r_ymouse;
	int				l_clic;
	double			previous_x;
	double			previous_y;
	int				rectangle_color;
}					t_var;

int					init_mlx(t_var *var);
void				init_img(t_var *var);
int					expose_hook(t_var *var);
int					error(char *str, t_var *var);
void				draw_img(t_var *var);
void				offsets_init(t_var *var);
void				choose_fractale(t_var *var, t_co *z, t_co *c, t_co *square);
void				mandelbrot_algo(t_co *z, t_co *c, t_co *square);
void				julia_algo(t_co *z, t_co *c, t_co *square);
void				burning_ship_algo(t_co *z, t_co *c, t_co *square);
t_thread			*create_thread_struc(t_var *var);
void				put_pixel(int color, int x, int y, int *img_str);
void				ft_delete_mlx(t_var *var);
void				init_env(t_var *var);
void				init_coord(t_var *var);
void				set_color(t_var *var, int i, t_xy *coord);
int					key_press(int key, t_var *var);
int					mouse_hook(int key, int x, int y, t_var *var);
int					mouse_move(int x, int y, t_var *var);
int					mouse_release(int key, int x, int y, t_var *var);
void				draw_menu(t_var *var);
void				draw_menu_template(t_var *var);
void				create_colortab(t_var *var);
int					key_hook(int key, t_var *var);
void				mouse_hook_2(int key, int x, int y, t_var *var);
void				color_hook_2(int key, t_var *var);
void				key_press_3(int key, t_var *var);
int					clean(t_var *var);
void				clean_exit(char *str, t_var *var);
#endif
