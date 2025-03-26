/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:19:00 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/26 08:03:40 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_doordstatus(t_map *data) {
    int width;
    int height;
    
    width = TEXTURE_SIZE;
    height = TEXTURE_SIZE;
    data->dooropen_texture = mlx_xpm_file_to_image(data->win.mlx, "textures/opendoor.xpm", &width, &height);
    if (!data->dooropen_texture)
        ft_putstr_fd("Error: Failed to load player texture\n", 2);
    data->doorclose_texture = mlx_xpm_file_to_image(data->win.mlx, "textures/Doorclose.xpm", &width, &height);
    if (!data->doorclose_texture)
        ft_putstr_fd("Error: Failed to load wall texture\n", 2);
}

void ft_load_textures(t_map *data)
{
    int width;
    int height;
    
    width = TEXTURE_SIZE;
    height = TEXTURE_SIZE;
    data->wall_texture = mlx_xpm_file_to_image(data->win.mlx, "textures/Wall.xpm", &width, &height);
    if (!data->wall_texture)
        ft_putstr_fd("Error: Failed to load wall texture\n", 2);
    data->floor_texture = mlx_xpm_file_to_image(data->win.mlx, "textures/background.xpm", &width, &height);
    if (!data->floor_texture)
        ft_putstr_fd("Error: Failed to load floor texture\n", 2);
    data->player_texture = mlx_xpm_file_to_image(data->win.mlx, "textures/player.xpm", &width, &height);
    if (!data->player_texture)
        ft_putstr_fd("Error: Failed to load player texture\n", 2);
    data->collectibles_texture = mlx_xpm_file_to_image(data->win.mlx, "textures/cristal.xpm", &width, &height);
    if (!data->collectibles_texture)
        ft_putstr_fd("Error: Failed to load player texture\n", 2);
}

void ft_render_map(t_map *data, t_player player)
{
    int y = 0;
    while (y < data->height)
    {
        int x = 0;
        while (x < data->width)
        {
            if (data->grad[y][x] == '0')
                mlx_put_image_to_window(data->win.mlx, data->win.win, data->floor_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
            else if (data->grad[y][x] == '1')
                mlx_put_image_to_window(data->win.mlx, data->win.win, data->wall_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
            else if(data->grad[y][x] == 'E')
                if(data->collectibles != 0)
                    mlx_put_image_to_window(data->win.mlx, data->win.win, data->doorclose_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
                else
                    mlx_put_image_to_window(data->win.mlx, data->win.win, data->dooropen_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
            else if(data->grad[y][x] == 'C')
                mlx_put_image_to_window(data->win.mlx, data->win.win, data->collectibles_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
            x++;
        }
        y++;
    }
        mlx_put_image_to_window(data->win.mlx, data->win.win, data->player_texture, player.x * TEXTURE_SIZE, player.y * TEXTURE_SIZE);
}


void ft_render(char **map, int width, int height)
{
    t_map *data;
    t_var *position;

    data = malloc(sizeof(t_map));
    if (!data)
        return (ft_putstr_fd("Error: Memory allocation failed\n", 2));
    
    // Initialize basic map data
    data->height = height;
    data->width = width;
    data->grad = map;
    data->collectibles = 0;

    // MLX initialization
    data->win.mlx = mlx_init();
    if (!data->win.mlx)
    {
        free(data);
        return (ft_putstr_fd("Error: MLX initialization failed\n", 2));
    }

    // Window creation
    data->win.win = mlx_new_window(data->win.mlx, 
                                 width * TEXTURE_SIZE, 
                                 height * TEXTURE_SIZE, 
                                 "so_long");
    if (!data->win.win)
    {
        mlx_destroy_display(data->win.mlx);
        free(data);
        return (ft_putstr_fd("Error: Window creation failed\n", 2));
    }

    // Load game assets
    ft_load_textures(data);
    ft_doordstatus(data);

    // Find player position
    position = find_position(map, height, width, 'P');
    if (!position || position->x == -1 || position->y == -1 || 
        position->x >= width || position->y >= height)
    {
        if (position) free(position);
        mlx_destroy_window(data->win.mlx, data->win.win);
        mlx_destroy_display(data->win.mlx);
        free(data);
        ft_putstr_fd("Error: Player position not found\n", 2);
        exit(1);
    }
    data->player.x = position->x;
    data->player.y = position->y;
    free(position);

    // Start game loop
    ft_render_map(data, data->player);
    ft_interactive(data);
    mlx_hook(data->win.win, 17, 0, ft_close_window, data);
    mlx_loop(data->win.mlx);
}
