/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:41:42 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/25 16:37:57 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		error(char *str, t_var *var)
{
	clean(var);
	ft_putstr(str);
	return (-1);
}

void	init_env(t_var *var)
{
	var->color = 0x000EE0E0;
	var->red = 128;
	var->green = 128;
	var->blue = 128;
	var->color_mode = 1;
	var->c_frequency = 0;
	var->amplitude = 0;
	var->rzoom = 1;
	var->offset_x = 0;
	var->offset_y = 0;
	var->x_centre = 0;
	var->y_centre = 0;
	var->l_clic = 0;
	var->julia_mode = 0;
	var->julia_c_r = 0;
	var->julia_c_i = 0;
	var->previous_fractale = -1;
	create_colortab(var);
	init_coord(var);
}

int		check_arg(char *av, t_var *var)
{
	if (ft_strcmp(av, "Mandelbrot") == 0)
		var->fractale = 0;
	else if (strcmp(av, "Julia") == 0)
		var->fractale = 1;
	else if (strcmp(av, "Tri-julia") == 0)
		var->fractale = 2;
	else if (strcmp(av, "Quad-julia") == 0)
		var->fractale = 3;
	else if (strcmp(av, "Burning-ship") == 0)
		var->fractale = 4;
	else if (strcmp(av, "Tricorn") == 0)
		var->fractale = 5;
	else if (strcmp(av, "Quadcorn") == 0)
		var->fractale = 6;
	else if (strcmp(av, "Tribrot") == 0)
		var->fractale = 7;
	else if (strcmp(av, "Excalibur") == 0)
		var->fractale = 8;
	else if (strcmp(av, "Buffalo") == 0)
		var->fractale = 9;
	else
		return (-1);
	return (0);
}

char	*print_usage(void)
{
	char	*str;

	str = "Usage : ./fractol \"fractale_name\"\nlist:\n\nMandelbrot\nJulia\
			\nTri-julia\nQuad-julia\nBurning-ship\nTricorn\nQuadcorn\
			\nTribrot\nExcalibur\nBuffalo\n";
	return (str);
}

int		main(int ac, char **av)
{
	t_var	*var;

	if (ac != 2)
	{
		ft_putstr(print_usage());
		return (-1);
	}
	if (!(var = (t_var *)malloc(sizeof(t_var))))
		return (error("malloc error", var));
	ft_bzero(var, sizeof(t_var *));
	if (!(var->color_tab = (int *)malloc(sizeof(int) * 501)))
		return (error("malloc error", var));
	if (check_arg(av[1], var) == -1)
		return (error(print_usage(), var));
	init_env(var);
	if (init_mlx(var) == -1)
		return (-1);
	mlx_hook(var->win_ptr, BUTTONPRESS, KPMASK, mouse_hook, var);
	mlx_hook(var->win_ptr, BUTTONRELEASE, KPMASK, mouse_release, var);
	mlx_hook(var->win_ptr, MOTIONNOTIFY, BUTTONMOTIONMASK, mouse_move, var);
	mlx_hook(var->win_ptr, 2, 0, key_press, var);
	mlx_mouse_hook(var->win_ptr, mouse_hook, var);
	mlx_expose_hook(var->win_ptr, expose_hook, var);
	mlx_loop(var->mlx_ptr);
	return (0);
}
