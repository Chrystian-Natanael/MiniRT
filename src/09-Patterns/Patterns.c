/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:56:56 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/15 15:28:47 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns.h"

void	init_pattern(t_pattern *pattern)
{
	pattern->flag = true;
	pattern->inv = id_mtx();
	pattern->transf = id_mtx();
}

void	set_pattern_transf(t_pattern *pattern, t_matrix t)
{
	pattern->transf = t;
	pattern->inv = inv(t);
}
