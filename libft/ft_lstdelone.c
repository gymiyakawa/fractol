/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:03:52 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/08 16:44:10 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && lst->content)
	{
		del(lst->content);
		lst->content = NULL;
	}
	free (lst);
	lst = NULL;
}

/*
There is an assumption that function del will behave as 
	free (argument);

	
	
Function name ft_lstdelone
Prototype void ft_lstdelone(t_list *lst, void (*del)(void
*));
Turn in files -
Parameters #1. The element to free.
#2. The address of the function used to delete the
content.
Return value None
External functs. free
Description Takes as a parameter an element and frees the
memory of the element’s content using the function
’del’ given as a parameter and free the element.
The memory of ’next’ must not be freed.
*/