#include "../includes/so_long.h"

void	ft_print_error(int num)
{
	if (num == 1)
		ft_putstr_fd("no map available to use, try again\n", 1);
	else if (num == 0)
		ft_putstr_fd("the process Done Successfully\n", 1);
    else if(num == 2)
        ft_putstr_fd("not valid format\n", 1);
    else if(num == 3)
        ft_putstr_fd("valid format\n", 1);
}
