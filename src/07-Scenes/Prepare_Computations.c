/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prepare_Computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:27:30 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:16:31 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"
#include "Scenes.h"

t_comp	*prepare_computations(t_inter *intersec, t_ray ray)
{
	t_comp		*comps;
	t_pool_set	*set;

	set = get_pool();
	comps = (t_comp *)alloc_pool(sizeof(t_comp), set->the_pool);
	comps->pos = intersec->pos;
	comps->shape = intersec->shape;
	comps->point = pos_ray(ray, intersec->pos);
	comps->sig.eye = multiply(ray.dir, -1);
	comps->sig.normal = normal_at(comps->shape, comps->point);
	comps->over_point = sum(comps->point,
			multiply(comps->sig.normal, MAX_DIFF));
	comps->inside = false;
	if (dot_prod(comps->sig.normal, comps->sig.eye) < 0)
	{
		comps->inside = true;
		comps->sig.normal = multiply(comps->sig.normal, -1);
	}
	return (comps);
}
