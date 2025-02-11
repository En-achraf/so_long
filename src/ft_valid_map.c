/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:35:04 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/10 15:13:52 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char **ft_get_grad(char *str, int width, int height) {
    char **arry;
    int (i) ,(j);

    i = 0;
    j = 0;
    arry = malloc(height * sizeof(char *));
    if(!arry)
        return (NULL);
    while(i <= height) {
        arry[i] = malloc(width * sizeof(char));
        if(!arry[i]) {
            while(j <= i)
                free(arry[j++]);
            free(arry);
            return(NULL);
        }
        ft_strlcpy(arry[i], str + (i * (width + 1)), width + 1);
        i++;
    }
    return (arry[i]);
}


void ft_valid_map(char *str, int width, int height)
{
    t_map data;
    int (exit_count), (collectible_count), (player_count);
    int (x), (y);
    char c;
    
    exit_count = 0;
    collectible_count = 0;
    player_count = 0;
    x = 0;
    y = 0;
    data.grad = ft_get_grad(str, width, height);
    if (!data.grad)
    {
        ft_putstr_fd("Error: Failed to create 2D map\n", 2);
        return;
    }
    while(y < height) {
        while(x < width) {
            c = data.grad[x][y];
            if(c == 'p')
                player_count++;
            else if(c == 'C')
                collectible_count++;
            else if(c == 'E')
                exit_count++;
            else if (c != '0' && c != '1')
                return(ft_putstr_fd("Error: Invalid character in map\n", 2), NULL);    
        }
        y++;
    }
    if (player_count != 1 || exit_count != 1 || collectible_count < 1)
        ft_putstr_fd("Error: Invalid player, exit, or collectible count\n", 2);
}