/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:55 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/24 09:30:14 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	count_hex_digits(unsigned int nb)
{
	int		len;
	char	*base;
	int		base_len;

	len = 0;
	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (nb == 0)
		return (len = 1);
	while (nb)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

static void	print_hex(unsigned int nb, int is_upper)
{
	char			*base;
	unsigned int	quoc;
	unsigned int	remain;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	quoc = nb / ft_strlen(base);
	remain = nb % ft_strlen(base);
	if (quoc != 0)
		print_hex(quoc, is_upper);
	ft_putchar_fd(base[remain], STDOUT);
}

int	ft_print_hex(unsigned int nb, int is_upper, t_flags flags)
{
	int	nb_len;

	nb_len = 0;
	if (flags.alt_form && !is_upper && nb != 0)
		nb_len += u_print_str("0x");
	else if (flags.alt_form && is_upper && nb != 0)
		nb_len += u_print_str("0X");
	nb_len += count_hex_digits(nb);
	if (flags.dot_flag)
		nb_len += u_print_padding('0', flags.precision - nb_len);
	else if (flags.zero_flag && !flags.dash_flag)
		nb_len += u_print_padding('0', flags.zero_flag - nb_len);
	print_hex(nb, is_upper);
	if (flags.dash_flag)
		nb_len += u_print_padding(' ', flags.dash_flag - nb_len);
	return (nb_len);
}
