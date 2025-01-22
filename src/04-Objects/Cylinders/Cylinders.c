/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:03:04 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/22 13:27:40 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

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
		(*value)->t_cap[0] = (((t_cl *)shape->obj)->min - ray.src[Y])
			/ ray.dir[Y];
		if (check_cap(ray, (*value)->t_cap[0]))
			(*value)->is_t_cap[0] = true;
		(*value)->t_cap[1] = (((t_cl *)shape->obj)->max - ray.src[Y])
			/ ray.dir[Y];
		if (check_cap(ray, (*value)->t_cap[1]))
			(*value)->is_t_cap[1] = true;
	}
}

static void	init_t_cl_inter(t_cl_inter **val, t_shape *shape, t_coef coef)
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
	coef.b = (2 * ray.src[X] * ray.dir[X])
		+ (2 * ray.src[Z] * ray.dir[Z]);
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
	if (value->is_t_cap[0])
		value->count++;
	if (value->is_t_cap[1])
		value->count++;
	return (value);
}

bool	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.src[X] + t * ray.dir[X];
	z = ray.src[Z] + t * ray.dir[Z];
	return (pow(x, 2) + pow(z, 2) <= 1);
}

t_cl	*create_cl(void)
{
	t_cl		*cl;
	t_pool_set	*set;

	set = get_pools();
	cl = (t_cl *)alloc_pool(sizeof(t_cl), set->objects);
	cl->src = point(0, 0, 0);
	cl->radius = 1;
	cl->min = INT32_MIN;
	cl->max = INT32_MAX;
	cl->closed = false;
	return (cl);
}
