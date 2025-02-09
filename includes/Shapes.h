/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:17 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/08 19:17:58 by cnatanae         ###   ########.fr       */
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

typedef struct s_cn
{
	double	*src;
	double	radius;
	double	max;
	double	min;
	bool	closed;
}	t_cn;

t_sp	*create_sp(void);
t_pl	*create_pl(void);
t_cl	*create_cl(void);
t_cn	*create_cn(void);

#endif
