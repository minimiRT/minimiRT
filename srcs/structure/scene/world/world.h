/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:19:10 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 13:30:08 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include "object.h"
# include "light.h"
# include "libft.h"

typedef struct s_world	t_world;

struct s_world
{
	t_objects	*objects;
	t_lights	*lights;
};

#endif