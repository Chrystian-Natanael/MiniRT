/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:43:44 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/07 14:52:49 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "Scenes.h"
# include "Colors.h"

typedef struct s_paint
{
	int			wid;
	int			hei;
	t_colors	**px;
}				t_paint;

t_paint	render_canva(t_camera cam, t_world *world);

#endif