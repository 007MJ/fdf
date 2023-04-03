/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:46:55 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/04/03 16:43:03 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/include/MLX42/MLX42.h"


# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
char	*ft_concante(char *dst, char *src, int *stop);
char	*get_next_line(int fd);
char	*ft_srch_backn(char *src);
char	*ft_memmove(char *dst, char *src, size_t len);
char	*ft_memcpy(char *dst, const char *src, size_t n);
char	*strmalloc(int size);

#endif
