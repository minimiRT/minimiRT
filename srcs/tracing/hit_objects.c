
#include "tracing.h"
#include <math.h>

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
	co = sub_vec3(ray.orig, sphere->center);
	a = dot_vec3(ray.dir, ray.dir);
	half_b = dot_vec3(ray.dir, co);
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

	record->hit_point = ray_at(ray, root); // todo: implement

	record->normal = div_vec3_t(sub_vec3(record->hit_point, sphere->center), sphere->radius);

	set_face_normal(ray, rec); // todo: implement

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
