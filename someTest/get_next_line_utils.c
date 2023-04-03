/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:53:09 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/04/03 16:21:31 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_memcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
	{
		return (0);
	}
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_memmove(char *dst, char *src, size_t len)
{
	if (dst >= src)
	{
		while (len > 0)
		{
			dst[len - 1] = src[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}

char	*strmalloc(int size)
{
	char	*ptr;

	ptr = malloc (sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
