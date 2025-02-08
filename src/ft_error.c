/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:08 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/08 16:07:28 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_error(int num)
{
	if (num == 0)
		ft_putstr_fd("the process Done Successfully\n", 1);
	else if (num == 1)
		ft_putstr_fd("no map available to use, try again\n", 1);
	else if (num == 2)
		ft_putstr_fd("not valid format\n", 1);
	else if (num == 3)
		ft_putstr_fd("valid format\n", 1);
}
