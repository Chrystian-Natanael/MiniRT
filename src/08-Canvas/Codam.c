/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Codam.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:30:39 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:55:18 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas.h"
#include "Codam.h"
#include "Colors.h"
#include "Scenes.h"

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
		error("Error\n", "Cannot open image\n", "", 1);
	y = -1;
	while (++y < canvas.hei)
	{
		x = -1;
		while (++x < canvas.wid)
			mlx_put_pixel(im, x, y, rgb2hex((canvas.px[y * canvas.wid + x])));
	}
	return (im);
}
