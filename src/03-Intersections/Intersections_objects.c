/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections_objects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:18:03 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/21 15:43:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

t_sp_inter	*intersect_sphere(t_shape *shape, t_ray ray)
{
	t_coef		coef;
	t_sp_inter	*value;

	if (!shape || !(t_sp *)shape->obj)
		error("Error\n", "Sphere doesn't exist", NULL, ERROR);
	coef = calc_coef((t_sp *)shape->obj, ray);
	value = calc_intersection(coef);
	value->sp = (t_sp *)shape->obj;
	return (value);
}

t_pl_inter	*intersect_plane(t_shape *shape, t_ray ray)
{
	t_pl_inter	*value;
	t_pool_set	*set;

	if (fabs(ray.dir[Y]) < MAX_DIFF)
		return (NULL);
	set = get_pools();
	value = (t_pl_inter *)alloc_pool(sizeof(t_pl_inter), set->objects);
	value->count = 1;
	value->t = -ray.src[Y] / ray.dir[Y];
	value->pl = (t_pl *)shape->obj;
	return (value);
}

static void	swap(double *t1, double *t2)
{
	double	tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

static void	aux_intersect_cl(t_cl_inter **value, t_ray ray, t_shape *shape)
{
	if ((*value)->t1 > (*value)->t2)
		swap(&(*value)->t1, &(*value)->t2);
	(*value)->y[0] = ray.src[Y] + (*value)->t1 * ray.dir[Y];
	if (((t_cl *)shape->obj)->min < (*value)->y[0] && (*value)->y[0]
			< ((t_cl *)shape->obj)->max)
		(*value)->is_y[0] = true;
	(*value)->y[1] = ray.src[Y] + (*value)->t2 * ray.dir[Y];
	if (((t_cl *)shape->obj)->min < (*value)->y[1] && (*value)->y[1]
			< ((t_cl *)shape->obj)->max)
		(*value)->is_y[1] = true;
	if (((t_cl *)shape->obj)->closed && !equal(ray.dir[Y], 0))
	{
		(*value)->t_cap[0] = (((t_cl *)shape->obj)->min - ray.src[Y]) / ray.dir[Y];
		if (check_cap(ray, (*value)->t_cap[0]))
		{
			(*value)->count++;
			(*value)->is_t_cap[0] = true;
		}
		(*value)->t_cap[1] = (((t_cl *)shape->obj)->max - ray.src[Y]) / ray.dir[Y];
		if (check_cap(ray, (*value)->t_cap[1]))
		{
			(*value)->count++;
			(*value)->is_t_cap[1] = true;
		}
	}
}

static void init_t_cl_inter(t_cl_inter **val, t_shape *shape, t_coef coef)
{
	t_pool_set	*set;

	set = get_pools();
	(*val) = (t_cl_inter *)alloc_pool(sizeof(t_cl_inter), set->objects);
	(*val)->cl = (t_cl *)shape->obj;
	(*val)->t1 = (-coef.b - sqrt(coef.discrim)) / (2 * coef.a);
	(*val)->t2 = (-coef.b + sqrt(coef.discrim)) / (2 * coef.a);
	(*val)->count = 0;
	(*val)->is_t_cap[0] = false;
	(*val)->is_t_cap[1] = false;
	(*val)->is_y[0] = false;
	(*val)->is_y[1] = false;
}

t_cl_inter	*intersect_cylinder(t_shape *shape, t_ray ray)
{
	t_cl_inter	*value;
	t_coef		coef;

	coef.a = pow(ray.dir[X], 2) + pow(ray.dir[Z], 2);
	if (equal(coef.a, 0) && !((t_cl *)shape->obj)->closed)
		return (NULL);
	coef.b = (2 * ray.src[X] * ray.dir[X]) +
			(2 * ray.src[Z] * ray.dir[Z]);
	coef.c = pow(ray.src[X], 2) + pow(ray.src[Z], 2) - 1;
	coef.discrim = pow(coef.b, 2) - (4 * coef.a * coef.c);
	if (coef.discrim < 0)
		return (NULL);
	init_t_cl_inter(&value, shape, coef);
	aux_intersect_cl(&value, ray, shape);
	if (value->is_y[0])
		value->count++;
	if (value->is_y[1])
		value->count++;
	return (value);
}
