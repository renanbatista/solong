/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:23:43 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/20 16:58:10 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_control *obj)
{
	obj->t_pac = mlx_load_png("./textures/char.png");
	obj->t_coll = mlx_load_png("./textures/collectable.png");
	obj->t_exit = mlx_load_png("./textures/door_1.png");
	obj->t_exit_1 = mlx_load_png("./textures/door_2.png");
	obj->t_back = mlx_load_png("./textures/black.png");
	obj->t_wall = mlx_load_png("./textures/wall.png");
	obj->i_pac = mlx_texture_to_image(obj->mlx, obj->t_pac);
	obj->i_coll = mlx_texture_to_image(obj->mlx, obj->t_coll);
	obj->i_exit = mlx_texture_to_image(obj->mlx, obj->t_exit);
	obj->i_exit_1 = mlx_texture_to_image(obj->mlx, obj->t_exit_1);
	obj->i_back = mlx_texture_to_image(obj->mlx, obj->t_back);
	obj->i_wall = mlx_texture_to_image(obj->mlx, obj->t_wall);
	mlx_resize_image(obj->i_pac, 30, 30);
	mlx_resize_image(obj->i_coll, 30, 30);
	mlx_resize_image(obj->i_back, 30, 30);
	mlx_resize_image(obj->i_exit, 30, 30);
	mlx_resize_image(obj->i_wall, 30, 30);
}

void	make_free_images(t_control *obj)
{
	mlx_delete_image(obj->mlx, obj->i_pac);
	mlx_delete_image(obj->mlx, obj->i_coll);
	mlx_delete_image(obj->mlx, obj->i_exit);
	mlx_delete_image(obj->mlx, obj->i_exit_1);
	mlx_delete_image(obj->mlx, obj->i_back);
	mlx_delete_image(obj->mlx, obj->i_wall);
	mlx_delete_texture(obj->t_pac);
	mlx_delete_texture(obj->t_coll);
	mlx_delete_texture(obj->t_exit);
	mlx_delete_texture(obj->t_exit_1);
	mlx_delete_texture(obj->t_back);
	mlx_delete_texture(obj->t_wall);
	obj->i_pac = NULL;
	obj->i_coll = NULL;
	obj->i_exit = NULL;
	obj->i_exit_1 = NULL;
	obj->i_back = NULL;
	obj->i_wall = NULL;
	obj->t_pac = NULL;
	obj->t_coll = NULL;
	obj->t_exit = NULL;
	obj->t_back = NULL;
	obj->t_wall = NULL;
}
