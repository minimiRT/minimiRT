/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:06:10 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 13:13:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"
#include <math.h>

static t_bool	set_root_of_cylinder_side(t_cylinder *cy, \
								t_trace *tr,t_vec3 vec_co, double *root)
{
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		dot_dir;

	dot_dir = dot_vec3(tr->ray.direction, cy->orientation);
	a = dot_vec3(tr->ray.direction, tr->ray.direction) - pow(dot_dir, 2);
	half_b = dot_vec3(tr->ray.direction, vec_co) \
		- dot_dir * dot_vec3(vec_co, cy->orientation);
	c = get_vec3_len_square(vec_co) \
		- pow(dot_vec3(vec_co, cy->orientation), 2) - pow(cy->radius, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	if (discriminant == 0 && (dot_dir = 1 || dot_dir == -1))
		return (FALSE);
	*root = (-half_b - sqrt(discriminant)) / a;
	if (*root < tr->record.min || tr->record.max < *root)
	{
		*root = (-half_b + sqrt(discriminant)) / a;
		if (*root < tr->record.min || tr->record.max < *root)
			return (FALSE);
	}
	return (TRUE);
}

static t_vec3	calc_cylinder_normal(t_cylinder *cylinder, t_trace *tracing)
{
	double	q_height;
	t_vec3	q;
	t_ray	temp_ray;
	t_vec3	normal;

	q_height = dot_vec3(tracing->record.hit_point, cylinder->center);
	temp_ray = init_ray(cylinder->center, cylinder->orientation);
	q = get_point_ray_reach(temp_ray, q_height);
	normal = get_unit_vec3(sub_vec3(tracing->record.hit_point, q));
	return (normal);
}

static t_bool	hit_cylinder_side(t_cylinder *cy, t_trace *tr, t_vec3 vec_co)
{
	t_vec3	hit_point;
	double	root;
	double	radius_square;
	double	half_height_square;
	double	hit_square;

	if (set_root_of_cylinder_side(cy, tr, vec_co, &root) == FALSE)
		return (FALSE);
	hit_point = get_point_ray_reach(tr->ray, root);;
	radius_square = pow(cy->radius, 2);
	half_height_square = pow(cy->height / 2, 2);
	hit_square = get_vec3_len_square(sub_vec3(hit_point, cy->center));
	if (hit_square > radius_square + half_height_square)
		return (FALSE);
	tr->record.distance_from_ray_origin = root;
	tr->record.hit_point = hit_point;
	tr->record.normal = calc_cylinder_normal(cy, tr);
	tr->record.is_front_face = \
				(dot_vec3(tr->ray.direction, tr->record.normal) < 0);
	if (tr->record.is_front_face == FALSE)
		tr->record.normal = mul_vec3_t(tr->record.normal, -1);
	return (TRUE);
}

t_bool	is_hit_circle(t_cylinder *cylinder, t_trace *tracing, t_vec3 point, t_vec3 normal)
{
	double	product;
	double	t;
	t_vec3	origin_sub;
	t_vec3	hit_point;

	product = dot_vec3(normal, tracing->ray.direction);
	if (product >= 0)
		return (FALSE);
	origin_sub = sub_vec3(point, tracing->ray.origin);
	t = dot_vec3(normal, origin_sub) / product;
	if (t < tracing->record.min || tracing->record.max < t)
		return (FALSE);
	hit_point = get_point_ray_reach(tracing->ray, t);
	if (get_vec3_len(sub_vec3(point, hit_point)) > cylinder->radius)
		return (FALSE);
	tracing->record.hit_point = hit_point;
	tracing->record.distance_from_ray_origin = t;
	tracing->record.normal = normal;
	tracing->record.is_front_face = \
			(dot_vec3(tracing->ray.direction, tracing->record.normal) < 0);
	if (tracing->record.is_front_face == FALSE)
		tracing->record.normal = mul_vec3_t(tracing->record.normal, -1);
	return (TRUE);
}

t_bool	hit_cylinder_circle(t_cylinder *cylinder, t_trace *tracing, t_vec3 vec_co)
{
	t_vec3	top_point;
	t_vec3	bottom_point;
	t_ray	temp_ray;
	double	t;

	temp_ray = init_ray(cylinder->center, cylinder->orientation);
	top_point = get_point_ray_reach(temp_ray, cylinder->height / 2);
	bottom_point = get_point_ray_reach(temp_ray, cylinder->height / 2 * -1);
	if (is_hit_circle(cylinder, tracing, top_point, cylinder->orientation) == TRUE)
		return (TRUE);
	if (is_hit_circle(cylinder, tracing, bottom_point, cylinder->orientation) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	hit_cylinder(t_object *object, t_trace *tracing)
{
	t_cylinder	*cylinder;
	t_vec3		vec_co;

	cylinder = object->element;
	vec_co = sub_vec3(tracing->ray.origin, cylinder->center);
	if (hit_cylinder_side(cylinder, tracing, vec_co) == TRUE)
	{
		tracing->record.albedo = object->albedo;
		return (TRUE);
	}
	if (hit_cylinder_circle(cylinder, tracing, vec_co) == TRUE)
	{
		tracing->record.albedo = object->albedo;
		return (TRUE);
	}
	return (FALSE);
}