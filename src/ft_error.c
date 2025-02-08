#include "../includes/so_long.h"

void	ft_print_error(int num)
{
	if (num == 1)
		ft_putstr_fd("no map available to use, try again\n", 1);
	else if (num == 0)
		ft_putstr_fd("the process Done Successfully", 1);
}
