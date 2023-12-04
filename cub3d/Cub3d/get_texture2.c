/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:19:14 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/27 11:20:51 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
