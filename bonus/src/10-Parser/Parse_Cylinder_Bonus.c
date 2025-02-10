/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Cylinder_Bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:14:29 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:45:31 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser_Bonus.h"
#include "Objects_Bonus.h"

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
	((t_cl *)(*cl)->shape->obj)->max = ft_atod(info[4])
		/ (ft_atod(info[3]) / 2);
	((t_cl *)(*cl)->shape->obj)->min = 0;
	((t_cl *)(*cl)->shape->obj)->closed = true;
	((t_cl *)(*cl)->shape->obj)->src = point(cy_pos[X], cy_pos[Y], cy_pos[Z]);
	cy_col = allocate(sizeof(double) * 3);
	cy_col = normalize_rgb_to_double(info[5]);
	(*cl)->shape->material.color = create_color
		(cy_col[0], cy_col[1], cy_col[2]);
	set_transf(&(*cl)->shape, rotate_mtx(cy_pos, cy_norm, cl));
}

void	set_cone(t_obj **cn, char **info)
{
	double	*c_pos;
	double	*c_norm;
	double	*c_col;

	c_pos = allocate(sizeof(double) * 3);
	c_pos = pos_to_double(info[1]);
	c_norm = allocate(sizeof(double) * 3);
	c_norm = pos_to_double(info[2]);
	c_norm = norm(vector(c_norm[X], c_norm[Y], c_norm[Z]));
	((t_cn *)(*cn)->shape->obj)->radius = ft_atod(info[3]) / 2;
	((t_cn *)(*cn)->shape->obj)->max = ft_atod(info[4]);
	((t_cn *)(*cn)->shape->obj)->min = 0;
	((t_cn *)(*cn)->shape->obj)->closed = true;
	((t_cn *)(*cn)->shape->obj)->src = point(c_pos[X], c_pos[Y], c_pos[Z]);
	c_col = allocate(sizeof(double) * 3);
	c_col = normalize_rgb_to_double(info[5]);
	(*cn)->shape->material.color = create_color(c_col[0], c_col[1], c_col[2]);
	set_transf(&(*cn)->shape, rotate_mtx(c_pos, c_norm, cn));
}

bool	parse_cylinder(char *line, t_world *world)
{
	char		**info;
	t_pool_set	*set;
	t_obj		*cl;

	info = ft_split(line, ' ');
	if ((!check_count(info, 6) && !check_count(info, 7)) || !parse_pos(info[1])
		|| !parse_dir(info[2]) || !is_double(info[3]) || !is_double(info[4])
		|| !parse_color(info[5]))
		return (true_or_false(info, false));
	set = get_pool();
	cl = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
	init_shape(CYLINDER, &cl->shape);
	set_cylinder(&cl, info);
	insert_into_obj_list(&world->obj_lst, cl);
	if (info[6] && check_obj_pattern(info[6], world, cl))
	{
		cl->shape->material.pat.flag = true;
		world->scene.pat_lst->pat.flag = true;
	}
	if (info[6] && !check_obj_pattern(info[6], world, cl))
		return (true_or_false(info, false));
	return (true_or_false(info, true));
}

bool	parse_cone(char *line, t_world *world)
{
	char		**info;
	t_pool_set	*set;
	t_obj		*cn;

	info = ft_split(line, ' ');
	if ((!check_count(info, 6) && !check_count(info, 7)) || !parse_pos(info[1])
		|| !parse_dir(info[2]) || !is_double(info[3]) || !is_double(info[4])
		|| !parse_color(info[5]))
		return (true_or_false(info, false));
	set = get_pool();
	cn = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
	init_shape(CONE, &cn->shape);
	set_cone(&cn, info);
	insert_into_obj_list(&world->obj_lst, cn);
	if (info[6] && check_obj_pattern(info[6], world, cn))
	{
		cn->shape->material.pat.flag = true;
		world->scene.pat_lst->pat.flag = true;
	}
	if (info[6] && !check_obj_pattern(info[6], world, cn))
		return (true_or_false(info, false));
	return (true_or_false(info, true));
}
