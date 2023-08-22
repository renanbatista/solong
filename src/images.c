/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:23:43 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/21 21:37:08 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_control *obj)
{
	obj->background_img = mlx_texture_to_image(obj->mlx,
												mlx_load_png("./sprites/tile_040.png"));
	obj->pac_img = mlx_texture_to_image(obj->mlx,
										mlx_load_png("./maps/pac_1.png"));
	obj->block_img = mlx_texture_to_image(obj->mlx,
											mlx_load_png("./maps/block.png"));
	obj->collectable_img = mlx_texture_to_image(obj->mlx,
												mlx_load_png("./maps/collectable.png"));
	if (!obj->background_img || !obj->pac_img || !obj->exit_img
		|| !obj->block_img || !obj->collectable_img)
		return (0);
	mlx_resize_image(obj->background_img, 64, 64);
	mlx_resize_image(obj->pac_img, 64, 64);
	mlx_resize_image(obj->exit_img, 64, 64);
	mlx_resize_image(obj->block_img, 64, 64);
	mlx_resize_image(obj->collectable_img, 64, 64);
}

void	change_image(t_control *obj, char *type, char *path_image)
{
	if (type == 'back')
	{
		mlx_delete_image(obj->mlx, obj->background_img);
		obj->background_img = mlx_texture_to_image(obj->mlx,
													mlx_load_png(path_image));
	}
	if (type == 'pac')
	{
		mlx_delete_image(obj->mlx, obj->pac_img);
		obj->pac_img = mlx_texture_to_image(obj->mlx,
											mlx_load_png(path_image));
	}
	if (type == 'block')
	{
		mlx_delete_image(obj->mlx, obj->block_img);
		obj->block_img = mlx_texture_to_image(obj->mlx,
												mlx_load_png(path_image));
	}
	if (type == 'collectable')
	{
		mlx_delete_image(obj->mlx, obj->collectable_img);
		obj->collectable_img = mlx_texture_to_image(obj->mlx,
													mlx_load_png(path_image));
	}
}
