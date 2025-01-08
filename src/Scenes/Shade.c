/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:56:07 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/08 12:15:50 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"
#include "Scenes.h"

t_colors	shade_hit(t_world *w, t_comp comps)
{
	t_colors	shade_color;
	t_lights	*aux;

	aux = w->lights_lst;
	shade_color = lighting(comps.sp->material, aux->light_src, comps.point,
			comps.sig);
	aux = aux->next;
	while (aux)
	{
		shade_color = sum_colors(shade_color, lighting(comps.sp->material,
					aux->light_src, comps.point, comps.sig));
		aux = aux->next;
	}
	return (shade_color);
}

t_colors	color_at(t_world *w, t_ray r)
{
	t_colors	color_at_hit;
	t_comp		*comps;
	t_inter		*nearest_hit;
	t_inter		*hits;

	color_at_hit = create_color(0, 0, 0);
	hits = intersect_world(w, r);
	nearest_hit = hit(hits);
	if (nearest_hit)
	{
		comps = prepare_computations(nearest_hit, r);
		color_at_hit = shade_hit(w, *comps);
	}
	return (color_at_hit);
}
