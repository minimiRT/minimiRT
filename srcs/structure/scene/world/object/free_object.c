/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:44 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 10:02:03 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	free_object(void *object)
{
	t_object	*object_temp;

	object_temp = (t_object *)object;
	free(object->element);
	free(object_temp);
}
