/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:16:36 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/26 16:36:33 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	explore(char **grad, t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->visited[y][x] == 'y' || grad[y][x] == '1')
		return (0);
	if (grad[y][x] == 'C')
		map->collectibles--;
	if (grad[y][x] == 'E')
		return (map->collectibles == 0);
	map->visited[y][x] = 'y';
	if (explore(grad, map, x + 1, y) || explore(grad, map, x - 1, y)
		|| explore(grad, map, x, y + 1) || explore(grad, map, x, y - 1))
		return (1);
	map->visited[y][x] = 'n';
	return (0);
}

char	**create_visited(int width, int height)
{
	char	**visited;
	int		y;

	y = 0;
	visited = malloc(height * sizeof(char *));
	if (!visited)
		return (NULL);
	while (y < height)
	{
		visited[y] = malloc(width + 1);
		if (!visited[y])
		{
			ft_free_grad(visited, y);
			return (NULL);
		}
		ft_memset(visited[y], 'n', width);
		visited[y][width] = '\0';
		y++;
	}
	return (visited);
}

t_var	*find_position(char **grad, int rows, int cols, char target)
{
	t_var	*pos;
	int		y;
	int		x;

	pos = malloc(sizeof(t_var));
	if (!pos)
		return (NULL);
	pos->x = -1;
	pos->y = -1;
	y = -1;
	while (y++ < rows)
	{
		x = -1;
		while (x++ < cols)
		{
			if (grad[y][x] == target)
			{
				pos->x = x;
				pos->y = y;
				return (pos);
			}
		}
	}
	return (pos);
}

int	finditems(char **grad, int width, int height)
{
	t_var	*pos;
	t_map	map;
	int		result;

	pos = find_position(grad, height, width, 'P');
	if (pos->x == -1 || pos->y == -1)
	{
		free(pos);
		return (0);
	}
	map.grad = grad;
	map.width = width;
	map.height = height;
	map.collectibles = 0;
	map.visited = create_visited(width, height);
	if (!map.visited)
		return (free(pos), 0);
	ft_count_collectibles(&map);
	result = explore(grad, &map, pos->x, pos->y);
	ft_free_grad(map.visited, height);
	free(pos);
	return (result);
}
