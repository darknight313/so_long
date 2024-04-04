/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:10:22 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 14:37:21 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	store_map(t_data *data, char *map)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close (fd);
	data->map.line = malloc(sizeof(char *) * (i + 1));
	fd = open(map, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		data->map.line[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	data->map.line[i] = NULL;
}

void	set_values(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map.line[i])
	{
		j = 0;
		while (data->map.line[i][j])
		{
			if (data->map.line[i][j] == 'P')
			{
				data->map.p_x = j;
				data->map.p_y = i;
			}
			else if (data->map.line[i][j] == 'C')
				data->map.prize_len ++;
			j++;
		}
		i++;
	}
	data->map.height = i * SIZE_IMG;
	data->map.width = (ft_strlen(data->map.line[0]) - 1) * SIZE_IMG;
}

void	value_init(t_data *data)
{
	data->map.width = 0;
	data->map.height = 0;
	data->map.p_x = 0;
	data->map.p_y = 0;
	data->map.prize_len = 0;
	data->map.move = 0;
	data->map.prize_count = 0;
}

int	only_character(char *str, int c)
{
	while (*(str + 1))
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

int	remove_prize(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->image.player->instances[0].y != \
		data->image.prize->instances[i].y)
		i++;
	while (data->image.player->instances[0].x != \
		data->image.prize->instances[i].x)
		i++;
	j = data->image.prize->instances[i].enabled;
	data->image.prize->instances[i].enabled = 0;
	return (j);
}
