/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:08 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/04 10:04:50 by tmalheir         ###   ########.fr       */
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
	return (sphere);
}

void	set_transform(t_sphere *s, t_matrix t)
{
	s->transform = t;
	return ;
}
