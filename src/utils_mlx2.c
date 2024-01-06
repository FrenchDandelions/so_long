/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:02:13 by thole             #+#    #+#             */
/*   Updated: 2023/12/21 17:16:00 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close2(t_mlx *mlx)
{
	end(mlx, mlx->posi / 32, mlx->posj / 32);
	return (0);
}

void	limiter(t_mlx *mlx)
{
	if (mlx->width > 1920 && mlx->height > 1030)
	{
		ft_perror_array2("Error\nYour map width and height are too big :(\n",
			mlx->map);
	}
	else if (mlx->width > 1920)
		ft_perror_array2("Error\nYour map width is too big :(\n", mlx->map);
	else if (mlx->height > 1030)
		ft_perror_array2("Error\nYour map height is too big :(\n", mlx->map);
	return ;
}

void	printf_message(int num, t_mlx *mlx)
{
	if (num == 1)
	{
		mlx->mvmnt++;
		ft_printf("\n\n*************************************************\n|\t");
		ft_printf("Congrats! You won in %d moves! :D\t|\n", mlx->mvmnt);
		ft_printf("*************************************************\n\n");
	}
	else
	{
		ft_printf("\n\n*************************************************\n|");
		ft_printf("\t     You lost :( Try again !\t\t|\n");
		ft_printf("*************************************************\n\n");
	}
}

void	print_exit_message(void)
{
	ft_printf("\n\n*************************************************\n|");
	ft_printf("    It's not over yet! Go collect 'em all :)   |\n");
	ft_printf("*************************************************\n\n");
}
