/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:24 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/22 16:58:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"
#include <math.h>
#include <unistd.h>

#define L_W 1000
#define L_H 500

void	function(void *param)
{
	t_canvas	*canvas;
	mlx_texture_t	*texture_image0;
	// mlx_texture_t	*texture_image1;
	mlx_image_t		*img0;
	// mlx_image_t		*img1;

	canvas = (t_canvas *)param;
	canvas->image = mlx_new_image(canvas->mlx, L_W, L_H);
	
	texture_image0 = mlx_load_png("./src/10-Loading_tool/content/L-0.png");
	img0 = mlx_texture_to_image(canvas->mlx, texture_image0);
	mlx_set_instance_depth(img0->instances, 1);

	// texture_image1 = mlx_load_png("./src/10-Loading_tool/content/L-parsing.png");
	// img1 = mlx_texture_to_image(canvas->mlx, texture_image1);
	
	// mlx_image_to_window(canvas->mlx, img0, 0, 0);
}

int	main(void)
{
	t_canvas		canvas;

	sleep(10);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	canvas.mlx = mlx_init(L_W, L_H, "WAIT! The Best miniRT is loading", true);
	mlx_loop_hook(canvas.mlx, function, &canvas);
	mlx_loop(canvas.mlx);

	// mlx_image_to_window(canvas.mlx, img1, 0, 0);
	// mlx_set_instance_depth(img1->instances, 1);


	mlx_terminate(canvas.mlx);
	quit(0);
}
