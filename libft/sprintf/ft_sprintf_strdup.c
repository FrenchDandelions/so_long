/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_strdup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:38:13 by thole             #+#    #+#             */
/*   Updated: 2024/01/06 14:38:15 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

int	ft_sprintf_strdup(const char *s, char **str)
{
	char	*copy;
	int		i;

	i = 0;
	if (!s)
		return (ft_sprintf_strdup2(&(*str)));
	copy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!copy)
		return (0);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	*str = copy;
	return (ft_strlen(*str));
}

int	ft_sprintf_strdup2(char **str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_calloc(7, sizeof(char));
	if (!copy)
		return (0);
	copy = ft_strcpy(copy, "(null)");
	*str = copy;
	return (ft_strlen(*str));
}
