/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:36:37 by thole             #+#    #+#             */
/*   Updated: 2023/11/14 13:17:13 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	i;
	size_t	j;

	k = size;
	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && k-- != 0)
		i++;
	while (src[j])
		j++;
	if (size <= i)
		return (j + size);
	else
		j = j + i;
	k = 0;
	while (src[k] && (i + 1) < size)
		dst[i++] = src[k++];
	dst[i] = '\0';
	return (j);
}
