/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Light_and_Shading.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:52:08 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/09 11:45:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_AND_SHADING_H
# define LIGHT_AND_SHADING_H

# include "Colors.h"
# include "Matrices.h"
# include "Sphere.h"

typedef struct s_pt_light
{
	double		*pos;
	t_colors	*intensity;
}				t_pt_light;

typedef struct s_light_aux
{
	t_colors	*ambient;
	t_colors	*diffuse;
	t_colors	*specular;
	t_colors	*effective_color;
	double		*lightv;
	double		light_dot_normal;
	double		*reflectv;
	double		reflect_dot_eye;
	double		factor;
}				t_light_aux;

typedef struct s_sight
{
	double	*eye;
	double	*normal;
}			t_sight;

double		*normal_at(t_sp *sp, double *wld_pt);

double		*reflect(double *in, double *normal);

t_pt_light	pt_light(double *pos, t_colors *intensity);

t_colors	*lighting(t_material m, t_pt_light light, double *pos, t_sight sig);

#endif
