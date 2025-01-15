/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patterns.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:36:07 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/15 10:35:33 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "Matrices.h"
# include "Colors.h"
# include <math.h>
# include <stdbool.h>

typedef struct s_pattern
{
	t_colors	c1;
	t_colors	c2;
	bool		flag;
	t_matrix	transf;
	t_matrix	inv;
}				t_pattern;

t_colors	choose_color(double *point, t_colors ca, t_colors cb);
t_pattern	stripe_pattern(t_colors ca, t_colors cb);
t_colors	stripe_at(t_pattern pattern, double *point);
void		init_pattern(t_pattern *pattern);
void		set_pattern_transf(t_pattern *pattern, t_matrix t);

#endif