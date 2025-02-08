/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:20:47 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/08 11:52:33 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns.h"

t_pattern	checker_pattern(t_colors ca, t_colors cb)
{
	t_pattern	pattern;

	pattern.c1 = ca;
	pattern.c2 = cb;
	pattern.flag = true;
	pattern.inv = id_mtx();
	pattern.transf = id_mtx();
	pattern.id = CHECKER;
	return (pattern);
}

t_colors	checker_at(t_pattern pattern, double *point)
{
	int	sum;
	int	color_mod;

	sum = ((int)floor(point[0]) + (int)floor(point[1]) + (int)floor(point[2]));
	if (sum % 2 == 0)
		color_mod = 0;
	else
		color_mod = 1;
	if (point[Z] < 0)
		color_mod = !color_mod;
	if (color_mod)
		return (pattern.c1);
	return (pattern.c2);
}
