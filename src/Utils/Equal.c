/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:31:35 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/21 13:34:04 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

/**
 * @brief Compares two double values for equality
 *
 * This function compares two double values and returns true if they
 * are approximately equal, considering a maximum difference.
 *
 * @param nbr1 The first double value to compare
 * @param nbr2 The second double value to compare
 * @return true if the values are approximately equal, false otherwise
 */
bool	equal(double nbr1, double nbr2)
{
	if (fabs(nbr1 - nbr2) < MAX_DIFF)
		return (true);
	return (false);
}
