/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:33:44 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/03/01 13:14:14 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_rputnbr_base(long long int n, int base, char *base_str)
{
	size_t	count;

	count = 0;
	if (n >= base)
	{
		count += ft_rputnbr_base(n / base, base, base_str);
		count += ft_rputnbr_base(n % base, base, base_str);
	}
	else
		count += ft_rputchar(base_str[n]);
	return (count);
}
