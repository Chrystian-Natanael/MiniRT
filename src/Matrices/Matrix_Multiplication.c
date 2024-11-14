/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_Multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:23:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/14 16:06:57 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"
#include "libft.h"

static double	calculate(t_matrix mtx_a, t_matrix mtx_b, int ir, int ic)
{
	int		idx;
	double	res;

	idx = -1;
	res = 0;
	while (++idx < mtx_a.col)
		res += get_value_pos(ir, idx, mtx_a) * get_value_pos(idx, ic, mtx_b);
	return (res);
}

t_matrix	matrix_multiply(t_matrix matrix_a, t_matrix matrix_b)
{
	int			ir;
	int			ic;
	int			pos;
	t_matrix	res;

	if (matrix_a.col != matrix_b.row)
		error("Not possible to multiply", NULL, NULL, 1);
	ft_bzero(&res, sizeof(t_matrix));
	ir = -1;
	while (++ir < matrix_a.row)
	{
		ic = -1;
		while (++ic < matrix_b.col)
		{
			pos = get_pos(ir, ic, matrix_a.col);
			set_value_pos(pos, calculate(matrix_a, matrix_b, ir, ic), &res);
		}
	}
	return (res);
}
