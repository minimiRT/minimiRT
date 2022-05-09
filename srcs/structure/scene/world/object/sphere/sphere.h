/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refigo <refigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:51:01 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 10:35:05 by refigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "vec3.h"

typedef struct s_sphere t_sphere;

struct  s_sphere
{
	t_point3	center;
	double		radius;
	double		radius_square;
};

void		free_sphere(t_sphere *sphere);
t_sphere	*new_sphere(t_point3 *center, double radius);

#endif