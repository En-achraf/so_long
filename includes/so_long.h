/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:43:27 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/04 16:45:57 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// includes
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

// macros
# define BUFFER_SIZE 1024
# define TEXTURE_SIZE 64

// structs
typedef struct s_win
{
	void	*mlx;
	void	*win;
}			t_win;

typedef struct s_map
{
	int		height;
	int		width;
	void	*image;
	char	**grad;
	char	**visited;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	t_win	win;
}			t_map;

typedef struct s_var
{
	int		count;
	char	*str;
	int		fd;
	int		i;
	int		x;
	int		y;
	int player_count;
	int exit_count;
	int enmy_count;
	t_map	map;
}			t_var;

// functions
// map render
void		ft_render(int width, int height);
char		**ft_valid_map(char *str, int width, int height);
int 	ft_check_map(char** grad, int width, int height);
int		findItems(char **grad, int width, int height);
t_var	find_position(char **grad, int row, int col, char target);

// file reading
char		*ft_read_file(char *str, int *width, int *height);

// utils functions
void		ft_pterr(int error_code);
void		ft_free_grad(char **str, int height);

#endif