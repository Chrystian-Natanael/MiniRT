/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections_world.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:03:34 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/11 16:13:12 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"
#include "Intersections.h"

void	create_t_inter(t_shape *shape, void *lst, t_inter **dest)
{
	if (shape->id == SPHERE)
	{
		intersections(((t_sp_inter *)lst)->t1, shape, dest);
		intersections(((t_sp_inter *)lst)->t2, shape, dest);
	}
	if (shape->id == PLANE)
		intersections(((t_pl_inter *)lst)->t, shape, dest);
}

t_inter	*intersect_world(t_world *w, t_ray ray)
{
	t_inter	*hit_list;
	void	*lst_inter;
	t_obj	*aux;

	hit_list = NULL;
	aux = w->obj_lst;
	while (aux)
	{
		lst_inter = intersect(aux->shape, ray);
		create_t_inter(aux->shape, lst_inter, &hit_list);
		aux = aux->next;
	}
	return (hit_list);
}
