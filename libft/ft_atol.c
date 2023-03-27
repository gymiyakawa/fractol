/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:29:46 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/03/01 14:49:19 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// converts from char *str to long;

long	ft_atol(const char *str)
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
		n = (n * 10 + str[i++]) - '0';
	return (n * sign);
}
