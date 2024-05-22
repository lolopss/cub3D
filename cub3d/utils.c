/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:18 by ldaniel           #+#    #+#             */
/*   Updated: 2023/12/04 15:48:56 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	init_verif(t_data *data)
{
	data->verif[0] = 0;
	data->verif[1] = 0;
	data->verif[2] = 0;
	data->verif[3] = 0;
	data->verif[4] = 0;
	data->verif[5] = 0;
	data->verif[6] = 0;
	data->verif[7] = 0;
	data->verif[8] = 0;
}

void	destroy_images(t_data *data)
{
	if (data->textures.door.init == 1)
		mlx_destroy_image(data->mlx, data->textures.door.img);
	if (data->textures.EA.init == 1)
		mlx_destroy_image(data->mlx, data->textures.EA.img);
	if (data->textures.WE.init == 1)
		mlx_destroy_image(data->mlx, data->textures.WE.img);
	if (data->textures.NO.init == 1)
		mlx_destroy_image(data->mlx, data->textures.NO.img);
	if (data->textures.SO.init == 1)
		mlx_destroy_image(data->mlx, data->textures.SO.img);
	if (data->textures.anim1.init == 1)
		mlx_destroy_image(data->mlx, data->textures.anim1.img);
	if (data->textures.anim2.init == 1)
		mlx_destroy_image(data->mlx, data->textures.anim2.img);
	mlx_destroy_display(data->mlx);
}

void	free_all(t_data *data)
{
	if (data->init)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->parse_init)
		free(data->parse);
	destroy_images(data);
	if (data->map)
		free_map(data);
	free(data->mlx);
	free(data);
	exit(0);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc(sizeof(*s2) * ft_strlen((char *)s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
