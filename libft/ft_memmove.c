/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:10:04 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 16:38:53 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (n-- > 0)
	{
		if (s < d)
		{
			d[n] = s[n];
		}
		else
		d[i] = s[i];
		i++;
	}
	return (dst);
}
