/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <ldaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:58:10 by ldaniel           #+#    #+#             */
/*   Updated: 2023/11/11 16:21:55 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strcpy_line(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strnlen(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	return (i);
}

char	*ft_strdup_line(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc(sizeof(*s2) * ft_strnlen((char *)s1, '\n') + 1);
	if (!s2)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	nullify_map(t_data *data, t_parse *parse)
{
	int	i;

	i = 0;
	while (i < parse->max_height)
	{
		data->map[i] = NULL;
		i++;
	}
}

int	fullfill_map(char *map, t_parse *parse, t_data *data)
{
	int	j;

	parse->index = 0;
	j = 0;
	data->map = malloc(sizeof (char *) * (parse->max_height + 1));
	nullify_map(data, parse);
	if (data->map == NULL)
	{
		print_error("Error\nMalloc failed\n");
		return (-1);
	}
	while (map[parse->index])
	{
		while (map[parse->index] && map[parse->index] != '\n')
			parse->index++;
		if (map[parse->index] == '\n')
			parse->index++;
		else
			break ;
		data->map[j] = ft_strdup_line(map + parse->index);
		if (!data->map[j])
			return (print_error("Error\nMalloc returned an error\n"));
		j++;
	}
	return (0);
}
