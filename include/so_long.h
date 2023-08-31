/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:52:33 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/31 13:52:33 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define MLX_ERROR 1
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_control
{
	mlx_t		*mlx;
	mlx_image_t	*img_background;
	mlx_image_t	*img_block;
	mlx_image_t	*img_pac;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collectable;
	char		**map;
	int			map_col;
	int			map_row;
	int			player_x;
	int			player_y;
	int			window_w;
	int			window_h;
}				t_control;

void			handle_keypress_esc(mlx_key_data_t keydata, void *mlx);
void			load_images(t_control *obj);
int				ft_strcmp(const char *str1, const char *str2);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
int				handle_initial_windows(t_control *obj, int args_number,
					char **args);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);

#endif
