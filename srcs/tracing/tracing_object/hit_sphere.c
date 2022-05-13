/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:27:40 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 13:26:51 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing_object.h"

static t_bool	set_root_of_sphere(t_sphere *sphere, t_trace *tracing, \
											t_vec3 vec_co, double *root)
{
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;

	a = dot_vec3(tracing->ray.direction, tracing->ray.direction);
	half_b = dot_vec3(tracing->ray.direction, vec_co);
	c = dot_vec3(vec_co, vec_co) - sphere->radius_square;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	*root = (-half_b - sqrtd) / a;
	if (*root < tracing->record.min || tracing->record.max < *root)
	{
		*root = (-half_b + sqrtd) / a;
		if (*root < tracing->record.min || tracing->record.max < *root)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	hit_sphere(t_object *object, t_trace *tracing)
{
	t_sphere	*sphere;
	t_vec3		vec_co;
	double		root;

	sphere = object->element;
	vec_co = sub_vec3(tracing->ray.origin, sphere->center);
	if (set_root_of_sphere(sphere, tracing, vec_co, &root) == FALSE)
		return (FALSE);
	tracing->record.distance_from_ray_origin = root;
	tracing->record.hit_point = get_point_ray_reach(tracing->ray, root);
	tracing->record.normal = get_unit_vec3(\
						sub_vec3(tracing->record.hit_point, sphere->center));
	tracing->record.is_front_face = \
				(dot_vec3(tracing->ray.direction, tracing->record.normal) < 0);
	if (tracing->record.is_front_face == FALSE)
		tracing->record.normal = mul_vec3_t(tracing->record.normal, -1);
	tracing->record.albedo = object->albedo;
	return (TRUE);
}
