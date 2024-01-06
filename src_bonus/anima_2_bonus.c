/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anima_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:19 by thole             #+#    #+#             */
/*   Updated: 2024/01/04 16:21:20 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_map3(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'U')
			{
				mlx->posi_pump = i * 32;
				mlx->posj_pump = j * 32;
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img.img_pump, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}

void	animate_left(t_mlx *mlx)
{
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire0.xpm", "./sprite/enemy/pumpkin0_l.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire1.xpm", "./sprite/enemy/pumpkin1_l.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire2.xpm", "./sprite/enemy/pumpkin2_l.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire3.xpm", "./sprite/enemy/pumpkin3_l.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire2.xpm", "./sprite/enemy/pumpkin4_l.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire3.xpm", "./sprite/enemy/pumpkin5_l.xpm", mlx);
}

void	animate_right(t_mlx *mlx)
{
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire0.xpm", "./sprite/enemy/pumpkin0.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire1.xpm", "./sprite/enemy/pumpkin1.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire2.xpm", "./sprite/enemy/pumpkin2.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire3.xpm", "./sprite/enemy/pumpkin3.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire2.xpm", "./sprite/enemy/pumpkin4.xpm", mlx);
	ft_wait(22000000);
	mlx_destroyer(mlx);
	animate("./sprite/enemy/fire3.xpm", "./sprite/enemy/pumpkin5.xpm", mlx);
}

void	mouv_enemy(t_mlx *mlx)
{
	int	rd;

	if (mlx->pump == 1)
	{
		rd = rand() % 4;
		if (rd == 0)
			mouv_up_enemy(mlx);
		if (rd == 1)
			mouv_down_enemy(mlx);
		if (rd == 2)
			mouv_left_enemy(mlx);
		if (rd == 3)
			mouv_right_enemy(mlx);
	}
	return ;
}

bool	isfloor_pump(int i, int j, t_mlx *mlx)
{
	if (mlx->flag_pump_l == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_pump_l,
			j * 32, i * 32);
	else if (mlx->flag_pump_r == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_pump, j
			* 32, i * 32);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_floor,
		mlx->posj_pump, mlx->posi_pump);
	mlx->map[mlx->posi_pump / 32][mlx->posj_pump / 32] = '0';
	mlx->map[i][j] = 'U';
	mlx->posi_pump = i * 32;
	mlx->posj_pump = j * 32;
	return (true);
}
