/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:40:12 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/14 11:19:33 by tmalheir         ###   ########.fr       */
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

#endif // ! MATRICES_H