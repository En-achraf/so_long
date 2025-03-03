/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:07:11 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/03 16:43:00 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_explore(char **grad, char **visited, int y, int x, int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height)
        return 0;
    printf("Exploring (%d, %d)\n", y, x);
    if (!visited || !visited[y] || !grad || !grad[y])
        return 0;
    if (visited[y][x] == 'Y' || grad[y][x] == '1')
        return 0;
    if (grad[y][x] == 'E')
        return 1;
        
    visited[y][x] = 'Y';

    if (ft_explore(grad, visited, y, x + 1, width, height) ||
        ft_explore(grad, visited, y, x - 1, width, height) ||
        ft_explore(grad, visited, y + 1, x, width, height) ||
        ft_explore(grad, visited, y - 1, x, width, height))
        return 1;

    return 0;
}

char **fill(char **arr, int width, int height)
{
    t_var data;

    arr = malloc(sizeof(char *) * height);
    if(!arr)
        return (NULL);
    data.y = 0;
    while(data.y < height) {
        arr[data.y] = malloc(sizeof(char) * width + 1);
        if(!arr[data.y])
            return(ft_free_grad(arr, height), NULL);
        data.x = 0;
        while(data.x < width) {
            arr[data.y][data.x] = 'F';
            data.x++;
        }
        arr[data.y][data.x] = '\0';
        data.y++;
    }
    return (arr);
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
                position.x = j;
                position.y = i;
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
    t_var (position);
    int (result), (x), (y);
    position.count = ft_check_map(grad, width, height);
    if(position.count == 1)
        return (1);
    position = find_position(grad, height, width, 'P');
    if(position.x == -1 || position.y == -1)
        return (1);
    x = position.x;
    y = position.y;
    printf("the loction of player is %d/%d\n", y, x);
    position.map.visited = fill(position.map.visited, width, height);
    if(!position.map.visited)
        return(1);
    result = ft_explore(grad, position.map.visited, y, x, width, height);
    ft_putstr_fd("the explore function return : ", 1);
    ft_putnbr_fd(result, 1);
    ft_putchar_fd('\n', 1);
    ft_free_grad(position.map.visited, height);
    return (result);
}

