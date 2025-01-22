/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:16:17 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/22 13:16:22 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

void	intersections(double pos, t_shape *s, t_inter **dest)
{
	t_inter		*node;
	t_pool_set	*set;

	set = get_pools();
	if (!s)
		error("Error\n", "Shape doesn't exist", NULL, ERROR);
	if (!(*dest))
	{
		(*dest) = (t_inter *)alloc_pool(sizeof(t_inter), set->objects);
		(*dest)->pos = pos;
		(*dest)->shape = s;
		return ;
	}
	node = (t_inter *)alloc_pool(sizeof(t_inter), set->objects);
	node->pos = pos;
	node->shape = s;
	insert_into_list(dest, node);
	while ((*dest)->prev)
		*dest = (*dest)->prev;
}

void	*intersect(t_shape *shape, t_ray ray)
{
	t_ray	new_ray;

	new_ray = transform(ray, shape->inv);
	if (shape->id == SPHERE)
		return ((void *)intersect_sphere(shape, new_ray));
	if (shape->id == PLANE)
		return ((void *)intersect_plane(shape, new_ray));
	if (shape->id == CYLINDER)
		return ((void *)intersect_cylinder(shape, new_ray));
	return (NULL);
}
