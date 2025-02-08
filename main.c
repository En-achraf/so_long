#include "includes/so_long.h"

int main(int ac, char **av) {
    char *map;

    if (ac != 2) {
        ft_print_error(1);
        return (0);
    }

    if (ft_strncmp(valid_map(av[1]), "not valid format", 15) == 0)
        return (ft_print_error(2) , 1);

    map = ft_read_map(av[1]);
    if (!map) {
        return (1);
    }

    ft_putstr_fd(map, 1);
    free(map);
    return (0);
}
