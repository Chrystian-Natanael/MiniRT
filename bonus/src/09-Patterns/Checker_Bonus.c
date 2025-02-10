/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker_Bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:20:47 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:43:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns_Bonus.h"

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

	sum = ((int)(point[0]) + (int)(point[1]) + (int)(point[2]));
	if (sum % 2 == 0)
		color_mod = 0;
	else
		color_mod = 1;
	if (point[Z] < 0)
		color_mod = !color_mod;
	if (point[X] < 0)
		color_mod = !color_mod;
	if (color_mod)
		return (pattern.c1);
	return (pattern.c2);
}
