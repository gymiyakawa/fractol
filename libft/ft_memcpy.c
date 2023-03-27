/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:49:14 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 16:37:12 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str_dst;
	char	*str_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	str_dst = (char *)dst;
	str_src = (char *)src;
	while (i < n)
	{
		str_dst[i] = str_src [i];
		i++;
	}
	return (dst);
}
