/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:07:11 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/01 17:47:04 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
    //player position
    position = find_position(grad, height, width, 'P');
    if(position.x == -1 || position.y == -1)
        return (1);
    //exit position
    position = find_position(grad, height, width, 'E');
    if(position.x == -1 || position.y == -1)
        return (1);
    return 0;
}

