/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:01:34 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 10:41:33 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H
# include "vec3.h"

typedef struct s_ambient	t_ambient;

struct s_ambient
{
	double		ratio;
	t_color3	color;
};

#endif