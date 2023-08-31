/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:48:25 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/30 21:00:20 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdint.h>

static int	load_map(t_control *obj, char *map_name)
{
	int		fd;
	char	*str;

	str = ft_strjoin("./maps/", map_name);
	fd = open(str, O_RDONLY);
	free(str);
	if (fd == -1)
		return (0);
	while (true)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
	}
	printf("%i", fd);
	return (0);
}

int	handle_initial_windows(t_control *obj, int args_number, char **args)
{
	// 0- Carregar mapa
	if (load_map(obj, *(args + 1)))
		return (0);
	// 1- Validar mapa
	// 2- Carregar janela
	if (args_number >= 3)
	{
		obj->window_w = atoi(*(args + 2));
		obj->window_h = atoi(*(args + 3));
		obj->mlx = mlx_init(obj->window_w, obj->window_h, "Pac-Man", false);
	}
	// 3- Carregar coletaveis
	// 4- Carregar PAC
	return (1);
}
