/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:52:20 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/03/15 12:16:47 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// frees every string in the array, and the pointer
	// itself at the end
#include "libft.h"

void	ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}
