#include "../includes/so_long.h"

char	*valid_map(char *str)
{
	int		len;
	char	*s;

	s = ".bar";
	len = ft_strlen(str);
	if (len < 4)
		return ("not valid format");
	if (ft_strncmp(&str[len - 4], s, 4) != 0)
		return ("not valid format");
	return ("valid format");
}
