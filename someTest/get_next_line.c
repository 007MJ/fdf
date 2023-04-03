/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:07:12 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/04/03 16:21:53 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (i);
}

char	*ft_concante(char *dst, char *src, int *stop)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = strmalloc(ft_strlen(dst) + ft_strlen(src));
	if (dst != NULL)
	{
		while (dst[i])
		{
			tmp[i] = dst[i];
			i++;
		}
		free(dst);
	}
	while (*src)
	{
		tmp[i] = *src;
		if (*src == '\n')
			*stop = 0;
		i++;
		src++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*ft_srch_backn(char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = strmalloc(ft_strlen(src));
	while (src[i])
	{
		str[i] = src[i];
		if (src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str[i] = '\0';
	src = ft_memmove(src, src + i, ft_strlen(src + i));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*dst;
	char		*src;
	int			stop;
	int			readbit;

	stop = 1;
	src = strmalloc(BUFFER_SIZE);
	readbit = read(fd, src, BUFFER_SIZE);
	while (readbit > 0)
	{
		src[readbit] = 0;
		dst = ft_concante(dst, src, &stop);
		if (stop == 0)
			break ;
		readbit = read(fd, src, BUFFER_SIZE);
	}
	free(src);
	if ((readbit == -1) || (readbit <= 0 && ft_strlen(dst) == 0))
	{
		if (dst)
			return (free(dst), dst = NULL, NULL);
		return (NULL);
	}
	return (ft_srch_backn(dst));
}
