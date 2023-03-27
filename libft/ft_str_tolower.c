/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:34:59 by gmiyakaw          #+#    #+#             */
/*   Updated: 2022/12/13 17:08:46 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// changes each alphabetical character in a string to lower
// case. Does nothing if the character is not a letter

#include "libft.h"

char	*ft_str_tolower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
