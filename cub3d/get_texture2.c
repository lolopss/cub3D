/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:19:14 by ldaniel           #+#    #+#             */
/*   Updated: 2023/12/04 15:19:05 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_anim2_image(t_data *data, char *path)
{
	t_idata	*anim2;

	if (data->textures.anim2.init != 0)
		return (print_error("Error\nmore than one anim2 texture in map\n"));
	anim2 = &data->textures.anim2;
	anim2->img = mlx_xpm_file_to_image(data->mlx, path, &anim2->width,
			&anim2->height);
	if (!anim2->img)
	{
		print_error("Error\nanim2 texture doesn't exist\n");
		return (-1);
	}
	if (anim2->width != 64 || anim2->height != 64)
	{
		print_error("Error\nanim2 texture size isn't good\n");
		return (-1);
	}
	anim2->addr = mlx_get_data_addr(anim2->img, &anim2->bits_per_pixel,
			&anim2->line_length,
			&anim2->endian);
	data->verif[8] = 1;
	data->textures.anim2.init = 1;
	return (0);
}

int	get_door_image(t_data *data, char *path)
{
	t_idata	*door;

	if (data->textures.door.init != 0)
		return (print_error("Error\nmore than one door texture in map\n"));
	door = &data->textures.door;
	door->img = mlx_xpm_file_to_image(data->mlx, path, &door->width,
			&door->height);
	if (!door->img)
	{
		print_error("Error\ndoor texture doesn't exist\n");
		return (-1);
	}
	if (door->width != 64 || door->height != 64)
	{
		print_error("Error\nDoor texture size isn't good\n");
		return (-1);
	}
	door->addr = mlx_get_data_addr(door->img, &door->bits_per_pixel,
			&door->line_length,
			&door->endian);
	data->verif[6] = 1;
	data->textures.door.init = 1;
	return (0);
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
