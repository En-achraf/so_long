#include "includes/so_long.h"

int main(int ac, char **av) {
    char *map;

    if (ac != 2) {
        ft_print_error(1);
        return (0);
    }
    map = ft_read_map(av[1]);
    if (!map) {
        ft_print_error(2);
        return (1);
    }
    printf("%s", map);
    free(map);
    return (0);
}
