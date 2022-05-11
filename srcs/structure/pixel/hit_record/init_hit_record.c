/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hit_record.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:05:04 by mypark            #+#    #+#             */
/*   Updated: 2022/05/11 09:11:31 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "hit_record.h"
#include "constant.h"

t_hit_record	init_hit_record(void)
{
	t_hit_record	record;

	record.min = EPSILON;
	record.max = INFINITY;
	return (record);
}
