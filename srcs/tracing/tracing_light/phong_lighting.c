/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:27:45 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 09:28:52 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing_light.h"

static t_bool	is_in_shadow(t_objects *objects, t_hit_point_to_light to_light)
{
	t_trace			tracing_light;
	t_hit_record	record_for_shadow;

	tracing_light.ray = to_light.ray;
	record_for_shadow.min = 0.0;
	record_for_shadow.max = to_light.len;
	tracing_light.record = record_for_shadow;
	if (hit_objects(objects, &(tracing_light)))
		return (TRUE);
	return (FALSE);
}

static void	set_hit_point_to_light(t_light *light, t_hit_record record, \
									t_hit_point_to_light *to_light)
{
	to_light->vec = sub_vec3(light->origin, record.hit_point);
	to_light->unit_vec = get_unit_vec3(to_light->vec);
	to_light->len = get_vec3_len(to_light->vec);
	to_light->ray = init_ray(\
		add_vec3(\
			record.hit_point, \
			mul_vec3_t(record.normal, EPSILON)), \
		to_light->unit_vec);
}

static t_color3	get_each_light_color(t_scene *scene, t_light *light, \
										t_trace *tracing)
{
	t_hit_point_to_light	to_light;
	t_color3				diffuse;
	t_color3				specular;
	double					brightness;
	t_color3				light_color;

	set_hit_point_to_light(light, tracing->record, &to_light);
	if (is_in_shadow(scene->world.objects, to_light))
		return (init_vec3(0, 0, 0));
	diffuse = get_diffuse_light(light, tracing->record, to_light);
	specular = get_specular_light(light, tracing, to_light);
	brightness = light->bright_ratio * LUMEN;
	light_color = mul_vec3_t(add_vec3(diffuse, specular), brightness);
	return (light_color);
}

t_color3	get_color_from_phong_lighting(t_scene *scene, t_trace *tracing)
{
	t_color3	lights_color;
	t_lights	*lights;

	lights_color = init_vec3(0, 0, 0);
	lights = scene->world.lights;
	while (lights)
	{
		lights_color = add_vec3(lights_color, \
						get_each_light_color(scene, lights->content, tracing));
		lights = lights->next;
	}
	lights_color = add_vec3(lights_color, \
					mul_vec3_t(scene->ambient.color, scene->ambient.ratio));
	lights_color = mul_vec3(lights_color, tracing->record.albedo);
	if (lights_color.x > 1)
		lights_color.x = 1;
	if (lights_color.y > 1)
		lights_color.y = 1;
	if (lights_color.z > 1)
		lights_color.z = 1;
	return (lights_color);
}
