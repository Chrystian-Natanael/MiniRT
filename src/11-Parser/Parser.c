/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:02:40 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 10:41:31 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Mem_pool.h"

t_world	*init_world(int argc, char **argv)
{
	t_world	*wld;

	wld = world();
	wld->scene.has_ambient = 0;
	wld->scene.has_camera = 0;
	wld->scene.has_light = 0;
	wld->scene.save_img = false;
	if (argc == 3)
	{
		wld->scene.save_img = true;
		wld->scene.file_name = argv[2];
	}
	return (wld);
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
	else if (!ft_strncmp(line, "pl", 2))
		return (parse_plane(line, world));
	// else if (!ft_strncmp(line, "cy", 2))
	// 	return (parse_cylinder(line, world));
	return (false);
}

void	set_ambient(t_world *wld)
{
	t_obj		*aux;
	t_colors	amb;

	aux = wld->obj_lst;
	amb = wld->scene.ambient;
	while (aux)
	{
		aux->shape->material.ambient = amb;
		aux = aux->next;
	}
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
	init_pools(counts);
	wld = init_world(argc, argv);
	get_line(fd, wld);
	close(fd);
	set_ambient(wld);
	return (wld);
}
