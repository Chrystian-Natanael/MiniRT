/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_Bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:26:01 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:35:37 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace_atod(const char *nptr)
{
	int	idx;

	idx = 0;
	while ((nptr[idx] == '\f') || (nptr[idx] == '\n')
		|| (nptr[idx] == '\r') || (nptr[idx] == '\t')
		|| (nptr[idx] == '\v') || (nptr[idx] == ' '))
	{
		idx++;
	}
	return (idx);
}

static int	ft_odd(char c)
{
	int	odd;

	odd = 1;
	if (c == '-')
		odd = -1;
	return (odd);
}

double	ft_atod(const char *nptr)
{
	int		odd;
	double	value;
	double	decimal;
	int		idx;

	value = 0.0;
	decimal = 0.1;
	idx = ft_isspace_atod(nptr);
	odd = ft_odd(nptr[idx]);
	while (nptr[idx] == '+' || nptr[idx] == '-')
		idx++;
	while (nptr[idx] >= '0' && nptr[idx] <= '9')
		value = value * 10.0 + (nptr[idx++] - '0');
	if (nptr[idx] == '.')
	{
		idx++;
		while (nptr[idx] >= '0' && nptr[idx] <= '9')
		{
			value += (nptr[idx++] - '0') * decimal;
			decimal /= 10.0;
		}
	}
	return (value * odd);
}
