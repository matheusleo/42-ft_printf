/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:50:27 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/05 00:54:55 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_strs(char const *str, char limiter)
{
	size_t	total_str;
	size_t	index;
	size_t	next;

	index = 0;
	total_str = 0;
	while (str[index] && str[index] == limiter)
		index++;
	while (str[index])
	{
		next = index + 1;
		if (str[index] != limiter && (str[next] == limiter || !str[next]))
			total_str++;
		index++;
	}
	return (total_str);
}

static char	*ft_copy_word(char **arr, size_t pos, char *str, char limiter)
{
	char	*end;
	size_t	substr_size;

	end = ft_strchr(str, limiter);
	if (!end)
		end = str + ft_strlen(str);
	substr_size = end - str;
	arr[pos] = ft_substr(str, 0, substr_size);
	return (end);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_nb;
	size_t	arr_index;
	char	**arr;
	char	*str_copy;

	word_nb = ft_count_strs(s, c);
	arr = (char **)malloc(sizeof(char *) * (word_nb + 1));
	if (!arr)
		return (NULL);
	arr_index = 0;
	str_copy = (char *)s;
	while (*str_copy)
	{
		while (*str_copy == c)
			str_copy++;
		if (*str_copy == '\0')
			break ;
		str_copy = ft_copy_word(arr, arr_index, str_copy, c);
		arr_index++;
	}
	arr[arr_index] = NULL;
	return (arr);
}
