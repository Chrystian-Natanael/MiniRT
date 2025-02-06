/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:57:54 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 14:05:08 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "Scenes.h"
# include <stdbool.h>

# define PI 3.14159265358979323846

t_world		*parser(int argc, char **argv);
t_world		*init_world(int argc, char **argv);
void		get_line(int fd, t_world *world);
bool		parse_line(char *line, t_world *world);

void		check_argc(int argc);
void		check_extensions(char **argv);
void		check_newline(char *line);
bool		check_empty_line(char *line);
bool		check_count(char **info, int count);

void		open_file(int *fd, char *file);
bool		is_double(char *str);
bool		in_range_double(char *str);
bool		true_or_false(char **str, bool flag);
void		ft_free_array(char **str);

bool		parse_ambient(char *line, t_world *world);

bool		parse_camera(char *line, t_world *world);
bool		parse_dir(char *str);
bool		dir_in_range(char *str);

bool		parse_light(char *line, t_world *world);

bool		parse_sphere(char *line, t_world *world);

bool		parse_plane(char *line, t_world *world);
void		set_plane(t_obj **pl, char *pos, char *norm, char *col);
t_matrix	rotate_mtx(double *pos, double *norm, t_obj **obj);
t_matrix	get_matrix(t_matrix scale, t_matrix rotate, t_matrix translate);

int			sign(int number);
t_matrix	get_rot_matrix(double x, double z);
void		calculate_rotation_angles(double *norm, double *x, double *z);

bool		parse_cylinder(char *line, t_world *world);

bool		parse_color(char *str);
double		*normalize_rgb_to_double(char *str);
bool		is_int(char *str);
bool		in_range_int(char *str);

bool		parse_pos(char *str);
double		*pos_to_double(char *str);

bool		parse_sphere(char *line, t_world *world);

#endif
