/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:20:00 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/20 12:13:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

static t_matrix	inverse_aux(t_matrix matrix);

static t_matrix	inverse_aux(t_matrix matrix)
{
	double		det_mtx;
	int			ir;
	int			ic;
	double		value;
	t_matrix	inv;

	ft_bzero(&inv, sizeof(t_matrix));
	det_mtx = determinant(matrix);
	ir = -1;
	inv.col = matrix.col;
	inv.row = matrix.row;
	while (++ir < matrix.row)
	{
		ic = -1;
		while (++ic < matrix.col)
		{
			value = cofactor(matrix, ir, ic) / det_mtx;
			set_value_pos(get_pos(ic, ir, inv.col), value, &inv);
		}
	}
	return (inv);
}

t_matrix	inverse(t_matrix matrix)
{
	if (determinant(matrix) == 0)
		error("Error\n", "msn", NULL, 1);
	return (inverse_aux(matrix));
}
