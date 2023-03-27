/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:42:49 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/10 17:51:43 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t n)
{
	size_t	j;
	size_t	dstsize;
	size_t	srcsize;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	j = 0;
	if (n <= dstsize)
		return (n + srcsize);
	while ((dstsize + 1 < n) && (n > 0) && src[j])
	{
		dst[dstsize++] = src[j++];
	}
	dst[dstsize] = '\0';
	return (dstsize + ft_strlen(&src[j]));
}
