/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Determinant_Bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:00:27 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:38:51 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices_Bonus.h"

static double	det_2x2(t_matrix matrix);
static double	det_aux(t_matrix matrix);

/**
 * @brief Calculate the determinant of a 2x2 matrix
 *
 * This function calculates the determinant of a 2x2 matrix using the formula:
 * det(A) = ad - bc
 *
 * @param matrix The 2x2 matrix
 * @return The determinant of the matrix
 */
static double	det_2x2(t_matrix matrix)
{
	double	el_a;
	double	el_b;
	double	el_c;
	double	el_d;

	el_a = get_val_pos(0, 0, matrix);
	el_b = get_val_pos(0, 1, matrix);
	el_c = get_val_pos(1, 0, matrix);
	el_d = get_val_pos(1, 1, matrix);
	return ((el_a * el_d) - (el_b * el_c));
}

/**
 * @brief Auxiliary function to calculate the determinant of a matrix
 *
 * This function calculates the determinant of a matrix using cofactors.
 *
 * @param matrix The matrix
 * @return The determinant of the matrix
 */
static double	det_aux(t_matrix matrix)
{
	double	res[4];

	res[0] = cofactor(matrix, 0, 0) * get_val_pos(0, 0, matrix);
	res[1] = cofactor(matrix, 0, 1) * get_val_pos(0, 1, matrix);
	res[2] = cofactor(matrix, 0, 2) * get_val_pos(0, 2, matrix);
	if (matrix.col == 4)
		res[3] = cofactor(matrix, 0, 3) * get_val_pos(0, 3, matrix);
	else
		res[3] = 0;
	return (res[0] + res[1] + res[2] + res[3]);
}

/**
 * @brief Calculate the determinant of a matrix
 *
 * This function calculates the determinant of a matrix. It handles
 * both 2x2 matrices
 * and larger matrices, ensuring the matrix is square.
 *
 * @param matrix The matrix
 * @return The determinant of the matrix
 */
double	det(t_matrix matrix)
{
	if (matrix.col == 2 && matrix.row == 2)
		return (det_2x2(matrix));
	else if (matrix.col != matrix.row)
		error("Error\n", "Not a quadratic matrix", "", 1);
	return (det_aux(matrix));
}
