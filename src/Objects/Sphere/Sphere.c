/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:08 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 14:20:10 by tmalheir         ###   ########.fr       */
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
	sp->transp = transp_mtx(sp->inv);
	return (sp);
}

void	set_transf(t_sp *s, t_matrix t)
{
	s->transf = t;
	s->inv = inv(s->transf);
	s->transp = transp_mtx(s->inv);
	return ;
}
