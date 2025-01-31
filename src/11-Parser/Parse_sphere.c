/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:49 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/30 15:26:30 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

bool	parse_sphere(char *line, t_world *world)
{
	double		*norm_col;
	double		*pos;
	char		**info;

	info = ft_split(line, ' ');
	if (!check_count(info, 4) || !parse_pos(info[1]) || !is_double(info[2])
		|| !parse_color(info[3]))
		return (true_or_false(info, false));
	norm_col = allocate(sizeof(double) * 3);
	norm_col = normalize_rgb_to_double(info[3]);
	pos = allocate(sizeof(double) * 3);
	pos = pos_to_double(info[1]);
	// Lógica para mudar as esferas ou adicionar novas
	set_transf(&world->obj_lst->shape, translate(pos[0], pos[1], pos[2]));
	return (true_or_false(info, true));
}
