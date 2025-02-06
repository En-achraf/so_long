/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:46:45 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/06 08:36:58 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/so_long.h"

int main(void)
{
    
    t_data img;
	t_map	map;
    
    img.mlx = mlx_init();
    if (!img.mlx)
        return (1);
    img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "so_long");

    map.background = mlx_xpm_file_to_image(img.mlx, "./texture/backgraund/backgraund.xpm", &map.width, &map.height);
    mlx_put_image_to_window(img.mlx, img.mlx_win, map.background, 0, 0);

    mlx_key_hook(img.mlx_win, key_hook, NULL);

    mlx_loop(img.mlx);
    return (0);
}