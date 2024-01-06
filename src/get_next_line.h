/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:11:02 by thole             #+#    #+#             */
/*   Updated: 2023/11/30 14:11:05 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "so_long.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 28
# endif

char	*get_next_line(int fd);
char	*ft_new_line(char *stock);
char	*ft_delete_past_line(char *buffer_line);
char	*ft_read(int fd, char *stock);
char	*ft_free(char *s);
char	*ft_freestrjoin(char *s1, char *s2);
#endif
