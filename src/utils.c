/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:43:35 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/18 19:33:46 by r-afonso         ###   ########.fr       */
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

void	print_msg(int type, t_control *obj)
{
	if (type == 1 || type == 2 || type == 3 || type == 4 || type == 5
		|| type == 6 || type == 7)
		ft_printf("\n%s", "ERROR: ");
	if (type == 1)
		ft_printf("\nMap does not exist - %s\n", strerror(errno));
	if (type == 2)
		ft_printf("\nThe map needs to be a rectangle.");
	if (type == 3)
	{
		ft_printf("\nThe map needs to 1 player, at least 1 collectible");
		ft_printf(" and 1 exit.");
	}
	if (type == 4)
		ft_printf("\nThe map needs has at least three lines.");
	if (type == 5)
		ft_printf("\nThe map needs to be closed by walls.");
	if (type == 6)
		ft_printf("Impossible to collect collectibles and finish the game.");
	if (type == 7)
		ft_printf("The map has invalid caracter");
	if (type == 8)
		ft_printf("\nNumbers of Moviment: %i", obj->n_moviments);
}
