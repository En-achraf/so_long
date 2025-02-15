/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:03 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/15 16:59:39 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	*check_work(char *av, int *width, int *height)
{
	char		*map;
	t_window	data;

	data.height = 0;
	data.width = 0;

	if (ft_strncmp(valid_format(av), "not valid format", 15) == 0)
		return (ft_print_error(2), NULL);
	else
		ft_print_error(3);

	map = ft_read_map(av, &data.width, &data.height);
	if (!map)
	{
		ft_putstr_fd("but file doesn't exist\n", 1);
		return (NULL);
	}
	*width = data.width;
	*height = data.height;
	return (map);
}

int	main(int ac, char **av)
{
	char	*ptr;
	int		width, height;
	char	**grad;

	if (ac != 2)
	{
		ft_print_error(1);
		return (0);
	}

	ptr = check_work(av[1], &width, &height);
	if (!ptr)
		return (free(ptr), 0);
	grad = ft_valid_map(ptr, width, height);
	free(ptr);
	if (grad)
		ft_free_grad(grad, height);
	return (0);
}
