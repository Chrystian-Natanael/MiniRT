/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:51:05 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/07 09:05:57 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"

static void calculate_pixel(t_camera *cam)
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
	cam.transform = id_mtx();
	calculate_pixel(&cam);
	return (cam);
}