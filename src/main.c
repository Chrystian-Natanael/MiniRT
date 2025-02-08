/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:24 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/07 15:23:42 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"
#include <math.h>

int	main(int argc, char **argv)
{
	t_world		*world;
	t_paint		paint;
	mlx_t		*mlx;
	mlx_image_t	*image;

	world = parser(argc, argv);
	paint = render_canva(world->camera, world);
	if (world->scene.save_img)
		canva2ppm(paint, world->scene.file_name);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(world->camera.hsize, world->camera.vsize, "MyminiRT", true);
	image = canva2image(paint, mlx);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	quit(0);
}
