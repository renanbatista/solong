/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:32:36 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/03 17:50:13 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_windows(void *param)
{
	mlx_destroy_display(param);
	mlx_destroy_window(param, "So_Long");
	free(param);
	return(0);
}
int main()
{
	void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "So_Long");

	mlx_hook(win_ptr, 17, 0, close_windows, mlx_ptr);

    mlx_loop(mlx_ptr);
	return (0);
}
