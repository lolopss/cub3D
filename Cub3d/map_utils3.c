/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:21:26 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 16:22:28 by ldaniel          ###   ########.fr       */
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
	else if (tab[0][0] == 'C' && !tab[0][1])
		*error = get_color_ceiling(data, tab[1]);
	else if (tab[0][0] == 'F' && !tab[0][1])
		*error = get_color_floor(data, tab[1]);
	else if (tab[0][0] != '\n')
		*error = -1;
}

int	put_texture_in_name(t_data *data, char *str)
{
	int		error;
	char	**tab;

	tab = ft_split(str, ' ');
	error = 0;
	if (tab[0] == NULL || (tab[0] && tab[0][0] != '\n' && tab[1] == NULL))
	{
		free_array(tab);
		return (-1);
	}
	if (tab && tab[0] && tab[1] && tab[2])
	{
		free_array(tab);
		return (-1);
	}
	check_line_name(tab, data, &error);
	if (error == -1)
	{
		free_array(tab);
		return (-1);
	}
	free_array(tab);
	return (0);
}

int	verify_line(char *t_name, char *str, t_data *data)
{
	int	error;

	if (t_name[0] == '\n')
	{
		if (ft_strlen(str) == 0)
			error = put_texture_in_name(data, "\n");
		else
		{
			str[ft_strlen(str)] = '\0';
			error = put_texture_in_name(data, str);
		}
		if (error != 0)
			return (-1);
		ft_bzero(str, 1024);
	}
	else
		str[ft_strlen(str)] = t_name[0];
	return (0);
}

int	parse_textures(t_data *data, int fd)
{
	char	t_name[2];
	char	str[1024];
	int		bytes;

	bytes = 1;
	ft_bzero(str, 1024);
	init_verif(data);
	while (bytes > 0)
	{
		bytes = read(fd, &t_name, 1);
		t_name[bytes] = '\0';
		if (verify_line(t_name, str, data) != 0)
			return (-1);
		if (data->verif[0] == 1 && data->verif[1] == 1 && data->verif[2] == 1
			&& data->verif[3] == 1 && data->verif[4] == 1
			&& data->verif[5] == 1 && data->verif[6] == 1)
			break ;
	}
	return (0);
}

void	replace_player(t_data *data, t_player *player, t_parse *parse)
{
	put_player_pos(player, data);
	data->map[(int)player->x][(int)player->y] = '0';
	data->parse = parse;
}
