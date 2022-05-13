/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/13 16:12:10 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"
#include "parsing_utils.h"
#include "constant.h"
#include "utils.h"

void	set_ambient(t_ambient *ambient, char **splited)
{
	ft_assert(splited[1] != FT_NULL, "Error: invalid format of Ambient\n");
	ft_assert(splited[2] != FT_NULL, "Error: invalid format of Ambient\n");
	ambient->ratio = parse_ratio(splited[1]);
	ambient->color = parse_color(splited[2]);
}
