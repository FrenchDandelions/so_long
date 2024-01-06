/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:53:05 by thole             #+#    #+#             */
/*   Updated: 2023/12/17 18:53:06 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		end(mlx, mlx->posi / 32, mlx->posj / 32);
	else if (keysym == XK_w || keysym == XK_Up)
		mlx->mvmnt += mouv_up(mlx);
	else if (keysym == XK_s || keysym == XK_Down)
		mlx->mvmnt += mouv_down(mlx);
	else if (keysym == XK_a || keysym == XK_Left)
		mlx->mvmnt += mouv_left(mlx);
	else if (keysym == XK_d || keysym == XK_Right)
		mlx->mvmnt += mouv_right(mlx);
	ft_show_on_screen(mlx);
	return (0);
}

void	initialize_img2(t_mlx *mlx)
{
	mlx->img.img_charac_left = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->img.char_img_left, &(mlx->img.width), &(mlx->img.height));
	mlx->img.img_exit_left = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->img.exit_charac_left_img, &(mlx->img.width),
			&(mlx->img.height));
	mlx->img.img_exit_right = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->img.exit_charac_right_img, &(mlx->img.width),
			&(mlx->img.height));
	mlx->flagleft = 0;
	mlx->flagright = 1;
	mlx->mvmnt = 0;
	mlx->img.boss_file = "./sprite/enemy/fire0.xpm";
	mlx->img.img_boss = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->img.boss_file,
			&(mlx->img.width), &(mlx->img.height));
	mlx->img.pump_img = "./sprite/enemy/pumpkin0.xpm";
	mlx->img.img_pump = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->img.pump_img,
			&(mlx->img.width), &(mlx->img.height));
	mlx->flag_pump_l = 0;
	mlx->flag_pump_r = 1;
	mlx->img.pump_img_l = "./sprite/enemy/pumpkin0_l.xpm";
	mlx->img.img_pump_l = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->img.pump_img_l, &(mlx->img.width), &(mlx->img.height));
}

void	initialize_img(t_mlx *mlx)
{
	mlx->img.width = 32;
	mlx->img.height = 32;
	mlx->img.char_img_left = "./sprite/character/charac_to_left.xpm";
	mlx->img.char_img_right = "./sprite/character/charac_to_right.xpm";
	mlx->img.collect_img = "./sprite/collectibles/collect.xpm";
	mlx->img.exit_img = "./sprite/exit/exit.xpm";
	mlx->img.exit_charac_left_img = "./sprite/exit/exittoleft.xpm";
	mlx->img.exit_charac_right_img = "./sprite/exit/exittoright.xpm";
	mlx->img.floor_img = "./sprite/floors/grass32.xpm";
	mlx->img.wall_img = "./sprite/wall/wall.xpm";
	mlx->img.img_floor = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->img.floor_img,
			&(mlx->img.width), &(mlx->img.height));
	mlx->img.img_charac_right = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->img.char_img_right, &(mlx->img.width), &(mlx->img.height));
	mlx->img.img_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->img.exit_img,
			&(mlx->img.width), &(mlx->img.height));
	mlx->img.img_collect = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->img.collect_img, &(mlx->img.width), &(mlx->img.height));
	mlx->img.img_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->img.wall_img,
			&(mlx->img.width), &(mlx->img.height));
	initialize_img2(mlx);
}

void	end(t_mlx *mlx, int i, int j)
{
	int	k;

	k = 0;
	if (mlx->all_c == mlx->collect && mlx->map[i][j] == 'E')
		printf_message(1, mlx);
	else
		printf_message(2, mlx);
	while (mlx->map[k] != NULL)
		free(mlx->map[k++]);
	free(mlx->map);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_wall);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_collect);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_charac_left);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_charac_right);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_exit);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_exit_left);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_exit_right);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_floor);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_boss);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_pump);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_pump_l);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}

bool	check_exit2(t_mlx *mlx, int i, int j)
{
	if (mlx->map[i][j] == 'E' && mlx->flagleft == 1
		&& mlx->collect < mlx->all_c)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_exit_left, j * 32, i * 32);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_floor,
			mlx->posj, mlx->posi);
		print_exit_message(mlx, i, j);
		mlx->posi = i * 32;
		mlx->posj = j * 32;
		return (true);
	}
	else if (mlx->map[i][j] == 'E' && mlx->flagright == 1
		&& mlx->collect < mlx->all_c)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->img.img_exit_right, j * 32, i * 32);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_floor,
			mlx->posj, mlx->posi);
		print_exit_message(mlx, i, j);
		mlx->posi = i * 32;
		mlx->posj = j * 32;
		return (true);
	}
	return (false);
}
