/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:59:58 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/10 15:06:49 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// includes
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// define
# define ESC 65307
# define BUFFER_SIZE 1024

// functions
int			key_hook(int keycode, void *param);
void		ft_print_error(int num);
char		*ft_read_map(char *str, int *width, int *height);
char		*valid_format(char *str);
void		ft_render_map(const char *str);
void		ft_valid_map(char *str);
// structs
typedef struct s_window
{
	int		width;
	int		height;
}			t_window;

typedef struct s_map
{
	void	**grad;
	void	*wall;
	void	*collectible;
	void	*exit;
}			t_map;

#endif
