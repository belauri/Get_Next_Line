/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrazale <lbrazale@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:24:12 by lbrazale          #+#    #+#             */
/*   Updated: 2021/10/18 12:10:04 by lbrazale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_cntchr(char const *save, int c)
{
	int	cnt;

	cnt = 0;
	if (!save)
		return (0);
	while (save[cnt] && save[cnt] != c)
		cnt++;
	return (cnt);
}

static char	*ft_gnl_substr(char const *save, unsigned int start, size_t len)
{
	size_t	x;
	char	*str;

	if (start > len)
		return (NULL);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	x = 0;
	while (save[start] && x < len)
		str[x++] = save[start++];
	str[x] = '\0';
	return (str);
}

static char	*ft_gnl_strjoin(char *save, char const *buffer)
{
	size_t	len;
	size_t	x;
	char	*str;

	if (!save && !buffer)
		return (NULL);
	str = malloc (sizeof(char) * (ft_strlen(save) + ft_strlen(buffer) + 1));
	if (!str)
		return (NULL);
	len = 0;
	x = 0;
	while (save[len])
	{
		str[len] = save[len];
		len++;
	}
	while (buffer[x])
		str[len++] = buffer[x++];
	str[len] = '\0';
	free (save);
	return (str);
}

static char	*ft_fillstr(char **save)
{
	char	*str;
	char	*aux;
	ssize_t	cnt;

	if (!*save)
		return (NULL);
	if (**save == '\0')
	{
		free (*save);
		*save = NULL;
		return (NULL);
	}
	aux = *save;
	cnt = ft_cntchr(*save, '\n');
	str = ft_gnl_substr(*save, 0, cnt + 1);
	*save = ft_gnl_substr(*save, cnt + 1, ft_strlen(*save));
	free (aux);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		check;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	check = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (check && (save == NULL || !ft_strchr(save, '\n')))
	{
		check = read (fd, buffer, BUFFER_SIZE);
		if (check == -1)
			break ;
		buffer[check] = '\0';
		if (save == NULL)
			save = ft_strdup (buffer);
		else
			save = ft_gnl_strjoin(save, buffer);
	}
	free (buffer);
	return (ft_fillstr(&save));
}
