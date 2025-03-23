/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:56:38 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/23 16:39:48 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_check_character(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != 'E' && str[i] != 'P' && str[i] != 'C' 
            && str[i] != '1' && str[i] != '0' && str[i] != '\n')
            return (ft_pterr(3), 1); 
        i++;
    }
    return (0);
}

char	**To_2D(char *str, int width, int height)
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
	if(data.count)
		return (NULL);
	data.map.grad = To_2D(str, width, height);
	if (!data.map.grad)
		return (NULL);
	data.count = findItems(data.map.grad, width, height);
	if (!data.count)
		return (ft_pterr(4), ft_free_grad(data.map.grad, height), NULL);
	return (data.map.grad);
}
