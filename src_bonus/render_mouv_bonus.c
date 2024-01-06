/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mouv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:38:33 by thole             #+#    #+#             */
/*   Updated: 2023/12/17 18:38:35 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mouv_up(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->posi / 32;
	j = mlx->posj / 32;
	mouv_enemy(mlx);
	if (mlx->map[i - 1][j] == '1')
		return (0);
	else if (mlx->map[i - 1][j] == 'E' && mlx->collect == mlx->all_c)
		end(mlx, i - 1, j);
	else if (mlx->map[i - 1][j] == 'B' || mlx->map[i - 1][j] == 'U')
		end(mlx, i - 1, j);
	else if (check_exit2(mlx, i - 1, j) == true)
		return (1);
	else if (iscollect(mlx, i - 1, j) == true)
		return (1);
	else if (isfloor(mlx, i - 1, j) == true)
		return (1);
	return (0);
}

int	mouv_down(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->posi / 32;
	j = mlx->posj / 32;
	mouv_enemy(mlx);
	if (mlx->map[i + 1][j] == '1')
		return (0);
	if (mlx->map[i + 1][j] == 'E' && mlx->collect == mlx->all_c)
		end(mlx, i + 1, j);
	else if (mlx->map[i + 1][j] == 'B' || mlx->map[i + 1][j] == 'U')
		end(mlx, i + 1, j);
	else if (check_exit2(mlx, i + 1, j) == true)
		return (1);
	else if (iscollect(mlx, i + 1, j) == true)
		return (1);
	else if (isfloor(mlx, i + 1, j) == true)
		return (1);
	return (0);
}

void	change_position(t_mlx *mlx, int i, int j)
{
	if (mlx->flagleft == 1 && mlx->map[i][j] != 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_charac_left, j * 32, i * 32);
	else if (mlx->flagright == 1 && mlx->map[i][j] != 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_charac_right, j * 32, i * 32);
	else if (mlx->flagleft == 1 && mlx->map[mlx->posi / 32][mlx->posj
		/ 32] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_exit_left, j * 32, i * 32);
	else if (mlx->flagright == 1 && mlx->map[mlx->posi / 32][mlx->posj
		/ 32] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_exit_right, j * 32, i * 32);
}

int	mouv_left(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->posi / 32;
	j = mlx->posj / 32;
	mlx->flagleft = 1;
	mlx->flagright = 0;
	mouv_enemy(mlx);
	if (mlx->map[i][j - 1] == '1')
	{
		change_position(mlx, i, j);
		return (0);
	}
	else if (mlx->map[i][j - 1] == 'E' && mlx->collect == mlx->all_c)
		end(mlx, i, j - 1);
	else if (mlx->map[i][j - 1] == 'B' || mlx->map[i][j - 1] == 'U')
		end(mlx, i, j - 1);
	else if (check_exit2(mlx, i, j - 1) == true)
		return (1);
	else if (iscollect(mlx, i, j - 1) == true)
		return (1);
	else if (isfloor(mlx, i, j - 1) == true)
		return (1);
	return (0);
}

int	mouv_right(t_mlx *mlx)
{
	int	i;
	int	j;

	i = mlx->posi / 32;
	j = mlx->posj / 32;
	mlx->flagleft = 0;
	mlx->flagright = 1;
	mouv_enemy(mlx);
	if (mlx->map[i][j + 1] == '1')
	{
		change_position(mlx, i, j);
		return (0);
	}
	else if (mlx->map[i][j + 1] == 'E' && mlx->collect == mlx->all_c)
		end(mlx, i, j + 1);
	else if (mlx->map[i][j + 1] == 'B' || mlx->map[i][j + 1] == 'U')
		end(mlx, i, j + 1);
	else if (check_exit2(mlx, i, j + 1) == true)
		return (1);
	else if (iscollect(mlx, i, j + 1) == true)
		return (1);
	else if (isfloor(mlx, i, j + 1) == true)
		return (1);
	return (0);
}
