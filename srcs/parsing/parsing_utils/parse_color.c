/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:17:52 by mypark            #+#    #+#             */
/*   Updated: 2022/05/11 20:15:02 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"
#include "utils.h"

t_vec3	parse_color(char *str)
{
	t_vec3	ret;

	ret = parse_vec3(str);
	ft_assert(ret.x >= 0 && ret.x <= 255, "Assert: invalid range of color value\n");
	ft_assert(ret.y >= 0 && ret.y <= 255, "Assert: invalid range of color value\n");
	ft_assert(ret.z >= 0 && ret.z <= 255, "Assert: invalid range of color value\n");
	ret = div_vec3_t(ret, 255);
	return (ret);
}