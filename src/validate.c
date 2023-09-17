#include "../include/so_long.h"

void	validate_collectable(t_control *obj)
{
	int	count;
	int	coll_true;

	count = -1;
	while (++count, count < obj->i_coll->count)
	{
		if ((obj->i_pac->instances->x == obj->i_coll->instances[count].x)
			&& (obj->i_pac->instances->y == obj->i_coll->instances[count].y))
		{
			obj->i_coll->instances[count].enabled = false;
			obj->coll_for_exit--;
		}
		if (obj->coll_for_exit == 0)
			obj->i_exit->instances->enabled = true;
	}
}

void	validate_exit(t_control *obj)
{
	if (obj->coll_for_exit == 0)
	{
		if (obj->player_x * 30 == obj->i_exit->instances->x
			&& obj->player_y * 30 == obj->i_exit->instances->y)
			handle_close(obj);	
	}
}