/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:03:23 by mypark            #+#    #+#             */
/*   Updated: 2022/05/09 20:13:47 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**_word_alloc(char const *s, char c)
{
	char		**words;
	int			wc;

	wc = 0;
	while (*s)
	{
		if (*s == c)
			wc++;
		s++;
	}
	words = malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);
	words[wc] = NULL;
	return (words);
}

static void	*_free_words(char **words, int wc)
{
	while (wc-- > 0)
	{
		free(words[wc]);
	}
	free(words);
	return (NULL);
}

char	**ft_strsep(char const *s, char c)
{
	char	**words;
	int		wc;
	int		i;
	int		prev_sep;

	words = _word_alloc(s, c);
	if (words == NULL)
		return (NULL);
	i = 0;
	wc = 0;
	prev_sep = -1;
	while (s[i])
	{
		if (s[i] == c)
		{
			words[wc] = malloc(sizeof(char) * (i - prev_sep));
			if (words[wc] == NULL)
				return (_free_words(words, wc));
			ft_strlcpy(words[wc++], s + start, (i - prev_sep));
			prev_sep = i;
		}
		i++;
	}
	return (words);
}
