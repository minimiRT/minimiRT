/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:06:10 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 09:46:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"
#include <math.h>

t_bool	hit_cylinder(t_object *object, t_trace *tracing)
{
	t_cylinder	*cylinder;
	t_vec3		origin_sub;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	double		dot_dir;

	cylinder = object->element;
	origin_sub = sub_vec3(tracing->ray.origin, cylinder->center);
	dot_dir = dot_vec3(tracing->ray.direction, cylinder->orientation);
	a = dot_vec3(tracing->ray.direction, tracing->ray.direction) \
		- pow(dot_dir, 2);
	half_b = dot_vec3(tracing->ray.direction, origin_sub) \
		- dot_dir * dot_vec3(origin_sub, cylinder->orientation);
	c = get_vec3_len_square(origin_sub) \
		- pow(dot_vec3(origin_sub, cylinder->orientation), 2) \
		- pow(cylinder->radius, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < tracing->record.min || tracing->record.max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < tracing->record.min || tracing->record.max < root)
			return (FALSE);
	}

	// tracing->record.distance_from_ray_origin = root;
	// tracing->record.hit_point = get_point_ray_reach(tracing->ray, root);
	// tracing->record.normal = div_vec3_t(sub_vec3(tracing->record.hit_point, cylinder->center), cylinder->radius); // get_unit으로 바꿀것

	// // set normal
	// tracing->record.front_face = (dot_vec3(tracing->ray.direction, tracing->record.normal) < 0);
	// if (tracing->record.front_face == FALSE)
	// 	tracing->record.normal = mul_vec3_t(tracing->record.normal, -1);

	// tracing->record.albedo = object->albedo;
	return (TRUE);
}