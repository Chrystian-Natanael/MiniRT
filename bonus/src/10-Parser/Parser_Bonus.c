/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_Bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:02:40 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:45:10 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser_Bonus.h"
#include "Mem_Pool_Bonus.h"

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
	else if (!ft_strncmp(line, "cy", 2))
		return (parse_cylinder(line, world));
	else if (!ft_strncmp(line, "cn", 2))
		return (parse_cone(line, world));
	else if (!ft_strncmp(line, "p", 1))
		return (parse_pattern(line, world));
	return (false);
}

void	set_ambient(t_world *wld)
{
	t_obj		*ax_wld;
	t_pat_lst	*pat;
	t_pat_lst	*ax_pat;

	pat = wld->scene.pat_lst;
	ax_wld = wld->obj_lst;
	while (ax_wld)
	{
		ax_wld->shape->material.ambient = hada_col(wld->scene.ambient, \
			ax_wld->shape->material.color);
		if (ax_wld->shape->material.pat.flag == true)
		{
			ax_pat = pat;
			while (ax_pat && (ax_wld->shape->material.pat.id != ax_pat->pat.id))
				ax_pat = ax_pat->next;
			ax_wld->shape->material.pat.c1 = ax_pat->pat.c1;
			ax_wld->shape->material.pat.c2 = ax_pat->pat.c2;
			ax_wld->shape->material.pat.flag = true;
			ax_wld->shape->material.pat.id = ax_pat->pat.id;
			ax_wld->shape->material.pat.inv = ax_pat->pat.inv;
			ax_wld->shape->material.pat.transf = ax_pat->pat.transf;
		}
		ax_wld = ax_wld->next;
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
