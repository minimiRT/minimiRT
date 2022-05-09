/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:36:44 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 21:37:23 by mgo              ###   ########.fr       */
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


/*
static void	init_mlx_win(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!(fdf->mlx))
		exit_error_2msg("mlx_init error\n", NULL);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!(fdf->win))
		exit_error_2msg("mlx_new_window error\n", NULL);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!(fdf->img))
		exit_error_2msg("mlx_new_image error\n", NULL);
	fdf->data_addr = mlx_get_data_addr(fdf->img, \
			&(fdf->bpp), &(fdf->size_line), &(fdf->endian));
}
*/

typedef struct s_mlx t_mlx
struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
};

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

#include <math.h>
t_bool	hit_sphere(t_object *object, t_lights *lights, t_ray ray, t_hit_record *record)
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

t_bool	hit_object(t_object *object, t_lights *lights, t_ray ray, t_hit_record *record)
{
	t_bool	is_hitting;
	
	is_hitting = FALSE;
	if (object->type == SPHERE)
		is_hitting = hit_sphere(object, lights, ray, record);
	return (is_hitting);
}

t_bool	hit_objects(t_scene *scene, t_ray ray, t_hit_record *record)
{
	t_bool			is_hitting;
	t_objects		*objects;
	t_hit_record	tmp_record;

	is_hitting = FALSE;
	objects = scene->world.objects;
	while (objects)
	{
		if (hit_object(objects->content, scene->world.lights, ray, &tmp_record))
		{
			is_hitting = TRUE;
			tmp_record.max = tmp_record.distance_from_ray_origin;
			*record = tmp_record;
		}
		objects = objects->next;
	}
	return (is_hitting);
}

t_color3	get_pixel_color(t_scene *scene, t_ray pixel_ray)
{
	t_color3		pixel_color; // todo: remove
	t_hit_record	record;

	// todo: init_record
	if (hit_objects(scene, pixel_ray, &record))
		return (get_color_using_phong_lighting());
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
