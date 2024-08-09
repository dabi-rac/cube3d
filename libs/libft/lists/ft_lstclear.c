/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:07:18 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/07 09:56:10 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*second_last;

	if (!lst || !del)
		return ;
	while (*lst && lst)
	{
		second_last = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = second_last;
	}
}
