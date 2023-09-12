/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:21:30 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/11 21:18:22 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	validate_moviment(t_control *obj)
{
	int		count;
	t_map	*map;

	map = obj->map;
	count = -1;
	while (count++, count < 4)
		obj->moviment[count] = 0;
	// W
	if (obj->player_y == 0)
		obj->moviment[1] = 0;
	else
	{
		count = 1;
		while (count++, count < obj->player_y / 30)
			map = map->next;
		if (*(map->row + obj->player_x) != '1')
			obj->moviment[1] = 1;
	}
	// A
	if (obj->player_x == 0)
		obj->moviment[0] = 0;
	else
		if (*(map->row + obj->player_x - 1) != '1')
			obj->moviment[0] = 1;	
	// D
	if (obj->player_x >= obj->size_x)
		obj->moviment[2] = 0;
	else
		if (*(map->row + obj->player_x + 1) != '1')
			obj->moviment[2] = 1;
	// S
	if(!map->next)
		obj->moviment[3] = 0;
	else
		if (*(map->row + obj->player_x) != '1')
			obj->moviment[3] = 1;
}

static int	move_key_w(t_control *obj)
{
	validate_moviment(obj);
	return (1);
}

static int	move_key_s(t_control *obj)
{
	validate_moviment(obj);
	return (1);
}

static int	move_key_a(t_control *obj)
{
	return (1);
}

static int	move_key_d(t_control *obj)
{
	return (1);
}
void	handle_keypress(void *t_c)
{
	t_control	*obj;

	obj = (t_control *)t_c;
	if (mlx_is_key_down(obj->mlx, MLX_KEY_ESCAPE))
	{
		// TODO: fazer o tratamento para free nas demais variveis
		mlx_terminate((mlx_t *)obj->mlx);
	}
	else if (mlx_is_key_down(obj->mlx, key
								: MLX_KEY_W))
		move_key_w(obj);
	else if (mlx_is_key_down(obj->mlx, key
								: MLX_KEY_S))
		move_key_s(obj);
	else if (mlx_is_key_down(obj->mlx, key
								: MLX_KEY_A))
		move_key_a(obj);
	else if (mlx_is_key_down(obj->mlx, key
								: MLX_KEY_D))
		move_key_d(obj);
}
