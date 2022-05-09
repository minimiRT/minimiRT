/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vec3_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:44:28 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 16:49:46 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	div_vec3_t(t_vec3 vec, double t)
{
	ft_assert(t != 0, "Assert: division by zero in div_vec3_t\n");
	vec.x /= t;
	vec.y /= t;
	vec.z /= t;
	return (vec);
}
