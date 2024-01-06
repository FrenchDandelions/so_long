/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:30:34 by thole             #+#    #+#             */
/*   Updated: 2023/11/13 11:30:37 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		uc;

	src = s;
	uc = c;
	while (n-- > 0)
	{
		if (*src == uc)
		{
			return ((void *)src);
		}
		src++;
	}
	return (NULL);
}
