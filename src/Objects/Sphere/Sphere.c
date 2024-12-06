/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:08 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 11:06:29 by cnatanae         ###   ########.fr       */
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
	sp->inv = inv(sp->transf);
	return (sp);
}

void	set_transf(t_sp *s, t_matrix t)
{
	s->transf = t;
	s->inv = inv(s->transf);
	return ;
}
