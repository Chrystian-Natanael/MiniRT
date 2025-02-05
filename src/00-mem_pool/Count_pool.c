/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Count_pool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:03:07 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/05 10:21:06 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Count_el.h"
#include "Mem_pool.h"
#include "Parser.h"

t_count_el	calc_sz_pools(char *file_name)
{
	int		fd;
	char	*line;
	t_count_el	counts;

	ft_bzero(&counts, sizeof(t_count_el));
	open_file(&fd, file_name);
	line = get_next_line(fd);
	while (line)
	{
		check_newline(line);
		if (!check_empty_line(line))
			parse_count(line ,&counts);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (counts);
}

void	parse_count(char *line, t_count_el *counts)
{
	if (!ft_strncmp(line, "sp", 2))
		counts->sp++;
	else if (!ft_strncmp(line, "pl", 2))
		counts->pl++;
	else if (!ft_strncmp(line, "cy", 2))
		counts->cy++;
	else if (!ft_strncmp(line, "L", 1))
		counts->lights++;
	else if (!ft_strncmp(line, "p", 1))
		counts->patterns++;
}
