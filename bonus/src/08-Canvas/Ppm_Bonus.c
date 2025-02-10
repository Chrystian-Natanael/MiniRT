/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ppm_Bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:15:50 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:42:49 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas_Bonus.h"
#include "Codam_Bonus.h"
#include "Colors_Bonus.h"
#include "Scenes_Bonus.h"
#include <fcntl.h>
#include <stdio.h>

static void	print_ppm_header(int width, int height, int fd)
{
	ft_putstr_fd("P3\n", fd);
	ft_putnbr_fd(width, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(height, fd);
	ft_putstr_fd("\n255\n", fd);
}

static char	*join_colors(t_colors pixel)
{
	char	*r;
	char	*g;
	char	*b;
	char	*line;
	char	*tmp;

	r = ft_itoa((int)(pixel.red * 255));
	insert(r);
	g = ft_itoa((int)(pixel.green * 255));
	insert(g);
	b = ft_itoa((int)(pixel.blue * 255));
	insert(b);
	tmp = ft_strjoin(r, " ");
	insert(tmp);
	line = ft_strjoin(tmp, g);
	insert(line);
	tmp = ft_strjoin(line, " ");
	insert(tmp);
	line = ft_strjoin(tmp, b);
	insert(line);
	tmp = ft_strjoin(line, "\n");
	insert(tmp);
	return (tmp);
}

static void	print_line_ppm(t_colors pixel, int fd, int flush)
{
	char		*line;
	static int	i;
	static char	saved[BUFFER_SIZE + 20];

	if (flush && i == 0)
		return ;
	line = join_colors(pixel);
	if (i + ft_strlen(line) > BUFFER_SIZE || flush)
	{
		(void)!write(fd, saved, i);
		i = 0;
	}
	i += ft_strlcpy(saved + i, line, ft_strlen(line) + 1);
}

void	canva2ppm(t_paint paint, char *filename)
{
	int	y;
	int	x;
	int	fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		error("Error\nCannot open: ", filename, "\n", 1);
	print_ppm_header(paint.wid, paint.hei, fd);
	y = -1;
	while (++y < paint.hei)
	{
		x = -1;
		while (++x < paint.wid)
			print_line_ppm(paint.px[y * paint.wid + x], fd, 0);
	}
	print_line_ppm((t_colors){0, 0, 0}, fd, 1);
	close(fd);
}
