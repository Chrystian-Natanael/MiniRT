/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:16:17 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/21 11:44:21 by cnatanae         ###   ########.fr       */
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
