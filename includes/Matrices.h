/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:40:12 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/15 14:29:52 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "Error.h"
# include "Tuples.h"
# include <stdbool.h>

typedef struct s_matrix
{
	int		row;
	int		col;
	double	content[16];
}			t_matrix;

t_matrix	create_matrix(int row, int col, double *elements);
bool		compare_matrix(t_matrix mtx_a, t_matrix mtx_b);
t_matrix	matrix_multiply(t_matrix matrix_a, t_matrix matrix_b);
double		*matrix_tuple_multiply(t_matrix matrix, double *tuple);
t_matrix	matrix_transpose(t_matrix matrix);

int			get_pos(int x, int y, int col);
void		set_value_pos(int pos, double value, t_matrix *matrix);
double		get_value_pos(int x, int y, t_matrix matrix);

double		determinant(t_matrix matrix);
t_matrix	submatrix(t_matrix matrix, int sub_r, int sub_c);

#endif // ! MATRICES_H