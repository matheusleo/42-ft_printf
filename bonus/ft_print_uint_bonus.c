/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:23 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/24 10:08:56 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	count_unsigned_digits(unsigned int nb)
{
	int	counter;

	counter = 0;
	while (nb > 0)
	{
		nb /= 10;
		counter++;
	}
	return (counter);
}

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

	nb_len = count_unsigned_digits(nb);
	if (flags.dot_flag)
		nb_len += u_print_padding('0', flags.precision - nb_len);
	else if (flags.zero_flag && !flags.dash_flag)
		nb_len += u_print_padding('0', flags.zero_flag - nb_len);
	print_uint(nb);
	if (flags.dash_flag - nb_len > 0)
		nb_len += u_print_padding(' ', flags.dash_flag - nb_len);
	return (nb_len);
}
