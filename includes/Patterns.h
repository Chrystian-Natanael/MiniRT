/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patterns.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:36:07 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/16 11:55:07 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "Matrices.h"
# include "Colors.h"
# include <math.h>
# include <stdbool.h>

typedef enum e_pattern_id
{
	STRIPES,
	GRADIENT,
	RING,
	CHECKER,
}			t_pattern_id;

typedef struct s_pattern
{
	t_colors		c1;
	t_colors		c2;
	bool			flag;
	t_matrix		inv;
	t_matrix		transf;
	t_pattern_id	id;
}				t_pattern;

void		set_pattern_transf(t_pattern *pattern, t_matrix t);
t_pattern	stripe_pattern(t_colors ca, t_colors cb);
t_colors	stripe_at(t_pattern pattern, double *point);
t_pattern	gradient_pattern(t_colors ca, t_colors cb);
t_colors	gradient_at(t_pattern pattern, double *point);
t_pattern	ring_pattern(t_colors ca, t_colors cb);
t_colors	ring_at(t_pattern pattern, double *point);
t_pattern	checker_pattern(t_colors ca, t_colors cb);
t_colors	checker_at(t_pattern pattern, double *point);

#endif