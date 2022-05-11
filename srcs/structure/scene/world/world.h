/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:19:10 by mypark            #+#    #+#             */
/*   Updated: 2022/05/11 10:45:08 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include "libft.h"
# include "object.h"
# include "light.h"

typedef struct s_world	t_world;

struct s_world
{
	t_objects	*objects;
	t_lights	*lights;
};

#endif