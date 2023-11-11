/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:34:21 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/10 16:48:41 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse_handle(int x, int y, t_data *data)
{
	if (x == data->x_win / 2)
		return (0);
	else if (x > data->x_win / 2)
		rotate_right(data, ((double)x - (double)data->x_win) / 12000.0);
	else if (x < data->x_win / 2)
		rotate_left(data, ((double)data->x_win - (double)x) / 12000.0);
	x = data->x_win / 2;
	y = data->y_win / 2;
	mlx_mouse_move(data->mlx, data->win, x, y);
	return (0);
}

int	init_mlx(t_data *data, t_player *player)
{
	data->map = NULL;
	data->init = 0;
	player->x = -1;
	player->y = -1;
	data->x_win = 800;
	data->y_win = 700;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->win = mlx_new_window(data->mlx, data->x_win, data->y_win, "Cub3D");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		print_error("Error\nMlx window failed");
		return (-1);
	}
	return (0);
}
