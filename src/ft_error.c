/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:08 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/19 13:06:53 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int error_code)
{
	if (error_code == 0)
		ft_putstr_fd("the process Done Successfully\n", 2);
	else if (error_code == 1)
		ft_putstr_fd("no map available to use, try again\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("not valid file format\n", 2);
	else if (error_code == 3)
		ft_putstr_fd("valid file format\n", 2);
	else if (error_code == 4)
		ft_putstr_fd("Error: Invalid character in map\n", 2);
	else if (error_code == 5)
		ft_putstr_fd("Error: Invalid player, exit, or collectible count\n", 2);
	else if (error_code == 6)
		ft_putstr_fd("MLX Faild Initialize connection\n", 2);
	else if (error_code == 7)
		ft_putstr_fd("Error: Failed to load textures\n", 2);
	else if (error_code == 8)
		ft_putstr_fd("Faild Initialize Window\n", 2);
	else if (error_code == ERR_MAP)
		ft_putstr_fd("indfeine error", 2);
}
