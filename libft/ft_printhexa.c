/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:51:39 by thole             #+#    #+#             */
/*   Updated: 2023/11/15 12:52:06 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_len(unsigned int n, char *base)
{
	unsigned long int	i;
	int					base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base_len;
	}
	return (i);
}

void	ft_putnbr_hexa_base(unsigned int n, char *base, int fd)
{
	unsigned long int	i;
	unsigned int		base_len;

	i = n;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return ;
	if (i < base_len)
		ft_putchar_fd(base[i], fd);
	else
	{
		ft_putnbr_hexa_base(i / base_len, base, fd);
		ft_putnbr_hexa_base(i % base_len, base, fd);
	}
}
