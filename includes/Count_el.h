/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Count_el.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:06:27 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/03 12:06:58 by cnatanae         ###   ########.fr       */
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

#endif //! COUNT_EL_H