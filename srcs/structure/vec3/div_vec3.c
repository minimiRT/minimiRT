/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:42:18 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 15:20:12 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	div_vec3(t_vec3 first, t_vec3 second)
{
	ft_assert((second.x != 0 && second.y != 0 && second.z != 0), \
		"Assert: division by zero in div_vec3\n");
	first.x /= second.x;
	first.y /= second.y;
	first.z /= second.z;
	return (first);
}
