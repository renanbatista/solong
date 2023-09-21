/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:29:03 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/20 19:03:27 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_collectable(t_control *obj)
{
	int	count;
	int	coll_true;

	count = -1;
	while (++count, count < obj->i_coll->count)
	{
		if ((obj->i_pac->instances->x == obj->i_coll->instances[count].x)
			&& (obj->i_pac->instances->y == obj->i_coll->instances[count].y))
		{
			if (obj->i_coll->instances[count].enabled)
			{
				obj->i_coll->instances[count].enabled = false;
				obj->coll_for_exit--;
			}
		}
	}
}

void	validate_exit(t_control *obj)
{
	if (obj->coll_for_exit == 0)
	{
		if (obj->player_x * 30 == obj->i_exit->instances->x && obj->player_y
			* 30 == obj->i_exit->instances->y)
			handle_close(obj);
	}
}

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

void	validate_moviment_w(t_control *obj)
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
