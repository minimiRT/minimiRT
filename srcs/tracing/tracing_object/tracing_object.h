/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_object.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:35:09 by mgo               #+#    #+#             */
/*   Updated: 2022/05/13 10:50:38 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACING_OBJECT_H
# define TRACING_OBJECT_H

# include "tracing.h"
# include <math.h>

t_bool	hit_sphere(t_object *object, t_trace *tracing);
t_bool	hit_plane(t_object *object, t_trace *tracing);
t_bool	hit_cylinder(t_object *object, t_trace *tracing);

#endif
