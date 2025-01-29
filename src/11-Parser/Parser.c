/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaismalheiros <thaismalheiros@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:02:40 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/28 21:04:47 by thaismalhei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "get_next_line.h"
#include <stdbool.h>

bool	parse_line(char *line, t_world *world)
{
	if (!ft_strncmp(line, "A", 1))
		return(parse_ambient(line, world));
	else if (!ft_strncmp(line, "C", 1))
		return(parse_camera(line, world));
	else if (!ft_strncmp(line, "L", 1))
		return(parse_light(line, world));
	else if (!ft_strncmp(line, "sp", 2))
		return(parse_sphere(line, world));
	else if (!ft_strncmp(line, "pl", 2))
		return(parse_plane(line, world));
	else if (!ft_strncmp(line, "cy", 2))
		return(parse_cylinder(line, world));
	return(false);
}

void	get_line(int fd, t_world *world)
{
	int		count;
	char	*line;

	world = default_world();
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		check_newline(line);
		if (!check_empty_line(line))
		{
			if (!parse_line(line, world))
				error("Error\n", "Bad arguments in line ", ft_itoa(count), 1); // checar se vai dar leak
		}
		free(line);
		line = get_next_line(fd);
		count++;
	}
}

void	parser(int argc, char **argv)
{
	int		fd;
	t_world	*world;

	world = NULL;
	check_argc(argc);
	check_extensions(argv);
	open_file(&fd, argv[1]);
	get_line(fd, world);
	close(fd);
}
