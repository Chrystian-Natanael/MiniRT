/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:31:54 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/21 13:35:35 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include "libft.h"
# include "garbage_collector.h"

// ! Convert
int		double_to_int(double value);

// ! Error
void	warning(char *m1, char *m2, char *m3);
void	error(char *m1, char *m2, char *m3, int code);

// ! Equal
bool	equal(double nbr1, double nbr2);

#endif //! UTILS_H
