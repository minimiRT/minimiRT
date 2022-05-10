#include "tracing.h"
#include <math.h>

// todo: move to structure/pixel/ray
t_point3	get_point_ray_reach(t_ray ray, double t)
{
	t_point3	point;

	point = add_vec3(ray.origin, mul_vec3_t(ray.direction, t));
	return (point);
}

t_bool	hit_sphere(t_object *object, t_ray ray, t_hit_record *record)
{
	t_sphere	*sphere;
	t_vec3		co;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;

	sphere = object->element;
	co = sub_vec3(ray.origin, sphere->center);
	a = dot_vec3(ray.direction, ray.direction);
	half_b = dot_vec3(ray.direction, co);
	c = dot_vec3(co, co) - sphere->radius_square; 
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < record->min || record->max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < record->min || record->max < root)
			return (FALSE);
	}
	record->distance_from_ray_origin = root;
	record->hit_point = get_point_ray_reach(ray, root);
	record->normal = div_vec3_t(sub_vec3(record->hit_point, sphere->center), sphere->radius);

	// set normal
	record->front_face = (dot_vec3(ray.direction, record->normal) < 0);
	if (record->front_face == FALSE)
		record->normal = mul_vec3_t(record->normal, -1);

	record->albedo = object->albedo;
	return (TRUE);
}

t_bool	hit_object(t_object *object, t_ray ray, t_hit_record *record)
{
	t_bool	is_hitting;
	
	is_hitting = FALSE;
	if (object->type == SPHERE)
		is_hitting = hit_sphere(object, ray, record);
	return (is_hitting);
}

t_bool	hit_objects(t_objects *objects, t_ray ray, t_hit_record *record)
{
	t_bool			is_hitting;
	t_hit_record	tmp_record;

	is_hitting = FALSE;
	while (objects)
	{
		if (hit_object(objects->content, ray, &tmp_record))
		{
			is_hitting = TRUE;
			tmp_record.max = tmp_record.distance_from_ray_origin;
			*record = tmp_record;
		}
		objects = objects->next;
	}
	return (is_hitting);
}
