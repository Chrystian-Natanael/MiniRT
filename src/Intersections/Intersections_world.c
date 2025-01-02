/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections_world.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:03:34 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/02 11:05:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"
#include "Intersections.h"

t_inter	*intersect_world(t_world *w, t_ray ray)
{
	t_inter		*hit_list;
	t_sp_inter	*sp_inter;
	t_obj		*aux;

	hit_list = NULL;
	aux = w->obj_lst;
	while (aux)
	{
		sp_inter = intersect(aux->sp, ray);
		intersections(sp_inter->t1, sp_inter->sp, &hit_list);
		intersections(sp_inter->t2, sp_inter->sp, &hit_list);
		aux = aux->next;
	}
	return (hit_list);
}
