/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thole <thole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:31:34 by thole             #+#    #+#             */
/*   Updated: 2023/11/14 11:31:36 by thole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
		temp = *lst;
	}
	*lst = NULL;
}
