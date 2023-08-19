/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:52:33 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/17 21:22:33 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define MLX_ERROR 1
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# include "../MLX42/include/MLX42/MLX42.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	handle_keypress_esc(mlx_key_data_t keydata, void* mlx);

#endif
