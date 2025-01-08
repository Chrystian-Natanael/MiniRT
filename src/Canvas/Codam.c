/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Codam.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:30:39 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/08 11:37:58 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas.h"
#include "Codam.h"
#include "Colors.h"
#include "Scenes.h"

void	init_window(t_canvas *canvas)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	canvas->mlx = mlx_init(WIDTH, HEIGHT, "MiniRT", true);
	canvas->image = mlx_new_image(canvas->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(canvas->mlx, canvas->image, 0, 0);
}

mlx_image_t	*canva2image(t_paint canvas, mlx_t *mlx)
{
	mlx_image_t	*im;
	int			x;
	int			y;

	im = mlx_new_image(mlx, canvas.wid, canvas.hei);
	if (!im)
		error("ERRO NA IMAGEM", NULL, NULL, 1);
	y = -1;
	while (++y < canvas.hei)
	{
		x = -1;
		while (++x < canvas.wid)
			mlx_put_pixel(im, x, y, rgb2hex((canvas.px[y * canvas.wid + x])));
	}
	return (im);
}
