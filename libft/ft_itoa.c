/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:30:44 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/02/17 11:19:28 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intsize(int n)
{
	int	intsize;

	if (n == 0)
		return (1);
	intsize = 0;
	if (n < 0)
	{
		intsize++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		intsize++;
	}
	return (intsize);
}

static char	*ft_intpos(char *str, int n, int size)
{
	str[size] = '\0';
	while (size > 0)
	{
		str[--size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static char	*ft_intneg(char *str, int n, int size)
{
	str[0] = 45;
	str[size] = '\0';
	n *= -1;
	while (size - 1 > 0)
	{
		str[--size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n > 2147483647 || n <= -2147483648)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_intsize(n);
	str = (char *)malloc ((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		return (ft_intneg(str, n, size));
	else
		return (ft_intpos(str, n, size));
}
