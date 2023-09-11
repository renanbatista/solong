#include "../include/so_long.h"
#include <stdint.h>

static void	init_variables(t_control *obj)
{
	obj->load_map_x = 0;
	obj->load_map_y = 0;
	obj->size_col = 0;
	obj->size_row = 0;
	obj->player_x = 0;
	obj->player_y = 0;
	obj->window_w = 0;
	obj->window_h = 0;
}
static int	load_map(t_control *obj, char *map_name)
{
	int		fd;
	char	*str;

	str = ft_strjoin("./maps/", map_name);
	if (!str)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	free(str);
	while (true)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		obj->size_row++;
		obj->size_col = ft_strlen(str);
		add_new_node_to_last(obj, str);
	}
	return (1);
}

static int	show_map_with_sprites(t_control *obj)
{
	t_map	*map;
	int		count;

	map = obj->map;
	while (true)
	{
		count = 0;
		while (*(map->row + count))
		{
			if (*(map->row + count) == '0' || *(map->row + count) == ' ' || *(map->row + count) == 'C' || *(map->row + count) == 'E')
				mlx_image_to_window(obj->mlx, obj->img_background,
						obj->load_map_x, obj->load_map_y);
			if (*(map->row + count) == '1')
				mlx_image_to_window(obj->mlx, obj->img_wall, obj->load_map_x,
						obj->load_map_y);
			if (*(map->row + count) == 'P')
				mlx_image_to_window(obj->mlx, obj->img_pac, obj->load_map_x,
						obj->load_map_y);
			// TODO: rever se C é de coletavel
			if (*(map->row + count) == 'C')
				mlx_image_to_window(obj->mlx, obj->img_collectable,
						obj->load_map_x + 8, obj->load_map_y + 8);
			if (*(map->row + count) == 'E')
				mlx_image_to_window(obj->mlx, obj->img_exit, obj->load_map_x,
						obj->load_map_y);
			obj->load_map_x += 30;
			count++;
		}
		if (!map->next)
			break ;
		map = map->next;
		obj->load_map_y += 30;
		obj->load_map_x = 0;
	}
	return (1);
}

int	handle_initial_windows(t_control *obj, int args_number, char **args)
{
	// DONE: Inicialize variaveis
	init_variables(obj);
	// DONE: Carregar mapa
	if (!load_map(obj, *(args + 1)))
		return (0);
	// TODO: Validar mapa
	// DONE: Carregar janela
	if (args_number >= 3)
	{
		obj->window_w = atoi(*(args + 2));
		obj->window_h = atoi(*(args + 3));
		obj->mlx = mlx_init(obj->window_w, obj->window_h, "Pac-Man", false);
	}
	// DONE: Carregar sprites no buffer
	if (!load_images(obj))
		return (0);
	// TODO: Montar Mapa com sprites
	if (!show_map_with_sprites(obj))
		return (0);
	return (1);
}
