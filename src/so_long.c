/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:32:36 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/17 21:56:23 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// static void	ft_error(void)
// {
// 	exit(EXIT_FAILURE);
// }

// static void	ft_hook(void *param)
// {
// 	const mlx_t	*mlx;

// 	mlx = param;
// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }
#include <string.h>

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(512, 512, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_key_hook(mlx, &handle_keypress_esc, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
