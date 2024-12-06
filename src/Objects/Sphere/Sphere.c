/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:08 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 10:17:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.h"

t_sp	*create_sp(void)
{
	t_sp	*sp;

	sp = allocate(sizeof(t_sp));
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
