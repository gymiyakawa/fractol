/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:12:54 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/01/27 19:02:26 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
same as strjoin but frees the first argument string
*/
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char const *s1, char const *s2)
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
	free((void *)s1);
	return (res);
}
