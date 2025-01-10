/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections_world.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:03:34 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/09 16:23:13 by tmalheir         ###   ########.fr       */
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
