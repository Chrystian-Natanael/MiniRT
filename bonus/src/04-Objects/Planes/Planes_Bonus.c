/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Planes_Bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:09:35 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:40:18 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Objects_Bonus.h"

t_pl	*create_pl(void)
{
	t_pl		*pl;
	t_pool_set	*set;

	set = get_pool();
	pl = (t_pl *)alloc_pool(sizeof(t_pl), set->the_pool);
	pl->src = point(0, 0, 0);
	return (pl);
}
