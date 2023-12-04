/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:14:19 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/30 18:40:28 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_open2(t_data *data, t_player *player, t_parse *parse)
{
	if (replace_player(data, player, parse) != 0)
		return (print_error("Error\nMap isn't closed\n"));
	return (0);
}

void	malloc_parse(t_data *data, t_parse *parse, int *bytes)
{
	if (!parse)
		free_all(data);
	parse->init = 1;
	*bytes = 1;
}

int	map_open(char *map_name, t_data *data, t_player *player)
{
	t_parse	*parse;
	int		bytes;
	char	map[100000 + 1];

	parse = malloc(sizeof(t_parse));
	malloc_parse(data, parse, &bytes);
	parse->fd = open(map_name, O_RDONLY);
	if (parse->fd == -1)
		return (print_error("Error\nError whilst opening the map\n"));
	if (parse_textures(data, parse->fd) != 0)
		return (print_error("Error\nError within textures in map file\n"));
	bytes = read(parse->fd, map, 100000);
	if (bytes == -1)
		return (print_error("Error\nError whilst opening the map\n"));
	if (bytes >= 100000)
		return (print_error("Error\nMap is too big\n"));
	map[bytes] = '\0';
	if (verif_map_char(map) != 0)
		return (-4);
	find_big_line(map, parse);
	if (fullfill_map(map, parse, data) != 0)
		return (-5);
	if (map_open2(data, player, parse) != 0)
		return (-1);
	return (0);
}

//***Launches all maps verifications subfunctions***//
int	map_valid(char *map, t_data *data, t_player *player)
{
	if (is_map_cub(map) != 0)
	{
		print_error("Error\nMap is not .cub format\n");
		return (-1);
	}
	if (map_open(map, data, player) != 0)
		return (-1);
	return (0);
}

int	check_args(int ac, char **av, t_data *data, t_player *player)
{
	data->init = 0;
	data->textures.EA.init = 0;
	data->textures.SO.init = 0;
	data->textures.NO.init = 0;
	data->textures.WE.init = 0;
	data->textures.anim1.init = 0;
	data->textures.anim2.init = 0;
	data->textures.door.init = 0;
	data->textures.ceiling_color = -1;
	data->textures.floor_color = -1;
	if (ac != 2)
	{
		print_error("Error\nNumber of arguments\n");
		return (-1);
	}
	if (map_valid(av[1], data, player) == -1)
		return (-1);
	return (0);
}
