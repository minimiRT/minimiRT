/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_ray_reach.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:02:14 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 20:11:42 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"

t_point3	get_point_ray_reach(t_ray ray, double t)
{
	t_point3	point;

	point = add_vec3(ray.origin, mul_vec3_t(ray.direction, t));
	return (point);
}
