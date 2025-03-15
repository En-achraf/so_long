/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:19:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/15 20:33:16 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to close the game window and free resources
int ft_close(t_map *data)
{
    if (data)
    {
        if (data->grad)
            ft_free_grad(data->grad, data->height);
        if (data->win.win)
            mlx_destroy_window(data->win.mlx, data->win.win);
        if (data->win.mlx) 
            free(data->win.mlx);
        exit(0);
    }
    return (0);
}

int keyhook(int key_code, t_map *data)
{
    int x = data->player.x;
    int y = data->player.y;

    if (key_code == ESC) 
        ft_close(data);
    else if ((key_code == KEY_W || key_code == KEY_UP) && data->grad[y - 1][x] != '1') 
    {
        data->grad[y][x] = '0';
        data->grad[y - 1][x] = 'P';
        data->player.y--;
    }
    else if ((key_code == KEY_S || key_code == KEY_DOWN) && data->grad[y + 1][x] != '1')
    {
        data->grad[y][x] = '0';
        data->grad[y + 1][x] = 'P';
        data->player.y++;
    }
    else if ((key_code == KEY_A || key_code == KEY_LEFT) && data->grad[y][x - 1] != '1')
    {
        data->grad[y][x] = '0';
        data->grad[y][x - 1] = 'P';
        data->player.x--;
    }
    else if ((key_code == KEY_D || key_code == KEY_RIGHT) && data->grad[y][x + 1] != '1')
    {
        data->grad[y][x] = '0';
        data->grad[y][x + 1] = 'P';
        data->player.x++;
    }
    ft_render_map(data->grad, data->win.mlx, data->win.win, (int[]){data->width, data->height}, data->player);
    return (0);
}

// Function to initialize interactive elements
void ft_interactive(char **map, int arr[], void *window, t_map *data)
{
    t_var position;
    
    data->width = arr[0];
    data->height = arr[1];
    position = find_position(map, arr[1], arr[0], 'P');
    if (position.x == -1 || position.y == -1)
    {
        ft_putstr_fd("Error: Player starting position not found\n", 2);
        exit(1);
    }

    data->player.x = position.x;
    data->player.y = position.y;
    data->grad = map;

    mlx_key_hook(window, keyhook, data);
}