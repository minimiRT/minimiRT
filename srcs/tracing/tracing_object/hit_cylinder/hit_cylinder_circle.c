/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_circle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:06:10 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 20:07:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"
#include <math.h>

static t_bool	is_hit_circle(t_cylinder *cy, t_trace *tr, \
											t_vec3 point, t_vec3 normal)
{
	double	product;
	double	t;
	t_vec3	origin_sub;
	t_vec3	hit_point;

	product = dot_vec3(normal, tr->ray.direction);
	if (product == 0)
		return (FALSE);
	origin_sub = sub_vec3(point, tr->ray.origin);
	t = dot_vec3(normal, origin_sub) / product;
	if (t < tr->record.min || tr->record.max < t)
		return (FALSE);
	hit_point = get_point_ray_reach(tr->ray, t);
	if (get_vec3_len(sub_vec3(point, hit_point)) > cy->radius)
		return (FALSE);
	tr->record.hit_point = hit_point;
	tr->record.distance_from_ray_origin = t;
	tr->record.max = t;
	tr->record.normal = normal;
	tr->record.is_front_face = \
			(dot_vec3(tr->ray.direction, tr->record.normal) < 0);
	if (tr->record.is_front_face == FALSE)
		tr->record.normal = mul_vec3_t(tr->record.normal, -1);
	return (TRUE);
}

t_bool	hit_cylinder_circle(t_cylinder *cy, t_trace *tr, t_vec3 vec_co)
{
	t_vec3	top_point;
	t_vec3	bottom_point;
	t_ray	temp_ray;
	double	t;

	temp_ray = init_ray(cy->center, cy->orientation);
	top_point = get_point_ray_reach(temp_ray, cy->height / 2);
	bottom_point = get_point_ray_reach(temp_ray, cy->height / 2 * -1);
	if (is_hit_circle(cy, tr, top_point, cy->orientation) == TRUE)
		return (TRUE);
	if (is_hit_circle(cy, tr, bottom_point, mul_vec3_t(cy->orientation, -1)) \
																	== TRUE)
		return (TRUE);
	return (FALSE);
}
