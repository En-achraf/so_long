/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:19:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/20 17:29:02 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int keyhook(int key_code, t_map *data)
{
    int x = data->player.x;
    int y = data->player.y;

    if (key_code == ESC) 
        ft_close_window(data);
    else if ((key_code == KEY_W || key_code == KEY_UP) && data->grad[y - 1][x] != '1') 
    {
        if (data->grad[y - 1][x] == 'E')
            ft_close_window(data);
        else {
            data->grad[y][x] = '0';
            data->grad[y - 1][x] = 'P';
            data->player.y--;
        }
    }
    else if ((key_code == KEY_S || key_code == KEY_DOWN) && data->grad[y + 1][x] != '1')
    {
        if (data->grad[y + 1][x] == 'E')
            ft_close_window(data);
        else {
            data->grad[y][x] = '0';
            data->grad[y + 1][x] = 'P';
            data->player.y++;
        }
    }
    else if ((key_code == KEY_A || key_code == KEY_LEFT) && data->grad[y][x - 1] != '1')
    {
        if (data->grad[y][x - 1] == 'E')
            ft_close_window(data);
        else {
            data->grad[y][x] = '0';
            data->grad[y][x - 1] = 'P';
            data->player.x--;
        }
    }
    else if ((key_code == KEY_D || key_code == KEY_RIGHT) && data->grad[y][x + 1] != '1')
    {
        if (data->grad[y][x + 1] == 'E')
            ft_close_window(data);
        else {    
            data->grad[y][x] = '0';
            data->grad[y][x + 1] = 'P';
            data->player.x++;
        }
    }
    ft_render_map(data, data->player);
    return (0);
}

// Function to initialize interactive elements
void ft_interactive(t_map *data)
{
    t_var position;
    
    position = find_position(data->grad, data->height, data->width, 'P');
    if (position.x == -1 || position.y == -1)
        exit(1);
    data->player.x = position.x;
    data->player.y = position.y;
    position = find_position(data->grad, data->height, data->width, 'E');
    mlx_key_hook(data->win.win, keyhook, data);
}
