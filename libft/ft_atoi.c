/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:56:47 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/04 18:29:44 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	jump_spaces(const char *nptr)
{
	size_t	offset;

	offset = 0;
	while (('\t' <= nptr[offset] && nptr[offset] <= '\r') \
						|| nptr[offset] == ' ')
		offset++;
	return (offset);
}

int	ft_atoi(const char *nptr)
{
	int		res;
	int		sign;
	size_t	index;

	res = 0;
	sign = 0;
	index = jump_spaces(nptr);
	if (ft_strncmp(nptr, "-2147483648", 11) == 0)
		return (-2147483648);
	while (nptr[index] == '-' || nptr[index] == '+')
	{
		if (sign != 0)
			return (0);
		if (nptr[index] == '-')
			sign = -1;
		if (nptr[index] == '+')
			sign = 1;
		index++;
	}
	while ('0' <= nptr[index] && nptr[index] <= '9')
		res = (res * 10) + (nptr[index++] - '0');
	if (sign == 0)
		return (res);
	return (res * sign);
}
