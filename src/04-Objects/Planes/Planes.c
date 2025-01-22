/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:09:35 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/22 13:17:09 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

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

t_pl	*create_pl(void)
{
	t_pl		*pl;
	t_pool_set	*set;

	set = get_pools();
	pl = (t_pl *)alloc_pool(sizeof(t_pl), set->objects);
	pl->src = point(0, 0, 0);
	return (pl);
}
