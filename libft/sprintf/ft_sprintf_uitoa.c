/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_uitoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:06:25 by thole             #+#    #+#             */
/*   Updated: 2024/01/06 15:06:26 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

size_t	ft_ulen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_usputstr(unsigned int nb, int len, char *str)
{
	int	i;

	i = len - 1;
	if (nb == 0)
		str[i] = '0';
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

int	ft_sprintf_uitoa(unsigned int n, char **s)
{
	char	*str;
	size_t	nb;
	size_t	len;

	nb = n;
	len = ft_ulen(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (free(str), 0);
	nb = n;
	str = ft_usputstr(nb, len, str);
	str[len] = '\0';
	*s = str;
	return (ft_strlen(*s));
}
