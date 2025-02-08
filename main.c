/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:03 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/08 16:09:07 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_work(char *av)
{
	char	*map;

	if (ft_strncmp(valid_map(av), "not valid format", 15) == 0)
		return (ft_print_error(2), 1);
	else
		ft_print_error(3);
	map = ft_read_map(av);
	if (!map)
	{
		return (1);
	}
	ft_putstr_fd(map, 1);
	free(map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (ft_print_error(1) ,0);
	check_work(av[1]);
	return (0);
}
