/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:49:50 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 10:47:48 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

/**
 * @brief Calculate the cofactor of a matrix element
 *
 * This function calculates the cofactor of an element in a matrix. The
 * cofactor is
 * determined by the minor of the element and its position.
 *
 * @param matrix The matrix
 * @param sub_r The row index of the element
 * @param sub_c The column index of the element
 * @return The cofactor of the element
 */
double	cofactor(t_matrix matrix, int sub_r, int sub_c)
{
	double	minor_submtx;

	minor_submtx = minor(matrix, sub_r, sub_c);
	if ((sub_r + sub_c) % 2 != 0)
		return (minor_submtx * -1);
	return (minor_submtx);
}
