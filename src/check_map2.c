/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:24:39 by thole             #+#    #+#             */
/*   Updated: 2023/12/08 19:24:40 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker_map(char **array, int i, int j, t_count *counter)
{
	if (array[i][j] == WALL)
		return (check_wall(counter));
	else if (array[i][j] == FLOOR)
		return (check_floor(counter));
	if (array[i][j] == COLLECT)
		return (check_collect(counter));
	if (array[i][j] == START)
		return (check_start(counter));
	if (array[i][j] == EXIT)
		return (check_exit(counter));
	return (0);
}

void	check_rectangular_map(char **array, t_tretris *valid)
{
	int		i;
	int		j;
	size_t	len;

	j = 0;
	i = 0;
	if (array[0][0] != WALL && array[0][0] != COLLECT && array[0][0] != START
		&& array[0][0] != EXIT && array[0][0] != FLOOR)
		send_error(9, array, valid->map);
	while (array[j] != NULL)
		j++;
	if (array[j - 1][0] != WALL && array[j - 1][0] != COLLECT && array[j
		- 1][0] != START && array[j - 1][0] != EXIT && array[j - 1][0] != FLOOR)
		send_error(9, array, valid->map);
	len = ft_strlen(array[i]);
	if (len > 70)
		send_error(10, array, valid->map);
	while (array[i])
	{
		if (ft_strlen(array[i]) != len)
			send_error(7, array, valid->map);
		i++;
		if (i > 70)
			send_error(10, array, valid->map);
	}
}

void	check_closed_map(char **array, t_tretris *valid)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = ft_strlen(array[i]) - 1;
	while (array[i])
	{
		j = 0;
		if (i == 0 || array[i + 1] == NULL)
		{
			while (array[i][j] != '\0')
			{
				if (array[i][j] != WALL)
					send_error(8, array, valid->map);
				j++;
			}
		}
		else if ((array[i][j] != WALL) || (array[i][k] != WALL))
			send_error(8, array, valid->map);
		i++;
	}
}

void	initialize_mlx_struct(char **map, t_tretris *valid, t_mlx *mlx, int j)
{
	ft_free_array(valid->map);
	mlx->map = map;
	mlx->all_c = valid->total_collectibles;
	mlx->collect = 0;
	mlx->height = j * 32;
	mlx->width = ft_strlen(map[0]) * 32;
	mlx->enemy = valid->enemy;
}

void	ft_perror_map_name(char *str)
{
	errno = EINVAL;
	perror(str);
	exit(EXIT_SUCCESS);
}
