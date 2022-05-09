/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vec3_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:44:28 by mgo               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/09 15:20:06 by mgo              ###   ########.fr       */
=======
/*   Updated: 2022/05/09 14:45:24 by mgo              ###   ########.fr       */
>>>>>>> d432b25095caa9be86b729b37d8c68044f0a3f8d
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	div_vec3_t(t_vec3 vec, double t)
{
<<<<<<< HEAD
	ft_assert(t != 0, "Assert: division by zero in div_vec3_t\n");
=======
	if (t == 0)
		exit(1); // todo: replace to ft_assert
>>>>>>> d432b25095caa9be86b729b37d8c68044f0a3f8d
	vec.x /= t;
	vec.y /= t;
	vec.z /= t;
	return (vec);
}
