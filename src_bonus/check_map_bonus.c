/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:21:42 by thole             #+#    #+#             */
/*   Updated: 2023/12/08 20:28:01 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_map_lines(char *argv, int error)
{
	char	*str;
	int		fd;
	int		j;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error = ft_perror("Error\nCouldn't open file\n");
	str = get_next_line(fd);
	if (str == NULL && error != 2)
		error = ft_perror("Error\nEmpty file, not a map\n");
	while (str != NULL)
	{
		j++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	check(error);
	return (j);
}

char	**get_map(int j, char *argv, char **array, int error)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error = ft_perror("Error\nCouldn't open file\n");
	array = (char **)malloc(sizeof(char *) * (j + 1));
	str = get_next_line(fd);
	if (str == NULL && error != 2)
		error = ft_perror("Error\nEmpty file, not a map\n");
	while (str != NULL)
	{
		array[i++] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	array[i] = NULL;
	close(fd);
	check(error);
	return (array);
}

void	check_map(char **array, t_count *counter, t_tretris *valid)
{
	int	error;
	int	i;
	int	j;

	i = 0;
	if (counter->pump > 1)
		send_error(10, array, valid->map);
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j])
		{
			error = checker_map(array, i, j, counter);
			if (error != 0)
			{
				send_error(error, array, valid->map);
			}
			j++;
		}
		i++;
	}
	check_count(*counter, array, valid);
}

void	check_characters(char **map, t_tretris *valid)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != WALL && map[i][j] != COLLECT && map[i][j] != START
				&& map[i][j] != EXIT && map[i][j] != FLOOR && map[i][j] != 'B'
				&& map[i][j] != 'U')
				ft_perror_array(BAD, map, valid->map);
			j++;
		}
		i++;
	}
}

void	map(char *argv, t_tretris *valid, t_mlx *mlx)
{
	int		j;
	char	**array;
	t_count	counter;
	int		error;

	error = 0;
	array = NULL;
	checkname_map(argv, ".ber");
	j = count_map_lines(argv, error);
	array = get_map(j, argv, array, error);
	valid->map = get_map(j, argv, valid->map, error);
	check_rectangular_map(array, valid);
	check_closed_map(array, valid);
	check_characters(array, valid);
	initialize_counter(&counter);
	check_map(array, &counter, valid);
	initialize_valid(valid, j, &counter, array);
	get_start_position(valid, array);
	if ((validpath(valid->map, valid->i, valid->j, valid)) == false
		&& (valid->flag == 0 || (valid->flag2 == 2
				&& valid->collectibles_collected < valid->total_collectibles)))
		ft_perror_array("Error\nThere's no valid path\n", array, valid->map);
	initialize_mlx_struct(array, valid, mlx, j);
	return ;
}
