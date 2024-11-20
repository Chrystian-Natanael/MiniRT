/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:00:27 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/20 11:06:10 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

static double	determinant_2x2(t_matrix matrix);
static double	determinant_aux(t_matrix matrix);

static double	determinant_2x2(t_matrix matrix)
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

static double	determinant_aux(t_matrix matrix)
{
	double	res[4];

	res[0] = cofactor(matrix, 0, 0) * get_value_pos(0, 0, matrix);
	res[1] = cofactor(matrix, 0, 1) * get_value_pos(0, 1, matrix);
	res[2] = cofactor(matrix, 0, 2) * get_value_pos(0, 2, matrix);
	if (matrix.col == 4)
		res[3] = cofactor(matrix, 0, 3) * get_value_pos(0, 3, matrix);
	else
		res[3] = 0;
	return (res[0] + res[1] + res[2] + res[3]);
}

double	determinant(t_matrix matrix)
{
	if (matrix.col == 2 && matrix.row == 2)
		return (determinant_2x2(matrix));
	else if (matrix.col != matrix.row)
		error("Error\n", "Not a quadratic matrix", NULL, 1);
	return (determinant_aux(matrix));
}
