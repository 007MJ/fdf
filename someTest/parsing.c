/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:57:10 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/04/03 17:18:04 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	numberinfile(int fd)
{
	char	*line;
	int		nletter;
	int		i;
	int		space;

	i = 0;
	space = 0;
	line = malloc (sizeof(char) * BUFFER_SIZE + 1);
	nletter = read(fd, line, BUFFER_SIZE);
	while (nletter > 1)
	{
		nletter = read(fd, line, BUFFER_SIZE);
		line[nletter] = 0;
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n')
				space++;
			i++;
		}
	}
}

char	**parsing(char *argv)
{
	char	*numberline;
	char	**tabline;
	int		fd;

	fd = open(argv, O_RDONLY);
	numberinfile(fd);
}
