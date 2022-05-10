/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:24:49 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 21:26:30 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "utils.h"
#include <stdlib.h>

t_vec3	*dup_vec3(t_vec3 vec)
{
	t_vec3	*duped;

	duped = malloc(sizeof(t_vec3));
	ft_assert(duped != NULL, "Assert: malloc failed in dup_vec3\n");
	duped->x = vec.x;
	duped->y = vec.y;
	duped->z = vec.z;
	return (duped);
}
