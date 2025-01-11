/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:51 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/11 12:51:01 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Objects.h"

void	init_shape(t_shape_id id, t_shape **shape)
{
	t_pool_set	*set;

	set = get_pools();
	*shape = (t_shape *)alloc_pool(sizeof(t_shape), set->objects);
	(*shape)->inv = id_mtx();
	(*shape)->transp = id_mtx();
	(*shape)->material = material();
	(*shape)->transf = id_mtx();
	if (id == SPHERE)
	{
		(*shape)->obj = create_sp();
		(*shape)->id = SPHERE;
	}
}
