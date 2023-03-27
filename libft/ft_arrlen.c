/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:07:09 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/03/15 14:10:12 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns the number of elements in a string array

int	ft_arrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
