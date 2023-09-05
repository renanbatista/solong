/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:52:33 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/05 18:07:59 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	mlx_t			*mlx;
	mlx_image_t		*img_background;
	mlx_image_t		*img_block;
	mlx_image_t		*img_pac;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_collectable;
	char			**map;
	int				size_col;
	int				size_row;
	int				player_x;
	int				player_y;
	int				window_w;
	int				window_h;
}					t_control;

typedef struct s_map
{
	char			*row;
	struct s_map	*next;
}					t_map;

void				handle_keypress_esc(mlx_key_data_t keydata, void *mlx);
int				load_images(t_control *obj);
int					ft_strcmp(const char *str1, const char *str2);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
int					handle_initial_windows(t_control *obj, t_map *map,
						int args_number, char **args);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
void				add_new_node_to_last(t_map *first_node, char *str);
void				handle_initial_exit(t_control obj, t_map *map);

#endif
