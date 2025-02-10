/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrices_Bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:43:54 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:38:45 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices_Bonus.h"

/**
 * @brief Create a matrix with specified rows, columns, and elements
 *
 * This function initializes a matrix with the given number of rows and columns,
 * and fills it with the provided elements. If the elements pointer is NULL or
 * the number of rows or columns is less than one, an error message is displayed
 * and the program is terminated.
 *
 * @param row The number of rows in the matrix
 * @param col The number of columns in the matrix
 * @param elements A pointer to the elements to fill the matrix
 * @return The created matrix
 */
t_matrix	create_mtx(int row, int col, double *elements)
{
	int			ir;
	int			ic;
	t_matrix	matrix;

	init_mtx(&matrix);
	if (!elements)
		error("Error\n", "Empty elements", "", 1);
	if (row < 1 || col < 1)
		error("Error\n", "Rows and cols cannot be lesser than one", "", 1);
	ir = -1;
	matrix.row = row;
	matrix.col = col;
	while (++ir < row)
	{
		ic = -1;
		while (++ic < col)
		{
			matrix.content[get_pos(ir, ic, col)] = *elements;
			elements++;
		}
	}
	return (matrix);
}

/**
 * @brief Compare two matrices for equality
 *
 * This function compares two matrices to check if they are equal. If the number
 * of rows or columns in the matrices are different, or if any corresponding
 * elements are not equal, the function returns false.
 * Otherwise, it returns true.
 *
 * @param mtx_a The first matrix
 * @param mtx_b The second matrix
 * @return true if the matrices are equal, false otherwise
 */
bool	comp_mtx(t_matrix mtx_a, t_matrix mtx_b)
{
	int	ir;
	int	ic;
	int	pos;

	if (mtx_a.row != mtx_b.row || mtx_a.col != mtx_b.col)
		return (false);
	ir = -1;
	while (++ir < mtx_a.row)
	{
		ic = -1;
		while (++ic < mtx_a.col)
		{
			pos = get_pos(ir, ic, mtx_a.col);
			if (!equal(mtx_a.content[pos], mtx_b.content[pos]))
				return (false);
		}
	}
	return (true);
}

void	init_mtx(t_matrix *mtx)
{
	int	i;

	mtx->col = 0;
	mtx->row = 0;
	i = -1;
	while (++i < 16)
		mtx->content[i] = 0;
}

/**
 * @brief Create an identity matrix
 *
 * This function creates a 4x4 identity matrix, which is a square matrix with
 * ones on the main diagonal and zeros elsewhere.
 *
 * @return The created identity matrix
 */
t_matrix	id_mtx(void)
{
	static double	elements[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		1};

	return (create_mtx(4, 4, elements));
}
