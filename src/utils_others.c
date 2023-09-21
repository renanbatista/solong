/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:43:35 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/21 12:21:11 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	sun;

	sun = 0;
	signal = 1;
	while ((*(nptr) >= 9 && *(nptr) <= 13) || *(nptr) == 32)
		nptr++;
	if (*(nptr) == '+' || *(nptr) == '-')
	{
		if (*(nptr) == '-')
			signal *= -1;
		nptr++;
		if (*(nptr) < 48 && *(nptr) > 57)
			return (0);
	}
	while (*(nptr) >= 48 && *(nptr) <= 57)
	{
		sun = (sun * 10) + *(nptr) - 48;
		nptr++;
	}
	return (sun * signal);
}

void	print_black(t_map *map, t_control *obj, int count)
{
	if (map->row[count] != '\n')
		mlx_image_to_window(obj->mlx, obj->i_back, obj->lm_x, obj->lm_y);
}

void	get_gnl(char *str, int fd, t_control *obj)
{
	while (true)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		obj->size_y++;
		obj->size_x = ft_strlen(str);
		add_new_node_to_last(obj, str);
	}
}
