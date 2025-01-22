/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:08 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/22 13:16:25 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

t_sp_inter	*calc_intersection(t_coef coef)
{
	t_sp_inter	*list;
	t_pool_set	*set;

	set = get_pools();
	list = (t_sp_inter *)alloc_pool(sizeof(t_sp_inter), set->objects);
	if (coef.discrim < 0)
		return (list);
	list->count = 2;
	list->t1 = ((coef.b * -1) - sqrt(coef.discrim)) / (2 * coef.a);
	list->t2 = ((coef.b * -1) + sqrt(coef.discrim)) / (2 * coef.a);
	return (list);
}

t_coef	calc_coef(t_sp *sp, t_ray ray)
{
	t_coef	coef;
	double	*sp_to_ray;

	sp_to_ray = sub(ray.src, sp->src);
	coef.a = dot_prod(ray.dir, ray.dir);
	coef.b = 2 * dot_prod(ray.dir, sp_to_ray);
	coef.c = dot_prod(sp_to_ray, sp_to_ray) - 1;
	coef.discrim = pow(coef.b, 2) - 4 * coef.a * coef.c;
	return (coef);
}

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

t_sp	*create_sp(void)
{
	t_sp		*sp;
	t_pool_set	*set;

	set = get_pools();
	sp = (t_sp *)alloc_pool(sizeof(t_sp), set->objects);
	sp->src = point(0, 0, 0);
	sp->radius = 1;
	return (sp);
}
