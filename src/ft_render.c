/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:18:39 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/18 20:33:41 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_map(const char *str)
{
	t_game	game;
	int		width;
	int		height;

	game.map.grad = ft_valid_map((char *)str, &width, &height);
	if (!game.map.grad)
		ft_error(ERR_MAP);
	game.map.width = width;
	game.map.height = height;
	ft_init_game(&game, (char *)str);
	ft_render_frame(&game);
}

int	ft_render_frame(t_game *game)
{
	t_var (var);
	var.y = -1;
	while (++var.y < game->map.height)
	{
		var.x = -1;
		while (++var.x < game->map.width)
		{
			mlx_put_image_to_window(game->win.mlx, game->win.win,
				game->floor.img, var.x * TILE_SIZE, var.y * TILE_SIZE);
			if (game->map.grad[var.y][var.x] == '1')
				mlx_put_image_to_window(game->win.mlx, game->win.win,
					game->wall.img, var.x * TILE_SIZE, var.y * TILE_SIZE);
			else if (game->map.grad[var.y][var.x] == 'C')
				mlx_put_image_to_window(game->win.mlx, game->win.win,
					game->collectible.img, var.x * TILE_SIZE, var.y
					* TILE_SIZE);
			else if (game->map.grad[var.y][var.x] == 'E')
				mlx_put_image_to_window(game->win.mlx, game->win.win,
					game->exit.img, var.x * TILE_SIZE, var.y * TILE_SIZE);
			else if (game->map.grad[var.y][var.x] == 'P')
				mlx_put_image_to_window(game->win.mlx, game->win.win,
					game->player.img, var.x * TILE_SIZE, var.y * TILE_SIZE);
		}
	}
	return (0);
}
