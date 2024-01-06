/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:55 by thole             #+#    #+#             */
/*   Updated: 2023/12/08 19:19:57 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkname_map(char *argv, char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = ft_strlen(argv);
	if (i < 4 || j < 4)
		ft_perror_map_name("Error\nNot a .ber map sweetheart\n");
	while (argv[j - 1] == str[i - 1] && i > 0)
	{
		i--;
		j--;
	}
	if (i != 0)
		ft_perror_map_name("Error\nNot a .ber map sweetheart\n");
	return ;
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

void	check_count(t_count counter, char **array, t_tretris *valid)
{
	if (counter.start == 0)
		send_error(6, valid->map, array);
	if (counter.exit == 0)
		send_error(5, valid->map, array);
	if (counter.collect == 0)
		send_error(3, valid->map, array);
	if (counter.wall == 0)
		send_error(4, valid->map, array);
}

void	initialize_counter(t_count *counter)
{
	counter->collect = 0;
	counter->exit = 0;
	counter->floor = 0;
	counter->start = 0;
	counter->wall = 0;
}

void	initialize_valid(t_tretris *valid, int j, t_count *counter,
		char **array)
{
	valid->height = j;
	valid->width = ft_strlen(array[0]) - 1;
	valid->total_collectibles = counter->collect;
	valid->flag = 0;
	valid->flag2 = 0;
	valid->collectibles_collected = 0;
}
