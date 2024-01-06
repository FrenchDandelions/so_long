/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:35:11 by thole             #+#    #+#             */
/*   Updated: 2024/01/05 15:30:43 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char charset)
{
	if (charset == c)
		return (1);
	else
		return (-1);
}

static int	ft_countwords(char const *str, char charset)
{
	int		word_count;
	int		new_word;
	char	*str_p;

	str_p = (char *)str;
	word_count = 0;
	new_word = 1;
	while (*str_p)
	{
		if (ft_ischarset(*str_p, charset) == -1)
		{
			if (new_word == 1)
				word_count++;
			new_word = 0;
		}
		else
			new_word = 1;
		str_p++;
	}
	return (word_count);
}

static char	*ft_extract_word(char const **str, char charset)
{
	int		i;
	int		size;
	char	*word;

	i = 0;
	while (ft_ischarset(**str, charset) >= 0)
		(*str)++;
	while ((*str)[i] && ft_ischarset((*str)[i], charset) == -1)
		i++;
	if (i == 0)
		return (NULL);
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	size = i;
	i = 0;
	while (i < size)
	{
		word[i] = (*str)[i];
		i++;
	}
	word[i] = '\0';
	*str += size;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_string;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = ft_countwords(s, c);
	tab_string = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!tab_string)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		tab_string[i] = ft_extract_word(&s, c);
		if (!tab_string[i])
		{
			while (i > 0)
				free(tab_string[--i]);
			free(tab_string);
			return (NULL);
		}
		i++;
	}
	tab_string[i] = 0;
	return (tab_string);
}
