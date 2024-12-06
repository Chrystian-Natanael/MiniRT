/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:17 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 10:17:44 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "Matrices.h"
# include "Tuples.h"

typedef struct s_sp
{
	double		*src;
	double		radius;
	t_matrix	transf;
	t_matrix	inv;
}				t_sp;

t_sp			*create_sp(void);
void			set_transf(t_sp *s, t_matrix t);

#endif