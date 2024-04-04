/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 07:44:08 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 14:42:51 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int args, char **argv)
{
	t_data	data;

	if (args != 2)
	{
		ft_printf("Error\n./so_long ./maps/<map_name>\n");
		return (1);
	}
	value_init(&data);
	store_map(&data, argv[1]);
	set_values(&data);
	if (!valid_map(&data))
	{
		ft_printf("Error\ninvalid map\n");
		return (1);
	}
	data.mlx = mlx_init(data.map.width, data.map.height, "SO_LONG 42", 0);
	if (!data.mlx)
		return (1);
	image_struct(&data);
	display_map(&data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
