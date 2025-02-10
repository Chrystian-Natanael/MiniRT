/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Canvas_Bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:43:44 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 08:14:10 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_BONUS_H
# define CANVAS_BONUS_H

# include "Scenes_Bonus.h"
# include "Colors_Bonus.h"

# define HEIGHT 300
# define WIDHT 300

typedef struct s_paint
{
	int			wid;
	int			hei;
	t_colors	*px;
}				t_paint;

t_paint	render_canva(t_camera cam, t_world *world);
void	canva2ppm(t_paint paint, char *filename);

#endif
