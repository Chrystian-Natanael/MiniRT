/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:17 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/10 16:02:43 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "Colors.h"
# include "Matrices.h"
# include "Tuples.h"

typedef struct s_sp
{
	double		*src;
	double		radius;
}				t_sp;

t_sp	*create_sp(void);

#endif
