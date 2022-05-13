/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:11:02 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 09:33:05 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing_light.h"

t_color3	get_diffuse_light(t_light *light, t_hit_record record, \
								t_hit_point_to_light to_light)
{
	t_color3	diffuse_light;
	double		cos_between_normal_and_light;

	cos_between_normal_and_light = fmax(\
									dot_vec3(record.normal, to_light.unit_vec), \
									0.0);
	diffuse_light = mul_vec3_t(light->color, cos_between_normal_and_light);
	return (diffuse_light);
}
