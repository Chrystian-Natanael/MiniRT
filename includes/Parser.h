/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:57:54 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/29 15:55:29 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "get_next_line.h"
# include "libft.h"
# include "Scenes.h"
# include <stdbool.h>

void	parser(int argc, char **argv);

void	check_argc(int argc);
void	check_extensions(char **argv);
void	check_newline(char *line);
bool	check_empty_line(char *line);
bool	check_count(char **info, int count);

bool	is_double(char *str);
bool	in_range_double(char *str);
bool	true_or_false(char **str, bool flag);
void	ft_free_array(char **str);

void	get_line(int fd, t_world *world);
bool	parse_line(char *line, t_world *world);
bool	parse_ambient(char *line, t_world *world);
bool	parse_camera(char *line, t_world *world);
bool	parse_light(char *line, t_world *world);
bool	parse_sphere(char *line, t_world *world);
bool	parse_plane(char *line, t_world *world);
bool	parse_cylinder(char *line, t_world *world);

bool	parse_color(char *line);
double	*normalize_rgb_to_double(char *str);
bool	is_int(char *str);
bool	in_range_int(char *str);

#endif