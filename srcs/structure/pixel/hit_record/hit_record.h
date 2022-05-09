/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:10:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 13:21:00 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H
# include "vec3.h"
# include "enum.h"

typedef struct s_hit_record t_hit_record;

struct s_hit_record
{
	t_point3	hit_point;
	t_vec3		normal;
	double		min;
	double		max;
	double		distance_from_ray_origin;
	enum e_bool	front_face;
	t_color3	albedo;
};

#endif