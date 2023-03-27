/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:17:38 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/21 13:13:47 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// runs a string until the finalizing \0. Returns the length of s.
// if an empty string is passed, displays an error message and returns -1.
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
	{
		ft_printf("ft_strlen error: invalid/empty argument\n");
		return (-1);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}
