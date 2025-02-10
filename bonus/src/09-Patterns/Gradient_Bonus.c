/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gradient_Bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:28:27 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:43:27 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns_Bonus.h"

t_pattern	gradient_pattern(t_colors ca, t_colors cb)
{
	t_pattern	pattern;

	pattern.c1 = ca;
	pattern.c2 = cb;
	pattern.flag = true;
	pattern.inv = id_mtx();
	pattern.transf = id_mtx();
	pattern.id = GRADIENT;
	return (pattern);
}

t_colors	gradient_at(t_pattern pattern, double *point)
{
	t_colors	dist;
	double		fraction;

	dist = sub_colors(pattern.c2, pattern.c1);
	if (fmod(fabs(point[0]), 2) >= 1)
		fraction = 1 - fmod(fabs(point[0]), 1);
	else
		fraction = fmod(fabs(point[0]), 1);
	return (sum_colors((multiply_col(dist, fraction)), pattern.c1));
}
