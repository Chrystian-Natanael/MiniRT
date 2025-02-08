/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:24 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/08 17:43:11 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"
#include <math.h>

void	key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
}

int	main(int argc, char **argv)
{
	t_world		*world;
	t_paint		paint;
	mlx_t		*mlx;
	mlx_image_t	*image;

	world = parser(argc, argv);
	paint = render_canva(world->camera, world);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(world->camera.hsize, world->camera.vsize, "miniRT", true);
	image = canva2image(paint, mlx);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_key_hook(mlx, key_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	if (world->scene.save_img)
	{
		ft_printf("Saving image as file...\n");
		canva2ppm(paint, world->scene.file_name);
	}
	quit(0);
}
