/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:51:01 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 11:00:06 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "vec3.h"

typedef struct s_plane t_plane;

struct  s_plane
{
	t_point3	center;
	t_vec3		orientation;
	t_color3	color;
};

#endif