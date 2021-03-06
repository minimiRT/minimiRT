/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:12:52 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 15:49:44 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"
#include "utils.h"

double	parse_ratio(char *str)
{
	double	ret;

	ret = parse_double(str);
	ft_assert(ret >= 0 && ret <= 1, "Error: invalid range of ratio\n");
	return (ret);
}
