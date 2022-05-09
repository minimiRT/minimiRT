/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:10:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 11:14:44 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H
# include "ray.h"
# include "hit_record.h"

typedef struct s_pixel	t_pixel;

struct s_pixel
{
	t_ray			ray;
	t_hit_record	record;
	t_color3		color;
};

#endif