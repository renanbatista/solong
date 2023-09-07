/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:32:36 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/06 21:11:57 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int args_number, char **args)
{
	t_control	obj;
	t_map		*map;

	map = ft_calloc(sizeof(t_map), 1);
	if(!handle_initial_windows(&obj, map, args_number, args))
		handle_initial_exit(obj, map); // Trato retorno se alocar com erro na inicialização
	if (!obj.mlx)
		exit(EXIT_FAILURE);
	mlx_image_to_window(obj.mlx, obj.img_background, 0, 0);
	mlx_key_hook(obj.mlx, &handle_keypress, obj.mlx);
	mlx_loop(obj.mlx);
	mlx_terminate(obj.mlx);
	return (0);
}
