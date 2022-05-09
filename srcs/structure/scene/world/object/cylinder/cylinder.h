/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:51:01 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 11:08:50 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "vec3.h"

typedef struct s_cylinder	t_cylinder;

struct s_cylinder
{
	t_point3	center;
	t_vec3		orientation;
	t_color3	color;
	double		radius;
	double		height;
};

#endif