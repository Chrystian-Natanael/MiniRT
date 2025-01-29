/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:02:40 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/29 15:26:02 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

static void	open_file(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		error("Error\n", "Could not open file", "", 1);
}

/**
 * @todo verificar onde deve ir o parseamento de materials
 * @todo vai ter que ter outro parser para o bônus (padrões e mais de uma luz)
 */
bool	parse_line(char *line, t_world *world)
{
	if (!ft_strncmp(line, "A", 1))
		return (parse_ambient(line, world));
	// else if (!ft_strncmp(line, "C", 1))
	// 	return (parse_camera(line, world));
	// else if (!ft_strncmp(line, "L", 1))
	// 	return (parse_light(line, world));
	// else if (!ft_strncmp(line, "sp", 2))
	// 	return (parse_sphere(line, world));
	// else if (!ft_strncmp(line, "pl", 2))
	// 	return (parse_plane(line, world));
	// else if (!ft_strncmp(line, "cy", 2))
	// 	return (parse_cylinder(line, world));
	return (false);
}

/**
 * @todo checar se a linha 50 vai dar leak de memoria
 */
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
				error("Error\n", "Bad arguments on line ", ft_itoa(count), 1);
		}
		free(line);
		line = get_next_line(fd);
		count++;
	}
}

void	parser(int argc, char **argv)
{
	int		fd;
	t_world	*world; // Passar *world ou **world?

	world = NULL;
	check_argc(argc);
	check_extensions(argv);
	open_file(&fd, argv[1]);
	get_line(fd, world);
	close(fd);
}
