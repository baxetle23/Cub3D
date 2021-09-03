/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keleonor/lcash <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:03:15 by keleonor          #+#    #+#             */
/*   Updated: 2021/08/14 15:03:17 by keleonor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include <math.h>

# define	SCREEN_WIDTH	1920
# define	SCREEN_HEIGHT	1860
# define	TEX_WIDTH		64
# define	TEX_HEIGHT		64

typedef struct s_cub
{
	int		**map;
	int		lines_num;
	int		line_length;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_color[3];
	int		c_color[3];
	char	*buff;
	int		x;
	int		y;
	char	view;
}	t_cub;

/*struct for window*/
typedef struct s_win
{
	void		*mlx;
	void		*win;
}				t_win;

/*struct for player and ray*/
typedef struct s_rc
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			texNum;
	double		wallX;
	int			texX;
	int			texY;
	double		step;
	double		texPos;
	int			color;
}				t_rc;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_color
{
	int			**north;
	char		*patn_n;
	int			**south;
	char		*patn_s;
	int			**west;
	char		*patn_w;
	int			**east;
	char		*patn_e;
}				t_color;

typedef struct s_all
{
	t_win		window;
	t_rc		player;
	t_img		img;
	t_color		color;
	t_rc		rc_var;
	t_cub		*cub;
	int			start;
}				t_all;

/*map_utils.c*/
void	errors(char *error, t_cub *cub);
int		ft_my_strlen(char *str);
void	ft_free(t_cub *cub);
void	fill_struct(t_cub *cub);
void	null_map(t_cub *cub);

/*map_validation.c*/
void	map_validation(t_cub *cub, char *argv);
void	check_fd_and_get_buff(char *argv, t_cub *cub);
int		get_file_length(char *str, t_cub *cub);
void	count_lines_in_map(t_cub *cub, int map_start);
void	find_longest_line(t_cub *cub, int map_start);

/*make_map_check_starting_position.c*/
void	map_maker(t_cub *cub, int map_start);
void	get_starting_position(t_cub *cub);
void	check_starting_position(t_cub *cub);

/*get_paths_colors_map_info.c*/
void	get_paths_colors_map_info(t_cub *cub);
int		get_paths_info(t_cub *cub, int i, char c);
int		malloc_and_save_path(t_cub *cub, int i, char c);
int		get_floor_ceiling_info(t_cub *cub, int i, char c);
int		save_color(t_cub *cub, int i, int *color);

/*get_and_check_path.c*/
void	get_so(t_cub *cub, int i, int start);
void	get_no(t_cub *cub, int i, int start);
void	get_ea(t_cub *cub, int i, int start);
void	get_we(t_cub *cub, int i, int start);
void	check_path(char *path, t_cub *cub);

/*map_validation_utils.c*/
int		skip_spaces(t_cub *cub, int i);
int		skip_lines(t_cub *cub, int i);
int		ft_my_atoi(t_cub *cub, int *color, int color_num, int i);
void	change_spaces(t_cub *cub);

/*check_walls_start.c*/
void	check_walls(t_cub *cub);
void	create_temp_array(t_cub *cub, int **array);
void	ft_free_temp_array(t_cub *cub, int **array);
void	copy_map_to_array(t_cub *cub, int **array);
void	check_zero_neighbors(t_cub *cub, int **array);

/*check_walls_end.c*/
void	fill_map_around_pers(t_cub *cub, int **array, int x, int y);
int		check_x_y(t_cub *cub, int x, int y);
void	check_whats_left_on_map(t_cub *cub, int **array);
void	fill_whats_left(t_cub *cub, int **array, int x, int y);

/*--------*/

void	main_alex(t_cub *cub);

void	initzilization(t_all *general);
void	init_raycast_variable(t_all *general);
void	get_image_texture(t_all *general);
void	render_map(t_all *general);

void	step_1(t_all *general, int x);
void	step_2(t_all *general);
void	step_3(t_all *general);
void	step_4(t_all *general);
void	step_5(t_all *general);

void	print_to_image(t_all *general, int x);

int		key_hook(int key, t_all *general);
int		close_win(t_all *general);

void	go_up(t_all *g, double moveSpeed);
void	go_down(t_all *g, double moveSpeed);
void	go_left(t_all *g, double moveSpeed);
void	go_right(t_all *g, double moveSpeed);
void	turn_left(t_all *g, double rotSpeed);
void	turn_right(t_all *g, double rotSpeed);

#endif
