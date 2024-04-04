/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:39:43 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 17:44:26 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// my header file
# include "lib/libft/libft.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/ft_printf/ft_printf.h"

// needed header files
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

// game needed vars
# define SIZE_IMG	50
# define SIZE_IMG	50

typedef struct s_map
{
	char	**line;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		prize_len;
	int		prize_count;
	int		move;
}t_map;

typedef struct s_image
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*prize;
	mlx_image_t	*player;
	mlx_image_t	*exit;
}t_image;

// the main struct
typedef struct s_data
{
	t_map		map;
	t_image		image;
	mlx_t		*mlx;
}t_data;

//create_struct for images
void	*create_image(t_data *data, char *str);
void	image_struct(t_data *data);

// display map of the game
void	display_map(t_data *data);
void	display_background(t_data *data);
void	display_item(t_data *data);

//move the player
void	key_hook(mlx_key_data_t keyData, void *param);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_top(t_data *data);
void	move_down(t_data *data);

//checks if the map has all the requirements to be played
int		valid_map(t_data *data);
int		rectangular_shape(t_data *data);
int		closed_map(t_data *data);
int		check_item(t_data *data);
int		check_map(char **ptr);

// map_init.c
void	map_init(t_data *data, char *map);
void	store_map(t_data *data, char *map);
void	set_values(t_data *data);
int		only_character(char *str, int c);

//utils.c
void	free_ptr(char **ptr);
void	value_init(t_data *data);
int		remove_prize(t_data *data);
int		map_len(char *map);

//flood_fill is algorithm to check whether the map is valid or not
int		valid_path(t_data *data);
char	**copy_map(t_data *data);
void	flood_fill(char **map, int y, int x);
int		valid_character(t_data *data);

#endif
