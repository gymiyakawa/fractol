/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:22:58 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 17:15:43 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	res = ft_strdup((char *)s);
	if (!res)
		return (NULL);
	while (res[i])
	{
		res[i] = f(i, res[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
