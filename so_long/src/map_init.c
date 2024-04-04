/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:27:08 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 17:55:31 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_init(t_data *data, char *map);
void	value_init(t_data *data);
void	store_map(t_data *data, char *map);
void	set_values(t_data *data);

void	map_init(t_data *data, char *map)
{
	value_init(data);
	store_map(data, map);
	if (!data->map.line)
		return ;
	set_values(data);
}

void	value_init(t_data *data)
{
	data->map.line = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.p_x = 0;
	data->map.p_y = 0;
	data->map.prize_len = 0;
	data->map.move = 0;
	data->map.prize_count = 0;
}

void	store_map(t_data *data, char *map)
{
	char	*line;
	int		i;
	int		len;
	int		fd;

	i = 0;
	len = map_len(map);
	if (!len)
		return ;
	data->map.line = malloc(sizeof(char *) * (i + 1));
	if (!data->map.line)
		return ;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->map.line[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	data->map.line[i] = NULL;
	close (fd);
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
