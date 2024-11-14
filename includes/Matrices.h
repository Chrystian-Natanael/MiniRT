/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:40:12 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/14 16:09:48 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <stdbool.h>
# include "Error.h"
# include "Tuples.h"

typedef struct s_matrix
{
	int		row;
	int		col;
	double	content[16];
}		t_matrix;

t_matrix	create_matrix(int row, int col, double *elements);
bool		compare_matrix(t_matrix mtx_a, t_matrix mtx_b);
t_matrix	matrix_multiply(t_matrix matrix_a, t_matrix matrix_b);

int			get_pos(int x, int y, int col);
void		set_value_pos(int pos, double value, t_matrix *matrix);
double		get_value_pos(int x, int y, t_matrix matrix);

#endif // ! MATRICES_H