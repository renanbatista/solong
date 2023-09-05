/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:00:01 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/05 15:27:47 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	add_new_node_to_last(t_map *first_node, char *str)
{
	t_map	*obj;

	obj = ft_calloc(sizeof(t_map), 1);
	// if (!obj)
	// trato para caso de falhar ao alocar
	obj->row = str;
	free(str);
	obj->next = NULL;
	while (first_node->next)
		first_node = first_node->next;
	first_node->next = obj;
}
