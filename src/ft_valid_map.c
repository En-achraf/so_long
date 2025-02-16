/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:35:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/16 14:26:12 by acennadi         ###   ########.fr       */
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
	int		player;
	int		collectible;
	int		exit;
	int		y;
	int		x;

	player = 0;
	collectible = 0;
	exit = 0;
	data.grad = ft_get_grad(str, width, height);
	if (!data.grad)
	{
		ft_putstr_fd("Error: Failed to create 2D map\n", 2);
		return (NULL);
	}
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (!ft_validate_map_char(data.grad[y][x], &player, &collectible, &exit))
			{
				ft_free_grad(data.grad, height);
				ft_putstr_fd("Error: Invalid character in map\n", 2);
				return (NULL);
			}
			x++;
		}
		y++;
	}
	if (!ft_check_map_contents(player, exit, collectible))
	{
		ft_free_grad(data.grad, height);
		ft_putstr_fd("Error: Invalid player, exit, or collectible count\n", 2);
		return (NULL);
	}
	return (data.grad);
}
