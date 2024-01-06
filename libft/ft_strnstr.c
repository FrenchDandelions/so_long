/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:37:51 by thole             #+#    #+#             */
/*   Updated: 2023/11/13 11:37:54 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0 && !big)
		return (NULL);
	while (big[i] && little[j] && i < len)
	{
		if (big[i] == little[j])
		{
			j++;
		}
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (little[j] == '\0')
		return ((char *)&big[i - j]);
	else
		return (NULL);
}
