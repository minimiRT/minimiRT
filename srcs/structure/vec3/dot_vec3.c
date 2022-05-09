/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:46:40 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 14:49:49 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	dot_vec3(t_vec3 first, t_vec3 second)
{
	double	ret;

	ret = (first.x * second.x) \
		+ (first.y * second.y) \
		+ (first.z * second.z);
	return (ret);
}
