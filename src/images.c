/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:23:43 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/22 14:06:27 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_control *obj)
{
	obj->img_background = mlx_texture_to_image(obj->mlx,
												mlx_load_png("./sprites/tile_040.png"));
	obj->img_pac = mlx_texture_to_image(obj->mlx,
										mlx_load_png("./maps/pac_1.png"));
	obj->img_block = mlx_texture_to_image(obj->mlx,
											mlx_load_png("./maps/block.png"));
	obj->img_collectable = mlx_texture_to_image(obj->mlx,
												mlx_load_png("./maps/collectable.png"));
	if (!obj->img_background || !obj->img_pac || !obj->img_block
		|| !obj->img_collectable)
		return (0);
	mlx_resize_image(obj->img_background, 64, 64);
	mlx_resize_image(obj->img_pac, 64, 64);
	mlx_resize_image(obj->img_block, 64, 64);
	mlx_resize_image(obj->img_collectable, 64, 64);
}

void	change_image(t_control *obj, char *type, char *path_image)
{
	if (type == 'back')
	{
		mlx_delete_image(obj->mlx, obj->img_background);
		obj->img_background = mlx_texture_to_image(obj->mlx,
													mlx_load_png(path_image));
	}
	if (type == 'pac')
	{
		mlx_delete_image(obj->mlx, obj->img_pac);
		obj->img_pac = mlx_texture_to_image(obj->mlx,
											mlx_load_png(path_image));
	}
	if (type == 'block')
	{
		mlx_delete_image(obj->mlx, obj->img_block);
		obj->img_block = mlx_texture_to_image(obj->mlx,
												mlx_load_png(path_image));
	}
	if (type == 'collectable')
	{
		mlx_delete_image(obj->mlx, obj->img_collectable);
		obj->img_collectable = mlx_texture_to_image(obj->mlx,
													mlx_load_png(path_image));
	}
}
