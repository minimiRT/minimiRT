/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unit_vec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:52:40 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 14:58:34 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	get_unit_vec3(t_vec3 vec)
{
	double	len;

	len = get_vec3_len(vec);
	if (len == 0)
		exit(1); // todo: replace to ft_assert
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
