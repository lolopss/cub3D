/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:00:50 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 16:07:54 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
#include <SDL2/SDL.h>

typedef struct image
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
	int		width;
	int		height;
	int		init;
}	t_idata;

typedef struct s_parsing
{
	char	map[5000 + 1];
	int	fd;
	int	j;
	int	index;
	int	line;
	int	big_line;
	int	max_height;
}	t_parse;

typedef struct s_2D
{
	double x;
	double y;
}		t_2d;

typedef struct s_textures
{
	t_idata NO;
	t_idata SO;
	t_idata WE;
	t_idata EA;
	t_idata door;
	int floor_color;
	int ceiling_color;
} 	t_textures;

typedef struct s_player
{
	char spawn_dir;
	double	x;
	double	y;
	double	ms;
	t_2d	dir;
	t_2d	plane;
}	t_player;

typedef struct s_exec
{
	t_2d	pos;
	t_2d	camera;
	t_2d	ray_dir;
	t_2d 	dist;
	t_2d 	delta;
	t_2d	step;
	t_2d	map;
	int		color;
}	t_exec;

typedef struct s_data
{
	t_textures textures;
	t_idata	*ttp;
	t_exec	exec;
	t_parse *parse;
	t_player *player;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	**map;
	int		init;
	int		index_tmp;
	int		coord_texture;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		y_win;
	int		x_win;
	int		x;
	int		i;
	int		wall_start;
	int		wall_end;
	int		hit;
	int		line_h;
	int		side;
	int		verif[7];
	double	dir_x;
	double	dir_y;
	double	orientation;
	double	pos_x;
	double	pos_y;
	double	perpwalldist;
	double	w;
	double	step;
	double tex_pos;
	double tex_y;
}	t_data;

void	cub3d_exec5(t_data *data, t_player *player);
void	put_vertical(t_data *data, int wall_start, int wall_end, t_idata *texture);
void	replace_player(t_data *data, t_player *player, t_parse *parse);
void	rotate_left(t_data *data, double spd);
void	rotate_right(t_data *data, double spd);
void	free_array(char **tab);
void	free_map(t_data *data);
void	set_player_dir(t_data *data);
void	free_all(t_data *data);
void	put_player_pos(t_player *player, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	find_big_line(char *map, t_parse *parse);
void	ft_bzero(void *s, size_t n);
void	init_verif(t_data *data);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *s1, char *s2);
char	**ft_split(char *s, char c);
int		print_error(char *str);
int		get_door_image(t_data *data, char *path);
int		init_mlx(t_data *data, t_player *player);
int		get_color_floor(t_data *data, char *str);
int		get_color_ceiling(t_data *data, char *str);
int		get_north_image(t_data *data, char *path);
int		get_south_image(t_data *data, char *path);
int		get_west_image(t_data *data, char *path);
int		get_east_image(t_data *data, char *path);
int		fullfill_map(char *map, t_parse *parse, t_data *data);
int		ft_atoi(const char *str);
int		check_args(int ac, char **av, t_data *data, t_player *player);
int		valid_character(char c);
int		key_hook(int keycode, t_data *data);
int		parse_textures(t_data *data, int fd);
int		map_open(char *map_name, t_data *data, t_player *player);
int		is_map_cub(char *map);
int		cub3d_exec(t_data *data);
int		ft_key(int key, t_data *data);
int		ft_strlen(char *s);
int		ft_mouse_handle(int x, int y, t_data *data);
int		get_pixel_color(t_idata *image, int x, int y);
double	abs_val(double nb);

#endif
