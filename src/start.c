/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:32:36 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/22 19:25:58 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	t_control	instance;

	load_images(instance.mlx);
	instance.mlx = mlx_init(1024, 768, "Pac-Man", true);
	if (!instance.mlx)
		exit(EXIT_FAILURE);
	mlx_image_to_window(instance.mlx, instance.img_background, 0, 0);
	mlx_key_hook(instance.mlx, &handle_keypress_esc, instance.mlx);
	mlx_loop(instance.mlx);
	mlx_terminate(instance.mlx);
	return (0);
}
