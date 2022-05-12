/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:36:44 by mgo               #+#    #+#             */
/*   Updated: 2022/05/12 14:32:20 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"

static void	set_pixel_ray(t_camera *cam, t_pixel *pixel)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.direction = get_unit_vec3(\
				sub_vec3(\
					add_vec3(\
						add_vec3(\
							cam->left_bottom, \
							mul_vec3_t(cam->horizontal_vec, pixel->x_ratio)), \
						mul_vec3_t(cam->vertical_vec, pixel->y_ratio)), \
					cam->origin));
	pixel->tracing.ray = ray;
}

static void	set_pixel_color(t_scene *scene, t_pixel *pixel)
{
	if (hit_objects(scene->world.objects, &(pixel->tracing)))
		pixel->color = get_color_from_phong_lighting(scene, &(pixel->tracing));
	else
		pixel->color = init_vec3(0, 0, 0);
}

static void	trace_ray_and_draw_pixel(t_scene *scene, t_pixel *pixel)
{
	set_pixel_ray(&scene->camera, pixel);
	set_pixel_color(scene, pixel);
	draw_pixel(scene, pixel);
}

void	drive_ray_tracing(t_scene *scene)
{
	t_pixel		pixel;
	t_mlx_info	*mlx_info;

	pixel.y_coord = scene->canvas.height;
	while (--(pixel.y_coord) >= 0)
	{
		pixel.x_coord = -1;
		while (++(pixel.x_coord) < scene->canvas.width)
		{
			pixel.x_ratio = (double)(pixel.x_coord) / (scene->canvas.width - 1);
			pixel.y_ratio = (double)(pixel.y_coord) / (scene->canvas.height - 1);
			trace_ray_and_draw_pixel(scene, &pixel);
		}
	}
	mlx_info = &scene->mlx_info;
	mlx_put_image_to_window(mlx_info->mlx, mlx_info->win, mlx_info->img, 0, 0);
}
