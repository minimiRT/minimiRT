/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:50:20 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 14:52:10 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	cross_vec3(t_vec3 first, t_vec3 second)
{
	t_vec3	ret;

	ret.x = first.y * second.z - first.z * second.y;
	ret.y = first.z * second.x - first.x * second.z;
	ret.z = first.x * second.y - first.y * second.x;
	return (ret);
}
