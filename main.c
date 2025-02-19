/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:03 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/19 08:34:22 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	*check_work(char *av, int *width, int *height)
{
	char	*map;

	if (ft_strncmp(valid_format(av), "not valid file format", 23) == 0)
		ft_error(2);
	map = ft_read_map(av, width, height);
	if (!map)
		ft_error(3);
	return (map);
}

int	main(int ac, char **av)
{
	t_game	game;
	char	*map_str;
	int		width;
	int		height;

	if (ac != 2)
		ft_error(1);
	ft_bzero(&game, sizeof(t_game));
	map_str = check_work(av[1], &width, &height);
	game.map.grad = ft_valid_map(map_str, &width, &height);
	if (!game.map.grad)
	{
		free(map_str);
		ft_error(3);
	}
	game.map.width = width;
	game.map.height = height;
	ft_init_game(&game, av[1]);
	mlx_hook(game.win.win, 2, 1L << 0, ft_key_hook, &game);
	mlx_hook(game.win.win, 17, 0, ft_close_game, &game);
	mlx_loop_hook(game.win.mlx, ft_render_frame, &game);
	mlx_loop(game.win.mlx);
	return (0);
}
