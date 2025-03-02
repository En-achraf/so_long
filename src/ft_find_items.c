/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:07:11 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/02 12:28:25 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_explore(char **grad, int x, int y) {
    char **visited;
    
    if(grad[y][x] == '1' || grad[y][x] == 'C' || visited[y][x])
        return 2;
    
    visited[y][x] = 0;

    ft_explore(grad, x + 1, y); ///Right
    ft_explore(grad, x - 1, y); ///Left
    ft_explore(grad, x, y + 1); ///Up
    ft_explore(grad, x, y - 1); ///Down

    return 0;
}

t_var find_position(char **grad, int row, int col, char target)
{
    t_var position;
    int i;
    int j;

    i = 0;
    position.x = -1;
    position.y = -1;
    while (i < row)
    {
        j = 0;
        while (j < col)
        {
            if (grad[i][j] == target)
            {
                position.x = i;
                position.y = j;
                return position;
            }
            j++;
        }
        i++;
    }
    return position;
}

int findItems(char **grad, int width, int height)
{
    t_var position;
    
    position.count = ft_check_map(grad, width, height);
    if(position.count == 1)
        return (1);
    position = find_position(grad, height, width, 'P');
    if(position.x == -1 || position.y == -1)
        return (1);
    position.map.start_x = position.x;
    position.map.start_y = position.y;
    position = find_position(grad, height, width, 'E');
    if(position.x == -1 || position.y == -1)
        return (1);
    position.map.end_x = position.x;
    position.map.end_y = position.y;
    position.i = ft_explore(grad, position.map.start_x, position.map.start_y);
    if(!position.i)
        return (1);
    return 0;
}

