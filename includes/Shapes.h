/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:17 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/13 15:16:07 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "Colors.h"
# include "Matrices.h"
# include "Tuples.h"

typedef struct s_sp
{
	double		*src;
	double		radius;
}				t_sp;

typedef struct s_pl
{
	double	*src;
}			t_pl;

typedef struct s_cl
{
	double	*src;
	double	radius;
	double	max;
	double	min;
	bool	closed;
}			t_cl;

t_sp	*create_sp(void);
t_pl	*create_pl(void);
t_cl	*create_cl(void);

#endif
