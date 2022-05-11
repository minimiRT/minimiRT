/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:19:39 by mypark            #+#    #+#             */
/*   Updated: 2022/05/11 09:22:14 by mypark           ###   ########.fr       */
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

t_ray		init_ray(t_point3 origin, t_vec3 direction);
t_point3	get_point_ray_reach(t_ray ray, double t);

#endif