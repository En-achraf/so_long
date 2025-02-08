/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:59:58 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/08 15:59:59 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// includes
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// define
# define ESC 65307
# define BUFFER_SIZE 1024

// functions
int		key_hook(int keycode, void *param);
void	ft_print_error(int num);
char	*ft_read_map(char *str);
char	*valid_map(char *str);

// structs
typedef struct s_map
{
}		t_map;

#endif