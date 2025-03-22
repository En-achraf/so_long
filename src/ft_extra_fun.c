/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:00:12 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/22 15:11:52 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_close_window(t_map *data)
{
    if (data)
    {
        if (data->wall_texture)
            mlx_destroy_image(data->win.mlx, data->wall_texture);
        if (data->floor_texture)
            mlx_destroy_image(data->win.mlx, data->floor_texture);
        if (data->player_texture)
            mlx_destroy_image(data->win.mlx, data->player_texture);
		if (data->player_texture)
            mlx_destroy_image(data->win.mlx, data->collectibles_texture);
		if (data->player_texture)
            mlx_destroy_image(data->win.mlx, data->door_texture);

        if (data->grad)
            ft_free_grad(data->grad, data->height);

        if (data->win.win)
            mlx_destroy_window(data->win.mlx, data->win.win);

        if (data->win.mlx)
            mlx_destroy_display(data->win.mlx);
		free(data->win.mlx);

        free(data);
    }

    exit(0);
    return (0);
}

void	ft_free_grad(char **str, int height)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (i < height && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_validate_map_char(char c, int *player, int *collectible, int *exit)
{
	if (c == 'P')
		(*player)++;
	else if (c == 'C')
		(*collectible)++;
	else if (c == 'E')
		(*exit)++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

int	ft_check_border(char **grad, int width, int height)
{
	t_var	data;

	data.y = 0;
	while (data.y < height)
	{
		data.x = 0;
		while (data.x < width)
		{
			if (data.y == 0 || data.y == (height - 1) || data.x == 0
				|| data.x == (width - 1))
			{
				if (grad[data.y][data.x] != '1')
					return (ft_putstr_fd("Error: Map is not surrounded by walls\n",
							2), 1);
			}
			data.x++;
		}
		data.y++;
	}
	return (0);
}

int	ft_check_map(char **grad, int width, int height)
{
	t_var	data;

	data.y = 0;
	data.player_count = 0;
	data.exit_count = 0;
	data.enmy_count = 0;
	data.count = ft_check_border(grad, width, height);
	if (data.count == 1)
		return (1);
	while (data.y < height)
	{
		data.x = 0;
		while (data.x < width)
		{
			ft_validate_map_char(grad[data.y][data.x], &data.player_count,
				&data.enmy_count, &data.exit_count);
			data.x++;
		}
		data.y++;
	}
	if (data.enmy_count < 1 || (data.player_count != 1)
		|| (data.exit_count != 1))
		return (ft_pterr(3), 1);
	return (0);
}
