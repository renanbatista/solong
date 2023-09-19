#include "../include/so_long.h"

static void	add_list_to_array(t_control *obj)
{
	int		x;
	int		y;
	t_map	*map;
	int		count;

	map = obj->map;
	count = -1;
	x = -1;
	obj->array = malloc(sizeof(char *) * obj->size_y);
	while (++count, count < obj->size_y)
		obj->array[count] = malloc(sizeof(char *) * obj->size_x);
	while (++x, x < obj->size_y)
	{
		y = -1;
		while (++y, y < obj->size_x)
		{
			obj->array[x][y] = map->row[y];
			if (map->row[y] == 'P')
			{
				obj->player_x = y;
				obj->player_y = x;
			}
		}
		map = map->next;
	}
}

static int	load_map(t_control *obj, char *map_name)
{
	int		fd;
	char	*str;

	str = join_str("./maps/", map_name);
	if (!str)
		return (0);
	fd = open(str, O_RDONLY);
	free(str);
	if (fd == -1)
	{
		print_msg(1, obj);
		return (0);
	}
	while (true)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		obj->size_y++;
		obj->size_x = ft_strlen(str);
		add_new_node_to_last(obj, str);
	}
	add_list_to_array(obj);
	return (1);
}
static void	validate_chars(t_map *map, t_control *obj)
{
	int	count;

	count = -1;
	while (++count, *(map->row + count))
	{
		mlx_image_to_window(obj->mlx, obj->i_back, obj->lm_x, obj->lm_y);
		if (*(map->row + count) == '1')
			mlx_image_to_window(obj->mlx, obj->i_wall, obj->lm_x, obj->lm_y);
		if (*(map->row + count) == 'P')
		{
			mlx_image_to_window(obj->mlx, obj->i_pac, obj->lm_x, obj->lm_y);
			if (obj->lm_x > 0)
				obj->player_x = obj->lm_x / 30;
			if (obj->lm_y > 0)
				obj->player_y = obj->lm_y / 30;
		}
		if (*(map->row + count) == 'C')
			mlx_image_to_window(obj->mlx, obj->i_coll, obj->lm_x, obj->lm_y);
		if (*(map->row + count) == 'E')
		{
			mlx_image_to_window(obj->mlx, obj->i_exit, obj->lm_x, obj->lm_y);
			obj->i_exit->instances->enabled = false;
		}
		obj->lm_x += 30;
	}
}
static void	show_map_with_sprites(t_control *obj)
{
	t_map	*map;
	int		count;

	map = obj->map;
	while (true)
	{
		validate_chars(map, obj);
		if (!map->next)
			break ;
		map = map->next;
		obj->lm_y += 30;
		obj->lm_x = 0;
	}
	obj->i_pac->instances->z = obj->i_wall->instances[obj->i_wall->count - 1].z;
	obj->coll_for_exit = obj->i_coll->count;
}

int	handle_initial_windows(t_control *obj, int args_number, char **args)
{
	char	*str;

	obj->window_w = 1024;
	obj->window_h = 1024;
	if (args_number == 4)
	{
		obj->window_w = ft_atoi(*(args + 2));
		obj->window_h = ft_atoi(*(args + 3));
	}
	if (!load_map(obj, *(args + 1)))
		return (0);
	if (!handle_validate_map(obj))
		return (0);
	obj->mlx = mlx_init(obj->window_w, obj->window_h, "Pac-Man", false);
	load_images(obj);
	show_map_with_sprites(obj);
	return (1);
}
