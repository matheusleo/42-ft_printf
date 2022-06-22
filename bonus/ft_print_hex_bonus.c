/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:55 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/22 10:27:33 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_hex(unsigned int nb, int is_upper, t_flags flags)
{
	char			*base;
	int				nb_len;
	unsigned int	quoc;
	unsigned int	remain;

	nb_len = 1;
	if (is_upper)
	{
		base = "0123456789ABCDEF";
		if (flags.alt_form && nb != 0)
			nb_len += ft_print_str("0X");
		flags.alt_form = 0;
	}
	else
	{
		base = "0123456789abcdef";
		if (flags.alt_form && nb != 0)
			nb_len += ft_print_str("0x");
		flags.alt_form = 0;
	}
	quoc = nb / ft_strlen(base);
	remain = nb % ft_strlen(base);
	if (quoc != 0)
		nb_len += ft_print_hex(quoc, is_upper, flags);
	ft_putchar_fd(base[remain], STDOUT);
	return (nb_len);
}
