/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:22:21 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/04 23:32:31 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	size_t	b_index;

	b_index = 0;
	l_len = ft_strlen(little);
	if (l_len <= 0)
		return ((char *)big);
	while ((char)big[b_index] && len > 0 && l_len + b_index <= len)
	{
		if (ft_strncmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
