/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:23 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/23 20:56:24 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_uint(unsigned int nb)
{
	int				nb_len;
	unsigned int	quoc;
	unsigned int	remain;

	nb_len = 1;
	quoc = nb / 10;
	remain = nb % 10;
	if (quoc != 0)
		nb_len += print_uint(quoc);
	ft_putchar_fd(remain + '0', STDOUT);
	return (nb_len);
}

int	ft_print_uint(unsigned int nb, t_flags flags)
{
	int				nb_len;

	nb_len = print_uint(nb);
	if (flags.dash_flag - nb_len > 0)
		nb_len += u_print_padding(' ', flags.dash_flag - nb_len);
	return (nb_len);
}
