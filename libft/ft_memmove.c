/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:37 by thole             #+#    #+#             */
/*   Updated: 2023/11/13 11:32:45 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*srccpy;
	unsigned char		*destcpy;
	unsigned int		i;

	srccpy = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	i = 0;
	if ((size_t)(destcpy - srccpy) < n && destcpy - srccpy > 0)
	{
		i = n - 1;
		while (i < n)
		{
			destcpy[i] = srccpy[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
