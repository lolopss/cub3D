/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:59:31 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 15:03:10 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->x_win, data->y_win);
	if (!data->img)
	{
		free_all(data);
		return (-1);
	}
	data->init = 1;
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
	{
		mlx_destroy_image(data->mlx, data->img);
		free_all(data);
		return (-1);
	}
	return (0);
}

void	init_data(t_data *data)
{
	data->x = 0;
	data->i = 0;
	data->bits_per_pixel = 32;
	if (init_textures(data) == -1)
	{
		print_error("Error\nError within main image");
		free_all(data);
	}
	set_player_dir(data);
	data->orientation = 0;
}

void	put_vertical(t_data *data, int wall_start, int wall_end,
		t_idata *texture)
{
	int	height;

	height = 0;
	while (height < wall_start)
	{
		my_mlx_pixel_put(data, data->x, height, data->textures.ceiling_color);
		height++;
	}
	while (height <= wall_end)
	{
		data->tex_y = (int)data->tex_pos & (64 - 1);
		data->tex_pos += data->step;
		my_mlx_pixel_put(data, (double)data->x, height, get_pixel_color(texture,
				data->coord_texture, data->tex_y));
		height++;
	}
	while (height < data->y_win)
	{
		my_mlx_pixel_put(data, (double)data->x, height,
			data->textures.floor_color);
		height++;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_player	player;

	if (init_mlx(&data, &player) == -1)
		return (-1);
	if (check_args(ac, av, &data, &player) == -1)
	{
		free_all(&data);
		return (-1);
	}
	data.player = &player;
	init_data(&data);
	cub3d_exec(&data);
	mlx_hook(data.win, 6, (1L << 6), ft_mouse_handle, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_key, &data);
	mlx_hook(data.win, 17, 0, (void *)free_all, &data);
	mlx_loop(data.mlx);
	return (0);
}
