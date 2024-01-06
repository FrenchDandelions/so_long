/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:12:57 by thole             #+#    #+#             */
/*   Updated: 2024/01/06 16:12:59 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

char	*ft_itoa_base_ptr(unsigned long long nb, char *base)
{
	char				*dup;
	unsigned long long	i;
	char				*left;
	char				*right;

	dup = NULL;
	i = ft_strlen(base);
	if (nb >= i)
	{
		left = ft_itoa_base_ptr(nb / i, base);
		right = ft_itoa_base_ptr(nb % i, base);
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

int	ft_sprintf_pointer(unsigned long long p, char *base, char **str)
{
	char	*dup;
	char	*copy;
	char	*copy2;

	dup = NULL;
	if (!p)
	{
		copy2 = ft_strdup("(nil)");
		dup = ft_strcpy(dup, copy2);
		free(copy2);
		*str = dup;
		return (5);
	}
	else
	{
		copy2 = ft_strdup("0x");
		copy = ft_itoa_base_ptr(p, base);
		dup = ft_strjoin(copy2, copy);
		free(copy);
		free(copy2);
		*str = dup;
		return (ft_strlen(*str));
	}
}
