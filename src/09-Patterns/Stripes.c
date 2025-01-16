/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stripes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:20:47 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/16 10:27:35 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns.h"

t_pattern	stripe_pattern(t_colors ca, t_colors cb)
{
	t_pattern	pattern;

	pattern.c1 = ca;
	pattern.c2 = cb;
	pattern.flag = true;
	pattern.inv = id_mtx();
	pattern.transf = id_mtx();
	pattern.id = STRIPES;
	return (pattern);
}

t_colors	stripe_at(t_pattern pattern, double *point)
{
	if (((int)floor(point[0]) % 2 == 0))
		return (pattern.c1);
	return (pattern.c2);
}
