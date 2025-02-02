/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:46:45 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/02 12:49:26 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;

	(void)mlx_window;
	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "so_long");
	mlx_pixel_put(mlx, mlx_window, 0, 0, 0x00FF00);
	mlx_key_hook(mlx_window, key_hook, NULL);
	mlx_loop(mlx);
	return (0);
}
