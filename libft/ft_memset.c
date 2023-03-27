/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:31:07 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/11/18 14:01:16 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	c = (unsigned char) c;
	i = 0;
	tmp = b;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (b);
}
