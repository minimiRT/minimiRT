/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:09:29 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 14:09:12 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
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

t_object	*new_object(enum e_object type, void *element, t_color3 *albedo);
void		free_object(void *object);

#endif