/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:06 by acennadi          #+#    #+#             */
/*   Updated: 2025/02/15 15:28:21 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_stjoin(char *s1, const char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
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

static void	update_dimensions(char *saved, int *width, int *height)
{
	int	i;

	i = 0;
	if (*height == 0)
	{
		while (saved[i] && saved[i] != '\n')
			i++;
		*width = i;
	}
	i = 0;
	while (saved[i])
	{
		if (saved[i] == '\n')
			(*height)++;
		i++;
	}
	if (saved[i - 1] != '\n' && i > 0)
		(*height)++;
}

static char	*read_loop(int fd, char *saved, int *width, int *height)
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
		if (count == -1 || count > BUFFER_SIZE)
			return (handle_read_error(buffer, saved, fd));
		buffer[count] = '\0';
		saved = ft_stjoin(saved, buffer);
		if (!saved)
			return (handle_read_error(buffer, NULL, fd));
	}
	update_dimensions(saved, width, height);
	free(buffer);
	return (saved);
}

char	*ft_read_map(char *str, int *width, int *height)
{
	int		fd;
	char	*saved;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	saved = ft_strdup("");
	if (!saved)
	{
		close(fd);
		return (NULL);
	}
	saved = read_loop(fd, saved, width, height);
	close(fd);
	return (saved);
}
