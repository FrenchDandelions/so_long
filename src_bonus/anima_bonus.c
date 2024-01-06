/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anima.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:59:22 by thole             #+#    #+#             */
/*   Updated: 2023/12/21 15:59:24 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_exit_message(t_mlx *mlx, int i, int j)
{
	mlx->map[i][j] = EXIT;
	mlx->map[mlx->posi / 32][mlx->posj / 32] = FLOOR;
	ft_printf("\n\n*************************************************\n|");
	ft_printf("    It's not over yet! Go collect 'em all :)   |\n");
	ft_printf("*************************************************\n\n");
}

void	animate(char *str, char *str2, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->img.img_boss = mlx_xpm_file_to_image(mlx->mlx_ptr, str,
			&(mlx->img.width), &(mlx->img.height));
	mlx->img.img_pump = mlx_xpm_file_to_image(mlx->mlx_ptr, str2,
			&(mlx->img.width), &(mlx->img.height));
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'B')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img.img_boss, j * 32, i * 32);
			else if (mlx->map[i][j] == 'U')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img.img_pump, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	ft_wait(int wait)
{
	int	i;

	i = 0;
	while (i < wait)
		i++;
	return ;
}

void	mlx_destroyer(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_boss);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_pump);
}

int	animation(t_mlx *mlx)
{
	if (mlx->flag_pump_r == 1)
		animate_right(mlx);
	else if (mlx->flag_pump_l == 1)
		animate_left(mlx);
	return (0);
}
