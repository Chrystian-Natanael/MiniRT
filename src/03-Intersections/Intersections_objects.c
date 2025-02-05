/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections_objects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:18:03 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/05 10:01:36 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

t_sp_inter	*intersect_sphere(t_shape *shape, t_ray ray)
{
	t_coef		coef;
	t_sp_inter	*value;
	t_ray		new_ray;

	if (!shape || !(t_sp *)shape->obj)
		error("Error\n", "Sphere doesn't exist", NULL, ERROR);
	new_ray = transform(ray, shape->inv);
	coef = calc_coef((t_sp *)shape->obj, new_ray);
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
	set = get_pool();
	value = (t_pl_inter *)alloc_pool(sizeof(t_pl_inter), set->the_pool);
	value->count = 1;
	value->t = -ray.src[Y] / ray.dir[Y];
	value->pl = (t_pl *)shape->obj;
	return (value);
}
