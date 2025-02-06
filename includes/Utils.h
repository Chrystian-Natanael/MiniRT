/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:31:54 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/06 12:47:03 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include "libft.h"
# include "garbage_collector.h"
# include <stdbool.h>

# define MAX_DIFF 0.00001

// ! Convert
int		dtoi(double value);

// ! Error
void	warning(char *m1, char *m2, char *m3);
void	error(char *m1, char *m2, char *m3, int code);

// ! Equal
bool	equal(double nbr1, double nbr2);

double	ft_atod(const char *nptr);

// ! Swap
void	swap(double *t1, double *t2);

#endif //! UTILS_H
