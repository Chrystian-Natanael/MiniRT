/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:49 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/08 18:18:34 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Objects.h"

static bool	sphere_patterns_validation(char **info, t_world *world, t_obj *sp)
{
	if (info[4] && check_obj_pattern(info[4], world, sp))
	{
		sp->shape->material.pat.flag = true;
		world->scene.pat_lst->pat.flag = true;
	}
	if (info[4] && !check_obj_pattern(info[4], world, sp))
		return (true_or_false(info, false));
	return (true);
}

static bool	sphere_validations(char **info)
{
	if ((!check_count(info, 4) && !check_count(info, 5)) || !parse_pos(info[1])
		|| !is_double(info[2]) || !parse_color(info[3]))
		return (false);
	return (true);
}

static void	set_sphere(t_obj **sp, char *diam, double *col, double *pos)
{
	double	radius;

	radius = ft_atod(diam) / 2;
	((t_sp *)(*sp)->shape->obj)->radius = radius;
	((t_sp *)(*sp)->shape->obj)->src = pos;
	(*sp)->shape->material.color = create_color(col[0], col[1], col[2]);
	set_transf(&(*sp)->shape, rotate_mtx(pos, point(0, 1, 0), sp));
}

bool	parse_sphere(char *line, t_world *world)
{
	double		*norm_col;
	double		*pos;
	char		**info;
	t_pool_set	*set;
	t_obj		*sp;

	info = ft_split(line, ' ');
	if (!sphere_validations(info))
		return (true_or_false(info, false));
	norm_col = allocate(sizeof(double) * 3);
	norm_col = normalize_rgb_to_double(info[3]);
	pos = allocate(sizeof(double) * 3);
	pos = pos_to_double(info[1]);
	set = get_pool();
	sp = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
	init_shape(SPHERE, &sp->shape);
	set_sphere(&sp, info[2], norm_col, pos);
	insert_into_obj_list(&world->obj_lst, sp);
	if (!sphere_patterns_validation(info, world, sp))
		return (true_or_false(info, false));
	return (true_or_false(info, true));
}
