/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:25:06 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 14:40:43 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_map(t_data *data);
int	rectangular_shape(t_data *data);
int	closed_map(t_data *data);
int	check_item(t_data *data);

int	valid_map(t_data *data)
{
	if (!rectangular_shape(data))
		return (0);
	else if (!closed_map(data))
		return (0);
	else if (!check_item(data))
		return (0);
	else if (!valid_path(data))
		return (0);
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
