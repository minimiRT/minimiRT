/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:23:43 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 20:20:51 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	parse_double(char *str)
{
	double	num;
	double	pow;

	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (double)(*str - '0');
		str++;
	}
	ft_assert(*str == '.' || *str == '\0', "Assert: It isn't float in parse_double");
	if (*str == '\0')
		return (num);
	str++;
	pow = 0.1;	//double min max?
	while (ft_isdigit(*str))
	{
		num += ((double)(*str - '0') * pow);
		pow *= 0.1;
		str++;
	}
	return (num);
}