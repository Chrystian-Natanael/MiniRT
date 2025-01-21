/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:15:50 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/21 17:32:02 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas.h"
#include "Codam.h"
#include "Colors.h"
#include "Scenes.h"
#include <fcntl.h>
#include <stdio.h>

void	print_ppm_header(int wid, int hei, int fd)
{
	dprintf(fd, "P3\n%d %d \n255\n", wid, hei);
}

void print_line_ppm(t_colors pixel, int fd)
{
	dprintf(fd, "%d %d %d ", (int)(pixel.red * 255), (int)(pixel.green * 255), (int)(pixel.blue * 255));
}

void	canva2ppm(t_paint paint, char *filename)
{
	int	x;
	int	y;
	int fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		error("ERROR", NULL, NULL, 1);
	print_ppm_header(paint.wid, paint.hei, fd);
	y = -1;
	while (++y < paint.hei)
	{
		x = -1;
		while (++x < paint.wid)
			print_line_ppm(paint.px[y * paint.wid + x], fd);
	}
	close(fd);
}