/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:31:06 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 14:32:49 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <stdlib.h>

t_vec3	*new_vec3(double x, double y, double z)
{
	t_vec3	*new;
	
	new = malloc(sizeof(t_vec3));
	if (new == NULL)
		exit(1); // todo: replace to ft_assert
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
