/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:42:24 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/05/24 21:27:23 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	ft_delete_mlx(t_var *var)
{
	mlx_hook(var->win_ptr, BUTTONPRESS, KPMASK, NULL, NULL);
	mlx_hook(var->win_ptr, BUTTONRELEASE, KPMASK, NULL, NULL);
	mlx_hook(var->win_ptr, MOTIONNOTIFY, BUTTONMOTIONMASK, NULL, NULL);
	mlx_hook(var->win_ptr, 2, 0, NULL, NULL);
	mlx_mouse_hook(var->win_ptr, NULL, NULL);
	if (var->img_ptr != NULL)
	{
		mlx_destroy_image(var->mlx_ptr, var->img_ptr);
		var->img_ptr = NULL;
	}
	if (var->win_ptr != NULL)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		var->win_ptr = NULL;
	}
	if (var->mlx_ptr != NULL)
		ft_memdel((void **)&var->mlx_ptr);
}

int		init_mlx(t_var *var)
{
	init_img(var);
	if ((var->mlx_ptr = mlx_init()) == NULL)
		return (error("malloc error", var));
	if ((var->win_ptr = mlx_new_window(var->mlx_ptr, LENGTH, HEIGHT, "Fractol"))
			== NULL)
		return (error("malloc error", var));
	if ((var->img_ptr = mlx_new_image(var->mlx_ptr, I_LENGTH, I_HEIGHT))
			== NULL)
		return (error("malloc error", var));
	var->img_str = (int *)mlx_get_data_addr(var->img_ptr, &var->bpp
	, &var->length, &var->endian);
	draw_menu_template(var);
	return (0);
}

int		expose_hook(t_var *var)
{
	draw_img(var);
	if (!(mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr,
					LENGTH - I_LENGTH, 0)))
		return (error("put image to windows error", var));
	return (0);
}
