/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:16:17 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 13:09:30 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

static t_intersec	*calc_intersection(t_coef coef)
{
	t_intersec	*list;

	list = allocate(sizeof(t_intersec));
	if (coef.discrim < 0)
		return (list);
	list->intersections = allocate(sizeof(double) * 2);
	list->count = 2;
	list->intersections[0] = ((coef.b * -1) - sqrt(coef.discrim)) / (2
			* coef.a);
	list->intersections[1] = ((coef.b * -1) + sqrt(coef.discrim)) / (2
			* coef.a);
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

t_intersec	*intersect(t_sphere *sphere, t_ray ray)
{
	t_coef	coef;

	if (!sphere)
		error("Error\n", "Sphere doesn't exist", NULL, ERROR);
	coef = calc_coef(sphere, ray);
	return (calc_intersection(coef));
}
