/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:22:22 by mleonard          #+#    #+#             */
/*   Updated: 2022/04/09 11:47:52 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*aux_ptr;

	counter = 0;
	aux_ptr = (char *)s;
	while (counter < n)
		aux_ptr[counter++] = '\0';
}
