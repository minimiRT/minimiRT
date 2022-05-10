/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:51:01 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 10:02:16 by mypark           ###   ########.fr       */
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

#endif