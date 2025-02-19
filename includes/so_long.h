/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:59:58 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/19 08:46:07 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// Defines
# define ESC 65307
# define TILE_SIZE 64
# define BUFFER_SIZE 1024

// Error Codes
# define ERR_MAP 1
# define ERR_ARGS 2
# define ERR_MLX 3
# define ERR_TEX 4

// Keycodes (Mac/Linux)
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// Structures
typedef struct s_var
{
	int			collectible;
	char		**grad;
	int			player;
	int			mapvar;
	int			exit;
	int			x;
	int			y;
}				t_var;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
}				t_window;

typedef struct s_map
{
	char		**grad;
	int			width;
	int			height;
	int			collectibles;
	int			exit;
	int			player_x;
	int			player_y;
	int			moves;
}				t_map;

typedef struct s_game
{
	t_window	win;
	t_map		map;
	t_image		wall;
	t_image		floor;
	t_image		player;
	t_image		collectible;
	t_image		exit;
}				t_game;

// Function Prototypes (Parameters preserved as per request)
// Initialization
void			ft_init_game(t_game *game, char *map_path);
void			ft_load_textures(t_game *game);

// Map Handling
char			*ft_read_map(char *str, int *width, int *height);
char			**ft_valid_map(char *str, int *width, int *height);
void			ft_free_map(t_game *game);

// Rendering
int				ft_render_frame(t_game *game);
void			ft_draw_tile(t_game *game, int x, int y);
void			ft_render_map(const char *str);

// Hooks & Events
int 			ft_key_hook(int keycode, void *param);
int				ft_close_game(t_game *game);

// Utilities
void			ft_error(int error_code);
void			ft_free_grad(char **grad, int height);
char			*valid_format(char *str);

#endif