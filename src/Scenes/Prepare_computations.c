/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:27:30 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/02 12:00:21 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"
#include "Scenes.h"

t_comp	*prepare_computations(t_inter *intersec, t_ray ray)
{
	t_comp		*comps;
	t_pool_set	*set;

	set = get_pools();
	comps = (t_comp *)alloc_pool(sizeof(t_comp), set->objects);
	comps->pos = intersec->pos;
	comps->sp = intersec->sp;
	comps->point = pos_ray(ray, intersec->pos);
	comps->eyev = multiply(ray.dir, -1);
	comps->normalv = normal_at(comps->sp, comps->point);
	if (dot_prod(comps->normalv, comps->eyev) < 0)
	{
		comps->inside = true;
		comps->normalv = multiply(comps->normalv, -1);
	}
	else
		comps->inside = false;
	return (comps);
}
