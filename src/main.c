/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:24 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/11 16:25:07 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"
#include "Canvas.h"
#include "Colors.h"
#include "ColorsTerm.h"

int	main(void)
{
	t_canvas	canva;

	init_window(&canva);
	mlx_loop(canva.mlx);
}
