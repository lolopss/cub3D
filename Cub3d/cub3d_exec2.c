/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_exec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:39:41 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/15 15:05:34 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_exec6(t_data *data)
{
	data->tex_pos = (data->wall_start - (double)data->y_win / 2
			+ (double)data->line_h / 2) * data->step;
	put_vertical(data, data->wall_start, data->wall_end, data->ttp);
	data->x++;
}

void	choose_texture(t_data *data)
{
	if (data->hit == 2)
		data->ttp = &data->textures.door;
	else if (data->side == 0 && data->dir_x < 0)
		data->ttp = &data->textures.NO;
	else if (data->side == 0 && data->dir_x > 0)
		data->ttp = &data->textures.SO;
	else if (data->side == 1 && data->dir_y < 0)
		data->ttp = &data->textures.EA;
	else if (data->side == 1 && data->dir_y >= 0)
		data->ttp = &data->textures.WE;
}

void	cub3d_exec5(t_data *data, t_player *player)
{
	if (data->side == 0)
		data->perpwalldist = (data->exec.dist.x - data->exec.delta.x);
	else
		data->perpwalldist = (data->exec.dist.y - data->exec.delta.y);
	data->line_h = (int)((double)data->y_win / data->perpwalldist);
	data->wall_start = (double)(-data->line_h) / 2 + (double)data->y_win / 2;
	if (data->wall_start < 0)
		data->wall_start = 0;
	data->wall_end = data->line_h / 2 + (double)data->y_win / 2;
	if (data->wall_end >= (double)data->y_win)
		data->wall_end = (double)data->y_win - 1;
	data->pos_x = player->x + (data->exec.ray_dir.x * data->perpwalldist);
	data->pos_y = player->y + (data->exec.ray_dir.y * data->perpwalldist);
	if (data->side == 0)
		data->coord_texture = ((data->pos_y - (int)data->pos_y) * 64);
	if (data->side == 1)
		data->coord_texture = ((data->pos_x - (int)data->pos_x) * 64);
	data->dir_x = data->pos_x - player->x;
	data->dir_y = data->pos_y - player->y;
	choose_texture(data);
	data->step = 1.0 * 64 / data->line_h;
	cub3d_exec6(data);
}
