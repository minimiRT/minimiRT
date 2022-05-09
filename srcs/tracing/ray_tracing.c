/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:36:44 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 19:45:48 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"



t_ray		get_pixel_ray(t_camera cam, double u, double v)
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

void	trace_ray_and_draw_pixel(t_scene *scene, double u, double v)
{
	t_ray		pixel_ray;
	t_color3	pixel_color;

	// get ray each pixel
	pixel_ray = get_pixel_ray(scene->camera);
	// get pixel color
	get_pixel_color();
	// draw pixel color
	draw_pixel();	
}

void	drive_ray_tracing(t_scene *scene)
{
	int			i;
	int			j;
	double		u;
	double		v;

	j = scene->canvas.height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			trace_ray_and_draw_pixel(scene, u, v);
		}
	}
}
