/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:18:43 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/16 16:37:32 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_get_grad(char *str, int width, int height)
{
	char	**arry;
	int		i;

	arry = malloc(height * sizeof(char *));
	if (!arry)
		return (NULL);
	i = 0;
	while (i < height)
	{
		arry[i] = malloc((width + 1) * sizeof(char));
		if (!arry[i])
		{
			ft_free_grad(arry, i);
			return (NULL);
		}
		ft_strlcpy(arry[i], str + (i * (width + 1)), width + 1);
		i++;
	}
	return (arry);
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
	int (x), (y);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
			{
				if (grad[y][x] != '1')
				{
					ft_putstr_fd("Error: Map is not surrounded by walls\n", 2);
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_map_contents(int player, int exit, int collectible)
{
	if (player != 1)
		return (0);
	if (exit != 1)
		return (0);
	if (collectible < 1)
		return (0);
	return (1);
}

char	**ft_valid_map(char *str, int width, int height)
{
	t_map	data;

	data.player = 0;
	data.collectible = 0;
	data.exit = 0;
	data.grad = ft_get_grad(str, width, height);
	if (!data.grad)
		return (ft_putstr_fd("Error: Failed to create 2D map\n", 2), NULL);
	data.y = -1;
	while (++data.y < height)
	{
		data.x = -1;
		while (++data.x < width)
		{
			data.mapvar = ft_validate_map_char(data.grad[data.y][data.x],
					&data.player, &data.collectible, &data.exit);
			if (!data.mapvar)
				return (ft_free_grad(data.grad, height), ft_prer(4), NULL);
		}
	}
	if (!ft_check_border(data.grad, width, height))
		return (ft_free_grad(data.grad, height), NULL);
	if (!ft_check_map_contents(data.player, data.exit, data.collectible))
		return (ft_free_grad(data.grad, height), ft_prer(5), NULL);
	return (data.grad);
}
