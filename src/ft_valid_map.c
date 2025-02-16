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

int ft_check_boarder(char c) {
	t_window data;
}

int	ft_check_map_contents(char c ,int player, int exit, int collectible)
{
	if (!(ft_check_boarder(c)))
		return (0);
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

	int (player), (collectible), (exit), (y), (x), (mapvar);
	player = 0;
	collectible = 0;
	exit = 0;
	data.grad = ft_get_grad(str, width, height);
	if (!data.grad)
		return (ft_putstr_fd("Error: Failed to create 2D map\n", 2), NULL);
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			mapvar = ft_validate_map_char(data.grad[y][x], &player,
					&collectible, &exit);
			if (!mapvar)
				return (ft_prer(4), ft_free_grad(data.grad, height), NULL);
		}
	}
	if (!ft_check_map_contents(data.grad[y][x], player, exit, collectible))
		return (ft_prer(5), ft_free_grad(data.grad, height), NULL);
	return (data.grad);
}
