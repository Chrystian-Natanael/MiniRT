/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stripes_Bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:20:47 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:43:22 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns_Bonus.h"

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
