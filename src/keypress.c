/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:21:30 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/16 21:56:53 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdbool.h>

static void	validate_moviment_ads(t_control *obj, t_map *map)
{
	if (obj->player_x != 0 && *(map->row + obj->player_x - 1) != '1')
		obj->moviment[0] = 1;
	if (obj->player_x < obj->size_x && *(map->row + obj->player_x + 1) != '1')
		obj->moviment[2] = 1;
	if (map->next)
	{
		map = map->next;
		if (map->next && *(map->row + obj->player_x) != '1')
			obj->moviment[3] = 1;
	}
}

static void	validate_moviment_w(t_control *obj)
{
	int		count;
	t_map	*map;

	map = obj->map;
	count = -1;
	while (count++, count < 4)
		obj->moviment[count] = 0;
	if (obj->player_y == 0)
		obj->moviment[1] = 0;
	else
	{
		count = 0;
		while (count++, count < obj->player_y)
			map = map->next;
		if (*(map->row + obj->player_x) != '1')
			obj->moviment[1] = 1;
	}
	validate_moviment_ads(obj, map->next);
}

static void	rewrite_player(t_control *obj, char type_moviment)
{
	if (type_moviment == 'w')
	{
		obj->i_pac->instances->y -= 30;
		obj->player_y -= 1;
	}
	else if (type_moviment == 'a')
	{
		obj->i_pac->instances->x -= 30;
		obj->player_x -= 1;
	}
	else if (type_moviment == 'd')
	{
		obj->i_pac->instances->x += 30;
		obj->player_x += 1;
	}
	else if (type_moviment == 's')
	{
		obj->i_pac->instances->y += 30;
		obj->player_y += 1;
	}
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_control	*obj;

	obj = (t_control *)param;
	obj->move_t = 0;
	if (mlx_is_key_down(obj->mlx, MLX_KEY_W) || mlx_is_key_down(obj->mlx,
			MLX_KEY_A) || mlx_is_key_down(obj->mlx, MLX_KEY_S)
		|| mlx_is_key_down(obj->mlx, MLX_KEY_D))
	{
		validate_moviment_w(obj);
		if (keydata.key == MLX_KEY_W && *(obj->moviment + 1) && ++obj->move_t)
			rewrite_player(obj, 'w');
		if (keydata.key == MLX_KEY_A && *(obj->moviment + 0) && ++obj->move_t)
			rewrite_player(obj, 'a');
		if (keydata.key == MLX_KEY_D && *(obj->moviment + 2) && ++obj->move_t)
			rewrite_player(obj, 'd');
		if (keydata.key == MLX_KEY_S && *(obj->moviment + 3) && ++obj->move_t)
			rewrite_player(obj, 's');
		validate_collectable(obj);
		validate_exit(obj);
	}
}

void	handle_keypress_esc(void *param)
{
	t_control *obj;

	obj = (t_control *)param;
	if (mlx_is_key_down(obj->mlx, MLX_KEY_ESCAPE))
		handle_close(obj);
}