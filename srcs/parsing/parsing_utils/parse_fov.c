/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:52 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 20:20:17 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"

double	parse_fov(char *str)
{
	double	ret;

	ret = parse_double(str);
	ft_assert(ret >= 0, "Assert: invalid range of height or diameter\n");
	return (ret);
}