/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:49 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 11:57:04 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Objects.h"
#include <math.h>

t_matrix	get_matrix(t_matrix scale, t_matrix rotate, t_matrix translate)
{
	t_matrix	result;

	result = multiply_mtx(multiply_mtx(scale, rotate), translate);
	return (result);
}

t_matrix	rotate_mtx(double *pos, double *norm, t_obj **obj)
{
	double	radius;
	double	x_angle;
	double	z_angle;

	x_angle = 0;
	z_angle = 0;
	calculate_rotation_angles(norm, &x_angle, &z_angle);
	radius = 1;
	if ((t_sp *)(*obj)->shape->id == SPHERE)
		radius = ((t_sp *)(*obj)->shape->obj)->radius;
	// else if ((t_cy *)(*obj)->shape->id == CYLINDER)
	// 	radius = ((t_cy *)(*obs)->shape->obj)->radius;
	return (get_matrix(translate(pos[0], pos[1], pos[2]),
			get_rot_matrix(x_angle, z_angle),
			scale(radius, radius, radius)));
}

void	set_plane(t_obj **pl, char *pos, char *norm, char *col)
{
	double	*pl_pos;
	double	*pl_norm;
	double	*pl_col;

	pl_pos = allocate(sizeof(double) * 3);
	pl_pos = pos_to_double(pos);
	pl_pos = point(pos[0], pos[1], pos[2]);
	pl_norm = allocate(sizeof(double) * 3);
	pl_norm = pos_to_double(norm);
	pl_norm = vector(norm[0], norm[1], norm[2]);
	pl_col = allocate(sizeof(double) * 3);
	pl_col = normalize_rgb_to_double(col);
	((t_pl *)(*pl)->shape->obj)->src = pl_pos;
	(*pl)->shape->material.color = create_color
		(pl_col[0], pl_col[1], pl_col[2]);
	set_transf(&(*pl)->shape, rotate_mtx(pl_pos, pl_norm, pl));
}

bool	parse_plane(char *line, t_world *world)
{
	char		**info;
	t_pool_set	*set;
	t_obj		*pl;

	info = ft_split(line, ' ');
	if (!check_count(info, 4) || !parse_pos(info[1]) || !parse_dir(info[2])
		|| !parse_color(info[3]))
		return (true_or_false(info, false));
	set = get_pool();
	pl = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
	init_shape(PLANE, &pl->shape);
	set_plane(&pl, info[1], info[2], info[3]);
	insert_into_obj_list(&world->obj_lst, pl);
	return (true_or_false(info, true));
}

// bool	parse_plane(char *line, t_world *world)
// {
// 	double		*norm_col;
// 	double		*pos;
// 	double		*norm;
// 	char		**info;
// 	t_pool_set	*set;
// 	t_obj		*pl;

// 	info = ft_split(line, ' ');
// 	if (!check_count(info, 4) || !parse_pos(info[1]) || !parse_dir(info[2])
// 		|| !parse_color(info[3]))
// 		return (true_or_false(info, false));
// 	norm_col = allocate(sizeof(double) * 3);
// 	norm_col = normalize_rgb_to_double(info[3]);
// 	pos = allocate(sizeof(double) * 3);
// 	pos = pos_to_double(info[1]);
// 	pos = point(pos[0], pos[1], pos[2]);
// 	norm = allocate(sizeof(double) * 3);
// 	norm = pos_to_double(info[2]);
// 	norm = vector(norm[0], norm[1], norm[2]);
// 	set = get_pool();
// 	pl = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
// 	init_shape(PLANE, &pl->shape);
// 	set_plane(&pl, norm, norm_col, pos);
// 	insert_into_obj_list(&world->obj_lst, pl);
// 	return (true_or_false(info, true));
// }