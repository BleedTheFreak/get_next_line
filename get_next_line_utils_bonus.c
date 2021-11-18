/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <ytaya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:10:57 by ytaya             #+#    #+#             */
/*   Updated: 2021/11/19 00:10:54 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ret;

	len = 0;
	while (s1[len])
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (ret)
	{
		i = 0;
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (*s1 == '\0' && *s2 == '\0')
		return (ft_strdup("\0"));
	string = (char *)
		malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (string)
	{
		while (*s1)
			string[i++] = *(s1++);
		while (*s2)
			string[i++] = *(s2++);
		string[i] = '\0';
	}
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		dst = (char *)malloc(sizeof(*dst));
	else if (i - start < len)
		dst = (char *)malloc(sizeof(*dst) * (i - start + 1));
	else
		dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[start] && i < len && start < ft_strlen(s))
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
