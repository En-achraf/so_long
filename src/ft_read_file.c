/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:43:53 by acennadi          #+#    #+#             */
/*   Updated: 2025/03/30 12:11:51 by acennadi         ###   ########.fr       */
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
	if (saved)
		free(saved);
	close(fd);
	return (NULL);
}

static int	update_dimensions(char *saved, int *width, int *height)
{
	int			i;
	int			status;
	t_line_data	data;

	data.current_width = 0;
	data.first_line = 1;
	data.width = width;
	data.height = height;
	i = 0;
	while (saved[i])
	{
		status = handle_character(saved[i], &data);
		if (status)
			return (1);
		i++;
	}
	status = process_line_data(&data);
	return (status);
}

static char	*read_loop(int fd, char *saved, int *width, int *height)
{
	char	*buffer;
	ssize_t	count;
	int		data;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_pterr(2), NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (ft_pterr(2), handle_read_error(buffer, saved, fd));
		buffer[count] = '\0';
		saved = ft_stjoin(saved, buffer);
		if (!saved)
			return (ft_pterr(2), handle_read_error(buffer, saved, fd));
	}
	data = update_dimensions(saved, width, height);
	free(buffer);
	if (data)
		return (free(saved), NULL);
	return (saved);
}

char	*ft_read_file(char *str, int *width, int *height)
{
	t_var	data;

	data.fd = open(str, O_RDONLY);
	if (data.fd == -1)
		return (NULL);
	data.str = ft_strdup("");
	if (!data.str)
	{
		close(data.fd);
		return (NULL);
	}
	data.str = read_loop(data.fd, data.str, width, height);
	if (!data.str || (*width < 4 || *width > 40) || (*height < 4
			|| *height > 20))
	{
		close(data.fd);
		free(data.str);
		return (NULL);
	}
	close(data.fd);
	return (data.str);
}
