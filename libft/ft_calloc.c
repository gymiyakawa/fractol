/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:22:24 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 17:37:23 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The calloc() function contiguously allocates enough space for count objects that 
are size bytes of memory each and returns a pointer to the allocated memory.  
The allocated memory is filled with bytes of value zero.
*/
#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc (count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (count * size));
	return (str);
}
