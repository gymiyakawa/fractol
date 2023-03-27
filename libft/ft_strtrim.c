/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:38:36 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 14:34:00 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_scanbeg(char *s, char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		while (s[i] == set[j] && s[i])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

static size_t	ft_scanend(char *s, char *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s) - 1;
	j = 0;
	while (set[j])
	{
		while (s[i] == set[j] && i > 0)
		{
			i--;
			j = 0;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	starti;
	size_t	endi;

	if (s1 == NULL || set == NULL)
		return (NULL);
	starti = ft_scanbeg((char *)s1, (char *)set);
	if (starti == ft_strlen(s1))
		return (ft_substr((char *)s1, 0, 0));
	endi = ft_scanend((char *)s1, (char *)set);
	return (ft_substr((char *)s1, starti, endi - starti + 1));
}
