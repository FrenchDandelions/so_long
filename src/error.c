/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:54:56 by thole             #+#    #+#             */
/*   Updated: 2023/12/10 12:54:59 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	send_error(int error, char **map, char **map2)
{
	if (error == 1)
		ft_perror_array("Error\nToo many starting points !\n", map, map2);
	if (error == 2)
		ft_perror_array("Error\nToo many exit points !\n", map, map2);
	if (error == 3)
		ft_perror_array("Error\nThere is no collectible on the map :(\n", map,
			map2);
	if (error == 4)
		ft_perror_array("Error\nYour map is missing walls... how?\n", map,
			map2);
	if (error == 5)
		ft_perror_array("Error\nThere is no exit in the map :(\n", map, map2);
	if (error == 6)
		ft_perror_array("Error\nThere is no starting point in the map :(\n",
			map, map2);
	if (error == 7)
		ft_perror_array("Error\nMap ain't a rectangle lmao\n", map, map2);
	if (error == 8)
		ft_perror_array("Error\nMap isn't surrounded by walls :(\n", map, map2);
	if (error == 9)
		ft_perror_array("Error\nNot a valid map !\n", map, map2);
	if (error == 10)
		ft_perror_array("Error\nMap too big bro :(\n)", map, map2);
}

void	ft_perror_array(char *str, char **map, char **map2)
{
	errno = EINVAL;
	perror(str);
	ft_free_array(map);
	ft_free_array(map2);
	exit(EXIT_SUCCESS);
}

void	ft_perror_array2(char *str, char **map)
{
	errno = EINVAL;
	perror(str);
	ft_free_array(map);
	exit(EXIT_SUCCESS);
}

int	ft_perror(char *str)
{
	errno = EINVAL;
	perror(str);
	return (2);
}

void	check(int error)
{
	if (error == 2)
		exit(EXIT_SUCCESS);
	return ;
}
