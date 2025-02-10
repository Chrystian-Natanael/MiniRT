/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Color_Bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:18:43 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:45:33 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser_Bonus.h"

bool	in_range_int(char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	if (nbr < 0 || nbr > 255)
		return (false);
	return (true);
}

bool	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

double	*normalize_rgb_to_double(char *str)
{
	int		idx;
	double	*rgb;
	char	**colors;

	idx = 0;
	rgb = allocate(sizeof(double) * 3);
	colors = ft_split(str, ',');
	while (colors[idx])
	{
		rgb[idx] = (ft_atod(colors[idx]) / 255);
		idx++;
	}
	ft_free_array(colors);
	return (rgb);
}

bool	parse_color(char *str)
{
	int		idx;
	char	**colors;

	idx = 0;
	colors = ft_split(str, ',');
	if (!check_count(colors, 3))
		return (true_or_false(colors, false));
	while (colors[idx])
	{
		if (!is_int(colors[idx]) || !in_range_int(colors[idx]))
			return (true_or_false(colors, false));
		idx++;
	}
	return (true_or_false(colors, true));
}
