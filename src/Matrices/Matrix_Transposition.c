/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_Transposition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:40:58 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/08 15:18:35 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

/**
 * @brief Transpose a matrix
 *
 * This function transposes the given matrix, which means it flips the matrix
 * over its diagonal, switching the row and column indices of the matrix.
 *
 * @param matrix The matrix to be transposed
 * @return The transposed matrix
 */
t_matrix	transp_mtx(t_matrix matrix)
{
	int			ir;
	int			ic;
	int			pos_t;
	double		vl_pos_m;
	t_matrix	transp;

	init_mtx(&transp);
	transp.col = matrix.row;
	transp.row = matrix.col;
	ir = -1;
	while (++ir < matrix.row)
	{
		ic = -1;
		while (++ic < matrix.col)
		{
			vl_pos_m = get_val_pos(ir, ic, matrix);
			pos_t = get_pos(ic, ir, matrix.row);
			set_val(pos_t, vl_pos_m, &transp);
		}
	}
	return (transp);
}
