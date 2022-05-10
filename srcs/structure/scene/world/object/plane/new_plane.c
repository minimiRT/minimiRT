/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 11:02:54 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "constant.h"
#include "utils.h"
#include <stdlib.h>

t_plane	*new_plane(t_point3 center, t_vec3 orientation)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	ft_assert(plane != FT_NULL, "Assert: malloc failed in new_plane\n");
	plane->center = center;
	plane->orientation = orientation;
	return (plane);
}