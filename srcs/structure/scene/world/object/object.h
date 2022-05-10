/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:09:29 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 09:50:01 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "cylinder.h"
# include "plane.h"
# include "sphere.h"
# include "libft.h"

typedef struct s_object	t_object;
typedef t_list			t_objects;

enum e_object
{
	SPHERE,
	PLANE,
	CYLINDER
};

struct s_object
{
	enum e_object	type;
	void			*element;
	t_color3		albedo;
};

t_object	*new_object(enum e_object type, void *element, t_color3 albedo);
void		free_object(void *object);

#endif