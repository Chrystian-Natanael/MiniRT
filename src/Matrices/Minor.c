/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:34:30 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/18 11:42:36 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

double	minor(t_matrix matrix, int sub_r, int sub_c)
{
	t_matrix	submtx;

	submtx = submatrix(matrix, sub_r, sub_c);
	return (determinant(submtx));
}
