/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:02:40 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/04 15:09:43 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

static void	open_file(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		error("Error\n", "Could not open file", "", 1);
}

bool	parse_line(char *line, t_world *world)
{
	if (!ft_strncmp(line, "A", 1))
		return (parse_ambient(line, world));
	else if (!ft_strncmp(line, "C", 1))
		return (parse_camera(line, world));
	else if (!ft_strncmp(line, "L", 1))
		return (parse_light(line, world));
	else if (!ft_strncmp(line, "sp", 2))
		return (parse_sphere(line, world));
	// else if (!ft_strncmp(line, "pl", 2))
	// 	return (parse_plane(line, world));
	// else if (!ft_strncmp(line, "cy", 2))
	// 	return (parse_cylinder(line, world));
	return (false);
}

void	get_line(int fd, t_world *wld)
{
	int		count;
	char	*line;

	count = 1;
	line = get_next_line(fd);
	while (line)
	{
		check_newline(line);
		if (!check_empty_line(line))
		{
			if (!parse_line(line, wld))
				error("Error\n", "Bad arguments on line ", ft_itoa(count), 1);
		}
		free(line);
		line = get_next_line(fd);
		count++;
	}
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

t_world	*parser(int argc, char **argv)
{
	int			fd;
	t_world		*wld;
	t_count_el	counts;

	check_argc(argc);
	check_extensions(argv);
	open_file(&fd, argv[1]);
	counts = calc_sz_pools(argv[1]);
	printf("SP[%d]\nPL[%d]\nCY[%d]\nL[%d]\nP[%d]\n", counts.sp, counts.pl, counts.cy, counts.lights, counts.patterns);
	init_pools(counts);
	wld = world();
	// set_scene(wld);
	// get_line(fd, wld);
	close(fd);
	return (wld);
}
