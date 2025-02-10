/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_Bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:08:26 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:36:16 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils_Bonus.h"

/**
 * @brief Displays a warning message
 *
 * This function displays a warning message composed of three parts.
 *
 * @param m1 First part of the warning message
 * @param m2 Second part of the warning message
 * @param m3 Third part of the warning message
 */
void	warning(char *m1, char *m2, char *m3)
{
	ft_putstr_fd(m1, ERROR);
	ft_putstr_fd(m2, ERROR);
	ft_putendl_fd(m3, ERROR);
}

/**
 * @brief Displays an error message and terminates the program
 *
 * This function displays an error message composed of three parts and
 * terminates the program with the provided error code.
 *
 * @param m1 First part of the error message
 * @param m2 Second part of the error message
 * @param m3 Third part of the error message
 * @param code Error code to terminate the program
 */
void	error(char *m1, char *m2, char *m3, int code)
{
	ft_putstr_fd(m1, ERROR);
	ft_putstr_fd(m2, ERROR);
	ft_putendl_fd(m3, ERROR);
	quit(code);
}
