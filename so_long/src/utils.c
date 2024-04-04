/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:10:22 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 17:44:06 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	map_len(char *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd <= 0 || read(fd, 0, 0) < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close (fd);
	return (i);
}

void	free_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
