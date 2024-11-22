/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_Multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:23:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 10:56:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"
#include "libft.h"

/**
 * @brief Calculate the value of a specific position in the resulting matrix
 *        from the multiplication of two matrices.
 *
 * This function calculates the value of the element at the specified row and
 * column in the resulting matrix by performing the dot product of the row from
 * the first matrix and the column from the second matrix.
 *
 * @param mtx_a The first matrix
 * @param mtx_b The second matrix
 * @param ir The row index in the resulting matrix
 * @param ic The column index in the resulting matrix
 * @return The calculated value for the specified position
 */
static double	calculate(t_matrix mtx_a, t_matrix mtx_b, int ir, int ic)
{
	int		idx;
	double	res;

	idx = -1;
	res = 0;
	while (++idx < mtx_a.col)
		res += get_val_pos(ir, idx, mtx_a) * get_val_pos(idx, ic, mtx_b);
	return (res);
}

/**
 * @brief Multiply two matrices
 *
 * This function multiplies two matrices. If the number of columns in the first
 * matrix is not equal to the number of rows in the second matrix, an error
 * message is displayed and the program is terminated.
 *
 * @param matrix1 The first matrix
 * @param matrix2 The second matrix
 * @return A matrix that is the result of the multiplication of the two
 * input matrices
 */
static double	calculate_matrix_tuple(t_matrix matrix, double *tuple, int ir)
{
	int		idx;
	double	res;

	idx = -1;
	res = 0;
	while (++idx < matrix.row)
		res += get_val_pos(ir, idx, matrix) * tuple[idx];
	return (res);
}

/**
 * @brief Multiply a matrix by a tuple
 *
 * This function multiplies a matrix by a tuple. If the number of columns in the
 * matrix is not equal to 4, an error message is displayed and the program is
 * terminated.
 *
 * @param matrix The matrix
 * @param tuple The tuple
 * @return A tuple that is the result of the multiplication of the
 * matrix and the tuple
 */
double	*multiply_mtx_tp(t_matrix matrix, double *tuple)
{
	double	*res;
	double	axis[4];

	if (matrix.col != 4)
		error("Not possible to multiply", NULL, NULL, 1);
	axis[X] = calculate_matrix_tuple(matrix, tuple, 0);
	axis[Y] = calculate_matrix_tuple(matrix, tuple, 1);
	axis[Z] = calculate_matrix_tuple(matrix, tuple, 2);
	axis[W] = calculate_matrix_tuple(matrix, tuple, 3);
	res = create_tp(axis[X], axis[Y], axis[Z], axis[W]);
	return (res);
}

/**
 * @brief Multiply two matrices
 *
 * This function multiplies two matrices. If the number of columns in the first
 * matrix is not equal to the number of rows in the second matrix, an error
 * message is displayed and the program is terminated.
 *
 * @param matrix1 The first matrix
 * @param matrix2 The second matrix
 * @return A matrix that is the result of the multiplication of
 * the two input matrices
 */
t_matrix	multiply_mtx(t_matrix matrix_a, t_matrix matrix_b)
{
	int			ir;
	int			ic;
	int			pos;
	t_matrix	res;

	if (matrix_a.col != matrix_b.row)
		error("Error\n", "Not possible to multiply", NULL, 1);
	ft_bzero(&res, sizeof(t_matrix));
	ir = -1;
	while (++ir < matrix_a.row)
	{
		ic = -1;
		while (++ic < matrix_b.col)
		{
			pos = get_pos(ir, ic, matrix_a.col);
			set_val(pos, calculate(matrix_a, matrix_b, ir, ic), &res);
		}
	}
	res.col = matrix_b.col;
	res.row = matrix_a.row;
	return (res);
}
