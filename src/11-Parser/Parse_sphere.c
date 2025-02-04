/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:49 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/03 12:09:58 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

bool	parse_sphere(char *line, t_world *world)
{
	double		*norm_col;
	double		*pos;
	char		**info;
	t_pool_set	*set;
	t_obj		*sp;
	t_matrix	transformation;

	info = ft_split(line, ' ');
	if (!check_count(info, 4) || !parse_pos(info[1]) || !is_double(info[2])
		|| !parse_color(info[3]))
		return (true_or_false(info, false));
	norm_col = allocate(sizeof(double) * 3);
	norm_col = normalize_rgb_to_double(info[3]);
	pos = allocate(sizeof(double) * 3);
	pos = pos_to_double(info[1]);
	set = get_pools();
	sp = (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(SPHERE, &sp->shape);
	sp->next = NULL;
	sp->prev = NULL;
	transformation = multiply_mtx(scale(ft_atod(info[1]) / 2, ft_atod(info[1]) / 2, ft_atod(info[1]) / 2), translate(pos[X], pos[Y], pos[Z]));
	set_transf(&sp->shape, transformation);
	insert_into_obj_list(&world->obj_lst, sp);
	return (true_or_false(info, true));
}
