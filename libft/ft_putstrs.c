/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:44:18 by thole             #+#    #+#             */
/*   Updated: 2023/11/15 13:44:20 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printchar(int c)
{
	write(1, &c, 1);
}

void	ft_print_percent(void)
{
	write(1, "%", 1);
}

int	ft_printf_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (6);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstrnull(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putstrf_fd(char *s, int fd)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
	{
		str = "(null)";
		ft_putstrnull(str);
	}
	else
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
