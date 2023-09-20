/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_validate_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:07:12 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/19 22:36:41 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	validate_components(t_control *obj)
{
	t_map	*map;
	int		count;

	map = obj->map;
	while (true)
	{
		count = -1;
		while (++count, *(map->row + count))
		{
			if (*(map->row + count) == 'P')
				obj->v_player++;
			if (*(map->row + count) == 'C')
				obj->v_collect++;
			if (*(map->row + count) == 'E')
				obj->v_exit++;
		}
		if (map->next)
			map = map->next;
		else
			break ;
	}
	if (obj->v_player == 1 && obj->v_collect >= 1 && obj->v_exit == 1)
		return (1);
	print_msg(3, obj);
	return (0);
}

static int	validate_retangle(t_control *obj)
{
	t_map	*map;
	int		count;

	map = obj->map;
	count = 0;
	while (true)
	{
		if (!count)
			count = ft_strlen(map->row);
		if (count != ft_strlen(map->row))
			obj->v_retangle = 1;
		if (map->next)
			map = map->next;
		else
		{
			if (count == ft_strlen(map->row) + 1)
				obj->v_retangle = 0;
			break ;
		}
	}
	if (!obj->v_retangle)
		return (1);
	print_msg(2, obj);
	return (0);
}

static int	validate_closed_wall(t_control *obj)
{
	t_map	*map;
	int		count;
	int		count_lines;

	map = obj->map;
	count_lines = 0;
	while (++count_lines, count_lines <= obj->size_y)
	{
		count = -1;
		if (count_lines == 1 || count_lines == obj->size_y)
			while (++count, count < obj->size_x)
				if (*(map->row + count) != '1')
					obj->v_wall = 1;
		if (*(map->row) != '1' || *(map->row + obj->size_x - 1) != '1')
			obj->v_wall = 1;
		map = map->next;
	}
	if (obj->v_wall == 1)
	{
		print_msg(5, obj);
		return (0);
	}
	return (1);
}

static int	validate_set(t_control *obj)
{
	int		count;
	t_map	*map;

	map = obj->map;
	while (map)
	{
		count = -1;
		while (++count, count < obj->size_x)
		{
			if (*(map->row + count) != '1' && *(map->row + count) != 'C'
				&& *(map->row + count) != 'E' && *(map->row + count) != 'P'
				&& *(map->row + count) != '0')
			{
				print_msg(7, obj);
				return (0);
			}
		}
		map = map->next;
	}
	return (1);
}

int	handle_validate_map(t_control *obj)
{
	if (obj->size_y < 3)
		print_msg(4, obj);
	if (obj->size_y < 3 || !validate_components(obj) || !validate_retangle(obj)
		|| !validate_closed_wall(obj) || !validate_set(obj))
		return (0);
	handle_ff(obj, obj->array, obj->player_x, obj->player_y);
	if (!validate_map_ff(obj))
	{
		print_msg(9, obj);
		return (0);
	}
	return (1);
}
