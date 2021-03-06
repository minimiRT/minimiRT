/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_positive_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:52 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 15:54:40 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"
#include "utils.h"

double	parse_positive_double(char *str)
{
	double	ret;

	ret = parse_double(str);
	ft_assert(ret >= 0, "Error: invalid value of diameter or height\n");
	return (ret);
}
