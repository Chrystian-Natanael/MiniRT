/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:14:29 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/06 16:57:26 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Objects.h"

// info[0] = name
// info[1] = position
// info[2] = direction
// info[3] = diameter
// info[4] = height
// info[5] = colors

void	set_cylinder(t_obj **cl, char **info)
{
	double	*cy_pos;
	double	*cy_norm;
	double	*cy_col;

	cy_pos = allocate(sizeof(double) * 3);
	cy_pos = pos_to_double(info[1]);
	cy_norm = allocate(sizeof(double) * 3);
	cy_norm = pos_to_double(info[2]);
	cy_norm = norm(vector(cy_norm[X], cy_norm[Y], cy_norm[Z]));
	((t_cl *)(*cl)->shape->obj)->radius = ft_atod(info[3]) / 2;
	((t_cl *)(*cl)->shape->obj)->max = ft_atod(info[4]) / (ft_atod(info[3]) / 2);
	((t_cl *)(*cl)->shape->obj)->min = 0;
	((t_cl *)(*cl)->shape->obj)->closed = true;
	((t_cl *)(*cl)->shape->obj)->src = point(cy_pos[X], cy_pos[Y], cy_pos[Z]);
	cy_col = allocate(sizeof(double) * 3);
	cy_col = normalize_rgb_to_double(info[5]);
	(*cl)->shape->material.color = create_color
		(cy_col[0], cy_col[1], cy_col[2]);
	set_transf(&(*cl)->shape, rotate_mtx(cy_pos, cy_norm, cl));
}

bool	parse_cylinder(char *line, t_world *world)
{
	char		**info;
	t_pool_set	*set;
	t_obj		*cl;

	info = ft_split(line, ' ');
	if (!check_count(info, 6) || !parse_pos(info[1]) || !parse_dir(info[2])
		|| !is_double(info[3]) || !is_double(info[4]) || !parse_color(info[5]))
		return (true_or_false(info, false));
	set = get_pool();
	cl = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
	init_shape(CYLINDER, &cl->shape);
	set_cylinder(&cl, info);
	insert_into_obj_list(&world->obj_lst, cl);
	return (true_or_false(info, true));
}
