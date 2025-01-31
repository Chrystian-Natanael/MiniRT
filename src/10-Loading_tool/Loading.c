/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:33:26 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/22 16:45:26 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Loading.h"

// #define L_W 1000
// #define L_H 500

// t_canvas	init_loading(void)
// {
// 	t_canvas		canvas;
// 	mlx_texture_t	*texture_image0;
// 	mlx_texture_t	*texture_image1;
// 	// mlx_texture_t	*texture_image2;
// 	// mlx_texture_t	*texture_image3;
// 	// mlx_texture_t	*texture_image4;
// 	// mlx_texture_t	*texture_image5;
// 	// mlx_texture_t	*texture_image6;
// 	mlx_image_t		*img0;
// 	mlx_image_t		*img1;
// 	// mlx_image_t		*img2;
// 	// mlx_image_t		*img3;
// 	// mlx_image_t		*img4;
// 	// mlx_image_t		*img5;
// 	// mlx_image_t		*img6;

// 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// 	canvas.mlx = mlx_init(L_W, L_H, "WAIT! The Best miniRT is loading", true);
// 	canvas.image = mlx_new_image(canvas.mlx, L_W, L_H);
	
// 	texture_image0 = mlx_load_png("./src/10-Loading_tool/content/L-0.png");
// 	img0 = mlx_texture_to_image(canvas.mlx, texture_image0);

// 	texture_image1 = mlx_load_png("./src/10-Loading_tool/content/L-parsing.png");
// 	img1 = mlx_texture_to_image(canvas.mlx, texture_image1);
	
// 	mlx_image_to_window(canvas.mlx, img0, 0, 0);
// 	mlx_set_instance_depth(img0->instances, 1);

// 	sleep(10);

// 	mlx_image_to_window(canvas.mlx, img1, 0, 0);
// 	mlx_set_instance_depth(img1->instances, 1);
// 	return (canvas);
// }
