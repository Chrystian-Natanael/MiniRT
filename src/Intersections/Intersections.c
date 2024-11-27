/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:16:17 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/27 15:27:53 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

static t_intersect	calc_intersection(t_coef coef)
{
	t_intersect	list;

	ft_bzero(&list, sizeof(t_intersect));
	if (coef.discrim < 0)
		return (list);
	list.count = 2;
	list.t1 = ((coef.b * -1) - sqrt(coef.discrim)) / (2 * coef.a);
	list.t2 = ((coef.b * -1) + sqrt(coef.discrim)) / (2 * coef.a);
	return (list);
}

static t_coef	calc_coef(t_sphere *sphere, t_ray ray)
{
	t_coef	coef;
	double	*sphere_to_ray;

	sphere_to_ray = sub(ray.origin, sphere->origin);
	coef.a = dot_prod(ray.direction, ray.direction);
	coef.b = 2 * dot_prod(ray.direction, sphere_to_ray);
	coef.c = dot_prod(sphere_to_ray, sphere_to_ray) - 1;
	coef.discrim = pow(coef.b, 2) - 4 * coef.a * coef.c;
	return (coef);
}

void	add2list(t_lst_inter **head, t_intersect value, t_sphere *s)
{
	t_lst_inter	*new1;
	t_lst_inter	*new2;
	t_lst_inter	*current;
	t_lst_inter	*prev;

	prev = NULL;
	current = *head;
	if (!(*head))
	{
		initialize_head(head, value, s);
		return ;
	}
	new1 = allocate(sizeof(t_lst_inter));
	new2 = allocate(sizeof(t_lst_inter));
	new1->pos = value.t1;
	new2->pos = value.t2;
	insert_into_list(head, new1, new2);
	while (current)
	{
		current->prev = prev;
		prev = current;
		current = current->next;
	}
}

t_lst_inter	*intersect(t_sphere *sphere, t_ray ray)
{
	t_coef		coef;
	t_intersect	value;
	t_lst_inter	**list;

	if (!sphere)
		error("Error\n", "Sphere doesn't exist", NULL, ERROR);
	coef = calc_coef(sphere, ray);
	value = calc_intersection(coef);
	list = allocate(sizeof(t_lst_inter *));
	if (value.count != 0)
		add2list(list, value, sphere);
	return (*list);
}
