/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:08 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/07 07:25:06 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.h"

t_sp	*create_sp(void)
{
	t_sp		*sp;
	t_pool_set	*set;

	set = get_pools();
	sp = (t_sp *)alloc_pool(sizeof(t_sp), set->objects);
	sp->src = point(0, 0, 0);
	sp->radius = 1;
	sp->transf = id_mtx();
	sp->inv = id_mtx();
	sp->transp = id_mtx();
	sp->material = material();
	return (sp);
}

void	set_transf(t_sp *s, t_matrix t)
{
	s->transf = t;
	s->inv = inv(s->transf);
	s->transp = transp_mtx(s->inv);
	return ;
}

t_material	material(void)
{
	t_material	material;

	material.color = create_color(1, 1, 1);
	material.ambient = create_color(0.1, 0.1, 0.1);
	material.diffu = create_color(0.9, 0.9, 0.9);
	material.spec = create_color(0.9, 0.9, 0.9);
	material.shininess = 200;
	return (material);
}
