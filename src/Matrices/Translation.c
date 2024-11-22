/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:54:32 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/22 10:40:54 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

t_matrix	translate(double x, double y, double z)
{
	t_matrix	trnsl_mtx;

	trnsl_mtx = id_mtx();
	set_val((get_pos(0, 3, 4)), x, &trnsl_mtx);
	set_val((get_pos(1, 3, 4)), y, &trnsl_mtx);
	set_val((get_pos(2, 3, 4)), z, &trnsl_mtx);
	trnsl_mtx.col = 4;
	trnsl_mtx.row = 4;
	return (trnsl_mtx);
}
