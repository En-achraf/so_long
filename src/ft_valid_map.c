/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:35:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/15 17:25:38 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_grad(char **grad, int height)
{
	int	i;

	i = 0;
	if (!grad)
		return ;
	while (i < height)
		free(grad[i++]);
	free(grad);
}

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

int	ft_validate_map_char(char c, int *player_count, int *collectible_count,
		int *exit_count)
{
	if (c == 'P')
		(*player_count)++;
	else if (c == 'C')
		(*collectible_count)++;
	else if (c == 'E')
		(*exit_count)++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

int	ft_check_map_contents(int player_count, int exit_count,
		int collectible_count)
{
	if (player_count != 1 || exit_count != 1 || collectible_count < 1)
		return (0);
	return (1);
}

int	ft_process_map_row(char *row, int width, int *player_count,
		int *collectible_count, int *exit_count)
{
	int		x;
	char	c;

	x = 0;
	while (x < width)
	{
		c = row[x];
		if (!ft_validate_map_char(c, player_count, collectible_count,
				exit_count))
			return (0);
		x++;
	}
	return (1);
}

char	**ft_valid_map(char *str, int width, int height)
{
	t_map	data;
	
	int		(exit_count), (collectible_count), (player_count), (y);
	exit_count = 0;
	collectible_count = 0;
	player_count = 0;
	data.grad = ft_get_grad(str, width, height);
	if (!data.grad)
		return (ft_putstr_fd("Error: Failed to create 2D map\n", 2), NULL);
	y = 0;
	while (y < height)
	{
		if (!ft_process_map_row(data.grad[y], width, &player_count, &collectible_count, &exit_count))
			return (ft_free_grad(data.grad, height), ft_putstr_fd("Error: Invalid character in map\n", 2), NULL);
		y++;
	}
	if (!ft_check_map_contents(player_count, exit_count, collectible_count))
		return (ft_free_grad(data.grad, height), ft_putstr_fd("Error: Invalid player, exit, or collectible count\n", 2), NULL);
	return (data.grad);
}
