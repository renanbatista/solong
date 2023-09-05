/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_initial_windows.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:48:25 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/05 18:09:57 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdint.h>

static int	load_map(t_control *obj, t_map *map, char *map_name)
{
	int		fd;
	int		fail;
	char	*str;
	int		count;

	fail = 1;
	str = ft_strjoin("./maps/", map_name);
	if (!str)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	count = 0;
	free(str);
	while (true)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		add_new_node_to_last(map, str);
	}
	return (1);
}

int	handle_initial_windows(t_control *obj, t_map *map, int args_number,
		char **args)
{
	// 0- Carregar mapa - OK
	if (!load_map(obj, map, *(args + 1)))
		return (0);
	// 1- Validar mapa
	// 2- Carregar janela - OK
	if (args_number >= 3)
	{
		obj->window_w = atoi(*(args + 2));
		obj->window_h = atoi(*(args + 3));
		obj->mlx = mlx_init(obj->window_w, obj->window_h, "Pac-Man", false);
	}
	// 3- Carregar sprites
	if(!load_images(obj))
		return (0);
	// 3- Carregar muro

	// 4- Carregar coletaveis
	
	// 5- Carregar PAC
	return (1);
}
