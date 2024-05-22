/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:42:53 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/30 17:45:40 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_exec4(t_data *data, t_player *player)
{
	while (data->hit == 0)
	{
		if (data->exec.dist.x < data->exec.dist.y)
		{
			data->exec.dist.x += data->exec.delta.x;
			data->exec.map.x += data->exec.step.x;
			data->side = 0;
		}
		else
		{
			data->exec.dist.y += data->exec.delta.y;
			data->exec.map.y += data->exec.step.y;
			data->side = 1;
		}
		if (data->map[(int)data->exec.map.x][(int)data->exec.map.y] == '1')
			data->hit = 1;
		else if (data->map[(int)data->exec.map.x][(int)data->exec.map.y] == 'D')
			data->hit = 2;
		else if (data->map[(int)data->exec.map.x][(int)data->exec.map.y] == 'A')
			data->hit = 3;
	}
	cub3d_exec5(data, player);
}

void	cub3d_exec3(t_data *data, t_player *player)
{
	if (data->exec.ray_dir.x < 0)
	{
		data->exec.step.x = -1;
		data->exec.dist.x = (player->x - data->exec.map.x) * data->exec.delta.x;
	}
	else
	{
		data->exec.step.x = 1;
		data->exec.dist.x = (data->exec.map.x + 1.0 - player->x)
			* data->exec.delta.x;
	}
	if (data->exec.ray_dir.y < 0)
	{
		data->exec.step.y = -1;
		data->exec.dist.y = (player->y - data->exec.map.y) * data->exec.delta.y;
	}
	else
	{
		data->exec.step.y = 1;
		data->exec.dist.y = (data->exec.map.y + 1.0 - player->y)
			* data->exec.delta.y;
	}
	cub3d_exec4(data, player);
}

void	cub3d_exec2(t_data *data, t_player *player)
{
	data->exec.camera.x = 2.0f * data->x / data->w - 1.0f;
	data->exec.map.x = (int)player->x;
	data->exec.map.y = (int)player->y;
	data->exec.ray_dir.x = player->dir.x + player->plane.x
		* data->exec.camera.x;
	data->exec.ray_dir.y = player->dir.y + player->plane.y
		* data->exec.camera.x;
	if (data->exec.ray_dir.x == 0)
		data->exec.delta.x = 1e30;
	else
		data->exec.delta.x = abs_val(1.0f / data->exec.ray_dir.x);
	if (data->exec.ray_dir.y == 0)
		data->exec.delta.y = 1e30;
	else
		data->exec.delta.y = abs_val(1.0f / data->exec.ray_dir.y);
	data->hit = 0;
	cub3d_exec3(data, player);
}

int	cub3d_exec(t_data *data)
{
	static int	count_anim = 0;

	data->w = (double)data->x_win;
	data->player->ms = 0.1;
	data->x = 0;
	data->hit = 0;
	data->perpwalldist = 0;
	while (data->x < data->w)
		cub3d_exec2(data, data->player);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (count_anim <= 150)
		data->anim = 1;
	else if (count_anim > 150 && count_anim <= 300)
		data->anim = 0;
	else
		count_anim = 0;
	count_anim++;
	return (0);
}
