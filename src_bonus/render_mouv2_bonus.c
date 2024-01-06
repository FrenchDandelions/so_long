/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:57:11 by thole             #+#    #+#             */
/*   Updated: 2023/12/10 18:57:13 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	collect_notexit(int i, int j, t_mlx *mlx)
{
	mlx->collect++;
	if (mlx->flagleft == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_charac_left, j * 32, i * 32);
	else if (mlx->flagright == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_charac_right, j * 32, i * 32);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_floor,
		mlx->posj, mlx->posi);
	mlx->map[i][j] = START;
	mlx->map[mlx->posi / 32][mlx->posj / 32] = FLOOR;
	mlx->posi = i * 32;
	mlx->posj = j * 32;
	return (true);
}

bool	iscollect(t_mlx *mlx, int i, int j)
{
	if (mlx->map[i][j] == 'C' && mlx->map[mlx->posi / 32][mlx->posj
		/ 32] != 'E')
	{
		return (collect_notexit(i, j, mlx));
	}
	if (mlx->map[i][j] == 'C' && mlx->map[mlx->posi / 32][mlx->posj
		/ 32] == 'E')
	{
		mlx->collect++;
		if (mlx->flagright == 1)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
				mlx->img.img_charac_right, j * 32, i * 32);
		else if (mlx->flagleft == 1)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
				mlx->img.img_charac_left, j * 32, i * 32);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_exit,
			mlx->posj, mlx->posi);
		mlx->map[i][j] = START;
		mlx->map[mlx->posi / 32][mlx->posj / 32] = EXIT;
		mlx->posi = i * 32;
		mlx->posj = j * 32;
		return (true);
	}
	return (false);
}

bool	isfloor_notexit(int i, int j, t_mlx *mlx)
{
	if (mlx->flagleft == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_charac_left, j * 32, i * 32);
	else if (mlx->flagright == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_charac_right, j * 32, i * 32);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_floor,
		mlx->posj, mlx->posi);
	mlx->map[i][j] = START;
	mlx->map[mlx->posi / 32][mlx->posj / 32] = FLOOR;
	mlx->posi = i * 32;
	mlx->posj = j * 32;
	return (true);
}

bool	isfloor_andexit(int i, int j, t_mlx *mlx)
{
	if (mlx->flagleft == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_charac_left, j * 32, i * 32);
	else if (mlx->flagright == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_charac_right, j * 32, i * 32);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_exit,
		mlx->posj, mlx->posi);
	mlx->map[i][j] = START;
	mlx->map[mlx->posi / 32][mlx->posj / 32] = EXIT;
	mlx->posi = i * 32;
	mlx->posj = j * 32;
	return (true);
}

bool	isfloor(t_mlx *mlx, int i, int j)
{
	if ((mlx->map[i][j] == '0' || mlx->map[i][j] == 'P') && mlx->map[mlx->posi
		/ 32][mlx->posj / 32] != 'E' && mlx->map[mlx->posi / 32][mlx->posj
		/ 32] != 'F' && mlx->map[mlx->posi / 32][mlx->posj / 32] != 'R')
	{
		return (isfloor_notexit(i, j, mlx));
	}
	else if ((mlx->map[i][j] == '0' || mlx->map[i][j] == 'P')
		&& mlx->map[mlx->posi / 32][mlx->posj / 32] == 'E')
	{
		return (isfloor_andexit(i, j, mlx));
	}
	return (false);
}
