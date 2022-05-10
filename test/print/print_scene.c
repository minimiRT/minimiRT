/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:58:30 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 14:10:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	print_vec3(t_vec3 *vec)
{
	printf("\t\tx:%7.2lf\n", vec->x);
	printf("\t\ty:%7.2lf\n", vec->y);
	printf("\t\tz:%7.2lf\n", vec->z);
}

static void	print_camera(t_camera *cam)
{
	(void)cam;
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

static void	print_sphere(t_sphere *sphere)
{
	static int	count;

	printf("sphere%d:\n", count++);
	printf("\tradius: %.2lf\n", sphere->radius);
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
	printf("\tradius: %.2lf\n", cylinder->radius);
	printf("\theight: %.2lf\n", cylinder->height);
}
static void	print_plane(t_plane *plane)
{
	static int	count;

	printf("plane%d:\n", count++);
	printf("\tcenter:\n");
	print_vec3(&plane->center);
	printf("\torientation:\n");
	print_vec3(&plane->orientation);
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