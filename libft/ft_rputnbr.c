/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:56:25 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/02/25 15:49:00 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_rputnbr(long long int n)
{
	size_t			count;
	long long int	tmp;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
		count++;
	}
	tmp = n;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		count++;
	}
	if (n < 10 && n >= 0)
		ft_putchar(n + '0');
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), 1);
		ft_putchar((n % 10) + '0');
	}
	return (count);
}
