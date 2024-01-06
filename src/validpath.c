/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:20:07 by thole             #+#    #+#             */
/*   Updated: 2023/12/09 13:41:54 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_start_position(t_tretris *valid, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == START)
			{
				valid->i = i;
				valid->j = j;
			}
			else if (map[i][j] == EXIT)
			{
				valid->x = i;
				valid->y = j;
			}
			j++;
		}
		i++;
	}
	return ;
}

bool	again(char **map, int i, int j, t_tretris *valid)
{
	if (map[i][j] == EXIT
		&& valid->collectibles_collected == valid->total_collectibles)
		return (true);
	if (i + 1 < valid->height && map[i + 1][j] != WALL)
		validpath(map, i + 1, j, valid);
	if (i - 1 > 0 && map[i - 1][j] != WALL)
		validpath(map, i - 1, j, valid);
	if (j - 1 >= 0 && map[i][j - 1] != WALL)
		validpath(map, i, j - 1, valid);
	if (j + 1 < valid->width && map[i][j + 1] != WALL)
		validpath(map, i, j + 1, valid);
	return (false);
}

bool	validpath(char **map, int i, int j, t_tretris *valid)
{
	bool	bo;

	if (map[i][j] == COLLECT)
		valid->collectibles_collected++;
	if (map[i][j] == EXIT
		&& valid->collectibles_collected < valid->total_collectibles)
	{
		valid->flag2 = 2;
		valid->flag = 1;
		bo = again(map, i, j, valid);
	}
	if (map[i][j] == EXIT
		&& valid->collectibles_collected == valid->total_collectibles)
	{
		valid->flag = 1;
		return (true);
	}
	if (map[i][j] == 'V')
		return (false);
	if (map[i][j] != EXIT)
		map[i][j] = 'V';
	bo = again(map, i, j, valid);
	return (bo);
}
