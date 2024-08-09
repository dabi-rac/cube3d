/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:16:42 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/27 12:24:20 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n;

	if (new == NULL || !lst)
		return ;
	n = *lst;
	if (n == NULL)
	{
		*lst = new;
		return ;
	}
	while (n->next != NULL)
		n = n->next;
	n->next = new;
}
