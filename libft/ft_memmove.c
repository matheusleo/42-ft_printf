/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:58:31 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/15 21:56:32 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	counter = n;
	if (!dest || !src)
		return (NULL);
	d_temp = (unsigned char *)dest;
	s_temp = (unsigned char *)src;
	while (counter > 0)
	{
		d_temp[counter - 1] = s_temp[counter - 1];
		counter--;
	}
	return (dest);
}
