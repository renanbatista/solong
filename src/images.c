/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:23:43 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/11 01:36:50 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_images(t_control *obj)
{
	obj->img_pac = mlx_texture_to_image(obj->mlx,
			mlx_load_png("./textures/pac/pac_1.png"));
	obj->img_collectable = mlx_texture_to_image(obj->mlx,
			mlx_load_png("./textures/maps/collectable.png"));
	obj->img_exit = mlx_texture_to_image(obj->mlx,
			mlx_load_png("./textures/maps/door.png"));
	obj->img_background = mlx_texture_to_image(obj->mlx,
			mlx_load_png("./textures/maps/black.png"));
	obj->img_wall = mlx_texture_to_image(obj->mlx,
			mlx_load_png("./textures/maps/wall.png"));
	if (!obj->img_background || !obj->img_pac || !obj->img_collectable || !obj->img_exit || !obj->img_wall)
		return 0;
	// mlx_resize_image(obj->img_background, 30, 30);
	mlx_resize_image(obj->img_pac, 30, 30);
	mlx_resize_image(obj->img_collectable, 15, 15);
	mlx_resize_image(obj->img_background, 30, 30);
	mlx_resize_image(obj->img_exit, 30, 30);
	mlx_resize_image(obj->img_wall, 30, 30);
	return (1);
}

void	change_image(t_control *obj, char *type, char *path_image)
{
	if (ft_strcmp("backgroud", type))
	{
		mlx_delete_image(obj->mlx, obj->img_background);
		obj->img_background = mlx_texture_to_image(obj->mlx,
				mlx_load_png(path_image));
	}
	else if (ft_strcmp("pac", type))
	{
		mlx_delete_image(obj->mlx, obj->img_pac);
		obj->img_pac = mlx_texture_to_image(obj->mlx, mlx_load_png(path_image));
	}
	else if (ft_strcmp("collectable", type))
	{
		mlx_delete_image(obj->mlx, obj->img_collectable);
		obj->img_collectable = mlx_texture_to_image(obj->mlx,
				mlx_load_png(path_image));
	}
}
