/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:08 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/16 16:03:06 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_prer(int num)
{
	if (num == 0)
		ft_putstr_fd("the process Done Successfully\n", 2);
	else if (num == 1)
		ft_putstr_fd("no map available to use, try again\n", 2);
	else if (num == 2)
		ft_putstr_fd("not valid file format\n", 2);
	else if (num == 3)
		ft_putstr_fd("valid file format\n", 2);
	else if (num == 4)
		ft_putstr_fd("Error: Invalid character in map\n", 2);
	else if (num == 5)
		ft_putstr_fd("Error: Invalid player, exit, or collectible count\n", 2);
}
