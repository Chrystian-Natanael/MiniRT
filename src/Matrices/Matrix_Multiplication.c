/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_Multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:23:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/15 11:27:40 by tmalheir         ###   ########.fr       */
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

static double	calculate_matrix_tuple(t_matrix matrix, double *tuple, int ir)
{
	int		idx;
	double	res;

	idx = -1;
	res = 0;
	while (++idx < matrix.row)
		res += get_value_pos(ir, idx, matrix) * tuple[idx];
	return (res);
}

double	*matrix_tuple_multiply(t_matrix matrix, double *tuple)
{
	double	*res;
	double	axis[4];

	if (matrix.col != 4)
		error("Not possible to multiply", NULL, NULL, 1);
	axis[X] = calculate_matrix_tuple(matrix, tuple, 0);
	axis[Y] = calculate_matrix_tuple(matrix, tuple, 1);
	axis[Z] = calculate_matrix_tuple(matrix, tuple, 2);
	axis[W] = calculate_matrix_tuple(matrix, tuple, 3);
	res = create_tuple(axis[X], axis[Y], axis[Z], axis[W]);
	return (res);
}

t_matrix	matrix_multiply(t_matrix matrix_a, t_matrix matrix_b)
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
			set_value_pos(pos, calculate(matrix_a, matrix_b, ir, ic), &res);
		}
	}
	res.col = matrix_b.col;
	res.row = matrix_a.row;
	return (res);
}
