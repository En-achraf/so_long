/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:01 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/08 16:22:48 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*valid_format(char *str)
{
	int		len;
	char	*s;

	s = ".bar";
	len = ft_strlen(str);
	if (len < 4)
		return ("not valid format");
	if (ft_strncmp(&str[len - 4], s, 4) != 0)
		return ("not valid format");
	return ("valid format");
}
