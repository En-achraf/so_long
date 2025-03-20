/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:43:29 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/20 17:55:25 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

#include "includes/so_long.h"

int check_arg(char *arg)
{
    int len = ft_strlen(arg);
    if (len < 4 || ft_strncmp(arg + len - 4, ".ber", 4) != 0)
        return (ft_pterr(1), 1);
    return (0); // Success
}

int initialize_data(t_var *data, char *filename)
{
    data->map.width = 0;
    data->map.height = 0;

    if (check_arg(filename))
        return (1);
    data->str = ft_read_file(filename, &data->map.width, &data->map.height);
    if (!data->str)
        return (2);
    data->map.grad = ft_valid_map(data->str, data->map.width, data->map.height);
    if (!data->map.grad)
        return (3);

    return (0); // Success
}

int main(int ac, char **av)
{
    t_var data;
    int status;

    if (ac != 2)
        return (ft_pterr(0), 1); // Error: Invalid number of arguments

    status = initialize_data(&data, av[1]);
    if (status)
    {
        if (status == 3) // If ft_valid_map failed, free data->str
            free(data.str);
        return (ft_pterr(status), 1); // Exit with the appropriate error code
    }

    ft_render(data.map.grad, data.map.width, data.map.height);

    ft_free_grad(data.map.grad, data.map.height);
    free(data.str);

    return (0); // Success
}
