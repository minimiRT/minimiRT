#include "tracing.h"
#include "constant.h"
#include <math.h>

t_bool	is_in_shadow(t_objects *objects, t_ray light_ray, double light_len)
{
	t_hit_record	record_for_shadow;

	record_for_shadow.min = 0.0;
	record_for_shadow.max = light_len;
	if (hit_objects(objects, light_ray, &record_for_shadow))
		return (TRUE);
	return (FALSE);
}

t_color3	get_diffuse_light(t_scene *scene, t_light *light, t_hit_record record)
{
	t_color3	diffuse_light;
	t_vec3		light_dir;
	double		light_len;
	t_ray		light_ray;
	double		kd;

	light_dir = sub_vec3(light->origin, record.hit_point); // todo: replace light_dir to vec_to_light ?
	light_len = get_vec3_len(light_dir);
	light_ray = init_ray(
		add_vec3(
			record.hit_point, 
			mul_vec3_t(record.normal, EPSILON)), light_dir);
	if (is_in_shadow(scene->world.objects, light_ray, light_len))
		return (init_vec3(0, 0, 0));
	light_dir = get_unit_vec3(light_dir);
	kd = fmax(dot_vec3(record.normal, light_dir), 0.0);
	diffuse_light = mul_vec3_t(light->color, kd);
	return (diffuse_light);
}

t_vec3	get_reflect_dir(t_vec3 v, t_vec3 n)
{
	return (sub_vec3(v, mul_vec3_t(n, dot_vec3(v, n) * 2)));
}

t_color3	get_specular_light(t_light *light, t_ray pixel_ray, t_hit_record record)
{
	t_color3	specular_light;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	double		ksn;
	double		ks;

	t_vec3		light_dir;

	light_dir = get_unit_vec3(sub_vec3(light->origin, record.hit_point)); // used before(diffuse_light)
	view_dir = get_unit_vec3(mul_vec3_t(pixel_ray.direction, -1));
	reflect_dir = get_reflect_dir(mul_vec3_t(light_dir, -1), record.normal);
	ksn = 64;
	ks = 0.5;
	spec = pow(fmax(dot_vec3(view_dir, reflect_dir), 0.0), ksn);
	specular_light = mul_vec3_t(mul_vec3_t(light->color, ks), spec);
	return (specular_light);
}

t_color3	get_light_of_pixel(t_scene *scene, t_light *light, t_ray pixel_ray, t_hit_record record)
{
	t_color3	ret;
	t_color3	diffuse;
	t_color3	specular;
	double		brightness;

	diffuse = get_diffuse_light(scene, light, record);
	specular = get_specular_light(light, pixel_ray, record);
	brightness = light->bright_ratio * LUMEN;
	//ret = diffuse;
	//ret = mul_vec3_t(diffuse, brightness);
	ret = mul_vec3_t(add_vec3(diffuse, specular), brightness);
	// ret = specular;
	return (ret);
}

#include "test.h"

t_color3	get_color_from_phong_lighting(t_scene *scene, t_ray pixel_ray, t_hit_record record)
{
	t_color3	ret_light_color;
	t_lights	*lights;

	ret_light_color = init_vec3(0, 0, 0);
	lights = scene->world.lights;
	while (lights)
	{
		ret_light_color = add_vec3(ret_light_color, \
								get_light_of_pixel(scene, lights->content, pixel_ray, record));
		lights = lights->next;
	}
	ret_light_color = add_vec3(ret_light_color, \
					mul_vec3_t(scene->ambient.color, scene->ambient.ratio));
	ret_light_color = mul_vec3(ret_light_color, record.albedo);
	ret_light_color.x = ret_light_color.x > 1 ? 1:ret_light_color.x;
	ret_light_color.y = ret_light_color.y > 1 ? 1:ret_light_color.y;
	ret_light_color.z = ret_light_color.z > 1 ? 1:ret_light_color.z;
	return (ret_light_color);
}
