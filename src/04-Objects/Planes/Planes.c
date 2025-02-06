/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:09:35 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/06 11:25:29 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Objects.h"

t_pl	*create_pl(void)
{
	t_pl		*pl;
	t_pool_set	*set;

	set = get_pool();
	pl = (t_pl *)alloc_pool(sizeof(t_pl), set->the_pool);
	pl->src = point(0, 0, 0);
	return (pl);
}
