/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:00:01 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/10 23:38:31 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	add_new_node_to_last(t_control *obj	, char *str)
{
	t_map	*new_map;
	t_map	*actual;

	actual = obj->map;
	new_map = ft_calloc(sizeof(t_map), 1);
	// if (!map)
	// trato para caso de falhar ao alocar
	new_map->row = str;
	new_map->next = NULL;
	if (actual)
	{
		while (actual->next)
			actual = actual->next;
		actual->next = new_map;
	}
	else 
		obj->map = new_map;
}
