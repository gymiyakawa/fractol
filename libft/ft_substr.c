/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:19:26 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/11/26 14:29:53 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (s == 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		s_len = 0;
	else if (start + len <= s_len)
		s_len = len;
	else
		s_len -= start;
	i = 0;
	str = (char *)malloc (s_len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len > 0 && s[start] && s_len != 0)
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}
