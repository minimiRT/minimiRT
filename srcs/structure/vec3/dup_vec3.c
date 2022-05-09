/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:24:49 by mgo               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/09 15:20:20 by mgo              ###   ########.fr       */
=======
/*   Updated: 2022/05/09 14:30:50 by mgo              ###   ########.fr       */
>>>>>>> d432b25095caa9be86b729b37d8c68044f0a3f8d
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <stdlib.h>

t_vec3	*dup_vec3(t_vec3 vec)
{
	t_vec3	*duped;

	duped = malloc(sizeof(t_vec3));
<<<<<<< HEAD
	ft_assert(duped != NULL, "Assert: malloc failed in dup_vec3\n");
=======
	if (duped == NULL)
		exit(1); // todo: replace to ft_assert
>>>>>>> d432b25095caa9be86b729b37d8c68044f0a3f8d
	duped->x = vec.x;
	duped->y = vec.y;
	duped->z = vec.z;
	return (duped);
}
