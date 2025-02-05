/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Count_el.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:06:27 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/05 10:05:58 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_EL_H
# define COUNT_EL_H

typedef struct s_count_el {
	int	sp; // 1 cores & 4 matrizes & 1 obj
	int	pl; // 1 cores & 4 matrizes & 1 obj
	int	cy; // 1 cores & 4 matrizes & 1 obj
	int	lights; // 5 cores & 1 matriz
	int	patterns; // 2 cores & 2 matrizes
}			t_count_el;

t_count_el	calc_sz_pools(char *file_name);
void		parse_count(char *line, t_count_el *counts);

#endif //! COUNT_EL_H