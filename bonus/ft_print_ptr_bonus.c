/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:48 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/24 09:34:36 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	count_lunsigned_digits(unsigned long int nb)
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

static int	print_unsigned_lint(unsigned long int nb)
{
	char	*base;
	int		base_len;
	int		nb_len;

	nb_len = 0;
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
	nb_len = count_lunsigned_digits(addr);
	if (flags.dot_flag)
		nb_len += u_print_padding('0', flags.precision - nb_len + 2);
	if (flags.zero_flag && !flags.dash_flag)
		nb_len += u_print_padding('0', flags.zero_flag - nb_len);
	print_unsigned_lint(addr);
	if (flags.dash_flag)
		nb_len += u_print_padding(' ', flags.dash_flag - nb_len);
	return (nb_len);
}
