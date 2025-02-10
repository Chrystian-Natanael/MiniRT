/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_shadowed_Bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:15:19 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:42:20 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes_Bonus.h"

bool	is_shadowed(t_world *world, double *pos, t_pt_light light)
{
	double	dist_pt_to_light;
	double	*dir;
	t_ray	ray;
	t_inter	*hit_lst;
	t_inter	*hit_pt;

	dist_pt_to_light = mag(sub(world->lights_lst->light_src.pos, pos));
	dir = norm(sub(light.pos, pos));
	ray = create_ray(pos, dir);
	hit_lst = intersect_world(world, ray);
	hit_pt = hit(hit_lst);
	if (hit_pt && hit_pt->next && hit_pt->next->pos < dist_pt_to_light)
		return (true);
	return (false);
}
