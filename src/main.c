/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:24 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/30 12:15:26 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	main(int argc, char **argv)
{
	init_pools();
	t_canvas	canva;

	parser(argc, argv);
	init_window(&canva);
	mlx_loop(canva.mlx);
	mlx_terminate(canva.mlx);
	quit(0);
}
