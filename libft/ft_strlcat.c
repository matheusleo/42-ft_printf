/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:41:00 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/04 20:01:18 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	s_index;
	size_t	d_index;

	s_len = ft_strlen(src);
	d_index = ft_strlen(dst);
	s_index = 0;
	if (d_index >= size)
		return (s_len + size);
	while (s_index + d_index + 1 < size && src[s_index])
	{
		dst[d_index + s_index] = src[s_index];
		s_index++;
	}
	dst[d_index + s_index] = '\0';
	return (d_index + s_len);
}
