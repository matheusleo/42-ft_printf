/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:37:29 by mleonard          #+#    #+#             */
/*   Updated: 2022/04/21 21:32:44 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	join(char *to, const char *from, size_t to_start)
{
	while (*from)
	{
		to[to_start] = *from++;
		to_start++;
	}
	return (to_start);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_new_str;
	size_t	index;

	len_new_str = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(sizeof(char) * (len_new_str));
	if (!new_str)
		return (NULL);
	index = 0;
	index = join(new_str, s1, index);
	index = join(new_str, s2, index);
	new_str[index] = '\0';
	return (new_str);
}
