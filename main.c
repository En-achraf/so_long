/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:03 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/08 17:02:24 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char *check_work(char *av)
{
	char	*map;

	if (ft_strncmp(valid_format(av), "not valid format", 15) == 0)
		return (ft_print_error(2), NULL);
	else
		ft_print_error(3);
	map = ft_read_map(av);
	if (!map) {
        free(map);
		return (NULL);
    }
	return(map);
}

int	main(int ac, char **av)
{
    char *ptr;

	if (ac != 2)
		return (ft_print_error(1) ,0);
    ptr = check_work(av[1]);
    if(!ptr)
        return 0;
}
