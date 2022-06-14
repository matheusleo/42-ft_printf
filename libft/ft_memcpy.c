/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:51:45 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/02 23:46:46 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	counter = 0;
	d_temp = (unsigned char *)dest;
	s_temp = (unsigned char *)src;
	while (counter < n)
	{
		d_temp[counter] = s_temp[counter];
		counter++;
	}
	return (dest);
}
