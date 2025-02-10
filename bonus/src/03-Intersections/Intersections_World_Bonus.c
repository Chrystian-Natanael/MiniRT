/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections_World_Bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:03:34 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:39:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes_Bonus.h"
#include "Intersections_Bonus.h"

static void	make_cylinder(t_shape *shape, void *lst, t_inter **dest)
{
	if (lst && ((t_cl_inter *)lst)->is_y[0])
		intersections(((t_cl_inter *)lst)->t1, shape, dest);
	if (lst && ((t_cl_inter *)lst)->is_y[1])
		intersections(((t_cl_inter *)lst)->t2, shape, dest);
	if (lst && ((t_cl_inter *)lst)->is_t_cap[0])
		intersections(((t_cl_inter *)lst)->t_cap[0], shape, dest);
	if (lst && ((t_cl_inter *)lst)->is_t_cap[1])
		intersections(((t_cl_inter *)lst)->t_cap[1], shape, dest);
}

static void	make_cone(t_shape *shape, void *lst, t_inter **dest)
{
	if (lst && ((t_cn_inter *)lst)->is_y[0])
		intersections(((t_cn_inter *)lst)->t1, shape, dest);
	if (lst && ((t_cn_inter *)lst)->is_y[1])
		intersections(((t_cn_inter *)lst)->t2, shape, dest);
	if (lst && ((t_cn_inter *)lst)->is_t_cap[0])
		intersections(((t_cn_inter *)lst)->t_cap[0], shape, dest);
	if (lst && ((t_cn_inter *)lst)->is_t_cap[1])
		intersections(((t_cn_inter *)lst)->t_cap[1], shape, dest);
}

void	create_t_inter(t_shape *shape, void *lst, t_inter **dest)
{
	if (!lst)
		return ;
	if (shape->id == SPHERE)
	{
		intersections(((t_sp_inter *)lst)->t1, shape, dest);
		intersections(((t_sp_inter *)lst)->t2, shape, dest);
	}
	if (shape->id == PLANE)
	{
		if (fabs(((t_pl_inter *)lst)->t) > MAX_DIFF)
			intersections(((t_pl_inter *)lst)->t, shape, dest);
	}
	if (shape->id == CYLINDER)
		make_cylinder(shape, lst, dest);
	if (shape->id == CONE)
		make_cone(shape, lst, dest);
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
