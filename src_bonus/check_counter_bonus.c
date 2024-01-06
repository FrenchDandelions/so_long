/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:23:44 by thole             #+#    #+#             */
/*   Updated: 2023/12/08 19:23:46 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_collect(t_count *counter)
{
	counter->collect += 1;
	return (0);
}

int	check_wall(t_count *counter)
{
	counter->wall += 1;
	return (0);
}

int	check_floor(t_count *counter)
{
	counter->floor += 1;
	return (0);
}

int	check_start(t_count *counter)
{
	counter->start += 1;
	if (counter->start > 1)
		return (1);
	return (0);
}

int	check_exit(t_count *counter)
{
	counter->exit += 1;
	if (counter->exit > 1)
		return (2);
	return (0);
}
