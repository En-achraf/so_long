/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:47:05 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/06 09:10:55 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// includes
# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

// macros
# define WIDTH 800
# define HEIGHT 500
# define ESC 65307

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
}			t_data;

typedef struct  s_map
{
//for background
	int		width;
	int		height;
	void *background;
//for wall
	int	x;
	int	y;
	void *wall;
}			t_map;

int			key_hook(int keycode, void *param);

#endif