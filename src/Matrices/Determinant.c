/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:00:27 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/15 14:12:21 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

double	determinant(t_matrix matrix)
{
	double	el_a;
	double	el_b;
	double	el_c;
	double	el_d;

	el_a = get_value_pos(0, 0, matrix);
	el_b = get_value_pos(0, 1, matrix);
	el_c = get_value_pos(1, 0, matrix);
	el_d = get_value_pos(1, 1, matrix);
	return ((el_a * el_d) - (el_b * el_c));
}
