/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:01:08 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/11 16:24:54 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas.h"
#include <stdlib.h>
#include <fcntl.h>

void	init_window(t_canvas *canvas)
{
	canvas->mlx = mlx_init(WIDTH, HEIGHT, "MiniRT", true);
	canvas->image = mlx_new_image(canvas->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(canvas->mlx, canvas->image, 0, 0);
}
