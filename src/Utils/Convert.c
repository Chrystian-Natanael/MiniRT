/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:22:05 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/21 13:34:09 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

/**
 * @brief Converts a double to an integer
 *
 * This function converts a double value to an integer by rounding it to
 * the nearest integer.
 *
 * @param value The double value to be converted
 * @return The rounded integer value
 */
int	double_to_int(double value)
{
	return ((int)round(value));
}
