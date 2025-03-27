/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:19:00 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/27 16:51:20 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_images(t_map *data, int y, int x)
{
	if (data->grad[y][x] == '0')
		mlx_put_image_to_window(data->win.mlx, data->win.win,
			data->floor_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	else if (data->grad[y][x] == '1')
		mlx_put_image_to_window(data->win.mlx, data->win.win,
			data->wall_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	else if (data->grad[y][x] == 'E')
	{
		if (data->collectibles != 0)
			mlx_put_image_to_window(data->win.mlx, data->win.win,
				data->doorclose_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.win,
				data->dooropen_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	}
	else if (data->grad[y][x] == 'C')
		mlx_put_image_to_window(data->win.mlx, data->win.win,
			data->collectibles_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

void	ft_load_textures(t_map *data)
{
	int	width;
	int	height;

	width = TEXTURE_SIZE;
	height = TEXTURE_SIZE;
	data->wall_texture = mlx_xpm_file_to_image(data->win.mlx,
			"textures/Wall.xpm", &width, &height);
	data->floor_texture = mlx_xpm_file_to_image(data->win.mlx,
			"textures/background.xpm", &width, &height);
	data->player_texture = mlx_xpm_file_to_image(data->win.mlx,
			"textures/player.xpm", &width, &height);
	data->collectibles_texture = mlx_xpm_file_to_image(data->win.mlx,
			"textures/cristal.xpm", &width, &height);
	data->dooropen_texture = mlx_xpm_file_to_image(data->win.mlx,
			"textures/opendoor.xpm", &width, &height);
	data->doorclose_texture = mlx_xpm_file_to_image(data->win.mlx,
			"textures/Doorclose.xpm", &width, &height);
	if (!data->collectibles_texture || !data->wall_texture
		|| !data->player_texture || !data->floor_texture
		|| !data->dooropen_texture || !data->doorclose_texture)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		ft_close_window(data);
	}
}

void	ft_render_map(t_map *data, t_player player)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			ft_put_images(data, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->player_texture,
		player.x * TEXTURE_SIZE, player.y * TEXTURE_SIZE);
}

void	find_player(t_var *position, int width, int height, t_map *data)
{
	if (!position || position->x == -1 || position->y == -1
		|| position->x >= width || position->y >= height)
	{
		if (position)
			free(position);
		ft_putstr_fd("Error: Player position not found\n", 2);
		ft_close_window(data);
	}
	data->player.x = position->x;
	data->player.y = position->y;
	free(position);
}

void	ft_render(char **map, int width, int height)
{
	t_map	*data;
	t_var	*position;

	data = malloc(sizeof(t_map));
	if (!data)
		return (ft_putstr_fd("Error: Memory allocation failed\n", 2));
	data->height = height;
	data->width = width;
	data->grad = map;
	data->collectibles = 0;
	data->win.mlx = mlx_init();
	if (!data->win.mlx)
		ft_close_window(data);
	data->win.win = mlx_new_window(data->win.mlx, width * TEXTURE_SIZE, height
			* TEXTURE_SIZE, "so_long");
	if (!data->win.win)
		ft_close_window(data);
	ft_load_textures(data);
	position = find_position(data->grad, height, width, 'P');
	find_player(position, width, height, data);
	ft_render_map(data, data->player);
	ft_interactive(data);
	mlx_hook(data->win.win, 17, 0, ft_close_window, data);
	mlx_loop(data->win.mlx);
}
