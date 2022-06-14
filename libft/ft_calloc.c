/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:36:34 by mleonard          #+#    #+#             */
/*   Updated: 2022/05/13 00:45:59 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buf;
	size_t	prod;

	prod = nmemb * size;
	if (nmemb != 0 && (prod / nmemb != size))
		return (NULL);
	buf = malloc(prod);
	if (!buf)
		return (NULL);
	ft_bzero(buf, prod);
	return (buf);
}
