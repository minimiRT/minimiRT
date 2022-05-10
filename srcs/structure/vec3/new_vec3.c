/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:31:06 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 21:27:14 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "utils.h"
#include <stdlib.h>

t_vec3	*new_vec3(double x, double y, double z)
{
	t_vec3	*new;

	new = malloc(sizeof(t_vec3));
	ft_assert(new != NULL, "Assert: malloc failed in new_vec3\n");
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
