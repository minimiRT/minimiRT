/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:22:58 by mypark            #+#    #+#             */
/*   Updated: 2022/05/15 15:52:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "parsing_utils.h"
#include "utils.h"
#include "constant.h"

t_vec3	parse_vec3(char *str)
{
	t_vec3	vec;
	char	**seperated;
	int		wc;
	int		i;

	seperated = ft_strsep(str, ',');
	ft_assert(seperated != FT_NULL, "Error: malloc failed in parse_vec3\n");
	wc = ft_wordcount(seperated);
	ft_assert(wc == 3, "Error: invalid format of vector\n");
	i = -1;
	while (++i < wc)
		ft_assert(*seperated[i] != '\0' && *seperated[i] != '\n', \
				"Error: invalid format of vector\n");
	vec.x = parse_double(seperated[0]);
	vec.y = parse_double(seperated[1]);
	vec.z = parse_double(seperated[2]);
	ft_splitfree(seperated);
	return (vec);
}
