/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:43:27 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/15 06:28:55 by acennadi         ###   ########.fr       */
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
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define ESC 65307
# define BUFFER_SIZE 1024
# define TEXTURE_SIZE 32

// structs
typedef struct s_win
{
	void	*mlx;
	void	*win;
}			t_win;

typedef	struct s_player
{
	int x;
	int y;
}	t_player;


typedef struct s_map
{
	
	void 	*wall_texture;
	void	*floor_texture;
	void	*player_texture;
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
	t_player player;
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
void ft_render_map(char **map, void *mlx, void *win, int arr[], t_player player);
void		ft_render(char **map, int width, int height);
void	ft_interactive(char **map, int arr[], void *window, t_map *data);
// map validation
int		findItems(char **grad, int width, int height);
int 	ft_check_map(char** grad, int width, int height);
char		**ft_valid_map(char *str, int width, int height);

// file reading
char		*ft_read_file(char *str, int *width, int *height);

// utils functions
void		ft_pterr(int error_code);
void		ft_free_grad(char **str, int height);
t_var	find_position(char **grad, int row, int col, char target);

#endif