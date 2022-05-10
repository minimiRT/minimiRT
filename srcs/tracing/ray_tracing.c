/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:36:44 by mgo               #+#    #+#             */
/*   Updated: 2022/05/10 13:14:53 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"


/*

	ray_tracing
		tracing
			pixel_color
				hit
		drawing

*/


static t_ray	get_pixel_ray(t_camera cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam.origin;
	ray.direction = get_unit_vec3(
						sub_vec3(
							add_vec3(
								add_vec3(
									cam.left_bottom, 
									mul_vec3_t(cam.horizontal_vec, u)), 
								mul_vec3_t(cam.vertical_vec, u)), 
							cam.origin));
	return (ray);
}

t_bool	hit_objects(t_objects *objects, t_ray ray, t_hit_record *record)

t_bool	is_in_shadow(t_objects *objects, t_ray light_ray, double light_len)
{
	t_hit_record	record_for_shadow;

	record_for_shadow.min = 0.0;
	record_for_shadow.max = light_len;
	if (hit_objects(objects, light_ray, record_for_shadow))
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

	light_dir = sub_vec3(light->origin, record.hit_point); // todo: replace to vec_to_light ?
	light_len = get_vec3_len(light_dir);
	light_ray = init_ray(
		add_vec3(record.hit_point, mul_vec3_t(record.normal, 1e-6), light_dir)
	); // todo: implement
	// +todo: replace 1e-6 macro EPSILON
	if (is_in_shadow(scene->world.objects, light_ray, light_len))
		return (init_vec3(0, 0, 0));
	light_dir = get_unit_vec3(light_dir);
	kd = fmax(dot_vec3(record.normal, light_dir), 0.0);
	diffuse_light = mul_vec3_t(light.color, kd);
	return (diffuse_light);
}

t_color3	get_specular_light(t_scene *scene, t_light *light, t_ray pixel_ray, t_hit_record record)
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
	specular_light = mul_vec3_t(mul_vec3_t(light.color, ks), spec);
	return (specular_light);
}

t_color3	get_light_of_pixel(t_scene *scene, t_light *light, t_ray pixel_ray, t_hit_record record)
{
	t_color3	ret;
	t_color3	diffuse;
	t_color3	specular;
	double		brightness;
	
	// get diffuse
	diffuse = get_diffuse_light(scene, light, record);

	// get specular
	specular = get_specular_light(scene, light, pixel_ray, record);

	brightness = light.bright_ratio * 3; // todo: replace 3 to LUMEN
	
	// ret = diffuse + specular
	ret = mul_vec3_t(add_vec3(diffuse, specular), brightness);
	return (ret);
}

t_color3	get_color_from_phong_lighting(t_scene *scene, t_ray pixel_ray, t_hit_record record)
{
	t_color3	ret_light_color;
	t_lights	*lights;

	ret_light_color = init_vec3(0, 0, 0); // todo: implement
	lights = scene->world.lights;
	while (lights)
	{
		ret_light_color = add_vec3(ret_light_color, \
								get_light_of_pixel(scene, lights->content, pixel_ray, record));
		lights = lights->next;
	}
	ret_light_color = add_vec3(ret_light_color, \
					mul_vec3_t(scene->ambient.color, scene->ambient.ratio));
	return (ret_light_color);
}

t_color3	get_pixel_color(t_scene *scene, t_ray pixel_ray)
{
	t_color3		pixel_color; // todo: remove
	t_hit_record	record;

	// todo: init_record
	if (hit_objects(scene->world.objects, pixel_ray, &record))
		return (get_color_from_phong_lighting(scene, pixel_ray, record));
	else
		return (pixel_color); // return black
}

void	trace_ray_and_draw_pixel(t_scene *scene, double u, double v)
{
	t_ray		pixel_ray;
	t_color3	pixel_color;

	pixel_ray = get_pixel_ray(scene->camera);
	
	// get pixel color
	pixel_color = get_pixel_color(scene, pixel_ray);
	
	// draw pixel color(using mlx)
	draw_pixel(); // convert color3 to 16-bit color value
}

// todo: implement setting mlx function before this function
void	drive_ray_tracing(t_scene *scene)
{
	int			x_coord;
	int			y_coord;
	double		u;
	double		v;
	
	t_mlx		mlx;	// buffer

	y_coord = scene->canvas.height;
	while (--y_coord >= 0)
	{
		x_coord = -1;
		while (++x_coord < scene->canvas.width)
		{
			u = (double)x_coord / (scene->canvas.width - 1);
			v = (double)y_coord / (scene->canvas.height - 1);
			trace_ray_and_draw_pixel(scene, u, v);
		}
	}
}
