/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Light_and_Shading.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:52:08 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/11 12:50:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_AND_SHADING_H
# define LIGHT_AND_SHADING_H

# include "Colors.h"
# include "Matrices.h"
// # include "Sphere.h"
# include "Objects.h"

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
}				t_pt_pos;

double			*normal_at(t_shape *shape, double *wld_pt);
double			*normal_at_sphere(t_shape *shape, double *wld_pt);

double			*reflect(double *in, double *normal);

t_pt_light		pt_light(double *pos, t_colors intens);

t_colors		lighting(t_material m, t_pt_light light, t_pt_pos pt,
					t_sight sig);

#endif
