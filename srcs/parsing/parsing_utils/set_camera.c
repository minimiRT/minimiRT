/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 18:08:07 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "vec3.h"
#include <math.h>
#include "parsing_utils.h"

static int	is_same_vec3(t_vec3 *a, t_vec3 *b)
{
	if (a->x == b->x && a->y == b->y && a->z == b->z)
		return (1);
	return (0);
}

static int	is_reverse_vec3(t_vec3 *a, t_vec3 *b)
{
	if (a->x == b->x && a->y == -(b->y) && a->z == b->z)
		return (1);
	return (0);
}

void	set_camera(t_camera *camera, t_canvas *canvas, char **splited)
{
	t_vec3	z_axis;
	t_vec3	x_axis;
	t_vec3	y_axis;
	t_vec3	temp_axis;
	double	fov;

	camera->origin = parse_vec3(splited[1]);
	z_axis = mul_vec3_t(get_unit_vec3(parse_vec3(splited[2])), -1);
	fov = parse_double(splited[3]); // 0 <= fov < 180;
	camera->viewport_height = VIEWPORT_HEIGHT;
	camera->viewport_width = camera->viewport_height * canvas->aspect_ratio;
	temp_axis = init_vec3(0, 1, 0);
	if (is_same_vec3(&temp_axis, &z_axis))
		temp_axis = init_vec3(0, 0, -1);
	else if (is_reverse_vec3(&temp_axis, &z_axis))
		temp_axis = init_vec3(0, 0, 1);
	x_axis = get_unit_vec3(cross_vec3(z_axis, temp_axis));
	y_axis = get_unit_vec3(cross_vec3(x_axis, z_axis));
	camera->horizontal_vec = mul_vec3_t(x_axis, camera->viewport_width);
	camera->vertical_vec = mul_vec3_t(y_axis, camera->viewport_height);
	camera->focal_vec = mul_vec3_t(z_axis, (camera->viewport_width / 2) * tan((180 - fov) /2));
	camera->left_bottom = sub_vec3(camera->origin, camera->focal_vec);
	camera->left_bottom = sub_vec3(camera->left_bottom, div_vec3_t(camera->vertical_vec, 2));
	camera->left_bottom = sub_vec3(camera->left_bottom, div_vec3_t(camera->horizontal_vec, 2));
}