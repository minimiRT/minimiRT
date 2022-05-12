/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:58:30 by mypark            #+#    #+#             */
/*   Updated: 2022/05/12 10:40:19 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_vec3(t_vec3 *vec)
{
	printf("\t\tx:%7.6lf\n", vec->x);
	printf("\t\ty:%7.6lf\n", vec->y);
	printf("\t\tz:%7.6lf\n", vec->z);
}

void	print_camera(t_camera *cam)
{
	printf("CAMERA:\n");
	printf("\torigin:\n");
	print_vec3(&cam->origin);
	printf("\tviewport_height: %.6lf\n", cam->viewport_height);
	printf("\tviewport_width : %.6lf\n", cam->viewport_width);
	printf("\thorizontal:\n");
	print_vec3(&cam->horizontal_vec);
	printf("\tvertical:\n");
	print_vec3(&cam->vertical_vec);
	printf("\tfocal:\n");
	print_vec3(&cam->focal_vec);
	printf("\tleft_bottom:\n");
	print_vec3(&cam->left_bottom);
	return ;
}

static void	print_canvas(t_canvas *canvas)
{
	printf("CANVAS:\n");
	printf("\twidth  : %4d\n", canvas->width);
	printf("\theight : %4d\n", canvas->height);
	printf("\taspect_ratio : %lf\n", canvas->aspect_ratio);
}

static void	print_ambient(t_ambient *ambient)
{
	printf("AMBIENT:\n");
	printf("\tratio : %lf\n", ambient->ratio);
	printf("\tcolor :\n");
	print_vec3(&ambient->color);
	return ;
}

void	print_sphere(t_sphere *sphere)
{
	static int	count;

	printf("sphere%d:\n", count++);
	printf("\tradius: %.6lf\n", sphere->radius);
	printf("\tradius_2: %.6lf\n", sphere->radius_square);
	printf("\tcenter:\n");
	print_vec3(&sphere->center);
}

static void	print_cylinder(t_cylinder *cylinder)
{
	static int	count;

	printf("cylinder%d:\n", count++);
	printf("\tcenter:\n");
	print_vec3(&cylinder->center);
	printf("\torientation:\n");
	print_vec3(&cylinder->orientation);
	printf("\tradius: %.6lf\n", cylinder->radius);
	printf("\theight: %.6lf\n", cylinder->height);
}
static void	print_plane(t_plane *plane)
{
	static int	count;

	printf("plane%d:\n", count++);
	printf("\tcenter:\n");
	print_vec3(&plane->center);
	printf("\torientation:\n");
	print_vec3(&plane->normal);
}

static void	print_objects(t_objects *objects)
{
	t_objects	*curr;
	t_object	*object;

	printf("OBJECT:\n");
	curr = objects;
	while (curr)
	{
		object = curr->content;
		if (object->type == SPHERE)
			print_sphere(object->element);
		else if (object->type == PLANE)
			print_plane(object->element);
		else if (object->type == CYLINDER)
			print_cylinder(object->element);
		curr = curr->next;
	}
}

static void	print_lights(t_lights *lights)
{
	t_lights	*curr;
	t_light		*light;
	int			i;

	printf("LIGHTS:\n");
	curr = lights;
	i = 0;
	while (curr)
	{
		light = curr->content;
		printf("light%d:\n", i);
		printf("\tbright_ratio : %lf\n", light->bright_ratio);
		printf("\torigin :\n");
		print_vec3(&light->origin);
		printf("\tcolor :\n");
		print_vec3(&light->color);
		curr = curr->next;
		i++;
	}
}


static void	print_world(t_world *world)
{
	print_objects(world->objects);
	print_lights(world->lights);
	return ;
}

void	print_scene(t_scene *scene)
{
	print_world(&scene->world);
	print_ambient(&scene->ambient);
	print_camera(&scene->camera);
	print_canvas(&scene->canvas);
}