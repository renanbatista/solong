/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:52:33 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/21 17:04:23 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define MLX_ERROR 1
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# include "../MLX42/include/MLX42/MLX42.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_control
{
	mlx_t			*mlx;
	mlx_image_t		*background_img;
	mlx_image_t		*block_img;
	mlx_image_t		*pac_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*collectable_img;
	char			**map;
	char			**iso_map;
	int32_t			map_col;
	int32_t			map_row;
	int32_t			player_x;
	int32_t			player_y;
	int32_t			window_w;
	int32_t			window_h;
}					t_control;

void				handle_keypress_esc(mlx_key_data_t keydata, void *mlx);
void				load_images(t_control *instance);

#endif
