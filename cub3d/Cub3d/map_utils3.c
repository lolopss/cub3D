/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:21:26 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/29 16:39:49 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line_name(char **tab, t_data *data, int *error)
{
	if (tab[0][0] == 'N' && tab[0][1] == 'O' && !tab[0][2])
		*error = get_north_image(data, tab[1]);
	else if (tab[0][0] == 'S' && tab[0][1] == 'O' && !tab[0][2])
		*error = get_south_image(data, tab[1]);
	else if (tab[0][0] == 'E' && tab[0][1] == 'A' && !tab[0][2])
		*error = get_west_image(data, tab[1]);
	else if (tab[0][0] == 'W' && tab[0][1] == 'E' && !tab[0][2])
		*error = get_east_image(data, tab[1]);
	else if (tab[0][0] == 'D' && !tab[0][1])
		*error = get_door_image(data, tab[1]);
	else if (tab[0][0] == 'A' && tab[0][1] == '1' && !tab[0][2])
		*error = get_anim1_image(data, tab[1]);
	else if (tab[0][0] == 'A' && tab[0][1] == '2' && !tab[0][2])
		*error = get_anim2_image(data, tab[1]);
	else if (tab[0][0] == 'C' && !tab[0][1])
		*error = get_color_ceiling(data, tab[1]);
	else if (tab[0][0] == 'F' && !tab[0][1])
		*error = get_color_floor(data, tab[1]);
	else if (tab[0][0] != '\n')
		*error = -1;
}

int	parse_textures(t_data *data, int fd)
{
	char	t_name[2];
	char	str[1024];
	int		bytes;

	bytes = 1;
	ft_bzero(str, 1024);
	init_verif(data);
	while (1)
	{
		if ((bytes = read(fd, &t_name, 1)) <= 0)
			break;
		t_name[bytes] = '\0';
		if (verify_line(t_name, str, data) != 0)
			return (-1);
		if (data->verif[0] == 1 && data->verif[1] == 1 && data->verif[2] == 1
			&& data->verif[3] == 1 && data->verif[4] == 1
			&& data->verif[5] == 1 && data->verif[6] == 1
			&& data->verif[7] == 1 && data->verif[8] == 1)
			break;
		}
	return (0);
}

char	**malloc_new_map(int *error, t_data *data)
{
	int		i;
	char	**new_map;

	i = 0;
	*error = -1;
	new_map = malloc(sizeof(char *) * (data->parse->max_height + 1));
	if (!new_map)
		return (NULL);
	while (i < data->parse->max_height)
	{
		new_map[i] = malloc(sizeof(char) * (data->parse->big_line + 1));
		if (!new_map[i++])
			return (new_map);
	}
	*error = 0;
	return (new_map);
}

int	duplicate_map(t_data *data, t_player *player)
{
	// char	new_map[data->parse->max_height][data->parse->big_line + 1];
	char	**new_map;
	int		i;
	int		j;
	int		error;

	new_map = malloc_new_map(&error, data);
	if (error == -1)
	{
		free_array(new_map);
		return (-1);
	}
	i = -1;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			new_map[i][j] = data->map[i][j];
		new_map[i][j] = '\0';
	}
	new_map[i][0] = '\0';
	new_map[data->parse->max_height] = NULL;
	error = verif_map_closed(new_map, player->x, player->y, data);
	free_array(new_map);
	return (error);
}

int	replace_player(t_data *data, t_player *player, t_parse *parse)
{
	put_player_pos(player, data);
	data->map[(int)player->x][(int)player->y] = '0';
	data->parse = parse;
	return (duplicate_map(data, player));
}
