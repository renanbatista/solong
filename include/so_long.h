/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:52:33 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/22 14:05:56 by r-afonso         ###   ########.fr       */
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
	mlx_image_t		*img_background;
	mlx_image_t		*img_block;
	mlx_image_t		*img_pac;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_collectable;
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
