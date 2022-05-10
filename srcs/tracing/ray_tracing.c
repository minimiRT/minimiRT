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

// todo: move to structure/pixel/hit_record
#include <math.h>
t_hit_record	init_hit_record(void)
{
	t_hit_record	record;

	record.min = 1e-6; // todo: replace to EPSILON
	record.max = INFINITY;
	return (record);
}

t_color3	get_pixel_color(t_scene *scene, t_ray pixel_ray)
{
	t_hit_record	record;

	record = init_hit_record(record);
	if (hit_objects(scene->world.objects, pixel_ray, &record))
		return (get_color_from_phong_lighting(scene, pixel_ray, record));
	else
		return (init_vec3(0, 0, 0)); // return black
}

void	trace_ray_and_draw_pixel(t_scene *scene, double u, double v)
{
	t_ray		pixel_ray;
	t_color3	pixel_color;

	pixel_ray = get_pixel_ray(scene->camera);
	pixel_color = get_pixel_color(scene, pixel_ray);

	// draw pixel color(using mlx)
	//draw_pixel(); // convert color3 to 16-bit color value
}

void	drive_ray_tracing(t_scene *scene)
{
	int			x_coord;
	int			y_coord;
	double		u;
	double		v;

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
