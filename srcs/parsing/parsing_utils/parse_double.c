/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:23:43 by mypark            #+#    #+#             */
/*   Updated: 2022/05/15 12:41:52 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "parsing_utils.h"
#include "constant.h"

static double	calc_integer_part(char **str)
{
	double	num;

	num = 0;
	while (ft_isdigit(**str))
	{
		num = num * 10 + (double)(**str - '0');
		(*str)++;
	}
	ft_assert(**str == '.' || **str == '\0' || **str == '\n', \
			"Error: invalid format of float\n");
	return (num);
}

static double	calc_rational_part(char **str)
{
	double	pow;
	double	num;

	num = 0;
	pow = 0.1;
	while (ft_isdigit(**str))
	{
		ft_assert(pow >= EPSILON, "Error: invalid range of float\n");
		num += pow * (double)(**str - '0');
		pow *= 0.1;
		(*str)++;
	}
	return (num);
}

double	parse_double(char *str)
{
	double	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	num += calc_integer_part(&str);
	if (*str == '\0')
		return (sign * num);
	str++;
	num += calc_rational_part(&str);
	return (sign * num);
}
