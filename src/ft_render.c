#include "../includes/so_long.h"

// Function to load textures
void *ft_load_textures(void *mlx, int num)
{
    t_var data;
    data.map.width = TEXTURE_SIZE;
    data.map.height = TEXTURE_SIZE;

    if (num == 0)
        data.map.image = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &data.map.width, &data.map.height);
    else if (num == 1)
        data.map.image = mlx_xpm_file_to_image(mlx, "textures/floar.xpm", &data.map.width, &data.map.height);
    else if (num == 2)
        data.map.image = mlx_xpm_file_to_image(mlx, "textures/walk_Down.xpm", &data.map.width , &data.map.height);
    return data.map.image;
}

void ft_render_map(char **map, void *mlx, void *win, int arr[], t_player player)
{
    void *wall_texture = ft_load_textures(mlx, 0);
    void *floor_texture = ft_load_textures(mlx, 1);
    void *player_texture = ft_load_textures(mlx, 2);

    int y = 0;
    while (y < arr[1])
    {
        int x = 0;
        while (x < arr[0])
        {
            if (map[y][x] == '0')
                mlx_put_image_to_window(mlx, win, floor_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
            else if (map[y][x] == '1')
                mlx_put_image_to_window(mlx, win, wall_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
            else if(map[y][x] == 'P')
                mlx_put_image_to_window(mlx, win, player_texture, x * TEXTURE_SIZE, y * TEXTURE_SIZE);

            x++;
        }
        y++;
    }
    mlx_put_image_to_window(mlx, win, player_texture, player.x * TEXTURE_SIZE, player.y * TEXTURE_SIZE);
    mlx_destroy_image(mlx, wall_texture);
    mlx_destroy_image(mlx, floor_texture);
    mlx_destroy_image(mlx, player_texture);
}

int ft_close_window(void *param)
{
    t_map *data = (t_map *)param;
    mlx_destroy_window(data->win.mlx, data->win.win);
    exit(0);
    return (0);
}

// Function to render the game
void ft_render(char **map, int width, int height)
{
    t_map data;
    int size[2];

    size[0] = width;
    size[1] = height;
    data.win.mlx = mlx_init();
    if (!data.win.mlx)
        return (ft_putstr_fd("Error :  MLX initialization failed\n", 2));
    data.win.win = mlx_new_window(data.win.mlx, width * TEXTURE_SIZE, height * TEXTURE_SIZE, "so_long");
    if (!data.win.win)
        return (ft_putstr_fd("Error : Window creation failed\n", 2));

    t_var position = find_position(map, height, width, 'P');
    if (position.x == -1 || position.y == -1)
    {
        ft_putstr_fd("Error: Player starting position not found\n", 2);
        exit(1);
    }
    data.player.x = position.x;
    data.player.y = position.y;
    ft_render_map(map, data.win.mlx, data.win.win, size, data.player);
    ft_interactive(map, size, data.win.win, &data);
    mlx_hook(data.win.win, 17, 0, ft_close_window, &data);
    mlx_loop(data.win.mlx);
}
