/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:51:01 by mypark            #+#    #+#             */
/*   Updated: 2022/05/12 10:25:22 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAIN_H
# define PLAIN_H
# include "vec3.h"

typedef struct s_plane t_plane;

struct  s_plane
{
	t_point3	center;
	t_vec3		normal;
};

t_plane	*new_plane(t_point3 center, t_vec3 orientation);

#endif