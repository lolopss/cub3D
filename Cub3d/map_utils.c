/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:42:47 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 15:10:20 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_big_line(char *map, t_parse *parse)
{
	int	count_tmp;
	int	i;

	i = 0;
	count_tmp = 0;
	parse->max_height = 1;
	parse->big_line = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (parse->big_line < count_tmp)
				parse->big_line = count_tmp;
			count_tmp = 0;
			i++;
			parse->max_height++;
		}
		else
		{
			count_tmp++;
			i++;
		}
	}
}

int	valid_character(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'D' || c == '\n')
		return (0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (-1);
}

void	put_player_pos(t_player *player, t_data *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W')
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				player->spawn_dir = data->map[j][i];
				data->map[j][i] = '9';
				break ;
			}
			i++;
		}
		if (player->x != -1)
			break ;
		j++;
	}
}

void	set_east_west(t_data *data)
{
	if (data->player->spawn_dir == 'E')
	{
		data->player->dir.x = 0;
		data->player->dir.y = 1;
		data->player->plane.x = 0.66;
		data->player->plane.y = 0;
	}
	else if (data->player->spawn_dir == 'W')
	{
		data->player->dir.x = 0;
		data->player->dir.y = -1;
		data->player->plane.x = -0.66;
		data->player->plane.y = 0;
	}
}

void	set_player_dir(t_data *data)
{
	if (data->player->spawn_dir == 'N')
	{
		data->player->dir.x = -1;
		data->player->dir.y = 0;
		data->player->plane.x = 0;
		data->player->plane.y = 0.66;
	}
	else if (data->player->spawn_dir == 'S')
	{
		data->player->dir.x = 1;
		data->player->dir.y = 0;
		data->player->plane.x = 0;
		data->player->plane.y = -0.66;
	}
	set_east_west(data);
}
