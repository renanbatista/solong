#include "../include/so_long.h"
#include <stdint.h>

static void	init_variables(t_control *obj)
{
	obj->load_map_x = 0;
	obj->load_map_y = 0;
	obj->size_x = 0;
	obj->size_y = 0;
	obj->player_x = 0;
	obj->player_y = 0;
	obj->window_w = 0;
	obj->window_h = 0;
	obj->moviment[0] = 0;
	obj->moviment[1] = 0;
	obj->moviment[2] = 0;
	obj->moviment[3] = 0;
	obj->move_t = 0;
}
static int	load_map(t_control *obj, char *map_name)
{
	int		fd;
	char	*str;

	str = join_str("./maps/", map_name);
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
		obj->size_y++;
		obj->size_x = ft_strlen(str);
		add_new_node_to_last(obj, str);
	}
	return (1);
}

static void	show_map_with_sprites(t_control *obj)
{
	t_map	*map;
	int		count;

	map = obj->map;
	while (true)
	{
		count = -1;
		while (++count, *(map->row + count))
		{
			mlx_image_to_window(obj->mlx, obj->i_back, obj->load_map_x,
					obj->load_map_y);
			if (*(map->row + count) == '1')
				mlx_image_to_window(obj->mlx, obj->i_wall, obj->load_map_x,
						obj->load_map_y);
			if (*(map->row + count) == 'P')
			{
				mlx_image_to_window(obj->mlx, obj->i_pac, obj->load_map_x,
						obj->load_map_y);
				if (obj->load_map_x > 0)
					obj->player_x = obj->load_map_x / 30;
				if (obj->load_map_y > 0)
					obj->player_y = obj->load_map_y / 30;
			}
			if (*(map->row + count) == 'C')
				mlx_image_to_window(obj->mlx, obj->i_coll, obj->load_map_x,
						obj->load_map_y);
			if (*(map->row + count) == 'E')
			{
				mlx_image_to_window(obj->mlx, obj->i_exit, obj->load_map_x,
						obj->load_map_y);
				obj->i_exit->instances->enabled = false;
			}
			obj->load_map_x += 30;
		}
		if (!map->next)
			break ;
		map = map->next;
		obj->load_map_y += 30;
		obj->load_map_x = 0;
	}
	obj->i_pac->instances->z = obj->i_wall->instances[obj->i_wall->count - 1].z;
}

int	handle_initial_windows(t_control *obj, int args_number, char **args)
{
	char *str;
	
	init_variables(obj);
	if (!load_map(obj, *(args + 1)))
		return (0);
	// TODO: Validar mapa
	if (args_number >= 3)
	{
		obj->window_w = ft_atoi(*(args + 2));
		obj->window_h = ft_atoi(*(args + 3));
		obj->mlx = mlx_init(obj->window_w, obj->window_h, "Pac-Man", false);
	}
	if (!load_images(obj))
		return (0);
	show_map_with_sprites(obj);
	obj->coll_for_exit = obj->i_coll->count;
	return (1);
}