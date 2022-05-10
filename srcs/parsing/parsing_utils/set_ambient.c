/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 20:28:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"
#include "parsing_utils.h"

void	set_ambient(t_ambient *ambient, char **splited)
{
	ambient->ratio = parse_ratio(splited[1]);
	ambient->color = parse_color(splited[2]);
}