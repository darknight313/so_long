/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:15:33 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/03 18:03:21 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_map(t_data *data);
void	display_background(t_data *data);
void	display_item(t_data *data);

void	display_map(t_data *data)
{
	display_background(data);
	display_item(data);
}

void	display_background(t_data *data)
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
			mlx_image_to_window(data->mlx, data->image.floor, \
								SIZE_IMG * j, SIZE_IMG * i);
			j++;
		}
		i++;
	}
}

void	display_item(t_data *data)
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
			if (data->map.line[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->image.prize, \
									SIZE_IMG * j, SIZE_IMG * i);
			else if (data->map.line[i][j] == 'E')
				mlx_image_to_window(data->mlx, data->image.exit, \
									SIZE_IMG * j, SIZE_IMG * i);
			else if (data->map.line[i][j] == '1')
				mlx_image_to_window(data->mlx, data->image.wall, \
									SIZE_IMG * j, SIZE_IMG * i);
			j++;
		}
		i++;
	}
	mlx_image_to_window(data->mlx, data->image.player, \
						data->map.p_x * SIZE_IMG, data->map.p_y * SIZE_IMG);
}
