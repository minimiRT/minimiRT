/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:31:06 by mgo               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/09 15:20:47 by mgo              ###   ########.fr       */
=======
/*   Updated: 2022/05/09 14:32:49 by mgo              ###   ########.fr       */
>>>>>>> d432b25095caa9be86b729b37d8c68044f0a3f8d
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <stdlib.h>

t_vec3	*new_vec3(double x, double y, double z)
{
	t_vec3	*new;
<<<<<<< HEAD

	new = malloc(sizeof(t_vec3));
	ft_assert(new != NULL, "Assert: malloc failed in new_vec3\n");
=======
	
	new = malloc(sizeof(t_vec3));
	if (new == NULL)
		exit(1); // todo: replace to ft_assert
>>>>>>> d432b25095caa9be86b729b37d8c68044f0a3f8d
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
