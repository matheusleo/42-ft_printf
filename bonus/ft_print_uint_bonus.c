/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:23 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/21 21:48:37 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_uint(unsigned int nb)
{
	int				nb_len;
	unsigned int	quoc;
	unsigned int	remain;

	nb_len = 1;
	quoc = nb / 10;
	remain = nb % 10;
	if (quoc != 0)
		nb_len += ft_print_uint(quoc);
	ft_putchar_fd(remain + '0', STDOUT);
	return (nb_len);
}
