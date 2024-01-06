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

#include "so_long_bonus.h"

int	close2(t_mlx *mlx)
{
	end(mlx, mlx->posi / 32, mlx->posj / 32);
	return (0);
}

void	limiter(t_mlx *mlx)
{
	if (mlx->width > 1920 && mlx->height + 20 > 1010)
	{
		ft_perror_array2("Error\nYour map width and height are too big :(\n",
			mlx->map);
	}
	else if (mlx->width > 1920)
		ft_perror_array2("Error\nYour map width is too big :(\n", mlx->map);
	else if (mlx->height + 20 > 1010)
		ft_perror_array2("Error\nYour map height is too big :(\n", mlx->map);
	return ;
}

int	render_rect(t_mlx *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->mlx_win == NULL)
		return (1);
	i = rect.i;
	while (i < rect.i + rect.height)
	{
		j = 0;
		while (j < rect.j)
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	ft_show_on_screen(t_mlx *mlx)
{
	char	mvmnts[50];
	char	collect[50];

	render_rect(mlx, (t_rect){mlx->height, mlx->width, mlx->width, mlx->height
		+ 20, 0x000000});
	ft_sprintf(mvmnts, "Mouves done : %d", mlx->mvmnt);
	ft_sprintf(collect, "Collected %d/%d", mlx->collect, mlx->all_c);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 0, mlx->height + 10, 0xFF0000,
		mvmnts);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 0, mlx->height + 20, 0xFFD700,
		collect);
	mlx_do_sync(mlx->mlx_ptr);
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
