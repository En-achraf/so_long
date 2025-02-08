#include "../includes/so_long.h"

static char	*ft_stjoin(char *s1, char const *s2)
{
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy((str + ft_strlen(s1)), (s2), (ft_strlen(s2) + 1));
	free(s1);
	return (str);
}

static char	*handle_read_error(char *buffer, char *saved, int fd)
{
	free(buffer);
	free(saved);
	close(fd);
	return (NULL);
}

static char	*read_loop(int fd, char *saved)
{
	char	*buffer;
	ssize_t	count;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return handle_read_error(buffer, saved, fd);
		buffer[count] = '\0';
		saved = ft_stjoin(saved, buffer);
		if (!saved)
			return handle_read_error(buffer, NULL, fd);
	}
	free(buffer);
	return (saved);
}

char	*ft_read_map(char *str)
{
	int		fd;
	char	*saved;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	saved = ft_strdup("");
	if (!saved)
		return (NULL);
	saved = read_loop(fd, saved);
	close(fd);
	return (saved);
}

