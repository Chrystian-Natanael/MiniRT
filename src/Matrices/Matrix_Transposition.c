/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_Transposition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:40:58 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/15 13:40:47 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

t_matrix	matrix_transpose(t_matrix matrix)
{
	int			ir;
	int			ic;
	int			pos_t;
	double		vl_pos_m;
	t_matrix	transp;

	ft_bzero(&transp, sizeof(t_matrix));
	transp.col = matrix.row;
	transp.row = matrix.col;
	ir = -1;
	while (++ir < matrix.row)
	{
		ic = -1;
		while (++ic < matrix.col)
		{
			vl_pos_m = get_value_pos(ir, ic, matrix);
			pos_t = get_pos(ic, ir, matrix.row);
			set_value_pos(pos_t, vl_pos_m, &transp);
		}
	}
	return (transp);
}
