/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:28 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 20:15:39 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H
# include "vec3.h"

t_vec3	parse_vec3(char *str);
double	parse_double(char *str);
char	**ft_strsep(char const *s, char c);

# endif
