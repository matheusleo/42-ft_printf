/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:03:26 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/21 21:45:36 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"
#include <stdio.h>

// Unchanged functions

int	ft_print_str(char *str)
{
	int	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT);
	return (str_len);
}

int	ft_print_char(int c)
{
	ft_putchar_fd((unsigned char)c, STDOUT);
	return (1);
}

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

int	ft_print_ptr(void *ptr)
{
	unsigned long int	addr;
	int					nb_len;

	addr = (unsigned long int)ptr;
	if (!ptr)
		return (ft_print_str("(nil)"));
	nb_len = ft_print_str("0x");
	nb_len += print_unsigned_lint(addr);
	return (nb_len);
}

// Refactored ft_print_hex

int	ft_print_hex(unsigned int nb, int is_upper, int is_alt)
{
	char			*base;
	int				nb_len;
	unsigned int	quoc;
	unsigned int	remain;

	nb_len = 1;
	if (is_upper)
	{
		base = "0123456789ABCDEF";
		if (is_alt)
			nb_len += ft_print_str("0x");
	}
	else
	{
		base = "0123456789abcdef";
		if (is_alt)
			nb_len += ft_print_str("0x");
	}
	quoc = nb / ft_strlen(base);
	remain = nb % ft_strlen(base);
	if (quoc != 0)
		nb_len += ft_print_hex(quoc, is_upper, FALSE);
	ft_putchar_fd(base[remain], STDOUT);
	return (nb_len);
}

// Refactored ft_print_int

int	ft_print_int(int nb,  int is_signed, int is_spaced)
{
	char	*nb_str;
	int		nb_len;

	nb_len = 0;
	nb_str = ft_itoa(nb);
	if (!*nb_str)
		return (-1);
	if (is_signed && nb > 0)
		nb_len += ft_print_str("+");
	else if (is_spaced && nb > 0)
		nb_len += ft_print_str(" ");
	nb_len += ft_print_str(nb_str);
	free(nb_str);
	return (nb_len);
}

// Refactored ft_printf

static int	ft_parse_format_char(char indicator, va_list list, t_flags flags)
{
	if (indicator == 'c')
		return (ft_print_char(va_arg(list, int)));
	if (indicator == 's')
		return (ft_print_str(va_arg(list, char *)));
	if (indicator == 'd')
		return (ft_print_int(va_arg(list, int), flags.signed_form, flags.spaced_form));
	if (indicator == 'i')
		return (ft_print_int(va_arg(list, int), flags.signed_form, flags.spaced_form));
	if (indicator == 'u')
		return (ft_print_uint(va_arg(list, unsigned int)));
	if (indicator == 'x')
		return (ft_print_hex(va_arg(list, unsigned int), FALSE, flags.alt_form));
	if (indicator == 'X')
		return (ft_print_hex(va_arg(list, unsigned int), TRUE, flags.alt_form));
	if (indicator == 'p')
		return (ft_print_ptr(va_arg(list, void *)));
	return (ft_print_char('%'));
}

int	ft_printf(const char *format, ...)
{
	int		format_len;
	va_list	arg_list;
	t_flags	flags;

	va_start(arg_list, format);
	format_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			flags = ft_flag_parser(++format);
			format += flags.total_flags;
			format_len += ft_parse_format_char(*(format), arg_list, flags);
			format++;
			continue ;
		}
		ft_putchar_fd(*format, STDOUT);
		format++;
		format_len++;
	}
	va_end(arg_list);
	return (format_len);
}
