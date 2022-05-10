/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:22:58 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 13:22:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "parsing_utils.h"
#include "utils.h"
#include "constant.h"

#include <stdio.h>

t_vec3	parse_vec3(char *str)
{
	t_vec3	vec;
	char	**seperated;
	int		wc;

	seperated = ft_strsep(str, ',');
	ft_assert(seperated != FT_NULL, "Assert: malloc failed in parse_vec3\n");
	wc = ft_wordcount(seperated);
	ft_assert(wc == 3, "Assert: invalid input of vector in parse_vec3\n");
	vec.x = parse_double(seperated[0]);
	vec.y = parse_double(seperated[1]);
	vec.z = parse_double(seperated[2]);
	ft_splitfree(seperated);
	return (vec);
}