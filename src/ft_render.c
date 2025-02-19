/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:18:39 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/19 13:02:36 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_game(t_game *game, char *map_path)
{
	game->win.mlx = mlx_init();
	if (!game->win.mlx)
		ft_error(6);
	game->map.grad = ft_valid_map(map_path, &game->map.width,
			&game->map.height);
	if (!game->map.grad)
		ft_error(7);
	game->win.win = mlx_new_window(game->win.mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win.win)
		ft_error(8);
	game->wall.img = mlx_xpm_file_to_image(game->win.mlx, "textures/wall.xpm",
			&game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->win.mlx, "textures/floor.xpm",
			&game->floor.width, &game->floor.height);
	game->player.img = mlx_xpm_file_to_image(game->win.mlx,
			"textures/player.xpm", &game->player.width, &game->player.height);
	game->collectible.img = mlx_xpm_file_to_image(game->win.mlx,
			"textures/collectible.xpm", &game->collectible.width,
			&game->collectible.height);
	game->exit.img = mlx_xpm_file_to_image(game->win.mlx, "textures/exit.xpm",
			&game->exit.width, &game->exit.height);
	if (!game->wall.img || !game->floor.img || !game->player.img
		|| !game->collectible.img || !game->exit.img)
		ft_error(ERR_TEX);
	game->map.moves = 0;
	game->map.collectibles = 0;
	game->map.exit = 0;
}

int	ft_close_game(t_game *game)
{
	if (game->win.mlx)
	{
		if (game->wall.img)
			mlx_destroy_image(game->win.mlx, game->wall.img);
		if (game->floor.img)
			mlx_destroy_image(game->win.mlx, game->floor.img);
		if (game->player.img)
			mlx_destroy_image(game->win.mlx, game->player.img);
		if (game->collectible.img)
			mlx_destroy_image(game->win.mlx, game->collectible.img);
		if (game->exit.img)
			mlx_destroy_image(game->win.mlx, game->exit.img);
		if (game->win.win)
			mlx_destroy_window(game->win.mlx, game->win.win);
		mlx_destroy_display(game->win.mlx);
		free(game->win.mlx);
	}
	ft_free_grad(game->map.grad, game->map.height);
	exit(0);
}
int	ft_render_frame(t_game *game)
{
	t_var(var);
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