/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:28:33 by thole             #+#    #+#             */
/*   Updated: 2023/12/17 19:28:34 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <stdbool.h>
# include <unistd.h>
# define WALL '1'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'
# define FLOOR '0'
# define MLX_ERROR 1
# define BAD "Error\nI found characters in the map that shouldn't be there!\n"
# define NL "\n"

typedef struct s_struct
{
	int		collect;
	int		wall;
	int		exit;
	int		floor;
	int		start;
	int		enemy;
}			t_count;

typedef struct s_tree
{
	char	**map;
	int		i;
	int		j;
	int		x;
	int		y;
	int		height;
	int		width;
	int		flag;
	int		flag2;
	int		total_collectibles;
	int		collectibles_collected;
	int		enemy;
}			t_tretris;

typedef struct s_image
{
	char	*char_img_right;
	char	*char_img_left;
	char	*floor_img;
	char	*wall_img;
	char	*collect_img;
	char	*exit_img;
	char	*exit_charac_left_img;
	char	*exit_charac_right_img;
	void	*img_charac_right;
	void	*img_wall;
	void	*img_collect;
	void	*img_floor;
	void	*img_exit;
	int		width;
	int		height;
	void	*img_charac_left;
	void	*img_exit_right;
	void	*img_exit_left;
	void	*img_boss;
	char	*boss_file;
}			t_image;

typedef struct s_mlx
{
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	int		all_c;
	int		posi;
	int		posj;
	int		width;
	int		height;
	int		flagright;
	int		flagleft;
	int		j;
	t_image	img;
	int		collect;
	int		mvmnt;
	int		enemy;
}			t_mlx;

typedef struct s_rect
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		color;
}			t_rect;

typedef struct s_sprintf
{
	size_t	length;
	size_t	pos;
	size_t	i;
	char	*string;
}			t_sprintf;

int			ft_strlen_without_nl(char *str);
int			count_map_lines(char *argv, int error);
char		**get_map(int j, char *argv, char **array, int error);
void		ft_free_array(char **array);
void		check_count(t_count counter, char **array, t_tretris *valid);
int			ft_perror(char *str);
void		check(int error);
void		check_rectangular_map(char **array, t_tretris *valid);
void		check_closed_map(char **array, t_tretris *valid);
void		send_error(int error, char **map, char **map2);
int			check_collect(t_count *counter);
int			check_wall(t_count *counter);
int			check_floor(t_count *counter);
int			check_start(t_count *counter);
int			check_exit(t_count *counter);
void		get_start_position(t_tretris *valid, char **map);
int			checker_map(char **array, int i, int j, t_count *counter);
void		check_map(char **array, t_count *counter, t_tretris *valid);
void		ft_perror_array(char *str, char **map, char **map2);
void		map(char *argv, t_tretris *valid, t_mlx *mlx_img);
char		**fix_array(char **map);
bool		validpath(char **map, int i, int j, t_tretris *valid);
void		ft_perror_array2(char *str, char **map);
void		initialize_valid(t_tretris *valid, int j, t_count *counter,
				char **array);
void		initialize_counter(t_count *counter);
void		checkname_map(char *argv, char *str);
void		check_characters(char **map, t_tretris *valid);
void		ft_perror_map_name(char *str);
void		initialize_mlx_struct(char **map, t_tretris *valid,
				t_mlx *mlx_image, int j);
void		initialize_img(t_mlx *mlx);
void		initialize_img2(t_mlx *mlx);
int			mouv_up(t_mlx *mlx);
int			mouv_down(t_mlx *mlx);
int			mouv_left(t_mlx *mlx);
int			mouv_right(t_mlx *mlx);
bool		isfloor(t_mlx *mlx, int i, int j);
bool		isfloor_andexit(int i, int j, t_mlx *mlx);
bool		isfloor_notexit(int i, int j, t_mlx *mlx);
bool		iscollect(t_mlx *mlx, int i, int j);
bool		collect_notexit(int i, int j, t_mlx *mlx);
bool		check_exit2(t_mlx *mlx, int i, int j);
void		end(t_mlx *mlx, int i, int j);
void		initialize_img(t_mlx *mlx);
void		initialize_img2(t_mlx *mlx);
int			handle_keypress(int keysym, t_mlx *mlx);
int			close2(t_mlx *mlx);
void		print_onscreen(t_mlx *mlx);
void		limiter(t_mlx *mlx);

int			render_rect(t_mlx *data, t_rect rect);

size_t		ft_len(int nb);
void		ft_show_on_screen(t_mlx *mlx);
void		ft_show_on_screen(t_mlx *mlx);
int			animation(t_mlx *mlx);
void		ft_wait(int wait);
void		animate(char *str, t_mlx *mlx);
void		printf_message(int num, t_mlx *mlx);
void		print_exit_message(void);
#endif
