/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:43:45 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/26 14:40:15 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render(int width, int height)
{
	t_map data;

	data.win.mlx = mlx_init();
	data.win.win = mlx_new_window(data.win.mlx, width, height, "test");
	if (!data.win.win)
	{
		mlx_destroy_window(data.win.mlx, data.win.win);
	}
	mlx_loop(data.win.mlx);
}