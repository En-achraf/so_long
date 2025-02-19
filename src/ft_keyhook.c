/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:46:40 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/19 08:52:27 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_key_hook(int keycode, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (keycode == ESC)
    {
        mlx_destroy_window(game->win.mlx, game->win.win);
        ft_close_game(game);
    }
    return (0);
}
