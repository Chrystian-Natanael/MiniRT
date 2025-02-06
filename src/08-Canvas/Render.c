/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:01:08 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/06 15:19:54 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas.h"
#include "Intersections.h"
#include "Light_and_Shading.h"
#include <fcntl.h>
#include <stdlib.h>

/**
 * @brief Renders a canvas for the given camera and world
 *
 * This function generates a canvas (image) based on the camera's
 * specifications and the world configuration, by casting rays for each pixel
 * in the canvas and determining the color at each pixel.
 * It creates a canvas structure and populates it with the colors resulting
 * from ray tracing in the world scene.
 *
 * @param cam The camera configuration
 * @param world A pointer to the world configuration that contains the objects
 * and lights list for ray tracing.
 * @return A t_paint structure representing the generated canvas,
 * which includes the pixel data (colors) based on the ray tracing.
 */
t_paint	render_canva(t_camera cam, t_world *world)
{
	int			i[2];
	t_ray		ray;
	t_pool_set	*set;
	t_paint		canvas;
	t_colors	color;

	i[0] = -1;
	set = get_pool();
	canvas.hei = cam.vsize;
	canvas.wid = cam.hsize;
	canvas.px = (t_colors *)alloc_pool(sizeof(t_colors) * canvas.hei
			* canvas.wid, set->the_pool);
	while (++i[0] <= (cam.vsize - 1))
	{
		i[1] = -1;
		while (++i[1] <= (cam.hsize - 1))
		{
			ray = ray_for_pixel(cam, i[1], i[0]);
			color = color_at(world, ray);
			if (i[1] >= canvas.wid || i[0] >= canvas.hei)
				continue ;
			canvas.px[i[0] * canvas.wid + i[1]] = color;
		}
		printf("LINE[%d]\n", i[0]);
	}
	return (canvas);
}

/**
 * @brief Retrieves the color of a pixel at a specified position on the canvas
 *
 * This function returns the color of the pixel located at the given (x, y)
 * coordinates on the provided canvas. If the coordinates are out of bounds,
 * it returns the color black (0, 0, 0).
 *
 * @param canvas The canvas structure containing pixel data, widht and height.
 * @param x The x-coordinate of the pixel to retrieve (horizontal position).
 * @param y The y-coordinate of the pixel to retrieve (vertical position).
 * @return The color of the pixel at the specified coordinates, or black if
 * the coordinates are out of bounds.
 */
t_colors	pixel_at(t_paint canvas, int x, int y)
{
	if (x < 0 || x >= canvas.wid || y < 0 || y >= canvas.hei)
		return (create_color(0, 0, 0));
	return (canvas.px[y * canvas.wid + x]);
}
