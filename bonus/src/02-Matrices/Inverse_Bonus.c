/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inverse_Bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:20:00 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:38:47 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices_Bonus.h"

static t_matrix	inv_aux(t_matrix matrix);

/**
 * @brief Auxiliary function to calculate the inverse of a matrix
 *
 * This function calculates the inverse of a matrix using cofactors and the
 * determinant of the matrix.
 *
 * @param matrix The matrix to be inverted
 * @return A matrix that is the inverse of the input matrix
 */
static t_matrix	inv_aux(t_matrix matrix)
{
	double		det_mtx;
	int			ir;
	int			ic;
	double		value;
	t_matrix	inv;

	init_mtx(&inv);
	det_mtx = det(matrix);
	ir = -1;
	inv.col = matrix.col;
	inv.row = matrix.row;
	while (++ir < matrix.row)
	{
		ic = -1;
		while (++ic < matrix.col)
		{
			value = cofactor(matrix, ir, ic) / det_mtx;
			set_val(get_pos(ic, ir, inv.col), value, &inv);
		}
	}
	return (inv);
}

/**
 * @brief Calculate the inverse of a matrix
 *
 * (OBS: return identity matrix in det = 0)
 * This function calculates the inverse of a matrix. If the determinant of the
 * matrix is zero, an error message is displayed and the program is terminated.
 *
 * @param matrix The matrix to be inverted
 * @return A matrix that is the inverse of the input matrix
 */
t_matrix	inv(t_matrix matrix)
{
	if (det(matrix) == 0)
		error("Error\n", "Impossible to calculate inverse of NULL mtx", "", 1);
	return (inv_aux(matrix));
}
