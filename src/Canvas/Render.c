/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:01:08 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/08 09:28:51 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Canvas.h"
#include "Intersections.h"
#include "Light_and_Shading.h"
#include <fcntl.h>
#include <stdlib.h>

t_paint	render_canva(t_camera cam, t_world *world)
{
	t_pool_set	*set;
	int			i[2];
	t_paint		canvas;
	t_colors	color;
	t_ray		ray;

	i[0] = -1;
	set = get_pools();
	canvas.hei = cam.vsize;
	canvas.wid = cam.hsize;
	canvas.px = (t_colors *)alloc_pool(sizeof(t_colors) * canvas.hei * canvas.wid, set->colors);
	while (++i[0] <= (cam.vsize - 1))
    {
        i[1] = -1;
        while (++i[1] <= (cam.hsize - 1))
        {
            ray = ray_for_pixel(cam, i[1], i[0]);
            color = color_at(world, ray);
            if (i[1] < 0 || i[1] >= canvas.wid || i[0] < 0
                || i[0] >= canvas.hei)
                continue ;
            // if (i[0] == 726 && i[1] == 240)
                // printf("a");
            canvas.px[i[0] * canvas.wid + i[1]] = color;
            printf("i[0] = %d/ i[1] = %d\n", i[0], i[1]);
        }
    }
	return (canvas);
}

t_colors	pixel_at(t_paint canvas, int x, int y)
{
	if (x < 0 || x >= canvas.wid || y < 0 || y >= canvas.hei)
		return (create_color(0, 0, 0));
	return (canvas.px[y * canvas.wid + x]);
}
