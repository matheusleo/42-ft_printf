/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:55 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/23 09:55:46 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_hex(unsigned int nb, int is_upper, int is_alt)
{
	char			*base;
	int				nb_len;
	unsigned int	quoc;
	unsigned int	remain;

	nb_len = 1;
	if (is_upper)
	{
		base = "0123456789ABCDEF";
		if (is_alt && nb != 0)
			nb_len += u_print_str("0X");
	}
	else
	{
		base = "0123456789abcdef";
		if (is_alt && nb != 0)
			nb_len += u_print_str("0x");
	}
	quoc = nb / ft_strlen(base);
	remain = nb % ft_strlen(base);
	if (quoc != 0)
		nb_len += print_hex(quoc, is_upper, (is_alt = 0));
	ft_putchar_fd(base[remain], STDOUT);
	return (nb_len);
}

int	ft_print_hex(unsigned int nb, int is_upper, t_flags flags)
{
	int	nb_len;

	nb_len = print_hex(nb, is_upper, flags.alt_form);
	if (flags.left_padded - nb_len > 0)
		nb_len += u_print_padding(' ', flags.left_padded - nb_len);
	return (nb_len);
}
