/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:05:07 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/21 10:40:53 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_case(char *a, va_list args, size_t i)
{
	size_t	len;

	i++;
	len = 0;
	if (a[i] == 'c')
		len += ft_rputchar(va_arg(args, int));
	if (a[i] == 's')
		len += ft_rputstr(va_arg(args, char *));
	if (a[i] == 'p')
	{
		len += ft_rputstr ("0x");
		len += ft_rputaddress(va_arg(args, unsigned long long int),
				"0123456789abcdef");
	}
	if (a[i] == 'd' || a[i] == 'i')
		len += ft_rputnbr(va_arg(args, int));
	if (a[i] == 'u')
		len += ft_rputnbr(va_arg(args, unsigned int));
	if (a[i] == 'x')
		len += ft_rputnbr_base(va_arg(args, unsigned int), 16,
				"0123456789abcdef");
	if (a[i] == 'X')
		len += ft_rputnbr_base(va_arg(args, unsigned int), 16,
				"0123456789ABCDEF");
	return (len);
}
