#include "../includes/so_long.h"

static int explore(char **grad, t_map *map, int x, int y)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
        return 0;
    if (map->visited[y][x] == 'y' || grad[y][x] == '1')
        return 0;
    if (grad[y][x] == 'C')
        map->collectibles--;
    if (grad[y][x] == 'E')
        return (map->collectibles == 0);
    map->visited[y][x] = 'y';
    if (explore(grad, map, x + 1, y) || explore(grad, map, x - 1, y) ||
        explore(grad, map, x, y + 1) || explore(grad, map, x, y - 1))
        return 1;
    map->visited[y][x] = 'n';
    return 0;
}

char **create_visited(int width, int height)
{
    char **visited = malloc(height * sizeof(char *));
    if (!visited) return NULL;
    for (int y = 0; y < height; y++) {
        visited[y] = malloc(width + 1);
        if (!visited[y]) {
            ft_free_grad(visited, y);
            return NULL;
        }
        ft_memset(visited[y], 'n', width);
        visited[y][width] = '\0';
    }
    return visited;
}


t_var *find_position(char **grad, int rows, int cols, char target) {
    t_var *pos = malloc(sizeof(t_var));
    if (!pos) return NULL;
    pos->x = -1;
    pos->y = -1;

    int y = 0;
    while (y < rows) {
        int x = 0;
        while (x < cols) {
            if (grad[y][x] == target) {
                pos->x = x;
                pos->y = y;
                return pos;
            }
            x++;
        }
        y++;
    }
    return pos;
}

int findItems(char **grad, int width, int height)
{
    t_var *pos = find_position(grad, height, width, 'P');
    if (pos->x == -1 || pos->y == -1) {
        free(pos);
        return 0;
    }
    t_map map = {
        .grad = grad,
        .width = width,
        .height = height,
        .collectibles = 0,
        .visited = create_visited(width, height)
    };
    if (!map.visited) {
        free(pos);
        return 0;
    }
    ft_count_collectibles(&map);
    int result = explore(grad, &map, pos->x, pos->y);
    ft_free_grad(map.visited, height);
    free(pos);
    return result;
}