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

#include "libft.h"

int	ft_ptr_len(unsigned long long p, char *base)
{
	unsigned long long	i;
	unsigned long long	base_len;
	unsigned long long	n;

	n = p;
	base_len = ft_strlen(base);
	i = 2;
	if (!p)
		return (5);
	while (n != 0)
	{
		i++;
		n /= base_len;
	}
	return (i);
}

void	ft_putptr(unsigned long long p, char *base, int fd)
{
	unsigned long long	i;
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	i = p;
	if (i < base_len)
		ft_putchar_fd(base[i], fd);
	else
	{
		ft_putptr(i / base_len, base, fd);
		ft_putptr(i % base_len, base, fd);
	}
}

void	ft_printptr(unsigned long long p, char *base, int fd)
{
	if (!p)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		ft_putptr(p, base, fd);
	}
}
