/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cone_Bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:16:21 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:39:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections_Bonus.h"

t_cn	*create_cn(void)
{
	t_cn		*cn;
	t_pool_set	*set;

	set = get_pool();
	cn = (t_cn *)alloc_pool(sizeof(t_cn), set->the_pool);
	cn->src = point(0, 0, 0);
	cn->radius = 1;
	cn->min = INT32_MIN;
	cn->max = INT32_MAX;
	cn->closed = false;
	return (cn);
}
