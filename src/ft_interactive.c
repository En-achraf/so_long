/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:19:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/14 17:23:02 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int keyhook(int key_code, t_map *data) 
{
    if(key_code == KEY_D)
    {
               
    }
}

void ft_interactive(char **map, int arr[], void *window, t_map *data)
{
    find_position(map, arr[1], arr[0], 'P');
    mlx_key_hook(window, keyhook, NULL);
}