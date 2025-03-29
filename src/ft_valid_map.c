/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:56:38 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/29 16:45:34 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_length(char **map, int height, int width)
{
	int	y;
	int	actual_width;

	y = 0;
	if (!map)
		return (1);
	while (y < height)
	{
		if (!map[y])
			return (1);
		actual_width = 0;
		while (map[y][actual_width] && map[y][actual_width] != '\n')
			actual_width++;
		if (actual_width != width)
			return (ft_putstr_fd("Error: Map width is inconsistent\n", 2), 1);
		if (map[y][width] != '\0' && map[y][width] != '\n')
			return (ft_putstr_fd("Error: Extra characters beyond map width\n",
					2), 1);
		y++;
	}
	return (0);
}

int	ft_check_borders(char **map, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (ft_putstr_fd("Error: Map not surrounded by walls\n", 2), 1);
		if (y == 0 || y == height - 1)
		{
			x = 0;
			while (x < width)
			{
				if (map[y][x] != '1')
					return (ft_putstr_fd("Error: Map not surrounded by walls\n",
							2), 1);
				x++;
			}
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

char	**to_2d(char *str, int width, int height)
{
	t_var	data;

	data.i = 0;
	data.map.grad = malloc((height * sizeof(char *)));
	if (!data.map.grad)
		return (ft_pterr(2), NULL);
	while (data.i < height)
	{
		data.map.grad[data.i] = malloc(sizeof(char) * (width + 1));
		if (!data.map.grad[data.i])
			return (ft_pterr(2), ft_free_grad(data.map.grad, height), NULL);
		ft_strlcpy(data.map.grad[data.i], str + (data.i * (width + 1)), width
			+ 1);
		data.i++;
	}
	return (data.map.grad);
}

char	**ft_valid_map(char *str, int width, int height)
{
	t_var	data;

	data.count = ft_check_character(str);
	if (data.count)
		return (free(str), NULL);
	data.map.grad = to_2d(str, width, height);
	if (!data.map.grad)
		return (NULL);
	data.count = ft_check_length(data.map.grad, height, width);
	if (data.count)
		return (free(str), ft_free_grad(data.map.grad, height), NULL);
	data.count = ft_check_borders(data.map.grad, height, width);
	if (data.count)
		return (free(str), ft_free_grad(data.map.grad, height), NULL);
	data.count = finditems(data.map.grad, width, height);
	if (!data.count)
		return (ft_pterr(4), free(str), ft_free_grad(data.map.grad, height),
			NULL);
	return (data.map.grad);
}
