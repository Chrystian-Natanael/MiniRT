/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Light_Bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:36:02 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:46:17 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser_Bonus.h"
#include "Tuples_Bonus.h"

bool	parse_light(char *line, t_world *world)
{
	double		*norm_col;
	double		*pos;
	char		**info;
	t_pt_light	light;

	world->scene.has_light += 1;
	info = ft_split(line, ' ');
	if (!check_count(info, 4) || !parse_pos(info[1]) || !is_double(info[2])
		|| !in_range_double(info[2]) || !parse_color(info[3]))
		return (true_or_false(info, false));
	norm_col = allocate(sizeof(double) * 3);
	norm_col = normalize_rgb_to_double(info[3]);
	pos = allocate(sizeof(double) * 3);
	pos = pos_to_double(info[1]);
	world->scene.light_pos = create_tp(pos[X], pos[Y], pos[Z], POINT);
	light = pt_light(world->scene.light_pos, multiply_col(create_color
				(norm_col[X], norm_col[Y], norm_col[Z]), ft_atod(info[2])));
	insert_into_light_list(&world->lights_lst, light);
	return (true_or_false(info, true));
}
