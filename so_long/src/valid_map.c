/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:25:06 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 18:20:12 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_map(t_data *data);
int	rectangular_shape(t_data *data);
int	closed_map(t_data *data);
int	check_item(t_data *data);
int	valid_character(t_data *data);

int	valid_map(t_data *data)
{
	if (!data->map.line)
	{
		ft_printf("Error\nmap does not exist\n");
		return (0);
	}
	else if (data->map.height > 1300)
	{
		free_ptr(data->map.line);
		ft_printf("Error\nmap too big to be displayed\n");
		return (0);
	}
	else if (!rectangular_shape(data) || !closed_map(data) \
		|| !check_item(data) || !valid_character(data) || !valid_path(data))
	{
		free_ptr(data->map.line);
		ft_printf("Error\ninvalid map\n");
		return (0);
	}
	return (1);
}

int	rectangular_shape(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data->map.line[i])
		len += ft_strlen(data->map.line[i++]);
	if (((ft_strlen(data->map.line[0]) - 1) * i) == (len - i))
		return (1);
	return (0);
}

int	closed_map(t_data *data)
{
	int	i;

	i = 0;
	if (!only_character(data->map.line[0], '1'))
		return (0);
	while (data->map.line[i])
	{
		if (data->map.line[i][0] != '1' || data->map.line[i] \
			[ft_strlen(data->map.line[i]) - 2] != '1')
			return (0);
		i++;
	}
	if (!only_character(data->map.line[i - 1], '1'))
		return (0);
	return (1);
}

int	check_item(t_data *data)
{
	int	i;
	int	j;
	int	p_c;
	int	e_c;

	i = 0;
	j = 0;
	p_c = 0;
	e_c = 0;
	while (data->map.line[i])
	{
		j = 0;
		while (data->map.line[i][j])
		{
			if (data->map.line[i][j] == 'E')
				e_c ++;
			else if (data->map.line[i][j] == 'P')
				p_c ++;
			j++;
		}
		i++;
	}
	if (data->map.prize_len <= 0 || e_c != 1 || p_c != 1)
		return (0);
	return (1);
}

int	valid_character(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.line[i])
	{
		j = 0;
		while (data->map.line[i][j])
		{
			if (data->map.line[i][j] != '1' && data->map.line[i][j] != '0' \
				&& data->map.line[i][j] != 'E' && data->map.line[i][j] != 'P' \
				&& data->map.line[i][j] != '\n' && data->map.line[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
