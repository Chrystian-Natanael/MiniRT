/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:08 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 12:53:09 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Objects.h"

t_sp	*create_sp(void)
{
	t_sp		*sp;
	t_pool_set	*set;

	set = get_pool();
	sp = (t_sp *)alloc_pool(sizeof(t_sp), set->the_pool);
	sp->src = point(0, 0, 0);
	sp->radius = 1;
	return (sp);
}
