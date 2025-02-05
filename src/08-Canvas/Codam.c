/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Codam.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:30:39 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/05 10:11:34 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas.h"
#include "Codam.h"
#include "Colors.h"
#include "Scenes.h"

/**
 * @brief Initializes the application window with the specified settings
 *
 * This function initializes the application window using the MLX library.
 * The window is created with the dimensions defined by `WIDHT` and `HEIGHT`,
 * and with the title "MiniRT". Additionally, a new image is created and
 * associated with the window, displayed at position (0, 0). MLX settings are
 * adjusted to allow image stretching.
 *
 * @param canvas A pointer to a `t_canvas` structure that holds references
 * to the MLX window
 * and the image to be displayed. The function initializes the `canvas`
 * structure with the
 * appropriate window and image.
 */
// void	init_window(t_canvas *canvas)
// {
// 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// 	canvas->mlx = mlx_init(WIDHT, HEIGHT, "MiniRT", true);
// 	canvas->image = mlx_new_image(canvas->mlx, WIDHT, HEIGHT);
// 	mlx_image_to_window(canvas->mlx, canvas->image, 0, 0);
// }
// void	init_window(t_canvas *canvas)
// {
// 	mlx_set_setting(MLX_STRETCH_IMAGE, true);
// 	canvas->mlx = mlx_init(WIDHT, HEIGHT, "MiniRT", true);
// 	canvas->image = mlx_new_image(canvas->mlx, WIDHT, HEIGHT);
// 	mlx_image_to_window(canvas->mlx, canvas->image, 0, 0);
// }

/**
 * @brief Converts canvas data to a usable MLX image
 *
 * This function creates a new MLX image based on the dimensions specified in
 * the canvas. For each pixel in the canvas, the corresponding RGB value is
 * converted to a hexadecimal value and placed into the image. The resulting
 * image is returned for display or further manipulation.
 *
 * @param canvas A `t_paint` structure containing the canvas data, including
 * its dimensions and the pixel data to be converted into the image.
 * @param mlx Reference to the MLX instance, required to create the new image.
 * @return A pointer to the newly created image, which contains the pixels
 * representing the canvas.
 */
mlx_image_t	*canva2image(t_paint canvas, mlx_t *mlx)
{
	mlx_image_t	*im;
	int			x;
	int			y;

	im = mlx_new_image(mlx, canvas.wid, canvas.hei);
	if (!im)
		error("IMAGE ERROR", NULL, NULL, 1);
	y = -1;
	while (++y < canvas.hei)
	{
		x = -1;
		while (++x < canvas.wid)
			mlx_put_pixel(im, x, y, rgb2hex((canvas.px[y * canvas.wid + x])));
	}
	return (im);
}
