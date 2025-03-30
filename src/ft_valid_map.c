/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:56:38 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/30 12:17:38 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_character(char c, t_line_data *data)
{
	if (c == '\n')
	{
		if (data->first_line)
		{
			*data->width = data->current_width;
			data->first_line = 0;
		}
		else if (data->current_width != *data->width)
			return (ft_putstr_fd("Inconsistent line or invalid character\n", 2),
				1);
		(*data->height)++;
		data->current_width = 0;
	}
	else
	{
		data->current_width++;
	}
	return (0);
}

int	process_line_data(t_line_data *data)
{
	if (data->current_width > 0)
	{
		if (data->first_line)
			*data->width = data->current_width;
		else if (data->current_width != *data->width)
			return (ft_putstr_fd("Inconsistent line or invalid character\n", 2),
				1);
		(*data->height)++;
	}
	return (0);
}

int	ft_check_bourders(char **map, int height, int width)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][width - 1] == '0' || map[y][0] == '0')
				return (ft_putstr_fd("the map not surrounded by walls\n", 2),
					1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_character(char *str)
{
	t_var	data;

	data.i = 0;
	data.player_count = 0;
	data.enmy_count = 0;
	data.exit_count = 0;
	while (str[data.i])
	{
		if (str[data.i] == 'P')
			data.player_count++;
		if (str[data.i] == 'E')
			data.exit_count++;
		if (str[data.i] == 'C')
			data.enmy_count++;
		if (str[data.i] != 'E' && str[data.i] != 'P' && str[data.i] != 'C'
			&& str[data.i] != '1' && str[data.i] != '0' && str[data.i] != '\n')
			return (ft_pterr(3), 1);
		data.i++;
	}
	if (data.player_count != 1 || data.exit_count != 1 || data.enmy_count < 1)
		return (ft_pterr(3), 1);
	return (0);
}

char	**ft_valid_map(char *str, int width, int height)
{
	t_var	data;

	data.count = ft_check_character(str);
	if (data.count)
		return (free(str), NULL);
	data.map.grad = ft_split(str, '\n');
	if (!data.map.grad)
		return (NULL);
	data.count = ft_check_bourders(data.map.grad, height, width);
	if (data.count)
		return (free(str), ft_free_grad(data.map.grad, height), NULL);
	data.count = finditems(data.map.grad, width, height);
	if (!data.count)
		return (ft_pterr(4), free(str), ft_free_grad(data.map.grad, height),
			NULL);
	return (data.map.grad);
}
