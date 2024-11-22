/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:34:30 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 10:38:57 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

double	minor(t_matrix matrix, int sub_r, int sub_c)
{
	t_matrix	submatrix;

	submatrix = submtx(matrix, sub_r, sub_c);
	return (det(submatrix));
}
