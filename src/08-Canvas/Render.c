/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:01:08 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 09:38:34 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas.h"
#include "Intersections.h"
#include "Light_and_Shading.h"
#include <fcntl.h>
#include <stdlib.h>

static void	print_rendering_progress(int hsize, int vsize, int y)
{
	int	i;
	int	progress;

	progress = (((y + 1) * hsize * 100) / (hsize * vsize));
	clear_term();
	ft_printf("\033[uProgress: [");
	i = 0;
	while (i < 50)
	{
		if (i < progress / 2)
			ft_printf("=");
		else if (abs((progress / 2) - i) < 1)
			ft_printf(">");
		else if (i % 5 == 0)
			ft_printf("o");
		else
			ft_printf(" ");
		i++;
	}
	ft_printf("] %d%%", progress);
}

t_colors	color_average(t_colors c1, t_colors c2, t_colors c3, t_colors c4)
{
	t_colors	col_average_result;

	col_average_result.red = (c1.red + c2.red + c3.red + c4.red) / 4;
	col_average_result.green = (c1.green + c2.green + c3.green + c4.green) / 4;
	col_average_result.blue = (c1.blue + c2.blue + c3.blue + c4.blue) / 4;
	return (col_average_result);
}

t_colors	render_pixel(t_camera cam, t_world *world, int x, int y)
{
	t_colors	colors[4];
	t_colors	color_average_result;
	t_ray		ray;

	ray = ray_for_pixel(cam, x, y, 0);
	colors[0] = color_at(world, ray);
	ray = ray_for_pixel(cam, x, y, 1);
	colors[1] = color_at(world, ray);
	ray = ray_for_pixel(cam, x, y, 2);
	colors[2] = color_at(world, ray);
	ray = ray_for_pixel(cam, x, y, 3);
	colors[3] = color_at(world, ray);
	color_average_result = color_average(colors[0], colors[1], \
		colors[2], colors[3]);
	return (color_average_result);
}

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
	int					i[2];
	t_paint				canvas;
	t_colors			color;
	const t_pool_set	*set = get_pool();

	i[0] = -1;
	canvas.hei = cam.vsize;
	canvas.wid = cam.hsize;
	canvas.px = (t_colors *)alloc_pool(sizeof(t_colors) * canvas.hei
			* canvas.wid, set->the_pool);
	set->the_pool->saved_point = set->the_pool->used;
	while (++i[0] <= (cam.vsize - 1))
	{
		i[1] = -1;
		while (++i[1] <= (cam.hsize - 1))
		{
			color = render_pixel(cam, world, i[1], i[0]);
			if (i[1] >= canvas.wid || i[0] >= canvas.hei)
				continue ;
			canvas.px[i[0] * canvas.wid + i[1]] = color;
		}
		print_rendering_progress(cam.hsize, cam.vsize, i[0]);
		set->the_pool->used = set->the_pool->saved_point;
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
