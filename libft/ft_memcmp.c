/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:43:49 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 16:57:35 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (n == 0)
		return (0);
	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (a[i] == b[i] && i < n - 1)
		i++;
	return (a[i] - b[i]);
}
