/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:18:26 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/04 22:12:29 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*dest;
	int		d_len;

	d_len = 0;
	s_len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (s_len + 1));
	if (dest)
	{
		while (d_len <= s_len)
		{
			dest[d_len] = s[d_len];
			d_len++;
		}
		return (dest);
	}
	return (NULL);
}
