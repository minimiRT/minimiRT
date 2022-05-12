

#include "tracing.h"
#include <math.h>

t_bool	hit_sphere(t_object *object, t_trace *tracing)
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
	if (root < tracing->record.min || tracing->record.max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < tracing->record.min || tracing->record.max < root)
			return (FALSE);
	}
	tracing->record.distance_from_ray_origin = root;
	tracing->record.hit_point = get_point_ray_reach(tracing->ray, root);
	tracing->record.normal = div_vec3_t(sub_vec3(tracing->record.hit_point, sphere->center), sphere->radius); // get_unit으로 바꿀것

	// set normal
	tracing->record.front_face = (dot_vec3(tracing->ray.direction, tracing->record.normal) < 0);
	if (tracing->record.front_face == FALSE)
		tracing->record.normal = mul_vec3_t(tracing->record.normal, -1);

	tracing->record.albedo = object->albedo;
	return (TRUE);
}
