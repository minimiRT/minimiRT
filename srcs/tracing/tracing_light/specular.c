/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:15:05 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 19:56:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing_light.h"

static t_vec3	get_vec_reflect(t_vec3 vec_to_light, t_vec3 vec_normal)
{
	t_vec3	vec_reflect;

	vec_reflect = sub_vec3(\
		mul_vec3_t(\
			vec_normal, \
			2 * dot_vec3(vec_to_light, vec_normal)), \
		vec_to_light);
	return (vec_reflect);
}

static t_vec3	get_vec_reflect_reversed(t_vec3 vec_to_light, \
											t_vec3 vec_normal)
{
	t_vec3	vec_reflect_reversed;

	vec_reflect_reversed = sub_vec3(\
		vec_to_light, \
		mul_vec3_t(\
			vec_normal, \
			2 * dot_vec3(vec_to_light, vec_normal)));
	return (vec_reflect_reversed);
}

t_color3	get_specular_light(t_light *light, t_trace *tracing, \
								t_hit_point_to_light to_light)
{
	t_vec3		vec_reflect_reversed;
	double		cos_between_reflect_and_cam;
	double		shininess_value;
	double		specular_ratio;
	double		specular;

	shininess_value = 128;
	specular_ratio = 1.0;
	vec_reflect_reversed = get_vec_reflect_reversed(to_light.unit_vec, \
													tracing->record.normal);
	cos_between_reflect_and_cam = dot_vec3(tracing->ray.direction, \
											vec_reflect_reversed);
	specular = pow(fmax(cos_between_reflect_and_cam, 0.0), shininess_value);
	return (mul_vec3_t(mul_vec3_t(light->color, specular_ratio), specular));
}
