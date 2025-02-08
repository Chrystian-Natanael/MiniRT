/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:20:39 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/07 14:30:40 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Matrices.h"

static void	set_pattern(char *str1, char *str2, char *str3, t_world *world)
{
	double			**col;
	t_colors		col1;
	t_colors		col2;
	t_pat_lst		*lst;
	t_pool_set		*set;

	col = allocate(sizeof(double *) * 2);
	col[0] = allocate(sizeof(double) * 3);
	col[0] = normalize_rgb_to_double(str2);
	col1 = create_color(col[0][0], col[0][1], col[0][2]);
	col[1] = allocate(sizeof(double) * 3);
	col[1] = normalize_rgb_to_double(str3);
	col2 = create_color(col[1][0], col[1][1], col[1][2]);
	set = get_pool();
	lst = (t_pat_lst *)alloc_pool(sizeof(t_pat_lst),
			set->the_pool);
	if (!ft_strncmp(str1, "gradient", ft_strlen(str1)))
		lst->pattern = gradient_pattern(col1, col2);
	else if (!ft_strncmp(str1, "ring", ft_strlen(str1)))
		lst->pattern = ring_pattern(col1, col2);
	else if (!ft_strncmp(str1, "checkers", ft_strlen(str1)))
		lst->pattern = checker_pattern(col1, col2);
	insert_into_pattern_list(&world->scene.pat_lst, lst);
}

bool	parse_pattern(char *line, t_world *world)
{
	double		*scale;
	double		*rotate;
	double		*translate;
	char		**info;
	t_matrix	transf;

	info = ft_split(line, ' ');
	if (!check_count(info, 8) || !check_pattern(info[1], info[2])
		|| !parse_color(info[3]) || !parse_color(info[4])
		|| !parse_transformations(info[5], info[6], info[7]))
		return (true_or_false(info, false));
	set_pattern(info[1], info[3], info[4], world);
	scale = allocate(sizeof(double) * 3);
	scale = pos_to_double(info[5]);
	rotate = allocate(sizeof(double) * 3);
	rotate = pos_to_double(info[6]);
	translate = allocate(sizeof(double) * 3);
	translate = pos_to_double(info[7]);
	transf = get_transf(scale, rotate, translate);
	world->scene.pat_lst->pattern.transf = transf;
	return (true_or_false(info, true));
}
