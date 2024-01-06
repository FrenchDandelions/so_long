/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy_mouv_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:41:19 by thole             #+#    #+#             */
/*   Updated: 2024/01/04 16:41:20 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mouv_up_enemy(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->posi_pump / 32;
	j = mlx->posj_pump / 32;
	if (mlx->map[i - 1][j] == '1' || mlx->map[i - 1][j] == 'B' || mlx->map[i
		- 1][j] == 'E' || mlx->map[i - 1][j] == 'C')
		return ;
	else if (mlx->map[i - 1][j] == mlx->map[mlx->posi / 32][mlx->posj / 32])
		end(mlx, i - 1, j);
	else if (isfloor_pump(i - 1, j, mlx) == true)
		return ;
	return ;
}

void	mouv_down_enemy(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->posi_pump / 32;
	j = mlx->posj_pump / 32;
	if (mlx->map[i + 1][j] == '1' || mlx->map[i + 1][j] == 'B' || mlx->map[i
		+ 1][j] == 'E' || mlx->map[i + 1][j] == 'C')
		return ;
	else if (mlx->map[i + 1][j] == mlx->map[mlx->posi / 32][mlx->posj / 32])
		end(mlx, i + 1, j);
	else if (isfloor_pump(i + 1, j, mlx) == true)
		return ;
	return ;
}

void	change_position_enemy(t_mlx *mlx, int i, int j)
{
	if (mlx->flag_pump_l == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_pump_l,
			j * 32, i * 32);
	else if (mlx->flag_pump_r == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_pump, j
			* 32, i * 32);
}

void	mouv_left_enemy(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->posi_pump / 32;
	j = mlx->posj_pump / 32;
	mlx->flag_pump_l = 1;
	mlx->flag_pump_r = 0;
	if (mlx->map[i][j - 1] == '1' || mlx->map[i][j - 1] == 'B' || mlx->map[i][j
		- 1] == 'E' || mlx->map[i][j - 1] == 'C')
	{
		change_position_enemy(mlx, i, j);
		return ;
	}
	else if (mlx->map[i][j - 1] == mlx->map[mlx->posi / 32][mlx->posj / 32])
		end(mlx, i, j - 1);
	else if (isfloor_pump(i, j - 1, mlx) == true)
		return ;
	return ;
}

void	mouv_right_enemy(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->posi_pump / 32;
	j = mlx->posj_pump / 32;
	mlx->flag_pump_l = 0;
	mlx->flag_pump_r = 1;
	if (mlx->map[i][j + 1] == '1' || mlx->map[i][j + 1] == 'B' || mlx->map[i][j
		+ 1] == 'E' || mlx->map[i][j + 1] == 'C')
	{
		change_position_enemy(mlx, i, j);
		return ;
	}
	else if (mlx->map[i][j + 1] == mlx->map[mlx->posi / 32][mlx->posj / 32])
		end(mlx, i, j + 1);
	else if (isfloor_pump(i, j + 1, mlx) == true)
		return ;
	return ;
}
