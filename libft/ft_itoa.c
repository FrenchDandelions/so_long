/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:28:58 by thole             #+#    #+#             */
/*   Updated: 2023/11/13 11:28:59 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
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

static char	*ft_putstr(int nb, int len, char *str)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		nb = -nb;
	}
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

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			len;

	nb = n;
	len = ft_len(nb);
	if (n == -2147483648)
	{
		str = (char *)malloc(12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	nb = n;
	str = ft_putstr(nb, len, str);
	str[len] = '\0';
	return (str);
}
