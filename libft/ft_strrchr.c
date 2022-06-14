/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:43:09 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/03 00:10:34 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len != 0)
	{
		if ((char)s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	if ((char)s[len] == (char)c)
		return ((char *)s);
	return (NULL);
}
