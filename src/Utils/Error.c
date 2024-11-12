/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:08:26 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/12 14:15:54 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.h"

void	warning(char *m1, char *m2, char *m3)
{
	ft_putstr_fd(m1, ERROR);
	ft_putstr_fd(m2, ERROR);
	ft_putendl_fd(m3, ERROR);
}

void	error(char *m1, char *m2, char *m3, int code)
{
	ft_putstr_fd(m1, ERROR);
	ft_putstr_fd(m2, ERROR);
	ft_putendl_fd(m3, ERROR);
	quit(code);
}
