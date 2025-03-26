#include "../includes/so_long.h"

void	ft_pterr(int error_code)
{
	if (error_code == 0)
		ft_putstr_fd("Error :  enter file name\n", 2);
	else if (error_code == 1)
		ft_putstr_fd("Error : file not '.ber'\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Error : no file exist with this name, or file is empty or map size not valid\n",
			2);
	else if (error_code == 3)
		ft_putstr_fd("Error : something wrong with P/E/C charcters\n", 2);
	else if (error_code == 4)
		ft_putstr_fd("Error : invalid 2D map\n", 2);
	else
		ft_putstr_fd("Error : indefine error\n", 2);
}