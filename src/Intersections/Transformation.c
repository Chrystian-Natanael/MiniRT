/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:36:29 by cnatanae          #+#    #+#             */
/*   Updated: 2024/12/02 15:44:38 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

t_ray	transform(t_ray ray, t_matrix action)
{
	return (create_ray(multiply_mtx_tp(action, ray.origin),
		multiply_mtx_tp(action, ray.direction)));
}