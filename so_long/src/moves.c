/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:35:04 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 14:28:46 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_hook(mlx_key_data_t keyData, void *param);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_top(t_data *data);
void	move_down(t_data *data);

void	key_hook(mlx_key_data_t keyData, void *param)
{
	t_data	*data;

	data = param;
	if (!data)
		return ;
	if (keyData.key == MLX_KEY_D && keyData.action == \
		MLX_PRESS)
		move_right(data);
	else if (keyData.key == MLX_KEY_A && keyData.action == \
		MLX_PRESS)
		move_left(data);
	else if (keyData.key == MLX_KEY_W && keyData.action == \
		MLX_PRESS)
		move_top(data);
	else if (keyData.key == MLX_KEY_S && keyData.action == \
		MLX_PRESS)
		move_down(data);
	else if (keyData.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
}

void	move_right(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = data->image.player->instances[0].x / SIZE_IMG;
	y = data->image.player->instances[0].y / SIZE_IMG;
	if (data->map.line[y][x + 1] != '1')
	{
		data->image.player->instances[0].x += SIZE_IMG;
		if (data->map.line[y][x + 1] == 'C')
		{
			i = remove_prize(data);
			data->map.prize_count += i;
		}
		else if (data->map.line[y][x + 1] == 'E' && \
			data->map.prize_count == data->map.prize_len)
			mlx_close_window(data->mlx);
		data->map.move ++;
		ft_printf("move %d\n", data->map.move);
	}
}

void	move_left(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = data->image.player->instances[0].x / SIZE_IMG;
	y = data->image.player->instances[0].y / SIZE_IMG;
	if (data->map.line[y][x - 1] != '1')
	{
		data->image.player->instances[0].x -= SIZE_IMG;
		if (data->map.line[y][x - 1] == 'C')
		{
			i = remove_prize(data);
			data->map.prize_count += i;
		}
		else if (data->map.line[y][x - 1] == 'E' && \
				data->map.prize_count == data->map.prize_len)
			mlx_close_window(data->mlx);
		data->map.move ++;
		ft_printf("move %d\n", data->map.move);
	}
}

void	move_top(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = data->image.player->instances[0].x / SIZE_IMG;
	y = data->image.player->instances[0].y / SIZE_IMG;
	if (data->map.line[y - 1][x] != '1')
	{
		data->image.player->instances[0].y -= SIZE_IMG;
		if (data->map.line[y - 1][x] == 'C')
		{
			i = remove_prize(data);
			data->map.prize_count += i;
		}
		else if (data->map.line[y - 1][x] == 'E' && \
			data->map.prize_count == data->map.prize_len)
			mlx_close_window(data->mlx);
		data->map.move ++;
		ft_printf("move %d\n", data->map.move);
	}
}

void	move_down(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = data->image.player->instances[0].x / SIZE_IMG;
	y = data->image.player->instances[0].y / SIZE_IMG;
	if (data->map.line[y + 1][x] != '1')
	{
		data->image.player->instances[0].y += SIZE_IMG;
		if (data->map.line[y + 1][x] == 'C')
		{
			i = remove_prize(data);
			data->map.prize_count += i;
		}
		else if (data->map.line[y + 1][x] == 'E' && \
			data->map.prize_count == data->map.prize_len)
			mlx_close_window(data->mlx);
		data->map.move ++;
		ft_printf("move %d\n", data->map.move);
	}
}
