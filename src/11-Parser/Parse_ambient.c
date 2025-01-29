/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:36:02 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/29 16:13:10 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

bool	parse_ambient(char *line, t_world *world)
{
	double		*norm_col;
	char		**info;

	info = ft_split(line, ' ');
	if (!check_count(info, 3) || !is_double(info[1])
		|| !in_range_double(info[1]) || !parse_color(info[2]))
		return (true_or_false(info, false));
	norm_col = normalize_rgb_to_double(info[2]);
	world->obj_lst->shape->material.ambient = multiply_col
		(create_color(norm_col[0], norm_col[1], norm_col[2]), ft_atod(info[1]));
	return (true_or_false(info, true));
}
