/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrazale <lbrazale@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:24:17 by lbrazale          #+#    #+#             */
/*   Updated: 2021/10/18 12:43:28 by lbrazale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strdup(const char *s1)
{
	size_t	cnt;
	size_t	x;
	char	*str;

	cnt = ft_strlen(s1);
	str = malloc((cnt + 1) * sizeof(char));
	if (!str)
		return (NULL);
	x = 0;
	while (s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	if (!s)
		return (0);
	while (s[cnt] && s[cnt] != (char)c)
		cnt++;
	if (s[cnt] == '\0' && (char)c != '\0')
		return (0);
	else
		return ((char *)&s[cnt]);
}
