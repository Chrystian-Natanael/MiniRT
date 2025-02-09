/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:51:42 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/08 21:19:26 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Light_and_Shading.h"
#include "Objects.h"

double	*normal_at_cone(t_shape s, double *obj_point)
{
	double	y;
	double	dist;
	double	max_radius;
	double	min_radius;
	double	*normal;

	dist = pow(obj_point[X], 2) + pow(obj_point[Z], 2);
	max_radius = pow(((t_cn *)(s.obj))->max, 2);
	min_radius = pow(((t_cn *)(s.obj))->min, 2);
	if (dist < max_radius
		&& obj_point[Y] >= ((t_cn *)(s.obj))->max - MAX_DIFF)
		normal = vector(0, 1, 0);
	else if (dist < min_radius
		&& obj_point[Y] <= ((t_cn *)(s.obj))->min + MAX_DIFF)
		normal = vector(0, -1, 0);
	else
	{
		y = sqrt(dist);
		if (obj_point[Y] > 0)
			y = -y;
		normal = vector(obj_point[X], y, obj_point[Z]);
	}
	return (normal);
}

double	*normal_at_sphere(t_shape *shape, double *obj_pt)
{
	double	*obj_n;
	double	*wld_n;

	(void)shape;
	obj_n = sub(obj_pt, point(0, 0, 0));
	wld_n = multiply_mtx_tp(shape->transp, obj_n);
	wld_n[W] = 0;
	return (norm(wld_n));
}

double	*normal_at_cylinder(t_shape *shape, double *obj_pt)
{
	double	dist;

	dist = pow(obj_pt[X], 2) + pow(obj_pt[Z], 2);
	if (dist < 1 && obj_pt[Y] >= ((t_cl *)shape->obj)->max - MAX_DIFF)
		return (vector(0, 1, 0));
	if (dist < 1 && obj_pt[Y] <= ((t_cl *)shape->obj)->min + MAX_DIFF)
		return (vector(0, -1, 0));
	return (vector(obj_pt[X], 0, obj_pt[Z]));
}

double	*normal_at(t_shape *shape, double *wld_pt)
{
	double	*obj_pt;
	double	*obj_normal;
	double	*world_normal;

	obj_normal = NULL;
	obj_pt = multiply_mtx_tp(shape->inv, wld_pt);
	if (shape->id == SPHERE)
		obj_normal = normal_at_sphere(shape, obj_pt);
	else if (shape->id == PLANE)
		obj_normal = vector(0, 1, 0);
	else if (shape->id == CYLINDER)
		obj_normal = normal_at_cylinder(shape, obj_pt);
	else if (shape->id == CONE)
		obj_normal = normal_at_cone(*shape, obj_pt);
	else
		error("Error\n", "Cannot calculate normal this", "", 1);
	world_normal = multiply_mtx_tp(shape->transp, obj_normal);
	world_normal[W] = 0;
	return (norm(world_normal));
}
