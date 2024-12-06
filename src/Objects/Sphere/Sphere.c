/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:08 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 09:43:44 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.h"

t_sphere	*create_sphere(void)
{
	t_sphere	*sphere;

	sphere = allocate(sizeof(t_sphere));
	sphere->origin = point(0, 0, 0);
	sphere->radius = 1;
	sphere->transform = id_mtx();
	sphere->inv = inv(sphere->transform);
	return (sphere);
}

void	set_transform(t_sphere *s, t_matrix t)
{
	s->transform = t;
	s->inv = inv(s->transform);
	return ;
}
