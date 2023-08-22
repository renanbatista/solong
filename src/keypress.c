/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:21:30 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/21 17:14:53 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_keypress_esc(mlx_key_data_t keydata, void *mlx)
{
	// printf("Action: %u e %u ",keydata.action, MLX_PRESS);
	printf("\nKey: %u", keydata.key);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate((mlx_t *)mlx);
		printf("%s", "ola");
	}
}
