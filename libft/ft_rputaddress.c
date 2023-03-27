/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rputaddress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:42:45 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/03/01 13:13:38 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_rputaddress(unsigned long long int n, char *base_str)
{
	size_t	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_rputaddress(n / 16, base_str);
		count += ft_rputaddress(n % 16, base_str);
	}
	else
		count += ft_rputchar(base_str[n]);
	return (count);
}
