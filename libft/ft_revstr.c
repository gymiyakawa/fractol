/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:21:09 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/11/17 14:52:17 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	size_t	i;
	size_t	j;
	char	*rev;

	rev = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!rev)
		return (NULL);
	rev[ft_strlen(str)] = '\0';
	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (i-- > 0)
		rev[j++] = str[i];
	return (rev);
}
