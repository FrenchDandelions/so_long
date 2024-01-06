/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:51:16 by thole             #+#    #+#             */
/*   Updated: 2023/11/15 12:51:19 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lengthswitch(va_list args, const char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = length + 1;
	else if (c == 's')
		length = length + ft_printf_strlen(va_arg(args, char *));
	else if (c == 'p')
		length = length + ft_ptr_len(va_arg(args, unsigned long long),
				"0123456789abcdef");
	else if (c == 'i')
		length = length + ft_nbrlen(va_arg(args, int));
	else if (c == 'd')
		length = length + ft_nbrlen(va_arg(args, int));
	else if (c == 'u')
		length = length + ft_unsigned_len(va_arg(args, unsigned int));
	else if (c == 'x')
		length = length + ft_hexa_len(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		length = length + ft_hexa_len(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (c == '%')
		length = length + 1;
	return (length);
}

void	ft_printswitch(va_list args, const char c)
{
	if (c == 'c')
		ft_printchar(va_arg(args, int));
	else if (c == 's')
		ft_putstrf_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_printptr(va_arg(args, unsigned long long), "0123456789abcdef", 1);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_unsigned_putnbr(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_putnbr_hexa_base(va_arg(args, unsigned int), "0123456789abcdef", 1);
	else if (c == 'X')
		ft_putnbr_hexa_base(va_arg(args, unsigned int), "0123456789ABCDEF", 1);
	else if (c == '%')
		ft_print_percent();
}

int	ft_convert(va_list args, const char *str)
{
	int		length;
	int		i;
	va_list	copy_args;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			va_copy(copy_args, args);
			ft_printswitch(args, str[i + 1]);
			length = length + ft_lengthswitch(copy_args, str[i + 1]);
			va_end(copy_args);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			length++;
			i++;
		}
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;

	length = 0;
	va_start(args, str);
	length = length + ft_convert(args, str);
	va_end(args);
	return (length);
}
