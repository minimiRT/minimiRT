/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:36:11 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 16:47:50 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	sub_vec3(t_vec3 first, t_vec3 second)
{
	first.x -= second.x;
	first.y -= second.y;
	first.z -= second.z;
	return (first);
}
