/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:15:29 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 15:02:39 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_num(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		str++;
	}
	return (0);
}

int	get_color_ceiling(t_data *data, char *str)
{
	int		r;
	int		g;
	int		b;
	char	**color;

	if (data->textures.ceiling_color != -1)
		return (print_error("Error\nMore than one ceiling color in the map"));
	color = ft_split(str, ',');
	if (!color || color[0] == NULL || color[1] == NULL || color[2] == NULL
		|| check_num(color[0]) == 1 || check_num(color[1]) == 1
		|| check_num(color[2]) == 1)
	{
		free_array(color);
		return (print_error("Error\nError : Non numerical characters within color\n"));
	}
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	free_array(color);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (print_error("Error\nColor value not within 0 - 255\n"));
	data->textures.ceiling_color = (r << 16 | g << 8 | b);
	data->verif[4] = 1;
	return (0);
}

int	get_color_floor(t_data *data, char *str)
{
	int		r;
	int		g;
	int		b;
	char	**color;

	if (data->textures.floor_color != -1)
		return (print_error("Error\nMore than one floor color in the map\n"));
	color = ft_split(str, ',');
	if (!color || color[0] == NULL || color[1] == NULL || color[2] == NULL
		|| check_num(color[0]) == 1 || check_num(color[1]) == 1
		|| check_num(color[2]) == 1)
	{
		print_error("Error\nError : Non numerical char within color\n");
		free_array(color);
		return (-1);
	}
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	free_array(color);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (print_error("Error\nColor value not within 0 - 255\n"));
	data->textures.floor_color = (r << 16 | g << 8 | b);
	data->verif[5] = 1;
	return (0);
}

void	free_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
