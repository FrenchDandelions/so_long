/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:09:06 by thole             #+#    #+#             */
/*   Updated: 2023/11/15 14:09:08 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_unsigned_len(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (i == n)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i <= 9)
		ft_putchar_fd(i + '0', 1);
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

void	ft_unsigned_putnbr(unsigned int n, int fd)
{
	unsigned long int	i;

	i = n;
	if (i <= 9)
		ft_putchar_fd(i + '0', fd);
	else
	{
		ft_unsigned_putnbr(i / 10, fd);
		ft_unsigned_putnbr(i % 10, fd);
	}
}
