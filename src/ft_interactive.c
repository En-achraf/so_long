/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:19:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/29 15:45:15 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_count_collectibles(t_map *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->height > y)
	{
		x = 0;
		while (data->width > x)
		{
			if (data->grad[y][x] == 'C')
				data->collectibles++;
			x++;
		}
		y++;
	}
}

static void	move_player(t_map *data, int new_x, int new_y)
{
	ft_putstr_fd("PLAYER_MOVE : ", 1);
	ft_putnbr_fd(data->player.player_steps, 1);
	ft_putchar_fd('\n', 1);
	if (data->grad[new_y][new_x] == 'C')
		data->collectibles--;
	if (data->grad[new_y][new_x] == 'E' && data->collectibles == 0)
		ft_close_window(data);
	else if (data->grad[new_y][new_x] == '0' || data->grad[new_y][new_x] == 'C')
	{
		data->grad[data->player.y][data->player.x] = '0';
		data->grad[new_y][new_x] = 'P';
		data->player.x = new_x;
		data->player.y = new_y;
		data->player.player_steps++;
	}
}

int	keyhook(int key_code, t_map *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (key_code == ESC)
		ft_close_window(data);
	else if ((key_code == KEY_W || key_code == KEY_UP) && y > 0 && data->grad[y
			- 1][x] != '1')
		move_player(data, x, y - 1);
	else if ((key_code == KEY_S || key_code == KEY_DOWN) && y < data->height - 1
		&& data->grad[y + 1][x] != '1')
		move_player(data, x, y + 1);
	else if ((key_code == KEY_A || key_code == KEY_LEFT) && x > 0
		&& data->grad[y][x - 1] != '1')
		move_player(data, x - 1, y);
	else if ((key_code == KEY_D || key_code == KEY_RIGHT) && x < data->width - 1
		&& data->grad[y][x + 1] != '1')
		move_player(data, x + 1, y);
	ft_render_map(data, data->player);
	return (0);
}

void	ft_interactive(t_map *data)
{
	t_var	*position;

	data->player.player_steps = 0;
	position = find_position(data->grad, data->height, data->width, 'P');
	if (!position || position->x == -1 || position->y == -1
		|| position->x >= data->width || position->y >= data->height)
	{
		free(position);
		exit(1);
	}
	data->player.x = position->x;
	data->player.y = position->y;
	free(position);
	position = find_position(data->grad, data->height, data->width, 'E');
	if (!position || position->x == -1 || position->y == -1)
	{
		free(position);
		exit(1);
	}
	data->end_x = position->x;
	data->end_y = position->y;
	free(position);
	ft_count_collectibles(data);
	mlx_key_hook(data->win.win, keyhook, data);
}
