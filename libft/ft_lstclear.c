/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:22:32 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 16:05:45 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name ft_lstclear
Prototype void ft_lstclear(t_list **lst, void (*del)(void
*));
Turn in files -
Parameters #1. The address of a pointer to an element.
#2. The address of the function used to delete the
content of the element.
Return value None
External functs. free
Description Deletes and frees the given element and every
successor of that element, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL.

----------
Using tmp to keep the address of the following struct.
using del to free the content and then pointing it to NULL.

From there, we free the memory for the struct itself and advance the line
using the address saved on tmp.

*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*tmp;

	while (*lst)
	{		
		tmp = (**lst).next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
	return ;
}
