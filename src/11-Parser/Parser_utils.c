/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:28:43 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/24 15:03:19 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

void	check_argc(int argc)
{
	if (argc != 2 && argc != 3)
		error("Error\n", "Invalid number of arguments", "", 1);
}

void	check_extensions(char **argv)
{
	if (ft_strlen(argv[1]) < 3)
		error("Error\n", argv[1], " must have a '.rt' extension", 1);
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 3), ".rt", 3))
		error("Error\n", "Invalid file extension", "", 1);
	if (argv[2])
	{
		if (ft_strlen(argv[2]) < 5)
			error("Error\n", argv[2], " must have a '.ppm' extension", 1);
		if (ft_strncmp((argv[2] + ft_strlen(argv[2]) - 4), ".ppm", 4))
			error("Error\n", "Invalid file extension", "", 1);
	}
}

void	open_file(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		error("Error\n", "Could not open file", "", 1);
}
