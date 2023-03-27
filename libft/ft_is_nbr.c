/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:52:34 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/03/10 10:54:01 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checks if the char string is a number. If it detects any non digit
// character, returns 1. Skips the first character if it's a "-"
int	ft_is_nbr(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
	}
	return (0);
}
