/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:21:30 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/19 11:26:51 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdbool.h>

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
	obj->n_moviments++;
	print_msg(8, obj);
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

void	handle_close(void *param)
{
	t_control	*obj;
	t_map		*map;
	t_map		*swap_map;

	obj = (t_control *)param;
	map = obj->map;
	if(!obj->fail_map_validate)
	{
		make_free_images(obj);
		mlx_close_window(obj->mlx);	
	}
	while (map->row)
	{
		free(map->row);
		if (!map->next)
		{
			free(map);
			break ;
		}
		swap_map = map->next;
		free(map);
		map = swap_map;
	}
	free_array(obj);
	obj->map = NULL;
}

void	handle_keypress_esc(void *param)
{
	t_control *obj;

	obj = (t_control *)param;
	if (mlx_is_key_down(obj->mlx, MLX_KEY_ESCAPE))
		handle_close(obj);
}