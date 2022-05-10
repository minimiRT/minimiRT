/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 10:37:30 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_object	*new_object(enum e_object type, void *element, t_color3 albedo)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	object->element = element;
	object->type = type;
	object->albedo = albedo;
	return (object);
}