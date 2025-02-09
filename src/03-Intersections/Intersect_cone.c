/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:54:54 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/08 21:39:39 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

static void	calculate_cone_intersections(t_cn_inter **cn, t_coef coef, t_ray r)
{
	coef.discrim = sqrt(coef.discrim);
	(*cn)->t1 = (-coef.b - coef.discrim) / (2.0 * coef.a);
	(*cn)->t2 = (-coef.b + coef.discrim) / (2.0 * coef.a);
	if ((*cn)->t1 > (*cn)->t2)
		swap(&(*cn)->t1, &(*cn)->t2);
	(*cn)->y[0] = r.src[Y] + (*cn)->t1
		* r.dir[Y];
	(*cn)->y[1] = r.src[Y] + (*cn)->t2
		* r.dir[Y];
	if ((*cn)->cn->min < (*cn)->y[0]
		&& (*cn)->y[0] < (*cn)->cn->max)
		(*cn)->is_y[0] = true;
	if ((*cn)->cn->min < (*cn)->y[1]
		&& (*cn)->y[1] < (*cn)->cn->max)
			(*cn)->is_y[1] = true;
}

static int	check_cap_cn(t_ray r, double t, double cap_y_pos)
{
	double	x;
	double	z;

	x = r.src[X] + t * r.dir[X];
	z = r.src[Z] + t * r.dir[Z];
	return (pow(x, 2) + pow(z, 2) <= pow(cap_y_pos, 2));
}

static void	intersect_caps(t_shape *s, t_ray r, t_cn_inter **cn)
{
	if (((t_cn *)s->obj)->closed == false || equal(r.dir[Y], 0))
		return ;
	(*cn)->t_cap[0] = (((t_cn *)s->obj)->min - r.src[Y]) / r.dir[Y];
	if (check_cap_cn(r, (*cn)->t_cap[0], ((t_cn *)s->obj)->min))
		(*cn)->is_t_cap[0] = true;
	(*cn)->t_cap[1] = (((t_cn *)s->obj)->max - r.src[Y]) / r.dir[Y];
	if (check_cap_cn(r, (*cn)->t_cap[1], ((t_cn *)s->obj)->max))
		(*cn)->is_t_cap[1] = true;
}

t_coef	calculate_cone_discriminats(t_ray ray)
{
	t_coef		coef;

	coef.a = pow(ray.dir[X], 2)
		- pow(ray.dir[Y], 2) + pow(ray.dir[Z], 2);
	coef.b = (2 * ray.src[X]
			* ray.dir[X])
		- (2 * ray.src[Y] * ray.dir[Y])
		+ (2 * ray.src[Z] * ray.dir[Z]);
	coef.c = pow(ray.src[X], 2)
		- pow(ray.src[Y], 2) + pow(ray.src[Z], 2);
	coef.discrim = pow(coef.b, 2)
		- 4 * coef.a * coef.c;
	return (coef);
}

t_cn_inter	*intersect_cone(t_shape *s, t_ray r)
{
	t_cn_inter			*value;
	t_coef				coef;
	const t_pool_set	*set = get_pool();

	value = (t_cn_inter *)alloc_pool(sizeof(t_cn_inter), set->the_pool);
	value->is_t_cap[0] = false;
	value->is_t_cap[1] = false;
	value->is_y[0] = false;
	value->is_y[1] = false;
	value->count = 1;
	value->cn = (t_cn *)s->obj;
	coef = calculate_cone_discriminats(r);
	intersect_caps(s, r, &value);
	if (equal(coef.a, 0))
	{
		if (equal(coef.b, 0))
			return (NULL);
		value->is_y[0] = true;
		value->t1 = -coef.c / (2 * coef.b);
		return (value);
	}
	if (coef.discrim < 0)
		return (NULL);
	calculate_cone_intersections(&value, coef, r);
	return (value);
}
