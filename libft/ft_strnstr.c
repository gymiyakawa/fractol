/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:02:42 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/27 19:03:50 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	while (haystack[i] && needle[j] && i < len && len > 0)
	{
		while (haystack[i] == needle [j] && haystack && i < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i - j]);
			i++;
			j++;
		}
		i -= j;
		j = 0;
		i++;
	}
	return (NULL);
}
