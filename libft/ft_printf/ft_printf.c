/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:20:56 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/21 10:31:39 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *a, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	if (!a)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, a);
	while (a[i])
	{
		if (a[i] == '%')
		{
			if (i < ft_strlen(a) && a[i + 1] == '%')
				len += ft_rputchar('%');
			len += ft_print_case((char *)a, args, i++);
		}
		else
		{
			ft_putchar(a[i]);
			len++;
		}
		i++;
	}
	return (len);
}
