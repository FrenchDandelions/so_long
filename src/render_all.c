/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_stroke.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:19:33 by thole             #+#    #+#             */
/*   Updated: 2023/12/12 19:19:34 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map2(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == EXIT)
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img.img_exit, j * 32, i * 32);
			else if (mlx->map[i][j] == COLLECT)
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img.img_collect, j * 32, i * 32);
			else if (mlx->map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img.img_floor, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	render_map1(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == WALL)
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img.img_wall, j * 32, i * 32);
			else if (mlx->map[i][j] == START)
			{
				mlx->posi = i * 32;
				mlx->posj = j * 32;
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					mlx->img.img_charac_right, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}

int	render(t_mlx *data)
{
	if (data->mlx_win == NULL)
		return (1);
	render_map1(data);
	render_map2(data);
	return (0);
}

int	render_game(char *argv, t_mlx *mlx, t_tretris *valid)
{
	map(argv, valid, mlx);
	limiter(mlx);
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (MLX_ERROR);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height,
			"so_long");
	if (mlx->mlx_win == NULL)
	{
		free(mlx->mlx_win);
		return (MLX_ERROR);
	}
	initialize_img(mlx);
	render(mlx);
	mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, &handle_keypress, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, &close2, mlx);
	mlx_loop(mlx->mlx_ptr);
	end(mlx, mlx->posi / 32, mlx->posj / 32);
	return (0);
}

int	main(int argc, char **argv)
{
	t_tretris	valid;
	t_mlx		mlx;
	int			error;

	if (argc == 2)
	{
		error = render_game(argv[1], &mlx, &valid);
		return (error);
	}
	else if (argc > 2)
		ft_perror("Error\nToo many arguments!\n");
	else if (argc < 2)
		ft_perror("Error\nToo few arguments!\n");
	return (0);
}
