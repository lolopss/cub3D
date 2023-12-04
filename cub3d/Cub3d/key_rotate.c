/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:33:03 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 15:58:49 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_data *data, double spd)
{
	double	last_dir_x;
	double	last_plane_x;

	last_dir_x = data->player->dir.x;
	last_plane_x = data->player->plane.x;
	data->player->dir.x = data->player->dir.x * cos(spd)
		- data->player->dir.y * sin(spd);
	data->player->dir.y = last_dir_x * sin(spd)
		+ data->player->dir.y * cos(spd);
	data->player->plane.x = data->player->plane.x
		* cos(spd) - data->player->plane.y * sin(spd);
	data->player->plane.y = last_plane_x
		* sin(spd) + data->player->plane.y * cos(spd);
	cub3d_exec(data);
}

void	rotate_left(t_data *data, double spd)
{
	double	last_dir_x;
	double	last_plane_x;

	last_dir_x = data->player->dir.x;
	last_plane_x = data->player->plane.x;
	data->player->dir.x = data->player->dir.x * cos(spd)
		- data->player->dir.y * sin(spd);
	data->player->dir.y = last_dir_x * sin(spd)
		+ data->player->dir.y * cos(spd);
	data->player->plane.x = data->player->plane.x * cos(spd)
		- data->player->plane.y * sin(spd);
	data->player->plane.y = last_plane_x * sin(spd)
		+ data->player->plane.y * cos(spd);
	cub3d_exec(data);
}
