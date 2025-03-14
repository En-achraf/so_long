/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:43:45 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/14 17:22:54 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void *ft_load_textures(void *mlx, int num) {
    t_var data;
    data.map.width = TEXTURE_SIZE;
    data.map.height = TEXTURE_SIZE;

    if (num == 0)
        data.map.image = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &data.map.width, &data.map.height);
    else if (num == 1)
        data.map.image = mlx_xpm_file_to_image(mlx, "textures/floar.xpm", &data.map.width, &data.map.height);
    else if (num == 2)
        data.map.image = mlx_xpm_file_to_image(mlx, "textures/walk_Down.xpm", &data.map.width , &data.map.height);
    return data.map.image;
}

void ft_render_map(char **map, void *mlx, void *win, int arr[])
{
    t_var data;
    void *wall_texture;
    void *floar_texture;
    void *player_texture;
	
	data.y = 0;
    wall_texture = ft_load_textures(mlx, 0);
    floar_texture = ft_load_textures(mlx, 1);
    player_texture = ft_load_textures(mlx, 2);
    if (!wall_texture)
		return;
    while(data.y < arr[1])
    {
	    data.x = 0;
        while(data.x < arr[0])
        {
            if(map[data.y][data.x] == '1')
                mlx_put_image_to_window(mlx, win, wall_texture, data.x * TEXTURE_SIZE, data.y * TEXTURE_SIZE);
            else if(map[data.y][data.x] == '0')
                mlx_put_image_to_window(mlx, win, floar_texture, data.x * TEXTURE_SIZE, data.y * TEXTURE_SIZE);
            else if(map[data.y][data.x] == 'P')
                mlx_put_image_to_window(mlx, win, player_texture, data.x * TEXTURE_SIZE, data.y * TEXTURE_SIZE);
            data.x++;
        }
        data.y++;
    }
    mlx_destroy_image(mlx, wall_texture);
    mlx_destroy_image(mlx, floar_texture);
}

int ft_close_window(void *param)
{
    t_map *data = (t_map *)param;
    mlx_destroy_window(data->win.mlx, data->win.win);
    exit(0);
    return (0);
}

void ft_render(char **map, int width, int height)
{
    t_map data;
    int size[1];

    size[0] = width;
    size[1] = height;
    data.win.mlx = mlx_init();
    if (!data.win.mlx)
        return (ft_putstr_fd("Error :  MLX initialization failed\n", 2));
    data.win.win = mlx_new_window(data.win.mlx, width * TEXTURE_SIZE, height * TEXTURE_SIZE, "so_long");
    if (!data.win.win)
        return (ft_putstr_fd("Error : Window creation failed\n", 2));
    ft_render_map(map, data.win.mlx, data.win.win, size);
    ft_interactive(map, size, data.win.win, &data);
    mlx_hook(data.win.win, 17, 0, ft_close_window, &data);
    mlx_loop(data.win.mlx);
}
