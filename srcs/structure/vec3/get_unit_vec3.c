/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unit_vec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:52:40 by mgo               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/09 15:20:27 by mgo              ###   ########.fr       */
=======
/*   Updated: 2022/05/09 14:58:34 by mgo              ###   ########.fr       */
>>>>>>> d432b25095caa9be86b729b37d8c68044f0a3f8d
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	get_unit_vec3(t_vec3 vec)
{
	double	len;

	len = get_vec3_len(vec);
<<<<<<< HEAD
	ft_assert(len != 0, "Assert: division by zero in get_unit_vec3\n");
=======
	if (len == 0)
		exit(1); // todo: replace to ft_assert
>>>>>>> d432b25095caa9be86b729b37d8c68044f0a3f8d
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
