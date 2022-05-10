/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unit_vec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:52:40 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 21:27:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "utils.h"

t_vec3	get_unit_vec3(t_vec3 vec)
{
	double	len;

	len = get_vec3_len(vec);
	ft_assert(len != 0, "Assert: division by zero in get_unit_vec3\n");
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
