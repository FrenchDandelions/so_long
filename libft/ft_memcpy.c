/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:21 by thole             #+#    #+#             */
/*   Updated: 2023/11/13 11:32:23 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*copy_src;
	unsigned char	*copy_dest;

	i = 0;
	copy_src = (unsigned char *)src;
	copy_dest = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		copy_dest[i] = copy_src[i];
		i++;
	}
	return (dest);
}
