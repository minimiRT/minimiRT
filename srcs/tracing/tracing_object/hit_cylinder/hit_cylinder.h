/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:35:09 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 20:51:27 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_CYLINDER_H
# define HIT_CYLINDER_H

# include "tracing.h"
# include <math.h>

t_bool	hit_cylinder_side(t_cylinder *cy, t_trace *tr, t_vec3 vec_co);
t_bool	hit_cylinder_circle(t_cylinder *cy, t_trace *tr);

#endif
