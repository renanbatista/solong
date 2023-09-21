/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:30:23 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/20 17:35:05 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int args_number, char **args)
{
	t_control	*obj;

	obj = ft_calloc(sizeof(t_control), 1);
	if (!obj)
		return (0);
	if (args_number < 2)
	{
		print_msg(9, obj);
		return (0);
	}
	if (!handle_initial_windows(obj, args_number, args))
	{
		free(obj);
		return (0);
	}
	if (!obj->mlx)
		exit(EXIT_FAILURE);
	mlx_loop_hook(obj->mlx, &handle_keypress_or_animation, obj);
	mlx_key_hook(obj->mlx, &handle_keypress, obj);
	mlx_close_hook(obj->mlx, &handle_close, obj);
	mlx_loop(obj->mlx);
	mlx_terminate(obj->mlx);
	free(obj);
	obj = NULL;
	return (0);
}
