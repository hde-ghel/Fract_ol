/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:22:22 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/25 16:37:05 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	rectangle(t_xy *start, int size_x, int size_y, t_var *var)
{
	int		tmp;
	int		max_x;
	int		max_y;

	tmp = start->x;
	max_x = start->x + size_x;
	max_y = start->y + size_y;
	while (start->y < max_y)
	{
		start->x = tmp;
		while (start->x < max_x)
		{
			mlx_pixel_put(var->mlx_ptr, var->win_ptr, start->x, start->y,
					var->rectangle_color);
			start->x++;
		}
		start->y++;
	}
}

void	draw_menu_template(t_var *var)
{
	void	*tmp;

	tmp = var->win_ptr;
	rectangle(&(t_xy) {300, 800}, 900, 100, var);
	mlx_string_put(var->mlx_ptr, tmp, 10, 20, LIGHT_BLUE, "Controls :");
	mlx_string_put(var->mlx_ptr, tmp, 30, 60, LIGHT_BLUE,
			"iterations : pg_up pg_down");
	mlx_string_put(var->mlx_ptr, tmp, 30, 90, LIGHT_BLUE, "move: mouse | wasd");
	mlx_string_put(var->mlx_ptr, tmp, 30, 120, LIGHT_BLUE, "zoom : mouse | +-");
	mlx_string_put(var->mlx_ptr, tmp, 30, 150, LIGHT_BLUE, "zoom : mouse | +-");
	mlx_string_put(var->mlx_ptr, tmp, 30, 180, LIGHT_BLUE, "color_mode : c");
	mlx_string_put(var->mlx_ptr, tmp, 30, 210, LIGHT_BLUE, "color : efv/ rgb");
	mlx_string_put(var->mlx_ptr, tmp, 30, 240, LIGHT_BLUE, "julia mode : j ");
	mlx_string_put(var->mlx_ptr, tmp, 30, 270, LIGHT_BLUE, "c_amplitude : k l");
	mlx_string_put(var->mlx_ptr, tmp, 30, 300, LIGHT_BLUE, "C_frequency : m n");
	mlx_string_put(var->mlx_ptr, tmp, 400, 820, LIGHT_BLUE, "      zoom :");
	mlx_string_put(var->mlx_ptr, tmp, 400, 840, LIGHT_BLUE, "iterations :");
	mlx_string_put(var->mlx_ptr, tmp, 800, 820, LIGHT_BLUE, "mouse x :");
	mlx_string_put(var->mlx_ptr, tmp, 800, 840, LIGHT_BLUE, "mouse y :");
}

void	replace_button(t_var *var)
{
	var->rectangle_color = (var->fractale == 0) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {15, 445}, 130, 30, var);
	var->rectangle_color = (var->fractale == 1) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {155, 445}, 130, 30, var);
	var->rectangle_color = (var->fractale == 2) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {15, 485}, 130, 30, var);
	var->rectangle_color = (var->fractale == 3) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {155, 485}, 130, 30, var);
	var->rectangle_color = (var->fractale == 4) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {15, 525}, 130, 30, var);
	var->rectangle_color = (var->fractale == 5) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {155, 525}, 130, 30, var);
	var->rectangle_color = (var->fractale == 6) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {15, 565}, 130, 30, var);
	var->rectangle_color = (var->fractale == 7) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {155, 565}, 130, 30, var);
	var->rectangle_color = (var->fractale == 8) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {15, 605}, 130, 30, var);
	var->rectangle_color = (var->fractale == 9) ? GREEN : LIGHT_BLUE;
	rectangle(&(t_xy) {155, 605}, 130, 30, var);
}

void	menu_fractale(t_var *var)
{
	void	*tmp;

	tmp = var->win_ptr;
	if (var->fractale != var->previous_fractale)
	{
		var->previous_fractale = var->fractale;
		replace_button(var);
		mlx_string_put(var->mlx_ptr, tmp, 10, 410, LIGHT_BLUE, "Fractales :");
		mlx_string_put(var->mlx_ptr, tmp, 20, 450, DARK_GREY, "0.Mandelbrot");
		mlx_string_put(var->mlx_ptr, tmp, 160, 450, DARK_GREY, "1.Julia");
		mlx_string_put(var->mlx_ptr, tmp, 20, 490, DARK_GREY, "2.Tri-julia");
		mlx_string_put(var->mlx_ptr, tmp, 160, 490, DARK_GREY, "3.Quad-julia");
		mlx_string_put(var->mlx_ptr, tmp, 20, 530, DARK_GREY, "4.Burning S");
		mlx_string_put(var->mlx_ptr, tmp, 160, 530, DARK_GREY, "5.Tricorn");
		mlx_string_put(var->mlx_ptr, tmp, 20, 570, DARK_GREY, "6.Quadcorn");
		mlx_string_put(var->mlx_ptr, tmp, 160, 570, DARK_GREY, "7.Tribrot");
		mlx_string_put(var->mlx_ptr, tmp, 20, 610, DARK_GREY, "8.Excalibur");
		mlx_string_put(var->mlx_ptr, tmp, 160, 610, DARK_GREY, "9.Buffalo");
	}
}

void	draw_menu(t_var *var)
{
	char	*value;

	var->rectangle_color = BLACK;
	rectangle(&(t_xy) {530, 840}, 50, 20, var);
	rectangle(&(t_xy) {530, 820}, 200, 20, var);
	rectangle(&(t_xy) {900, 820}, 50, 20, var);
	rectangle(&(t_xy) {900, 840}, 50, 20, var);
	value = ft_itoa(var->it_max);
	mlx_string_put(var->mlx_ptr, var->win_ptr, 530, 840, 0x000000FF, value);
	ft_strdel(&value);
	value = ft_itoa(var->rzoom);
	mlx_string_put(var->mlx_ptr, var->win_ptr, 530, 820, 0x000000FF, value);
	ft_strdel(&value);
	value = ft_itoa(var->previous_x);
	mlx_string_put(var->mlx_ptr, var->win_ptr, 900, 820, 0x000000FF, value);
	ft_strdel(&value);
	value = ft_itoa(var->previous_y);
	mlx_string_put(var->mlx_ptr, var->win_ptr, 900, 840, 0x000000FF, value);
	ft_strdel(&value);
	menu_fractale(var);
}
