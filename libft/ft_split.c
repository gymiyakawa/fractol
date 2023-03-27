/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:33:51 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/16 13:33:53 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_scount(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	char	*ft_mksplt(const char *str, size_t n)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc ((n + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	k = 0;
	i = 0;
	array = (char **)malloc ((ft_scount(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
			array[k++] = ft_mksplt(s + j, i - j);
	}
	array[k] = NULL;
	return (array);
}
