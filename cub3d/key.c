/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:52:59 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/29 17:34:16 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_key(t_data *data)
{
	if (data->map[(int)(data->player->x + data->player->dir.x * 0.1 * 2)]
		[(int)data->player->y] == '0'
		|| data->map[(int)(data->player->x + data->player->dir.x * 0.1 * 2)]
		[(int)data->player->y] == 'O')
		data->player->x += data->player->dir.x * data->player->ms;
	if (data->map[(int)data->player->x][(int)
		(data->player->y + data->player->dir.y * data->player->ms * 2)] == '0'
		|| data->map[(int)data->player->x][(int)
		(data->player->y + data->player->dir.y * data->player->ms * 2)] == 'O')
		data->player->y += data->player->dir.y * data->player->ms;
	cub3d_exec(data);
}

void	s_key(t_data *data)
{
	if (data->map[(int)(data->player->x - data->player->dir.x * 0.1 * 2)]
		[(int)data->player->y] == '0' ||
		data->map[(int)(data->player->x - data->player->dir.x * 0.1 * 2)]
		[(int)data->player->y] == 'O')
		data->player->x -= data->player->dir.x * data->player->ms;
	if (data->map[(int)data->player->x][(int)
		(data->player->y - data->player->dir.y * data->player->ms * 2)] == '0'
		|| data->map[(int)data->player->x][(int)
		(data->player->y - data->player->dir.y * data->player->ms * 2)] == 'O')
		data->player->y -= data->player->dir.y * data->player->ms;
	cub3d_exec(data);
}

void	d_key(t_data *data)
{
	if (data->map[(int)(data->player->x + data->player->plane.x * 0.1 * 2)]
		[(int)data->player->y] == '0' ||
		data->map[(int)(data->player->x + data->player->plane.x * 0.1 * 2)]
		[(int)data->player->y] == 'O')
		data->player->x += data->player->plane.x * data->player->ms * 0.5;
	if (data->map[(int)data->player->x][(int)(data->player->y
		+ data->player->plane.y * data->player->ms * 2)] == '0' ||
		data->map[(int)data->player->x][(int)(data->player->y
		+ data->player->plane.y * data->player->ms * 2)] == 'O')
		data->player->y += data->player->plane.y * data->player->ms * 0.5;
	cub3d_exec(data);
}

void	a_key(t_data *data)
{
	if (data->map[(int)(data->player->x - data->player->plane.x * 0.1 * 2)]
		[(int)data->player->y] == '0' ||
		data->map[(int)(data->player->x - data->player->plane.x * 0.1 * 2)]
		[(int)data->player->y] == 'O')
		data->player->x -= data->player->plane.x * data->player->ms;
	if (data->map[(int)data->player->x][(int)(data->player->y
		- data->player->plane.y * data->player->ms * 2)] == '0' ||
		data->map[(int)data->player->x][(int)(data->player->y
		- data->player->plane.y * data->player->ms * 2)] == 'O')
		data->player->y -= data->player->plane.y * data->player->ms;
	cub3d_exec(data);
}

int	ft_key(int key, t_data *data)
{
	if (key == 65307)
	{
		free_all(data);
		return (-1);
	}
	if (key == 119)
		w_key(data);
	if (key == 115)
		s_key(data);
	if (key == 97)
		a_key(data);
	if (key == 100)
		d_key(data);
	if (key == 65361)
		rotate_left(data, 0.03);
	if (key == 32)
		open_door(data);
	if (key == 65363)
		rotate_right(data, -0.03);
	return (0);
}
