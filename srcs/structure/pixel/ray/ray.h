/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:19:39 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 10:43:33 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vec3.h"

typedef struct s_ray t_ray;

struct s_ray
{
	t_point3	origin;
	t_vec3		direction;
};

t_ray		*new_ray(t_point3 *origin, t_vec3 *direction);
// t_point3	*new_point_from_ray_origin(t_ray *ray, double distance);
void		free_ray(t_ray *ray);

#endif