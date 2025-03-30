/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:43:27 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/30 12:07:45 by acennadi         ###   ########.fr       */
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

// macros
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define ESC 65307
# define BUFFER_SIZE 1
# define TEXTURE_SIZE 100

// structs
typedef struct s_win
{
	void		*mlx;
	void		*win;
}				t_win;

typedef struct s_player
{
	int			x;
	int			y;
	int			player_steps;
}				t_player;

typedef struct s_map
{
	void		*wall_texture;
	void		*floor_texture;
	void		*player_texture;
	void		*doorclose_texture;
	void		*dooropen_texture;
	void		*collectibles_texture;
	void		*playerindoor_texture;
	int			collectibles;
	int			height;
	int			width;
	void		*image;
	char		**grad;
	char		**visited;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	t_win		win;
	t_player	player;
}				t_map;

typedef struct s_var
{
	int			count;
	char		*str;
	int			fd;
	int			i;
	int			x;
	int			y;
	int			player_count;
	int			exit_count;
	int			enmy_count;
	t_map		map;
}				t_var;

typedef struct s_line_data
{
	int			current_width;
	int			first_line;
	int			*width;
	int			*height;
}				t_line_data;

// functionsmov
// map render
void			ft_render_map(t_map *data, t_player player);
void			ft_render(char **map, int width, int height);
void			ft_interactive(t_map *data);
// map validation
int				finditems(char **grad, int width, int height);
int				ft_check_map(char **grad, int width, int height);
char			**ft_valid_map(char *str, int width, int height);

// file reading
char			*ft_read_file(char *str, int *width, int *height);

// utils functions
void			ft_pterr(int error_code);
void			ft_free_grad(char **str, int height);
t_var			*find_position(char **grad, int row, int col, char target);
int				ft_close_window(t_map *data);
void			ft_count_collectibles(t_map *data);
int				check_lenth(char *saved, int arr[], int *width, int *height);
int				handle_character(char c, t_line_data *data);
int				process_line_data(t_line_data *data);

#endif