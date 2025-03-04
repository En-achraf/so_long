/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:43:45 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/04 17:41:04 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void *ft_load_textures(void *mlx, int num) {
    t_var data;
    data.map.width = TEXTURE_SIZE;
    data.map.height = TEXTURE_SIZE;

    if (num == 0)
        data.map.image = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &data.map.width, &data.map.height);
    return data.map.image;
}

void ft_render_map(void *mlx, void *win)
{
    int x, y;
	
	x = 0;
	y = 0;
    void *wall_texture;

    wall_texture = ft_load_textures(mlx, 0);
    if (!wall_texture)
		return;
    mlx_put_image_to_window(mlx, win, wall_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
}

int ft_close_window(void *param)
{
    t_map *data = (t_map *)param;
    mlx_destroy_window(data->win.mlx, data->win.win);
    exit(0);
    return (0);
}

void ft_render(int width, int height)
{
    t_map data;

    data.win.mlx = mlx_init();
    if (!data.win.mlx) {
        printf("MLX initialization failed\n");
        return;
    }
    data.win.win = mlx_new_window(data.win.mlx, width * TEXTURE_SIZE, height * TEXTURE_SIZE, "so_long");
    if (!data.win.win) {
        printf("Window creation failed\n");
        return;
    }
    ft_render_map(data.win.mlx, data.win.win);
    mlx_hook(data.win.win, 17, 0, ft_close_window, &data);
    mlx_loop(data.win.mlx);
}
