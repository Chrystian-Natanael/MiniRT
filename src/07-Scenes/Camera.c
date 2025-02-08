/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:51:05 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/08 17:34:37 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"

double	*set_offset(t_camera cam, double px, double py, int sample)
{
	double			*offset;
	const double	adjustments[4][2] = {
		{0.25, 0.25},
		{0.75, 0.25},
		{0.25, 0.75},
		{0.75, 0.75}
	};

	offset = allocate(2 * sizeof(double));
	if (sample >= 0 && sample < 4)
	{
		offset[X] = (px + adjustments[sample][0]) * cam.pixel_sz;
		offset[Y] = (py + adjustments[sample][1]) * cam.pixel_sz;
	}
	else
	{
		offset[X] = (px + 0.5) * cam.pixel_sz;
		offset[Y] = (py + 0.5) * cam.pixel_sz;
	}
	return (offset);
}

t_ray	ray_for_pixel(t_camera cam, double px, double py, int sample)
{
	double	*offset;
	double	world[2];
	double	*pixel;
	double	*origin;
	double	*direction;

	offset = set_offset(cam, px, py, sample);
	world[X] = (cam.half_widht) - offset[X];
	world[Y] = (cam.half_heigth) - offset[Y];
	pixel = multiply_mtx_tp(inv(cam.transform), point(world[X], world[Y], -1));
	origin = multiply_mtx_tp(inv(cam.transform), point(0, 0, 0));
	direction = norm(sub(pixel, origin));
	return (create_ray(origin, direction));
}

static void	calculate_pixel(t_camera *cam)
{
	double	half_view;
	double	aspect;

	half_view = tan(cam->field_view / 2);
	aspect = cam->hsize / cam->vsize;
	if (aspect >= 1)
	{
		cam->half_widht = half_view;
		cam->half_heigth = half_view / aspect;
	}
	else
	{
		cam->half_widht = half_view * aspect;
		cam->half_heigth = half_view;
	}
	cam->pixel_sz = (cam->half_widht * 2) / cam->hsize;
}

t_camera	camera(int hsize, int vsize, double field_view)
{
	t_camera	cam;

	cam.hsize = hsize;
	cam.vsize = vsize;
	cam.field_view = field_view;
	cam.up = vector(0, 1, 0);
	cam.transform = id_mtx();
	calculate_pixel(&cam);
	return (cam);
}
