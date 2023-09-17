#include "../include/so_long.h"

int	main(int args_number, char **args)
{
	t_control	*obj;

	obj = ft_calloc(sizeof(t_control), 1);
	if (!handle_initial_windows(obj, args_number, args))
		handle_close(obj);
	if (!obj->mlx)
		exit(EXIT_FAILURE);
	// TODO: Tratativa da movimentação do player
	// mlx_loop_hook(obj->mlx, &handle_keypress, obj);
	mlx_loop_hook(obj->mlx, &handle_keypress_esc, obj);
	mlx_key_hook(obj->mlx, &handle_keypress, obj);
	mlx_close_hook(obj->mlx, &handle_close, obj);
	mlx_loop(obj->mlx);
	mlx_terminate(obj->mlx);
	free(obj);
	obj = NULL;
	return (0);
}
