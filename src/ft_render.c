/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:43:45 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/04 16:56:28 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void *ft_load_textures(void *mlx, int num) {
	t_var texture;
	if(num == 0)
		texture.map.image = mlx_xpm_file_to_image(mlx, "../textures/", 64, 64);

	return (texture.map.image);
}

void ft_render_map(void *mlx, void *win)
{
	t_map	textures;

	
}

void	ft_render(int width, int height)
{
	t_map data;

	data.win.mlx = mlx_init();
	data.win.win = mlx_new_window(data.win.mlx, width * TEXTURE_SIZE, height * TEXTURE_SIZE, "so_long");
	if (!data.win.win)
		mlx_destroy_window(data.win.mlx, data.win.win);
	ft_render_map(data.win.mlx, data.win.win);
	mlx_loop(data.win.mlx);
}
