/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:36:43 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 15:56:10 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name ft_lstadd_back

Prototype void ft_lstadd_back(t_list **lst, t_list *new);
Turn in files -

Parameters #1. The address of a pointer to the first link of
a list.

#2. The address of a pointer to the element to be
added to the list.

Return value None
External functs. None
Description Adds the element ’new’ at the end of the list

TENTAR OUTR TESTER!
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
