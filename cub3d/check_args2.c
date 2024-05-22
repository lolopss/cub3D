/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:04:19 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/29 15:00:25 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_cub(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '.')
		i++;
	if (map[i + 1] == 'c' && map[i + 2] == 'u' && map[i + 3] == 'b'
		&& map[i + 4] == '\0' && i >= 1)
		return (0);
	else
		return (-1);
}

int	malloc_map(t_data *data, t_parse *parse)
{
	int	i;

	i = -1;
	data->map = malloc(sizeof (char *) * (parse->max_height + 1));
	if (data->map == NULL)
	{
		print_error("Error\nMalloc failed\n");
		return (-1);
	}
	while (++i < parse->max_height)
	{
		data->map[i] = malloc(sizeof(char) * parse->big_line + 1);
		if (!data->map[i])
		{
			print_error("Error\nMalloc failed\n");
			return (-1);
		}
	}
	data->map[i] = NULL;
	return (0);
}

int	verif_map_char(char *map)
{
	int	i;
	int	spawn;

	spawn = 0;
	i = 0;
	while (map[i])
	{
		if (valid_character(map[i]) == 1)
			spawn++;
		else if (valid_character(map[i]) == -1)
		{
			print_error("Error\nWrong characters\n");
			return (-1);
		}
		i++;
	}
	if (spawn == 0 || spawn > 1)
	{
		print_error("Error\nthere's either too much or no player on map.\n");
		return (-2);
	}
	return (0);
}

int	verif_map_closed(char **map, int x, int y, t_data *data)
{
	int	error;

	error = 0;
	if ((map[x][y] != '0' && map[x][y] != '1' && map[x][y] != '9'
		&& map[x][y] != 'D' && map[x][y] == 'A') || y == 0 || x == 0
		|| x == data->parse->max_height
		|| y == data->parse->big_line)
		return (-1);
	map[x][y] = '9';
	if (map[x][y - 1] != '1' && map[x][y - 1] != '9' && error == 0
		&& map[x][y - 1] != 'A')
		error = verif_map_closed(map, x, y - 1, data);
	if (map[x][y + 1] != '1' && map[x][y + 1] != '9' && error == 0
		&& map[x][y + 1] != 'A')
		error = verif_map_closed(map, x, y + 1, data);
	if (map[x - 1][y] != '1' && map[x - 1][y] != '9' && error == 0
		&& map[x - 1][y] != 'A')
		error = verif_map_closed(map, x - 1, y, data);
	if (map[x + 1][y] != '1' && map[x + 1][y] != '9' && error == 0
		&& map[x + 1][y] != 'A')
		error = verif_map_closed(map, x + 1, y, data);
	return (error);
}
