/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaismalheiros <thaismalheiros@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:57:54 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/28 21:04:16 by thaismalhei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "Scenes.h"

void	parser(int argc, char **argv);
void	check_argc(int argc);
void	check_extensions(char **argv);
void	open_file(int *fd, char *file);
void	get_line(int fd, t_world *world);
void	check_newline(char *line);
bool	check_empty_line(char *line);
bool	parse_line(char *line, t_world *world);
bool	parse_ambient(char *line, t_world *world);
bool	parse_camera(char *line, t_world *world);
bool	parse_light(char *line, t_world *world);
bool	parse_sphere(char *line, t_world *world);
bool	parse_plane(char *line, t_world *world);
bool	parse_cylinder(char *line, t_world *world);

#endif