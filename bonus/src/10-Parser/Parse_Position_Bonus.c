/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Position_Bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:22:15 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:45:15 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser_Bonus.h"

bool	parse_pos(char *str)
{
	int		idx;
	char	**pos;

	idx = 0;
	pos = ft_split(str, ',');
	if (!check_count(pos, 3))
		return (true_or_false(pos, false));
	while (pos[idx])
	{
		if (!is_double(pos[idx]))
			return (true_or_false(pos, false));
		idx++;
	}
	return (true_or_false(pos, true));
}

double	*pos_to_double(char *str)
{
	int		idx;
	double	*pos;
	char	**coordinates;

	idx = 0;
	pos = allocate(sizeof(double) * 3);
	coordinates = ft_split(str, ',');
	while (coordinates[idx])
	{
		pos[idx] = ft_atod(coordinates[idx]);
		idx++;
	}
	ft_free_array(coordinates);
	return (pos);
}
