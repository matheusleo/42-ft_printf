/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:48 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/25 11:23:12 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	count_lhex_digits(unsigned long int nb)
{
	int		len;
	char	*base;
	int		base_len;

	len = 1;
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

static int	print_unsigned_lint(unsigned long int nb)
{
	char	*base;
	int		base_len;
	int		nb_len;

	nb_len = 1;
	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (nb != 0)
	{
		nb_len += 1;
		nb_len += print_unsigned_lint(nb / base_len);
		ft_putchar_fd(base[nb % base_len], STDOUT);
		return (nb_len);
	}
	return (nb_len);
}

int	ft_print_ptr(void *ptr, t_flags flags)
{
	unsigned long int	addr;
	int					nb_len;

	addr = (unsigned long int)ptr;
	if (!ptr)
		return (ft_print_str("(nil)", flags));
	u_print_str("0x");
	nb_len = count_lhex_digits(addr) + 1;
	if (flags.dot_flag)
		nb_len += u_print_padding('0', flags.precision - nb_len + 2);
	if (flags.zero_flag && !flags.dash_flag)
		nb_len += u_print_padding('0', flags.zero_flag - nb_len);
	print_unsigned_lint(addr);
	if (flags.dash_flag)
		nb_len += u_print_padding(' ', flags.dash_flag - nb_len);
	return (nb_len);
}
