/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:51:42 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/21 12:02:14 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Light_and_Shading.h"
#include "Objects.h"

double	*normal_at_sphere(t_shape *shape, double *wld_pt)
{
	double	*obj_pt;
	double	*obj_n;
	double	*wld_n;

	obj_pt = multiply_mtx_tp(shape->inv, wld_pt);
	obj_n = sub(obj_pt, point(0, 0, 0));
	wld_n = multiply_mtx_tp(shape->transp, obj_n);
	wld_n[W] = 0;
	return (norm(wld_n));
}

double	*normal_at_cylinder(t_shape *shape, double *wld_pt)
{
	double	dist;

	dist = pow(wld_pt[X], 2) + pow(wld_pt[Z], 2);
	if (dist < 1 && wld_pt[Y] >= ((t_cl *)shape->obj)->max - MAX_DIFF)
		return (vector(0, 1, 0));
	if (dist < 1 && wld_pt[Y] <= ((t_cl *)shape->obj)->min + MAX_DIFF)
		return (vector(0, -1, 0));
	return (vector(wld_pt[X], 0, wld_pt[Z]));
}

double	*normal_at(t_shape *shape, double *wld_pt)
{
	if (shape->id == SPHERE)
		return (normal_at_sphere(shape, wld_pt));
	if (shape->id == PLANE)
		return (vector(0, 1, 0));
	if (shape->id == CYLINDER)
		return (normal_at_cylinder(shape, wld_pt));
	return (0);
}
