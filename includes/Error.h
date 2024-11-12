/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:08:29 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/12 14:39:05 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include "garbage_collector.h"

void	warning(char *m1, char *m2, char *m3);
void	error(char *m1, char *m2, char *m3, int code);

#endif // ! ERROR_H