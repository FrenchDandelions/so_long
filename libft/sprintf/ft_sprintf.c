/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:51:16 by thole             #+#    #+#             */
/*   Updated: 2024/01/06 16:38:41 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

typedef struct s_sprintf
{
	size_t	length;
	size_t	pos;
	size_t	i;
	char	*string;
}			t_sprintf;

int	ft_getchar(int c, char **ch)
{
	char	*str;

	str = malloc(sizeof(char *) * 1);
	str[0] = c;
	*ch = str;
	return (1);
}

void	ft_get_str_switch(va_list args, char c, char **str, size_t *len)
{
	size_t	len2;

	len2 = 0;
	if (c == 'd' || c == 'i')
		len2 = ft_sprintf_itoa(va_arg(args, int), &(*str));
	else if (c == 'c')
		len2 = ft_getchar(va_arg(args, int), &(*str));
	else if (c == 's')
		len2 = ft_sprintf_strdup(va_arg(args, char *), &(*str));
	else if (c == 'u')
		len2 = ft_sprintf_uitoa(va_arg(args, unsigned int), &(*str));
	else if (c == 'x')
		len2 = ft_sprintf_hexa(va_arg(args, unsigned int), "0123456789abcdef",
				&(*str));
	else if (c == 'X')
		len2 = ft_sprintf_hexa(va_arg(args, unsigned int), "0123456789ABCDEF",
				&(*str));
	else if (c == 'p')
		len2 = ft_sprintf_pointer(va_arg(args, unsigned long long),
				"0123456789abcdef", &(*str));
	*len = len2;
}

void	initialize_struct_sprintf(t_sprintf *p)
{
	p->i = 0;
	p->length = 0;
	p->pos = 0;
	p->string = NULL;
}

int	ft_sprintf(char *buffer, const char *str, ...)
{
	va_list		args;
	t_sprintf	p;

	initialize_struct_sprintf(&p);
	va_start(args, str);
	while (str[p.i])
	{
		if (str[p.i] == '%')
		{
			ft_get_str_switch(args, str[p.i + 1], &p.string, &p.length);
			ft_memcpy(buffer + p.pos, p.string, p.length);
			p.pos += p.length;
			free(p.string);
			p.i += 2;
		}
		else
		{
			buffer[p.pos++] = str[p.i++];
		}
	}
	va_end(args);
	buffer[p.pos] = '\0';
	return (p.pos);
}
