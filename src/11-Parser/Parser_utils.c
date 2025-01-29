/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaismalheiros <thaismalheiros@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:28:43 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/28 21:03:44 by thaismalhei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

void	open_file(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		error("Error\n", "Could not open file", "", 1);
}
