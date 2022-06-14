/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 23:35:16 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/17 18:55:10 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_dgts_sign(int n)
{
	size_t	counter;

	counter = 0;
	if (n < 0)
		counter++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static char	*ft_reverse(char *str)
{
	size_t	start;
	size_t	end;
	char	aux_var;

	start = 0;
	if (str[start] == '-')
		start++;
	end = ft_strlen(str) - 1;
	while (end > start)
	{
		aux_var = str[start];
		str[start] = str[end];
		str[end] = aux_var;
		start++;
		end--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	max_size;
	size_t	index;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	max_size = ft_count_dgts_sign(n);
	str = (char *)malloc(sizeof(char) * (max_size + 1));
	if (!str)
		return (NULL);
	index = 0;
	if (n < 0)
	{
		str[index++] = '-';
		n = -n;
	}
	while (index < max_size)
	{
		str[index] = n % 10 + '0';
		n = n / 10;
		index++;
	}
	str[index] = '\0';
	return (ft_reverse(str));
}
