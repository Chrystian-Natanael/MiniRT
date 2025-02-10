/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Pattern_Utils_Bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:20:39 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:45:23 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser_Bonus.h"
#include "Matrices_Bonus.h"

bool	check_obj_pattern(char *str, t_world *world, t_obj *obj)
{
	(void)world;
	if (!ft_strncmp(str, "gradient", ft_strlen(str)))
		obj->shape->material.pat.id = GRADIENT;
	else if (!ft_strncmp(str, "ring", ft_strlen(str)))
		obj->shape->material.pat.id = RING;
	else if (!ft_strncmp(str, "checkers", ft_strlen(str)))
		obj->shape->material.pat.id = CHECKER;
	else
		return (false);
	return (true);
}

bool	check_pattern(char *str1, char *str2)
{
	if (ft_strncmp(str1, "gradient", 9) && ft_strncmp(str1, "ring", 5)
		&& ft_strncmp(str1, "checkers", 9))
	{
		warning("Error\n", "Not a valid pattern name", "");
		return (false);
	}
	if (ft_strncmp(str2, "gradient", 9) && ft_strncmp(str2, "ring", 5)
		&& ft_strncmp(str2, "checkers", 9))
	{
		warning("Error\n", "Not a valid pattern type", "");
		return (false);
	}
	if (ft_strncmp(str1, str2, ft_strlen(str1)))
	{
		warning("Error\n", "Pattern name and pattern type are different", "");
		return (false);
	}
	return (true);
}

bool	parse_transformations(char *str1, char *str2, char *str3)
{
	if (!parse_pos(str1))
	{
		warning("Error\n", "Not a valid pattern scale", "");
		return (false);
	}
	if (!parse_pos(str2))
	{
		warning("Error\n", "Not a valid pattern rotation", "");
		return (false);
	}
	if (!parse_pos(str3))
	{
		warning("Error\n", "Not a valid pattern translation", "");
		return (false);
	}
	return (true);
}

void	insert_into_pattern_list(t_pat_lst **lst, t_pat_lst *pat)
{
	t_pat_lst	*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	pat->prev = tmp;
	if (!tmp)
		*lst = pat;
	else
		tmp->next = pat;
}

t_matrix	get_transf(double *scl, double *rot, double *trns)
{
	t_matrix	scale_mtx;
	t_matrix	rotate_mtx;
	t_matrix	translate_mtx;
	t_matrix	transf;

	scale_mtx = scale(scl[0], scl[1], scl[2]);
	rotate_mtx = multiply_mtx(multiply_mtx(rotate_x((rot[0] * PI) / 180),
				rotate_y((rot[1] * PI) / 180)),
			(rotate_z((rot[2] * PI) / 180)));
	translate_mtx = translate(trns[0], trns[1], trns[2]);
	transf = (multiply_mtx(multiply_mtx(scale_mtx, rotate_mtx), translate_mtx));
	return (transf);
}
