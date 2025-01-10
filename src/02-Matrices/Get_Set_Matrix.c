/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Set_Matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:39:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 10:46:32 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

/**
 * @brief Calculates the cross product of two vectors
 *
 * This function calculates the cross product of two vectors. If either vector
 * is null or is a point, an error message is displayed and the
 * program is terminated.
 *
 * @param vector1 The first vector
 * @param vector2 The second vector
 * @return A pointer to the resulting vector after the cross product operation
 */
int	get_pos(int x, int y, int col)
{
	return (x * col + y);
}

/**
 * @brief Calculates the cross product of two vectors
 *
 * This function calculates the cross product of two vectors. If either vector
 * is null or is a point, an error message is displayed and the
 * program is terminated.
 *
 * @param vector1 The first vector
 * @param vector2 The second vector
 * @return A pointer to the resulting vector after the cross product operation
 */
double	get_val_pos(int x, int y, t_matrix matrix)
{
	return (matrix.content[x * matrix.col + y]);
}

/**
 * @brief Set the value at a specific position in a matrix
 *
 * This function sets the value at the specified position in the given matrix.
 *
 * @param pos The position in the matrix
 * @param value The value to set
 * @param matrix The matrix in which to set the value
 */
void	set_val(int pos, double value, t_matrix *matrix)
{
	matrix->content[pos] = value;
}
