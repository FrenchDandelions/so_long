/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:48:03 by thole             #+#    #+#             */
/*   Updated: 2023/12/10 14:48:05 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int		i;
	char	*dest_cpy;

	i = 0;
	dest_cpy = dest;
	while (src[i] != '\0')
	{
		dest_cpy[i] = src[i];
		i++;
	}
	dest_cpy[i] = '\0';
	return (dest);
}
