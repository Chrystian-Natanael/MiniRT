/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Count_El.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:06:27 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:09:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_EL_H
# define COUNT_EL_H

typedef struct s_count_el {
	int	sp;
	int	pl;
	int	cy;
	int	lights;
	int	patterns;
}			t_count_el;

t_count_el	calc_sz_pools(char *file_name);
void		parse_count(char *line, t_count_el *counts);

#endif //! COUNT_EL_H
