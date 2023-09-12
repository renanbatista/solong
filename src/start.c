#include "../include/so_long.h"

int	main(int args_number, char **args)
{
	t_control	*obj;

	obj = ft_calloc(sizeof(t_control), 1);
	if (!handle_initial_windows(obj, args_number, args))
		handle_close_map(obj);
	if (!obj->mlx)
		exit(EXIT_FAILURE);
	// TODO: Tratativa da movimentação do player
	mlx_loop_hook(obj->mlx, &handle_keypress, obj);
	mlx_loop(obj->mlx);
	mlx_terminate(obj->mlx);
	return (0);
}
