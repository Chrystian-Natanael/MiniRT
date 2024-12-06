/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:47:07 by cnatanae          #+#    #+#             */
/*   Updated: 2024/12/06 16:18:47 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Light_and_Shading.h"

double	*reflect(double *in, double *normal)
{
	double	*reflection;

	reflection = multiply(normal, 2);
	reflection = multiply(reflection, dot_prod(in, normal));
	return (sub(in, reflection));
}

t_pt_light	pt_light(double *pos, t_colors *intensity)
{
	t_pt_light	light;

	light.pos = pos;
	light.intensity = intensity;
	return (light);
}

t_colors	*lighting(t_material m, t_pt_light light, double *pos, t_sight sig)
{
	return (create_color(1, 1, 1));
}
