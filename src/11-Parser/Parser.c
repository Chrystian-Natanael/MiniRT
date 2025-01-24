/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:02:40 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/24 15:07:58 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"
#include "get_next_line.h"

void	parse(int fd, t_world *world)
{
	char	*line;

	world = default_world();
	line = get_next_line(fd);
}

void	parser(int argc, char **argv)
{
	int		fd;
	t_world	*world;

	world = NULL;
	check_argc(argc);
	check_extensions(argv);
	open_file(&fd, argv[1]);
	parse(fd, world);
}
