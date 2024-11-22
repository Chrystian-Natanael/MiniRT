/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:34:30 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 10:53:43 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

/**
 * @brief Calculate the minor of a matrix element
 *
 * This function calculates the minor of a matrix element at the specified row
 * and column. The minor is the determinant of the submatrix that remains after
 * removing the specified row and column from the original matrix.
 *
 * @param matrix The original matrix
 * @param sub_r The row index to be removed
 * @param sub_c The column index to be removed
 * @return The determinant of the submatrix, which is the minor of the element
 */
double	minor(t_matrix matrix, int sub_r, int sub_c)
{
	t_matrix	submatrix;

	submatrix = submtx(matrix, sub_r, sub_c);
	return (det(submatrix));
}
