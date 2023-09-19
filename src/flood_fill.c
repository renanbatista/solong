#include "../include/so_long.h"

int	handle_ff(t_control *obj, char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y][x] == '1')
		return (0);
	if (x >= obj->size_x -1 || y >= obj->size_y -1)
		return (0);
	map[y][x] = '1';
	if (handle_ff(obj, map, x + 1, y) || handle_ff(obj, map, x - 1, y)
		|| handle_ff(obj, map, x, y + 1) || handle_ff(obj, map, x, y - 1))
		return (1);
	return (0);
}

int	validate_map_ff(t_control *obj)
{
	int	x;
	int	y;
	char **array;

	array = obj->array;
	y = 0;
	while (y < obj->size_y)
	{
		x = 0;
		while (x < obj->size_x)
		{
			if (array[y][x] != '1' && array[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
