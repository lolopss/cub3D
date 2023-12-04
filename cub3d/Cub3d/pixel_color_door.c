/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color_door.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:56:20 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/27 15:09:36 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color(t_idata *image, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	return (*(unsigned int *)pixel_addr);
}

void	open_door(t_data *data)
{
	float	dir_x;
	float	dir_y;

	dir_x = data->player->dir.x;
	dir_y = data->player->dir.y;
	if (data->map[(int)(data->player->x + dir_x)][(int)(data->player->y + dir_y)] == 'D')
		data->map[(int)(data->player->x + dir_x)][(int)(data->player->y + dir_y)] = 'O';
	else if (data->map[(int)(data->player->x + dir_x)][(int)(data->player->y + dir_y)] == 'O'
		&& ((int)(data->player->x + dir_x) != data->player->x
			&& (int)(data->player->y + dir_y) != data->player->y))
		data->map[(int)(data->player->x + dir_x)][(int)(data->player->y + dir_y)] = 'D';
	cub3d_exec(data);
}
