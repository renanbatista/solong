/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:43:35 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/17 02:32:35 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		*(p) = c;
		p++;
		n--;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocate;

	if ((size * nmemb != 0) && (nmemb * size) / size != nmemb)
		return (NULL);
	allocate = malloc(nmemb * size);
	if (allocate != NULL)
		ft_memset(allocate, 0, nmemb * size);
	return (allocate);
}

void	add_new_node_to_last(t_control *obj, char *str)
{
	// TODO: TEM LEAK
	t_map	*new_map;
	t_map	*actual;

	actual = obj->map;
	new_map = ft_calloc(sizeof(t_map), 1);
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

void	handle_close(void *param)
{
	t_control	*obj;
	t_map		*map;
	t_map		*swap_map;

	obj = (t_control *)param;
	map = obj->map;
	make_free_images(obj);
	mlx_close_window(obj->mlx);
	while (map->row)
	{
		free(map->row);
		if (map->next)
		{
			swap_map = map->next;
			free(map);
			map = swap_map;
		}
		else
		{
			free(map);
			break ;
		}
	}
	obj->map = NULL;
}

char	*join_str(char *str, char *str2)
{
	char	*str_new;
	int		count;
	int		count2;

	count = -1;
	count2 = -1;
	str_new = ft_calloc(ft_strlen(str), ft_strlen(str2));
	if (!str_new)
		return (0);
	while (++count, str[count])
		str_new[count] = str[count];
	while (++count2, str2[count2])
		str_new[count++] = str2[count2];
	return (str_new);
}
