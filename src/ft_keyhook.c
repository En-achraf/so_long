/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:46:40 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/02 12:51:24 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
	{
		ft_putstr_fd("ESC pressed. Exiting...\n", 1);
		exit(0);
	}
	return (0);
}
