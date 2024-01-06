/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:10:50 by thole             #+#    #+#             */
/*   Updated: 2023/11/30 14:10:53 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_read(int fd, char *stock)
{
	char	*strj;
	int		i;

	if (!stock)
	{
		stock = malloc(1);
		*stock = '\0';
	}
	strj = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!strj)
		return (free(stock), ft_free(strj));
	i = 1;
	while (i > 0)
	{
		i = read(fd, strj, BUFFER_SIZE);
		if (i == -1)
			return (free(stock), ft_free(strj));
		strj[i] = '\0';
		stock = ft_freestrjoin(stock, strj);
		if (ft_strchr(stock, '\n') && ft_strchr(stock, '\0'))
			break ;
	}
	free(strj);
	return (stock);
}

char	*ft_new_line(char *stock)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	new_line = ft_calloc(sizeof(char), (i + 1));
	if (!new_line)
		return (ft_free(new_line));
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		new_line[i] = stock[i];
		i++;
	}
	if (stock[i] && stock[i] == '\n')
		new_line[i++] = '\0';
	return (new_line);
}

char	*ft_delete_past_line(char *stock)
{
	char	*trimmed_line;
	int		i;
	int		j;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (!stock[i])
		return (ft_free(stock));
	trimmed_line = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!trimmed_line)
		return (ft_free(trimmed_line));
	i++;
	j = 0;
	while (stock[i])
	{
		trimmed_line[j++] = stock[i];
		i++;
	}
	free(stock);
	trimmed_line[j] = '\0';
	return (trimmed_line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	stock = ft_read(fd, stock);
	if (!stock)
		return (NULL);
	new_line = ft_new_line(stock);
	stock = ft_delete_past_line(stock);
	return (new_line);
}
