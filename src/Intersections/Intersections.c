/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:16:17 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 11:06:13 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

static t_sp_inter	*calc_intersection(t_coef coef)
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

static t_coef	calc_coef(t_sp *sp, t_ray ray)
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

void	intersections(double pos, t_sp *s, t_inter **dest)
{
	t_inter		*node;
	t_pool_set	*set;

	set = get_pools();
	if (!s)
		error("Error\n", "Sphere doesn't exist", NULL, ERROR);
	if (!(*dest))
	{
		(*dest) = (t_inter *)alloc_pool(sizeof(t_inter), set->objects);
		(*dest)->pos = pos;
		(*dest)->sp = s;
		return ;
	}
	node = (t_inter *)alloc_pool(sizeof(t_inter), set->objects);
	node->sp = s;
	node->pos = pos;
	insert_into_list(dest, node);
	while ((*dest)->prev)
		*dest = (*dest)->prev;
}

t_sp_inter	*intersect(t_sp *sp, t_ray ray)
{
	t_coef		coef;
	t_sp_inter	*value;
	t_ray		new_ray;

	if (!sp)
		error("Error\n", "Sphere doesn't exist", NULL, ERROR);
	new_ray = transform(ray, sp->inv);
	coef = calc_coef(sp, new_ray);
	value = calc_intersection(coef);
	value->sp = sp;
	return (value);
}

t_inter	*hit(t_inter *list)
{
	t_inter	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->pos > 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
