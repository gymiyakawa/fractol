/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:31:00 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 17:13:41 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	res = (char *)malloc((t_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
