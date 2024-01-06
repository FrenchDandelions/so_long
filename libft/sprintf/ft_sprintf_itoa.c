/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:05:01 by thole             #+#    #+#             */
/*   Updated: 2023/11/15 15:05:03 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

size_t	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_sputstr(int nb, int len, char *str)
{
	int	i;

	i = len - 1;
	if (nb == 0)
		str[i] = '0';
	if (nb == -2147483648)
		return (str = ft_strcpy(str, "-2147483648"));
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

int	ft_sprintf_itoa(int n, char **s)
{
	char	*str;
	size_t	nb;
	size_t	len;

	nb = n;
	len = ft_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (free(str), 0);
	nb = n;
	str = ft_sputstr(nb, len, str);
	str[len] = '\0';
	*s = str;
	return (ft_strlen(*s));
}
