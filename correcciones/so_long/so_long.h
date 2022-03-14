/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:19:41 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 23:29:23 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	"./minilibx/mlx.h"
# include	"getnextline/get_next_line.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define STOP_DIR 0
# define UP_DIR 1
# define DOWN_DIR 2
# define LEFT_DIR 3
# define RIGHT_DIR 4
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define ESC 53

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_hero
{
	t_img		*img;
	int			alive;
	int			pos_x;
	int			pos_y;
	int			collected;
	int			direction;
	int			sp_time;
	int			sp_num;
}				t_hero;

typedef struct s_enemy
{
	t_img		*img;
	int			pos_x;
	int			pos_y;
	int			dest_x;
	int			dest_y;
	int			direction;
}				t_enemy;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	char		**map;
	t_hero		*hero;
	t_enemy		*enemys;
	t_img		*img;
	int			num_enemys;
	int			num_moves;
	int			num_collectables;
	int			map_width;
	int			map_height;
	int			exit_x;
	int			exit_y;
}				t_mlx;

int		open_map(char *map_name);
int		map_lines_width(char *map_info);
char	*get_initial_map_info(char *map_name);
int		map_lines_height(char *map_info);
void	print_initial_map_line(char *line, int y, t_mlx *mlx);
void	print_initial_map(int map_height, int map_width, t_mlx *mlx);
char	**parse_initial_map(t_mlx *mlx);
char	*ft_itoa(int n);
void	place_text_moves_to_window(t_mlx *mlx, char *str);
void	place_text_to_window(t_mlx *mlx, char *str);
void	place_centered_text_to_window(t_mlx *mlx, char *str);
void	move_hero_sprites_right(t_mlx *mlx);
void	move_hero_sprites_left(t_mlx *mlx);
void	move_hero_sprites_up(t_mlx *mlx);
void	move_hero_sprites_down(t_mlx *mlx);
void	parse_0_tile(t_mlx *mlx, int x, int y);
void	parse_1_tile(t_mlx *mlx, int x, int y);
void	parse_p_tile(t_mlx *mlx, int x, int y);
void	parse_c_tile(t_mlx *mlx, int x, int y);
void	parse_n_tile(t_mlx *mlx, int x, int y);
void	parse_e_tile(t_mlx *mlx, int x, int y);
void	init_mlx_object(t_mlx *mlx);
t_hero	*init_hero(t_mlx *mlx);
t_enemy	*init_enemies(t_mlx *mlx);
int		check_enemy_collition(t_mlx *mlx, int enemy_nbr);
int		enemy_can_move_to(int x, int y, t_mlx *mlx);
void	switch_enemy_dir(t_mlx *mlx, int count);
void	move_enemys(t_mlx *mlx);
void	move_enemy_right(t_mlx *mlx, int count);
void	move_enemy_left(t_mlx *mlx, int count);
void	move_enemy_down(t_mlx *mlx, int count);
void	move_enemy_up(t_mlx *mlx, int count);
void	init_map_images(t_mlx *mlx);
void	init_items_images(t_mlx *mlx);
void	init_enemy_images(t_mlx *mlx);
void	move_hero(t_mlx *mlx);
void	move_hero_right(t_mlx *mlx);
void	move_hero_left(t_mlx *mlx);
void	move_hero_down(t_mlx *mlx);
void	move_hero_up(t_mlx *mlx);
void	show_exit_door(t_mlx *mlx);
void	show_you_win(t_mlx *mlx);
int		can_move_to(int x, int y, t_mlx *mlx);
int		input(int key, t_mlx *mlx);
void	count_another_move(t_mlx *mlx);
void	input_is_key_up(t_mlx *mlx);
void	input_is_key_down(t_mlx *mlx);
void	input_is_key_right(t_mlx *mlx);
void	input_is_key_left(t_mlx *mlx);
void	load_basic_hero_images(t_mlx *mlx);
void	load_basic_hero_images2(t_mlx *mlx);
void	load_sprites_images_right(t_mlx *mlx);
void	load_sprites_images_left(t_mlx *mlx);
void	load_sprites_images_up(t_mlx *mlx);
void	load_sprites_images_down(t_mlx *mlx);
int		exit_game(t_mlx *mlx);
void	check_map_file_exist(char *map_info, t_mlx *mlx);
void	check_map_valid_height_and_width(char *map_info, t_mlx *mlx);
void	check_map_is_rectangular(char *map_info, t_mlx *mlx);
void	check_map_valid_chars(char *map_info, t_mlx *mlx);
void	check_map_surronded_by_walls(char *map_info, t_mlx *mlx);
int		map_is_surrounded_be_walls(char *map_info, t_mlx *mlx);
void	free_memory_and_exit(t_mlx *mlx);
void	free_objects_memory(t_mlx *mlx);
void	free_general_images_memory(t_mlx *mlx);
void	free_map_memory(t_mlx *mlx);
void	ft_putnbr_fd(int n, int fd);
char	*create_map_y_malloc(t_mlx *mlx, int count);
void	create_map_x_malloc(t_mlx *mlx);
void	create_malloc_map_images(t_mlx *mlx);
t_hero	*create_hero_malloc(t_mlx *mlx);
t_img	*create_hero_images_malloc(t_mlx *mlx);
void	create_enemys_malloc(t_mlx *mlx);
void	check_map_needed_chars(char *map_info, t_mlx *mlx);
#endif
