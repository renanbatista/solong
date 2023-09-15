/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:21:30 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/14 14:24:01 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void validate_moviment_ads(t_control *obj, t_map *map)
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

static void	rewrite_player(t_control *obj)
{
	mlx_image_to_window(obj->mlx, obj->img_pac, obj->load_map_x,
	obj->load_map_y);
	if ( obj->load_map_x > 0 )
		obj->player_x = obj->load_map_x / 30;
	if ( obj->load_map_y > 0 )
		obj->player_y = obj->load_map_y / 30;
	return;
}

void	handle_keypress(void *t_c)
{
	t_control	*obj;

	obj = (t_control *)t_c;
	validate_moviment_w(obj);
	obj->moviment_true = 0;
	if (mlx_is_key_down(obj->mlx, MLX_KEY_ESCAPE))
	{
		// TODO: fazer o tratamento para free nas demais variveis
		mlx_terminate((mlx_t *)obj->mlx);
	}
	else if (mlx_is_key_down(obj->mlx, MLX_KEY_W && *(obj->moviment + 1)) && ++obj->moviment_true)
		obj->img_pac->instances[0].y += 1;
	else if (mlx_is_key_down(obj->mlx, MLX_KEY_A && *(obj->moviment + 0)) && ++obj->moviment_true)
		obj->img_pac->instances[0].x -= 1;
	else if (mlx_is_key_down(obj->mlx, MLX_KEY_D && *(obj->moviment + 2)) && ++obj->moviment_true)
		obj->img_pac->instances[0].x += 1;
	else if (mlx_is_key_down(obj->mlx, MLX_KEY_S && *(obj->moviment + 3)) && ++obj->moviment_true)
		obj->img_pac->instances[0].y -= 1;
	rewrite_player(obj);
}
