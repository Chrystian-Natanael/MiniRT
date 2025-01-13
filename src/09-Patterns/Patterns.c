/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:56:56 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/13 16:25:30 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns.h"

t_colors	choose_color(double *point, t_colors ca, t_colors cb)
{
	int	x;

	x = (int)floor(point[0]);
	if (x % 2 == 0)
		return (ca);
	else
		return (cb);
}

t_pattern	stripe_pattern(t_colors ca, t_colors cb)
{
	t_pattern	pattern;

	pattern.c1 = ca;
	pattern.c2 = cb;
	return (pattern);
}

t_colors	stripe_at(t_pattern pattern, double *point)
{
	pattern.c1 = create_color(1, 1, 1);
	pattern.c2 = create_color(0, 0, 0);
	return (choose_color(point, pattern.c1, pattern.c2));
}
