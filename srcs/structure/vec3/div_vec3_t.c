/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vec3_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:44:28 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 21:26:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "utils.h"

t_vec3	div_vec3_t(t_vec3 vec, double t)
{
	ft_assert(t != 0, "Assert: division by zero in div_vec3_t\n");
	vec.x /= t;
	vec.y /= t;
	vec.z /= t;
	return (vec);
}
