#include "tracing.h"
#include <math.h>

#include "test.h"

// test
void	print_ray(t_ray *ray)
{
	printf("ray :\n");
	print_vec3(&ray->direction);
}

//t_bool	hit_sphere(t_object *object, t_ray ray, t_hit_record *record)
t_bool	hit_sphere(t_object *object, t_trace *tracing, t_hit_record *tmp_record)
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
	co = sub_vec3(tracing->ray.origin, sphere->center);
	a = dot_vec3(tracing->ray.direction, tracing->ray.direction);
	half_b = dot_vec3(tracing->ray.direction, co);
	c = dot_vec3(co, co) - sphere->radius_square; 
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < tmp_record->min || tmp_record->max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < tmp_record->min || tmp_record->max < root)
			return (FALSE);
	}
	tmp_record->distance_from_ray_origin = root;
	tmp_record->hit_point = get_point_ray_reach(tracing->ray, root);
	tmp_record->normal = div_vec3_t(sub_vec3(tmp_record->hit_point, sphere->center), sphere->radius); // get_unit으로 바꿀것

	// set normal
	tmp_record->front_face = (dot_vec3(tracing->ray.direction, tmp_record->normal) < 0);
	if (tmp_record->front_face == FALSE)
		tmp_record->normal = mul_vec3_t(tmp_record->normal, -1);

	tmp_record->albedo = object->albedo;
	return (TRUE);
}

//t_bool	hit_object(t_object *object, t_ray ray, t_hit_record *record)
t_bool	hit_object(t_object *object, t_trace *tracing, t_hit_record *tmp_record)
{
	t_bool	is_hitting;
	
	is_hitting = FALSE;
	if (object->type == SPHERE)
		is_hitting = hit_sphere(object, tracing, tmp_record); //is_hitting = hit_sphere(object, ray, tmp_record);
	return (is_hitting);
}

t_bool	hit_objects(t_objects *objects, t_trace *tracing)
{
	t_bool			is_hitting;
	t_hit_record	tmp_record;

	tmp_record = tracing->record; // todo: replace to init ?
	is_hitting = FALSE;
	while (objects)
	{
		if (hit_object(objects->content, tracing, &tmp_record)) // ray, record
		{
			is_hitting = TRUE;
			tmp_record.max = tmp_record.distance_from_ray_origin;
			// todo: debug to add record.max comparison
			tracing->record = tmp_record;
		}
		objects = objects->next;
	}
	return (is_hitting);
}
