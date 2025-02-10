/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Patterns_Bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:56:56 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:43:26 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Patterns_Bonus.h"

void	set_pattern_transf(t_pattern *pattern, t_matrix t)
{
	pattern->transf = t;
	pattern->inv = inv(t);
}
