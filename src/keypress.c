/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:21:30 by r-afonso          #+#    #+#             */
/*   Updated: 2023/09/10 23:54:33 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_keypress(void *t_c)
{
	t_control *obj;
	obj = (t_control *) t_c;
	if (mlx_is_key_down(obj->mlx, MLX_KEY_ESCAPE))
	{
		// TODO: fazer o tratamento para free nas demais variveis 
		mlx_terminate((mlx_t *)obj->mlx);
	}
}
