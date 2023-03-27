/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:14:57 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/03/01 14:27:31 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Converts asci value to int. can't deal with above or below INT MIN or MAX.
*/
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		sign;

i = 0;
n = 0;
sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10 + str[i++]) - '0';
		if ((n * sign) > 2147483647 || (n * sign) < -2147483648)
			return (0);
	}
	return (n * sign);
}
