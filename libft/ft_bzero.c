/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:40:10 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/14 16:47:02 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The bzero() function writes n zeroed bytes to the string s.  If n is zero, 
 bzero() does nothing.
*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = s;
	while (i < n)
		tmp[i++] = 0;
}
