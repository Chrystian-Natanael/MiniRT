/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:40:12 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/08 15:13:48 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "Utils.h"
# include "Tuples.h"

typedef struct s_matrix
{
	int		row;
	int		col;
	double	content[16];
}			t_matrix;

t_matrix	create_mtx(int row, int col, double *elements);
void		init_mtx(t_matrix *mtx);
bool		comp_mtx(t_matrix mtx_a, t_matrix mtx_b);
t_matrix	multiply_mtx(t_matrix matrix_a, t_matrix matrix_b);
double		*multiply_mtx_tp(t_matrix matrix, double *tuple);
t_matrix	transp_mtx(t_matrix matrix);
t_matrix	id_mtx(void);

int			get_pos(int x, int y, int col);
void		set_val(int pos, double value, t_matrix *matrix);
double		get_val_pos(int x, int y, t_matrix matrix);

double		det(t_matrix matrix);
t_matrix	submtx(t_matrix matrix, int sub_r, int sub_c);
double		minor(t_matrix matrix, int sub_r, int sub_c);
double		cofactor(t_matrix matrix, int sub_r, int sub_c);
t_matrix	inv(t_matrix matrix);
t_matrix	translate(double x, double y, double z);
t_matrix	scale(double x, double y, double z);
t_matrix	rotate_x(double rad);
t_matrix	rotate_y(double rad);
t_matrix	rotate_z(double rad);

#endif // ! MATRICES_H