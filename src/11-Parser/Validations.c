/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:28:43 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/05 10:24:31 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Canvas.h"

void	check_argc(int argc)
{
	if (argc != 2 && argc != 3)
		error("Error\n", "Invalid number of arguments", "", 1);
	else if (WIDHT <= 0 || HEIGHT <= 0)
		error("Error\n", "Invalid resolution", "", 1);
	else if (WIDHT > 1920 || HEIGHT > 1080)
		error("Error\n", "This pc doesn't support 4k resolution... yet", "", 1);
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

void	check_newline(char *line)
{
	if (ft_strchr(line, '\n'))
		*ft_strchr(line, '\n') = '\0';
}

bool	check_empty_line(char *line)
{
	if (!line[0] || line[0] == '#')
		return (true);
	return (false);
}

bool	check_count(char **info, int count)
{
	int	i;

	i = 0;
	while (info && info[i])
		i++;
	if (i != count)
		return (false);
	return (true);
}
