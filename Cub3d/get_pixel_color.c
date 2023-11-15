/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:56:20 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/15 17:00:09 by ldaniel          ###   ########.fr       */
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
	if (data->map[(int)data->player->x + 1][(int)data->player->y] == 'D')
		data->map[(int)data->player->x + 1][(int)data->player->y] = 'O';
	else if (data->map[(int)data->player->x + 1][(int)data->player->y] == 'O')
		data->map[(int)data->player->x + 1][(int)data->player->y] = 'D';
	if (data->map[(int)data->player->x - 1][(int)data->player->y] == 'D')
		data->map[(int)data->player->x - 1][(int)data->player->y] = 'O';
	else if (data->map[(int)data->player->x - 1][(int)data->player->y] == 'O')
		data->map[(int)data->player->x - 1][(int)data->player->y] = 'D';
	if (data->map[(int)data->player->x][(int)data->player->y + 1] == 'D')
		data->map[(int)data->player->x][(int)data->player->y + 1] = 'O';
	else if (data->map[(int)data->player->x + 1]
		[(int)data->player->y + 1] == 'O')
		data->map[(int)data->player->x + 1][(int)data->player->y + 1] = 'D';
	if (data->map[(int)data->player->x][(int)data->player->y - 1] == 'D')
		data->map[(int)data->player->x][(int)data->player->y - 1] = 'O';
	else if (data->map[(int)data->player->x][(int)data->player->y - 1] == 'O')
		data->map[(int)data->player->x][(int)data->player->y - 1] = 'D';
	cub3d_exec(data);
}
