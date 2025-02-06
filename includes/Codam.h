/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Codam.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:28:57 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/06 13:30:47 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODAM_H
# define CODAM_H

# include "MLX42/MLX42.h"

typedef struct s_canvas
{
	mlx_t		*mlx;
	mlx_image_t	*image;

}				t_canvas;

// void		init_window(t_canvas *canvas);
mlx_image_t	*canva2image(t_paint canvas, mlx_t *mlx);

#endif // ! CODAM_H