/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:37:01 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/20 14:06:21 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s_ptr;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	s_ptr = (char *)malloc(len + 1);
	if (s_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s_ptr[i] = s[i];
		i++;
	}
	s_ptr[i] = '\0';
	return (s_ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (!dest || !src)
		return (NULL);
	if (dest == src)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*total_alloc;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_alloc = malloc(s1_len + s2_len + 1);
	if (!total_alloc)
		return (NULL);
	ft_memcpy(total_alloc, s1, s1_len);
	ft_memcpy(total_alloc + s1_len, s2, s2_len);
	total_alloc[s1_len + s2_len] = '\0';
	return (total_alloc);
}
