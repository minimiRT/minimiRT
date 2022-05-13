/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:07:16 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 09:30:40 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACING_LIGHT_H
# define TRACING_LIGHT_H

# include "tracing.h"
# include "constant.h"
# include <math.h>

typedef struct s_hit_point_to_light	t_hit_point_to_light;

struct s_hit_point_to_light
{
	t_vec3	vec;
	t_vec3	unit_vec;
	double	len;
	t_ray	ray;
};

t_color3	get_diffuse_light(t_light *light, t_hit_record record, \
								t_hit_point_to_light to_light);
t_color3	get_specular_light(t_light *light, t_trace *tracing, \
								t_hit_point_to_light to_light);

#endif
