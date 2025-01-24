/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:57:54 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/24 15:02:25 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "Utils.h"

void	parser(int argc, char **argv);
void	check_argc(int argc);
void	check_extensions(char **argv);
void	open_file(int *fd, char *file);
void	parse(int fd, t_world *world);

#endif