#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_ERROR 1
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# include "get_next_line.h"
# include "ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct 		s_map
{
	char			*row;
	struct s_map	*next;
}					t_map;

typedef struct 		s_control
{
	mlx_t			*mlx;
	t_map			*map;
	int				moviment[4];
	mlx_image_t		*img_background;
	mlx_image_t		*img_pac;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_collectable;
	mlx_image_t		*img_wall;
	int				load_map_x; // só usada INICIALMENTE 
	int				load_map_y; // só usada INICIALMENTE 
	int				size_x; // tamanho total do das strings na lista
	int				size_y; // numero de listas
	int				player_x; // posição na string atual do player
	int				player_y; // lista atual do player
	int				window_w;
	int				window_h;
	int				moviment_true;

}					t_control;

void				handle_keypress(void *obj);
int					load_images(t_control *obj);
int					ft_strcmp(const char *str1, const char *str2);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
int					handle_initial_windows(t_control *obj, int args_number,
						char **args);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
void				add_new_node_to_last(t_control *obj, char *str);
void				handle_close_map(t_control *obj);

#endif
