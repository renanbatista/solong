/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_validate_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:07:12 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/18 01:45:01 by r-afonso         ###   ########.fr       */
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
			obj->v_retangle++;
		if (map->next)
			map = map->next;
		else
		{
			if (count == ft_strlen(map->row) + 1)
				obj->v_retangle--;
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

	map = obj->map;
	count = 0;
	while (true)
	{
		if (!count)
			count = ft_strlen(map->row);
		if (count != ft_strlen(map->row))
			obj->v_retangle++;
		if (map->next)
			map = map->next;
		else
		{
			if (count == ft_strlen(map->row) + 1)
				obj->v_retangle--;
			break ;
		}
	}
	if (!obj->v_retangle)
		return (1);
	print_msg(2, obj);
	return (0);
}

int	handle_validate_map(t_control *obj)
{
	if (!validate_components(obj) || !validate_retangle(obj))
		return (0);
	
	// TODO: Mapa precisa ser cercado por parede.
	// TODO: preciso tratar quando tenho outras letras dentro do mapa, nesse caso também é invalido.
	// TODO: validar se mapa pode ser vencido 
	return (1);
}
