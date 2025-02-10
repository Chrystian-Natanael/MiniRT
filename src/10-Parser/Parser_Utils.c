/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_Utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:28:43 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:18:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Canvas.h"

void	open_file(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		error("Error\n", "Could not open file", "", 1);
}

bool	is_double(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (dot > 1)
		return (false);
	return (true);
}

bool	in_range_double(char *str)
{
	double	nbr;

	nbr = ft_atod(str);
	if (nbr < 0.0 || nbr > 1.0)
		return (false);
	return (true);
}

bool	true_or_false(char **str, bool flag)
{
	ft_free_array(str);
	if (flag)
		return (true);
	return (false);
}

void	ft_free_array(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		free(str[idx++]);
	free(str);
}
