/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:25:21 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/16 15:22:34 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_grad(char **grad, int height)
{
	int	i;

	i = 0;
	if (!grad)
		return ;
	while (i < height)
	{
		free(grad[i]);
		i++;
	}
	free(grad);
}
