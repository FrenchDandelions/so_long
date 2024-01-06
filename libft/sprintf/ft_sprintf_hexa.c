/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:19:42 by thole             #+#    #+#             */
/*   Updated: 2024/01/06 15:19:44 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

char	*ft_itoa_base_hexa(unsigned int nb, char *base)
{
	char			*dup;
	unsigned int	i;
	char			*left;
	char			*right;

	dup = NULL;
	i = ft_strlen(base);
	if (nb >= i)
	{
		left = ft_itoa_base_hexa(nb / i, base);
		right = ft_itoa_base_hexa(nb % i, base);
		dup = ft_strjoin(left, right);
		free(left);
		free(right);
	}
	else
	{
		dup = (char *)malloc(sizeof(char) * 2);
		if (!dup)
			return (NULL);
		dup[0] = base[nb];
		dup[1] = '\0';
	}
	return (dup);
}

int	ft_sprintf_hexa(unsigned int nb, char *base, char **str)
{
	*str = ft_itoa_base_hexa(nb, base);
	return (ft_strlen(*str));
}
