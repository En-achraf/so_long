/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:19:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/15 06:57:00 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to close the game window and free resources
int ft_close(t_map *data)
{
    if (data)
    {
        // Free the map grid (grad)
        if (data->grad)
            ft_free_grad(data->grad, data->height);

        // Destroy the MLX window
        if (data->win.win)
            mlx_destroy_window(data->win.mlx, data->win.win);

        // Free the MLX instance
        if (data->win.mlx)
        {
            // Note: On some systems, mlx_destroy_display may be needed
            // mlx_destroy_display(data->win.mlx);
            free(data->win.mlx);
        }

        // Exit the program
        exit(0);
    }
    return (0);
}

// Function to handle key presses
int keyhook(int key_code, t_map *data)
{
    int x = data->player.x;
    int y = data->player.y;

    if (key_code == ESC) // ESC key to close the game
        ft_close(data);
    else if (key_code == KEY_W && data->grad[y - 1][x] != '1') // Move up
    {
        data->grad[y][x] = '0'; // Clear old position
        data->grad[y - 1][x] = 'P'; // Update new position
        data->player.y--;
    }
    else if (key_code == KEY_S && data->grad[y + 1][x] != '1') // Move down
    {
        data->grad[y][x] = '0';
        data->grad[y + 1][x] = 'P';
        data->player.y++;
    }
    else if (key_code == KEY_A && data->grad[y][x - 1] != '1') // Move left
    {
        data->grad[y][x] = '0';
        data->grad[y][x - 1] = 'P';
        data->player.x--;
    }
    else if (key_code == KEY_D && data->grad[y][x + 1] != '1') // Move right
    {
        data->grad[y][x] = '0';
        data->grad[y][x + 1] = 'P';
        data->player.x++;
    }

    // Re-render the map with the updated player position
    ft_render_map(data->grad, data->win.mlx, data->win.win, (int[]){data->width, data->height}, data->player);
    return (0);
}

// Function to initialize interactive elements
void ft_interactive(char **map, int arr[], void *window, t_map *data)
{
    t_var position;
    
    // Find the player's starting position
    position = find_position(map, arr[1], arr[0], 'P');
    if (position.x == -1 || position.y == -1)
    {
        ft_putstr_fd("Error: Player starting position not found\n", 2);
        exit(1);
    }

    // Initialize player position in the data structure
    data->player.x = position.x;
    data->player.y = position.y;
    data->grad = map;

    // Set up the key hook for player movement
    mlx_key_hook(window, keyhook, data);
}