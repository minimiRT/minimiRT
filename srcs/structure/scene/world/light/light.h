/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:52:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 10:05:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "vec3.h"
# include "libft.h"

typedef struct s_light	t_light;
typedef t_list			t_lights;

struct	s_light
{
	t_point3	origin;
	t_color3	color;
	double		bright_ratio;
};

t_light	*new_light(t_point3 origin, t_color3 color, double bright_ratio);

#endif