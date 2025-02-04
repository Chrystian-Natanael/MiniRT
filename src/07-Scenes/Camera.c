/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:51:05 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/04 14:47:36 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"

t_ray	ray_for_pixel(t_camera cam, double px, double py)
{
	double	offset[2];
	double	world[2];
	double	*pixel;
	double	*origin;
	double	*direction;

	offset[X] = (px + 0.5) * cam.pixel_sz;
	offset[Y] = (py + 0.5) * cam.pixel_sz;
	world[X] = (cam.half_width) - offset[X];
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
		cam->half_width = half_view;
		cam->half_heigth = half_view / aspect;
	}
	else
	{
		cam->half_width = half_view * aspect;
		cam->half_heigth = half_view;
	}
	cam->pixel_sz = (cam->half_width * 2) / cam->hsize;
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
