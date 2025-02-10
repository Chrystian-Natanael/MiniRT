/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Light_and_Shading_Bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:52:08 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 08:14:32 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_AND_SHADING_BONUS_H
# define LIGHT_AND_SHADING_BONUS_H

# include "Colors_Bonus.h"
# include "Matrices_Bonus.h"
# include "Objects_Bonus.h"

typedef struct s_pt_light
{
	double		*pos;
	t_colors	intens;
}				t_pt_light;

typedef struct s_light_aux
{
	t_colors	ambient;
	t_colors	diffu;
	t_colors	spec;
	t_colors	eff_col;
	double		*lightv;
	double		light_dtn;
	double		*reflectv;
	double		reflect_dot_eye;
	double		factor;
}				t_light_aux;

typedef struct s_sight
{
	double		*eye;
	double		*normal;
}				t_sight;

typedef struct s_pt_pos
{
	double	*pos;
	bool	in_shadow;
}			t_pt_pos;

double			*normal_at(t_shape *shape, double *wld_pt);
double			*normal_at_sphere(t_shape *shape, double *wld_pt);
double			*normal_at_cylinder(t_shape *shape, double *wld_pt);

double			*reflect(double *in, double *normal);

t_pt_light		pt_light(double *pos, t_colors intens);

t_colors		lighting(t_shape *shape, t_pt_light light, t_pt_pos pt,
					t_sight sig);

#endif
