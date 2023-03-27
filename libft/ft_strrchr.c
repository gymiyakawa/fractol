/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:50:23 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/11/25 11:13:16 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	i;
	char	nc;
	char	*lc;
	int		detect;

	nc = (char)c;
	i = 0;
	detect = 0;
	while (s[i])
	{
		if (s[i] == nc)
		{
			detect++;
			lc = &s[i];
		}
		i++;
	}
	if (detect != 0)
		return (lc);
	else if (s[i] == '\0' && nc == '\0')
		return (&s[i]);
	else
		return (NULL);
}
