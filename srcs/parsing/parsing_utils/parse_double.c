/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:23:43 by mypark            #+#    #+#             */
/*   Updated: 2022/05/11 11:14:59 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "parsing_utils.h"

#include "test.h"

double	parse_double(char *str)
{
	double	num;
	double	pow;
	int		sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (double)(*str - '0');
		str++;
	}
	ft_assert(*str == '.' || *str == '\0' || *str == '\n', "Assert: It isn't float in parse_double\n");
	if (*str == '\0')
		return (sign * num);
	str++;
	pow = 0.1;	//double min max?
	while (ft_isdigit(*str))
	{
		num += ((double)(*str - '0') * pow);
		pow *= 0.1;
		str++;
	}
	return (sign * num);
}