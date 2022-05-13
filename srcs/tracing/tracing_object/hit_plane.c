/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:11:57 by mypark            #+#    #+#             */
/*   Updated: 2022/05/12 14:44:19 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"

t_bool	hit_plane(t_object *object, t_trace *tracing)
{
	t_vec3	origin_sub;
	t_plane	*pl;
	double	t;
	double	product;

	pl = object->element;
	product = dot_vec3(pl->normal, tracing->ray.direction);
	if (product >= 0)
		return (FALSE);
	origin_sub = sub_vec3(pl->center, tracing->ray.origin);
	t = dot_vec3(pl->normal, origin_sub) / product;
	if (t < tracing->record.min || tracing->record.max < t)
		return (FALSE);
	tracing->record.hit_point = get_point_ray_reach(tracing->ray, t);
	tracing->record.distance_from_ray_origin = t;
	tracing->record.normal = pl->normal;
	tracing->record.is_front_face = \
			(dot_vec3(tracing->ray.direction, tracing->record.normal) < 0);
	if (tracing->record.is_front_face == FALSE)
		tracing->record.normal = mul_vec3_t(tracing->record.normal, -1);
	tracing->record.albedo = object->albedo;
	return (TRUE);
}
