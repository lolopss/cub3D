/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:24:26 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/30 18:47:47 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_cub(t_data *data, int i, int j, int color)
{
	int end_i = i + 10;
	int end_j = j + 10;
	while (i <= end_i)
	{
		j = end_j - 10;
		while (j <= end_j)
			my_mlx_pixel_put(data, i, j++, color);
		i++;
	}
}

void draw_minimap_pixel(t_data *data, int i, int j, char value)
{
	int color;

	if (value == '0')
		color = 0x0000FF; // Blue for open space
	else if (value == '1')
		color = 0x00FFFF; // Cyan for walls
	else if (value == 'D' || value == 'O')
		color = 0x964B00; // green for door
	else if (value == 'A')
		color = 0xFF0099; // green for door
	else if (value == 'J')
		color = 0xFF0000;
	else
		color = 0x000000;
	draw_cub(data, i, j, color);
}

void draw_minimap(t_data *data)
{
	int map_x, map_y;

	for (map_y = 0; map_y < 11; map_y++)
	{
		for (map_x = 0; map_x < 11; map_x++)
		{
			char block_type;
			if ((int)data->player->y + map_y - 5 < 0 || (int)data->player->x + map_x - 5 < 0 || (int)data->player->x + map_x - 5 > data->parse->max_height - 5 || (int)data->player->y + map_y - 5 >= data->parse->big_line)
				block_type = 'W';
			else
				block_type = data->map[(int)data->player->x + map_x - 5][(int)data->player->y + map_y - 5];
			if (map_x == 5 && map_y == 5)
				block_type = 'J';
			draw_minimap_pixel(data, (map_x * 10) + 30, (map_y * 10) + 30, block_type);
		}
	}
}
