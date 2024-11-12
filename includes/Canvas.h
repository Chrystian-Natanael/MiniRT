/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:43:44 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/12 16:18:04 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "MLX42/MLX42.h"
# include "Colors.h"

# define WIDTH 1366
# define HEIGHT 720

typedef struct s_canvas
{
	mlx_t		*mlx;
	mlx_image_t	*image;

}	t_canvas;

void	init_window(t_canvas *canvas);

#endif