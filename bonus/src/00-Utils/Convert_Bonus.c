/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert_Bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:22:05 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 11:12:40 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils_Bonus.h"

/**
 * @brief Converts a double to an integer
 *
 * This function converts a double value to an integer by rounding it to
 * the nearest integer.
 *
 * @param value The double value to be converted
 * @return The rounded integer value
 */
int	dtoi(double value)
{
	return ((int)round(value));
}

char	*free_line(char *line, int fd, int count)
{
	char	*tmp;
	int		id;

	tmp = ft_itoa(count);
	insert(tmp);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	id = fd - 1;
	while (++id < 10)
		close(id);
	return (tmp);
}

void	empty_file(int fd)
{
	close(fd);
	error("Error\n", "Empty file ", "", 1);
}

void	clear_term(void)
{
	int	i;

	i = -1;
	while (++i < 50)
	{
		ft_printf("\n");
	}
}
