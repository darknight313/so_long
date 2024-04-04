/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:00:26 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 14:44:23 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_struct(t_data *data);
void	*create_image(t_data *data, char *str);

void	image_struct(t_data *data)
{
	data->image.wall = create_image(data, "images/w_sp.png");
	data->image.floor = create_image(data, "images/f_sp.png");
	data->image.prize = create_image(data, "images/c_sp.png");
	data->image.player = create_image(data, "images/p_sp.png");
	data->image.exit = create_image(data, "images/e_sp.png");
}

void	*create_image(t_data *data, char *str)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(str);
	image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}
