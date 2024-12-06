/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Light_and_Shading.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:52:08 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 14:14:31 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_AND_SHADING_H
# define LIGHT_AND_SHADING_H

# include "Matrices.h"
# include "Sphere.h"

double	*normal_at(t_sp sp, double *wld_pt);

#endif
