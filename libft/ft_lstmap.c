/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:02:18 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/10 14:58:21 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name ft_lstmap
Prototype t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
Turn in files -
Parameters #1. The adress of a pointer to an element.
#2. The adress of the function used to iterate on
the list.
#3. The adress of the function used to delete the
content of an element if needed.
Return value The new list. NULL if the allocation fails.
External functs. malloc, free
Description Iterates the list ’lst’ and applies the function
’f’ to the content of each element. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of an element if needed.

STEPS:
1 - safety check

2 - copies first node into new node while calling function f 
	to act into said node.

3 - checks for malloc error: if the return is NULL. Clears/frees the list 
	if it is.

4 - advances the original list forward one node.

5 - loops while lst is not NULL

6 - holds the content of current node into pointer newcont. Checks for malloc
	faillure, clearing both the list and the pointer if it's the case.
7 - adds the newcont into the new list.

8 - advances the original list forwards one node.
*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcont;

	if (!lst || !f)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (!newlst)
	{
		ft_lstclear(&newlst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		newcont = ft_lstnew(f(lst->content));
		if (!newcont)
		{
			ft_lstclear(&newlst, del);
			ft_lstclear(&newcont, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newcont);
		lst = lst->next;
	}
	return (newlst);
}
