/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ring_Bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:28:27 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:43:24 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns_Bonus.h"

t_pattern	ring_pattern(t_colors ca, t_colors cb)
{
	t_pattern	pattern;

	pattern.c1 = ca;
	pattern.c2 = cb;
	pattern.flag = true;
	pattern.inv = id_mtx();
	pattern.transf = id_mtx();
	pattern.id = RING;
	return (pattern);
}

t_colors	ring_at(t_pattern pattern, double *point)
{
	double	sum;

	sum = ((point[0] * point[0]) + (point[2] * point[2]));
	if ((int)floor(sqrt(sum)) % 2 == 0)
		return (pattern.c1);
	return (pattern.c2);
}
