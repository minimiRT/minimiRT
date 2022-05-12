/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:11:57 by mypark            #+#    #+#             */
/*   Updated: 2022/05/12 10:33:15 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"

t_bool	hit_plane(t_object *object, t_ray ray, t_hit_record *record)
{
	t_vec3	origin_sub;
	t_plane	*pl;
	double	t;
	double	product;

	pl = object->element;
	product = dot_vec3(pl->normal, ray.direction);
	if (product == 0)
		return (FALSE);
	origin_sub = sub_vec3(pl->center, ray.origin);
	t = dot_vec3(pl->normal, origin_sub) / product;
	record->hit_point = get_point_ray_reach(ray, t);
	record->distance_from_ray_origin = t;
	record->normal = pl->normal;
	record->front_face = (dot_vec3(ray.direction, record->normal) < 0);
	if (record->front_face == FALSE)
		record->normal = mul_vec3_t(record->normal, -1);
	record->albedo = object->albedo;
	return (TRUE);
}