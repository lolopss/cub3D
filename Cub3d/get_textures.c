/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:06 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 16:22:07 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_north_image(t_data *data, char *path)
{
	t_idata	*no;

	if (data->textures.NO.init != 0)
		return (print_error("Error\nmore than one north texture in map\n"));
	no = &data->textures.NO;
	no->img = mlx_xpm_file_to_image(data->mlx, path, &no->width, &no->height);
	if (!no->img)
	{
		print_error("Error\nnorth texture doesn't exist\n");
		return (-1);
	}
	if (no->width != 64 || no->height != 64)
	{
		print_error("Error\nnorth texture size isn't good\n");
		return (-1);
	}
	no->addr = mlx_get_data_addr(no->img, &no->bits_per_pixel, &no->line_length,
			&no->endian);
	data->verif[0] = 1;
	data->textures.NO.init = 1;
	return (0);
}

int	get_south_image(t_data *data, char *path)
{
	t_idata	*so;

	if (data->textures.SO.init != 0)
		return (print_error("Error\nmore than one south texture in map\n"));
	so = &data->textures.SO;
	so->img = mlx_xpm_file_to_image(data->mlx, path, &so->width, &so->height);
	if (!so->img)
	{
		print_error("Error\nsouth texture doesn't exist\n");
		return (-1);
	}
	if (so->width != 64 || so->height != 64)
	{
		print_error("Error\nsouth texture size isn't good\n");
		return (-1);
	}
	so->addr = mlx_get_data_addr(so->img, &so->bits_per_pixel, &so->line_length,
			&so->endian);
	data->verif[1] = 1;
	data->textures.SO.init = 1;
	return (0);
}

int	get_east_image(t_data *data, char *path)
{
	t_idata	*ea;

	if (data->textures.EA.init != 0)
		return (print_error("Error\nmore than one east texture in map\n"));
	ea = &data->textures.EA;
	ea->img = mlx_xpm_file_to_image(data->mlx, path, &ea->width, &ea->height);
	if (!ea->img)
	{
		print_error("Error\neast texture doesn't exist\n");
		return (-1);
	}
	if (ea->width != 64 || ea->height != 64)
	{
		print_error("Error\neast texture size isn't good\n");
		return (-1);
	}
	ea->addr = mlx_get_data_addr(ea->img, &ea->bits_per_pixel, &ea->line_length,
			&ea->endian);
	data->verif[2] = 1;
	data->textures.EA.init = 1;
	return (0);
}

int	get_west_image(t_data *data, char *path)
{
	t_idata	*we;

	if (data->textures.WE.init != 0)
		return (print_error("Error\nmore than one west texture in map\n"));
	we = &data->textures.WE;
	we->img = mlx_xpm_file_to_image(data->mlx, path, &we->width, &we->height);
	if (!we->img)
	{
		print_error("Error\nwest texture doesn't exist\n");
		return (-1);
	}
	if (we->width != 64 || we->height != 64)
	{
		print_error("Error\nwest texture size isn't good\n");
		return (-1);
	}
	we->addr = mlx_get_data_addr(we->img, &we->bits_per_pixel, &we->line_length,
			&we->endian);
	data->verif[3] = 1;
	data->textures.WE.init = 1;
	return (0);
}

int	get_door_image(t_data *data, char *path)
{
	t_idata	*door;

	if (data->textures.door.init != 0)
		return (print_error("Error\nmore than one door texture in map\n"));
	door = &data->textures.door;
	door->img = mlx_xpm_file_to_image(data->mlx, path, &door->width, &door->height);
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
	door->addr = mlx_get_data_addr(door->img, &door->bits_per_pixel, &door->line_length,
			&door->endian);
	data->verif[6] = 1;
	data->textures.door.init = 1;
	return (0);
}

int	get_pixel_color(t_idata *image, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	return (*(unsigned int *)pixel_addr);
}
