/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:48:25 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/29 20:28:07 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	handle_initial_windows(t_control obj, int args_number, char **args)
{
	// 0- Validar mapa
	
	// 1- Carregar janela
	if (args_number >=3)
	{
		obj.window_w = atoi(*(args + 2));
		obj.window_h = atoi(*(args + 3));
		printf("\nwidth = %i", obj.window_w);
		printf("\nheight = %i", obj.window_h);
		// obj.mlx = mlx_init(1024, 768, "Pac-Man", true);
		getchar();
	}
	// 2- Ler e carregar mapa

	// 3- Carregar coletaveis

	// 4- Carregar PAC
	return (1);
}

char	*load_map(char *map_name)
{
	int	fd;
	char *str;

	str = ft_strjoin("./maps/", map_name);
	fd = open(str, O_RDONLY);
	free(str);
	if (fd == -1)
	{
		//mapa invalido
	}
	while(true)
	{
		str = get_next_line(fd);
		
	}
	
	printf("%i", fd);
	return NULL;
}
