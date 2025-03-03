/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:43:29 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/03 16:34:40 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_arg(char *arg)
{
    int len;
    int i;
    char *str;

    i = 0;
    str = ".ber";
    len = ft_strlen(arg) - 4;
    while (arg[len] != '\0') {
        if(arg[len] != str[i++])
            return (ft_pterr(1), 1);
        len++;
    }
    return (0);
}

int	main(int ac, char **av)
{
    t_var data;

    if (ac < 2)
		return (ft_pterr(0), 1);
    data.map.width = 0;
    data.map.height = 0;
	check_arg(av[1]);
    data.str = ft_read_file(av[1], &data.map.width, &data.map.height);
    if(!data.str)
        return (ft_pterr(2), 0);
    data.map.grad = ft_valid_map(data.str, data.map.width, data.map.height);
    if(data.map.grad == NULL)
        return (free(data.str) ,0);
    ft_render((data.map.width) * TEXTURE_SIZE, (data.map.height) * TEXTURE_SIZE);
    ft_free_grad(data.map.grad, data.map.height);
}
