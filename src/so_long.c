/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:32:36 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/10 23:01:53 by r-afonso         ###   ########.fr       */
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

void	handle_keypress(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_terminate(mlx);
	if(param)
		puts("teste");
}

int32_t	main(void)
{
	mlx_t		*mlx;
	// mlx_image_t	*img;

	mlx = mlx_init(256, 256, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_key_hook(mlx, &handle_keypress, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
