/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:14:19 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 15:52:14 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
