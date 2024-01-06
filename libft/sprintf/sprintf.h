/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:46:54 by thole             #+#    #+#             */
/*   Updated: 2023/11/14 12:08:44 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRINTF_H
# define SPRINTF_H

# include "../libft.h"

int	ft_sprintf_strdup(const char *s, char **str);
int	ft_sprintf_strdup2(char **str);
int	ft_sprintf_itoa(int n, char **s);
int	ft_sprintf_uitoa(unsigned int n, char **s);
int	ft_sprintf_hexa(unsigned int nb, char *base, char **str);
int	ft_sprintf_pointer(unsigned long long p, char *base, char **str);
int	ft_sprintf(char *buffer, const char *str, ...);

#endif
