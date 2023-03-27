/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:43:14 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/07 17:33:05 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*a1;

	a1 = (t_list *)malloc(sizeof(t_list));
	if (!a1)
		return (NULL);
	a1->next = NULL;
	a1->content = content;
	return (a1);
}
